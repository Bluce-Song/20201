#ifndef CCONFIGRES_H
#define CCONFIGRES_H

#include <QWidget>
#include <QLayout>
#include <QCheckBox>
#include <QComboBox>
#include <QPushButton>
#include <QDockWidget>
#include <QDoubleSpinBox>
#include <QTableWidgetItem>

#include "MyHelper.h"
#define RES_COL 7
namespace Ui {
class CConfigRes;
}

class CConfigRes : public QWidget
{
    Q_OBJECT
    
public:
    explicit CConfigRes(QWidget *parent = 0);
    ~CConfigRes();
    
private:
    Ui::CConfigRes *ui;

public slots:
    void updateShow();
    void updateData(QStringList p);
    QStringList output();
    QByteArray getCmdIssued();
    QByteArray getCmdStart();
    QByteArray getCmdStop();

private slots:
    void buttonJudge(int);
    void insertRow();
    void deleteRow();
    quint8 getGear(double res);

    void on_tableWidget_cellClicked(int row, int column);

private:
    QByteArray msg;

    QList<QTableWidgetItem *> pLineList;
    QList<quint8> issue;
    QButtonGroup *btnGroup;
};

#endif // CCONFIGRES_H
