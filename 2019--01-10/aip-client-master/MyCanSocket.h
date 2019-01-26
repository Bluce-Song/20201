#ifndef LINUX_CAN_H
#define LINUX_CAN_H
#ifndef CLIENT
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
#include <QDebug>

class MyCanSocket
{
public:
    MyCanSocket();

public:
    bool openSocket(int bitrate);
    bool closeSocket();
    bool sendFrame(can_frame);
    bool recieveFrame();
    can_frame readFrame();
private slots:
    void mDelay(int ms);
private:
    int                     s;
    struct sockaddr_can     addr;
    struct ifreq            ifr;
    can_frame               frame;
};
#endif // CLIENT
#endif // LINUX_CAN_H
