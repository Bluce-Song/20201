#ifndef CSYSTEMSET_H
#define CSYSTEMSET_H

#include <QWidget>
#include "MyHelper.h"
namespace Ui {
class CSystemSet;
}

class CSystemSet : public QWidget
{
    Q_OBJECT
    
public:
    explicit CSystemSet(QWidget *parent = 0);
    ~CSystemSet();
    
signals:
    void goToWidget(int win);
    void saveConfig();
public slots:
    void updateShow();
private slots:
    void on_btnExit_clicked();
private:
    Ui::CSystemSet *ui;
};

#endif // CSYSTEMSET_H
