#ifndef CCONFIGITT_H
#define CCONFIGITT_H

#include <QWidget>
#include <QLayout>
#include <QButtonGroup>
#include <QComboBox>
#include <QTableWidgetItem>
#include <QDoubleSpinBox>
#include "MyWaveLabel.h"

#include "MyHelper.h"
#define ITT_COL 11
namespace Ui {
class CConfigItt;
}

class CConfigItt : public QWidget
{
    Q_OBJECT
    
public:
    explicit CConfigItt(QWidget *parent = 0);
    ~CConfigItt();
    
private:
    Ui::CConfigItt *ui;
public slots:
    void updateShow();
    void updateData(QStringList p);
    QStringList output();
    QByteArray getCmdSampling();
    QByteArray getCmdIssued();
    QByteArray getCmdStart();
    QByteArray getCmdStop();
private slots:
    void insertWave();
    quint8 getGear(double res);
private:
    QByteArray msg;
    QButtonGroup *btnGroup;
    QList<MyWaveLabel *> wave;
    QList<QComboBox *> combo;
    QList<QDoubleSpinBox *> spin;
};

#endif // CCONFIGITT_H
