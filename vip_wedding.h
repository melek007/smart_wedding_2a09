#ifndef VIP_WEDDING_H
#define VIP_WEDDING_H
#include"QString"
#include <QSqlQuery>
#include <QSqlQueryModel>



class vip_wedding
{
public:
    vip_wedding();
       vip_wedding(int,QString,QString,QString,int);
       int getIDvip();
        QString getnamevip();
         QString getplacevip();
          QString getplanvip();
          int getpricevip();

          void setIDvip(int );
          void setnamevip(QString );
          void setplacevip(QString );
          void setplanvip(QString );
          void setpricevip(int);
          bool add();
          QSqlQueryModel * show();
          bool erase(int);
          bool modify( );
          QSqlQueryModel * triIDvip();
            QSqlQueryModel * tripricevip();
            QSqlQueryModel * trinamevip();
            QSqlQueryModel * searchnamevip(QString);
            QSqlQueryModel * searchplacevip(QString);
            QSqlQueryModel * searchpricevip(int);






    private:
          QString name,place , plan ;
          int IDvip,price;

};

#endif // VIP_WEDDING_H
