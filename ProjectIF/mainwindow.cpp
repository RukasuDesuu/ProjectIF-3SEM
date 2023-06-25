
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <contatoresservice.h>
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


//Numero de Linhas
/*int getNRows(float y){
    query.prepare("SELECT COUNT(Imin) FROM rele_cod WHERE Imin < ? AND Imax > ?");
    query.addBindValue(y);
    query.addBindValue(y);
    query.exec();
    if(query.first()){
        return query.value(0).toInt();
    }else{
        return 0;
    }
}*/


void MainWindow::on_calcBtn_clicked()
{
    /*
    //Declarando as Variaveis
    int tensao, pot, nca, ncf, x;
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
    x = 1;
    
 

    try{
        //Conectando ao Bando de Dados
        db = QSqlDatabase::addDatabase ("QSQLITE");
        db.setDatabaseName("../bd/ademar.sqlite");
        db.open();
        

        //Contator
        iminc = in*1.1;

        //Relé Sobrecarga
        ifrt = 0;
        if(fs<1.15) {ifrt = in*1.15;}

        if (fs>=1.15){ifrt = in*1.25;}
        

        //ログや何らかの回復処理
        if(db.isOpen()){
            qDebug() << "DB TA ABERTO!";
            QSqlQuery query;
            //query dos valores dos códigos e correntes relativos à corrente de ajuste :T
            float imax, imin, imaxt, imint, det1, det2, det, maior;
            int idc;
            maior = 0;
            imint=0;
            imaxt=0;

            qDebug() << getNRows(ifrt);
            float Imin[getNRows(ifrt)];
            float Imax[getNRows(ifrt)];

            
            if (query.prepare("SELECT Imax FROM rele_cod WHERE Imin < ? AND Imax > ?")){qDebug()<< "Prepare 2 Success";}
            query.addBindValue(ifrt);
            query.addBindValue(ifrt);
            if(query.exec()){qDebug() << "Exec 2 Success";}
            if(query.first()){
                for(int i = 0; i==x-1; i++){
                    Imax[i] = query.value(0).toFloat();
                    query.next();
                }
            }
            if(query.prepare("SELECT Imin FROM rele_cod WHERE Imin < ? AND Imax > ?")){qDebug()<<"Prepare 4 Success";}
            query.addBindValue(ifrt);
            query.addBindValue(ifrt);
            if(query.exec()){qDebug() << "Exec 4 Success";}
            if(query.first()){
                for(int i = 0; i==x-1; i++){
                 Imin[i] = query.value(0).toFloat();
                 query.next();
                }
            }
            for(int i = 0; i==x-1; i++){
                    imint = Imin[i];
                    imaxt = Imax[i];
                    det1 = imaxt - ifrt;
                    det2 = ifrt - imint;
                    det  = det1 + det2;
                    /*qDebug() << maior;
                    qDebug() << det1;
                    qDebug() << det2;
                    qDebug() << det;
                    qDebug() << ifrt;
                    qDebug() << imaxt;
                    qDebug() << imint;*//*
                if(det > maior){
                        maior = det;
                        imax = imaxt;
                        imin = imint;
                        qDebug()<<imax;
                        qDebug()<<imin;
                }
                    qDebug()<<" ";
            }
            if(query.prepare("SELECT cod FROM rele_cod WHERE Imin = ? AND Imax = ?")){qDebug()<<"Prepare 5 success";}
            query.addBindValue(imin);
            query.addBindValue(imax);
            if(query.exec()){
                qDebug() << "Exec 5 Success";
                }else { qDebug()<<"FEIO";}
            if(query.first()){
                qDebug() << query.value(0).toString();
                }else { qDebug()<<"mt feio";}
            if(query.prepare("SELECT id_c FROM rele_cod WHERE cod = ?")){qDebug()<<"Prepare 6 success";}
            query.addBindValue(codigo);
            if(query.exec()){qDebug() << "Exec 6 Success";}
            if(query.first()){idc = query.value(0).toInt();}
            if(query.prepare("SELECT COUNT(Modelo) FROM rele_model WHERE cod = ?")){qDebug()<<"Prepare 7 Success";}
            query.addBindValue(idc);
            if(query.exec()){qDebug() << "Exec 7 Success";}
            if(query.first()){
                x = query.value(0).toInt();
            }
            QString modelos[x];
            if(query.prepare("SELECT Modelo FROM rele_model WHERE cod = ?")){qDebug()<<"Prepare 8 Success";}
            query.addBindValue(idc);
            if(query.exec()){qDebug() << "Exec 8 Success";}
            if(query.first()){
                for(int i = 0; i==x-1; i++){
                    modelos[i] = query.value(0).toString();
                    query.next();
                }
            }
        }
    }
    catch (...){
        QMessageBox::information(this, "ERRO!", "ERRO AO CONECTAR AO BANCO DE DADOS OU DADOS INVALIDOS");
    }

    ui -> testlbl -> setText(QVariant(db.isOpen()).toString());
    ui -> tabWidget -> setCurrentIndex(1);

    /*qDebug() << tensao;
    qDebug() << pot;
    qDebug() << fs;
    qDebug()<<ipin;
    qDebug()<<in;
    qDebug()<<nca;
    qDebug()<<ncf;
    qDebug()<<isAC;*/
    //qDebug() << codigo;
    /*qDebug() << modelos[0];
    qDebug() << modelos[1];*/

    ContatoresService paulo = new ContatoresService();

    paulo.GetAllContatoras();

}

void MainWindow::on_voltarBtn_clicked()
{
    ui -> tabWidget -> setCurrentIndex(0);
}




