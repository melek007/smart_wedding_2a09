#include "clothes.h"
#include <QDebug>
#include <QString>
clothes::clothes()
{
     idvet=0;
      prixvet=0;
     tailledispo="";
       typevet="";

}
clothes::clothes(int idvet,QString typevet,QString tailledispo,int prixvet)
{
  this->idvet=idvet;

    this->typevet=typevet;
  this->tailledispo=tailledispo;
this->prixvet=prixvet;

}
QString clothes::get_typevet(){return  typevet;}


int clothes::get_idvet(){return  idvet;}

int clothes::get_prix(){return  prixvet;}

QString clothes::get_tailledispo(){return  tailledispo;}


void clothes:: set_idvet(int idvet ){this->idvet=idvet;}
 void clothes:: set_typevet(QString typevet ){this->typevet=typevet;}
  void clothes:: set_tailledispo(QString tailledispo ){this->tailledispo=tailledispo;}
  void clothes:: set_prix(int prixvet ){this->prixvet=prixvet;}

bool clothes::ajoutercl()
{
QSqlQuery query;
QString res11= QString::number(idvet);
QString res22= QString::number(prixvet);

query.prepare("INSERT INTO VETEMENTS (ID_VETEMENTS, TYPE_VETEMENTS ,TAILLE_VETEMENTS,PRIX_VET) "
                    "VALUES (:id,  :type, :taille,:prix )");
query.bindValue(":id", res11);
query.bindValue(":type", typevet);
query.bindValue(":taille", tailledispo);
query.bindValue(":prix", res22);



return    query.exec();
}

bool clothes::supprimercl(int idvet)
{
    QSqlQuery query;
      QString res= QString::number(idvet);
      query.prepare("Delete from VETEMENTS where ID_VETEMENTS = :idservice ");
      query.bindValue(":idservice", res);
      return    query.exec();

}
QSqlQueryModel * clothes::affichercl()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from VETEMENTS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_vetements"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("type_vetements "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("taille_disponible "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));


    return model;
}
bool clothes::modifiercl( )
{
    QSqlQuery query;
    QString res11= QString::number(idvet);
    QString res22= QString::number(prixvet);
    query.prepare("update VETEMENTS set ID_VETEMENTS=:vet, TYPE_VETEMENTS=:type ,TAILLE_VETEMENTS:taille,PRIX_VET=:prix where ID_VETEMENTS=:vet");
    query.bindValue(":vet", res11);
    query.bindValue(":type", typevet);
    query.bindValue(":taille", tailledispo);
     query.bindValue(":prix", res22);



    return query.exec();
}
QSqlQueryModel *clothes::recherchercl1(QString typevet)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from VETEMENTS where TYPE_VETEMENTS ='"+typevet+"'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_vetements"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("type_vetements "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("taille_disponible "));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));




    return model;
}
QSqlQueryModel *clothes::recherchercl2(int prixvet)
{
    QSqlQueryModel * model= new QSqlQueryModel();
       QString res22= QString::number(prixvet);
        model->setQuery("select * from VETEMENTS where PRIX_VET ='"+res22+"'");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_vetements"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("type_vetements "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("taille_disponible "));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));


return model;
}
QSqlQueryModel * clothes::tricl1()
{
    QSqlQueryModel *model= new QSqlQueryModel;
   model->setQuery("select * from VETEMENTS order by ID_VETEMENTS");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_vetements"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type_vetements "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("taille_disponible "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));


    return  model;
}
QSqlQueryModel * clothes::tricl2()
{
    QSqlQueryModel *model= new QSqlQueryModel;

    model->setQuery("select * from VETEMENTS order by TYPE_VETEMENTS");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_vetements"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type_vetements "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("taille_disponible "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));


    return  model;
}
QSqlQueryModel * clothes::tricl3()
{
    QSqlQueryModel *model= new QSqlQueryModel;

   model->setQuery("select * from VETEMENTS order by PRIX_VET");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_vetements"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type_vetements "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("taille_disponible "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));


    return  model;
}
