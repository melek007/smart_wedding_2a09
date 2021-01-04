#include "the_band.h"
#include "ui_the_band.h"
#include"bandM.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QtPrintSupport/QAbstractPrintDialog>
#include <QPrinter>
#include "QPainter"
#include <QPrintDialog>
#include <QMediaPlayer>
#include "singerM.h"
#include "cameraman.h"
#include "traiteur.h"
#include "theme.h"
#include "vip_wedding.h"
#include "voiture.h"
#include "statistiques.h"
#include "clothes.h"
#include "compte.h"
#include "personnel.h"
#include "salle.h"
#include<QPdfWriter>
#include <QPainter>
#include<QFileDialog>
#include<QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include<QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QVector>
#include <QSqlQuery>
#include<QDesktopServices>
#include <QMessageBox>
#include<QUrl>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>
#include <QPrintDialog>
#include<QtSql/QSqlQuery>
#include<QVariant>
#include "reservation.h"
#include "statsband.h"
#include "honeymoon.h"
#include "location_voiture.h"



the_band::the_band(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::the_band)
{
    ui->setupUi(this);
    ui->table_band->setModel(tmpboudinar.afficher());
    ui->table_band2->setModel(tmpboudinar.afficher());

    ui->table_singer1->setModel(tmpdrake.affichersinger());

     ui->table_chant->setModel(tmpdrake.affichersinger());
     ui->table_cameraman->setModel(tmpcameraman.affichert());
     ui->table_cameraman2->setModel(tmpcameraman.affichert());
     ui->table_honeymoon->setModel(tmphoneymoon.show());
                    ui->table_honeymoon_3->setModel(tmphoneymoon.show());

     ui->table_traiteur->setModel(tmptraiteur.affichertr());
     ui->table_traitor1->setModel(tmptraiteur.affichertr());

     ui->table_salle->setModel(tmpsalles.afficher());
     ui->table_salle1->setModel(tmpsalles.afficher());
     ui->table_vip->setModel(tmpvip.show());
     ui->table_vip1->setModel(tmpvip.show());
     ui->table_theme->setModel(tmptheme.afficherth());
     ui->table_theme1->setModel(tmptheme.afficherth());
     ui->table_car->setModel(tmpvoiture.affichervo());
     ui->table_car1->setModel(tmpvoiture.affichervo());
     ui->table_client->setModel(tmppersonnel.afficherpe());
          ui->table_client1->setModel(tmppersonnel.afficherpe());
               ui->table_clothes->setModel(tmpclothes.affichercl());
               ui->table_clothes1->setModel(tmpclothes.affichercl());
                ui->table_location_voiture->setModel(tmploc.afficherlo());




    ui->lineEdit_ID1->setValidator(new QIntValidator(0,999999,this));
    ui->LineEdit_key1->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_ID10->setValidator(new QIntValidator(0,999999,this));

    ui->lineEdit_ID->setValidator(new QIntValidator(0,999999,this));
    ui->LineEdit_key->setValidator(new QIntValidator(0,999999,this));
    ui->LineEdit_10->setValidator(new QIntValidator(0,999999,this));


    ui->modepaiment->addItem("cheque");
       ui->modepaiment->addItem("especes");
       ui->modepaiment->addItem("virement");
  ui->ID_band->setModel(cc.afficher_idband());
  ui->ID_vetements->setModel(cc.afficher_idvetements());
  ui->ID_singer->setModel(cc.afficher_idchant());
  ui->ID_traiteur->setModel(cc.afficher_idtraiteur());
  ui->ID_cameraman->setModel(cc.afficher_idcameraman());
  ui->ID_vip->setModel(cc.afficher_idvip());
  ui->ID_honeymoon->setModel(cc.afficher_idhoneymoon());
  ui->salle_ID->setModel(cc.afficher_idsalle());
  ui->ID_theme->setModel(cc.afficher_idtheme());
  ui->cin_client->setModel(cc.afficher_idcin());

   ui->table_reservation->setModel(tmpreservation.afficher());

   ui->paimentres_modif->addItem("cheque");
      ui->paimentres_modif->addItem("especes");
      ui->paimentres_modif->addItem("virement");
 ui->bandres_modif->setModel(cc.afficher_idband());
 ui->clothesres_modif->setModel(cc.afficher_idvetements());
 ui->singerres_modif->setModel(cc.afficher_idchant());
 ui->traitorres_modif->setModel(cc.afficher_idtraiteur());
 ui->camerares_modif->setModel(cc.afficher_idcameraman());
 ui->vipres_modif->setModel(cc.afficher_idvip());
 ui->honeymoonres_modif->setModel(cc.afficher_idhoneymoon());
 ui->roomres_modif->setModel(cc.afficher_idsalle());
 ui->themeres_modif->setModel(cc.afficher_idtheme());
 ui->cinres_modif->setModel(cc.afficher_idcin());


 ui->locloc_res->setModel(l.afficher_idreservation());

 ui->locloc_resmodif->setModel(l.afficher_idreservation());

 ui->locloc_car->setModel(l.afficher_idcar());
 ui->locloc_carmodif->setModel(l.afficher_idcar());




}

the_band::~the_band()
{
    delete ui;
}

void the_band::on_pushButton_2_clicked()
{
    QMediaPlayer * music =new QMediaPlayer;
     music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
     music->play();
        int id=ui->lineEdit_ID1->text().toInt();
            QString nom=ui->lineEdit_nom1->text();
            QString adresse=ui->lineEdit_adresse->text();
             QString typemusic=ui->lineEdit_typemusic->text();
             int prix=ui->lineEdit_prix->text().toInt();


             boudinar b(id,nom,adresse,typemusic,prix);
         bool test=b.ajouter();
         /*QMessageBox msgBox;

         if(test)
           {  msgBox.setText("Ajout avec succes.");

         }
         else
            { msgBox.setText("Echec d'ajout");
             msgBox.exec();
        }*/
         if(test)
         {

             QMessageBox::information(nullptr, QObject::tr("database is open"),
                         QObject::tr("ajout avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);
             ui->table_band->setModel(b.afficher());
             ui->table_band2->setModel(b.afficher());
             // qDebug()<<"Connection successful";
         }
         else

             QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                         QObject::tr("echec d ajout\n""Click Cancel to exit."), QMessageBox::Cancel);


    }



void the_band::on_pushButton_3_clicked()
{
    QMediaPlayer * music =new QMediaPlayer;
     music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
     music->play();
    boudinar s;
    s.setID(ui->LineEdit_key1->text().toInt());
    bool test=s.supprimer(s.getID());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->table_band->setModel(s.afficher());

    ui->table_band2->setModel(s.afficher());

    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
}

void the_band::on_pushButton_4_clicked()
{  QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();

            int ID=ui->lineEdit_ID10->text().toInt();
            QString nom=ui->lineEdit_nom10->text();
              QString adresse=ui->lineEdit_adresse10->text();
                QString typemusic= ui->lineEdit_music10->text();
                int prix=ui->lineEdit_prix10->text().toInt();




            boudinar E1 (ID,nom ,adresse,typemusic,prix);
             bool test=E1.modifier();
             if(test)
             {

                 QMessageBox::information(nullptr, QObject::tr("database is open"),
                             QObject::tr("modification reussite.\n""Click Cancel to exit."), QMessageBox::Ok);
    ui->table_band->setModel(E1.afficher());

    ui->table_band2->setModel(E1.afficher());
                 // qDebug()<<"Connection successful";
             }
             else

                 QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                             QObject::tr("echec de modification\n""Click Cancel to exit."), QMessageBox::Cancel);





}


void the_band::on_pushButton_5_clicked()

    {  QMediaPlayer * music =new QMediaPlayer;
       music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
       music->play();
        bool test = true;
              if (test)
                  {
                  ui->table_band->setModel(tmpboudinar.afficher());

                      ui->table_band->setModel(tmpboudinar.trierID());



                  }

              else
              {
                  QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                        QObject::tr("Erreur !.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
              }

        }



void the_band::on_pushButton_6_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    bool test = true;
          if (test)
              {
              ui->table_band->setModel(tmpboudinar.afficher());

                  ui->table_band->setModel(tmpboudinar.trierprix());



              }

          else
          {
              QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                    QObject::tr("Erreur !.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
          }

    }

void the_band::on_pushButton_7_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    bool test = true;
          if (test)
              {
              ui->table_band->setModel(tmpboudinar.afficher());

                  ui->table_band->setModel(tmpboudinar.trieradresse());



              }

          else
          {
              QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                    QObject::tr("Erreur !.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
          }

    }





void the_band::on_pushButton_8_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    ui->table_band->setModel(tmpboudinar.afficher());
            QString adresse = ui->lineEdit_search->text();
           ui->table_band->setModel(tmpboudinar.chercher(adresse));
}



void the_band::on_pushButton_9_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    ui->table_band->setModel(tmpboudinar.afficher());
            QString nom = ui->lineEdit_seach1->text();
           ui->table_band->setModel(tmpboudinar.cherchernom(nom));
}

void the_band::on_pushButton_10_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    ui->table_band->setModel(tmpboudinar.afficher());
            QString type_music = ui->lineEdit_search2->text();
           ui->table_band->setModel(tmpboudinar.cherchermusic(type_music));
}

void the_band::on_pushButton_11_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    QPrinter printer;
            QPainter painter;
            printer.setPrinterName("liste");
            QPrintDialog dialog(&printer,this);
            if(dialog.exec()==QDialog::Rejected)return;
            ui->table_band->render(&printer);
}

void the_band::on_pushButton_12_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    int id=ui->lineEdit_ID->text().toInt();
        QString nom=ui->lineEdit_nom->text();
        QString prenom=ui->lineEdit_prenom->text();
         QString typechant=ui->lineEdit_typechant->text();
         int prix=ui->lineEdit_prix->text().toInt();



         drake E(id,nom,prenom,typechant,prix);
     bool test=E.ajoutersinger();
    // QMessageBox msgBox;

    /* if(test)
       {  msgBox.setText("Ajout avec succes.");

     }
     else
        { msgBox.setText("Echec d'ajout");
         msgBox.exec();
    }*/
     if(test)
     {

         QMessageBox::information(nullptr, QObject::tr("database is open"),
                     QObject::tr("ajout avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);
  ui->table_singer1->setModel(E.affichersinger());
         // qDebug()<<"Connection successful";
     }
     else

         QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                     QObject::tr("echec d ajout\n""Click Cancel to exit."), QMessageBox::Cancel);


}

void the_band::on_pushButton_14_clicked()
{QMediaPlayer * music =new QMediaPlayer;
 music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
 music->play();
    bool test = true;
          if (test)
              {
              ui->table_chant->setModel(tmpdrake.affichersinger());

                  ui->table_chant->setModel(tmpdrake.trierIDsinger());



              }

          else
          {
              QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                    QObject::tr("Erreur !.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
          }

    }

void the_band::on_pushButton_15_clicked()
{QMediaPlayer * music =new QMediaPlayer;
 music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
 music->play();
    bool test = true;
          if (test)
              {
              ui->table_chant->setModel(tmpdrake.affichersinger());

                  ui->table_chant->setModel(tmpdrake.triernomsinger());



              }

          else
          {
              QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                    QObject::tr("Erreur !.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
          }

    }

void the_band::on_pushButton_16_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    {
        bool test = true;
              if (test)
                  {
                  ui->table_chant->setModel(tmpdrake.affichersinger());

                      ui->table_chant->setModel(tmpdrake.trierprixsinger());



                  }

              else
              {
                  QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                        QObject::tr("Erreur !.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
              }

        }


}
void the_band::on_pushButton_17_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    ui->table_chant->setModel(tmpdrake.affichersinger());
            QString nom = ui->lineEdit_searchname->text();
           ui->table_chant->setModel(tmpdrake.cherchernomsinger(nom));
}


void the_band::on_pushButton_18_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    ui->table_chant->setModel(tmpdrake.affichersinger());
QString typechant= ui->lineEdit_searchmusic->text();
ui->table_chant->setModel(tmpdrake.cherchersinger(typechant));
}

void the_band::on_pushButton_19_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    ui->table_chant->setModel(tmpdrake.affichersinger());
            int prix=ui->lineEdit_searchprice->text().toInt();
           ui->table_chant->setModel(tmpdrake.chercherprixsinger(prix));
}



void the_band::on_pushButton_20_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    QPrinter printer;
            QPainter painter;
            printer.setPrinterName("liste");
            QPrintDialog dialog(&printer,this);
            if(dialog.exec()==QDialog::Rejected)return;
            ui->table_chant->render(&printer);
}

void the_band::on_pushButton_21_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();

    drake E1;
    E1.setIDsinger(ui->LineEdit_key->text().toInt());
    bool test=E1.supprimersinger(E1.getIDsinger());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->table_chant->setModel(E1.affichersinger());
      ui->table_singer1->setModel(E1.affichersinger());

    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();

}

void the_band::on_pushButton_22_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();

        int ID=ui->LineEdit_10->text().toInt();
        QString nom=ui->LineEdit_11->text();
          QString prenom=ui->LineEdit_12->text();
            QString typechant= ui->LineEdit_13->text();
            int prix=ui->lineEdit_price->text().toInt();


        drake  E1 (ID,nom ,prenom,typechant,prix);
         bool test=E1.modifiersinger();
         if(test)
         {

             QMessageBox::information(nullptr, QObject::tr("database is open"),
                         QObject::tr("modification avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);
         ui->table_chant->setModel(E1.affichersinger());
           ui->table_singer1->setModel(E1.affichersinger());
             // qDebug()<<"Connection successful";
         }
         else

             QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                         QObject::tr("echec de modification\n""Click Cancel to exit."), QMessageBox::Cancel);




}

void the_band::on_pushButton_add_clicked()

    {
    QMediaPlayer * music =new QMediaPlayer;
        music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
        music->play();
        int id_cam=ui->lineEdit_IDcam->text().toInt();
        QString nom_cam=ui->lineEdit_nomcam->text();
         QString theme_cam=ui->lineEdit_themecam->text();
        QString adresse_cam=ui->lineEdit_adresscam->text();
        int prix_cam=ui->lineEdit_pricecam->text().toInt();
        cameraman c (id_cam,nom_cam,theme_cam,adresse_cam,prix_cam);
        bool test=c.ajoutert();
      /* msg.setText("Ajout avec succes");
         msg.setText("Ajout avec succes");
          ui->tab_salle->setModel(t.afficher());
        }
        else
          msg.setText("Echec de l'Ajout");
        msg.exec();*/
        if(test)
               {
            ui->table_cameraman->setModel(c.affichert());
            ui->table_cameraman2->setModel(c.affichert());


                   QMessageBox::information(nullptr, QObject::tr("database is open"),
                               QObject::tr("ajout avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);

                   // qDebug()<<"Connection successful";
               }
               else

                   QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                               QObject::tr("echec d ajout\n""Click Cancel to exit."), QMessageBox::Cancel);

    }


void the_band::on_pushButton_delete_clicked()
 {QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
        cameraman c; c.setidcam(ui->lineEdit_IDdelete->text().toInt());
         bool test =c.supprimert(c.getidcam());
         QMessageBox msgBox;
         if(test)

             {
               msgBox.setText("suppression avec succes.");
               ui->table_cameraman->setModel(c.affichert());
               ui->table_cameraman2->setModel(c.affichert());

             }
             else
              msgBox.setText("Echec de suppression.");
         msgBox.exec();

    }



void the_band::on_pushButton_update_clicked()

    {QMediaPlayer * music =new QMediaPlayer;
     music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
     music->play();
            int id=ui->lineEditIDchange->text().toInt();
            QString nom=ui->lineEdit_namechange->text();
            QString theme=ui->lineEdit_themchange->text();
            QString adrese = ui->lineEdit_adresschange->text();
            int prix = ui->lineEdit_pricechange->text().toInt();
           cameraman c(id,nom,theme,adrese,prix);
           QMessageBox msg;
           bool test=c.modifiert(id,nom,theme,adrese,prix);

           if(test)
           {
               ui->lineEditIDchange->clear();
               ui->lineEdit_namechange->clear();
               ui->lineEdit_themchange->clear();
               ui->lineEdit_adresschange->clear();
               ui->lineEdit_pricechange->clear();
               ui->table_cameraman->setModel(c.affichert());
               ui->table_cameraman2->setModel(c.affichert());

               msg.setText("modifiction avec succes");
           }

               else {
               msg.setText("Echec au niveau de la modification d un cameraman");
           }
           msg.exec();

    }


void the_band::on_pushButton_23_clicked()
{ QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    int id_tr=ui->lineEdit_IDtraitor->text().toInt();
    QString nom_tr=ui->lineEdit_adessetraitor->text();
    QString adresse_tr=ui->lineEdit_themetraitor->text();
    int prix_tr=ui->lineEdit_pricetraitor->text().toInt();
    traiteur t(id_tr,nom_tr,adresse_tr,prix_tr);
    bool test=t.ajoutertr();
  /* msg.setText("Ajout avec succes");
     msg.setText("Ajout avec succes");
      ui->tab_salle->setModel(t.afficher());
    }
    else
      msg.setText("Echec de l'Ajout");
    msg.exec();*/
    if(test)
           {
        ui->table_traiteur->setModel(t.affichertr());
        ui->table_traitor1->setModel(t.affichertr());


               QMessageBox::information(nullptr, QObject::tr("database is open"),
                           QObject::tr("ajout avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);

               // qDebug()<<"Connection successful";
           }
           else

               QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                           QObject::tr("echec d ajout\n""Click Cancel to exit."), QMessageBox::Cancel);

}

void the_band::on_pushButton_32_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    traiteur t1;
    t1.setid_tr(ui->lineEdit_IDdelete_2->text().toInt());
    bool test =t1.supprimertr(t1.getid_tr());
    QMessageBox msgBox;
    if(test)

        {
          msgBox.setText("suppression avec succes.");
          ui->table_traiteur->setModel(t1.affichertr());
          ui->table_traitor1->setModel(t1.affichertr());

        }
        else
         msgBox.setText("Echec de suppression.");
    msgBox.exec();
}


void the_band::on_pushButton_33_clicked()
{{QMediaPlayer * music =new QMediaPlayer;
        music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
        music->play();
        int id_tr=ui->lineEdit_idchange1->text().toInt();
        QString nom_tr=ui->lineEdit_nomchange2->text();
        QString adresse_tr = ui->lineEdit_adressechange1->text();
        int prix_tr = ui->lineEdit_prixchange3->text().toInt();
       traiteur t(id_tr,nom_tr,adresse_tr,prix_tr);
       QMessageBox msg;
       bool test=t.modifiertr(id_tr,nom_tr,adresse_tr,prix_tr);

       if(test)
       {
           ui->lineEdit_idchange1->clear();
           ui->lineEdit_adressechange1->clear();
           ui->lineEdit_nomchange2->clear();
           ui->lineEdit_prixchange3->clear();
           ui->table_traiteur->setModel(t.affichertr());
           ui->table_traitor1->setModel(t.affichertr());


           msg.setText("modifiction avec succes");


       }

           else {
           msg.setText("Echec au niveau de la modification d un traiteur");
       }
       msg.exec();
}

}

void the_band::on_pushButton_24_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
bool test = true;
      if (test)
          {
          ui->table_traiteur->setModel(tmptraiteur.affichertr());

              ui->table_traiteur->setModel(tmptraiteur.trierIDtraiteur());



          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }

}

void the_band::on_pushButton_25_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
bool test = true;
      if (test)
          {
          ui->table_traiteur->setModel(tmptraiteur.affichertr());

              ui->table_traiteur->setModel(tmptraiteur.trieradressetraiteur());



          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }

}


void the_band::on_pushButton_26_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
bool test = true;
      if (test)
          {
          ui->table_traiteur->setModel(tmptraiteur.affichertr());

              ui->table_traiteur->setModel(tmptraiteur.trierprixtraiteur());



          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }

}

void the_band::on_pushButton_29_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    ui->table_traiteur->setModel(tmptraiteur.affichertr());
            QString theme_traiteur = ui->lineEdit_searchthemetr->text();
           ui->table_traiteur->setModel(tmptraiteur.chercherthemetraiteur(theme_traiteur));
}

void the_band::on_pushButton_30_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    ui->table_traiteur->setModel(tmptraiteur.affichertr());
            QString adresse_traiteur = ui->lineEdit_searchadressetr->text();
           ui->table_traiteur->setModel(tmptraiteur.chercheradressetraiteur(adresse_traiteur));
}

void the_band::on_pushButton_31_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
     ui->table_traiteur->setModel(tmptraiteur.affichertr());
     int prix=ui->lineEdit_searchprice_tr->text().toInt();
           ui->table_traiteur->setModel(tmptraiteur.chercherprixtraiteur(prix));
}

void the_band::on_pushButton_27_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    QPrinter printer;
            QPainter painter;
            printer.setPrinterName("liste");
            QPrintDialog dialog(&printer,this);
            if(dialog.exec()==QDialog::Rejected)return;
            ui->table_traiteur->render(&printer);
}



void the_band::on_pushButton_sortID_clicked()

    {QMediaPlayer * music =new QMediaPlayer;
     music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
     music->play();
    bool test = true;
          if (test)
              {
               ui->table_cameraman->setModel(tmpcameraman.affichert());
                  ui->table_cameraman->setModel(tmpcameraman.trierIDcameraman());



              }

          else
          {
              QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                    QObject::tr("Erreur !.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
          }

    }


void the_band::on_pushButton_sortname_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
bool test = true;
      if (test)
          {
           ui->table_cameraman->setModel(tmpcameraman.affichert());
              ui->table_cameraman->setModel(tmpcameraman.triernamecameraman());



          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }

}
void the_band::on_pushButton_sorttheme_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
bool test = true;
      if (test)
          {
           ui->table_cameraman->setModel(tmpcameraman.affichert());
              ui->table_cameraman->setModel(tmpcameraman.trierthemecameraman());



          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }

}

void the_band::on_pushButton_themesearch_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    ui->table_cameraman->setModel(tmpcameraman.affichert());
            QString theme_cam = ui->lineEdit_searchtheme1->text();
           ui->table_cameraman->setModel(tmpcameraman.chercherthemecameraman(theme_cam));
}

void the_band::on_pushButton_namesearch_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    ui->table_cameraman->setModel(tmpcameraman.affichert());
            QString nom_cam = ui->lineEdit_searchname1->text();
           ui->table_cameraman->setModel(tmpcameraman.cherchernomcameraman(nom_cam));
}

void the_band::on_pushButton_adresssearch_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    ui->table_cameraman->setModel(tmpcameraman.affichert());
            QString adresse = ui->lineEdit_searchadress1->text();
           ui->table_cameraman->setModel(tmpcameraman.chercheradressecameraman(adresse));
}

void the_band::on_pushButton_pront_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    QPrinter printer;
            QPainter painter;
            printer.setPrinterName("liste");
            QPrintDialog dialog(&printer,this);
            if(dialog.exec()==QDialog::Rejected)return;
            ui->table_cameraman->render(&printer);
}

void the_band::on_pushButton_stat_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    int res;
       statistiques w(this);
       w.setWindowTitle("Stats of our singers type");

       res = w.exec();
       qDebug() << res;
       if (res == QDialog::Rejected)
         return;
}

void the_band::on_addcar_clicked()
{

    QMediaPlayer * music =new QMediaPlayer;
     music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
     music->play();
        int carte_grise=ui->addcar_grey->text().toInt();
            QString matricule=ui->addcar_matricule->text();
            QString model=ui->addcar_model->text();
             QString couleur=ui->addcar_color->text();
             int prixlocation=ui->addcar_price->text().toInt();


             voiture b(carte_grise,matricule,model,couleur,prixlocation);
         bool test=b.ajoutervo();
         /*QMessageBox msgBox;

         if(test)
           {  msgBox.setText("Ajout avec succes.");

         }
         else
            { msgBox.setText("Echec d'ajout");
             msgBox.exec();
        }*/
         if(test)
         {

             QMessageBox::information(nullptr, QObject::tr("database is open"),
                         QObject::tr("ajout avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);
             ui->table_car->setModel(tmpvoiture.affichervo());
             ui->table_car1->setModel(tmpvoiture.affichervo());

             // qDebug()<<"Connection successful";
         }
         else

             QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                         QObject::tr("echec d ajout\n""Click Cancel to exit."), QMessageBox::Cancel);


    }


void the_band::on_searchpricecar_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    ui->table_car->setModel(tmpvoiture.affichervo());
            int prix=ui->searchcar_price->text().toInt();
           ui->table_car->setModel(tmpvoiture.chercherprixlocation(prix));
}

void the_band::on_searchcolorcar_clicked()    //QString typechant= ui->lineEdit_searchmusic->text();
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    ui->table_car->setModel(tmpvoiture.affichervo());
            QString color= ui->searchcar_color->text();
           ui->table_car->setModel(tmpvoiture.cherchercouleur(color));
}

void the_band::on_searchmatriculecar_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    ui->table_car->setModel(tmpvoiture.affichervo());
            QString matricule= ui->searchcar_matricule->text();
           ui->table_car->setModel(tmpvoiture.cherchermodel(matricule));
}

void the_band::on_sortprice_car_clicked()
 {  QMediaPlayer * music =new QMediaPlayer;
        music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
        music->play();
         bool test = true;
               if (test)
                   {
                  ui->table_car->setModel(tmpvoiture.affichervo());
                 ui->table_car->setModel(tmpvoiture.trierprixvoiture());

                   }

               else
               {
                   QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                         QObject::tr("Erreur !.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
               }

         }



void the_band::on_sortmatricule_car_clicked()
{  QMediaPlayer * music =new QMediaPlayer;
       music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
       music->play();
        bool test = true;
              if (test)
                  {
                 ui->table_car->setModel(tmpvoiture.affichervo());
                ui->table_car->setModel(tmpvoiture.triermatricule());

                  }

              else
              {
                  QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                        QObject::tr("Erreur !.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
              }

        }

void the_band::on_sortgreycardcar_clicked()
{  QMediaPlayer * music =new QMediaPlayer;
       music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
       music->play();
        bool test = true;
              if (test)
                  {
                 ui->table_car->setModel(tmpvoiture.affichervo());
                ui->table_car->setModel(tmpvoiture.triercarte_grise());

                  }

              else
              {
                  QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                        QObject::tr("Erreur !.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
              }

        }

void the_band::on_pdfcar_clicked()
{
    QString strStream;
                      QTextStream out(&strStream);

                      const int rowCount = ui->table_car->model()->rowCount();
                      const int columnCount = ui->table_car->model()->columnCount();

                      out <<  "<html>\n"
                          "<head>\n"
                          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                          <<  QString("<title>%1</title>\n").arg("strTitle")
                          <<  "</head>\n"
                          "<body bgcolor=#ffffff link=#5000A0>\n"

                         //     "<align='right'> " << datefich << "</align>"
                          "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                      // headers
                      out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                      for (int column = 0; column < columnCount; column++)
                          if (!ui->table_car->isColumnHidden(column))
                              out << QString("<th>%1</th>").arg(ui->table_car->model()->headerData(column, Qt::Horizontal).toString());
                      out << "</tr></thead>\n";

                      // data table
                      for (int row = 0; row < rowCount; row++) {
                          out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                          for (int column = 0; column < columnCount; column++) {
                              if (!ui->table_car->isColumnHidden(column)) {
                                  QString data = ui->table_car->model()->data(ui->table_car->model()->index(row, column)).toString().simplified();
                                  out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                              }
                          }
                          out << "</tr>\n";
                      }
                      out <<  "</table> </center>\n"
                          "</body>\n"
                          "</html>\n";

                QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                  if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                 QPrinter printer (QPrinter::PrinterResolution);
                  printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setPaperSize(QPrinter::A4);
                printer.setOutputFileName(fileName);

                 QTextDocument doc;
                  doc.setHtml(strStream);
                  doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                  doc.print(&printer);
}

void the_band::on_printcar_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    QPrinter printer;
            QPainter painter;
            printer.setPrinterName("liste");
            QPrintDialog dialog(&printer,this);
            if(dialog.exec()==QDialog::Rejected)return;
            ui->table_car->render(&printer);
}

void the_band::on_carmodifier_clicked()
{  QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();

    int carte_grise=ui->greycard_car_modifier->text().toInt();
        QString matricule=ui->matriculeca_modifier->text();
        QString model=ui->modelcar_modifier->text();
         QString couleur=ui->colorcar_modifier->text();
         int prixlocation=ui->pricecar_modifier->text().toInt();


         voiture b(carte_grise,matricule,model,couleur,prixlocation);
             bool test=b.modifiervo();
             if(test)
             {

                 QMessageBox::information(nullptr, QObject::tr("database is open"),
                             QObject::tr("modification reussite.\n""Click Cancel to exit."), QMessageBox::Ok);
                 ui->table_car->setModel(tmpvoiture.affichervo());
                 ui->table_car1->setModel(tmpvoiture.affichervo());

                 // qDebug()<<"Connection successful";
             }
             else

                 QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                             QObject::tr("echec de modification\n""Click Cancel to exit."), QMessageBox::Cancel);





}


void the_band::on_cardelete_id_clicked()
{
        QMediaPlayer * music =new QMediaPlayer;
         music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
         music->play();
        voiture s;
        s.set_cartegrise(ui->greycard_delete->text().toInt());
        bool test=s.supprimervo(s.get_cartegrise());
        QMessageBox msgBox;

        if(test)
           { msgBox.setText("Suppression avec succes.");
            ui->table_car->setModel(tmpvoiture.affichervo());
            ui->table_car1->setModel(tmpvoiture.affichervo());


        }
        else
            msgBox.setText("Echec de suppression");
            msgBox.exec();
    }




void the_band::on_addsalla_clicked()
{
QMediaPlayer * music =new QMediaPlayer;
 music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
 music->play();
 int capacity=ui->capacitysalle_add->text().toInt();
 QString adresse=ui->adresssalleadd->text();
 int prix=ui->pricesalle_add->text().toInt();

    int id=ui->idsalla_add->text().toInt();



         Salles b(capacity,adresse,prix,id);
     bool test=b.ajouters();
     /*QMessageBox msgBox;

     if(test)
       {  msgBox.setText("Ajout avec succes.");

     }
     else
        { msgBox.setText("Echec d'ajout");
         msgBox.exec();
    }*/
     if(test)
     {

         QMessageBox::information(nullptr, QObject::tr("database is open"),
                     QObject::tr("ajout avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);
         ui->table_salle->setModel(tmpsalles.afficher());
         ui->table_salle1->setModel(tmpsalles.afficher());
         // qDebug()<<"Connection successful";
     }
     else

         QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                     QObject::tr("echec d ajout\n""Click Cancel to exit."), QMessageBox::Cancel);


}

void the_band::on_searchsalle1_price_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
     ui->table_salle->setModel(tmpsalles.afficher());
      int prix=ui->searchprice_salle->text().toInt();                                                        //     QString color= ui->searchprice_salle->text();
           ui->table_salle->setModel(tmpsalles.chercher_Salle_par_idsalle(prix));
}


void the_band::on_searchsalla2_adress_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
     ui->table_salle->setModel(tmpsalles.afficher());
     QString adresse= ui->searchadress_salle->text();                                                                          //  int prix=ui->searchadress_salle->text().toInt();
           ui->table_salle->setModel(tmpsalles.chercher_Salle_par_nom(adresse));
}

void the_band::on_searchsalla3_capacity_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
     ui->table_salle->setModel(tmpsalles.afficher());
    int cap=ui->searchcapacity_salle->text().toInt();
           ui->table_salle->setModel(tmpsalles.chercher_Salle_par_capacite(cap));}

void the_band::on_sortadress_salle_clicked()
{  QMediaPlayer * music =new QMediaPlayer;
       music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
       music->play();
        bool test = true;
              if (test)
                  {
                ui->table_salle->setModel(tmpsalles.afficher());
                ui->table_salle->setModel(tmpsalles.trier0());

                  }

              else
              {
                  QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                        QObject::tr("Erreur !.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
              }

        }
void the_band::on_sortID_salle_clicked()
{  QMediaPlayer * music =new QMediaPlayer;
       music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
       music->play();
        bool test = true;
              if (test)
                  {
                ui->table_salle->setModel(tmpsalles.afficher());
                ui->table_salle->setModel(tmpsalles.trier1());

                  }

              else
              {
                  QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                        QObject::tr("Erreur !.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
              }

        }

void the_band::on_sortcapacity_salle_clicked()
{  QMediaPlayer * music =new QMediaPlayer;
       music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
       music->play();
        bool test = true;
              if (test)
                  {
                ui->table_salle->setModel(tmpsalles.afficher());
                ui->table_salle->setModel(tmpsalles.trier2());

                  }

              else
              {
                  QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                        QObject::tr("Erreur !.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
              }

        }

void the_band::on_pdf_salle_clicked()
{
    QString strStream;
                      QTextStream out(&strStream);

                      const int rowCount = ui->table_salle->model()->rowCount();
                      const int columnCount = ui->table_salle->model()->columnCount();

                      out <<  "<html>\n"
                          "<head>\n"
                          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                          <<  QString("<title>%1</title>\n").arg("strTitle")
                          <<  "</head>\n"
                          "<body bgcolor=#ffffff link=#5000A0>\n"

                         //     "<align='right'> " << datefich << "</align>"
                          "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                      // headers
                      out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                      for (int column = 0; column < columnCount; column++)
                          if (!ui->table_salle->isColumnHidden(column))
                              out << QString("<th>%1</th>").arg(ui->table_salle->model()->headerData(column, Qt::Horizontal).toString());
                      out << "</tr></thead>\n";

                      // data table
                      for (int row = 0; row < rowCount; row++) {
                          out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                          for (int column = 0; column < columnCount; column++) {
                              if (!ui->table_salle->isColumnHidden(column)) {
                                  QString data = ui->table_salle->model()->data(ui->table_salle->model()->index(row, column)).toString().simplified();
                                  out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                              }
                          }
                          out << "</tr>\n";
                      }
                      out <<  "</table> </center>\n"
                          "</body>\n"
                          "</html>\n";

                QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                  if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                 QPrinter printer (QPrinter::PrinterResolution);
                  printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setPaperSize(QPrinter::A4);
                printer.setOutputFileName(fileName);

                 QTextDocument doc;
                  doc.setHtml(strStream);
                  doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                  doc.print(&printer);
}


void the_band::on_print_salle_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    QPrinter printer;
            QPainter painter;
            printer.setPrinterName("liste");
            QPrintDialog dialog(&printer,this);
            if(dialog.exec()==QDialog::Rejected)return;
            ui->table_salle->render(&printer);
}

void the_band::on_modifsalle_clicked()
{
QMediaPlayer * music =new QMediaPlayer;
 music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
 music->play();

 int capacity=ui->capacitysallemodif->text().toInt();
 QString adresse=ui->adressesalle_modif->text();
 int prix=ui->pricesalle_modif->text().toInt();

    int id=ui->IDsalle_modif->text().toInt();



         Salles b(capacity,adresse,prix,id);
     bool test=b.modifier();
     /*QMessageBox msgBox;

     if(test)
       {  msgBox.setText("Ajout avec succes.");

     }
     else
        { msgBox.setText("Echec d'ajout");
         msgBox.exec();
    }*/
     if(test)
     {

         QMessageBox::information(nullptr, QObject::tr("database is open"),
                     QObject::tr("ajout avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);
         ui->table_salle->setModel(tmpsalles.afficher());
         ui->table_salle1->setModel(tmpsalles.afficher());
         // qDebug()<<"Connection successful";
     }
     else

         QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                     QObject::tr("echec d ajout\n""Click Cancel to exit."), QMessageBox::Cancel);


}

void the_band::on_delete_salle_clicked()
{
        QMediaPlayer * music =new QMediaPlayer;
         music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
         music->play();
        Salles s;
        s.setIdsalle(ui->idsalle_delete->text().toInt());
        bool test=s.supprimer(s.getIdsalle());
        QMessageBox msgBox;

        if(test)
           { msgBox.setText("Suppression avec succes.");
            ui->table_salle->setModel(tmpsalles.afficher());
            ui->table_salle1->setModel(tmpsalles.afficher());


        }
        else
            msgBox.setText("Echec de suppression");
            msgBox.exec();
    }



void the_band::on_add_theme_clicked()

    {
    QMediaPlayer * music =new QMediaPlayer;
     music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
     music->play();
        int id=ui->idtheme_add->text().toInt();
            QString concept=ui->concepttheme_add->text();
           int prix=ui->pricetheme_add->text().toInt();


             theme b(id,concept,prix);
         bool test=b.ajouterth();
         /*QMessageBox msgBox;

         if(test)
           {  msgBox.setText("Ajout avec succes.");

         }
         else
            { msgBox.setText("Echec d'ajout");
             msgBox.exec();
        }*/
         if(test)
         {

             QMessageBox::information(nullptr, QObject::tr("database is open"),
                         QObject::tr("ajout avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);
             ui->table_theme->setModel(tmptheme.afficherth());
             ui->table_theme1->setModel(tmptheme.afficherth());
             // qDebug()<<"Connection successful";
         }
         else

             QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                         QObject::tr("echec d ajout\n""Click Cancel to exit."), QMessageBox::Cancel);


    }


void the_band::on_searchprice_theme_2_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    ui->table_theme->setModel(tmptheme.afficherth());
    int prix=ui->searchprice_theme->text().toInt();
           ui->table_theme->setModel(tmptheme.chercher_theme_par_prixtheme(prix));}

void the_band::on_searchid_theme_2_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    ui->table_theme->setModel(tmptheme.afficherth());
    int id=ui->searchid_theme->text().toInt();
           ui->table_theme->setModel(tmptheme.chercher_theme_par_idtheme(id));}


void the_band::on_searchconcept_theme_2_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    ui->table_theme->setModel(tmptheme.afficherth());
    QString concept=ui->searchconcept_theme->text() ;
           ui->table_theme->setModel(tmptheme.chercher_theme_par_concept(concept));}


void the_band::on_sortid_theme_clicked()
{  QMediaPlayer * music =new QMediaPlayer;
       music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
       music->play();
        bool test = true;
              if (test)
                  {
                 ui->table_theme->setModel(tmptheme.afficherth());
                ui->table_theme->setModel(tmptheme.trier0());

                  }

              else
              {
                  QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                        QObject::tr("Erreur !.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
              }

        }

void the_band::on_sortprice_theme_clicked()
{  QMediaPlayer * music =new QMediaPlayer;
       music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
       music->play();
        bool test = true;
              if (test)
                  {
                 ui->table_theme->setModel(tmptheme.afficherth());
                ui->table_theme->setModel(tmptheme.trier2());

                  }

              else
              {
                  QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                        QObject::tr("Erreur !.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
              }

        }

void the_band::on_sortconcept_theme_clicked()
{  QMediaPlayer * music =new QMediaPlayer;
       music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
       music->play();
        bool test = true;
              if (test)
                  {
                 ui->table_theme->setModel(tmptheme.afficherth());
                ui->table_theme->setModel(tmptheme.trier1());

                  }

              else
              {
                  QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                        QObject::tr("Erreur !.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
              }

        }

void the_band::on_pdf_theme_clicked()
{
    QString strStream;
                      QTextStream out(&strStream);

                      const int rowCount = ui->table_theme->model()->rowCount();
                      const int columnCount = ui->table_theme->model()->columnCount();

                      out <<  "<html>\n"
                          "<head>\n"
                          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                          <<  QString("<title>%1</title>\n").arg("strTitle")
                          <<  "</head>\n"
                          "<body bgcolor=#ffffff link=#5000A0>\n"

                         //     "<align='right'> " << datefich << "</align>"
                          "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                      // headers
                      out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                      for (int column = 0; column < columnCount; column++)
                          if (!ui->table_theme->isColumnHidden(column))
                              out << QString("<th>%1</th>").arg(ui->table_theme->model()->headerData(column, Qt::Horizontal).toString());
                      out << "</tr></thead>\n";

                      // data table
                      for (int row = 0; row < rowCount; row++) {
                          out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                          for (int column = 0; column < columnCount; column++) {
                              if (!ui->table_theme->isColumnHidden(column)) {
                                  QString data = ui->table_theme->model()->data(ui->table_theme->model()->index(row, column)).toString().simplified();
                                  out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                              }
                          }
                          out << "</tr>\n";
                      }
                      out <<  "</table> </center>\n"
                          "</body>\n"
                          "</html>\n";

                QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                  if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                 QPrinter printer (QPrinter::PrinterResolution);
                  printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setPaperSize(QPrinter::A4);
                printer.setOutputFileName(fileName);

                 QTextDocument doc;
                  doc.setHtml(strStream);
                  doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                  doc.print(&printer);
}


void the_band::on_print_theme_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    QPrinter printer;
            QPainter painter;
            printer.setPrinterName("liste");
            QPrintDialog dialog(&printer,this);
            if(dialog.exec()==QDialog::Rejected)return;
            ui->table_theme->render(&printer);
}

void the_band::on_modifier_theme_clicked()
{
QMediaPlayer * music =new QMediaPlayer;
 music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
 music->play();
    int id=ui->IDtheme_modif->text().toInt();
        QString concept=ui->concepttheme_modif->text();
       int prix=ui->pricetheme_modif->text().toInt();


         theme b(id,concept,prix);
     bool test=b.modifierth();
     /*QMessageBox msgBox;

     if(test)
       {  msgBox.setText("Ajout avec succes.");

     }
     else
        { msgBox.setText("Echec d'ajout");
         msgBox.exec();
    }*/
     if(test)
     {

         QMessageBox::information(nullptr, QObject::tr("database is open"),
                     QObject::tr("ajout avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);
         ui->table_theme->setModel(tmptheme.afficherth());
         ui->table_theme1->setModel(tmptheme.afficherth());
         // qDebug()<<"Connection successful";
     }
     else

         QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                     QObject::tr("echec d ajout\n""Click Cancel to exit."), QMessageBox::Cancel);


}

void the_band::on_pushButton_43_clicked() //delete_theme

    {
            QMediaPlayer * music =new QMediaPlayer;
             music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
             music->play();
            theme s;
            s.setIdtheme(ui->IDtheme_delete->text().toInt());
            bool test=s.supprimerth(s.getIdtheme());
            QMessageBox msgBox;

            if(test)
               { msgBox.setText("Suppression avec succes.");
                ui->table_theme->setModel(tmptheme.afficherth());
                ui->table_theme1->setModel(tmptheme.afficherth());


            }
            else
                msgBox.setText("Echec de suppression");
                msgBox.exec();
        }


void the_band::on_add_vip_clicked()

        {
        QMediaPlayer * music =new QMediaPlayer;
         music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
         music->play();
            int id=ui->idvip_add->text().toInt();
                QString name=ui->namevip_add->text();
                 QString lieu=ui->locationvip_add->text();
                  QString program=ui->programvip_ajouter->text();
               int prix=ui->pricevip_add->text().toInt();


                 vip_wedding b(id,name,lieu,program,prix);
             bool test=b.add();
             /*QMessageBox msgBox;

             if(test)
               {  msgBox.setText("Ajout avec succes.");

             }
             else
                { msgBox.setText("Echec d'ajout");
                 msgBox.exec();
            }*/
             if(test)
             {

                 QMessageBox::information(nullptr, QObject::tr("database is open"),
                             QObject::tr("ajout avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);
                 ui->table_vip->setModel(tmpvip.show());
                 ui->table_vip1->setModel(tmpvip.show());
                 // qDebug()<<"Connection successful";
             }
             else

                 QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                             QObject::tr("echec d ajout\n""Click Cancel to exit."), QMessageBox::Cancel);


        }




void the_band::on_searchlocation_vip_2_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
 ui->table_vip->setModel(tmpvip.show());
 QString location=ui->searchlocation_vip->text()    ;
          ui->table_vip->setModel(tmpvip.searchplacevip(location));}

void the_band::on_searchname_vip_2_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
 ui->table_vip->setModel(tmpvip.show());
 QString name=ui->searchname_vip->text()    ;
          ui->table_vip->setModel(tmpvip.searchnamevip(name));}


void the_band::on_searchprice_vip_2_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
 ui->table_vip->setModel(tmpvip.show());
 int prix=ui->searchprice_vip->text().toInt()    ;
          ui->table_vip->setModel(tmpvip.searchpricevip(prix));}


void the_band::on_sortid_vip_clicked()
{  QMediaPlayer * music =new QMediaPlayer;
       music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
       music->play();
        bool test = true;
              if (test)
                  {
                 ui->table_vip->setModel(tmpvip.show());
                ui->table_vip->setModel(tmpvip.triIDvip());

                  }

              else
              {
                  QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                        QObject::tr("Erreur !.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
              }

        }

void the_band::on_sortprice_vip_clicked()
{  QMediaPlayer * music =new QMediaPlayer;
       music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
       music->play();
        bool test = true;
              if (test)
                  {
                 ui->table_vip->setModel(tmpvip.show());
                ui->table_vip->setModel(tmpvip.tripricevip());

                  }

              else
              {
                  QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                        QObject::tr("Erreur !.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
              }

        }

void the_band::on_sortname_vip_clicked()
{  QMediaPlayer * music =new QMediaPlayer;
       music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
       music->play();
        bool test = true;
              if (test)
                  {
                 ui->table_vip->setModel(tmpvip.show());
                ui->table_vip->setModel(tmpvip.trinamevip());

                  }

              else
              {
                  QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                        QObject::tr("Erreur !.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
              }

        }

void the_band::on_pdf_vip_clicked()
{
    QString strStream;
                      QTextStream out(&strStream);

                      const int rowCount = ui->table_vip->model()->rowCount();
                      const int columnCount = ui->table_vip->model()->columnCount();

                      out <<  "<html>\n"
                          "<head>\n"
                          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                          <<  QString("<title>%1</title>\n").arg("strTitle")
                          <<  "</head>\n"
                          "<body bgcolor=#ffffff link=#5000A0>\n"

                         //     "<align='right'> " << datefich << "</align>"
                          "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                      // headers
                      out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                      for (int column = 0; column < columnCount; column++)
                          if (!ui->table_vip->isColumnHidden(column))
                              out << QString("<th>%1</th>").arg(ui->table_vip->model()->headerData(column, Qt::Horizontal).toString());
                      out << "</tr></thead>\n";

                      // data table
                      for (int row = 0; row < rowCount; row++) {
                          out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                          for (int column = 0; column < columnCount; column++) {
                              if (!ui->table_vip->isColumnHidden(column)) {
                                  QString data = ui->table_vip->model()->data(ui->table_vip->model()->index(row, column)).toString().simplified();
                                  out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                              }
                          }
                          out << "</tr>\n";
                      }
                      out <<  "</table> </center>\n"
                          "</body>\n"
                          "</html>\n";

                QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                  if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                 QPrinter printer (QPrinter::PrinterResolution);
                  printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setPaperSize(QPrinter::A4);
                printer.setOutputFileName(fileName);

                 QTextDocument doc;
                  doc.setHtml(strStream);
                  doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                  doc.print(&printer);
}



void the_band::on_print_vip_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    QPrinter printer;
            QPainter painter;
            printer.setPrinterName("liste");
            QPrintDialog dialog(&printer,this);
            if(dialog.exec()==QDialog::Rejected)return;
            ui->table_vip->render(&printer);
}

void the_band::on_vip_modif_clicked()

{
QMediaPlayer * music =new QMediaPlayer;
 music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
 music->play();
    int id=ui->idvip_modif->text().toInt();
        QString name=ui->namevip_modif->text();
         QString lieu=ui->locationvip_modif->text();
          QString program=ui->programvip_modifier->text();
       int prix=ui->pricevip_modif->text().toInt();


         vip_wedding b(id,name,lieu,program,prix);
     bool test=b.modify();
     /*QMessageBox msgBox;

     if(test)
       {  msgBox.setText("Ajout avec succes.");

     }
     else
        { msgBox.setText("Echec d'ajout");
         msgBox.exec();
    }*/
     if(test)
     {

         QMessageBox::information(nullptr, QObject::tr("database is open"),
                     QObject::tr("ajout avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);
         ui->table_vip->setModel(tmpvip.show());
         ui->table_vip1->setModel(tmpvip.show());
         // qDebug()<<"Connection successful";
     }
     else

         QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                     QObject::tr("echec d ajout\n""Click Cancel to exit."), QMessageBox::Cancel);


}


void the_band::on_vip_delete_clicked()
{
        QMediaPlayer * music =new QMediaPlayer;
         music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
         music->play();
        vip_wedding s;
        s.setIDvip(ui->idvip_delete->text().toInt());
        bool test=s.erase(s.getIDvip());
        QMessageBox msgBox;

        if(test)
           { msgBox.setText("Suppression avec succes.");
            ui->table_vip->setModel(tmpvip.show());
            ui->table_vip1->setModel(tmpvip.show());


        }
        else
            msgBox.setText("Echec de suppression");
            msgBox.exec();
    }

void the_band::on_add_client_clicked()

        {
        QMediaPlayer * music =new QMediaPlayer;
         music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
         music->play();
            int cin=ui->cinclient_add->text().toInt();
                QString name=ui->nameclient_add->text();
                 QString surname=ui->surnameclient_add->text();



                 personnel b(cin,name,surname);
             bool test=b.ajouterpe();
             /*QMessageBox msgBox;

             if(test)
               {  msgBox.setText("Ajout avec succes.");

             }
             else
                { msgBox.setText("Echec d'ajout");
                 msgBox.exec();
            }*/
             if(test)
             {

                 QMessageBox::information(nullptr, QObject::tr("database is open"),
                             QObject::tr("ajout avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);
                 ui->table_client->setModel(tmppersonnel.afficherpe());
                      ui->table_client1->setModel(tmppersonnel.afficherpe());
                 // qDebug()<<"Connection successful";
             }
             else

                 QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                             QObject::tr("echec d ajout\n""Click Cancel to exit."), QMessageBox::Cancel);


        }


void the_band::on_searchcin_client_2_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
  ui->table_client->setModel(tmppersonnel.afficherpe());
 int cin=ui->searchcin_client->text().toInt()   ;
          ui->table_client->setModel(tmppersonnel.rechercherpe2(cin));}

void the_band::on_searchname_client_2_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
  ui->table_client->setModel(tmppersonnel.afficherpe());
 QString nom=ui->searchname_client->text()    ;
          ui->table_client->setModel(tmppersonnel.rechercherpe1(nom));}


void the_band::on_sortcin_client_clicked()
{  QMediaPlayer * music =new QMediaPlayer;
       music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
       music->play();
        bool test = true;
              if (test)
                  {
                ui->table_client->setModel(tmppersonnel.afficherpe());
                ui->table_client->setModel(tmppersonnel.tripe1());

                  }

              else
              {
                  QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                        QObject::tr("Erreur !.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
              }

        }

void the_band::on_sortname_client_clicked()
{  QMediaPlayer * music =new QMediaPlayer;
       music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
       music->play();
        bool test = true;
              if (test)
                  {
                ui->table_client->setModel(tmppersonnel.afficherpe());
                ui->table_client->setModel(tmppersonnel.tripe3());

                  }

              else
              {
                  QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                        QObject::tr("Erreur !.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
              }

        }

void the_band::on_sortsurname_client_clicked()
{  QMediaPlayer * music =new QMediaPlayer;
       music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
       music->play();
        bool test = true;
              if (test)
                  {
                ui->table_client->setModel(tmppersonnel.afficherpe());
                ui->table_client->setModel(tmppersonnel.tripe2());

                  }

              else
              {
                  QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                        QObject::tr("Erreur !.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
              }

        }

void the_band::on_pdfclient_clicked()
{
    QString strStream;
                      QTextStream out(&strStream);

                      const int rowCount = ui->table_client->model()->rowCount();
                      const int columnCount = ui->table_client->model()->columnCount();

                      out <<  "<html>\n"
                          "<head>\n"
                          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                          <<  QString("<title>%1</title>\n").arg("strTitle")
                          <<  "</head>\n"
                          "<body bgcolor=#ffffff link=#5000A0>\n"

                         //     "<align='right'> " << datefich << "</align>"
                          "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                      // headers
                      out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                      for (int column = 0; column < columnCount; column++)
                          if (!ui->table_client->isColumnHidden(column))
                              out << QString("<th>%1</th>").arg(ui->table_client->model()->headerData(column, Qt::Horizontal).toString());
                      out << "</tr></thead>\n";

                      // data table
                      for (int row = 0; row < rowCount; row++) {
                          out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                          for (int column = 0; column < columnCount; column++) {
                              if (!ui->table_client->isColumnHidden(column)) {
                                  QString data = ui->table_client->model()->data(ui->table_client->model()->index(row, column)).toString().simplified();
                                  out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                              }
                          }
                          out << "</tr>\n";
                      }
                      out <<  "</table> </center>\n"
                          "</body>\n"
                          "</html>\n";

                QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                  if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                 QPrinter printer (QPrinter::PrinterResolution);
                  printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setPaperSize(QPrinter::A4);
                printer.setOutputFileName(fileName);

                 QTextDocument doc;
                  doc.setHtml(strStream);
                  doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                  doc.print(&printer);
}



void the_band::on_print_client_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    QPrinter printer;
            QPainter painter;
            printer.setPrinterName("liste");
            QPrintDialog dialog(&printer,this);
            if(dialog.exec()==QDialog::Rejected)return;
            ui->table_client->render(&printer);
}

void the_band::on_modif_client_clicked()

{
QMediaPlayer * music =new QMediaPlayer;
 music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
 music->play();
    int cin=ui->cinclient_modif->text().toInt();
        QString name=ui->nameclient_modif->text();
         QString surname=ui->surnameclient_modif->text();



         personnel b(cin,name,surname);
     bool test=b.modifierpe();
     /*QMessageBox msgBox;

     if(test)
       {  msgBox.setText("Ajout avec succes.");

     }
     else
        { msgBox.setText("Echec d'ajout");
         msgBox.exec();
    }*/
     if(test)
     {

         QMessageBox::information(nullptr, QObject::tr("database is open"),
                     QObject::tr("ajout avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);
         ui->table_client->setModel(tmppersonnel.afficherpe());
              ui->table_client1->setModel(tmppersonnel.afficherpe());
         // qDebug()<<"Connection successful";
     }
     else

         QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                     QObject::tr("echec d ajout\n""Click Cancel to exit."), QMessageBox::Cancel);

}

void the_band::on_delete_client_clicked()
{
        QMediaPlayer * music =new QMediaPlayer;
         music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
         music->play();
        personnel s;
        s.set_cin(ui->cinclient_delete->text().toInt());
        bool test=s.supprimerpe(s.get_cin());
        QMessageBox msgBox;

        if(test)
           { msgBox.setText("Suppression avec succes.");
            ui->table_client->setModel(tmppersonnel.afficherpe());
                 ui->table_client1->setModel(tmppersonnel.afficherpe());


        }
        else
            msgBox.setText("Echec de suppression");
            msgBox.exec();
    }


void the_band::on_add_clothes_clicked()

        {
        QMediaPlayer * music =new QMediaPlayer;
         music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
         music->play();
            int id=ui->idclothes_add->text().toInt();
                QString type=ui->typeclothes_add->text();
                 QString tailledispo=ui->sizeclothes_add->text();

               int prix=ui->priceclothes_add->text().toInt();


                 clothes b(id,type,tailledispo,prix);
             bool test=b.ajoutercl();
             /*QMessageBox msgBox;

             if(test)
               {  msgBox.setText("Ajout avec succes.");

             }
             else
                { msgBox.setText("Echec d'ajout");
                 msgBox.exec();
            }*/
             if(test)
             {

                 QMessageBox::information(nullptr, QObject::tr("database is open"),
                             QObject::tr("ajout avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);
                 ui->table_clothes->setModel(tmpclothes.affichercl());
                                ui->table_clothes1->setModel(tmpclothes.affichercl());

                 // qDebug()<<"Connection successful";
             }
             else

                 QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                             QObject::tr("echec d ajout\n""Click Cancel to exit."), QMessageBox::Cancel);


        }


void the_band::on_searchbtype_clothes_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
  ui->table_clothes->setModel(tmpclothes.affichercl());
 QString type=ui->searchtype_clothes->text()    ;
        ui->table_clothes->setModel(tmpclothes.recherchercl1(type));}


void the_band::on_searchbprice_clothes_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
  ui->table_clothes->setModel(tmpclothes.affichercl());
 int prix=ui->searchprice_clothes->text().toInt()    ;
        ui->table_clothes->setModel(tmpclothes.recherchercl2(prix));}


void the_band::on_sortid_clothes_clicked()
{  QMediaPlayer * music =new QMediaPlayer;
       music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
       music->play();
        bool test = true;
              if (test)
                  {
               ui->table_clothes->setModel(tmpclothes.affichercl());
             ui->table_clothes->setModel(tmpclothes.tricl1());

                  }

              else
              {
                  QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                        QObject::tr("Erreur !.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
              }

        }

void the_band::on_sorttype_clothes_clicked()
{  QMediaPlayer * music =new QMediaPlayer;
       music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
       music->play();
        bool test = true;
              if (test)
                  {
               ui->table_clothes->setModel(tmpclothes.affichercl());
             ui->table_clothes->setModel(tmpclothes.tricl2());

                  }

              else
              {
                  QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                        QObject::tr("Erreur !.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
              }

        }

void the_band::on_sortprice_clothes_clicked()
{  QMediaPlayer * music =new QMediaPlayer;
       music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
       music->play();
        bool test = true;
              if (test)
                  {
               ui->table_clothes->setModel(tmpclothes.affichercl());
             ui->table_clothes->setModel(tmpclothes.tricl3());

                  }

              else
              {
                  QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                        QObject::tr("Erreur !.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
              }

        }

void the_band::on_pdf_clothes_clicked()
{
    QString strStream;
                      QTextStream out(&strStream);

                      const int rowCount = ui->table_clothes->model()->rowCount();
                      const int columnCount = ui->table_clothes->model()->columnCount();

                      out <<  "<html>\n"
                          "<head>\n"
                          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                          <<  QString("<title>%1</title>\n").arg("strTitle")
                          <<  "</head>\n"
                          "<body bgcolor=#ffffff link=#5000A0>\n"

                         //     "<align='right'> " << datefich << "</align>"
                          "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                      // headers
                      out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                      for (int column = 0; column < columnCount; column++)
                          if (!ui->table_clothes->isColumnHidden(column))
                              out << QString("<th>%1</th>").arg(ui->table_clothes->model()->headerData(column, Qt::Horizontal).toString());
                      out << "</tr></thead>\n";

                      // data table
                      for (int row = 0; row < rowCount; row++) {
                          out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                          for (int column = 0; column < columnCount; column++) {
                              if (!ui->table_clothes->isColumnHidden(column)) {
                                  QString data = ui->table_clothes->model()->data(ui->table_clothes->model()->index(row, column)).toString().simplified();
                                  out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                              }
                          }
                          out << "</tr>\n";
                      }
                      out <<  "</table> </center>\n"
                          "</body>\n"
                          "</html>\n";

                QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                  if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                 QPrinter printer (QPrinter::PrinterResolution);
                  printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setPaperSize(QPrinter::A4);
                printer.setOutputFileName(fileName);

                 QTextDocument doc;
                  doc.setHtml(strStream);
                  doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                  doc.print(&printer);
}


void the_band::on_print_clothes_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    QPrinter printer;
            QPainter painter;
            printer.setPrinterName("liste");
            QPrintDialog dialog(&printer,this);
            if(dialog.exec()==QDialog::Rejected)return;
            ui->table_clothes->render(&printer);
}

void the_band::on_modify_clothes_clicked()

{
QMediaPlayer * music =new QMediaPlayer;
 music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
 music->play();
    int id=ui->idclothes_modif->text().toInt();
        QString type=ui->typeclothes_modif->text();
         QString tailledispo=ui->size_modifcl->text();

       int prix=ui->priceclothes_modif->text().toInt();


         clothes b(id,type,tailledispo,prix);
     bool test=b.modifiercl();
     /*QMessageBox msgBox;

     if(test)
       {  msgBox.setText("Ajout avec succes.");

     }
     else
        { msgBox.setText("Echec d'ajout");
         msgBox.exec();
    }*/
     if(test)
     {

         QMessageBox::information(nullptr, QObject::tr("database is open"),
                     QObject::tr("modification avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);
         ui->table_clothes->setModel(tmpclothes.affichercl());
                        ui->table_clothes1->setModel(tmpclothes.affichercl());

         // qDebug()<<"Connection successful";
     }
     else

         QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                     QObject::tr("echec de modif \n""Click Cancel to exit."), QMessageBox::Cancel);


}


void the_band::on_clothes_delete_clicked()
{
        QMediaPlayer * music =new QMediaPlayer;
         music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
         music->play();
        clothes s;
        s.set_idvet(ui->idclothes_delete->text().toInt());
        bool test=s.supprimercl(s.get_idvet());
        QMessageBox msgBox;

        if(test)
           { msgBox.setText("Suppression avec succes.");
            ui->table_clothes->setModel(tmpclothes.affichercl());
                 ui->table_clothes1->setModel(tmpclothes.affichercl());


        }
        else
            msgBox.setText("Echec de suppression");
            msgBox.exec();


}
void the_band::on_pushButton_clicked()
{  int prix= 0;

    int ID_reservation=ui->ID_reservation->text().toInt();
    QDate date= ui->date_reservation->date();
          QString date_resrvation= date.toString("dd/MM/yy");
    QDate datec= ui->date_mariage->date();
          QString date_mariage= datec.toString("dd/MM/yy");
           int cin_client=ui->cin_client->currentText().toInt();
           int ID_band=ui->ID_band->currentText().toInt();
            int ID_cameraman=ui->ID_cameraman->currentText().toInt();
            int ID_honeymoon=ui->ID_honeymoon->currentText().toInt();
            int ID_vip=ui->ID_vip->currentText().toInt();
            int ID_traiteur=ui->ID_traiteur->currentText().toInt();
            int ID_theme=ui->ID_theme->currentText().toInt();
            int ID_salle=ui->salle_ID->currentText().toInt();
            int ID_vetements=ui->ID_vetements->currentText().toInt();
            int ID_chant=ui->ID_singer->currentText().toInt();
              QString  modepaiment=ui->modepaiment->currentText();


                reservation cc (ID_reservation,cin_client,date_resrvation,date_mariage,ID_band, ID_cameraman, ID_chant, ID_honeymoon,ID_salle,ID_theme,ID_traiteur,ID_vetements, ID_vip,prix,modepaiment     );
                    bool test=cc.ajouter();
                    /*QMessageBox msgBox;

                    if(test)
                      {  msgBox.setText("Ajout avec succes.");

                    }
                    else
                       { msgBox.setText("Echec d'ajout");
                        msgBox.exec();
                   }*/
                    if(test)
                    {

                        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                    QObject::tr("ajout avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);
                        ui->table_reservation->setModel(cc.afficher());

                        // qDebug()<<"Connection successful";
                    }
                    else

                        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                    QObject::tr("echec d ajout\n""Click Cancel to exit."), QMessageBox::Cancel);


               }











void the_band::on_pushButton_45_clicked()
{
    reservation s;
    s.setID_reservation(ui->lineEdit_IDreservation->text().toInt());
    bool test=s.supprimer(s.getID_reservation());
    if(test)
    {

        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("supression avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);
        ui->table_reservation->setModel(cc.afficher());

        // qDebug()<<"Connection successful";
    }
    else

        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("supression reussite\n""Click Cancel to exit."), QMessageBox::Cancel);


}

void the_band::on_modifyreservation_clicked()
{
int prix= 0;

    int ID_reservation=ui->idreservation_modif->text().toInt();
    QDate date= ui->dateres_modif->date();
          QString dateres_modif= date.toString("dd/MM/yy");
    QDate datec= ui->datemar_modif->date();
          QString datemar_modif= datec.toString("dd/MM/yy");
           int cin_client=ui->cinres_modif->currentText().toInt();
           int ID_band=ui->bandres_modif->currentText().toInt();
            int ID_cameraman=ui->camerares_modif->currentText().toInt();
            int ID_honeymoon=ui->honeymoonres_modif->currentText().toInt();
            int ID_vip=ui->vipres_modif->currentText().toInt();
            int ID_traiteur=ui->traitorres_modif->currentText().toInt();
            int ID_theme=ui->themeres_modif->currentText().toInt();
            int ID_salle=ui->roomres_modif->currentText().toInt();
            int ID_vetements=ui->clothesres_modif->currentText().toInt();
            int ID_chant=ui->singerres_modif->currentText().toInt();
              QString  modepaiment=ui->paimentres_modif->currentText();



              reservation cc (ID_reservation,cin_client,dateres_modif,datemar_modif,ID_band, ID_cameraman, ID_chant, ID_honeymoon,ID_salle,ID_theme,ID_traiteur,ID_vetements, ID_vip,prix,modepaiment     );
                    bool test=cc.modifierres();
                    /*QMessageBox msgBox;

                    if(test)
                     {  msgBox.setText("Ajout avec succes.");

                    }
                    else
                       { msgBox.setText("Echec d'ajout");
                        msgBox.exec();
                   }*/
                    if(test)
                    {

                        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                    QObject::tr("modification avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);
                        ui->table_reservation->setModel(tmpreservation.afficher());

                        // qDebug()<<"Connection successful";
                    }
                    else

                        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                    QObject::tr("echec de modification \n""Click Cancel to exit."), QMessageBox::Cancel);


               }







void the_band::on_print_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    QPrinter printer;
            QPainter painter;
            printer.setPrinterName("liste");
            QPrintDialog dialog(&printer,this);
            if(dialog.exec()==QDialog::Rejected)return;
            ui->table_reservation->render(&printer);
}

void the_band::on_pdf_clicked()
{
    QString strStream;
                      QTextStream out(&strStream);

                      const int rowCount = ui->table_reservation->model()->rowCount();
                      const int columnCount = ui->table_reservation->model()->columnCount();

                      out <<  "<html>\n"
                          "<head>\n"
                          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                          <<  QString("<title>%1</title>\n").arg("strTitle")
                          <<  "</head>\n"
                          "<body bgcolor=#ffffff link=#5000A0>\n"

                         //     "<align='right'> " << datefich << "</align>"
                          "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                      // headers
                      out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                      for (int column = 0; column < columnCount; column++)
                          if (!ui->table_reservation->isColumnHidden(column))
                              out << QString("<th>%1</th>").arg(ui->table_reservation->model()->headerData(column, Qt::Horizontal).toString());
                      out << "</tr></thead>\n";

                      // data table
                      for (int row = 0; row < rowCount; row++) {
                          out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                          for (int column = 0; column < columnCount; column++) {
                              if (!ui->table_reservation->isColumnHidden(column)) {
                                  QString data = ui->table_reservation->model()->data(ui->table_reservation->model()->index(row, column)).toString().simplified();
                                  out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                              }
                          }
                          out << "</tr>\n";
                      }
                      out <<  "</table> </center>\n"
                          "</body>\n"
                          "</html>\n";

                QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                  if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                 QPrinter printer (QPrinter::PrinterResolution);
                  printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setPaperSize(QPrinter::A4);
                printer.setOutputFileName(fileName);

                 QTextDocument doc;
                  doc.setHtml(strStream);
                  doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                  doc.print(&printer);
}

void the_band::on_pdfsinger_clicked()
{
    QString strStream;
                      QTextStream out(&strStream);

                      const int rowCount = ui->table_chant->model()->rowCount();
                      const int columnCount = ui->table_chant->model()->columnCount();

                      out <<  "<html>\n"
                          "<head>\n"
                          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                          <<  QString("<title>%1</title>\n").arg("strTitle")
                          <<  "</head>\n"
                          "<body bgcolor=#ffffff link=#5000A0>\n"

                         //     "<align='right'> " << datefich << "</align>"
                          "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                      // headers
                      out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                      for (int column = 0; column < columnCount; column++)
                          if (!ui->table_chant->isColumnHidden(column))
                              out << QString("<th>%1</th>").arg(ui->table_chant->model()->headerData(column, Qt::Horizontal).toString());
                      out << "</tr></thead>\n";

                      // data table
                      for (int row = 0; row < rowCount; row++) {
                          out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                          for (int column = 0; column < columnCount; column++) {
                              if (!ui->table_chant->isColumnHidden(column)) {
                                  QString data = ui->table_chant->model()->data(ui->table_chant->model()->index(row, column)).toString().simplified();
                                  out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                              }
                          }
                          out << "</tr>\n";
                      }
                      out <<  "</table> </center>\n"
                          "</body>\n"
                          "</html>\n";

                QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                  if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                 QPrinter printer (QPrinter::PrinterResolution);
                  printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setPaperSize(QPrinter::A4);
                printer.setOutputFileName(fileName);

                 QTextDocument doc;
                  doc.setHtml(strStream);
                  doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                  doc.print(&printer);
}

void the_band::on_pdfband_clicked()
{
    QString strStream;
                      QTextStream out(&strStream);

                      const int rowCount = ui->table_band->model()->rowCount();
                      const int columnCount = ui->table_band->model()->columnCount();

                      out <<  "<html>\n"
                          "<head>\n"
                          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                          <<  QString("<title>%1</title>\n").arg("strTitle")
                          <<  "</head>\n"
                          "<body bgcolor=#ffffff link=#5000A0>\n"

                         //     "<align='right'> " << datefich << "</align>"
                          "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                      // headers
                      out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                      for (int column = 0; column < columnCount; column++)
                          if (!ui->table_band->isColumnHidden(column))
                              out << QString("<th>%1</th>").arg(ui->table_band->model()->headerData(column, Qt::Horizontal).toString());
                      out << "</tr></thead>\n";

                      // data table
                      for (int row = 0; row < rowCount; row++) {
                          out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                          for (int column = 0; column < columnCount; column++) {
                              if (!ui->table_band->isColumnHidden(column)) {
                                  QString data = ui->table_band->model()->data(ui->table_band->model()->index(row, column)).toString().simplified();
                                  out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                              }
                          }
                          out << "</tr>\n";
                      }
                      out <<  "</table> </center>\n"
                          "</body>\n"
                          "</html>\n";

                QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                  if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                 QPrinter printer (QPrinter::PrinterResolution);
                  printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setPaperSize(QPrinter::A4);
                printer.setOutputFileName(fileName);

                 QTextDocument doc;
                  doc.setHtml(strStream);
                  doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                  doc.print(&printer);
}

void the_band::on_pushButton_46_clicked()
{
    int res;
       statsband w(this);
       w.setWindowTitle("Stats bands singing type");

       res = w.exec();
       qDebug() << res;
       if (res == QDialog::Rejected)
         return;
}

void the_band::on_addhoneymoon_clicked()
{

    QMediaPlayer * music =new QMediaPlayer;
     music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
     music->play();
        int id=ui->idhoneymoon_add->text().toInt();
            QString destination=ui->deshoneymoon_add->text();
            QString programme=ui->proghoneymoon_add->text();
             QString hotel=ui->hotelhoneymoon_add->text();
             int prix=ui->pricehoneymoon_add->text().toInt();


             honeymoon b(id,destination,programme,hotel,prix);
         bool test=b.add();
         /*QMessageBox msgBox;

         if(test)
           {  msgBox.setText("Ajout avec succes.");

         }
         else
            { msgBox.setText("Echec d'ajout");
             msgBox.exec();
        }*/
         if(test)
         {

             QMessageBox::information(nullptr, QObject::tr("database is open"),
                         QObject::tr("ajout avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);
             ui->table_honeymoon->setModel(tmphoneymoon.show());
             ui->table_honeymoon_3->setModel(tmphoneymoon.show());

             // qDebug()<<"Connection successful";
         }
         else

             QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                         QObject::tr("echec d ajout\n""Click Cancel to exit."), QMessageBox::Cancel);


    }



void the_band::on_pushButton_38_clicked() //price
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    ui->table_honeymoon->setModel(tmphoneymoon.show());
 int prix=ui->pricehoneymoon_search->text().toInt()    ;
        ui->table_honeymoon->setModel(tmphoneymoon.searchpriceh(prix));}


void the_band::on_pushButton_37_clicked()//nom_hotel
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    ui->table_honeymoon->setModel(tmphoneymoon.show());
    QString concept=ui->hotelhoneymoon_search->text() ;
           ui->table_honeymoon->setModel(tmphoneymoon.searchplaceh(concept));}

void the_band::on_pushButton_39_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    ui->table_honeymoon->setModel(tmphoneymoon.show());
    QString concept=ui->deshoneymoon_search->text() ;
           ui->table_honeymoon->setModel(tmphoneymoon.searchdestinationh(concept));}


void the_band::on_pricehoneymoon_sort_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
bool test = true;
      if (test)
          {
 ui->table_honeymoon->setModel(tmphoneymoon.show());
 ui->table_honeymoon->setModel(tmphoneymoon.tripriceh());



          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }

}


void the_band::on_sort_hotel_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
bool test = true;
      if (test)
          {
 ui->table_honeymoon->setModel(tmphoneymoon.show());
 ui->table_honeymoon->setModel(tmphoneymoon.trinameh());



          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }

}

void the_band::on_sort_idhoneymoon_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
bool test = true;
      if (test)
          {
 ui->table_honeymoon->setModel(tmphoneymoon.show());
 ui->table_honeymoon->setModel(tmphoneymoon.triIDh());



          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }

}

void the_band::on_print_2_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    QPrinter printer;
            QPainter painter;
            printer.setPrinterName("liste");
            QPrintDialog dialog(&printer,this);
            if(dialog.exec()==QDialog::Rejected)return;
            ui->table_honeymoon->render(&printer);
}

void the_band::on_pdf_2_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    QString strStream;
                      QTextStream out(&strStream);

                      const int rowCount = ui->table_honeymoon->model()->rowCount();
                      const int columnCount = ui->table_honeymoon->model()->columnCount();

                      out <<  "<html>\n"
                          "<head>\n"
                          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                          <<  QString("<title>%1</title>\n").arg("strTitle")
                          <<  "</head>\n"
                          "<body bgcolor=#ffffff link=#5000A0>\n"

                         //     "<align='right'> " << datefich << "</align>"
                          "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                      // headers
                      out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                      for (int column = 0; column < columnCount; column++)
                          if (!ui->table_honeymoon->isColumnHidden(column))
                              out << QString("<th>%1</th>").arg(ui->table_honeymoon->model()->headerData(column, Qt::Horizontal).toString());
                      out << "</tr></thead>\n";

                      // data table
                      for (int row = 0; row < rowCount; row++) {
                          out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                          for (int column = 0; column < columnCount; column++) {
                              if (!ui->table_honeymoon->isColumnHidden(column)) {
                                  QString data = ui->table_honeymoon->model()->data(ui->table_honeymoon->model()->index(row, column)).toString().simplified();
                                  out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                              }
                          }
                          out << "</tr>\n";
                      }
                      out <<  "</table> </center>\n"
                          "</body>\n"
                          "</html>\n";

                QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                  if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                 QPrinter printer (QPrinter::PrinterResolution);
                  printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setPaperSize(QPrinter::A4);
                printer.setOutputFileName(fileName);

                 QTextDocument doc;
                  doc.setHtml(strStream);
                  doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                  doc.print(&printer);
}


void the_band::on_update_honeymoon_clicked()
{
QMediaPlayer * music =new QMediaPlayer;
 music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
 music->play();
 int id=ui->idhoneymoon_modif->text().toInt();
     QString destination=ui->deshoneymoon_modif->text();
     QString programme=ui->proghoneymoon_modif->text();
      QString hotel=ui->hotelhoneymoon_modif->text();
      int prix=ui->prhoneymoon_modif->text().toInt();


          honeymoon b(id,destination,programme,hotel,prix);
     bool test=b.modify();
     /*QMessageBox msgBox;

     if(test)
       {  msgBox.setText("Ajout avec succes.");

     }
     else
        { msgBox.setText("Echec d'ajout");
         msgBox.exec();
    }*/
     if(test)
     {

         QMessageBox::information(nullptr, QObject::tr("database is open"),
                     QObject::tr("modification avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);
         ui->table_honeymoon->setModel(b.show());
                        ui->table_honeymoon_3->setModel(b.show());

         // qDebug()<<"Connection successful";
     }
     else

         QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                     QObject::tr("echec de modif \n""Click Cancel to exit."), QMessageBox::Cancel);


}



void the_band::on_delete_honeymoon_clicked()
{
        QMediaPlayer * music =new QMediaPlayer;
         music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
         music->play();
        honeymoon s;
        s.setIDh(ui->idhoneymoon_delete->text().toInt());
        bool test=s.erase(s.getIDh());
        QMessageBox msgBox;

        if(test)
           { msgBox.setText("Suppression avec succes.");
            ui->table_honeymoon->setModel(tmphoneymoon.show());
                           ui->table_honeymoon_3->setModel(tmphoneymoon.show());


        }
        else
            msgBox.setText("Echec de suppression");
            msgBox.exec();
    }

void the_band::on_add_location_voiture_clicked()
{
    QMediaPlayer * music =new QMediaPlayer;
     music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
     music->play();

           int ID_reservation=ui->idloc->text().toInt();
            int ID_res=ui->locloc_res->currentText().toInt();
            int ID_car=ui->locloc_car->currentText().toInt();



            location_voiture cc (ID_reservation,ID_res,ID_car  );
                    bool test=cc.ajouterlo();
                    /*QMessageBox msgBox;

                    if(test)
                      {  msgBox.setText("Ajout avec succes.");

                    }
                    else
                       { msgBox.setText("Echec d'ajout");
                        msgBox.exec();
                   }*/
                    if(test)
                    {

                        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                    QObject::tr("ajout avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);
                        ui->table_location_voiture->setModel(cc.afficherlo());

                        // qDebug()<<"Connection successful";
                    }
                    else

                        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                    QObject::tr("echec d ajout\n""Click Cancel to exit."), QMessageBox::Cancel);


               }








void the_band::on_delete_carreserv_clicked()
{
        QMediaPlayer * music =new QMediaPlayer;
         music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
         music->play();
        location_voiture s;
        s.setidloc(ui->locloc_delete->text().toInt());
        bool test=s.supprimerlo(s.getidloc());
        QMessageBox msgBox;

        if(test)
           { msgBox.setText("Suppression avec succes.");
            ui->table_location_voiture->setModel(tmploc.afficherlo());



        }
        else
            msgBox.setText("Echec de suppression");
            msgBox.exec();
    }

void the_band::on_pdfloc_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    QString strStream;
                      QTextStream out(&strStream);

                      const int rowCount = ui->table_location_voiture->model()->rowCount();
                      const int columnCount = ui->table_location_voiture->model()->columnCount();

                      out <<  "<html>\n"
                          "<head>\n"
                          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                          <<  QString("<title>%1</title>\n").arg("strTitle")
                          <<  "</head>\n"
                          "<body bgcolor=#ffffff link=#5000A0>\n"

                         //     "<align='right'> " << datefich << "</align>"
                          "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                      // headers
                      out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                      for (int column = 0; column < columnCount; column++)
                          if (!ui->table_location_voiture->isColumnHidden(column))
                              out << QString("<th>%1</th>").arg(ui->table_location_voiture->model()->headerData(column, Qt::Horizontal).toString());
                      out << "</tr></thead>\n";

                      // data table
                      for (int row = 0; row < rowCount; row++) {
                          out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                          for (int column = 0; column < columnCount; column++) {
                              if (!ui->table_location_voiture->isColumnHidden(column)) {
                                  QString data = ui->table_location_voiture->model()->data(ui->table_location_voiture->model()->index(row, column)).toString().simplified();
                                  out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                              }
                          }
                          out << "</tr>\n";
                      }
                      out <<  "</table> </center>\n"
                          "</body>\n"
                          "</html>\n";

                QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                  if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                 QPrinter printer (QPrinter::PrinterResolution);
                  printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setPaperSize(QPrinter::A4);
                printer.setOutputFileName(fileName);

                 QTextDocument doc;
                  doc.setHtml(strStream);
                  doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                  doc.print(&printer);
}


void the_band::on_printloc_clicked()
{QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    QPrinter printer;
            QPainter painter;
            printer.setPrinterName("liste");
            QPrintDialog dialog(&printer,this);
            if(dialog.exec()==QDialog::Rejected)return;
            ui->table_location_voiture->render(&printer);
}

void the_band::on_pushButton_34_clicked()
{


           int ID_reservation=ui->idloc->text().toInt();
            int ID_res=ui->locloc_res->currentText().toInt();
            int ID_car=ui->locloc_car->currentText().toInt();



            location_voiture cc (ID_reservation,ID_res,ID_car  );
                    bool test=cc.modifierlo();
                    /*QMessageBox msgBox;

                    if(test)
                      {  msgBox.setText("Ajout avec succes.");

                    }
                    else
                       { msgBox.setText("Echec d'ajout");
                        msgBox.exec();
                   }*/
                    if(test)
                    {

                        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                    QObject::tr("ajout avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);
                        ui->table_location_voiture->setModel(cc.afficherlo());

                        // qDebug()<<"Connection successful";
                    }
                    else

                        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                    QObject::tr("echec d ajout\n""Click Cancel to exit."), QMessageBox::Cancel);


               }


