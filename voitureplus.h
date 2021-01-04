
#ifndef VOITUREPLUS_H
#define VOITUREPLUS_H
#include"QString"
#include <QSqlQuery>
#include <QSqlQueryModel>

class voitureplus
{
public:
    voitureplus();
    voitureplus(int,QString,QString,int,QString);
       int getCARTE_GRISE();
        QString getcouleur();
         QString getmarque();
          QString getMatricule();
          int getprix();
          void setCARTE_GRISE(int );
          void setcouleur(QString );
          void setmarque(QString );
          void setMatricule(QString );
          void setprix(int );
          bool ajouter();
          QSqlQueryModel * afficher();
          bool supprimer(int);
          bool modifier();
          voitureplus findByCarteGrise(QString);
          bool checkExisteVoiture(QString);


    private:
          QString   couleur, marque,matricule;
          int CARTE_GRISE,prix;
};

#endif // VOITUREPLUS_H
