#include "traiteur.h"
#include "mainwindow.h"

traiteur::traiteur()
{
    id_tr=0;
    nom_tr=" ";
    adresse_tr=" ";
    prix_tr=0;

}
traiteur::traiteur(int id_tr,QString nom_tr,QString adresse_tr,int prix_tr)
{
 this->id_tr=id_tr;
 this->nom_tr=nom_tr;
 this->adresse_tr=adresse_tr;
 this->prix_tr=prix_tr;
}


bool traiteur::ajoutertr()
{

QSqlQuery query;

 QString id_tr_string=QString::number(id_tr);
 QString prix_tr_string=QString::number(prix_tr);

 query.prepare("INSERT INTO TRAITEUR(id_traiteur,adresse_traiteur,theme_traiteur,prix_traiteur)"
               "VALUES(:id,:nom,:adresse,:prix)");

 query.bindValue(":id",id_tr_string);
 query.bindValue(":nom",nom_tr);
 query.bindValue(":adresse",adresse_tr);
 query.bindValue(":prix",prix_tr_string);

return query.exec();
}
bool traiteur::supprimertr(int id_tr)
{
   QSqlQuery query;
    query.prepare("Delete from TRAITEUR where id_traiteur=:id_tr");

    query.bindValue(0,id_tr);

    return query.exec();


}
QSqlQueryModel*traiteur ::affichertr()
{

   QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM TRAITEUR");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_traiteur"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("adresse_traiteur"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("theme_traiteur"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix_traiteur"));


   return model;
}
bool traiteur::modifiertr(int id_tr,QString nom_tr,QString adresse_tr,int prix_tr)
{
    QSqlQuery query;
           QString id_tr_string=QString::number(id_tr);
           QString prix_tr_string=QString::number(prix_tr);

          query.prepare(" UPDATE traiteur SET id_traiteur=:id_tr,adresse_traiteur=:nom_traiteur,theme_traiteur=:adresse_traiteur,prix_traiteur=:prix_traiteur WHERE id_traiteur=:id_tr");
                 query.bindValue(":id_tr", id_tr_string);
                 query.bindValue(":nom_traiteur",adresse_tr);
                    query.bindValue(":adresse_traiteur",nom_tr);
                 query.bindValue(":prix_traiteur",prix_tr_string);

                 return query.exec();
}
QSqlQueryModel * traiteur::trierIDtraiteur()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from traiteur ORDER BY ID_traiteur");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_traiteur"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("adresse_traiteur"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("theme_traiteur"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix_traiteur"));
                 return model ;}
QSqlQueryModel * traiteur::trieradressetraiteur()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from traiteur ORDER BY adresse_traiteur");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_traiteur"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("adresse_traiteur"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("theme_traiteur"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix_traiteur"));

        return model ;}

QSqlQueryModel * traiteur::trierprixtraiteur()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from traiteur ORDER BY prix_traiteur");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_traiteur"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("adresse_traiteur"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("theme_traiteur"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix_traiteur"));
        return model ;}

QSqlQueryModel * traiteur::chercherthemetraiteur(QString nom_tr)
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from traiteur where theme_traiteur ='"+nom_tr+"'");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_traiteur"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("adresse_traiteur"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("theme_traiteur"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix_traiteur"));
        return model ;
}

QSqlQueryModel * traiteur::chercheradressetraiteur(QString adresse_tr)
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from traiteur where adresse_traiteur ='"+adresse_tr+"'");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_traiteur"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("adresse_traiteur"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("theme_traiteur"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix_traiteur"));
        return model ;
}

QSqlQueryModel * traiteur::chercherprixtraiteur(int prix_tr)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString code=QString::number(prix_tr);
        model->setQuery("SELECT * from traiteur where prix_traiteur ='"+code+"'");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_traiteur"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("adresse_traiteur"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("theme_traiteur"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix_traiteur"));
        return model ;
}
