#include "Connection.h"

Connection::Connection()
{

}
bool Connection::createConnect()
{
    bool test =false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName("Smart_wedding");
        db.setUserName("farah");
        db.setPassword("farah11");

        if(db.open()) test = true;

        return test;
}
