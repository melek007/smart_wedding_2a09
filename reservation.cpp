#include "reservation.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QSqlQueryModel>
#include<QSqlQuery>
reservation::reservation()
{  ID_reservation=ID_band=ID_chant=ID_salle=ID_theme=CIN=ID_traiteur=ID_cameraman=ID_honeymoon=ID_vetements=ID_vipwedding=prix_reservation=0;
  date_reservation= date_mariage=modepaiment="" ;

}

 reservation::reservation(int ID_reservation,int CIN,QString date_reservation,QString date_mariage,int ID_band,int ID_cameraman,int ID_chant,int ID_honeymoon,int ID_salle,int ID_theme,int ID_traiteur,int ID_vetements,int ID_vipwedding,int prix_reservation,QString modepaiment)
 {

this->ID_reservation=ID_reservation; this->date_reservation=date_reservation; this->date_mariage=date_mariage;this->ID_band=ID_band;this->ID_cameraman=ID_cameraman;
  this->ID_chant=ID_chant;this->ID_honeymoon=ID_honeymoon;this-> ID_salle= ID_salle;this->ID_theme=ID_theme;this->ID_traiteur=ID_traiteur;this->ID_vetements=ID_vetements;
     this->ID_vipwedding=ID_vipwedding; this->CIN=CIN;this->prix_reservation=prix_reservation;this->modepaiment=modepaiment;

 }
   int reservation:: getID_reservation(){return ID_reservation;}
   int  reservation::getCIN(){return CIN;}
    QString  reservation::getdate_reservation(){return date_reservation;}
     QString reservation:: getdate_mariage(){return date_mariage;}
     int reservation:: getID_chant(){return ID_chant;}
     int reservation:: getID_cameraman(){return ID_cameraman;}
     int reservation:: getID_band(){return ID_band;}
     int reservation:: getID_traiteur(){return ID_traiteur;}
     int reservation:: getID_vetements(){return ID_vetements;}
     int reservation:: getID_honeymoon(){return ID_honeymoon;}
     int reservation:: getID_theme(){return ID_theme;}
     int reservation:: getID_salle(){return ID_salle;}
     int reservation:: getID_vipwedding(){return ID_vipwedding;}
     int reservation:: getprix_reservation(){return prix_reservation;}
     QString reservation:: getmodepaiment(){return modepaiment;}


     void reservation:: setID_reservation(int ID_reservation ){this->ID_reservation=ID_reservation;}
      void reservation:: setdate_reservation(QString date_reservation ){this->date_reservation=date_reservation;}
      void reservation:: setdate_mariage(QString date_mariage){this->date_mariage=date_mariage;}
      void reservation:: setCIN(int CIN){this->CIN=CIN;}
       void reservation:: setID_chant(int ID_chant ){this->ID_chant=ID_chant;}
        void reservation:: setID_cameraman(int ID_cameraman){this->ID_cameraman=ID_cameraman;}
         void reservation:: setID_band(int ID_band ){this->ID_band=ID_band;}
          void reservation:: setID_traiteur(int ID_traiteur ){this->ID_traiteur=ID_traiteur;}
           void reservation:: setID_vetements(int ID_vetements ){this->ID_vetements=ID_vetements;}
            void reservation:: setID_honeymoon(int ID_honeymoon ){this->ID_honeymoon=ID_honeymoon;}
             void reservation:: setID_theme(int ID_theme ){this->ID_theme=ID_theme;}
              void reservation:: setID_salle(int ID_salle ){this->ID_salle=ID_salle;}
               void reservation:: setID_vipwedding(int ID_vipwedding ){this->ID_vipwedding=ID_vipwedding;}
               void reservation:: setprix_reservation(int prix_reservation){this->prix_reservation=prix_reservation;}
                 void reservation:: setmodepaiment(QString modepaiment){this->modepaiment=modepaiment;}


      bool reservation::ajouter()


          {
              QSqlQuery query;
              QString reservation_string=QString::number(ID_reservation);
               QString chant_string=QString::number(ID_chant);
              QString cameraman_string=QString::number(ID_cameraman);
              QString band_string=QString::number(ID_band);
              QString traiteur_string=QString::number(ID_traiteur);
             QString vetements_string=QString::number(ID_vetements);
              QString honeymoon_string=QString::number(ID_honeymoon);
               QString theme_string=QString::number(ID_theme);
              QString salle_string=QString::number(ID_salle);
              QString vipwedding_string=QString::number(ID_vipwedding);
              QString cin_string=QString::number(CIN);
              QDate datereservation_date =QDate::fromString(date_reservation,"dd/MM/yy");
              QDate datemariage_date =QDate::fromString(date_mariage,"dd/MM/yy");
               QString prix_res=QString::number(prix_reservation);

                    query.prepare("INSERT INTO reservation (ID_reservation,date_mariage,date_reservation,ID_chant,ID_cameraman,ID_honeymoon,CIN,ID_vip,ID_traiteur,ID_vetements,ID_salle,ID_theme,ID,prix_reservation,mode_de_paiment) "
                                  "VALUES (:reservation,:datemariage,:datereservation,:chant,:cameraman,:honeymoon,:cin,:vip,:traiteur,:vetements,:salle,:theme,:band,:prix,:mode)");
                    query.bindValue(":reservation", reservation_string);
                    query.bindValue(":datemariage", datemariage_date);
                    query.bindValue(":datereservation", datereservation_date);
                   query.bindValue(":chant",chant_string);
                       query.bindValue(":cameraman",cameraman_string);
                    query.bindValue(":honeymoon",honeymoon_string);
                    query.bindValue(":cin",cin_string);
                    query.bindValue(":vip",vipwedding_string);
                    query.bindValue(":traiteur",traiteur_string);
                    query.bindValue(":vetements",vetements_string);
                    query.bindValue(":salle",salle_string);
                    query.bindValue(":theme",theme_string);
                    query.bindValue(":band",band_string);
                    query.bindValue(":prix",prix_res);
                    query.bindValue(":mode",modepaiment);

                    return query.exec();
 }

bool reservation::modifierres()
{
    QSqlQuery query;
    QString reservation_string=QString::number(ID_reservation);
     QString chant_string=QString::number(ID_chant);
    QString cameraman_string=QString::number(ID_cameraman);
    QString band_string=QString::number(ID_band);
    QString traiteur_string=QString::number(ID_traiteur);
   QString vetements_string=QString::number(ID_vetements);
    QString honeymoon_string=QString::number(ID_honeymoon);
     QString theme_string=QString::number(ID_theme);
    QString salle_string=QString::number(ID_salle);
    QString cin_string=QString::number(CIN);
    QString vipwedding_string=QString::number(ID_vipwedding);
    QDate datereservation_date =QDate::fromString(date_reservation,"dd/MM/yy");
    QDate datemariage_date =QDate::fromString(date_mariage,"dd/MM/yy");
    QString prix_res=QString::number(prix_reservation);

    query.prepare("UPDATE reservation SET ID_reservation=:reservation,date_mariage=:datemariage,date_reservation=:datereservation,ID_chant=:chant,ID_cameraman=:cameraman,ID_honeymoon=:honeymoon,CIN=:cin,ID_vip=:vip,ID_traiteur=:traiteur,ID_vetements=:vetements,ID_salle=:salle,ID_theme=:theme,ID=:band,prix_reservation=:prix,mode_de_paiment=:mode where ID_reservation=reservation");



    query.bindValue(":reservation", reservation_string);
    query.bindValue(":datemariage", datemariage_date);
    query.bindValue(":datereservation", datereservation_date);
   query.bindValue(":chant",chant_string);
       query.bindValue(":cameraman",cameraman_string);
    query.bindValue(":honeymoon",honeymoon_string);
    query.bindValue(":cin",cin_string);
    query.bindValue(":vip",vipwedding_string);
    query.bindValue(":traiteur",traiteur_string);
    query.bindValue(":vetements",vetements_string);
    query.bindValue(":salle",salle_string);
    query.bindValue(":theme",theme_string);
    query.bindValue(":band",band_string);
    query.bindValue(":prix",prix_res);
    query.bindValue(":mode",modepaiment);
    return query.exec();


}

QSqlQueryModel* reservation::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM reservation");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_reservation"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_mariage"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_reservation"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_singer"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_cameraman"));
           model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_honeymoon"));
           model->setHeaderData(6, Qt::Horizontal, QObject::tr("CIN_client"));
           model->setHeaderData(7, Qt::Horizontal, QObject::tr("ID_vip_wedding"));
           model->setHeaderData(8, Qt::Horizontal, QObject::tr("ID_traiteur"));
           model->setHeaderData(9, Qt::Horizontal, QObject::tr("ID_vetements"));
           model->setHeaderData(10, Qt::Horizontal, QObject::tr("ID_salle"));
           model->setHeaderData(11, Qt::Horizontal, QObject::tr("ID_theme"));
           model->setHeaderData(12, Qt::Horizontal, QObject::tr("ID_band"));
           model->setHeaderData(13, Qt::Horizontal, QObject::tr("prix_reservation"));
           model->setHeaderData(14, Qt::Horizontal, QObject::tr("mode_de_paiment"));



    return model;}

bool reservation::supprimer(int ID_reservation)
{ QSqlQuery query;
    QString reservation_string= QString::number(ID_reservation);
    query.prepare(" Delete from reservation where ID_reservation=:id");
    query.bindValue(":id", reservation_string);

        return query.exec();}








QSqlQueryModel * reservation::afficher_idband()
{
     QSqlQueryModel * model =new QSqlQueryModel();
     model->setQuery("select ID from  boudinar");
     return model ;

}
QSqlQueryModel * reservation::afficher_idchant()
{
     QSqlQueryModel * model =new QSqlQueryModel();
     model->setQuery("select ID_CHANT from  chant");
     return model ;

}
QSqlQueryModel * reservation::afficher_idvip()
{
     QSqlQueryModel * model =new QSqlQueryModel();
     model->setQuery("select ID_vip from VIP_WEDDING  ");
     return model ;

}
QSqlQueryModel * reservation::afficher_idhoneymoon()
{
     QSqlQueryModel * model =new QSqlQueryModel();
     model->setQuery("select ID_HONEYMOON from  honeymoon");
     return model ;

}
QSqlQueryModel * reservation::afficher_idvetements()
{
     QSqlQueryModel * model =new QSqlQueryModel();
     model->setQuery("select ID_VETEMENTS from  vetements");
     return model ;

}
QSqlQueryModel * reservation::afficher_idcameraman()
{
     QSqlQueryModel * model =new QSqlQueryModel();
     model->setQuery("select ID_CAMERAMAN from  cameraman");
     return model ;

}
QSqlQueryModel * reservation::afficher_idtraiteur()
{
     QSqlQueryModel * model =new QSqlQueryModel();
     model->setQuery("select ID_TRAITEUR from traiteur ");
     return model ;

}
QSqlQueryModel * reservation::afficher_idsalle()
{
     QSqlQueryModel * model =new QSqlQueryModel();
     model->setQuery("select ID_SALLE from  salle");
     return model ;

}
QSqlQueryModel * reservation::afficher_idtheme()
{
     QSqlQueryModel * model =new QSqlQueryModel();
     model->setQuery("select ID_THEME from  theme");
     return model ;

}
QSqlQueryModel * reservation::afficher_idcin()
{
     QSqlQueryModel * model =new QSqlQueryModel();
     model->setQuery("select CIN from  client");
     return model ;

}
QSqlQueryModel * reservation::afficher_prixtheme()
{
     QSqlQueryModel*  model =new QSqlQueryModel();
     QSqlQuery  query;
      QString id_string=QString::number(ID_theme);
     model->setQuery("select prix_theme from  theme where ID_theme=:id");
     query.bindValue(":res",id_string);
     return model ;

}

