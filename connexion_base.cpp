#include "connexion_base.h"


connexion_base::connexion_base()
{

}
bool connexion_base::ouvrirConnexion()
{

    db=QSqlDatabase::addDatabase("QODBC");

db.setDatabaseName("wedding");
db.setUserName("melek1");//inserer nom de l'utilisateur
db.setPassword("melek0000");//inserer mot de passe de cet utilisateur


if (db.open())
return true;
    return  false;
}
void connexion_base::fermerConnexion()
{db.close();}
