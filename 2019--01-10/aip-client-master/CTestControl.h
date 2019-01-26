#ifndef CTESTCONTROL_H
#define CTESTCONTROL_H

#include <QTime>
#include <QWidget>
#include <QLayout>
#include <QPainter>
#include <QScrollBar>
#include <QModelIndex>
#include <QTableWidgetItem>

#include "MyWaveLabel.h"

#include "MyHelper.h"
namespace Ui {
class CTestControl;
}

class CTestControl : public QWidget
{
    Q_OBJECT
    
public:
    explicit CTestControl(QWidget *parent = 0);
    ~CTestControl();
    
private:
    Ui::CTestControl *ui;
signals:
    void goToWidget(int win);
public slots:
    void updateShow();
    void updateData(QStringList param);
    void updateTime();
    void updateTemp(int temp);
    QStringList getParam(QString type, QStringList p);
    void insertRow();
    void on_pushButtonExit_clicked();
    void on_pushButtonConf_clicked();
private:
    QList<MyWaveLabel *> wave;
    QList<QLabel*> color;
    QList<QTableWidgetItem *> testList;
    QStringList number;
    QStringList item;
    QStringList param;
    QStringList result;
    QStringList judge;
    int itemCount;
    int waveCount;
};

#endif // CTESTCONTROL_H
