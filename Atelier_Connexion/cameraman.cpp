#include "cameraman.h"
#include "mainwindow.h"

cameraman::cameraman()
{
id=prix=0;
nom=theme=adrese="";
}
cameraman::cameraman(int id,QString nom,QString theme,QString adrese,int prix)
{
    this->id=id;
    this->nom=nom;
    this->theme=theme;
    this->adrese=adrese;
    this->prix=prix;
}

bool cameraman::ajoutert()
{
    QSqlQuery query;

     QString id_string=QString::number(id);
     QString prix_string=QString::number(prix);

     query.prepare("INSERT INTO CAMERAMAN(id,nom,theme,adrese,prix)"
                   "VALUES(:id,:nom,:theme,:adresse,:prix)");

     query.bindValue(":id",id);
     query.bindValue(":nom",nom);
     query.bindValue(":theme",theme);
     query.bindValue(":adresse",adrese);
     query.bindValue(":prix",prix);

    return query.exec();

 }

bool cameraman::supprimert(int id)
{
   QSqlQuery query;
    query.prepare("Delete from CAMERAMAN where id=:id");

    query.bindValue(0,id);

  return query.exec();

}


QSqlQueryModel*cameraman::affichert()
{

   QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM cameraman");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("THEME"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESE"));
   model->setHeaderData(4,Qt::Horizontal,QObject::tr("PRIX"));


   return model;
}
bool cameraman::modifiert(int id,QString nom,QString theme,QString adrese,int prix)
{
    QSqlQuery query;

       QString id_string= QString::number(id);
       QString prix_string= QString::number(prix);


       query.prepare("UPDATE cameraman SET  id=:id, nom=:nom ,theme=:theme ,adrese=:adrese ,prix=:prix WHERE id=:id ");
       query.bindValue(":id", id_string);
       query.bindValue(":nom", nom);
       query.bindValue(":theme", theme);
       query.bindValue(":adrese", adrese);
       query.bindValue(":prix", prix_string);
       return  query.exec();
   }


