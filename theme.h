#ifndef THEME_H
#define THEME_H
#include <QString>
#include <QSqlQueryModel>

class theme
{ int idtheme;
    QString concept;
    int prixtheme;


    public:
    theme();
       theme(int,QString,int);


       int getIdtheme();
       void setIdtheme(int);
       QString getconcept();
       void setconcept(QString);
       int getprixtheme();
       void setprixtheme(int);

       bool ajouterth();
       bool supprimerth(int);
       bool modifierth();
       QSqlQueryModel* afficherth();



       QSqlQueryModel* trier0();
       QSqlQueryModel* trier1();
        QSqlQueryModel* trier2();


       QSqlQueryModel * chercher_theme_par_concept(QString concept);
   QSqlQueryModel * chercher_theme_par_idtheme(int idtheme);
   QSqlQueryModel * chercher_theme_par_prixtheme(int prixtheme);




};

#endif // THEME_H
