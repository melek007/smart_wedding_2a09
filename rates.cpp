#include "rates.h"
#include <QSqlQuery>

Rates::Rates()
{
    id="";
   nbetoiles=0;
}
Rates::Rates(QString id,int nbetoiles )
{
    this->id=id;
    this->nbetoiles=nbetoiles;
}
Rates::~Rates()
{

}




QString Rates::getId(){
    return id;
}
void Rates::setId(QString id){
    this->id=id;
}
int Rates::getnbetoiles(){
    return nbetoiles;
}
void Rates::setnbetoiles(int nbetoiles){
    this->nbetoiles=nbetoiles;
}





/*
bool Rates::ajouter(){
    QSqlQuery query;
    query.prepare("insert into rate (id,nbetoiles) values (:id,:nbetoiles)");
    query.bindValue(":id",id);
    query.bindValue(":nbetoiles",nbetoiles);



    return query.exec();
}
*/

