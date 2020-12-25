#include "voitureplus.h"
#include "voiture.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QSqlQueryModel>
#include<QSqlQuery>
voitureplus::voitureplus()
{
    CARTE_GRISE=prix=0;
    couleur=marque="";

}

voitureplus::voitureplus(int  CARTE_GRISE,QString couleur ,QString marque ,int prix )
{
    this->CARTE_GRISE=CARTE_GRISE; this->couleur=couleur; this->marque=marque; this->prix=prix;


 }
   int voitureplus:: getCARTE_GRISE(){return CARTE_GRISE;}
    QString voitureplus:: getcouleur(){return couleur;}
     QString voitureplus:: getmarque(){return marque;}
     int voitureplus:: getprix(){return prix;}
     void voitureplus:: setCARTE_GRISE(int CARTE_GRISE ){this->CARTE_GRISE=CARTE_GRISE;}
     void voitureplus:: setcouleur(QString couleur){this->couleur=couleur;}
     void voitureplus:: setmarque(QString marque){this->marque=marque;}
     void voitureplus:: setprix(int prix){this->prix=prix;}

bool voitureplus:: ajouter()
{
     QSqlQuery query;
     QString carte_grise_string= QString::number(CARTE_GRISE);

            query.prepare("INSERT INTO voiture (carte_grise, couleur, marque,prix) "
                          "VALUES (:carte_grise, :couleur, :marque, :prix)");
            query.bindValue(":carte_grise",carte_grise_string);
            query.bindValue(":couleur", couleur);
            query.bindValue(":marque", marque);
            query.bindValue(":prix", prix);
           return query.exec();
}

bool voitureplus::supprimer(int carte_grise)
{
    QSqlQuery query;
    QString res= QString::number(carte_grise);
    query.prepare(" Delete from voiture where carte_grise=:carte_grise");
    query.bindValue(":carte_grise", res);

        return query.exec();}
QSqlQueryModel* voitureplus::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT carte_grise,couleur,marque,prix FROM voiture");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("carte_grise"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("couleur"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));

  return  model;
}
bool voitureplus::modifier()
{

        QSqlQuery query;
        QString carte_grise_string=QString::number(CARTE_GRISE);

       query.prepare(" UPDATE voiture SET CARTE_GRISE=:CARTE_GRISE,couleur=:couleur,marque=:marque,prix=:prix WHERE CARTE_GRISE=:CARTE_GRISE");
              query.bindValue(":CARTE_GRISE", carte_grise_string);
              query.bindValue(":couleur",couleur);
                 query.bindValue(":marque",marque);
              query.bindValue(":prix",prix);

              return query.exec();
}

voitureplus voitureplus::findByCarteGrise(QString carte_grise){

    QSqlQuery query;
    voitureplus voiture = voitureplus() ;
    query.prepare(" select carte_grise,couleur,marque,prix from voiture where carte_grise="+carte_grise);
    query.exec();
    query.next();
    voiture.setCARTE_GRISE(query.value(0).toInt());
    voiture.setcouleur(query.value(1).toString());
    voiture.setmarque(query.value(2).toString());
    voiture.setprix(query.value(3).toInt());
return voiture;
}

bool voitureplus::checkExisteVoiture(QString carte_grise){

    QSqlQuery query;
    voitureplus voiture = voitureplus() ;
    query.prepare("select count(*) as nbr from voiture where carte_grise="+carte_grise);
    query.exec();
    query.next();
    if(query.value("nbr").toInt() > 0){
        return true;
    }
    return false;
}


