
#ifndef VOITUREPLUS_H
#define VOITUREPLUS_H
#include"QString"
#include <QSqlQuery>
#include <QSqlQueryModel>

class voitureplus
{
public:
    voitureplus();
    voitureplus(int,QString,QString,int);
       int getCARTE_GRISE();
        QString getcouleur();
         QString getmarque();
          int getprix();
          void setCARTE_GRISE(int );
          void setcouleur(QString );
          void setmarque(QString );
          void setprix(int );
          bool ajouter();
          QSqlQueryModel * afficher();
          bool supprimer(int);
          bool modifier();


    private:
          QString   couleur, marque;
          int CARTE_GRISE,prix;
};

#endif // VOITUREPLUS_H
