#ifndef RELECUR_H
#define RELECUR_H
#include <QList>
#include <rele.h>

class ReleCur:public QObject{
    int id_cod;
    QString cod;
    float imin;
    float imax;

    QList <Rele> reles;
};
#endif // RELECUR_H
