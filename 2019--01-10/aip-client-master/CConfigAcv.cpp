#include "CConfigAcv.h"
#include "ui_CConfigAcv.h"

CConfigAcv::CConfigAcv(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CConfigAcv)
{
    ui->setupUi(this);
}

CConfigAcv::~CConfigAcv()
{
    delete ui;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.15
  * brief:      更新显示
******************************************************************************/
void CConfigAcv::updateShow()
{
    this->setFocus();
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.15
  * brief:      更新设置参数
******************************************************************************/
void CConfigAcv::updateData(QStringList p)
{
    QStringList a = MyHelper::getParam(getAcvOther,p);
    if (!a.isEmpty()) {
        ui->spinBox1->setValue(a[0].toDouble());
        ui->spinBox2->setValue(a[1].toDouble());
        ui->spinBox3->setValue(a[2].toDouble());
        ui->spinBox4->setValue(a[3].toDouble());
        ui->spinBox5->setValue(a[4].toDouble());
        ui->spinBox6->setValue(a[5].toDouble());
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.15
  * brief:      输出保存设置参数
******************************************************************************/
QStringList CConfigAcv::output()
{
    QStringList out;
    QStringList k;
    k.append(getAcvOther);
    k.append(QString::number(ui->spinBox1->value()));
    k.append(QString::number(ui->spinBox2->value()));
    k.append(QString::number(ui->spinBox3->value()));
    k.append(QString::number(ui->spinBox4->value()));
    k.append(QString::number(ui->spinBox5->value()));
    k.append(QString::number(ui->spinBox6->value()));
    out.append(k.join(" "));
    return out;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.15
  * brief:      下发设置参数
******************************************************************************/
QByteArray CConfigAcv::getCmdIssued()
{
    msg.clear();
    QDataStream out(&msg, QIODevice::ReadWrite);
    out.setVersion(QDataStream::Qt_4_8);
    out<<(quint8)0x23<<    // ID
         (quint8)0x08<<    // DLC
         (quint8)0x03<<    // 交耐测试参数1
         (quint8)0x00<<    // 测试组号
         (quint8)0x05<<    // 测试ACV
         (quint8)0x00<<    // 高压端
         (quint8)0x00<<
         (quint8)0xff<<    // 低压端
         (quint8)0xff<<
         (quint8)(int(ui->spinBox6->value())%256)<< // 频率

         (quint8)0x23<<    // ID
         (quint8)0x08<<    // DLC
         (quint8)0x04<<    // 交耐测试参数2
         (quint8)0x00<<    // 测试组号
         (quint8)(int(ui->spinBox1->value())/256)<< // 电压
         (quint8)(int(ui->spinBox1->value())%256)<<
         (quint8)(int(ui->spinBox5->value())/256)<< // 时间
         (quint8)(int(ui->spinBox5->value())%256)<<
         (quint8)(int(ui->spinBox2->value())/256)<< // 下限/0.01mA
         (quint8)(int(ui->spinBox2->value())%256)<<

         (quint8)0x23<<    // ID
         (quint8)0x07<<    // DLC
         (quint8)0x05<<    // 交耐测试参数3
         (quint8)0x00<<    // 测试组号
         (quint8)(int(ui->spinBox3->value())/256)<< // 上限/0.01mA
         (quint8)(int(ui->spinBox3->value())%256)<<
         (quint8)0x00<<    // 电弧等级
         (quint8)0x03<<    // 缓升
         (quint8)0x0A;     // 缓降

    return msg;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.15
  * brief:      下发启动命令
******************************************************************************/
QByteArray CConfigAcv::getCmdStart()
{
    msg.clear();
    QDataStream out(&msg, QIODevice::ReadWrite);
    out.setVersion(QDataStream::Qt_4_8);
    out<<(quint8)0x23<<    // ID
         (quint8)0x05<<    // DLC
         (quint8)0x01<<    // 启动
         (quint8)0x05<<    // 测试组号
         (quint8)0x00<<    // 档位
         (quint8)0x13<<    // 工位
         (quint8)0x00;     // 测试组
    return msg;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.15
  * brief:      下发停止命令
******************************************************************************/
QByteArray CConfigAcv::getCmdStop()
{
    return msg;
}
