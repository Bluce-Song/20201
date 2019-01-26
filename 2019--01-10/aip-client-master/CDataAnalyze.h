#ifndef CDATAANALYZE_H
#define CDATAANALYZE_H

#include <QWidget>
#include "MyHelper.h"
namespace Ui {
class CDataAnalyze;
}

class CDataAnalyze : public QWidget
{
    Q_OBJECT
    
public:
    explicit CDataAnalyze(QWidget *parent = 0);
    ~CDataAnalyze();
    
signals:
    void goToWidget(int win);
    void saveConfig();
public slots:
    void updateShow();
private slots:
    void on_btnExit_clicked();
private:
    Ui::CDataAnalyze *ui;
};

#endif // CDATAANALYZE_H
