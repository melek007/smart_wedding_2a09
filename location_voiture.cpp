#include "location_voiture.h"

location_voiture::location_voiture()
{
idlocation=idcar=idreservation=0;

}
location_voiture::location_voiture(int idlocation,int idreservation,int idcar)
{
    this->idlocation=idlocation;
    this->idreservation=idreservation;
    this->idcar=idcar;

}

bool location_voiture::ajouterlo()
{
    QSqlQuery query;

     QString id_string=QString::number(idlocation);
     QString res_string=QString::number(idreservation);
     QString car_string=QString::number(idcar);

     query.prepare("INSERT INTO location_voiture(ID_LOCATION_VOITURE,ID_RESERVATION,NUM_CARTE_GRISE)"
                   "VALUES(:loc,:res,:car)");

     query.bindValue(":loc",id_string);
     query.bindValue(":res",res_string);
     query.bindValue(":car",car_string);



    return query.exec();

 }

bool location_voiture::supprimerlo(int idlocation)
{
   QSqlQuery query;
    QString res= QString::number(idlocation);
    query.prepare("Delete from location_voiture where ID_LOCATION_VOITURE=:id");

    query.bindValue(":id",res);

  return query.exec();

}


QSqlQueryModel*location_voiture::afficherlo()
{

   QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM location_voiture");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_LOCATION_VOITURE"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID_RESERVATION"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("NUM_CARTE_GRISE"));


   return model;
}
bool location_voiture::modifierlo()
{
    QSqlQuery query;

    QString id_string=QString::number(idlocation);
    QString res_string=QString::number(idreservation);
    QString car_string=QString::number(idcar);

       query.prepare("UPDATE location_voiture SET  ID_LOCATION_VOITURE=:loc, ID_RESERVATION=:res ,NUM_CARTE_GRISE=:car  WHERE ID_LOCATION_VOITURE=:loc ");

       query.bindValue(":loc",id_string);
       query.bindValue(":res",res_string);
       query.bindValue(":car",car_string);
       return  query.exec();
   }
QSqlQueryModel * location_voiture::afficher_idcar()
{
     QSqlQueryModel * model =new QSqlQueryModel();
     model->setQuery("select NUM_CARTE_GRISE from  voiture");
     return model ;

}
QSqlQueryModel * location_voiture::afficher_idreservation()
{
     QSqlQueryModel*  model =new QSqlQueryModel();


     model->setQuery("select ID_RESERVATION from  reservation ");

     return model ;

}
