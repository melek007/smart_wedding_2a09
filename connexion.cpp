#include "connexion.h"
#include<QDebug>
Connexion::Connexion()
{

}

bool Connexion::createConnexion()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Smart_wedding");
    db.setUserName("farah");
    db.setPassword("farah11");

    if (db.open())
     test=true;

    qDebug()<<db.lastError().text();

    return test;

}
