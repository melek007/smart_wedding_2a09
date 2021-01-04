#include "vip_wedding.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QSqlQueryModel>
#include<QSqlQuery>
vip_wedding::vip_wedding()
{ price=0; IDvip=0;
    plan=name=place="";

}

 vip_wedding::vip_wedding(int IDvip,QString name,QString place,QString plan,int price)
 {

this->IDvip=IDvip ; this->name=name; this->place=place; this->plan=plan;this->price=price;

 }
   int vip_wedding:: getIDvip(){return IDvip;}
    QString  vip_wedding::getnamevip(){return name;}
     QString vip_wedding:: getplacevip(){return place;}
     QString vip_wedding:: getplanvip(){return plan;}
     int vip_wedding:: getpricevip(){return price;}

     void vip_wedding:: setIDvip(int IDvip ){this->IDvip=IDvip;}
      void vip_wedding:: setnamevip(QString name ){this->name=name;}
      void vip_wedding:: setplacevip(QString place ){this->place=place;}
      void vip_wedding:: setplanvip(QString plan){this->plan=plan;}
      void vip_wedding:: setpricevip(int price){this->price=price;}

      bool vip_wedding:: add()
      {
           QSqlQuery query;
           QString id_string= QString::number(IDvip);
               QString prix_string= QString::number(price);

                  query.prepare("INSERT INTO vip_wedding (id_vip, lieu_vip,programme_vip ,prix_vip,nom_vip) "
                                "VALUES (:id, :lieu, :prog, :prix,:nom)");
                  query.bindValue(":id",id_string);
                  query.bindValue(":lieu", place);
                  query.bindValue(":prog", plan);
                  query.bindValue(":prix", prix_string);
                  query.bindValue(":nom", name);

                 return query.exec();}

      bool vip_wedding::erase(int IDvip)
      {
          QSqlQuery query;
          QString res= QString::number(IDvip);
          query.prepare(" Delete from vip_wedding where id_vip=:id");
          query.bindValue(":id", res);

              return query.exec();}
      QSqlQueryModel* vip_wedding::show()
      {
        QSqlQueryModel* model=new QSqlQueryModel();


         model->setQuery("SELECT* FROM vip_wedding");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_vip"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("place"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("plan"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("price"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("name"));


        return  model;
      }
      bool vip_wedding::modify()
      {

              QSqlQuery query;
              QString id_string=QString::number(IDvip);
              QString prix_string= QString::number(price);

             query.prepare(" UPDATE vip_wedding SET ID_vip=:ID,lieu_vip=:place_vip_wedding,programme_vip=:plan,prix_vip=:price,nom_vip=:name_vip_wedding WHERE ID_vip=:ID");
                    query.bindValue(":ID", id_string);

                       query.bindValue(":place_vip_wedding",place);
                    query.bindValue(":plan",plan);
                    query.bindValue(":price",prix_string);
                     query.bindValue(":name_vip_wedding",name);


                    return query.exec();


      }


      QSqlQueryModel * vip_wedding::triIDvip()
      {
          QSqlQueryModel *model = new QSqlQueryModel();
              model->setQuery("SELECT * from vip_wedding ORDER BY ID_vip");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_vip"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("place"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("plan"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("price"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("name"));
                       return model ;}

      QSqlQueryModel * vip_wedding::tripricevip()
      {
          QSqlQueryModel *model = new QSqlQueryModel();
              model->setQuery("SELECT * from vip_wedding ORDER BY prix_vip");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_vip"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("place"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("plan"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("price"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("name"));
              return model ;}
      QSqlQueryModel * vip_wedding::trinamevip()
      {
          QSqlQueryModel *model = new QSqlQueryModel();
              model->setQuery("SELECT * from vip_wedding ORDER BY nom_vip");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_vip"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("place"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("plan"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("price"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("name"));
              return model ;}


      QSqlQueryModel * vip_wedding::searchnamevip(QString name)
      {
          QSqlQueryModel *model = new QSqlQueryModel();
              model->setQuery("SELECT * from vip_wedding where nom_vip ='"+name+"'");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_vip"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("place"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("plan"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("price"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("name"));
              return model ;
      }

      QSqlQueryModel * vip_wedding::searchplacevip(QString place)
      {
          QSqlQueryModel *model = new QSqlQueryModel();
              model->setQuery("SELECT * from vip_wedding where lieu_vip ='"+place+"'");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_vip"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("place"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("plan"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("price"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("name"));
              return model ;
      }
      QSqlQueryModel * vip_wedding::searchpricevip(int price)
      {
          QSqlQueryModel *model = new QSqlQueryModel();
          QString prix_string= QString::number(price);

              model->setQuery("SELECT * from vip_wedding where prix_vip ='"+prix_string+"'");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_vip"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("place"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("plan"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("price"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("name"));
              return model ;
      }
