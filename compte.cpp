#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include "compte.h"



compte::compte()
{ degree=1;
    mdp=login="";

}

 compte::compte(QString mdp,QString login , int degree)
{
 this->mdp=mdp; this->login=login; this->degree=degree;

 }
   int compte:: getdegree(){return degree;}
    QString  compte::getmdp(){return mdp;}
     QString compte:: getlogin(){return login;}

     void compte:: setdegree(int degree ){this->degree=degree;}
      void compte:: setmdp(QString mdp ){this->mdp=mdp;}
      void compte:: setlogin(QString login ){this->login=login;}

        QSqlQueryModel * compte:: affichermdp()
        {
            QSqlQuery query;
            QSqlQueryModel * model =new QSqlQueryModel();
           query.prepare("select mot_de_passe from  compte WHERE mot_de_passe=:mdp");
             query.bindValue(":mdp",mdp);
            return model ;


        }

        QSqlQueryModel * compte:: afficherlogin()
        {
            QSqlQuery query;
            QSqlQueryModel * model =new QSqlQueryModel();
           query.prepare("select login from  compte WHERE mot_de_passe=:mdp");
             query.bindValue(":mdp",mdp);
            return model ;


        }

        QSqlQueryModel * compte:: afficherdegree()
        {
            QSqlQuery query;
            QSqlQueryModel * model =new QSqlQueryModel();
           query.prepare("select degree from  compte WHERE mot_de_passe=:mdp");
             query.bindValue(":mdp",mdp);
            return model ;


        }
