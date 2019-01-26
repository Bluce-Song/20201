#ifndef LINUX_RTC_H
#define LINUX_RTC_H
#ifndef CLIENT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/ioctl.h>
#include <linux/rtc.h>
#include <linux/ioctl.h>

class MyRealTimeClock
{
public:
    MyRealTimeClock();

    int setRealTimeClock(rtc_time rtc_tm);
    rtc_time getRealTimeClock();

};
#endif // LINUX_RTC_H
#endif // LINUX_RTC_H
