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

     query.prepare("INSERT INTO CAMERAMAN(nom_cam,theme,prix,ID_cameraman,adresse)"
                   "VALUES(:cam,:th,:pr,:id,:adr)");

     query.bindValue(":cam",nom);
     query.bindValue(":th",theme);
     query.bindValue(":pr",prix_string);
     query.bindValue(":id",id_string);
     query.bindValue(":adr",adrese);

    return query.exec();

 }

bool cameraman::supprimert(int id)
{
   QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("Delete from CAMERAMAN where id_cameraman=:id");

    query.bindValue(":id",res);

  return query.exec();

}


QSqlQueryModel*cameraman::affichert()
{

   QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM cameraman");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("name"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("theme"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("price"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("ID_cam"));
   model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));


   return model;
}
bool cameraman::modifiert(int id,QString nom,QString theme,QString adrese,int prix)
{
    QSqlQuery query;

       QString id_string= QString::number(id);
       QString prix_string= QString::number(prix);


       query.prepare("UPDATE cameraman SET  id_cameraman=:id, nom_cam=:nom ,theme=:theme ,adresse=:adrese ,prix=:prix WHERE id_cameraman=:id ");
       query.bindValue(":id", id_string);
       query.bindValue(":nom", nom);
       query.bindValue(":theme", theme);
       query.bindValue(":adrese", adrese);
       query.bindValue(":prix", prix_string);
       return  query.exec();
   }
QSqlQueryModel * cameraman::trierIDcameraman()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from cameraman ORDER BY ID_cameraman");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("name"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("theme"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("price"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("ID_cam"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));
                 return model ;}
QSqlQueryModel * cameraman::trierthemecameraman()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from cameraman ORDER BY theme");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("name"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("theme"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("price"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("ID_cam"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));

        return model ;}

QSqlQueryModel * cameraman::triernamecameraman()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from cameraman ORDER BY nom_cam");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("name"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("theme"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("price"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("ID_cam"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));
        return model ;}

QSqlQueryModel * cameraman::cherchernomcameraman(QString nom)
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from cameraman where nom_cam ='"+nom+"'");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("name"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("theme"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("price"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("ID_cam"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));
        return model ;
}

QSqlQueryModel * cameraman::chercheradressecameraman(QString adrese)
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from cameraman where adresse ='"+adrese+"'");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("name"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("theme"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("price"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("ID_cam"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));
        return model ;
}

QSqlQueryModel * cameraman::chercherthemecameraman(QString  theme)
{
    QSqlQueryModel *model = new QSqlQueryModel();

        model->setQuery("SELECT * from cameraman where theme ='"+theme+"'");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("name"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("theme"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("price"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("ID_cam"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));
        return model ;
}
