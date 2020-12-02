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


bool traiteur::ajouter()
{

QSqlQuery query;

 QString id_tr_string=QString::number(id_tr);
 QString prix_tr_string=QString::number(prix_tr);

 query.prepare("INSERT INTO TRAITEUR(id_tr,nom_tr,adresse_tr,prix_tr)"
               "VALUES(:id,:nom,:adresse,:prix)");

 query.bindValue(":id",id_tr);
 query.bindValue(":nom",nom_tr);
 query.bindValue(":adresse",adresse_tr);
 query.bindValue(":prix",prix_tr);

return query.exec();
}
bool traiteur::supprimer(int id_tr)
{
   QSqlQuery query;
    query.prepare("Delete from TRAITEUR where id_tr=:id_tr");

    query.bindValue(0,id_tr);

    return query.exec();


}
QSqlQueryModel*traiteur ::afficher()
{

   QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM TRAITEUR");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_tr"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom_tr"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("adresse_tr"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix_tr"));


   return model;
}
bool traiteur::modifier(int id_tr,QString nom_tr,QString adresse_tr,int prix_tr)
{
    QSqlQuery query;
           QString id_tr_string=QString::number(id_tr);
           QString prix_tr_string=QString::number(prix_tr);

          query.prepare(" UPDATE traiteur SET id_tr=:id_tr,nom_tr=:nom_traiteur,adresse_tr=:adresse_traiteur,prix_tr=:prix_traiteur WHERE id_tr=:id_tr");
                 query.bindValue(":id_tr", id_tr_string);
                 query.bindValue(":nom_traiteur",nom_tr);
                    query.bindValue(":adresse_traiteur",adresse_tr);
                 query.bindValue(":prix_traiteur",prix_tr_string);

                 return query.exec();
}
bool traiteur::rechercher(int id_tr)
{
    bool traiteur::rechercher(int id_tr)
    {
        QMessageBox msgBox;
        QMessageBox msgBox1;
        QSqlQuery query;
        bool retour=0;
        int count=0;
        query.prepare("SELECT * FROM traiteur WHERE id_tr= ? ");
        query.addBindValue(id_tr);

        if(query.exec() )
            {
    while (query.next())
       {
       count ++;
        }
    if(count==1)
       {
        msgBox.setText("traiteur existe");
        msgBox.exec();
        retour=1;
       }
    else if (count<1)
    {
        msgBox1.setText("traiteur n'existe pas");
            msgBox1.exec();
            retour=0;
    }
            }
        return retour;

    }

}
