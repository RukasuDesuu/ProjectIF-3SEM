
#include "mainwindow.h"

#include <QApplication>

#include <QDebug>
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    qDebug()<<"Start";

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase ("QSQLITE");
    db.setDatabaseName("C:/Users/lucas/OneDrive/Documentos/IFSP3/bd/ademar.sqlite");
    qDebug()<<db.open();
    qDebug()<<"end";
    return a.exec();
}
