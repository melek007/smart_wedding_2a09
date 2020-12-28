#ifndef SALLE_H
#define SALLE_H
#include <QString>
#include <QSqlQueryModel>

class Salle
{
    int id;
    QString adresse;
    int capacite;
     int prix;
    public:
    Salle();
       Salle(int,QString,int,int);
       ~Salle();

       int getId();
       void setId(int);
       QString getadresse();
       void setadresse(QString);
       int getcapacite();
       void setcapacite(int);
       int getprix();
       void setprix(int);
       int getrate();
       void setrate(int);
       bool ajouter();
       bool supprimer(int);
       bool modifier(int,QString,int,int);
       QSqlQueryModel* afficher();
       QSqlQueryModel* recherche_nom(QString);

       bool verifierExnoms(QString);

       QSqlQueryModel* trier();
       QSqlQueryModel* trier1();
       QSqlQueryModel* trier2();

       QSqlQueryModel * chercher_Salle_par_capacite(QString m);

       QSqlQueryModel * chercher_Salle_par_id(QString idd);

};

#endif // SALLE_H
