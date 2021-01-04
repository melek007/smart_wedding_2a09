#include "personnel.h"
#include <QDebug>
#include <QString>
personnel::personnel()
{
cin=0;
nom="";
prenom="";


}
personnel::personnel(int cin,QString nom , QString prenom)
{
  this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;

}

int personnel::get_cin(){return  cin;}
QString personnel::get_nom(){return  nom;}
QString personnel::get_prenom(){return  prenom;}

void personnel:: set_cin(int cin ){this->cin=cin;}
 void personnel:: set_nom(QString nom ){this->nom=nom;}
  void personnel:: set_prenom(QString prenom ){this->prenom=prenom;}


bool personnel::ajouterpe()
{
QSqlQuery query;
QString res1= QString::number(cin);

query.prepare("INSERT INTO CLIENT (CIN, NOM_CLIENT, PRENOM_CLIENT ) "
                    "VALUES (:cin, :nom, :prenom)");
query.bindValue(":cin", res1);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);




return    query.exec();
}

bool personnel::supprimerpe(int cin)
{
QSqlQuery query;
QString res1= QString::number(cin);
query.prepare("Delete from CLIENT where CIN = :cin ");
query.bindValue(":cin", res1);
return    query.exec();
}
QSqlQueryModel * personnel::afficherpe()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CLIENT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));

    return model;
}
  bool personnel:: modifierpe()
  {
      QSqlQuery query;
       QString id_string=QString::number(cin);

      query.prepare("update client set  CIN=:c, NOM_CLIENT=:n, PRENOM_CLIENT=:p where CIN=:c");


      query.bindValue(":c",id_string);

      query.bindValue(":n",nom);
      query.bindValue(":p",prenom);



      return query.exec();
  }
QSqlQueryModel *personnel::rechercherpe1(QString nom)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from CLIENT where  NOM_CLIENT = '"+nom+"' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));


    return model;
}
QSqlQueryModel *personnel::rechercherpe2(int cin)
{
    QSqlQueryModel * model= new QSqlQueryModel();
         QString res1= QString::number(cin);
        model->setQuery("select * from CLIENT where  CIN = '"+res1+"' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));


    return model;
}


QSqlQueryModel * personnel::tripe1()
{
    QSqlQueryModel *model= new QSqlQueryModel;

    model->setQuery("select * from CLIENT order by CIN ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    return  model;
}
QSqlQueryModel * personnel::tripe2()
{
    QSqlQueryModel *model= new QSqlQueryModel;

   model->setQuery("select * from CLIENT order by prenom_client ");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));

    return  model;
}
QSqlQueryModel * personnel::tripe3()
{
    QSqlQueryModel *model= new QSqlQueryModel;

   model->setQuery("select * from CLIENT order by nom_client ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    return  model;

}


