#ifndef MINPUTMETHOD_H
#define MINPUTMETHOD_H
#include "MyHelper.h"
#ifndef CLIENT
#include <QWSInputMethod>
#include "CKeyboard.h"

class MyInputMethod : public QWSInputMethod
{
    Q_OBJECT
public:
    explicit MyInputMethod();
    
public:
    void updateHandler(int);
private:
    CKeyboard* mKeyb;
    bool isCapsLock;
private slots:
    void SendString(QString);
    void SendEnter();
    void Backspace();
    void Escape();
};
#endif
#endif // MINPUTMETHOD_H
