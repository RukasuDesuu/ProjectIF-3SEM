
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>

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
    int tensao, pot, fs, freq, ipin, in, nca, nfa;
    bool isAC;
    tensao = ui -> tensaoTxt -> text().toInt();
    pot = ui -> potTxt -> text().toInt();
    fs = ui -> fstxt -> text().toInt();
    freq = ui -> freqTxt -> text().toInt();
    ipin = ui -> ipinTxt -> text().toInt();
    in = ui -> inTxt -> text().toInt();
    nca = ui -> CAspn -> get
    db = QSqlDatabase::addDatabase ("QSQLITE");
    db.setDatabaseName("../bd/ademar.sqlite");

        ui -> testlbl -> setText(QVariant(db.open()).toString());


    ui -> tabWidget -> setCurrentIndex(1);
}


void MainWindow::on_voltarBtn_clicked()
{
    ui -> tabWidget -> setCurrentIndex(0);
}

