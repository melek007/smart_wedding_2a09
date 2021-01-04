#include "singerM.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QSqlQueryModel>
#include<QSqlQuery>
drake::drake()
{
    ID=0; prix=0;
    nom=prenom=typechant="";

}

drake::drake(int ID,QString nom ,QString prenom ,QString typechant,int prix )
{
    this->ID=ID; this->nom=nom; this->prenom=prenom; this->typechant=typechant; this->prix=prix ;


 }
   int drake:: getIDsinger(){return ID;}
    QString drake:: getnom(){return nom;}
     QString drake:: getprenom(){return prenom;}
     QString drake:: gettypechant(){return typechant;}
     int drake:: getprix(){return prix;}
     void drake:: setIDsinger(int ID)  {this->ID=ID;}
     void drake:: setnom(QString nom){this->nom=nom;}
     void drake:: setprenom(QString prenom){this->prenom=prenom;}
     void drake:: settypechant(QString typechant){this->typechant=typechant;}
     void drake:: setprix(int prix ){this->prix=prix;}


bool drake:: ajoutersinger()
{
     QSqlQuery query;
     QString id_string= QString::number(ID);

            query.prepare("INSERT INTO chant (id_chant, nom, prenom,type_de_chant,prix) "
                          "VALUES (:id, :forename, :surname, :typechant, :price)");
            query.bindValue(":id",id_string);
            query.bindValue(":forename", nom);
            query.bindValue(":surname", prenom);
            query.bindValue(":typechant", typechant);
            query.bindValue(":price", prix);

           return query.exec();}

bool drake::supprimersinger(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare(" Delete from chant where id_chant=:id");
    query.bindValue(":id", res);

        return query.exec();}
QSqlQueryModel* drake::affichersinger()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM chant");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identenfiant"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("name"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("surname"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("sing_type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("price"));


  return  model;
}
bool drake::modifiersinger()
{

        QSqlQuery query;
        QString id_string=QString::number(ID);



       query.prepare(" UPDATE chant SET ID_chant=:ID,nom=:nom_chanteur,prenom=:prenom_chanteur,type_de_chant=:typchant,prix=:prix_chanteur WHERE ID_chant=:ID");
              query.bindValue(":ID", id_string);
              query.bindValue(":nom_chanteur",nom);
                 query.bindValue(":prenom_chanteur",prenom);
              query.bindValue(":typchant",typechant);
              query.bindValue(":prix_chanteur",prix);


              return query.exec();


}
QSqlQueryModel * drake::trierIDsinger()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from chant ORDER BY ID_chant");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identenfiant"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("name"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("surname"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("sing_type"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("price"));
                 return model ;}
QSqlQueryModel * drake::triernomsinger()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from chant ORDER BY nom");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identenfiant"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("name"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("surname"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("sing_type"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("price"));

        return model ;}

QSqlQueryModel * drake::trierprixsinger()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from chant ORDER BY prix");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identenfiant"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("name"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("surname"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("sing_type"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("price"));
        return model ;}

QSqlQueryModel * drake::cherchersinger(QString typechant)
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from chant where type_de_chant ='"+typechant+"'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identenfiant"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("name"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("surname"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("sing_type"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("price"));
        return model ;
}

QSqlQueryModel * drake::cherchernomsinger(QString nom)
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from chant where nom ='"+nom+"'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identenfiant"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("name"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("surname"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("sing_type"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("price"));
        return model ;
}

QSqlQueryModel * drake::chercherprixsinger(int prix)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString code=QString::number(prix);
        model->setQuery("SELECT * from chant where prix ='"+code+"'");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("adress"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("music_type"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("price"));
        return model ;
}
int drake::calculer(QString typechant) {
  QSqlQuery query;
  query.prepare("select * from chant where type_de_chant = :typechant");
  query.bindValue(":typechant", typechant);

  query.exec();
  int total = 0;
  while (query.next()) {
    total++;
  }

  return total;
}

