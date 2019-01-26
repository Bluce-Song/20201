/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.30
 * brief:       软键盘界面
*******************************************************************************/
#include "CKeyboard.h"
#include "ui_CKeyboard.h"

CKeyboard::CKeyboard(QWidget *parent) :
    QWidget(parent,Qt::Tool|Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint),
    ui(new Ui::CKeyboard)
{
    ui->setupUi(this);
    btnGroup = new QButtonGroup;
    this->setKeyboard();
    connect(btnGroup,SIGNAL(buttonClicked(int)),this,SLOT(buttonJudge(int)));
    isCapsLock = true;
}

CKeyboard::~CKeyboard()
{
    delete ui;
    delete btnGroup;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      按键定义
******************************************************************************/
void CKeyboard::setKeyboard()
{
    btnGroup->addButton(ui->Key_0,Qt::Key_0);
    btnGroup->addButton(ui->Key_1,Qt::Key_1);
    btnGroup->addButton(ui->Key_2,Qt::Key_2);
    btnGroup->addButton(ui->Key_3,Qt::Key_3);
    btnGroup->addButton(ui->Key_4,Qt::Key_4);
    btnGroup->addButton(ui->Key_5,Qt::Key_5);
    btnGroup->addButton(ui->Key_6,Qt::Key_6);
    btnGroup->addButton(ui->Key_7,Qt::Key_7);
    btnGroup->addButton(ui->Key_8,Qt::Key_8);
    btnGroup->addButton(ui->Key_9,Qt::Key_9);

    btnGroup->addButton(ui->Key_A,Qt::Key_A);
    btnGroup->addButton(ui->Key_B,Qt::Key_B);
    btnGroup->addButton(ui->Key_C,Qt::Key_C);
    btnGroup->addButton(ui->Key_D,Qt::Key_D);
    btnGroup->addButton(ui->Key_E,Qt::Key_E);
    btnGroup->addButton(ui->Key_F,Qt::Key_F);
    btnGroup->addButton(ui->Key_G,Qt::Key_G);
    btnGroup->addButton(ui->Key_H,Qt::Key_H);
    btnGroup->addButton(ui->Key_I,Qt::Key_I);
    btnGroup->addButton(ui->Key_J,Qt::Key_J);
    btnGroup->addButton(ui->Key_K,Qt::Key_K);
    btnGroup->addButton(ui->Key_L,Qt::Key_L);
    btnGroup->addButton(ui->Key_M,Qt::Key_M);
    btnGroup->addButton(ui->Key_N,Qt::Key_N);
    btnGroup->addButton(ui->Key_O,Qt::Key_O);
    btnGroup->addButton(ui->Key_P,Qt::Key_P);
    btnGroup->addButton(ui->Key_Q,Qt::Key_Q);
    btnGroup->addButton(ui->Key_R,Qt::Key_R);
    btnGroup->addButton(ui->Key_S,Qt::Key_S);
    btnGroup->addButton(ui->Key_T,Qt::Key_T);
    btnGroup->addButton(ui->Key_U,Qt::Key_U);
    btnGroup->addButton(ui->Key_V,Qt::Key_V);
    btnGroup->addButton(ui->Key_W,Qt::Key_W);
    btnGroup->addButton(ui->Key_X,Qt::Key_X);
    btnGroup->addButton(ui->Key_Y,Qt::Key_Y);
    btnGroup->addButton(ui->Key_Z,Qt::Key_Z);

    btnGroup->addButton(ui->Key_Space,Qt::Key_Space);
    btnGroup->addButton(ui->Key_Enter,Qt::Key_Enter);
    btnGroup->addButton(ui->Key_Escape,Qt::Key_Escape);
    btnGroup->addButton(ui->Key_Period,Qt::Key_Period);
    btnGroup->addButton(ui->Key_CapsLock,Qt::Key_CapsLock);
    btnGroup->addButton(ui->Key_Backspace,Qt::Key_Backspace);

}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.30
  * brief:      按键功能
******************************************************************************/
void CKeyboard::buttonJudge(int id )
{
    int i;
    QString str;
    switch (id)
    {
    case Qt::Key_0 :
        emit SendString("0");
        break;
    case Qt::Key_1 :
        emit SendString("1");
        break;
    case Qt::Key_2 :
        emit SendString("2");
        break;
    case Qt::Key_3 :
        emit SendString("3");
        break;
    case Qt::Key_4 :
        emit SendString("4");
        break;
    case Qt::Key_5 :
        emit SendString("5");
        break;
    case Qt::Key_6 :
        emit SendString("6");
        break;
    case Qt::Key_7 :
        emit SendString("7");
        break;
    case Qt::Key_8 :
        emit SendString("8");
        break;
    case Qt::Key_9 :
        emit SendString("9");
        break;

    case Qt::Key_A :
        emit SendString(ui->Key_A->text());
        break;
    case Qt::Key_B :
        emit SendString(ui->Key_B->text());
        break;
    case Qt::Key_C :
        emit SendString(ui->Key_C->text());
        break;
    case Qt::Key_D :
        emit SendString(ui->Key_D->text());
        break;
    case Qt::Key_E :
        emit SendString(ui->Key_E->text());
        break;
    case Qt::Key_F :
        emit SendString(ui->Key_F->text());
        break;
    case Qt::Key_G :
        emit SendString(ui->Key_G->text());
        break;
    case Qt::Key_H :
        emit SendString(ui->Key_H->text());
        break;
    case Qt::Key_I :
        emit SendString(ui->Key_I->text());
        break;
    case Qt::Key_J :
        emit SendString(ui->Key_J->text());
        break;
    case Qt::Key_K :
        emit SendString(ui->Key_K->text());
        break;
    case Qt::Key_L :
        emit SendString(ui->Key_L->text());
        break;
    case Qt::Key_M :
        emit SendString(ui->Key_M->text());
        break;
    case Qt::Key_N :
        emit SendString(ui->Key_N->text());
        break;
    case Qt::Key_O :
        emit SendString(ui->Key_O->text());
        break;
    case Qt::Key_P :
        emit SendString(ui->Key_P->text());
        break;
    case Qt::Key_Q :
        emit SendString(ui->Key_Q->text());
        break;
    case Qt::Key_R :
        emit SendString(ui->Key_R->text());
        break;
    case Qt::Key_S :
        emit SendString(ui->Key_S->text());
        break;
    case Qt::Key_T :
        emit SendString(ui->Key_T->text());
        break;
    case Qt::Key_U :
        emit SendString(ui->Key_U->text());
        break;
    case Qt::Key_V :
        emit SendString(ui->Key_V->text());
        break;
    case Qt::Key_W :
        emit SendString(ui->Key_W->text());
        break;
    case Qt::Key_X :
        emit SendString(ui->Key_X->text());
        break;
    case Qt::Key_Y :
        emit SendString(ui->Key_Y->text());
        break;
    case Qt::Key_Z :
        emit SendString(ui->Key_Z->text());
        break;
    case Qt::Key_Space :
        emit SendString(" ");
        break;
    case Qt::Key_Period:
        emit SendString(".");
        break;
    case Qt::Key_Enter :
        emit this->SendEnter();
        break;
    case Qt::Key_Escape :
        emit this->SendEscape();
        break;
    case Qt::Key_Backspace :
        emit this->SendBackspace();
        break;
    case Qt::Key_CapsLock:
        isCapsLock = !isCapsLock;
        if (isCapsLock) {
            for (i=10; i<36; i++) {
                str = btnGroup->buttons()[i]->text().toLower();
                btnGroup->buttons()[i]->setText(str);
            }
        } else {
            for (i=10; i<36; i++) {
                str = btnGroup->buttons()[i]->text().toUpper();
                btnGroup->buttons()[i]->setText(str);
            }
        }
        break;
    default:
        emit SendString("wrong");
        break;

    }
}
void CKeyboard::moveShow()
{
    QWidget *widget = QApplication::focusWidget();
    int y = 0;
    while (widget->parentWidget() != NULL) {
        y += widget->y();
        widget = widget->parentWidget();
    }
    if (y > 300)
        this->move(70,y-250);
    else
        this->move(70,y+50);
    this->show();
}

/******************************************************************************
                                    END
******************************************************************************/
