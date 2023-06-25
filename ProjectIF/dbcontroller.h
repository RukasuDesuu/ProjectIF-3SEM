#ifndef DBCONTROLLER_H
#define DBCONTROLLER_H
#include <QtSql>
#include <QObject>

class DBController : public QObject
{
    Q_OBJECT
public:
    explicit DBController(QObject *parent = nullptr);
    static DBController* getInstance();
    static QSqlDatabase db;
signals:

private:
    void SqlConnection();
};

#endif // DBCONTROLLER_H
