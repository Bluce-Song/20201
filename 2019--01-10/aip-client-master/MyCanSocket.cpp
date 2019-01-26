#include "MyCanSocket.h"
#ifndef CLIENT
MyCanSocket::MyCanSocket()
{
    s = 0;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.12
  * brief:      打开CAN，设置波特率
******************************************************************************/
bool MyCanSocket::openSocket(int bitrate)
{
    int ret;
    char str[256];
    s = socket(PF_CAN, SOCK_RAW, CAN_RAW);  /*打开套接字*/
    if (s < 0){
        printf("Error while opening socket");
        return false;
    }

    sprintf(str, "ip link set can0 type can bitrate %d",bitrate);
    system("ifconfig can0 down");
    system(str);
    system("ifconfig can0 up");

    //int loopback = 1;
    //setsockopt(s, SOL_CAN_RAW, CAN_RAW_LOOPBACK, &loopback, sizeof(loopback));

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

    struct can_filter filter;

    filter.can_id = 0x001 | CAN_EFF_FLAG;
    filter.can_mask = 0xFFF;
    ret = setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, &filter, sizeof(filter));
    if (ret < 0) {
        perror("setsockopt failed");
        return false;
    }

    int optVal = 8*1024 ;

    ret = setsockopt(s, SOL_SOCKET,SO_RCVBUF,(char*)&optVal,sizeof(int) );
    if (ret < 0) {
        perror("setsockopt failed");
        return false;
    }

    ret = setsockopt(s, SOL_SOCKET,SO_SNDBUF,(char*)&optVal,sizeof(int) );
    if (ret < 0) {
        perror("setsockopt failed");
        return false;
    }
    return true;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.12
  * brief:      初始化CAN，设置波特率
******************************************************************************/
bool MyCanSocket::closeSocket()
{
    if(s > 0)
        close(s);
    return true;
}

/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.11.12
  * brief:      CAN发送一帧
******************************************************************************/
bool MyCanSocket::sendFrame(can_frame frame)
{
    int nbytes;

    if (s <= 0)
        return false;

    nbytes = write(s, &frame, sizeof(struct can_frame));
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
  * brief:      读取CAN
******************************************************************************/
bool MyCanSocket::recieveFrame()
{
    int nbytes;
    int ret;
    fd_set rdfds;
    struct timeval tv;

    if (s <= 0)
        return false;

    FD_ZERO(&rdfds);
    FD_SET(s, &rdfds);
    tv.tv_sec  = 0;
    tv.tv_usec = 0;
    ret = select(s+1, &rdfds, NULL, NULL, &tv);
    if (ret < 0){
        printf("select failed");
        return false;
    }
    else if (ret == 0){
        //printf( "time out\n" );
        return false;
    }
    else if (FD_ISSET(s, &rdfds)){
        nbytes = read(s, &frame, 512 );
        /*nbytes = read(s, &frame, sizeof(struct can_frame));*/
        /*nbytes = recv(s, &frame, sizeof(struct can_frame), 0 );*/
        return true;
    }
    return true;
}

can_frame MyCanSocket::readFrame()
{
    return frame;
}

void MyCanSocket::mDelay(int ms)
{
    struct timeval time;

    time.tv_sec  = ms / 1000;				// unit = second
    time.tv_usec = (ms % 1000)*1000;		// unit = micro-second

    select(0,NULL,NULL,NULL,&time);
}
#endif // CLIENT
/******************************************************************************
                                    END
******************************************************************************/
