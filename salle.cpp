#include "salle.h"
#include <QSqlQuery>
Salle::Salle()
{
    id=0;
   adresse="";
    capacite=0;
    prix=0;
}
Salle::Salle(int id,QString adresse,int capacite,int prix )
{
    this->id=id;
    this->adresse=adresse;
     this->capacite=capacite;
    this->prix=prix;
}
Salle::~Salle()
{

}


QString Salle::getadresse(){
    return adresse;
}
void Salle::setadresse(QString adresse){
    this->adresse=adresse;
}

int Salle::getId(){
    return id;
}
void Salle::setId(int id){
    this->id=id;
}
int Salle::getcapacite(){
    return capacite;
}
void Salle::setcapacite(int capacite){
    this->capacite=capacite;
}
int Salle::getprix(){
    return prix;
}






bool Salle::ajouter(){
    QSqlQuery query;
    query.prepare("insert into salle (id,adresse,capacite,prix) values (:id,:adresse,:capacite,:prix)");
    query.bindValue(":id",id);
    query.bindValue(":adresse",adresse);
    query.bindValue(":capacite",capacite);
    query.bindValue(":prix",prix);

    return query.exec();
}

bool Salle::supprimer(int id){
    QSqlQuery q;
    q.prepare("select * from salle where id=:id");
    q.bindValue(":id",id);
    q.exec();
    int total=0;
    while(q.next()){
        total++;
    }
    if(total==1){
        QSqlQuery query;
        query.prepare("delete from salle where id=:id");
        query.bindValue(":id",id);

        return query.exec();
    }
    else{
        return false;
    }


}

bool Salle::modifier(int idc ,QString adresse,int capacite,int prix){
    QSqlQuery query;
    query.prepare("update salle set adresse=:adresse,capacite=:capacite,prix=:prix where id=:idc");
    query.bindValue(":id",id);

    query.bindValue(":adresse",adresse);
    query.bindValue(":prix",prix);
    query.bindValue(":capacite",capacite);
    query.bindValue(":idc",idc);

    return query.exec();
}

QSqlQueryModel * Salle::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from salle");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CAPACITE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX"));


    return model;
}






QSqlQueryModel *Salle::chercher_Salle_par_id(QString idd)
 {

    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM Salle WHERE ID like '"+idd+"' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("ADRESSE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("CAPACITE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX"));
        return model ;
    }
}
QSqlQueryModel * Salle::chercher_Salle_par_capacite(QString m)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM Salle WHERE capacite like '"+m+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("ADRESSE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("CAPACITE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX"));
        return model ;
    }

 }

QSqlQueryModel* Salle:: trier()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from theme order by id desc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CONCEPT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));

    return model;
}

QSqlQueryModel* Salle:: trier1()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Salle order by capacite asc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CAPACITE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX"));

    return model;
}

QSqlQueryModel* Salle:: trier2()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from Salle order by prix asc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CAPACITE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX"));

    return model;
}
QSqlQueryModel* Salle::recherche_nom(QString nom){
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Salle WHERE ADRESSE like '"+nom+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CAPACITE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX"));
    return model ;
}


 bool Salle::verifierExnoms(QString nom){
 int i=0;

 QSqlQuery query;
 query.prepare("select * from salle where ADRESSE= ? ");
query.addBindValue(nom);
 if(query.exec())
 {while(query.next())
     {i++;}}

 if(i!=0)
     return true ;
 else
     return false;}






