#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QSqlQueryModel>
#include "adminM.h"

admin::admin()
{
    login="";
    password="";
    degree=0;
}

 admin::admin(QString login,QString password,int degree)
 {

this->login=login; this->password=password;this->degree=degree;

 }
   QString admin:: getlogin(){return login;}
     QString admin:: getpassword(){return password;}
     int admin:: getdegree(){return degree;}

     void admin:: setlogin(QString login ){this->login=login;}
      void admin:: setpassword(QString password){this->password=password;}
      void admin:: setdegree(int degree){this->degree=degree;}

      bool admin:: add()
      {
           QSqlQuery query;
           QString degree_string= QString::number(degree);

                  query.prepare("INSERT INTO boudinar (id,password,degree) "
                                "VALUES (:id, :password,:degree)");
                  query.bindValue(":login",login);
                  query.bindValue(":password", password);
                  query.bindValue(":degree", degree);

                 return query.exec();}

      bool admin::erase(QString login)
      {
          QSqlQuery query;
          query.prepare(" Delete from user where login=:login");
          query.bindValue(":login", login);

              return query.exec();}
      QSqlQueryModel* admin::show()
      {
        QSqlQueryModel* model=new QSqlQueryModel();


         model->setQuery("SELECT* FROM adminM");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("login"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("password"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("degree"));


        return  model;
      }
      bool admin::modify()
      {

              QSqlQuery query;
              QString id_string=QString::number(degree);

             query.prepare(" UPDATE user SET password=:password,degree=:degree WHERE login=:login");
                    query.bindValue(":password",password);
                    query.bindValue(":degree",degree);


                    return query.exec();


      }




      QSqlQueryModel * admin::tridegree()
      {
          QSqlQueryModel *model = new QSqlQueryModel();
              model->setQuery("SELECT * from adminM ORDER BY degree");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("login"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("password"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("degree"));


              return model ;}


      QSqlQueryModel * admin::searchlogin(QString login)
      {
          QSqlQueryModel *model = new QSqlQueryModel();
              model->setQuery("SELECT * from adminM where login ='"+login+"'");
              model->setHeaderData(0,Qt::Horizontal,QObject::tr("login"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("password"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("degree"));
              return model ;
      }

