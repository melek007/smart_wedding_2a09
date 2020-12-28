#ifndef THEME_H
#define THEME_H
#include <QString>
#include <QSqlQueryModel>

class theme
{ int id;
    QString concept;
    int prix;
    int rate;

    public:
    theme();
       theme(int,QString,int);
         theme(int,int);
       theme(int,QString,int,int);
       ~theme();

       int getId();
       void setId(int);
       QString getconcept();
       void setconcept(QString);
       int getprix();
       void setprix(int);

       bool ajouter();
       bool supprimer(int);
       bool modifier(int,QString,int);
        bool modifier_rate(int,int);
       QSqlQueryModel* afficher();
       QSqlQueryModel* recherche_nom(QString);

       bool verifierExnoms(QString);

       QSqlQueryModel* trier();
       QSqlQueryModel* trier1();


       QSqlQueryModel * chercher_theme_par_capacite(QString m);

       QSqlQueryModel * chercher_theme_par_id(QString idd);
        QSqlQueryModel* Filter(int);


};

#endif // THEME_H
