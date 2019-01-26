/*******************************************************************************
 * Copyright (c) 2016,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2016.03.22
 * brief:       主程序
*******************************************************************************/
#include <QApplication>
#include <QTextCodec>
#include <QDebug>
#include <QTime>

#include "CMainScreen.h"
int main(int argc, char *argv[])
{
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);

    QApplication a(argc, argv);

    QFile file(":/image/abc.qss");
    file.open(QFile::ReadOnly);
    QString qss = QLatin1String(file.readAll());
    a.setStyleSheet(qss);
    a.setPalette(QPalette(QColor("#F0F0F0")));

    QTime time;
    time.start();
    CMainScreen w;
    qDebug()<<"\ninit time"<<time.elapsed();
    time.restart();
    w.show();
    qDebug()<<"show time"<<time.elapsed();

    return a.exec();
}
