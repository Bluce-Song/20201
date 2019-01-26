#include "CSystemSet.h"
#include "ui_CSystemSet.h"

CSystemSet::CSystemSet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CSystemSet)
{
    ui->setupUi(this);
}

CSystemSet::~CSystemSet()
{
    delete ui;
}
void CSystemSet::updateShow()
{
    this->setFocus();
}
void CSystemSet::on_btnExit_clicked()
{
    emit goToWidget(W_HOME);
}
