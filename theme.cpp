#include "theme.h"
#include <QSqlQuery>
theme::theme()
{
    idtheme=0;
   concept="";

    prixtheme=0;

}
theme::theme(int idtheme,QString concept,int prixtheme )
{
    this->idtheme=idtheme;
    this->concept=concept;
     this->prixtheme=prixtheme;


}






QString theme::getconcept(){
    return concept;
}
void theme::setconcept(QString concept){
    this->concept=concept;
}

int theme::getIdtheme(){
    return idtheme;
}
void theme::setIdtheme(int idtheme){
    this->idtheme=idtheme;
}

int theme::getprixtheme(){
    return prixtheme;
}
void theme::setprixtheme(int prixtheme){
    this->prixtheme=prixtheme;
}





bool theme::ajouterth(){
    QSqlQuery query;
      QString id_string=QString::number(idtheme);
        QString prix_string=QString::number(prixtheme);
    query.prepare("insert into theme (id_theme,concept,prix_theme) values (:id,:concept,:prix)");
    query.bindValue(":id",id_string);
    query.bindValue(":concept",concept);
    query.bindValue(":prix",prix_string);

    return query.exec();
}

bool theme::supprimerth(int idtheme){
    QSqlQuery q;
    QString id_string=QString::number(idtheme);
    q.prepare("select * from theme where id_theme=:id");
    q.bindValue(":id",id_string);
    q.exec();
    int total=0;
    while(q.next()){
        total++;
    }
    if(total==1){
         QString id_string=QString::number(idtheme);
        QSqlQuery query;
        query.prepare("delete from theme where id_theme=:id");
        query.bindValue(":id",id_string);

        return query.exec();
    }
    else{
        return false;
    }


}

bool theme::modifierth(){
    QSqlQuery query;
    QString id_string=QString::number(idtheme);
      QString prix_string=QString::number(prixtheme);
    query.prepare("update theme set id_theme=:id,concept=:concept,prix_theme=:prix where id_theme=:id");
    query.bindValue(":id",id_string);
    query.bindValue(":concept",concept);
    query.bindValue(":prix",prix_string);

    return query.exec();
}

QSqlQueryModel * theme::afficherth(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from theme");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_THEME"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CONCEPT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX_THEME"));



    return model;
}




QSqlQueryModel *theme::chercher_theme_par_idtheme(int idtheme)
 {

    {
        QSqlQueryModel *model = new QSqlQueryModel;
         QString id_string=QString::number(idtheme);
        model->setQuery("SELECT * FROM theme WHERE id_theme like '"+id_string+"' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_THEME"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("CONCEPT"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX_THEME"));

        return model ;
    }
}
QSqlQueryModel * theme::chercher_theme_par_concept(QString concept)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM theme WHERE concept like '"+concept+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_THEME"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("CONCEPT"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX_THEME"));

        return model ;
    }

 }
QSqlQueryModel * theme::chercher_theme_par_prixtheme(int prixtheme)
 {

    {QSqlQueryModel *model = new QSqlQueryModel;
        QString prix_string=QString::number(prixtheme);
        model->setQuery("SELECT * FROM theme WHERE prix_theme like '"+prix_string+"%' ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_THEME"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("CONCEPT"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX_THEME"));

        return model ;
    }

 }

QSqlQueryModel* theme:: trier0()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from theme order by id_theme ");
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
QSqlQueryModel* theme:: trier2()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from theme order by prix_theme ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CONCEPT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));

    return model;
}







