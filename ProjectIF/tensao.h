#ifndef TENSAO_H
#define TENSAO_H
#include<QString>


class Tensao:public QObject{
    int id;
    int v;
    QString codV;
    bool isAC;
};
#endif // TENSAO_H
