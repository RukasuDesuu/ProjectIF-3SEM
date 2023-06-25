#include "dbcontroller.h"
#include <QtSql>

static DBController* DBController::instance = nullptr; // Inicializando a instância como nullptr


//DBController()
//{
//    // Construtor privado para evitar instanciação direta
//}



static DBController* getInstance()
{
    if (instance == nullptr) {
        instance = new DBController();
    }
    return instance;
}

void DBController::SqlConnection()
{
    db = QSqlDatabase::addDatabase ("QSQLITE");
    db.setDatabaseName("../bd/ademar.sqlite");
}

