#ifndef CONTATORESSERVICE_H
#define CONTATORESSERVICE_H

#include <QObject>

class ContatoresService : public QObject
{
    Q_OBJECT
public:
    explicit ContatoresService(QObject *parent = nullptr);
    void GetAllContatoras();
signals:

};

#endif // CONTATORESSERVICE_H
