#ifndef MYHELPER_H
#define MYHELPER_H
#include <QFile>
#include <QDebug>
#include <QVariant>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QStringList>
#include <QSqlDatabase>
#include <QNetworkInterface>
//#define CLIENT
#define DB_PATH "/opt/aip.db"
#define RCV_PATH "/mnt/nfs/"

#define W_MAIN 0x00
#define W_HOME 0x00
#define W_LIST 0x01
#define W_SYST 0x02
#define W_DATA 0x03
#define W_TEST 0x04
#define W_CONF 0x05
#define WS_RES 0x06
#define WS_OPP 0x07
#define WS_INS 0x08
#define WS_ACV 0x09
#define WS_DCV 0x0A
#define WS_ITT 0x0B
#define W_EASY 0x0C

#define W_INIT 0x10
#define W_EXIT 0xFF

const QString getMotorFile  = "10";
const QString getWireColor  = "11";
const QString getMotorType  = "12";
const QString getMotorOther = "13";
const QString getProjEnable = "14";
const QString getProjInUse  = "15";

const QString getResOther   = "20";
const QString getResLine    = "21";
const QString getOppOther   = "22";
const QString getOppLine    = "23";
const QString getInsOther   = "24";
const QString getInsLine    = "25";
const QString getAcvOther   = "26";
const QString getAcvLine    = "27";
const QString getDcvOther   = "28";
const QString getDcvLine    = "29";
const QString getIttOther   = "30";
const QString getIttLine    = "31";

const quint16 MaxClient     = 1000;
const quint64 ServerIndex   = MaxClient;

const quint64 getNumber     = 0x01;
const quint64 getHardware   = 0x02;
const quint64 getVersion    = 0x03;
const quint64 getDateTime   = 0x04;
const quint64 getFileActive = 0x05;
const quint64 getFileExist  = 0x06;
const quint64 getConfig     = 0x07;
const quint64 getOnlineList = 0x08;
const quint64 getFileLog    = 0x09;

const quint64 putNumber     = 0x21;
const quint64 putHardware   = 0x22;
const quint64 putVersion    = 0x23;
const quint64 putDateTime   = 0x24;
const quint64 putFileActive = 0x25;
const quint64 putFileExist  = 0x26;
const quint64 putConfig     = 0x27;
const quint64 putOnlineList = 0x28;
const quint64 putFileLog    = 0x29;

const quint64 putFileData   = 0x41;
const quint64 putFileName   = 0x42;
const quint64 putFileSize   = 0x43;
const quint64 putFileVerify = 0x44;
const quint64 putCmdHeart   = 0x45;
const quint64 putCmdTest    = 0x46;
const quint64 putCmdError   = 0x47;

const QByteArray Empty      = 0x00;

const quint8 state_upper   = 0;
const quint8 state_lower   = 1;
const quint8 state_error   = 2;
const quint8 state_test    = 3;
const quint8 state_config  = 4;

class MyHelper:public QObject
{
public:

    static QStringList getParam(QString type, QStringList p)
    {
        QStringList k;
        for (int i=0; i<p.size(); i++) {
            if (p[i].startsWith(type)) {
                k = p[i].split(" ");
                k.removeFirst();
                break;
            }
        }
        return k;
    }
    static QString getHardwareAddress()
    {
        int i;
        QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
        for (i=0; i<list.size(); i++) {
            if (list[i].name()=="eth0")
                return list[i].hardwareAddress();
        }
        return list[0].hardwareAddress();
    }

    static bool ConnectDataBase()
    {
        QSqlDatabase db;
        QFile file(DB_PATH);
        if (file.exists()) {
            if(QSqlDatabase::contains("qt_sql_default_connection"))
                db = QSqlDatabase::database("qt_sql_default_connection");
            else
                db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName(DB_PATH);
            db.open();
            return true;
        }
        return false;
    }
    static bool DisConnect()
    {
        QSqlDatabase::removeDatabase("qt_sql_default_connection");
        return true;
    }
    static int GetMaxId(QString table)
    {
        QSqlQuery query("qt_sql_default_connection");
        QString cmd = QString("select max(id) from %1").arg(table);
        query.exec(cmd);
        query.next();
        return query.value(0).toInt();
    }
    static int GetMinId(QString table)
    {
        QSqlQuery query("qt_sql_default_connection");
        QString cmd = QString("select min(id) from %1").arg(table);
        query.exec(cmd);
        query.next();
        return query.value(0).toInt();
    }
    static int GetCount(QString table)
    {
        QSqlQuery query("qt_sql_default_connection");
        QString cmd = QString("select count(*) from %1").arg(table);
        query.exec(cmd);
        query.next();
        return query.value(0).toInt();
    }
    static int DeleteTop(QString table)
    {
        QSqlQuery query("qt_sql_default_connection");
        QString cmd = QString("delete from %1 where ID in").arg(table);
        cmd += QString("(select ID from %1 order by ID limit 0,1)").arg(table);
        query.exec(cmd);
        return true;
    }
    static void InsertLog(QString param)
    {
        QSqlQuery query("qt_sql_default_connection");
        int max = GetMaxId("log");
        int min = GetMinId("log");
        if (max-min>10) {
            query.prepare("delete from log where ID=:ID");
            query.bindValue(":ID",min);
            query.exec();
        }
        QString cmd = QString("insert into log values ");
        cmd += QString("(%1,%2,%3)").arg(max+1).arg(GetLocalTime()).arg(param);
        query.exec(cmd);
    }
    static QString GetLocalTime()
    {
        QSqlQuery query("qt_sql_default_connection");
        QString cmd = QString("select datetime ('now','localtime')");
        query.exec(cmd);
        query.next();
        QString str = query.value(0).toString();
        str.replace("-","");
        str.replace(" ","");
        str.replace(":","");
        return str;
    }
    static QString GetFileActive()
    {
        QSqlQuery query("qt_sql_default_connection");
        query.exec("select file from system where active = 1");
        query.next();
        return query.value(0).toString();
    }
    static QString GetSysFile()
    {
        QSqlQuery query("qt_sql_default_connection");
        QStringList fileExist;
        query.exec("select file from system");
        while (query.next())
            fileExist.append(query.value(0).toString());
        return fileExist.join(" ");
    }
    static QString GetSysParam(QString file)
    {
        QSqlQuery query("qt_sql_default_connection");
        query.prepare("select param from system where file = :file");
        query.bindValue(":file",file);
        query.exec();
        query.next();
        return query.value(0).toString();
    }
    static void DeleteSysFile(QString file)
    {
        QSqlQuery query("qt_sql_default_connection");
        query.prepare("delete from system where file = :file");
        query.bindValue(":file",file);
        query.exec();
    }
    static void InsertSysFile(QString file, QString param)
    {
        QSqlQuery query("qt_sql_default_connection");
        int max = GetMaxId("system");
        query.prepare("insert into system values (:d,:f,:p,0)");
        query.bindValue(":d",max+1);
        query.bindValue(":f",file);
        query.bindValue(":p",param);
        query.exec();
    }
    static void UpdateSysFile(QString param)
    {
        QSqlQuery query("qt_sql_default_connection");
        query.prepare("update system set param=:p where active=1");
        query.bindValue(":p",param);
        query.exec();
    }
    static void ActiveSysFile(QString file)
    {
        QSqlQuery query("qt_sql_default_connection");
        query.exec("update system set active=0 where active=1");
        query.prepare("update system set active=1 where file=:file");
        query.bindValue(":file",file);
        query.exec();
    }
};


#endif // MYHELPER_H
