/********************************************************************************
** Form generated from reading UI file 'CMainScreen.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CMAINSCREEN_H
#define UI_CMAINSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CMainScreen
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tabDevice;
    QTableWidget *tabSoftware;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnUpdate;
    QPushButton *KeyReset;
    QPushButton *btnRun;
    QPushButton *btnDelete;
    QPushButton *btnExit;
    QLineEdit *textFile;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *CMainScreen)
    {
        if (CMainScreen->objectName().isEmpty())
            CMainScreen->setObjectName(QString::fromUtf8("CMainScreen"));
        CMainScreen->resize(800, 600);
        verticalLayout_3 = new QVBoxLayout(CMainScreen);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_2 = new QWidget(CMainScreen);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMinimumSize(QSize(100, 0));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabDevice = new QTableWidget(widget_2);
        if (tabDevice->columnCount() < 1)
            tabDevice->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabDevice->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tabDevice->setObjectName(QString::fromUtf8("tabDevice"));
        tabDevice->setMaximumSize(QSize(150, 16777215));
        tabDevice->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tabDevice->setSelectionMode(QAbstractItemView::SingleSelection);
        tabDevice->setTextElideMode(Qt::ElideMiddle);
        tabDevice->horizontalHeader()->setStretchLastSection(true);
        tabDevice->verticalHeader()->setVisible(false);

        horizontalLayout->addWidget(tabDevice);

        tabSoftware = new QTableWidget(widget_2);
        if (tabSoftware->columnCount() < 1)
            tabSoftware->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tabSoftware->setHorizontalHeaderItem(0, __qtablewidgetitem1);
        tabSoftware->setObjectName(QString::fromUtf8("tabSoftware"));
        tabSoftware->setSelectionMode(QAbstractItemView::SingleSelection);
        tabSoftware->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout->addWidget(tabSoftware);

        widget = new QWidget(widget_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btnUpdate = new QPushButton(widget);
        btnUpdate->setObjectName(QString::fromUtf8("btnUpdate"));
        btnUpdate->setMinimumSize(QSize(100, 50));

        verticalLayout->addWidget(btnUpdate);

        KeyReset = new QPushButton(widget);
        KeyReset->setObjectName(QString::fromUtf8("KeyReset"));
        KeyReset->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(KeyReset);

        btnRun = new QPushButton(widget);
        btnRun->setObjectName(QString::fromUtf8("btnRun"));
        btnRun->setMinimumSize(QSize(100, 50));

        verticalLayout->addWidget(btnRun);

        btnDelete = new QPushButton(widget);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));
        btnDelete->setMinimumSize(QSize(100, 50));

        verticalLayout->addWidget(btnDelete);

        btnExit = new QPushButton(widget);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setMinimumSize(QSize(100, 50));

        verticalLayout->addWidget(btnExit);

        textFile = new QLineEdit(widget);
        textFile->setObjectName(QString::fromUtf8("textFile"));

        verticalLayout->addWidget(textFile);

        textBrowser = new QTextBrowser(widget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        horizontalLayout->addWidget(widget);


        verticalLayout_3->addWidget(widget_2);


        retranslateUi(CMainScreen);

        QMetaObject::connectSlotsByName(CMainScreen);
    } // setupUi

    void retranslateUi(QWidget *CMainScreen)
    {
        CMainScreen->setWindowTitle(QApplication::translate("CMainScreen", "CMainScreen", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tabDevice->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CMainScreen", "\345\275\223\345\211\215\350\256\276\345\244\207", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tabSoftware->horizontalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("CMainScreen", "\345\217\257\347\224\250\345\215\207\347\272\247\345\214\205", 0, QApplication::UnicodeUTF8));
        btnUpdate->setText(QApplication::translate("CMainScreen", "\345\274\200\345\247\213\345\215\207\347\272\247", 0, QApplication::UnicodeUTF8));
        KeyReset->setText(QApplication::translate("CMainScreen", "\351\207\215\345\220\257\350\256\276\345\244\207", 0, QApplication::UnicodeUTF8));
        btnRun->setText(QApplication::translate("CMainScreen", "\350\277\220\350\241\214\347\250\213\345\272\217", 0, QApplication::UnicodeUTF8));
        btnDelete->setText(QApplication::translate("CMainScreen", "\345\210\240\351\231\244\345\215\207\347\272\247\345\214\205", 0, QApplication::UnicodeUTF8));
        btnExit->setText(QApplication::translate("CMainScreen", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        textFile->setText(QApplication::translate("CMainScreen", "/mnt/nfs/FreeRTOS.bin", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CMainScreen: public Ui_CMainScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMAINSCREEN_H
