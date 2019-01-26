#ifndef CHOMESCREEN_H
#define CHOMESCREEN_H

#include <QWidget>
#include <QButtonGroup>
#include "MyHelper.h"

namespace Ui {
class CHomeScreen;
}

class CHomeScreen : public QWidget
{
    Q_OBJECT
signals:
    void goToWidget(int win);
public slots:
    void updatePrograssBar(int per);
    void updateButton();
public:
    explicit CHomeScreen(QWidget *parent = 0);
    ~CHomeScreen();
private slots:
    void buttonJudge(int id);
private:
    Ui::CHomeScreen *ui;
    QButtonGroup *btnGroup;
};

#endif // CHOMESCREEN_H
