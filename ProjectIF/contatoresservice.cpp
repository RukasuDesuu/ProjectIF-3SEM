#include "contatoresservice.h"
#include <contatora.h>
#include <QList>
#include <QtSql>
#include <dbcontroller.h>

//    ContatoresService()
//    {
//        //Construtor
//    }


void GetAllContatoras(){
    DBController* dbconn = DBController::getInstance();
    QSqlQuery query;
    dbconn.db.query("SELECT id FROM v");
}
