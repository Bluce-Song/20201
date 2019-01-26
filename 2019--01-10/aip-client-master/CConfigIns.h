#ifndef CCONFIGINS_H
#define CCONFIGINS_H

#include <QWidget>
#include "MyHelper.h"
namespace Ui {
class CConfigIns;
}

class CConfigIns : public QWidget
{
    Q_OBJECT
    
public:
    explicit CConfigIns(QWidget *parent = 0);
    ~CConfigIns();
    
private:
    Ui::CConfigIns *ui;

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

#endif // CCONFIGINS_H
