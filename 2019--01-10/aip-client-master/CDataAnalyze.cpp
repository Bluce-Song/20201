#include "CDataAnalyze.h"
#include "ui_CDataAnalyze.h"

CDataAnalyze::CDataAnalyze(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CDataAnalyze)
{
    ui->setupUi(this);
}

CDataAnalyze::~CDataAnalyze()
{
    delete ui;
}
void CDataAnalyze::updateShow()
{
    this->setFocus();
}
void CDataAnalyze::on_btnExit_clicked()
{
    emit goToWidget(W_HOME);
}
