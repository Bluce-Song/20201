#include "CConfigRes.h"
#include "ui_CConfigRes.h"

CConfigRes::CConfigRes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CConfigRes)
{
    ui->setupUi(this);
    ui->dockWidget->hide();

    btnGroup = new QButtonGroup;
    btnGroup->addButton(ui->btnInsert,Qt::Key_A);
    btnGroup->addButton(ui->btnDelete,Qt::Key_B);
    btnGroup->addButton(ui->btnAuto,Qt::Key_C);
    btnGroup->addButton(ui->Key_1,1);
    btnGroup->addButton(ui->Key_2,2);
    btnGroup->addButton(ui->Key_3,3);
    btnGroup->addButton(ui->Key_4,4);
    btnGroup->addButton(ui->Key_5,5);
    btnGroup->addButton(ui->Key_6,6);
    btnGroup->addButton(ui->Key_7,7);
    btnGroup->addButton(ui->Key_8,8);
    connect(btnGroup,SIGNAL(buttonClicked(int)),this,SLOT(buttonJudge(int)));
}

CConfigRes::~CConfigRes()
{
    delete ui;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.15
  * brief:      刷新显示
******************************************************************************/
void CConfigRes::updateShow()
{
    this->setFocus();
    ui->tableWidget->setColumnWidth(0,60);
    ui->tableWidget->setColumnWidth(1,60);
    ui->tableWidget->setColumnWidth(2,60);
    ui->tableWidget->setColumnWidth(3,100);
    ui->tableWidget->setColumnWidth(4,(ui->tableWidget->width()-280)/3);
    ui->tableWidget->setColumnWidth(5,(ui->tableWidget->width()-280)/3);
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.15
  * brief:      更新数据
******************************************************************************/
void CConfigRes::updateData(QStringList p)
{
    QStringList a;

    a = MyHelper::getParam(getResOther,p);
    if (!a.isEmpty()) {
        ui->doubleSpinBoxA->setValue(a[0].toDouble());
        ui->doubleSpinBoxB->setValue(a[1].toDouble());
        ui->doubleSpinBoxC->setValue(a[2].toDouble());
        ui->doubleSpinBoxD->setValue(a[3].toDouble());
        ui->doubleSpinBoxE->setValue(a[4].toDouble());
    }
    a = MyHelper::getParam(getResLine,p);
    if (!a.isEmpty()) {
        while (ui->tableWidget->rowCount() < a.size()/RES_COL) {
            insertRow();
        }
        while (ui->tableWidget->rowCount() > a.size()/RES_COL) {
            deleteRow();
        }
        for (int i=0; i<a.size(); i++)
            pLineList[i]->setText(a[i]);
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.15
  * brief:      输出配置
******************************************************************************/
QStringList CConfigRes::output()
{
    QStringList out;
    QStringList k;

    k.append(getResOther);
    k.append(QString::number(ui->doubleSpinBoxA->value()));
    k.append(QString::number(ui->doubleSpinBoxB->value()));
    k.append(QString::number(ui->doubleSpinBoxC->value()));
    k.append(QString::number(ui->doubleSpinBoxD->value()));
    k.append(QString::number(ui->doubleSpinBoxE->value()));
    out.append(k.join(" "));

    k.clear();
    k.append(getResLine);
    for (int i=0; i<pLineList.size(); i++)
        k.append(pLineList[i]->text());

    out.append(k.join(" "));

    return out;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.15
  * brief:      下发设置参数
******************************************************************************/
QByteArray CConfigRes::getCmdIssued()
{
    msg.clear();
    QDataStream out(&msg, QIODevice::ReadWrite);
    out.setVersion(QDataStream::Qt_4_8);
    for (int i=0; i<ui->tableWidget->rowCount(); i++) {
        if (ui->tableWidget->item(i,0)->text() == "√") {
            int gear = getGear(ui->tableWidget->item(i,5)->text().toDouble());
            out<<(quint8)0x22<<    // ID
                 (quint8)0x06<<    // DLC
                 (quint8)0x03<<    // 设置电阻
                 (quint8)i<<       // 设置序号
                 (quint8)ui->tableWidget->item(i,1)->text().toInt()<< // 抽头1
                 (quint8)ui->tableWidget->item(i,2)->text().toInt()<< // 抽头2
                 (quint8)gear<<    // 档位
                 (quint8)(ui->doubleSpinBoxC->value()*100); // 测试时间
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
QByteArray CConfigRes::getCmdStart()
{
    quint16 tt = 0;
    for (int i=0; i<ui->tableWidget->rowCount(); i++) {
        if (ui->tableWidget->item(i,0)->text() == "√")
            tt += 0x0001<<i;
    }
    msg.clear();
    QDataStream out(&msg, QIODevice::ReadWrite);
    out.setVersion(QDataStream::Qt_4_8);
    out<<(quint8)0x22<<    // ID
         (quint8)0x06<<    // DLC
         (quint8)0x01<<    // 启动
         (quint8)0x01<<    // 测试组号
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
QByteArray CConfigRes::getCmdStop()
{
    msg.clear();
    QDataStream out(&msg, QIODevice::ReadWrite);
    out.setVersion(QDataStream::Qt_4_8);
    out<<(quint8)0x22<<    // ID
         (quint8)0x01<<    // DLC
         (quint8)0x02;     // 停止
    return msg;
}

void CConfigRes::buttonJudge(int id)
{
    int i;
    double std;
    double lower;
    double upper;

    switch (id) {
    case Qt::Key_A:
        insertRow();
        break;
    case Qt::Key_B:
        deleteRow();
        break;
    case Qt::Key_C:
        for (i=0; i<ui->tableWidget->rowCount(); i++) {
            std = ui->tableWidget->item(i,6)->text().toDouble();
            lower = std*(100-ui->doubleSpinBoxD->value())/100;
            upper = std*(100+ui->doubleSpinBoxE->value())/100;

            ui->tableWidget->item(i,4)->setText(QString::number(lower,10,5));
            ui->tableWidget->item(i,5)->setText(QString::number(upper,10,5));
        }
        break;
    default:
        ui->dockWidget->hide();
        ui->tableWidget->currentItem()->setText(QString::number(id));
        break;
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.15
  * brief:      添加行
******************************************************************************/
void CConfigRes::insertRow()
{
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(row+1);

    for (int i=0; i<RES_COL; i++) {
        pLineList.append(new QTableWidgetItem);
        if (i<=3)
            pLineList.last()->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        pLineList.last()->setTextAlignment(Qt::AlignCenter);

        ui->tableWidget->setItem(row,i,pLineList.last());
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.15
  * brief:      删除行
******************************************************************************/
void CConfigRes::deleteRow()
{
    int row = ui->tableWidget->rowCount();
    if (row > 0) {
        ui->tableWidget->setRowCount(row-1);
        for (int i=0; i<RES_COL; i++)
            pLineList.removeLast();
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.03.24
  * brief:      获取档位
******************************************************************************/
quint8 CConfigRes::getGear(double res)
{
    if (res <= 0.2)
        return 1;
    if (res <= 2)
        return 2;
    if (res <= 20)
        return 3;
    if (res <= 200)
        return 4;
    if (res <= 2000)
        return 5;
    if (res <= 20000)
        return 6;
    else
        return 7;
}

void CConfigRes::on_tableWidget_cellClicked(int row, int column)
{
    ui->dockWidget->hide();
    if (column == 0) {
        if (ui->tableWidget->item(row,column)->text() == "√")
            ui->tableWidget->item(row,column)->setText("X");
        else
            ui->tableWidget->item(row,column)->setText("√");
        return;
    }
    if (column == 3) {
        if (ui->tableWidget->item(row,column)->text() == tr("铜")) {
            ui->tableWidget->item(row,column)->setText(tr("铝"));
            return;
        }
        if (ui->tableWidget->item(row,column)->text() == tr("铝")) {
            ui->tableWidget->item(row,column)->setText(tr("铜铝混合"));
            return;
        }
        ui->tableWidget->item(row,column)->setText(tr("铜"));
        return;
    }

    if (column==1 || column==2)
        ui->dockWidget->show();
}

