#ifndef VIP_WEDDINGM_H
#define VIP_WEDDINGM_H
#include"QString"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "connection_db.h"


class vip_wedding
{
public:
    vip_wedding();
       vip_wedding(int,QString,QString,QString,int);
       int getID();
        QString getname();
         QString getplace();
          QString getplan();
          int getprice();

          void setID(int );
          void setname(QString );
          void setplace(QString );
          void setplan(QString );
          void setprice(int);
          bool add();
          QSqlQueryModel * show();
          bool erase(int);
          bool modify();
          QSqlQueryModel * triID();
            QSqlQueryModel * triprice();
            QSqlQueryModel * searchname(QString);
            QSqlQueryModel * searchplace(QString);




    private:
          QString name,place , plan ;
          int ID,price;

};

#endif // VIP_WEDDINGM_H
