
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
    int tensao, pot, fs, freq, ipin, in;
    tensao = ui -> tensaoTxt -> text().toInt();
    pot = ui -> potTxt -> text().toInt();
    fs = ui -> fstxt -> text().toInt();
    freq = ui -> freqTxt -> text().toInt();
    ipin = ui -> ipinTxt -> text().toInt();
    in = ui -> inTxt -> text().toInt();

    db = QSqlDatabase::addDatabase ("QSQLITE");
    db.setDatabaseName("R:/IFSP/3ºSEM/prog/Projeto/ProjetoIF/ProjectIF-3SEM/bd/ademar.sqlite");

        ui -> testlbl -> setText(QVariant(db.open()).toString());

    ui -> tabWidget -> setCurrentIndex(1);
}


void MainWindow::on_voltarBtn_clicked()
{
    ui -> tabWidget -> setCurrentIndex(0);
}

