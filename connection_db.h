#ifndef BASE_CONNECTION_H
#define BASE_CONNECTION_H
#include <QSqlDatabase>
#include <QCoreApplication>
#include <QtSql>
#include <QDebug>


class base_connection
{
private:
    QSqlDatabase db;
public:
    base_connection();
    bool openConnection();
    void closeConnection();

};

#endif // base_CONNECTION_H
