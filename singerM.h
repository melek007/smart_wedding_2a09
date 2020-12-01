#ifndef DRAKE_H
#define DRAKE_H
#include"QString"
#include <QSqlQuery>
#include <QSqlQueryModel>

class drake
{
public:
    drake();
    drake(int,QString,QString,QString,int);
       int getID();
        QString getnom();
         QString getprenom();
          QString gettypechant();
          int getprix();


          void setID(int );
          void setnom(QString );
          void setprenom(QString );
          void settypechant(QString );
          void setprix(int );
          bool ajouter();
          QSqlQueryModel * afficher();
          bool supprimer(int);
          bool modifier();
          QSqlQueryModel * trierID();
            QSqlQueryModel * triernom();
            QSqlQueryModel * trierprix();
            QSqlQueryModel * chercher(QString);
            QSqlQueryModel * cherchernom(QString);
            QSqlQueryModel * chercherprix(int);


    private:
          QString typechant , nom, prenom;
          int ID,prix;
};

#endif // DRAKE_H
