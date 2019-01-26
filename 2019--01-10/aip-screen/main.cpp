#include <QTime>
#include <QDebug>
#include <QString>
#include <QPixmap>
#include <QWSServer>
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWSServer::setCursorVisible(false);//隐藏鼠标

    char str[30];
    QTime t = QTime::currentTime();
    sprintf(str,"./%02d%02d%02d.png",t.hour(),t.minute(),t.second());

    QString fileName = str;
    if (argc > 1)
        fileName = argv[1];

    QPixmap scrPic = QPixmap::grabWindow(QApplication::desktop()->winId());

    bool ret = scrPic.save(fileName, "png");

    if (ret)
        qDebug("Screenshot is saved to: %s", fileName.toLatin1().data());
    else
        qCritical("Failed to save file: %s", fileName.toLatin1().data());

    return 0;
}

