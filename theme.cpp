#include "theme.h"
#include <QDebug>
#include<QSqlQuery>
#include<QSqlQueryModel>

theme::theme()
{
ID_theme=0;
concept="";
prix=0;

}
theme::theme(int ID_theme,QString concept,float prix)
{
  this->ID_theme=ID_theme;
  this->concept=concept;
  this->prix=prix;

}
int theme::get_ID_theme(){return ID_theme ;}
QString theme::get_concept(){return concept;}
float theme::get_prix(){return  prix;}


bool theme::ajouter()
{
QSqlQuery query;
QString res= QString::number(ID_theme);
query.prepare("INSERT INTO theme (ID_THEME,CONCEPT, PRIX) "
                    "VALUES (:ID_theme,:concept,:prix)");
query.bindValue(":ID_theme", ID_theme);
query.bindValue(":concept", concept);
query.bindValue(":prix", prix);

return    query.exec();
}

QSqlQueryModel * theme::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from theme ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_THEME"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("CONCEPT"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX"));

    return model;
}
bool theme::supprimer(int ID_theme)
{
QSqlQuery query;
query.prepare("Delete from theme where ID = :ID_theme ");
query.bindValue(":id", ID_theme);
return    query.exec();
}

bool theme::modifier(int ID_theme)
{
    QSqlQuery query;
   QString res= QString::number(ID_theme);
   query.prepare("UPDATE theme SET ID=:ID_theme,CONCEPT=:concept,PRIX=:prix WHERE ID=:ID_theme");
   query.bindValue(":ID_theme", ID_theme);
   query.bindValue(":concept", concept);
   query.bindValue(":prix", prix);


    return  query.exec();
}
QSqlQueryModel *theme::afficher_trier()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from theme ORDER BY ID_theme");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_THEME"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CONCEPT"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("PRIX"));

    return model;
}

QSqlQueryModel *theme::rechercher(const int &ID_theme)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from theme where(ID LIKE '"+ID_theme+"')");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_THEME"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CONCEPT"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("prix"));

    return model;
}



