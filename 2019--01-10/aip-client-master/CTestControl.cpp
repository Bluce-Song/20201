#include "CTestControl.h"
#include "ui_CTestControl.h"

CTestControl::CTestControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CTestControl)
{
    ui->setupUi(this);
    int i;
    for (i=0; i<12; i++) {
        insertRow();
    }
    color.append(ui->labelColor1);
    color.append(ui->labelColor2);
    color.append(ui->labelColor3);
    color.append(ui->labelColor4);
    color.append(ui->labelColor5);
    color.append(ui->labelColor6);
    color.append(ui->labelColor7);
    color.append(ui->labelColor8);
    itemCount = 0;
    waveCount = 0;
}

CTestControl::~CTestControl()
{
    delete ui;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.27
  * brief:      更新显示
******************************************************************************/
void CTestControl::updateShow()
{
    this->setFocus();
    ui->tableWidgetTest->setColumnWidth(0,50);
    ui->tableWidgetTest->setColumnWidth(1,(ui->tableWidgetTest->width()-50)*15/100);
    ui->tableWidgetTest->setColumnWidth(2,(ui->tableWidgetTest->width()-50)*45/100);
    ui->tableWidgetTest->setColumnWidth(3,(ui->tableWidgetTest->width()-50)*25/100);
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.27
  * brief:      更新测试数据
******************************************************************************/
void CTestControl::updateData(QStringList p)
{
    int i;
    int row=0;
    int column=0;
    QLabel *label;
    QStringList a,b;
    //颜色
    a = getParam(getWireColor,p);
    if (!a.isEmpty()) {
        for (i=0; i<a.size(); i++) {
            QString str = "background-color:";
            str += a[i];
            color[i]->setStyleSheet(str);
        }
    }
    //测试项目
    a = getParam(getProjInUse,p);
    item.clear();
    param.clear();
    for (i=0; i<wave.size(); i++)
        wave[i]->hide();

    wave.clear();

    for (i=0; i<a.size(); i++) {
        switch (a[i].toInt()) {
        case 1:
            b = getParam(getResLine,p);
            while(b.size()>0) {
                if (b[0] == "√") {
                    item.append(QString("电阻%1-%2").arg(b[1].toInt()+1).arg(b[2].toInt()+1));
                    param.append(QString("下限:%1Ω,上限:%2Ω").arg(b[4]).arg(b[5]));
                    itemCount++;
                }
                b.removeFirst();
                b.removeFirst();
                b.removeFirst();
                b.removeFirst();
                b.removeFirst();
                b.removeFirst();
                b.removeFirst();
            }
            break;
        case 2:
            b = getParam(getOppLine,p);
            while(b.size()>0) {
                if (b[0].toInt() == 1) {

                    item.append(QString("反嵌%1-%2").arg(b[1].toInt()+1).arg(b[2].toInt()+1));
                    param.append(QString("上限:%1%").arg(b[3]));

                    wave.append(new MyWaveLabel(this));
                    wave.last()->setMinimumSize(200,128);
                    wave.last()->setMaximumSize(200,128);
                    wave.last()->updateText(item.last());
                    wave.last()->updateWave(b[4].toUtf8());
                    wave.last()->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);


                    if (column == 3) {
                        column = 0;
                        row++;
                    }
                    ui->gridLayout->addWidget(wave.last(),row,column);
                    column++;
                    waveCount++;
                }
                b.removeFirst();
                b.removeFirst();
                b.removeFirst();
                b.removeFirst();
                b.removeFirst();
            }
            while(column != 3) {
                label = new QLabel(this);
                label->setMaximumSize(200,128);
                ui->gridLayout->addWidget(label,row,column);
                column++;
            }
            break;
        case 3:
            b = getParam(getInsOther,p);
            while(b.size()>0) {
                item.append(tr("绝缘"));
                param.append(QString("%1V,%2MΩ~%3MΩ,%4s").arg(b[0]).arg(b[1]).arg(b[2]).arg(b[3]));
                b.removeFirst();
                b.removeFirst();
                b.removeFirst();
                b.removeFirst();
            }
            break;
        case 4:
            b = getParam(getAcvOther,p);
            while(b.size()>0) {
                item.append(tr("交耐"));
                param.append(QString("%1V,%2mA~%3mA,ARC:%4").arg(b[0]).arg(b[1]).arg(b[2]).arg(b[3]));
                b.removeFirst();
                b.removeFirst();
                b.removeFirst();
                b.removeFirst();
                b.removeFirst();
                b.removeFirst();
            }
            break;
        case 5:
            b = getParam(getDcvOther,p);
            while(b.size()>0) {
                item.append(tr("直耐"));
                param.append(QString("%1V,%2mA~%3mA,ARC:%4").arg(b[0]).arg(b[1]).arg(b[2]).arg(b[3]));
                b.removeFirst();
                b.removeFirst();
                b.removeFirst();
                b.removeFirst();
                b.removeFirst();
            }
            break;
        case 6:
            break;
        default:
            break;
        }
    }
    QSpacerItem *verticalSpacer = new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);
    ui->gridLayout->addItem(verticalSpacer, row, 0);
    while (ui->tableWidgetTest->rowCount() < item.size())
        insertRow();

    for (i=0; i<item.size(); i++) {
        testList[i*5+0]->setText(QString::number(i+1));
        testList[i*5+1]->setText(item[i]);
        testList[i*5+2]->setText(param[i]);
    }
    for (i=item.size(); i<testList.size()/5; i++) {
        testList[i*5+0]->setText("");
        testList[i*5+1]->setText("");
        testList[i*5+2]->setText("");
        testList[i*5+3]->setText("");
        testList[i*5+4]->setText("");
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.27
  * brief:      更新时间
******************************************************************************/
void CTestControl::updateTime()
{
    ui->labelTime->setText(QTime::currentTime().toString());
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.27
  * brief:      更新温度
******************************************************************************/
void CTestControl::updateTemp(int temp)
{
    int integer = temp/10;
    int decimal = temp%10;
    QString t = QString("温度:%1.%2°C").arg(integer).arg(decimal);
    ui->labelTemp->setText(t);
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.03.24
  * brief:      获取参数
******************************************************************************/
QStringList CTestControl::getParam(QString type, QStringList p)
{
    QStringList k;
    for (int i=0; i<p.size(); i++) {
        if (p[i].startsWith(type)) {
            k = p[i].split(" ");
            k.removeFirst();
            break;
        }
    }
    return k;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.03.24
  * brief:      添加一行
******************************************************************************/
void CTestControl::insertRow()
{
    int row = ui->tableWidgetTest->rowCount();
    ui->tableWidgetTest->setRowCount(row+1);
    testList.append(new QTableWidgetItem);
    testList.last()->setTextAlignment(Qt::AlignCenter);
    ui->tableWidgetTest->setItem(row,0,testList.last());
    testList.append(new QTableWidgetItem);
    testList.last()->setTextAlignment(Qt::AlignCenter);
    ui->tableWidgetTest->setItem(row,1,testList.last());
    testList.append(new QTableWidgetItem);
    ui->tableWidgetTest->setItem(row,2,testList.last());
    testList.append(new QTableWidgetItem);
    ui->tableWidgetTest->setItem(row,3,testList.last());
    testList.append(new QTableWidgetItem);
    ui->tableWidgetTest->setItem(row,4,testList.last());
}
void CTestControl::on_pushButtonExit_clicked()
{
    emit goToWidget(W_HOME);
}

void CTestControl::on_pushButtonConf_clicked()
{
    emit goToWidget(W_CONF);
}
