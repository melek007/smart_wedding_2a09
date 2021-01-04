#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>



class personnel
{public:
    personnel();
    personnel(int,QString,QString);
    int get_cin();
    QString get_nom();
    QString get_prenom();


    void set_cin(int );
    void set_nom(QString );
    void set_prenom(QString );


    bool ajouterpe();
    QSqlQueryModel * afficherpe();
    bool supprimerpe(int);
    bool modifierpe();
QSqlQueryModel * rechercherpe1(QString);
QSqlQueryModel * rechercherpe2(int);
QSqlQueryModel *tripe1();
QSqlQueryModel *tripe2();
QSqlQueryModel *tripe3();

private:

    int cin;


      QString nom;
      QString prenom;
};
;
#endif // PERSONNEL_H
