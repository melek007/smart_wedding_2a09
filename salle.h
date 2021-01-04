#ifndef SALLE_H
#define SALLE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Salles
{
    int idsalle;
    QString nomsalle; //adresse
    int numbloc;  //prix
    int capacite;
    public:
    Salles();
       Salles(int,QString,int,int);
       ~Salles();

       int getIdsalle();
       void setIdsalle(int);
       QString getnomsalle();
       void setnomsalle(QString);
       int getnumbloc();
       void setnumbloc(int);
       int getcapacite();
       void setcapacite(int);

       bool ajouters();
       bool supprimer(int);
       bool modifier();
       QSqlQueryModel* afficher();

       Salles recherche_mail(QString);


       QSqlQueryModel* trier0();
       QSqlQueryModel* trier1();
       QSqlQueryModel* trier2();
       QSqlQueryModel * chercher_Salle_par_nom(QString nomsalle);
       QSqlQueryModel * chercher_Salle_par_capacite(int capacite);

       QSqlQueryModel * chercher_Salle_par_idsalle(int numbloc);


      };

#endif // SALLE_H
