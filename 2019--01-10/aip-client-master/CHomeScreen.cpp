#include "CHomeScreen.h"
#include "ui_CHomeScreen.h"

CHomeScreen::CHomeScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CHomeScreen)
{
    ui->setupUi(this);
    btnGroup = new QButtonGroup;
    btnGroup->addButton(ui->btnOnline,Qt::Key_0);
    btnGroup->addButton(ui->btnSystem,Qt::Key_1);
    btnGroup->addButton(ui->btnConfig,Qt::Key_2);
    btnGroup->addButton(ui->btnData,Qt::Key_3);
    btnGroup->addButton(ui->btnTest,Qt::Key_4);
    btnGroup->addButton(ui->btnExit,Qt::Key_5);
    connect(btnGroup,SIGNAL(buttonClicked(int)),this,SLOT(buttonJudge(int)));
}

CHomeScreen::~CHomeScreen()
{
    delete ui;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.03.24
  * brief:      切换窗口
******************************************************************************/
void CHomeScreen::buttonJudge(int id)
{
    switch (id) {
    case Qt::Key_0:
        emit goToWidget(W_LIST);
        break;
    case Qt::Key_1:
        emit goToWidget(W_SYST);
        break;
    case Qt::Key_2:
        emit goToWidget(W_CONF);
        break;
    case Qt::Key_3:
        emit goToWidget(W_DATA);
        break;
    case Qt::Key_4:
        emit goToWidget(W_TEST);
        break;
    case Qt::Key_5:
        emit goToWidget(W_EXIT);
        break;
    default:
        break;
    }
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2016.03.24
  * brief:      更新进度条
******************************************************************************/
void CHomeScreen::updatePrograssBar(int per)
{
    if (per < W_INIT)
        ui->progressBar->setValue(per*100/W_INIT);
    if (per == W_INIT)
        ui->progressBar->hide();
}

void CHomeScreen::updateButton()
{
    ui->btnOnline->hide();
}

