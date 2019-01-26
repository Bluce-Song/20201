#ifndef CMAINSCREEN_H
#define CMAINSCREEN_H

#include <QTime>
#include <QTimer>
#include <QLayout>
#include <QWidget>
#include <QProcess>
#include <QDateTime>
#include <QSqlQuery>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QButtonGroup>
#include <QFileInfoList>
#include <QStackedWidget>
#include <QCryptographicHash>

#include "MyRealTimeClock.h"
#include "MyInputMethod.h"
#include "MyCanSocket.h"
#include "MyTcpClient.h"
//#include "udpsocket.h"
#include "MyHelper.h"
namespace Ui {
class CMainScreen;
}

class CMainScreen : public QWidget
{
    Q_OBJECT
    
public:
    explicit CMainScreen(QWidget *parent = 0);
    ~CMainScreen(); 
private:
    Ui::CMainScreen *ui;
private slots:
    void system();
    void goToWidget(int win);

    void ClientSendMessage(quint64 type, quint64 target, QByteArray data);
    void ClientRcvMessage(quint64 type, quint64 target, QByteArray data);
    void ClientSendFile(quint64 index, QString name);
    void ClientConnected();
    void updateUserData();

    void getConfigFromUser();
    void getConfigFromSql();
    void updateSqlData();
    void insertFile(QString fileName);
    void deleteFile(QString fileName);
    void importFile();
    void exportFile(QString fileName);
    void readFile(QString fileName);
    void buttonJudge(int id);
private:
    int sysSetp;

    MyTcpClient *client;

    QString param;
    QString fileActive;
    QString fileExist;
    QStringList paramAll;
    QStringList paramList;

    qint64 totalBytes;
    qint64 bytesToWrite;
    qint64 bytesWritten;
    QByteArray md5;
    QByteArray message;

    QString fileName;   //存放文件名
    QFile *localFile;   //本地文件
    QByteArray inBlock;   //数据缓冲区
    qint64 loadSize;
    QFile *file;

//    udpSocket *udp;

    bool isSave;
    bool isInit;

    QTime time;
#ifndef CLIENT
    MyRealTimeClock *realTimeClock;
    QWSInputMethod* p_ipmethod;
    MyCanSocket *canSocket;
#endif
    QButtonGroup *btnGroup;

    QMessageBox msgBox;
};

#endif // CMAINSCREEN_H
