#include "honeymoon.h"
#include "honeymoonplus.h"
#include <QMessageBox>

#include <QSqlQuery>
#include <QtDebug>
#include <QDebug>
#include <QObject>
#include<QSqlQueryModel>
#include<QSqlQuery>
honeymoon::honeymoon()
{ prix=0; ID=0;
  lieu="";nom_hotel="";

}

honeymoon:: honeymoon (int ID,QString lieu,int prix,QString nom_hotel)

 {

this->ID=ID;  this->lieu=lieu;this->prix=prix;  this->nom_hotel=nom_hotel;

 }
   int honeymoon:: getID(){return ID;}

     QString honeymoon:: getlieu(){return lieu;}

     int honeymoon:: getprix(){return prix;}
     QString honeymoon:: getnom_hotel(){return nom_hotel;}

     void honeymoon:: setID(int ID ){this->ID=ID;}

      void honeymoon:: setlieu(QString lieu ){this->lieu=lieu;}

      void honeymoon:: setprix(int prix){this->prix=prix;}
   void honeymoon:: setnom_hotel(QString nom_hotel ){this->nom_hotel=nom_hotel;}
      bool honeymoon:: ajouter()
      {
           QSqlQuery query;
           QString id_string= QString::number(ID);

                  query.prepare("INSERT INTO honeymoon (id,  lieu,prix,nom_hotel) "
                                "VALUES (:id, :lieu,:prix,:nom_hotel)");
                  query.bindValue(":id",id_string);
                  query.bindValue(":lieu", lieu);
                  query.bindValue(":prix", prix);
                  query.bindValue(":nom_hotel", nom_hotel);
                 return query.exec();}

      bool honeymoon::supprimer(int id)
      {
          QSqlQuery query;
          QString res= QString::number(id);
          query.prepare(" Delete from honeymoon where id=:id");
          query.bindValue(":id", res);

              return query.exec();}
      QSqlQueryModel* honeymoon::afficher()
      {
        QSqlQueryModel* model=new QSqlQueryModel();


         model->setQuery("SELECT id,lieu,prix,nom_hotel FROM honeymoon");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Lieu"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom hotel"));
        return  model;
      }
      bool honeymoon::modifier()
      {

              QSqlQuery query;
              QString id_string=QString::number(ID);

              query.prepare(" UPDATE honeymoon SET lieu=:lieu,prix=:prix,nom_hotel=:nom_hotel WHERE ID=:ID");
              query.bindValue(":ID", id_string);
              query.bindValue(":lieu",lieu);
              query.bindValue(":nom_hotel",nom_hotel);
              query.bindValue(":prix",prix);


                    return query.exec();


      }

      bool honeymoon::rechercher(int ID,int prix,QString lieu)
      {
          QMessageBox msgBox;
          QMessageBox msgBox1;
          QSqlQuery query;
          bool retour=0;
          int count=0;
          query.prepare("SELECT * FROM honeymoon WHERE ID= ?,prix= ?,lieu= ? ");
          query.addBindValue(ID);
          query.addBindValue(prix);
          query.addBindValue(lieu);
          if(query.exec() )
              {
      while (query.next())
         {
         count ++;
          }
      if(count==1)
         {
          msgBox.setText("honeymoonplus existe");
          msgBox.exec();
          retour=1;
         }
      else if (count<1)
      {
          msgBox1.setText("honeymoonplus n'existe pas");
              msgBox1.exec();
              retour=0;
      }
              }
          return retour;

      }

      honeymoon honeymoon::findByID(QString ID){

          QSqlQuery query;
          honeymoon honeymoon1 = honeymoon() ;
          query.prepare(" select ID,lieu,prix,nom_hotel from honeymoon where ID="+ID);
          query.exec();
          query.next();
          honeymoon1.setID(query.value(0).toInt());
          honeymoon1.setlieu(query.value(1).toString());
           honeymoon1.setprix(query.value(2).toInt());
          honeymoon1.setnom_hotel(query.value(3).toString());

      return honeymoon1;
      }

      bool honeymoon::checkExisteHoneymoon(QString ID){

          QSqlQuery query;
          honeymoon voiture = honeymoon() ;
          query.prepare("select count(*) as nbr from honeymoon where ID="+ID);
          query.exec();
          query.next();
          if(query.value("nbr").toInt() > 0){
              return true;
          }
          return false;
      }

