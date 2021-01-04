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

    int getidcam(){return id;}
    int getprixcam(){return prix;}
    QString getnomcam(){return nom;}
    QString getadrese(){return adrese;}
    QString getheme(){return theme;}

    void setidcam(int id){this->id=id;}
    void setprixcam(int prix){this->prix=prix;}
    void setnomcam(QString nom){this->nom=nom;}
    void setadrese(QString adrese){this->adrese=adrese;}
    void settheme(QString theme){this->theme=theme;}
    QSqlQueryModel* affichert();
    bool ajoutert();
    bool supprimert(int);
    bool modifiert(int,QString,QString,QString,int);
    QSqlQueryModel * trierIDcameraman();
      QSqlQueryModel * triernamecameraman();
      QSqlQueryModel * trierthemecameraman();
      QSqlQueryModel * chercheradressecameraman(QString);
      QSqlQueryModel * chercherthemecameraman(QString);
      QSqlQueryModel * cherchernomcameraman(QString);

private:
 int id,prix;
 QString adrese,nom,theme;
};

#endif // CAMERAMAN_H
