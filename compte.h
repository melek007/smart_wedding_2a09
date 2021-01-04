#ifndef COMPTE_H
#define COMPTE_H
#include "qstring.h"
#include <QSqlQuery>
#include <QSqlQueryModel>

class compte
{
public:
    compte();
    compte(QString,QString,int);
       int getdegree();
        QString getmdp();
         QString getlogin();



          void setdegree(int );
          void setmdp(QString );
          void setlogin(QString );


          QSqlQueryModel * affichermdp();
          QSqlQueryModel * afficherlogin();
          QSqlQueryModel * afficherdegree();

    private:
          QString mdp,login;
          int degree;
};
#endif // COMPTE_H
