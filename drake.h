#ifndef DRAKE_H
#define DRAKE_H
#include"QString"
#include <QSqlQuery>
#include <QSqlQueryModel>

class drake
{
public:
    drake();
    drake(int,QString,QString,QString);
       int getID();
        QString getnom();
         QString getprenom();
          QString gettypechant();
          void setID(int );
          void setnom(QString );
          void setprenom(QString );
          void settypechant(QString );
          bool ajouter();
          QSqlQueryModel * afficher();
          bool supprimer(int);
          bool modifier();


    private:
          QString typechant , nom, prenom;
          int ID;
};

#endif // DRAKE_H
