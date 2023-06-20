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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *pag1;
    QGridLayout *gridLayout;
    QLabel *ipinlbl;
    QVBoxLayout *verticalLayout;
    QLabel *ACDClbl;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QSlider *ACDCslider;
    QHBoxLayout *horizontalLayout_2;
    QLabel *DClbl;
    QSpacerItem *spacer;
    QLabel *AClbl;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *ipinTxt;
    QPushButton *calcBtn;
    QLabel *tensaolbl;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout_3;
    QLabel *CFlbl;
    QSpinBox *CFspn;
    QLineEdit *potTxt;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QLabel *inlbl;
    QLabel *fslbl;
    QLineEdit *tensaoTxt;
    QLabel *label;
    QLabel *potlbl;
    QGridLayout *gridLayout_2;
    QSpinBox *CAspn;
    QLabel *CAlbl;
    QLineEdit *inTxt;
    QLineEdit *fstxt;
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
        tabWidget->setGeometry(QRect(0, -40, 791, 561));
        pag1 = new QWidget();
        pag1->setObjectName("pag1");
        gridLayout = new QGridLayout(pag1);
        gridLayout->setObjectName("gridLayout");
        ipinlbl = new QLabel(pag1);
        ipinlbl->setObjectName("ipinlbl");

        gridLayout->addWidget(ipinlbl, 5, 3, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        ACDClbl = new QLabel(pag1);
        ACDClbl->setObjectName("ACDClbl");

        verticalLayout->addWidget(ACDClbl);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        ACDCslider = new QSlider(pag1);
        ACDCslider->setObjectName("ACDCslider");
        ACDCslider->setMaximum(1);
        ACDCslider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(ACDCslider);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        DClbl = new QLabel(pag1);
        DClbl->setObjectName("DClbl");

        horizontalLayout_2->addWidget(DClbl);

        spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(spacer);

        AClbl = new QLabel(pag1);
        AClbl->setObjectName("AClbl");
        AClbl->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_2->addWidget(AClbl);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 10, 3, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_3, 3, 1, 1, 1);

        ipinTxt = new QLineEdit(pag1);
        ipinTxt->setObjectName("ipinTxt");

        gridLayout->addWidget(ipinTxt, 7, 3, 1, 1);

        calcBtn = new QPushButton(pag1);
        calcBtn->setObjectName("calcBtn");

        gridLayout->addWidget(calcBtn, 12, 2, 1, 1);

        tensaolbl = new QLabel(pag1);
        tensaolbl->setObjectName("tensaolbl");

        gridLayout->addWidget(tensaolbl, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 8, 1, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        CFlbl = new QLabel(pag1);
        CFlbl->setObjectName("CFlbl");

        gridLayout_3->addWidget(CFlbl, 0, 0, 1, 1);

        CFspn = new QSpinBox(pag1);
        CFspn->setObjectName("CFspn");

        gridLayout_3->addWidget(CFspn, 2, 0, 1, 1);


        gridLayout->addLayout(gridLayout_3, 10, 2, 1, 1);

        potTxt = new QLineEdit(pag1);
        potTxt->setObjectName("potTxt");

        gridLayout->addWidget(potTxt, 7, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 11, 2, 1, 1);

        label_2 = new QLabel(pag1);
        label_2->setObjectName("label_2");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Black")});
        font.setPointSize(18);
        font.setBold(true);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 8, 2, 1, 1);

        inlbl = new QLabel(pag1);
        inlbl->setObjectName("inlbl");

        gridLayout->addWidget(inlbl, 5, 2, 1, 1);

        fslbl = new QLabel(pag1);
        fslbl->setObjectName("fslbl");

        gridLayout->addWidget(fslbl, 1, 3, 1, 1);

        tensaoTxt = new QLineEdit(pag1);
        tensaoTxt->setObjectName("tensaoTxt");

        gridLayout->addWidget(tensaoTxt, 2, 1, 1, 1);

        label = new QLabel(pag1);
        label->setObjectName("label");
        label->setFont(font);

        gridLayout->addWidget(label, 0, 2, 1, 1);

        potlbl = new QLabel(pag1);
        potlbl->setObjectName("potlbl");

        gridLayout->addWidget(potlbl, 5, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        CAspn = new QSpinBox(pag1);
        CAspn->setObjectName("CAspn");

        gridLayout_2->addWidget(CAspn, 1, 0, 1, 1);

        CAlbl = new QLabel(pag1);
        CAlbl->setObjectName("CAlbl");

        gridLayout_2->addWidget(CAlbl, 0, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 10, 1, 1, 1);

        inTxt = new QLineEdit(pag1);
        inTxt->setObjectName("inTxt");

        gridLayout->addWidget(inTxt, 7, 2, 1, 1);

        fstxt = new QLineEdit(pag1);
        fstxt->setObjectName("fstxt");

        gridLayout->addWidget(fstxt, 2, 3, 1, 1);

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
        ipinlbl->setText(QCoreApplication::translate("MainWindow", "Ip/In", nullptr));
        ACDClbl->setText(QCoreApplication::translate("MainWindow", "Qual tipo de corrente usa?", nullptr));
        DClbl->setText(QCoreApplication::translate("MainWindow", "DC", nullptr));
        AClbl->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        calcBtn->setText(QCoreApplication::translate("MainWindow", "DIMENSIONAR!", nullptr));
        tensaolbl->setText(QCoreApplication::translate("MainWindow", "Tens\303\243o", nullptr));
        CFlbl->setText(QCoreApplication::translate("MainWindow", "Contatos Fechados", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Informa\303\247\303\265es do Projeto", nullptr));
        inlbl->setText(QCoreApplication::translate("MainWindow", "Corrente Nominal (In)", nullptr));
        fslbl->setText(QCoreApplication::translate("MainWindow", "Fator de Servi\303\247o (FS)", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Informa\303\247\303\265es do Motor", nullptr));
        potlbl->setText(QCoreApplication::translate("MainWindow", "Pot\303\252ncia", nullptr));
        CAlbl->setText(QCoreApplication::translate("MainWindow", "Contatos Abertos", nullptr));
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
