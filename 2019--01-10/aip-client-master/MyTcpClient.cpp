/*******************************************************************************
 * Copyright (c) 2016,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2016.03.22
 * brief:       客户端
*******************************************************************************/
#include "MyTcpClient.h"
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.03.22
  * brief:      客户端
******************************************************************************/
MyTcpClient::MyTcpClient(QObject *parent,int ClientIndex) :
    QTcpSocket(parent)
{
    index        = ClientIndex;
    heart        = 0;
    loadSize     = 4*1024;
    blockSize    = 0;
    totalBytes   = 0;
    bytesToWrite = 0;
    bytesWritten = 0;

    connect(this, SIGNAL(readyRead()), this, SLOT(ReadData()));
    connect(this, SIGNAL(connected()), this, SIGNAL(ClientConnected()));
    connect(this, SIGNAL(bytesWritten(qint64)),
            this, SLOT(updateClientProgress(qint64)));
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.03.22
  * brief:      读取数据
******************************************************************************/
void MyTcpClient::ReadData()
{
    qint64 type;
    qint64 target;

    QDataStream in(this);
    in.setVersion(QDataStream::Qt_4_8);

    while (1) {
        if (blockSize == 0) {
            if (this->bytesAvailable() < sizeof(qint64))
                return;
            in >> blockSize;
        }

        if (this->bytesAvailable() < blockSize)
            return;

        msg.clear();
        in >> type >> target >> msg;

        emit RcvMessage(type ,target, msg);

        blockSize = 0;
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.03.29
  * brief:      发送消息
******************************************************************************/
void MyTcpClient::SendMessage(quint64 type, quint64 target, QByteArray data)
{
    int ret;
    msg.clear();
    QDataStream out(&msg, QIODevice::ReadWrite);

    out.setVersion(QDataStream::Qt_4_8);
    out<<(qint64)0 << (quint64)type << (quint64)target << data;
    out.device()->seek(0);
    out<<(qint64)(msg.size()-sizeof(qint64));

    ret = this->writeData(msg, msg.size());
    if (ret == -1)
        qDebug() << "write data error!" << this->errorString();
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.03.29
  * brief:      准备发送文件
******************************************************************************/
void MyTcpClient::StartTransfer(quint64 id ,QString name)
{
    index = id;

    file = new QFile(name);

    if (!file->open(QFile::ReadOnly)) {
        qDebug() << "open file error!" << file->errorString();
        return;
    }
    msg.clear();
    msg = QCryptographicHash::hash(file->readAll(),QCryptographicHash::Md5);
    this->SendMessage(putFileVerify, index, msg);

    file->seek(0);

    totalBytes = file->size();
    msg.clear();
    msg.append(QString::number(totalBytes));
    this->SendMessage(putFileSize, index, msg);

    fileName = name.right(name.size() - name.lastIndexOf('/')-1);
    msg.clear();
    msg.append(fileName);
    this->SendMessage(putFileName, index, msg);

    bytesToWrite = totalBytes;
    bytesWritten = 0;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.03.29
  * brief:      发送文件内容
******************************************************************************/
void MyTcpClient::updateClientProgress(qint64 numBytes)
{
    if (bytesToWrite == 0)
        return;

    bytesWritten += (int)numBytes;

    msg.clear();
    msg = file->read(loadSize);

    this->SendMessage(putFileData, index, msg);

    bytesToWrite -= (int)qMin(bytesToWrite,loadSize);

    if (bytesToWrite == 0)
        file->close();

}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.03.29
  * brief:      心跳处理
******************************************************************************/
void MyTcpClient::HeartBeat()
{
    heart++;
    SendMessage(putCmdHeart,ServerIndex,0);
    if (heart >= 10) {
        heart = 0;
        qDebug()<<"disconnect";
        disconnectFromHost();
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.03.29
  * brief:      清零心跳
******************************************************************************/
void MyTcpClient::HeartClear()
{
    heart = 0;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.03.29
  * brief:      连接服务器
******************************************************************************/
void MyTcpClient::Connect(QString str)
{
    if (this->state() == QAbstractSocket::UnconnectedState) {
        QHostInfo::lookupHost(str,this,SLOT(NetworkAvailable(QHostInfo)));
        return;
    }
    if (this->state() == QAbstractSocket::ConnectingState) {
        return;
    }
    if (this->state() == QAbstractSocket::ConnectedState) {
        this->HeartBeat();
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.03.29
  * brief:      连接服务器
******************************************************************************/
void MyTcpClient::NetworkAvailable(QHostInfo host)
{
    this->connectToHost(host.addresses()[0], 6000);
}

