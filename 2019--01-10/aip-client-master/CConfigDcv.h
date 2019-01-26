#ifndef CCONFIGDCV_H
#define CCONFIGDCV_H

#include <QWidget>
#include "MyHelper.h"
namespace Ui {
class CConfigDcv;
}

class CConfigDcv : public QWidget
{
    Q_OBJECT
    
public:
    explicit CConfigDcv(QWidget *parent = 0);
    ~CConfigDcv();
    
private:
    Ui::CConfigDcv *ui;
public slots:
    void updateShow();
    void updateData(QStringList p);
    QStringList output();
};

#endif // CCONFIGDCV_H
