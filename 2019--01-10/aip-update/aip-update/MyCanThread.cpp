#include "MyCanThread.h"

MyCanThread::MyCanThread(QObject *parent) :
    QObject(parent)
{
    PageCount = 0;
    TimeCount = 0;
    isDevFree = 1;

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(KeepAlive()));
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.07.28
  * brief:      初始化CAN
******************************************************************************/
void MyCanThread::CanInit()
{
    if (CanOpen()) {
        emit MsgInsert("打开CAN口成功\n");
        timer->start(50);
    } else {
        emit MsgInsert("打开CAN口失败\n");
        return;
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.12
  * brief:      打开CAN
******************************************************************************/
bool MyCanThread::CanOpen()
{
    struct sockaddr_can     addr;
    struct ifreq            ifr;
    s = socket(PF_CAN, SOCK_RAW, CAN_RAW);  /*打开套接字*/
    if (s < 0){
        printf("Error while opening socket");
        return false;
    }
    strcpy(ifr.ifr_name, "can0" );
    if (ioctl(s, SIOCGIFINDEX, &ifr) < 0){
        printf("Error while opening can0");
        return false;
    }
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;
    if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0){
        printf("Error in socket bind");
        return false;
    }
    return true;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.07.28
  * brief:      初始化CAN
******************************************************************************/
void MyCanThread::KeepAlive()
{
    if (ReadFrame()) {
        TimeCount = 0;
        ExecuteCmd();
        return;
    }
    TimeCount++;
    if (TimeCount > 200) {
        TimeCount = 0;
        isDevFree = 1;
        emit MsgInsert("连接设备超时\n");
    }
    if (isDevFree)
        SendMsg("R");
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.12
  * brief:      CAN发送一帧
******************************************************************************/
bool MyCanThread::WriteFrame(can_frame TxMsg)
{
    int nbytes;
    nbytes = write(s, &TxMsg, sizeof(struct can_frame));
    if (nbytes != sizeof(struct can_frame)){
        perror("can raw socket write");
        return false;
    }
    return true;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.12
  * brief:      CAN读取一帧
******************************************************************************/
bool MyCanThread::ReadFrame()
{
    int nbytes;
    int ret;
    fd_set rdfds;
    struct timeval tv;

    FD_ZERO(&rdfds);
    FD_SET(s, &rdfds);
    tv.tv_sec  = 0;
    tv.tv_usec = 0;
    ret = select(s+1, &rdfds, NULL, NULL, &tv);
    if (ret <= 0){
        return false;
    }
    if (FD_ISSET(s, &rdfds)){
        nbytes = read(s, &RxMsg, sizeof(struct can_frame));
        return true;
    }
    return false;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.07.18
  * brief:      写入一页
******************************************************************************/
void MyCanThread::WritePage(QByteArray msg)
{
    if (msg.size() != 1028)
        return;
    can_frame  TxMsg;
    TxMsg.can_dlc = 4;
    TxMsg.data[0] = msg.at(0);
    TxMsg.data[1] = msg.at(1);
    TxMsg.data[2] = msg.at(2);
    TxMsg.data[3] = msg.at(3);
    WriteFrame(TxMsg);
    for (int i=0; i<1024/8; i++) {
        TxMsg.can_dlc = 8;
        for (int j=0; j<8; j++) {
            TxMsg.data[j] = msg.at(i*8+j+4);
        }
        WriteFrame(TxMsg);
        usleep(500);
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.07.18
  * brief:      读取一页
******************************************************************************/
void MyCanThread::ReadPage(void)
{
    text = file->read(1024);
    if (file->atEnd()) {
        for (int i=text.size(); i<1024; i++)
            text.append(0xff);
    }
    quint8 crc = 0;
    for (int i=0; i<1024; i++)
        crc+= text[i];
    text.insert(0,'S');
    text.insert(1,PageCount);
    text.insert(2,!PageCount);
    text.insert(3,crc);
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.07.28
  * brief:      CAN命令处理
******************************************************************************/
void MyCanThread::ExecuteCmd(void)
{
    QString v;
    quint8 cmd = RxMsg.data[0];
    switch (cmd) {
    case 'A':
        emit MsgInsert("   写入成功\n");
        if (file->atEnd()) {
            SendMsg("E");
            break;
        }
        ReadPage();
        WritePage(text);
        PageCount++;
        emit MsgInsert(QString("正在写入第%1帧数据...").arg(PageCount));
        usleep(20000);
        break;
    case 'C':
        emit MsgInsert("   同步成功\n");
        ReadPage();
        WritePage(text);
        PageCount++;
        emit MsgInsert(QString("正在写入第%1帧数据...").arg(PageCount));
        usleep(20000);
        break;
    case 'E':
        PageCount = 0;
        isDevFree = true;
        emit MsgInsert("写入结束\n");
        break;
    case 'N':
        emit MsgInsert("   写入出错\n");
        WritePage(text);
        emit MsgInsert(QString("重新写入第1%帧数据...").arg(PageCount));
        usleep(20000);
        break;
    case 'V':
        if (RxMsg.can_dlc == 4) {
            emit MsgInsert("连接设备成功\n");
            v.append("当前版本:");
            v.append(RxMsg.data[0]);
            v.append(RxMsg.data[1]);
            v.append(RxMsg.data[2]);
            v.append(RxMsg.data[3]);
            v.append("\n");
            emit MsgInsert(v);
        }
        break;
    case 'R':
        break;
    default:
        break;
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.07.28
  * brief:      发送命令
******************************************************************************/
void MyCanThread::SendMsg(QByteArray msg)
{
    if (msg.isEmpty())
        return;
    if (msg.size() > 8)
        return;
    can_frame  TxMsg;
    TxMsg.can_id  = CAN_SEND_ID;
    TxMsg.can_dlc = msg.size();
    for (int i=0; i<msg.size(); i++)
        TxMsg.data[i] = msg.at(i);
    WriteFrame(TxMsg);
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.07.28
  * brief:      发送文件
******************************************************************************/
void MyCanThread::SendText(QString name)
{
    file = new QFile(name);
    if (!file->open(QFile::ReadOnly)) {
        emit MsgInsert("文件打开失败\n");
        return;
    }
    emit MsgInsert("同步设备...");
    isDevFree = 0;
    SendMsg("C");
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.07.28
  * brief:      重启目标设备
******************************************************************************/
void MyCanThread::DevReset(int dev)
{
    can_frame  TxMsg;
    TxMsg.can_id  = dev;
    TxMsg.can_dlc = 1;
    TxMsg.data[0] = 'G';
    WriteFrame(TxMsg);
    usleep(20000);
}
