#include "CConfigItt.h"
#include "ui_CConfigItt.h"

CConfigItt::CConfigItt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CConfigItt)
{
    ui->setupUi(this);
}

CConfigItt::~CConfigItt()
{
    delete ui;
}
void CConfigItt::updateShow()
{
    this->setFocus();
}

void CConfigItt::updateData(QStringList p)
{
    QStringList a = MyHelper::getParam(getIttLine,p);

    while (wave.size() < a.size()/ITT_COL)
        insertWave();

    for (int i=0; i<a.size()/ITT_COL; i++) {
        if (a[i*ITT_COL+0].toInt() == 1)
            wave[i]->updateValid(true);
        else
            wave[i]->updateValid(false);

        combo[i*3+0]->setCurrentIndex(a[i*ITT_COL+1].toInt());
        combo[i*3+1]->setCurrentIndex(a[i*ITT_COL+2].toInt());
        combo[i*3+2]->setCurrentIndex(a[i*ITT_COL+3].toInt());

        spin[i*6+0]->setValue(a[i*ITT_COL+4].toDouble());
        spin[i*6+1]->setValue(a[i*ITT_COL+5].toDouble());
        spin[i*6+2]->setValue(a[i*ITT_COL+6].toDouble());
        spin[i*6+3]->setValue(a[i*ITT_COL+7].toDouble());
        spin[i*6+4]->setValue(a[i*ITT_COL+8].toDouble());
        spin[i*6+5]->setValue(a[i*ITT_COL+9].toDouble());

        wave[i]->updateWave(a[i*ITT_COL+10].toUtf8());
    }
}

QStringList CConfigItt::output()
{
    QStringList out;
    QStringList k;

    k.append(getIttLine);

    for (int i=0; i<wave.size(); i++) {
        if (wave[i]->isChecked())
            k.append(QString::number(1));
        else
            k.append(QString::number(0));
        k.append(QString::number(combo[i*3+0]->currentIndex()));
        k.append(QString::number(combo[i*3+1]->currentIndex()));
        k.append(QString::number(combo[i*3+2]->currentIndex()));
        k.append(QString::number(spin[i*6+0]->value()));
        k.append(QString::number(spin[i*6+1]->value()));
        k.append(QString::number(spin[i*6+2]->value()));
        k.append(QString::number(spin[i*6+3]->value()));
        k.append(QString::number(spin[i*6+4]->value()));
        k.append(QString::number(spin[i*6+5]->value()));
        k.append(wave[i]->wave());
    }
    out.append(k.join(" "));

    return out;
}

QByteArray CConfigItt::getCmdSampling()
{
//    if(WIMP->IMP_TestItems!=0)
//    {
//        frame.can_id = 0x24;   frame.can_dlc = 0x05;
//        frame.data[0] = 0x01;  frame.data[1] = 0x02; //0x00测试;0x01自动选频采样;0x02;定频采样;
//        frame.data[2] =0x13;
//        frame.data[3] =0x00;
//        frame.data[4] =WIMP->IMP_TestItems;
//        canSend(frame);
//    }
    return msg;
}

QByteArray CConfigItt::getCmdIssued()
{
    return msg;
}

QByteArray CConfigItt::getCmdStart()
{
    return msg;
}

QByteArray CConfigItt::getCmdStop()
{
    return msg;
}
void CConfigItt::insertWave()
{
    int size = wave.size();
    wave.append(new MyWaveLabel(this));
    wave.last()->updateSet(true);

    QStringList str;
    str<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8";

    QGridLayout *input = new QGridLayout;

    input->addWidget(new QLabel(tr("端一"),this),0,0);
    input->addWidget(new QLabel(tr("端二"),this),1,0);
    input->addWidget(new QLabel(tr("档位"),this),2,0);

    input->addWidget(new QLabel(tr("电压"),this),0,2);
    input->addWidget(new QLabel(tr("电晕"),this),1,2);
    input->addWidget(new QLabel(tr("面积"),this),2,2);
    input->addWidget(new QLabel(tr("次数"),this),0,4);
    input->addWidget(new QLabel(tr("相位"),this),1,4);
    input->addWidget(new QLabel(tr("差积"),this),2,4);

    combo.append(new QComboBox(this));
    combo.last()->addItems(str);
    combo.last()->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    input->addWidget(combo.last(),0,1);
    combo.append(new QComboBox(this));
    combo.last()->addItems(str);
    combo.last()->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    input->addWidget(combo.last(),1,1);

    str.clear();
    str<<tr("自动")<<"0"<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8";
    combo.append(new QComboBox(this));
    combo.last()->addItems(str);
    combo.last()->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    input->addWidget(combo.last(),2,1);

    spin.append(new QDoubleSpinBox(this));
    spin.last()->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spin.last()->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    input->addWidget(spin.last(),0,3);
    spin.append(new QDoubleSpinBox(this));
    spin.last()->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spin.last()->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    input->addWidget(spin.last(),0,5);
    spin.append(new QDoubleSpinBox(this));
    spin.last()->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spin.last()->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    input->addWidget(spin.last(),1,3);
    spin.append(new QDoubleSpinBox(this));
    spin.last()->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spin.last()->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    input->addWidget(spin.last(),1,5);
    spin.append(new QDoubleSpinBox(this));
    spin.last()->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spin.last()->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    input->addWidget(spin.last(),2,3);
    spin.append(new QDoubleSpinBox(this));
    spin.last()->setButtonSymbols(QAbstractSpinBox::NoButtons);
    spin.last()->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    input->addWidget(spin.last(),2,5);

    ui->gridLayout->addWidget(wave.last(),size,0);
    ui->gridLayout->addLayout(input,size,1);
}

quint8 CConfigItt::getGear(double itt)
{
    if (itt <= 1500)
        return 1;
    if (itt <  2500)
        return 2;
    else
        return 3;
}

