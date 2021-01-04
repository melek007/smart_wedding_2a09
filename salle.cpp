#include "salle.h"
#include <QSqlQuery>


Salles::Salles()
{
    idsalle=0;
    nomsalle="";
    capacite=0;
    numbloc=0;
}
Salles::Salles(int idsalle,QString nomsalle,int capacite,int numbloc )
{
    this->idsalle=idsalle;
    this->nomsalle=nomsalle;
     this->capacite=capacite;
    this->numbloc=numbloc;
}
Salles::~Salles()
{

}


QString Salles::getnomsalle(){
    return nomsalle;
}
void Salles::setnomsalle(QString nomsalle){
    this->nomsalle=nomsalle;
}

int Salles::getIdsalle(){
    return idsalle;
}
void Salles::setIdsalle(int idsalle){
    this->idsalle=idsalle;
}
int Salles::getnumbloc(){
    return numbloc;
}
void Salles::setnumbloc(int numbloc){
    this->numbloc=numbloc;
}
int Salles::getcapacite(){
    return capacite;
}
void Salles::setcapacite(int capacite){
    this->capacite=capacite;
}





bool Salles::ajouters(){
    QSqlQuery query;
     QString cap_string=QString::number(capacite);
     QString prix_string=QString::number(numbloc);

    QString id_string=QString::number(idsalle);

    query.prepare("insert into salle (capacite,adresse_salle,prix_salle,id_salle) values (:capacite,:nomsalle,:numbloc,:id)");
    query.bindValue(":capacite",cap_string);
      query.bindValue(":nomsalle",nomsalle);
    query.bindValue(":id",id_string);


    query.bindValue(":numbloc",prix_string);

    return query.exec();
}

bool Salles::supprimer(int idsalle){
    QSqlQuery q;
    QString id_string=QString::number(idsalle);
    q.prepare("select * from salle where id_salle=:id");
    q.bindValue(":id",id_string);
    q.exec();
    int total=0; //mch mawjoud mayfasakhch
    while(q.next()){
        total++;
    }
    if(total==1){
        QSqlQuery query;
        QString id_string=QString::number(idsalle);

        query.prepare("delete from salle where id=:id");
        query.bindValue(":id",id_string);

        return query.exec();
    }
    else{
        return false;
    }


}

bool Salles::modifier(){
    QSqlQuery query;
     QString id_string=QString::number(idsalle);
     QString prix_string=QString::number(numbloc);
    QString cap_string=QString::number(capacite);
    query.prepare("update salle set  capacite=:cap,adresse_salle=:nomsalle,prix_salle=:numbloc,id_salle=:id where id_salle=:id");


    query.bindValue(":cap",cap_string);
      query.bindValue(":nomsalle",nomsalle);
    query.bindValue(":id",id_string);


    query.bindValue(":numbloc",prix_string);



    return query.exec();
}

QSqlQueryModel * Salles::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from salle");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("capacite"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("adresse_salle"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix_salle"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("id_salle"));

    return model;
}


QSqlQueryModel * Salles::chercher_Salle_par_nom(QString nomsalle)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM Salle WHERE adresse ='"+nomsalle+"'");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("capacite"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("adresse_salle"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix_salle"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("id_salle"));
        return model ;
    }

 }

QSqlQueryModel *Salles::chercher_Salle_par_idsalle(int numbloc)
 {

    {
        QSqlQueryModel *model = new QSqlQueryModel;
        QString prix_string=QString::number(numbloc);
        model->setQuery("SELECT * FROM Salle WHERE prix_salle ='"+prix_string+"' ");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("capacite"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("adresse_salle"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix_salle"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("id_salle"));
        return model ;
    }
}
QSqlQueryModel * Salles::chercher_Salle_par_capacite(int capacite)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
         QString cap_string=QString::number(capacite);
        model->setQuery("SELECT * FROM Salle WHERE capacite = '"+cap_string+"' ");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("capacite"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("adresse_salle"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix_salle"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("id_salle"));
        return model ;
    }

 }

QSqlQueryModel* Salles:: trier0()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Salle order by adresse_salle ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("capacite"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("adresse_salle"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix_salle"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("id_salle"));

    return model;
}

QSqlQueryModel* Salles:: trier1()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Salle order by id_salle ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("capacite"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("adresse_salle"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix_salle"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("id_salle"));

    return model;
}
QSqlQueryModel* Salles:: trier2()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Salle order by capacite ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("capacite"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("adresse_salle"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix_salle"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("id_salle"));
    return model;
}


