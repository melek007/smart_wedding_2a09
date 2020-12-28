#include "theme.h"
#include <QSqlQuery>
theme::theme()
{
    id=0;
   concept="";

    prix=0;

}
theme::theme(int id,QString concept,int prix )
{
    this->id=id;
    this->concept=concept;
     this->prix=prix;


}
theme::theme(int id,int rate )
{
    this->id=id;
    this->rate=rate;



}
theme::~theme()
{

}


QString theme::getconcept(){
    return concept;
}
void theme::setconcept(QString concept){
    this->concept=concept;
}

int theme::getId(){
    return id;
}
void theme::setId(int id){
    this->id=id;
}

int theme::getprix(){
    return prix;
}
void theme::setprix(int prix){
    this->prix=prix;
}





bool theme::ajouter(){
    QSqlQuery query;
    query.prepare("insert into theme (id,concept,prix) values (:id,:concept,:prix)");
    query.bindValue(":id",id);
    query.bindValue(":concept",concept);
    query.bindValue(":prix",prix);

    return query.exec();
}

bool theme::supprimer(int id){
    QSqlQuery q;
    q.prepare("select * from theme where id=:id");
    q.bindValue(":id",id);
    q.exec();
    int total=0;
    while(q.next()){
        total++;
    }
    if(total==1){
        QSqlQuery query;
        query.prepare("delete from theme where id=:id");
        query.bindValue(":id",id);

        return query.exec();
    }
    else{
        return false;
    }


}

bool theme::modifier(int idc ,QString concept,int prix){
    QSqlQuery query;
    query.prepare("update theme set concept=:concept,prix=:prix where id=:idc");
    query.bindValue(":id",id);
    query.bindValue(":concept",concept);
    query.bindValue(":prix",prix);

    query.bindValue(":idc",idc);

    return query.exec();
}

QSqlQueryModel * theme::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from theme");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CONCEPT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));



    return model;
}




QSqlQueryModel *theme::chercher_theme_par_id(QString idd)
 {

    {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM theme WHERE ID like '"+idd+"' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("CONCEPT"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
        return model ;
    }
}
QSqlQueryModel * theme::chercher_theme_par_capacite(QString m)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM theme WHERE capacite like '"+m+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("CONCEPT"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
        return model ;
    }

 }

QSqlQueryModel* theme:: trier()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from theme order by id desc ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CONCEPT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));

    return model;
}

QSqlQueryModel* theme:: trier1()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from theme order by concept ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CONCEPT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));

    return model;
}



QSqlQueryModel* theme::recherche_nom(QString nom){
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM theme WHERE concept like '"+nom+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CONCEPT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));
    return model ;
}


 bool theme::verifierExnoms(QString nom){
 int i=0;

 QSqlQuery query;
 query.prepare("select * from theme where CONCEPT= ? ");
query.addBindValue(nom);
 if(query.exec())
 {while(query.next())
     {i++;}}

 if(i!=0)
     return true ;
 else
     return false;}




