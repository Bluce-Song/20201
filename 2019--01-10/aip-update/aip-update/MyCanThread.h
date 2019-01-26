#ifndef MYCANTHREAD_H
#define MYCANTHREAD_H

#include <QFile>
#include <QObject>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <linux/netlink.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <net/if.h>
#include <fcntl.h>
#include <sys/un.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>

#include <QTimer>

#define CAN_SEND_ID 0x40

class MyCanThread : public QObject
{
    Q_OBJECT
public:
    explicit MyCanThread(QObject *parent = 0);
signals:
    void DevInsert(QString dev);
    void MsgInsert(QString msg);
public slots:
    void CanInit(void);
    bool CanOpen(void);
    void KeepAlive(void);
    bool WriteFrame(can_frame TxMsg);
    bool ReadFrame(void);
    void WritePage(QByteArray msg);
    void ReadPage(void);

    void ExecuteCmd(void);
    void SendMsg(QByteArray msg);
    void SendText(QString name);
    void DevReset(int dev);
private:
    int        s;
    can_frame  RxMsg;
    quint8 TimeCount;
    quint8 PageCount;
    quint8 isDevFree;
    QByteArray text;
    QTimer *timer;
    QFile *file;


};

#endif // MYCANTHREAD_H
