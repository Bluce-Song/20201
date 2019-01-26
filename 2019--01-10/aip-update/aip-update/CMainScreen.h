#ifndef CMAINSCREEN_H
#define CMAINSCREEN_H

#include <QDir>
#include <QFile>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include <QWidget>
#include <QFileInfo>
#include <QTableWidgetItem>
#include "MyCanThread.h"

namespace Ui {
class CMainScreen;
}

class CMainScreen : public QWidget
{
    Q_OBJECT
    
public:
    explicit CMainScreen(QWidget *parent = 0);
    ~CMainScreen();

signals:
    void SendMsg(QByteArray);
    void SendText(QString);
    void DevReset(int dev);
private slots:
    void CanInit(void);
    void DevInsert(QString dev);
    void MsgInsert(QString msg);
    void ShowFirmware(QString hardware);
    void CheckFirmware(QString path);

    void on_btnUpdate_clicked();
    void on_btnExit_clicked();
    void on_btnRun_clicked();
    void on_tabSoftware_cellClicked(int row, int column);

    void on_btnDelete_clicked();

    void on_KeyReset_clicked();

private:
    Ui::CMainScreen *ui;

    QList<QTableWidgetItem*> DeviceList;
    QList<QTableWidgetItem*> HardwareList;

    QThread *can;
    MyCanThread *canThread;
};

#endif // CMAINSCREEN_H
