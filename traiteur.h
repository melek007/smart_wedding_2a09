#ifndef TRAITEUR_H
#define TRAITEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>



class traiteur
{
public:
    traiteur();
    traiteur(int,QString,QString,int);

    int getid_tr(){return id_tr;}
    int getprix_tr(){return prix_tr;}
    QString getnom_tr(){return nom_tr;}
    QString getadresse_tr(){return adresse_tr;}

    void setid_tr(int id_tr){this->id_tr=id_tr;}
    void setprix_tr(int prix_tr){this->prix_tr=prix_tr;}
    void setnom_tr(QString nom_tr){this->nom_tr=nom_tr;}
    void setadresse_tr(QString adresse_tr){this->adresse_tr=adresse_tr;}
    bool ajoutertr();
    QSqlQueryModel* affichertr();
    bool supprimertr(int);
    bool modifiertr(int,QString,QString,int);
    QSqlQueryModel * trierIDtraiteur();
      QSqlQueryModel * trieradressetraiteur();
      QSqlQueryModel * trierprixtraiteur();
      QSqlQueryModel * chercherthemetraiteur(QString);
      QSqlQueryModel * chercheradressetraiteur(QString);
      QSqlQueryModel * chercherprixtraiteur(int);


 private:
    int id_tr,prix_tr;
    QString nom_tr,adresse_tr;

};

#endif // TRAITEUR_H
