#ifndef CONTATORA_H
#define CONTATORA_H
#include <QString>
#include <tensao.h>
#include <rele.h>
#include <QList>

class Contatora:public QObject{
    int ID;
    QString Model;
    QList <Tensao> tensoes;
    QList <Rele> reles;
};
#endif // CONTATORA_H
