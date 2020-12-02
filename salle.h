#ifndef SALLE_H
#define SALLE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class salle
{
public:
    salle();
    salle(QString,int,QString,float);
    QString get_ID_salle();
    int get_capacite();
    QString get_adresse();
    float get_prix();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_salle_trier();
    QSqlQueryModel * rechercher_salle(const QString &ID_salle);
    bool supprimer(QString);
    bool ajouter();
    bool modifier(QString);
private:
    QString ID_salle,adresse;
    int capacite;
    float prix;
};

#endif // SALLE_H
