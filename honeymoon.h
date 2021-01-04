#ifndef HONEYMOON_H
#define HONEYMOON_H
#include"QString"
#include <QSqlQuery>
#include <QSqlQueryModel>
class honeymoon
{
public:
    honeymoon();
    honeymoon(int,QString,QString,QString,int);
    int getIDh();
     QString getdestination();
      QString getplaceh();
       QString getplanh();
       int getpriceh();

       void setIDh(int );
       void setdestination(QString );
       void setplaceh(QString );
       void setplanh(QString );
       void setpriceh(int);
       bool add();
       QSqlQueryModel * show();
       bool erase(int);
       bool modify( );
       QSqlQueryModel * triIDh();
         QSqlQueryModel * tripriceh();
         QSqlQueryModel * trinameh();
         QSqlQueryModel * searchdestinationh(QString);
         QSqlQueryModel * searchplaceh(QString);
         QSqlQueryModel * searchpriceh(int);






 private:
       QString destination,place , plan ;
       int IDh,price;

};


#endif // HONEYMOON_H
