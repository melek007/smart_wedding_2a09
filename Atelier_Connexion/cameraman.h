#ifndef CAMERAMAN_H
#define CAMERAMAN_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class cameraman
{
public:
    cameraman();
    cameraman (int,QString,QString,QString,int);

    int getid(){return id;}
    int getprix(){return prix;}
    QString getnom(){return nom;}
    QString getadrese(){return adrese;}
    QString getheme(){return theme;}

    void setid(int id){this->id=id;}
    void setprix(int prix){this->prix=prix;}
    void setnom(QString nom){this->nom=nom;}
    void setadrese(QString adrese){this->adrese=adrese;}
    void settheme(QString theme){this->theme=theme;}
    QSqlQueryModel* affichert();
    bool ajoutert();
    bool supprimert(int);
    bool modifiert(int,QString,QString,QString,int);
    bool recherchert(int id,QString nom,QString adrese);


private:
 int id,prix;
 QString adrese,nom,theme;
};

#endif // CAMERAMAN_H
