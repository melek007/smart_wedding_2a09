#ifndef LOCATION_VOITURE_H
#define LOCATION_VOITURE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class location_voiture
{
public:
    location_voiture();
    location_voiture(int,int,int);
    int getidloc(){return idlocation;}
    int getidres(){return idreservation;}
    int getidcar(){return idcar;}

    void setidloc(int idlocation){this->idlocation=idlocation;}
    void setidres(int idreservation){this->idreservation=idreservation;}
    void setidcar(int idcar){this->idcar=idcar;}

    QSqlQueryModel* afficherlo();
    bool ajouterlo();
    bool supprimerlo(int);
    bool modifierlo();
     QSqlQueryModel * trierIDlocation();
  QSqlQueryModel *   afficher_idcar();
  QSqlQueryModel * afficher_idreservation();

     QSqlQueryModel * searchidlocation();
 private:
    int idlocation, idreservation,idcar;
};

#endif // LOCATION_VOITURE_H
