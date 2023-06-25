
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QDebug>
#include <QMessageBox>
#include <QString>
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
    //Declarando as Variaveis
    int tensao, pot, nca, ncf;
    float fs, ipin, in, iminc, ifrt, det;
    bool isAC;

    //Atribuindo os valores
    tensao = ui -> tensaoTxt -> text().toInt();
    pot = ui -> potTxt -> text().toInt();
    fs = ui -> fstxt -> text().toFloat();
    ipin = ui -> ipinTxt -> text().toFloat();
    in = ui -> inTxt -> text().toFloat();
    nca = ui -> CAspn -> text().toInt();
    ncf = ui -> CFspn -> text().toInt();
    isAC = ui -> ACDCslider -> value();
    QString codigo;

    //Conectando ao Bando de Dados
    db = QSqlDatabase::addDatabase ("QSQLITE");
    db.setDatabaseName("../bd/ademar.sqlite");
    QSqlQuery query;

    try{
        //Contator
        iminc = in*1.1;

        //Relé Sobrecarga
        if(fs<1.15) {ifrt = in*1.15;}

        if (fs>=1.15){ifrt = in*1.25;}
        
        //ログや何らかの回復処理
        
            //query dos valores dos códigos e correntes relativos à corrente de ajuste :T
            float imax, imin, imaxt, imint, det1, det2, det, maior;
            int id_c, x;
            maior = 0;
            query.prepare("SELECT COUNT(Imax) FROM rele_cod WHERE Imin < ? AND Imax > ?");
            query.addBindValue(ifrt);
            query.addBindValue(ifrt);
            query.exec();
            x = query.value(0).toInt();
            float Imax[x-1];
            query.prepare("SELECT Imax FROM rele_cod WHERE Imin < ? AND Imax > ?");
            query.addBindValue(ifrt);
            query.addBindValue(ifrt);
            query.exec();
            for(int i = 0; i==x-1; i++){
                Imax[i] = query.value(0).toFloat();
                query.next();
            }
            query.prepare("SELECT COUNT(Imin) FROM rele_cod WHERE Imin < ? AND Imax > ?");
            query.addBindValue(ifrt);
            query.addBindValue(ifrt);
            query.exec();
            x = query.value(0).toInt();
            float Imin[x-1];
            query.prepare("SELECT Imin FROM rele_cod WHERE Imin < ? AND Imax > ?");
            query.addBindValue(ifrt);
            query.addBindValue(ifrt);
            query.exec();
            for(int i = 0; i==x-1; i++){
                Imin[i] = query.value(0).toFloat();
                query.next();
            }
    for(int i = 0; i<=2; i++){
            imint = Imin[i];
            imaxt = Imax[i];
            det1 = imax - ifrt;
            det2 = ifrt - imin;
            det  = det1 + det2;
            if(det > maior){
                maior = det;
                imax = imaxt;
                imin = imint;
                }
            }
            query.prepare("SELECT cod FROM rele_cod WHERE Imin = ? AND Imax = ?");
            query.addBindValue(imin);
            query.addBindValue(imax);
            query.exec();
            codigo = query.value(0).toString();
            query.prepare("SELECT id_c FROM rele_cod WHERE cod = ?");
            query.addBindValue(codigo);
            query.exec();
            id_c = query.value(0).toInt();
            query.prepare("SELECT COUNT(Modelo) FROM rele_model WHERE cod = ?");
            query.addBindValue(id_c);
            query.exec();
            x = query.value(0).toInt();
            QString modelos[x-1];
            query.prepare("SELECT Modelo FROM rele_model WHERE cod = ?");
            query.addBindValue(id_c);
            query.exec();
            for(int i = 0; i==x-1; i++){
                modelos[i] = query.value(0).toString();
                query.next();
            }
        }
    catch (...){
        QMessageBox::information(this, "ERRO!", "ERRO AO CONECTAR AO BANCO DE DADOS OU DADOS INVALIDOS");
    }
        ui -> testlbl -> setText(QVariant(db.open()).toString());


    ui -> tabWidget -> setCurrentIndex(1);

    /*qDebug() << tensao;
    qDebug() << pot;
    qDebug() << fs;
    qDebug()<<ipin;
    qDebug()<<in;
    qDebug()<<nca;
    qDebug()<<ncf;
    qDebug()<<isAC;*/
    qDebug() << codigo;
   // qDebug() << modelos[0];
    //qDebug() << modelos[1];
}

void MainWindow::on_voltarBtn_clicked()
{
    ui -> tabWidget -> setCurrentIndex(0);
}
