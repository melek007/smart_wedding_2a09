#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
class Connexion
{

public:
    Connexion();
    bool createConnexion();

};

#endif // CONNEXION_H
