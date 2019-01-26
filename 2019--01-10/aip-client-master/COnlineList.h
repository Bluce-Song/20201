#ifndef CONLINELIST_H
#define CONLINELIST_H

#include <QWidget>
#include <QButtonGroup>
#include <QScrollBar>
#include <QTableWidgetItem>
#include "MyHelper.h"

#define W_ROW 255
#define W_COL 6

namespace Ui {
class COnlineList;
}

class COnlineList : public QWidget
{
    Q_OBJECT
public:
    explicit COnlineList(QWidget *parent = 0);
    ~COnlineList();
private:
    Ui::COnlineList *ui;
signals:
    void goToWidget(int win);
    void SendFile(quint64 index, QString name);
    void SendMessage(quint64 type, quint64 index,QByteArray data);
public slots:
    void updateShow();
    void updateData(QString str);
    void updateText(QString str);
public:
    int currentIndex;
private slots:
    void buttonJudge(int id);
private:
    QList<QTableWidgetItem *> pItem;
    QList<int> ClientIndex;
    QButtonGroup *btnGroup;
};

#endif // CONLINELIST_H
