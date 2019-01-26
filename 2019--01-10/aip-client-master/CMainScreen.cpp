#include "CMainScreen.h"
#include "ui_CMainScreen.h"

CMainScreen::CMainScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CMainScreen)
{
    totalBytes   = 0;
    bytesToWrite = 0;
    bytesWritten = 0;

    isSave = false;
    isInit = false;
    sysSetp = 0;
    //网络
    client = new MyTcpClient(this);
    connect(client,SIGNAL(RcvMessage(quint64,quint64,QByteArray)),
            this,SLOT(ClientRcvMessage(quint64,quint64,QByteArray)));
    connect(client,SIGNAL(ClientConnected()),this,SLOT(ClientConnected()));

    //    udp = new udpSocket(this);
    //    udp->bind(6001,QUdpSocket::ShareAddress);
#ifndef CLIENT
    //输入法
    p_ipmethod = new MyInputMethod;
    QWSServer::setCurrentInputMethod(p_ipmethod);

    this->setWindowFlags(Qt::FramelessWindowHint);

    canSocket = new MyCanSocket;
    canSocket->openSocket(500000);

    //    realTimeClock = new MyRealTimeClock;
    //    rtc_time rtc_tm;
    //    rtc_tm.tm_year = 2016;
    //    rtc_tm.tm_mon  = 5;
    //    rtc_tm.tm_mday = 7;
    //    rtc_tm.tm_hour = 16;
    //    rtc_tm.tm_min  = 27;
    //    rtc_tm.tm_sec  = 0;
    //    realTimeClock->setRealTimeClock(rtc_tm);
#endif
    ui->setupUi(this);
    ui->btnScrollArea->hide();
    connect(ui->wHome,SIGNAL(goToWidget(int)),this,SLOT(goToWidget(int)));
    connect(ui->wList,SIGNAL(goToWidget(int)),this,SLOT(goToWidget(int)));
    connect(ui->wList,SIGNAL(SendMessage(quint64,quint64,QByteArray)),
            this,SLOT(ClientSendMessage(quint64,quint64,QByteArray)));
    connect(ui->wList,SIGNAL(SendFile(quint64,QString)),
            this,SLOT(ClientSendFile(quint64,QString)));
    connect(ui->wSyst,SIGNAL(goToWidget(int)),this,SLOT(goToWidget(int)));
    connect(ui->wData,SIGNAL(goToWidget(int)),this,SLOT(goToWidget(int)));
    connect(ui->wTest,SIGNAL(goToWidget(int)),this,SLOT(goToWidget(int)));
    connect(ui->wConf,SIGNAL(insertFile(QString)),this,SLOT(insertFile(QString)));
    connect(ui->wConf,SIGNAL(deleteFile(QString)),this,SLOT(deleteFile(QString)));
    connect(ui->wConf,SIGNAL(exportFile(QString)),this,SLOT(exportFile(QString)));
    connect(ui->wConf,SIGNAL(importFile()),this,SLOT(importFile()));
    connect(ui->wConf,SIGNAL(readFile(QString)),this,SLOT(readFile(QString)));

    btnGroup = new QButtonGroup;
    btnGroup->addButton(ui->btnExit,Qt::Key_0);
    btnGroup->addButton(ui->btnSave,Qt::Key_1);
    btnGroup->addButton(ui->btnEasy,Qt::Key_2);
    btnGroup->addButton(ui->btnConf,Qt::Key_3);
    btnGroup->addButton(ui->btnRes, Qt::Key_4);
    btnGroup->addButton(ui->btnOpp, Qt::Key_5);
    btnGroup->addButton(ui->btnIns, Qt::Key_6);
    btnGroup->addButton(ui->btnAcv, Qt::Key_7);
    btnGroup->addButton(ui->btnDcv, Qt::Key_8);
    btnGroup->addButton(ui->btnItt, Qt::Key_9);
    connect(btnGroup,SIGNAL(buttonClicked (int)),this,SLOT(buttonJudge(int)));

#ifndef CLIENT
    ui->wHome->updateButton();
#endif
    //系统节拍
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(system()));
    timer->start(50);
}

CMainScreen::~CMainScreen()
{
    delete ui;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.10
  * brief:      系统后台功能
******************************************************************************/
void CMainScreen::system()
{
    time.restart();
    switch (sysSetp) {
    case 0:
        client->Connect("xiagengtao.f3322.net");
        break;
    case 1:
        getConfigFromSql();
    case 2:
        ui->wTest->updateData(paramAll);
        break;
    case 3:
        ui->wConf->updateData(paramAll);
        break;
    case 4:
        ui->wsRes->updateData(paramAll);
        break;
    case 5:
        ui->wsOpp->updateData(paramAll);
        break;
    case 6:
        ui->wsIns->updateData(paramAll);
        break;
    case 7:
        ui->wsAcv->updateData(paramAll);
        break;
    case 8:
        ui->wsDcv->updateData(paramAll);
        break;
    case 9:
        ui->wsItt->updateData(paramAll);
        break;
    case 10:
        goToWidget(W_TEST);
        break;
    default:
        break;
    }
    if (sysSetp<=9)
        qDebug()<<sysSetp<<time.elapsed();
    sysSetp++;
    ui->wHome->updatePrograssBar(sysSetp);

    if ((sysSetp%100) == 0) {
        client->Connect("xiagengtao.f3322.net");
    }
    if ((sysSetp%20) == 0) {
        ui->wTest->updateTime();
        ui->wTest->updateTemp(240);
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.10
  * brief:      切换窗口
******************************************************************************/
void CMainScreen::goToWidget(int win)
{
    if (win <= ui->stackedWidget->count())
        ui->stackedWidget->setCurrentIndex(win);
    switch(win) {
    case W_HOME:
        break;
    case W_LIST:
        break;
    case W_SYST:
        break;
    case W_TEST:
        ui->wTest->updateShow();
        break;
    case W_CONF:
        ui->btnScrollArea->show();
        ui->wConf->updateShow();
        break;
    case WS_RES:
        ui->wsRes->updateShow();
        break;
    case WS_OPP:
        ui->wsOpp->updateShow();
        break;
    case WS_INS:
        ui->wsIns->updateShow();
        break;
    case WS_ACV:
        ui->wsAcv->updateShow();
        break;
    case WS_DCV:
        ui->wsDcv->updateShow();
        break;
    case WS_ITT:
        ui->wsItt->updateShow();
        break;
    case W_EXIT:
        this->close();
        break;
    default:
        break;
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.25
  * brief:      按键功能
******************************************************************************/
void CMainScreen::buttonJudge(int id)
{
    switch (id) {
    case Qt::Key_0:
        goToWidget(W_TEST);
        ui->btnScrollArea->hide();
        break;
    case Qt::Key_1:
        getConfigFromUser();
        updateSqlData();
        ui->btnScrollArea->hide();
        goToWidget(W_TEST);
        break;
    case Qt::Key_2:
        break;
    case Qt::Key_3:
        goToWidget(W_CONF);
        break;
    case Qt::Key_4:
        goToWidget(WS_RES);
        break;
    case Qt::Key_5:
        goToWidget(WS_OPP);
        break;
    case Qt::Key_6:
        goToWidget(WS_INS);
        break;
    case Qt::Key_7:
        goToWidget(WS_ACV);
        break;
    case Qt::Key_8:
        goToWidget(WS_DCV);
        break;
    case Qt::Key_9:
        goToWidget(WS_ITT);
        break;
    default:
        break;
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.14
  * brief:      接收网络数据
******************************************************************************/
void CMainScreen::ClientRcvMessage(quint64 type, quint64 origin, QByteArray data)
{
    int ret;
    QByteArray msg;

    switch(type){
    case getNumber:
        msg.append("AIP100000");
        client->SendMessage(putNumber,origin, msg);
        return;
    case getHardware:
        msg.append(MyHelper::getHardwareAddress());
        client->SendMessage(putHardware,origin, msg);
        return;
    case getVersion:
        msg.append(tr("软件版本0.11"));
        client->SendMessage(putVersion,origin, msg);
        return;
    case getDateTime:
        msg.append(MyHelper::GetLocalTime());
        client->SendMessage(putDateTime,origin,msg);
        return;
    case getFileActive:
        msg.append(fileActive);
        client->SendMessage(putFileActive,origin,msg);
        return;
    case getFileExist:
        client->SendMessage(putFileExist,origin,fileExist.toUtf8());
        return;
    case getConfig:
        client->SendMessage(putConfig,origin, param.toUtf8());
        return;
    case putOnlineList:
        ui->wList->updateData(data);
        return;
    case putFileData:
        ret = file->write(data);
        bytesWritten += ret;
        if (bytesWritten == totalBytes) {
            file->seek(0);
            msg = QCryptographicHash::hash(file->readAll(),QCryptographicHash::Md5);
            qDebug() << "md5 ="<< msg.toHex().constData();
            file->close();
            totalBytes = 0;
            bytesToWrite = 0;
            bytesWritten = 0;
        }
        return;
    case putFileName:
        fileName.clear();
        fileName.append(RCV_PATH);
        fileName.append(data);
        qDebug()<<"fileName ="<<fileName;
        file = new QFile(fileName);
        if (!file->open(QFile::ReadWrite ))
            qDebug()<<"open failed";
        return;
    case putFileSize:
        totalBytes = qint64(data.toDouble());
        bytesToWrite = totalBytes;
        bytesWritten = 0;
        qDebug()<<"totalBytes ="<<totalBytes;
        return;
    case putFileVerify:
        md5 = data;
        qDebug() << "md5 ="<< md5.toHex().constData();
        return;
    case putCmdHeart:
        client->HeartClear();
        return;
    case putFileActive:
        fileActive = data;
        break;
    case putFileExist:
        fileExist = data;
        break;
    case putConfig:
        param = data;
        isSave = true;
        updateSqlData();
        updateUserData();
        break;
    default:
        break;
    }
    ui->wList->updateText(data);
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.14
  * brief:      发送网络数据
******************************************************************************/
void CMainScreen::ClientSendMessage(quint64 type, quint64 target, QByteArray data)
{
    client->SendMessage(type,target,data);
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.14
  * brief:      发送网络文件
******************************************************************************/
void CMainScreen::ClientSendFile(quint64 index ,QString name)
{
    client->StartTransfer(index, name);
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.14
  * brief:      网络连接初始化
******************************************************************************/
void CMainScreen::ClientConnected()
{
    ClientRcvMessage(getHardware,ServerIndex,Empty);
    ClientRcvMessage(getVersion,ServerIndex,Empty);
    ClientRcvMessage(getNumber,ServerIndex,Empty);
}
/*****************************************************************************/
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.14
  * brief:      从客户界面获取配置信息
******************************************************************************/
void CMainScreen::getConfigFromUser()
{
    int i,j;
    QStringList p = ui->wConf->output();
    p.append(ui->wsRes->output());
    p.append(ui->wsOpp->output());
    p.append(ui->wsIns->output());
    p.append(ui->wsAcv->output());
    p.append(ui->wsDcv->output());
    p.append(ui->wsItt->output());

    for(i=0; i<p.size(); i++) {
        for (j=0; j<paramList.size(); j++) {
            if (p[i].left(2) == paramList[j].left(2)) {
                if (paramList[j] != p[i]) {
                    paramList[j] = p[i];
                    isSave = true;
                }
            }
        }
    }
    if (isSave == true) {
        param = paramList.join("\n\n");
        updateUserData();
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.14
  * brief:      从数据库获取配置信息
******************************************************************************/
void CMainScreen::getConfigFromSql()
{
    if (MyHelper::ConnectDataBase()) {
        if (isInit == false) {
            isInit = true;
            MyHelper::InsertLog("1");
        }
        fileExist  = MyHelper::GetSysFile();
        fileActive = MyHelper::GetFileActive();
        param      = MyHelper::GetSysParam(fileActive);
    }
    updateUserData();
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.14
  * brief:      更新用户界面信息
******************************************************************************/
void CMainScreen::updateUserData()
{
    QStringList k;
    k.append(getMotorFile);
    k.append(fileExist.split(" "));
    paramList  = param.split("\n\n");
    paramAll.clear();
    paramAll.append(k.join(" "));
    paramAll.append(paramList);

    ui->wTest->updateData(paramAll);
    ui->wConf->updateData(paramAll);
    ui->wsRes->updateData(paramAll);
    ui->wsOpp->updateData(paramAll);
    ui->wsIns->updateData(paramAll);
    ui->wsAcv->updateData(paramAll);
    ui->wsDcv->updateData(paramAll);
    ui->wsItt->updateData(paramAll);
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.14
  * brief:      存储配置信息
******************************************************************************/
void CMainScreen::updateSqlData()
{
    if (isSave == true){
        isSave = false;
#ifndef CLIENT
        MyHelper::UpdateSysFile(param);
        MyHelper::InsertLog("2");
#else
        client->SendMessage(putConfig,(quint64)ui->wList->currentIndex,param.toUtf8());
#endif
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.14
  * brief:      添加配置文件
******************************************************************************/
void CMainScreen::insertFile(QString fileName)
{
    fileName += QString(" %1").arg(MyHelper::GetLocalTime());
    MyHelper::InsertSysFile(fileName,param);
    getConfigFromSql();
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.14
  * brief:      删除配置文件
******************************************************************************/
void CMainScreen::deleteFile(QString fileName)
{
    if (fileName == fileActive) {
        msgBox.setWindowFlags(Qt::FramelessWindowHint);
        msgBox.setText(tr("不能删除当前文件"));
        msgBox.exec();
        return;
    }
    MyHelper::DeleteSysFile(fileName);
    getConfigFromSql();
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.14
  * brief:      导出配置文件
******************************************************************************/
void CMainScreen::exportFile(QString fileName)
{
    int pos = fileName.indexOf("/");
    QString ff = fileName.left(pos);
    QString filePath = QString("/opt/%1.csv").arg(ff);
    QString fileParam = MyHelper::GetSysParam(fileName).replace("\n\n","##");
    QString fileData = QString("%1,%2\n").arg(fileName).arg(fileParam);
    QFile csvFile(filePath);
    if (csvFile.open(QIODevice::ReadWrite)) {
        csvFile.write(fileData.toAscii());
        csvFile.close();
    } else {
        qDebug()<<"open fail";
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.14
  * brief:      导入配置文件
******************************************************************************/
void CMainScreen::importFile()
{
    QFileDialog *fileDialog = new QFileDialog;
    fileDialog->setWindowTitle(tr("Open Image"));
    fileDialog->setDirectory(".");
    fileDialog->setFilter(tr("Source Files(*.csv)"));
    fileDialog->setFocus();
    if(fileDialog->exec() == QDialog::Accepted) {
        QString path = fileDialog->selectedFiles()[0];

        QFile csvFile(path);
        if (csvFile.open(QIODevice::ReadWrite)) {
            QStringList list;
            list.clear();
            QTextStream in(&csvFile);
            while(!in.atEnd()) {
                QString fileLine = in.readLine();
                list = fileLine.split(",", QString::SkipEmptyParts);
                QString fileName = list[0];
                QString fileParam = list[1].replace("##","\n\n");
                MyHelper::InsertSysFile(fileName,fileParam);
            }
            csvFile.close();
            getConfigFromSql();
        }
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.14
  * brief:      读取配置文件
******************************************************************************/
void CMainScreen::readFile(QString fileName)
{
    MyHelper::ActiveSysFile(fileName);
    getConfigFromSql();
}
