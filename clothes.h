#ifndef CLOTHES_H
#define CLOTHES_H
#include "qstring.h"
#include <QSqlQuery>
#include <QSqlQueryModel>


class clothes
{
public:
    clothes();
    clothes(int,QString,QString,int);
    QString get_typevet();
 QString get_tailledispo();
 int get_idvet();
    int get_prix();

    void set_idvet(int );
    void set_typevet(QString );
    void set_tailledispo(QString );
    void set_prix(int );


    bool ajoutercl();
    QSqlQueryModel * affichercl();
    bool supprimercl(int);
    bool modifiercl( );
    QSqlQueryModel * recherchercl1(QString);
    QSqlQueryModel * recherchercl2(int);
    QSqlQueryModel *tricl1();
    QSqlQueryModel *tricl2();
    QSqlQueryModel *tricl3();

private:

    int idvet;
     int prixvet;
    QString tailledispo;
      QString typevet;
};

#endif // CLOTHES_H
