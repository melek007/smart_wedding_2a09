#include "honeymoon.h"

#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QSqlQueryModel>
#include<QSqlQuery>

honeymoon::honeymoon()
{ price=0; IDh=0;
    plan=destination=place="";

}

 honeymoon::honeymoon(int IDh,QString destination,QString plan,QString place,int price)
 {

this->IDh=IDh ; this->destination=destination; this->place=place; this->plan=plan;this->price=price;

 }
   int honeymoon:: getIDh(){return IDh;}
    QString  honeymoon::getdestination(){return destination;}
     QString honeymoon:: getplaceh(){return place;}
     QString honeymoon:: getplanh(){return plan;}
     int honeymoon:: getpriceh(){return price;}

     void honeymoon:: setIDh(int IDh ){this->IDh=IDh;}
      void honeymoon:: setdestination(QString destination ){this->destination=destination;}
      void honeymoon:: setplaceh(QString place ){this->place=place;}
      void honeymoon:: setplanh(QString plan){this->plan=plan;}
      void honeymoon:: setpriceh(int price){this->price=price;}

      bool honeymoon:: add()
      {
           QSqlQuery query;
           QString id_string= QString::number(IDh);
               QString prix_string= QString::number(price);

                  query.prepare("INSERT INTO honeymoon (id_honeymoon, destination,programme_honeymoon ,nom_hotel,prix) "
                                "VALUES (:id,:nom, :prog,:lieu, :prix)");
                  query.bindValue(":id",id_string);
                  query.bindValue(":nom", destination);
                  query.bindValue(":prog", plan);
                  query.bindValue(":lieu", place);

                  query.bindValue(":prix", prix_string);


                 return query.exec();}

      bool honeymoon::erase(int IDh)
      {
          QSqlQuery query;
          QString res= QString::number(IDh);
          query.prepare(" Delete from honeymoon where id_honeymoon=:id");
          query.bindValue(":id", res);

              return query.exec();}
      QSqlQueryModel* honeymoon::show()
      {
        QSqlQueryModel* model=new QSqlQueryModel();


         model->setQuery("SELECT* FROM honeymoon");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_honeymoon"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("destination"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("plan"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom_hotel"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("price"));


        return  model;
      }
      bool honeymoon::modify()
      {

              QSqlQuery query;
              QString id_string=QString::number(IDh);
              QString prix_string= QString::number(price);

             query.prepare(" UPDATE honeymoon SET id_honeymoon=:ID,destination=:place_vip_wedding,programme_honeymoon=:plan,nom_hotel=:name_vip_wedding,prix=:price WHERE id_honeymoon=:ID");
                    query.bindValue(":ID", id_string);

                       query.bindValue(":place_vip_wedding",destination);
                    query.bindValue(":plan",plan);
                      query.bindValue(":name_vip_wedding",place);
                    query.bindValue(":price",prix_string);



                    return query.exec();


      }


      QSqlQueryModel * honeymoon::triIDh()
      {
          QSqlQueryModel *model = new QSqlQueryModel();
              model->setQuery("SELECT * from honeymoon ORDER BY id_honeymoon");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_honeymoon"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("destination"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("plan"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom_hotel"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("price"));

                       return model ;}

      QSqlQueryModel * honeymoon::trinameh()
      {
          QSqlQueryModel *model = new QSqlQueryModel();
              model->setQuery("SELECT * from honeymoon ORDER BY nom_hotel");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_honeymoon"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("destination"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("plan"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom_hotel"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("price"));
              return model ;}
      QSqlQueryModel * honeymoon::tripriceh()
      {
          QSqlQueryModel *model = new QSqlQueryModel();
              model->setQuery("SELECT * from honeymoon ORDER BY prix");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_honeymoon"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("destination"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("plan"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom_hotel"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("price"));
              return model ;}


      QSqlQueryModel * honeymoon::searchdestinationh(QString destination)
      {
          QSqlQueryModel *model = new QSqlQueryModel();
              model->setQuery("SELECT * from honeymoon where destination ='"+destination+"'");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_honeymoon"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("destination"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("plan"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom_hotel"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("price"));
              return model ;
      }

      QSqlQueryModel * honeymoon::searchplaceh(QString place)
      {
          QSqlQueryModel *model = new QSqlQueryModel();
              model->setQuery("SELECT * from honeymoon where nom_hotel ='"+place+"'");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_honeymoon"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("destination"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("plan"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom_hotel"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("price"));
              return model ;
      }
      QSqlQueryModel * honeymoon::searchpriceh(int price)
      {
          QSqlQueryModel *model = new QSqlQueryModel();
          QString prix_string= QString::number(price);

              model->setQuery("SELECT * from honeymoon where prix ='"+prix_string+"'");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_honeymoon"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("destination"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("plan"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom_hotel"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("price"));
              return model ;
      }
