
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    ui -> tabWidget -> setCurrentIndex(0);
}



QSqlDatabase db;

void MainWindow::on_calcBtn_clicked()
{
    int tensao, pot, nca, ncf;
    float fs, ipin, in;
    bool isAC;
    tensao = ui -> tensaoTxt -> text().toInt();
    pot = ui -> potTxt -> text().toInt();
    fs = ui -> fstxt -> text().toFloat();
    ipin = ui -> ipinTxt -> text().toFloat();
    in = ui -> inTxt -> text().toFloat();
    nca = ui -> CAspn -> text().toInt();
    ncf = ui -> CFspn -> text().toInt();
    isAC = ui -> ACDCslider -> value();

    db = QSqlDatabase::addDatabase ("QSQLITE");
    db.setDatabaseName("../bd/ademar.sqlite");

        ui -> testlbl -> setText(QVariant(db.open()).toString());


    ui -> tabWidget -> setCurrentIndex(1);

    qDebug() << tensao;
    qDebug() << pot;
    qDebug() << fs;

    qDebug()<<ipin;
    qDebug()<<in;
    qDebug()<<nca;
    qDebug()<<ncf;
    qDebug()<<isAC;
}


void MainWindow::on_voltarBtn_clicked()
{
    ui -> tabWidget -> setCurrentIndex(0);
}

