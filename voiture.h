#ifndef VOITURE_H
#define VOITURE_H
#include"QString"
#include <QSqlQuery>
#include <QSqlQueryModel>

class voiture
{
public:
    voiture();
     voiture(int,QString,QString,QString,int);
       int get_cartegrise();
        QString getmodel();
        QString get_matricule();
        QString get_couleur();
          int getprixlocation();

          void set_cartegrise(int );
          void setmodel(QString );
          void set_matricule(QString );
          void set_couleur(QString );
          void setprixlocation(int);
          bool ajoutervo();
          QSqlQueryModel * affichervo();
          bool supprimervo(int);
          bool modifiervo();
          QSqlQueryModel * triermatricule();
            QSqlQueryModel * trierprixvoiture();
            QSqlQueryModel * triercarte_grise();
            QSqlQueryModel * cherchercouleur(QString);
            QSqlQueryModel * chercherprixlocation(int);
            QSqlQueryModel * cherchermodel(QString);


    private:
          QString model,matricule,couleur ;
          int carte_grise,prixlocation;
};

#endif // VOITURE_H
