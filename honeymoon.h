#ifndef HONEYMOON_H
#define HONEYMOON_H
#include"QString"
#include <QSqlQuery>
#include <QSqlQueryModel>

class honeymoon
{
public:
    honeymoon();
     honeymoon(int,QString,int,QString);
       int getID();

         QString getlieu();
          int getprix();
        QString getnom_hotel();
          void setID(int );
          void setlieu(QString );
          void setprix(int);
          void setnom_hotel(QString );
          bool ajouter();
          QSqlQueryModel * afficher();
          bool supprimer(int);
          bool modifier();
          bool rechercher(int,int,QString);
          honeymoon findByID(QString);
          bool checkExisteHoneymoon(QString);
    private:
          QString lieu ,nom_hotel ;
          int ID,prix;
};

#endif // HONEYMOON_H
