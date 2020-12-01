#ifndef BOUDINAR_H
#define BOUDINAR_H
#include"QString"
#include <QSqlQuery>
#include <QSqlQueryModel>

class boudinar
{
public:
    boudinar();
     boudinar(int,QString,QString,QString,int);
       int getID();
        QString getnom();
         QString getadresse();
          QString gettypemusic();
          int getprix();

          void setID(int );
          void setnom(QString );
          void setadresse(QString );
          void settypemusic(QString );
          void setprix(int);
          bool ajouter();
          QSqlQueryModel * afficher();
          bool supprimer(int);
          bool modifier();
          QSqlQueryModel * trierID();
            QSqlQueryModel * trierprix();
            QSqlQueryModel * trieradresse();
            QSqlQueryModel * chercher(QString);
            QSqlQueryModel * cherchernom(QString);
            QSqlQueryModel * cherchermusic(QString);





    private:
          QString nom,adresse , typemusic ;
          int ID,prix;
};

#endif // BOUDINAR_H
