#ifndef CCONFIGTYPE_H
#define CCONFIGTYPE_H

#include <QWidget>
#include <QLayout>
#include <QComboBox>
#include <QDockWidget>
#include <QPushButton>
#include <QRadioButton>
#include <QColorDialog>
#include <QTableWidgetItem>

#include "MyHelper.h"
namespace Ui {
class CConfigType;
}

class CConfigType : public QWidget
{
    Q_OBJECT
    
public:
    explicit CConfigType(QWidget *parent = 0);
    ~CConfigType();
    
private:
    Ui::CConfigType *ui;

signals:
    void insertFile(QString fileName);
    void deleteFile(QString fileName);
    void updateFile(QString fileName);
    void importFile();
    void exportFile(QString fileName);
    void readFile(QString fileName);
public slots:
    void updateShow();
    void updateData(QStringList p);
    QStringList output();

private slots:
    void buttonJudge(int);

    void on_btnInsert_clicked();
    void on_btnDelete_clicked();
    void on_btnImport_clicked();
    void on_btnExport_clicked();
    void on_btnRead_clicked();
    void on_btnCheck_clicked();

    void on_pushButton_clicked();

    void on_tableWidgetTest_cellClicked(int row, int column);

private:
    QStringList pixmapPath;
    QStringList itemName;

    QList<QTableWidgetItem *> fileList;
    QList<int >fileId;
    QList<QComboBox *> testList;
    QList<QTableWidgetItem *> ttList;
    QButtonGroup *btnGroup;
    QButtonGroup *btnColor;
    QButtonGroup *btnAvlFun;
    QList<int > btnAvlId;
};

#endif // CCONFIGTYPE_H
