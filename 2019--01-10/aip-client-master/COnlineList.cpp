#include "COnlineList.h"
#include "ui_COnlineList.h"

COnlineList::COnlineList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::COnlineList)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
    for (int i=0; i<W_ROW*W_COL; i++) {
        pItem.append(new QTableWidgetItem);
        pItem[i]->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i/W_COL,i%W_COL,pItem[i]);
    }
    btnGroup = new QButtonGroup;
    btnGroup->addButton(ui->btnExit,Qt::Key_0);
    btnGroup->addButton(ui->btnLoad,Qt::Key_1);
    btnGroup->addButton(ui->btnRead,Qt::Key_2);
    btnGroup->addButton(ui->btnTest,Qt::Key_3);
    btnGroup->addButton(ui->btnCmd ,Qt::Key_4);
    btnGroup->addButton(ui->btnFile,Qt::Key_5);
    connect(btnGroup,SIGNAL(buttonClicked(int)),this,SLOT(buttonJudge(int)));
}
COnlineList::~COnlineList()
{
    delete ui;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.03.22
  * brief:      更新显示
******************************************************************************/
void COnlineList::updateShow()
{
    this->setFocus();
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.03.22
  * brief:      刷新列表
******************************************************************************/
void COnlineList::updateData(QString str)
{
    int i;
    QStringList item = str.split(" ");
    for (i=0; i<item.size(); i++) {
        pItem[i]->setText(item[i]);
    }
    ClientIndex.clear();
    for (i=0; i<item.size()/W_COL; i++)
        ClientIndex.append(item[i*W_COL].toInt());
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.03.22
  * brief:      显示收到的数据
******************************************************************************/
void COnlineList::updateText(QString str)
{
    ui->lineEdit->setText(str);
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.03.22
  * brief:      按钮功能
******************************************************************************/
void COnlineList::buttonJudge(int id)
{
    int ret;
    quint64 type;
    QString fileName;
    switch (id) {
    case Qt::Key_0:
        emit goToWidget(W_HOME);
        break;
    case Qt::Key_1:
        emit SendMessage(getOnlineList,ServerIndex,Empty);
        break;
    case Qt::Key_2:
        ret = ui->tableWidget->currentRow();
        if (ret < 0)
            return;
        currentIndex = ClientIndex[ret];
        emit SendMessage(getFileActive,ClientIndex[ret],Empty);
        emit SendMessage(getFileExist,ClientIndex[ret],Empty);
        emit SendMessage(getConfig,ClientIndex[ret],Empty);
        break;
    case Qt::Key_3:
        emit goToWidget(W_TEST);
        break;
    case Qt::Key_4:
        ret = ui->tableWidget->currentRow();
        if (ret < 0)
            return;
        if (ui->lineEditCmd->text().isEmpty())
            return;
        type = (quint64)ui->lineEditCmd->text().toInt();
        emit SendMessage(type,ClientIndex[ret],Empty);
        break;
    case Qt::Key_5:
        ret = ui->tableWidget->currentRow();
        if (ret < 0)
            return;
        if (ui->lineEditFile->text().isEmpty())
            return;
        fileName = ui->lineEditFile->text();
        emit SendFile(ClientIndex[ret], fileName);
        break;
    default:
        break;
    }
}
