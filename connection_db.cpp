#include "connection_db.h"


base_connection::base_connection()
{

}
bool base_connection::openConnection()
{
    bool test=false;
    QSqlDatabase db =QSqlDatabase::addDatabase("QODBC");

db.setDatabaseName("wedding planner");
db.setUserName("hedi");//inserer nom de l'utilisateur
db.setPassword("hedi1");//inserer mot de passe de cet utilisateur


if (db.open()) test=true;
    else throw QString ("compilation errer"[test]);

}

void base_connection::closeConnection()
{db.close();}
