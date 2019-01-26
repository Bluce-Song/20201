#-------------------------------------------------
#
# Project created by QtCreator 2016-03-29T13:13:51
#
#-------------------------------------------------

QT       += core gui sql network

TARGET = aip-client
TEMPLATE = app


SOURCES += \
    main.cpp \
    CHomeScreen.cpp \
    CMainScreen.cpp \
    COnlineList.cpp \
    CSystemSet.cpp \
    CDataAnalyze.cpp \
    CTestControl.cpp \
    CConfigType.cpp \
    CConfigRes.cpp \
    CConfigOpp.cpp \
    CConfigIns.cpp \
    CConfigAcv.cpp \
    CConfigDcv.cpp \
    CConfigItt.cpp \
    CKeyboard.cpp \
    MyTcpClient.cpp \
    MyWaveLabel.cpp \
    MyInputMethod.cpp \
    MyScrollArea.cpp \
    MyCanSocket.cpp \
    MyRealTimeClock.cpp

HEADERS  += \
    CHomeScreen.h \
    CMainScreen.h \
    COnlineList.h \
    CSystemSet.h \
    CDataAnalyze.h \
    CTestControl.h \
    CConfigType.h \
    CConfigRes.h \
    CConfigOpp.h \
    CConfigIns.h \
    CConfigAcv.h \
    CConfigDcv.h \
    CConfigItt.h \
    MyHelper.h \
    CKeyboard.h \
    MyTcpClient.h \
    MyWaveLabel.h \
    MyInputMethod.h \
    MyScrollArea.h \
    MyCanSocket.h \
    MyRealTimeClock.h

FORMS += \
    CHomeScreen.ui \
    CMainScreen.ui \
    COnlineList.ui \
    CSystemSet.ui \
    CDataAnalyze.ui \
    CTestControl.ui \
    CConfigType.ui \
    CConfigRes.ui \
    CConfigOpp.ui \
    CConfigIns.ui \
    CConfigAcv.ui \
    CConfigDcv.ui \
    CConfigItt.ui \
    CKeyboard.ui

DISTFILES +=

RESOURCES += \
    image.qrc
