#include "CConfigType.h"
#include "ui_CConfigType.h"

CConfigType::CConfigType(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CConfigType)
{
    ui->setupUi(this);

    pixmapPath<<":/image/M1S0.png"<<":/image/M1S1.png"<<":/image/M1S2.png"
             <<":/image/M1S3.png"<<":/image/M1S4.png"<<":/image/M1S1L1.png"
            <<":/image/M1S1L2.png"<<":/image/M1S1L3.png"<<":/image/None.png";

    itemName<<tr("")
           <<tr("电阻")<<tr("反嵌")<<tr("绝缘")<<tr("交耐")<<tr("直耐")
          <<tr("匝间")<<tr("功率")<<tr("低启")<<tr("泄漏")<<tr("转速")
         <<tr("PG")<<tr("EMF")<<tr("DCBL");

    btnColor = new QButtonGroup;
    btnColor->addButton(ui->btnColor1,Qt::Key_1);
    btnColor->addButton(ui->btnColor2,Qt::Key_2);
    btnColor->addButton(ui->btnColor3,Qt::Key_3);
    btnColor->addButton(ui->btnColor4,Qt::Key_4);
    btnColor->addButton(ui->btnColor5,Qt::Key_5);
    btnColor->addButton(ui->btnColor6,Qt::Key_6);
    btnColor->addButton(ui->btnColor7,Qt::Key_7);
    btnColor->addButton(ui->btnColor8,Qt::Key_8);
    connect(btnColor,SIGNAL(buttonClicked(int)),this,SLOT(buttonJudge(int)));

    btnGroup = new QButtonGroup;
    btnGroup->addButton(ui->btnType1,Qt::Key_F1);
    btnGroup->addButton(ui->btnType2,Qt::Key_F2);
    btnGroup->addButton(ui->btnType3,Qt::Key_F3);
    btnGroup->addButton(ui->btnType4,Qt::Key_F4);
    btnGroup->addButton(ui->btnType5,Qt::Key_F5);
    btnGroup->addButton(ui->btnType6,Qt::Key_F6);
    btnGroup->addButton(ui->btnType7,Qt::Key_F7);
    btnGroup->addButton(ui->btnType8,Qt::Key_F8);
    btnGroup->addButton(ui->btnType9,Qt::Key_F9);
    connect(btnGroup,SIGNAL(buttonClicked(int)),this,SLOT(buttonJudge(int)));

    ui->dockWidget->hide();

    btnAvlFun = new QButtonGroup;
    btnAvlFun->addButton(ui->btnAvlFun0,0);
    btnAvlFun->addButton(ui->btnAvlFun1,1);
    btnAvlFun->addButton(ui->btnAvlFun2,2);
    btnAvlFun->addButton(ui->btnAvlFun3,3);
    btnAvlFun->addButton(ui->btnAvlFun4,4);
    btnAvlFun->addButton(ui->btnAvlFun5,5);
    btnAvlFun->addButton(ui->btnAvlFun6,6);
    connect(btnAvlFun,SIGNAL(buttonClicked(int)),this,SLOT(buttonJudge(int)));
    for (int i=0; i<btnAvlFun->buttons().size(); i++) {
        btnAvlId.append(0);
    }
}

CConfigType::~CConfigType()
{
    delete ui;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.25
  * brief:      更新显示
******************************************************************************/
void CConfigType::updateShow()
{
    this->setFocus();
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.25
  * brief:      按键功能
******************************************************************************/
void CConfigType::buttonJudge(int id)
{
    if (id>= Qt::Key_1 && id<=Qt::Key_Z) {
        QPalette palette;
        QColor color = QColorDialog::getColor(palette.color(QPalette::Base),this);
        if (!color.isValid())
            return;
        QString str = QString("background-color:%1").arg(color.name());

        switch (id) {
        case Qt::Key_1 :
            ui->btnColor1->setStyleSheet(str);
            break;
        case Qt::Key_2 :
            ui->btnColor2->setStyleSheet(str);
            break;
        case Qt::Key_3 :
            ui->btnColor3->setStyleSheet(str);
            break;
        case Qt::Key_4 :
            ui->btnColor4->setStyleSheet(str);
            break;
        case Qt::Key_5 :
            ui->btnColor5->setStyleSheet(str);
            break;
        case Qt::Key_6 :
            ui->btnColor6->setStyleSheet(str);
            break;
        case Qt::Key_7 :
            ui->btnColor7->setStyleSheet(str);
            break;
        case Qt::Key_8 :
            ui->btnColor8->setStyleSheet(str);
            break;
        default:
            break;
        }
        return;
    }

    if (id>=0 && id <=20) {
        ui->dockWidget->hide();
        ui->tableWidgetTest->currentItem()->setText(itemName[id]);
        return;
    }

    switch (id) {
    case Qt::Key_F1:
        ui->labelType->setPixmap(QPixmap(pixmapPath[0]));
        break;
    case Qt::Key_F2:
        ui->labelType->setPixmap(QPixmap(pixmapPath[1]));
        break;
    case Qt::Key_F3:
        ui->labelType->setPixmap(QPixmap(pixmapPath[2]));
        break;
    case Qt::Key_F4:
        ui->labelType->setPixmap(QPixmap(pixmapPath[3]));
        break;
    case Qt::Key_F5:
        ui->labelType->setPixmap(QPixmap(pixmapPath[4]));
        break;
    case Qt::Key_F6:
        ui->labelType->setPixmap(QPixmap(pixmapPath[5]));
        break;
    case Qt::Key_F7:
        ui->labelType->setPixmap(QPixmap(pixmapPath[6]));
        break;
    case Qt::Key_F8:
        ui->labelType->setPixmap(QPixmap(pixmapPath[7]));
        break;
    case Qt::Key_F9:
        ui->labelType->setPixmap(QPixmap(pixmapPath[8]));
        break;
    default:
        break;
    }

}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.25
  * brief:      更新配置
******************************************************************************/
void CConfigType::updateData(QStringList p)
{
    int i=0;
    QStringList a;
    //颜色
    a = MyHelper::getParam(getWireColor,p);
    if (a.size() != btnColor->buttons().size())
        return;
    for (i=0; i<a.size(); i++) {
        QString str = QString("background-color:%1").arg(a[i]);
        btnColor->buttons()[i]->setStyleSheet(str);
    }

    //其它
    a = MyHelper::getParam(getMotorOther,p);
    if (a.size() != 1)
        return;
    if (a[0].toInt() == 0)
        ui->btnOther1->setChecked(true);
    else
        ui->btnOther2->setChecked(true);

    //电机类型
    a = MyHelper::getParam(getMotorType,p);
    if (a.size() != 1)
        return;
    for (i=0; i<a.size(); i++) {
        btnGroup->buttons()[a[i].toInt()]->setChecked(true);
        ui->labelType->setPixmap(QPixmap(pixmapPath[a[i].toInt()]));
    }

    //文件
    a = MyHelper::getParam(getMotorFile,p);
    if (!a.isEmpty()) {
        fileList.clear();
        ui->tableWidgetFile->setRowCount(a.size());
        for (i=0; i<a.size(); i++) {
            fileList.append(new QTableWidgetItem);
            fileList.last()->setTextAlignment(Qt::AlignCenter);
            fileList.last()->setText(a[i]);
            ui->tableWidgetFile->setItem(fileList.size()-1,0,fileList.last());
        }
    }
    //可用项目
    a = MyHelper::getParam(getProjEnable,p);
    if (!a.isEmpty()) {
        for (i=0; i<a.size(); i++) {
            btnAvlId[a[i].toInt()+1] = 1;
        }
        for (i=1; i<btnAvlId.size(); i++) {
            if (btnAvlId[i])
                btnAvlFun->buttons()[i]->show();
            else
                btnAvlFun->buttons()[i]->hide();
        }
    }
    a = MyHelper::getParam(getProjInUse,p);
    if (!a.isEmpty()) {
        ttList.clear();
        ui->tableWidgetTest->setRowCount(a.size());
        for (i=0; i<a.size(); i++) {
            ttList.append(new QTableWidgetItem);
            ttList.last()->setText(itemName[a[i].toInt()]);
            ttList.last()->setTextAlignment(Qt::AlignCenter);
            ui->tableWidgetTest->setItem(ttList.size()-1,0,ttList.last());
        }
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.25
  * brief:      输出配置
******************************************************************************/
QStringList CConfigType::output()
{
    QStringList out;
    QStringList k;

    k.append(getWireColor);
    for (int i=0; i<8; i++){
        QPalette palette = btnColor->buttons()[i]->palette();
        QBrush brush = palette.background();
        k.append(brush.color().name());
    }
    out.append(k.join(" "));

    k.clear();
    k.append(getMotorType);
    for (int i=0; i<9; i++) {
        if (btnGroup->buttons()[i]->isChecked())
            k.append(QString::number(i));
    }
    out.append(k.join(" "));

    k.clear();
    k.append(getMotorOther);
    if (ui->btnOther1->isChecked())
        k.append(QString::number(0));
    else
        k.append(QString::number(1));
    out.append(k.join(" "));

    k.clear();
    k.append(getProjInUse);
    for (int i=0; i<ttList.size(); i++)
        for (int j=0; j<itemName.size(); j++)
            if (ttList[i]->text() == itemName[j])
                k.append(QString::number(j));

    out.append(k.join(" "));

    return out;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.25
  * brief:      添加文件
******************************************************************************/
void CConfigType::on_btnInsert_clicked()
{
    QStringList k;
    if (ui->lineEditName->text().isEmpty())
        return;
    k.append(ui->lineEditName->text());
    if (ui->lineEditType->text().isEmpty())
        k.append("NULL");
    else
        k.append(ui->lineEditType->text());

    emit insertFile(k.join("/"));
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.04.25
  * brief:      删除文件
******************************************************************************/
void CConfigType::on_btnDelete_clicked()
{
    int row = ui->tableWidgetFile->currentRow();
    if (row < 0 || row > fileList.size())
        return;
    emit deleteFile(fileList[row]->text());
}

void CConfigType::on_btnImport_clicked()
{
    emit importFile();
}

void CConfigType::on_btnExport_clicked()
{
    int row = ui->tableWidgetFile->currentRow();
    if (row < 0 || row > fileList.size())
        return;
    emit exportFile(fileList[row]->text());
}

void CConfigType::on_btnRead_clicked()
{
    int row = ui->tableWidgetFile->currentRow();
    if (row < 0 || row > fileList.size())
        return;
    emit readFile(fileList[row]->text());
}

void CConfigType::on_btnCheck_clicked()
{
    QStringList k;
    if (ui->lineEditName->text().isEmpty())
        return;
    for (int i=0; i<fileList.size(); i++) {
        k.append(fileList[i]->text());

        if (k.last().contains(ui->lineEditName->text()))
            k.move(i,0);
    }
    for (int i=0; i<fileList.size(); i++)
        fileList[i]->setText(k[i]);
}

void CConfigType::on_pushButton_clicked()
{
    int count = ui->tableWidgetTest->rowCount();
    ui->tableWidgetTest->setRowCount(count+1);
    ttList.append(new QTableWidgetItem);
    ttList.last()->setTextAlignment(Qt::AlignCenter);
    ui->tableWidgetTest->setItem(ttList.size()-1,0,ttList.last());
}

void CConfigType::on_tableWidgetTest_cellClicked(int, int)
{
    ui->dockWidget->show();
}
