#ifndef MTCPCLIENT_H
#define MTCPCLIENT_H

#include <QFile>
#include <QHostInfo>
#include <QTcpSocket>
#include <QDataStream>
#include <QCryptographicHash>

#include "MyHelper.h"

class MyTcpClient : public QTcpSocket
{
    Q_OBJECT
public:
    explicit MyTcpClient(QObject *parent = 0,int ClientIndex = 0);

public:
//    clientInfo Info;
public slots:
    void SendMessage(quint64 type, quint64 origin, QByteArray data);
    void StartTransfer(quint64 index, QString fileName);
    void HeartBeat();
    void HeartClear();
    void Connect(QString str);
signals:
    void RcvMessage(quint64 type, quint64 target, QByteArray data);
    void ClientConnected();
private:
    int index;
    int heart;
    QFile *file;
    QString fileName;

    qint64 loadSize;
    qint64 blockSize;
    qint64 totalBytes;
    qint64 bytesToWrite;
    qint64 bytesWritten;
    QByteArray msg;

private slots:
    void ReadData();
    void NetworkAvailable(QHostInfo host);
    void updateClientProgress(qint64 numBytes);  //发送文件内容
};

#endif // TCPCLIENT_H
