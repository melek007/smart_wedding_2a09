#ifndef CONNEXION_BASE_H
#define CONNEXION_BASE_H
#include <QSqlDatabase>


class connexion_base
{
private:
    QSqlDatabase db;
public:
    connexion_base();
    bool ouvrirConnexion();
    void fermerConnexion();

};

#endif // CONNEXION_BASE_H
