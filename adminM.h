#ifndef USERM_H
#define USERM_H
#include"QString"
#include <QSqlQuery>
#include "connection_db.h"
#include <QSqlQueryModel>

class admin
{
public:
    admin();
    admin(QString,QString,int);
       QString getlogin();
        QString getpassword();
          int getdegree();
          void setlogin(QString );
          void setpassword(QString);
          void setdegree(int);
          bool add();
          QSqlQueryModel * show();
          bool erase(QString);
          bool modify();
            QSqlQueryModel * tridegree();
            QSqlQueryModel * searchlogin(QString);





    private:
          QString login, password ;
          int degree;
};



#endif // USERM_H
