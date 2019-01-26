#include "CConfigDcv.h"
#include "ui_CConfigDcv.h"

CConfigDcv::CConfigDcv(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CConfigDcv)
{
    ui->setupUi(this);
}

CConfigDcv::~CConfigDcv()
{
    delete ui;
}
void CConfigDcv::updateShow()
{
    this->setFocus();
}
void CConfigDcv::updateData(QStringList p)
{
    QStringList a = MyHelper::getParam(getDcvOther,p);
    if (!a.isEmpty()) {
        ui->spinBox1->setValue(a[0].toDouble());
        ui->spinBox2->setValue(a[1].toDouble());
        ui->spinBox3->setValue(a[2].toDouble());
        ui->spinBox4->setValue(a[3].toDouble());
        ui->spinBox5->setValue(a[4].toDouble());
    }
}

QStringList CConfigDcv::output()
{
    QStringList out;
    QStringList k;
    k.append(getDcvOther);
    k.append(QString::number(ui->spinBox1->value()));
    k.append(QString::number(ui->spinBox2->value()));
    k.append(QString::number(ui->spinBox3->value()));
    k.append(QString::number(ui->spinBox4->value()));
    k.append(QString::number(ui->spinBox5->value()));
    out.append(k.join(" "));
    return out;
}
