#include "CConfigOpp.h"
#include "ui_CConfigOpp.h"

CConfigOpp::CConfigOpp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CConfigOpp)
{
    ui->setupUi(this);
}

CConfigOpp::~CConfigOpp()
{
    delete ui;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.15
  * brief:      刷新显示
******************************************************************************/
void CConfigOpp::updateShow()
{
    this->setFocus();
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.15
  * brief:      更新数据
******************************************************************************/
void CConfigOpp::updateData(QStringList param)
{
    QStringList a = MyHelper::getParam(getOppLine,param);

    while (wave.size() < a.size()/OPP_COL)
        insertWave();

    for (int i=0; i<a.size()/OPP_COL; i++) {
        if (a[i*OPP_COL+0].toInt() == 1)
            wave[i]->updateValid(true);
        else
            wave[i]->updateValid(false);

        combo[i*2+0]->setCurrentIndex(a[i*OPP_COL+1].toInt());
        combo[i*2+1]->setCurrentIndex(a[i*OPP_COL+2].toInt());

        spin[i]->setValue(a[i*OPP_COL+3].toDouble());

        wave[i]->updateWave(a[i*OPP_COL+4].toUtf8());
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.15
  * brief:      输出配置
******************************************************************************/
QStringList CConfigOpp::output()
{
    QStringList out;
    QStringList k;

    k.append(getOppLine);

    for (int i=0; i<ui->gridLayout->count(); i++) {
        if (wave[i]->isChecked())
            k.append(QString::number(1));
        else
            k.append(QString::number(0));
        k.append(QString::number(combo[i*2+0]->currentIndex()));
        k.append(QString::number(combo[i*2+1]->currentIndex()));
        k.append(QString::number(spin[i]->value()));
        k.append(wave[i]->wave());
    }
    out.append(k.join(" "));

    return out;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.15
  * brief:      下发采样命令
******************************************************************************/
QByteArray CConfigOpp::getCmdSampling()
{
    quint16 tt = 0;
    for (int i=0; i<wave.count(); i++) {
        if (wave[i]->isChecked()) {
            tt += 0x0001<<i;
        }
    }
    msg.clear();
    QDataStream out(&msg, QIODevice::ReadWrite);
    out.setVersion(QDataStream::Qt_4_8);
    out<<(quint8)0x22<<    // ID
         (quint8)0x06<<    // DLC
         (quint8)0x01<<    // 启动
         (quint8)0x02<<    // 测试组号
         (quint8)0x01<<    // 测试/采样
         (quint8)0x13<<    // 工位
         (quint8)(tt/256)<<// 测试组
         (quint8)(tt%256);
    return msg;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.15
  * brief:      下发设置参数
******************************************************************************/
QByteArray CConfigOpp::getCmdIssued()
{
    msg.clear();
    QDataStream out(&msg, QIODevice::ReadWrite);
    out.setVersion(QDataStream::Qt_4_8);
    for (int i=0; i<wave.count(); i++) {
        if (wave[i]->isChecked()) {
            out<<(quint8)0x22<<    // ID
                 (quint8)0x05<<    // DLC
                 (quint8)0x04<<    // 设置反嵌
                 (quint8)i<<       // 设置序号
                 (quint8)combo[i*2+0]->currentIndex()<< // 抽头1
                 (quint8)combo[i*2+1]->currentIndex()<< // 抽头2
                 (quint8)0x01;    // 档位
        }
    }
    return msg;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.15
  * brief:      下发启动命令
******************************************************************************/
QByteArray CConfigOpp::getCmdStart()
{
    quint16 tt = 0;
    for (int i=0; i<wave.count(); i++) {
        if (wave[i]->isChecked()) {
            tt += 0x0001<<i;
        }
    }
    msg.clear();
    QDataStream out(&msg, QIODevice::ReadWrite);
    out.setVersion(QDataStream::Qt_4_8);
    out<<(quint8)0x22<<    // ID
         (quint8)0x06<<    // DLC
         (quint8)0x01<<    // 启动
         (quint8)0x02<<    // 测试组号
         (quint8)0x00<<    // 测试/采样
         (quint8)0x13<<    // 工位
         (quint8)(tt/256)<<// 测试组
         (quint8)(tt%256);
    return msg;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.15
  * brief:      下发停止命令
******************************************************************************/
QByteArray CConfigOpp::getCmdStop()
{
    return msg;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.15
  * brief:      添加数据
******************************************************************************/
void CConfigOpp::insertWave()
{
    int size = wave.size();
    wave.append(new MyWaveLabel(this));
    wave.last()->updateSet(true);

    QStringList str;
    str<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8";

    QGridLayout *input = new QGridLayout;
    input->addWidget(new QLabel(tr("上限"),this),0,0);
    input->addWidget(new QLabel(tr("端一"),this),1,0);
    input->addWidget(new QLabel(tr("端二"),this),2,0);

    spin.append(new QDoubleSpinBox);
    spin.last()->setAlignment(Qt::AlignCenter);
    spin.last()->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    spin.last()->setButtonSymbols(QAbstractSpinBox::NoButtons);
    input->addWidget(spin.last(),0,1);
    combo.append(new QComboBox(this));
    combo.last()->addItems(str);
    combo.last()->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    input->addWidget(combo.last(),1,1);
    combo.append(new QComboBox(this));
    combo.last()->addItems(str);
    input->addWidget(combo.last(),2,1);
    combo.last()->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(wave.last());
    layout->addLayout(input);

    ui->gridLayout->addLayout(layout,size/2,size%2);
}
