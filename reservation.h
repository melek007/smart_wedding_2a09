#ifndef RESERVATION_H
#define RESERVATION_H
#include"QString"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class reservation
{
public:
    reservation();
    reservation(int,int,QString,QString,int,int,int,int,int,int,int,int,int,int,QString);
    int getCIN();
     QString getdate_reservation();
      QString getdate_mariage();
      int getID_reservation();
      int getID_band();
      int getID_cameraman();
      int getID_chant();
      int getID_honeymoon();
      int getID_salle();
      int getID_theme();
      int getID_traiteur();
      int getID_vetements();
      int getID_vipwedding();
      int getprix_reservation();
        QString  getmodepaiment();

         void setID_reservation(int );
         void setdate_reservation(QString );
         void setdate_mariage(QString );
         void setCIN(int);
         void setID_band(int );
         void setID_cameraman(int );
         void setID_chant(int );
          void setID_honeymoon(int );
         void setID_salle(int );
         void setID_theme(int );
         void setID_traiteur(int );
         void setID_vetements(int );
         void setID_vipwedding(int );
          void setprix_reservation(int);
          void setmodepaiment(QString);
         bool ajouter();
         QSqlQueryModel * afficher();
         bool supprimer(int);
         bool modifierres();
          QSqlQueryModel * verifierid(int);
          QSqlQueryModel *searchidres(int);
         QSqlQueryModel * afficher_idband();
         QSqlQueryModel * afficher_idsalle();
         QSqlQueryModel * afficher_idtheme();
         QSqlQueryModel * afficher_idvip();
         QSqlQueryModel * afficher_idcin();
         QSqlQueryModel * afficher_idvetements();
         QSqlQueryModel * afficher_idtraiteur();
         QSqlQueryModel * afficher_idcameraman();
         QSqlQueryModel * afficher_idhoneymoon();
         QSqlQueryModel * afficher_idchant();
         QSqlQueryModel  * afficher_prixtheme();
         QSqlQueryModel  *trierIDres();
   private:
         QString date_mariage , date_reservation ,modepaiment ;
         int CIN,ID_reservation,ID_band,ID_cameraman,ID_chant,ID_honeymoon,ID_salle,ID_theme,ID_traiteur,ID_vetements,ID_vipwedding,prix_reservation;
};

#endif // RESERVATION_H
