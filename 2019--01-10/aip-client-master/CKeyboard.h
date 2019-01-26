#ifndef MKEYBOARD_H
#define MKEYBOARD_H

#include <QWidget>
#include <QButtonGroup>
namespace Ui {
class CKeyboard;
}

class CKeyboard : public QWidget
{
    Q_OBJECT
    
public:
    explicit CKeyboard(QWidget *parent = 0);
    ~CKeyboard();
    
private:
    Ui::CKeyboard *ui;

signals:
    void SendString(QString);
    void SendEnter();
    void SendBackspace();
    void SendEscape();
    void SendCapsLock();
public slots:
    void moveShow();
private slots:
    void setKeyboard();
    void buttonJudge(int);
private:
    QButtonGroup *btnGroup;
    bool isCapsLock;


};

#endif // MKEYBOARD_H
