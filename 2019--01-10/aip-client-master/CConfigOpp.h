#ifndef CCONFIGOPP_H
#define CCONFIGOPP_H

#include <QWidget>
#include <QCheckBox>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
#include <QDoubleSpinBox>

#include "MyWaveLabel.h"
#include "MyHelper.h"
#define OPP_COL 5
namespace Ui {
class CConfigOpp;
}

class CConfigOpp : public QWidget
{
    Q_OBJECT
    
public:
    explicit CConfigOpp(QWidget *parent = 0);
    ~CConfigOpp();
    
private:
    Ui::CConfigOpp *ui;

public slots:
    void updateShow();
    void updateData(QStringList issuedParam);
    QStringList output();
    QByteArray getCmdSampling();
    QByteArray getCmdIssued();
    QByteArray getCmdStart();
    QByteArray getCmdStop();
private slots:
    void insertWave();
private:
    QByteArray msg;
    QList<MyWaveLabel *> wave;
    QList<QDoubleSpinBox *> spin;
    QList<QComboBox *> combo;
    QList<quint8> issue;
    QList<QLineEdit *> lineEdit;
};

#endif // CCONFIGOPP_H
