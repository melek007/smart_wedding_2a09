#include "bandM.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QSqlQueryModel>
#include<QSqlQuery>
boudinar::boudinar()
{ prix=0; ID=0;
    typemusic=nom=adresse="";

}

 boudinar::boudinar(int ID,QString nom,QString adresse,QString typemusic,int prix)
 {

this->ID=ID; this->nom=nom; this->adresse=adresse; this->typemusic=typemusic;this->prix=prix;

 }
   int boudinar:: getID(){return ID;}
    QString  boudinar::getnom(){return nom;}
     QString boudinar:: getadresse(){return adresse;}
     QString boudinar:: gettypemusic(){return typemusic;}
     int boudinar:: getprix(){return prix;}

     void boudinar:: setID(int ID ){this->ID=ID;}
      void boudinar:: setnom(QString nom ){this->nom=nom;}
      void boudinar:: setadresse(QString adresse ){this->adresse=adresse;}
      void boudinar:: settypemusic(QString typemusic){this->typemusic=typemusic;}
      void boudinar:: setprix(int prix){this->prix=prix;}

      bool boudinar:: ajouter()
      {
           QSqlQuery query;
           QString id_string= QString::number(ID);

                  query.prepare("INSERT INTO boudinar (id, nom, adresse,type_music,prix) "
                                "VALUES (:id, :name, :place, :typechant,:price)");
                  query.bindValue(":id",id_string);
                  query.bindValue(":name", nom);
                  query.bindValue(":place", adresse);
                  query.bindValue(":typechant", typemusic);
                  query.bindValue(":price", prix);

                 return query.exec();}

      bool boudinar::supprimer(int id)
      {
          QSqlQuery query;
          QString res= QString::number(id);
          query.prepare(" Delete from boudinar where id=:id");
          query.bindValue(":id", res);

              return query.exec();}
      QSqlQueryModel* boudinar::afficher()
      {
        QSqlQueryModel* model=new QSqlQueryModel();


         model->setQuery("SELECT* FROM boudinar");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("adress"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("music_type"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("price"));


        return  model;
      }
      bool boudinar::modifier()
      {

              QSqlQuery query;
              QString id_string=QString::number(ID);

             query.prepare(" UPDATE boudinar SET ID=:ID,nom=:nom_band,adresse=:adresse_band,type_music=:typechant,prix=:soum WHERE ID=:ID");
                    query.bindValue(":ID", id_string);
                    query.bindValue(":nom_band",nom);
                       query.bindValue(":adresse_band",adresse);
                    query.bindValue(":typechant",typemusic);
                    query.bindValue(":soum",prix);


                    return query.exec();


      }




      QSqlQueryModel * boudinar::trierID()
      {
          QSqlQueryModel *model = new QSqlQueryModel();
              model->setQuery("SELECT * from boudinar ORDER BY ID");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("adress"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("music_type"));
              model->setHeaderData(4, Qt::Horizontal, QObject::tr("price"));


                       return model ;}
      QSqlQueryModel * boudinar::trierprix()
      {
          QSqlQueryModel *model = new QSqlQueryModel();
              model->setQuery("SELECT * from boudinar ORDER BY prix");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("adress"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("music_type"));
              model->setHeaderData(4, Qt::Horizontal, QObject::tr("price"));


              return model ;}

      QSqlQueryModel * boudinar::trieradresse()
      {
          QSqlQueryModel *model = new QSqlQueryModel();
              model->setQuery("SELECT * from boudinar ORDER BY adresse");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("adress"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("music_type"));
              model->setHeaderData(4, Qt::Horizontal, QObject::tr("price"));

              return model ;}

      QSqlQueryModel * boudinar::chercher(QString adresse)
      {
          QSqlQueryModel *model = new QSqlQueryModel();
              model->setQuery("SELECT * from boudinar where adresse ='"+adresse+"'");
              model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("adress"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("music_type"));
              model->setHeaderData(4, Qt::Horizontal, QObject::tr("price"));
              return model ;
      }

      QSqlQueryModel * boudinar::cherchernom(QString nom)
      {
          QSqlQueryModel *model = new QSqlQueryModel();
              model->setQuery("SELECT * from boudinar where nom ='"+nom+"'");
              model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("adress"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("music_type"));
              model->setHeaderData(4, Qt::Horizontal, QObject::tr("price"));
              return model ;
      }

      QSqlQueryModel * boudinar::cherchermusic(QString typemusic)
      {
          QSqlQueryModel *model = new QSqlQueryModel();
              model->setQuery("SELECT * from boudinar where type_music ='"+typemusic+"'");
              model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("adress"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("music_type"));
              model->setHeaderData(4, Qt::Horizontal, QObject::tr("price"));
              return model ;
      }
      int boudinar::calculerm(QString typemusic) {
        QSqlQuery query;
        query.prepare("select * from boudinar where type_music = :typechant");
        query.bindValue(":typechant", typemusic);

        query.exec();
        int total = 0;
        while (query.next()) {
          total++;
        }

        return total;
      }

