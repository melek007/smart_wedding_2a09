#ifndef THEME_H
#define THEME_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class theme
{
public:
    theme();
    theme(int,QString,float);
    int get_ID_theme();
    QString get_concept();
    float get_prix();

    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher_trier();
    QSqlQueryModel * rechercher(const int &ID_theme);
    bool ajouter();
    bool supprimer(int);
    bool modifier(int ID_theme);

private:
    QString concept;
    float prix;
    int ID_theme;
};

#endif // THEME_H
