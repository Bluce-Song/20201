/*******************************************************************************
 * Copyright (c) 2015,青岛艾普智能仪器有限公司
 * All rights reserved.
 *
 * version:     1.0
 * author:      link
 * date:        2015.12.29
 * brief:       输入法
*******************************************************************************/
#include "MyInputMethod.h"
#ifndef CLIENT
MyInputMethod::MyInputMethod()
{
    mKeyb =NULL;
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.29
  * brief:      输入
******************************************************************************/
void MyInputMethod::SendString(QString newcontent)
{
    sendCommitString(newcontent,0,0);
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.29
  * brief:      确认输入
******************************************************************************/
void MyInputMethod::SendEnter()
{
    if (NULL == mKeyb)
        return;
    else
        mKeyb->hide();
    QApplication::focusWidget()->clearFocus();
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.29
  * brief:      删除
******************************************************************************/
void MyInputMethod::Backspace()
{
    sendCommitString("",-1,1);
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.29
  * brief:      退出
******************************************************************************/
void MyInputMethod::Escape()
{
    if (NULL == mKeyb)
        return;
    else
        mKeyb->hide();
    QApplication::focusWidget()->clearFocus();
}
/******************************************************************************
  * version:    1.0
  * author:     link
  * date:       2015.12.29
  * brief:      输入法启动
******************************************************************************/
void MyInputMethod::updateHandler(int type)
{
    switch (type)
    {
    case QWSInputMethod::FocusIn:
        if (NULL==mKeyb){
            mKeyb = new CKeyboard;
            connect(mKeyb,SIGNAL(SendString(QString)),
                    this,SLOT(SendString(QString)));
            connect(mKeyb,SIGNAL(SendEnter()),this,SLOT(SendEnter()));
            connect(mKeyb,SIGNAL(SendBackspace()),this,SLOT(Backspace()));
            connect(mKeyb,SIGNAL(SendEscape()),this,SLOT(Escape()));
        }
        mKeyb->moveShow();

        break;
    case QWSInputMethod::FocusOut:
        if(NULL==mKeyb)
            break;
        else
            mKeyb->hide();
        break;
    default:
        break;
    }
}
#endif //CLIENT
/******************************************************************************
                                    END
******************************************************************************/
