#include "CMainScreen.h"
#include "ui_CMainScreen.h"

CMainScreen::CMainScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CMainScreen)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    CanInit();
    CheckFirmware("/opt/aip/network/");
    CheckFirmware("/mnt/usb1/aip/");
}

CMainScreen::~CMainScreen()
{
    delete ui;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.07.18
  * brief:      CAN初始化
******************************************************************************/
void CMainScreen::CanInit()
{
    can = new QThread(this);
    canThread = new MyCanThread;
    canThread->moveToThread(can);
    connect(can,SIGNAL(started()),canThread,SLOT(CanInit()));
    connect(canThread,SIGNAL(DevInsert(QString)),this,SLOT(DevInsert(QString)));
    connect(canThread,SIGNAL(MsgInsert(QString)),this,SLOT(MsgInsert(QString)));
    connect(this,SIGNAL(SendMsg(QByteArray)),canThread,SLOT(SendMsg(QByteArray)));
    connect(this,SIGNAL(SendText(QString)),canThread,SLOT(SendText(QString)));
    connect(this,SIGNAL(DevReset(int)),canThread,SLOT(DevReset(int)));
    can->start();
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.07.18
  * brief:      添加设备
******************************************************************************/
void CMainScreen::DevInsert(QString dev)
{
    DeviceList.append(new QTableWidgetItem);
    DeviceList.last()->setTextAlignment(Qt::AlignCenter);
    DeviceList.last()->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    ui->tabDevice->setRowCount(DeviceList.size());
    ui->tabDevice->setItem(DeviceList.size()-1,0,DeviceList.last());
    DeviceList.last()->setText(dev);
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.07.18
  * brief:      添加信息
******************************************************************************/
void CMainScreen::MsgInsert(QString msg)
{
    ui->textBrowser->insertPlainText(msg);
    ui->textBrowser->moveCursor(QTextCursor::End);
}
/*******************************************************************************
 * version:    1.0
 * author:     link
 * date:       2016.06.29
 * brief:      显示固件列表
 ******************************************************************************/
void CMainScreen::ShowFirmware(QString hardware)
{
    HardwareList.append(new QTableWidgetItem);
    HardwareList.last()->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

    ui->tabSoftware->setRowCount(HardwareList.size());
    ui->tabSoftware->setItem(HardwareList.size()-1,0,HardwareList.last());

    HardwareList.last()->setText(hardware);
    qDebug()<<hardware;
}
/*******************************************************************************
 * version:    1.0
 * author:     link
 * date:       2016.06.29
 * brief:      搜索固件
 ******************************************************************************/
void CMainScreen::CheckFirmware(QString path)
{
    QFileInfo *info = new QFileInfo(path);
    if (info->isDir()) {
        QDir *dir = new QDir(path);
        QStringList file = dir->entryList();
        for (int i=0; i<file.size(); i++) {
            if (file.at(i).contains(".bin")) {
                QString n = file.at(i);
                ShowFirmware(n.insert(0,path));
            }
        }
    }
}
/*******************************************************************************
 * version:    1.0
 * author:     link
 * date:       2016.06.29
 * brief:      升级
 ******************************************************************************/
void CMainScreen::on_btnUpdate_clicked()
{
    emit SendText(ui->textFile->text());
}
/*******************************************************************************
 * version:    1.0
 * author:     link
 * date:       2016.06.29
 * brief:      退出
 ******************************************************************************/
void CMainScreen::on_btnExit_clicked()
{
    can->quit();
    this->close();
}
/*******************************************************************************
 * version:    1.0
 * author:     link
 * date:       2016.06.29
 * brief:      运行
 ******************************************************************************/
void CMainScreen::on_btnRun_clicked()
{
    emit SendMsg("G");
}
/*******************************************************************************
 * version:    1.0
 * author:     link
 * date:       2016.06.29
 * brief:      选择固件
 ******************************************************************************/
void CMainScreen::on_tabSoftware_cellClicked(int row, int column)
{
    QString text = ui->tabSoftware->item(row,column)->text();
    ui->textFile->setText(text);
}

void CMainScreen::on_btnDelete_clicked()
{
    QFile::remove(ui->textFile->text());
    ui->textFile->setText("");
    ui->tabSoftware->setRowCount(0);
    HardwareList.clear();
    CheckFirmware("/opt/aip/network/");
    CheckFirmware("/mnt/usb1/aip/");
}

void CMainScreen::on_KeyReset_clicked()
{
    emit DevReset(0x40);
}
