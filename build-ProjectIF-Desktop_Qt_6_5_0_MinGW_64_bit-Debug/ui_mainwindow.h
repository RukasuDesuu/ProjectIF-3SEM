/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *pag1;
    QGridLayout *gridLayout;
    QLineEdit *inTxt;
    QLineEdit *tensaoTxt;
    QLabel *tensaolbl;
    QLabel *ipinlbl;
    QLineEdit *ipinTxt;
    QLabel *potlbl;
    QLabel *freqlbl;
    QLineEdit *freqTxt;
    QLabel *inlbl;
    QLineEdit *potTxt;
    QLineEdit *fstxt;
    QLabel *fslbl;
    QPushButton *calcBtn;
    QWidget *pag2;
    QPushButton *voltarBtn;
    QLabel *testlbl;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, -30, 791, 621));
        pag1 = new QWidget();
        pag1->setObjectName("pag1");
        gridLayout = new QGridLayout(pag1);
        gridLayout->setObjectName("gridLayout");
        inTxt = new QLineEdit(pag1);
        inTxt->setObjectName("inTxt");

        gridLayout->addWidget(inTxt, 6, 2, 1, 1);

        tensaoTxt = new QLineEdit(pag1);
        tensaoTxt->setObjectName("tensaoTxt");

        gridLayout->addWidget(tensaoTxt, 1, 1, 1, 1);

        tensaolbl = new QLabel(pag1);
        tensaolbl->setObjectName("tensaolbl");

        gridLayout->addWidget(tensaolbl, 0, 1, 1, 1);

        ipinlbl = new QLabel(pag1);
        ipinlbl->setObjectName("ipinlbl");

        gridLayout->addWidget(ipinlbl, 5, 1, 1, 1);

        ipinTxt = new QLineEdit(pag1);
        ipinTxt->setObjectName("ipinTxt");

        gridLayout->addWidget(ipinTxt, 6, 1, 1, 1);

        potlbl = new QLabel(pag1);
        potlbl->setObjectName("potlbl");

        gridLayout->addWidget(potlbl, 0, 2, 1, 1);

        freqlbl = new QLabel(pag1);
        freqlbl->setObjectName("freqlbl");

        gridLayout->addWidget(freqlbl, 3, 2, 1, 1);

        freqTxt = new QLineEdit(pag1);
        freqTxt->setObjectName("freqTxt");

        gridLayout->addWidget(freqTxt, 4, 2, 1, 1);

        inlbl = new QLabel(pag1);
        inlbl->setObjectName("inlbl");

        gridLayout->addWidget(inlbl, 5, 2, 1, 1);

        potTxt = new QLineEdit(pag1);
        potTxt->setObjectName("potTxt");

        gridLayout->addWidget(potTxt, 1, 2, 1, 1);

        fstxt = new QLineEdit(pag1);
        fstxt->setObjectName("fstxt");

        gridLayout->addWidget(fstxt, 4, 1, 1, 1);

        fslbl = new QLabel(pag1);
        fslbl->setObjectName("fslbl");

        gridLayout->addWidget(fslbl, 3, 1, 1, 1);

        calcBtn = new QPushButton(pag1);
        calcBtn->setObjectName("calcBtn");

        gridLayout->addWidget(calcBtn, 13, 1, 2, 3);

        tabWidget->addTab(pag1, QString());
        pag2 = new QWidget();
        pag2->setObjectName("pag2");
        voltarBtn = new QPushButton(pag2);
        voltarBtn->setObjectName("voltarBtn");
        voltarBtn->setGeometry(QRect(20, 550, 739, 24));
        testlbl = new QLabel(pag2);
        testlbl->setObjectName("testlbl");
        testlbl->setGeometry(QRect(10, 20, 49, 16));
        tabWidget->addTab(pag2, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        tensaolbl->setText(QCoreApplication::translate("MainWindow", "Tens\303\243o", nullptr));
        ipinlbl->setText(QCoreApplication::translate("MainWindow", "Ip/In", nullptr));
        potlbl->setText(QCoreApplication::translate("MainWindow", "Pot\303\252ncia", nullptr));
        freqlbl->setText(QCoreApplication::translate("MainWindow", "Frequencia", nullptr));
        inlbl->setText(QCoreApplication::translate("MainWindow", "Corrente Nominal (In)", nullptr));
        fslbl->setText(QCoreApplication::translate("MainWindow", "Fator de Servi\303\247o (FS)", nullptr));
        calcBtn->setText(QCoreApplication::translate("MainWindow", "DIMENSIONAR!", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(pag1), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        voltarBtn->setText(QCoreApplication::translate("MainWindow", "DIMENSIONAR OUTRO MOTOR", nullptr));
        testlbl->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(pag2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
