#include "CConfigIns.h"
#include "ui_CConfigIns.h"

CConfigIns::CConfigIns(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CConfigIns)
{
    ui->setupUi(this);
}

CConfigIns::~CConfigIns()
{
    delete ui;
}
void CConfigIns::updateShow()
{
    this->setFocus();
}
void CConfigIns::updateData(QStringList p)
{
    QStringList a = MyHelper::getParam(getInsOther,p);
    if (!a.isEmpty()) {
        ui->spinBox1->setValue(a[0].toDouble());
        ui->spinBox2->setValue(a[1].toDouble());
        ui->spinBox3->setValue(a[2].toDouble());
        ui->spinBox4->setValue(a[3].toDouble());
    }
}

QStringList CConfigIns::output()
{
    QStringList out;
    QStringList k;
    k.append(getInsOther);
    k.append(QString::number(ui->spinBox1->value()));
    k.append(QString::number(ui->spinBox2->value()));
    k.append(QString::number(ui->spinBox3->value()));
    k.append(QString::number(ui->spinBox4->value()));
    out.append(k.join(" "));
    return out;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.15
  * brief:      下发设置参数
******************************************************************************/
QByteArray CConfigIns::getCmdIssued()
{
    msg.clear();
    QDataStream out(&msg, QIODevice::ReadWrite);
    out.setVersion(QDataStream::Qt_4_8);
    out<<(quint8)0x23<<    // ID
         (quint8)0x08<<    // DLC
         (quint8)0x03<<    // 绝缘测试参数1
         (quint8)0x01<<    // 测试组号
         (quint8)0x04<<    // 测试INS
         (quint8)0x00<<    // 高压端
         (quint8)0x00<<
         (quint8)0xff<<    // 低压端
         (quint8)0xff<<
         (quint8)0x00<<    // 频率

         (quint8)0x23<<    // ID
         (quint8)0x08<<    // DLC
         (quint8)0x04<<    // 绝缘测试参数2
         (quint8)0x01<<    // 测试组号
         (quint8)(int(ui->spinBox1->value())/256)<< // 电压
         (quint8)(int(ui->spinBox1->value())%256)<<
         (quint8)(int(ui->spinBox4->value())/256)<< // 时间
         (quint8)(int(ui->spinBox4->value())%256)<<
         (quint8)(int(ui->spinBox2->value())/256)<< // 下限/0.01mA
         (quint8)(int(ui->spinBox2->value())%256)<<

         (quint8)0x23<<    // ID
         (quint8)0x07<<    // DLC
         (quint8)0x05<<    // 绝缘测试参数3
         (quint8)0x01<<    // 测试组号
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
QByteArray CConfigIns::getCmdStart()
{
    msg.clear();
    QDataStream out(&msg, QIODevice::ReadWrite);
    out.setVersion(QDataStream::Qt_4_8);
    out<<(quint8)0x23<<    // ID
         (quint8)0x05<<    // DLC
         (quint8)0x01<<    // 启动
         (quint8)0x04<<    // 测试组号
         (quint8)0x00<<    // 档位
         (quint8)0x13<<    // 工位
         (quint8)0x01;     // 测试组
    return msg;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.15
  * brief:      下发停止命令
******************************************************************************/
QByteArray CConfigIns::getCmdStop()
{
    return msg;
}

