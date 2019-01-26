#ifndef CCONFIGACV_H
#define CCONFIGACV_H

#include <QWidget>
#include <QDataStream>

#include "MyHelper.h"

namespace Ui {
class CConfigAcv;
}

class CConfigAcv : public QWidget
{
    Q_OBJECT
    
public:
    explicit CConfigAcv(QWidget *parent = 0);
    ~CConfigAcv();
    
private:
    Ui::CConfigAcv *ui;
public slots:
    void updateShow();
    void updateData(QStringList p);
    QStringList output();
    QByteArray getCmdIssued();
    QByteArray getCmdStart();
    QByteArray getCmdStop();
private:
    QByteArray msg;
};

#endif // CCONFIGACV_H
