#include "traiteur_camera.h"
#include "ui_traiteur_camera.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "traiteur.h"
#include "cameraman.h"
#include <QDialog>
#include <QMessageBox>
#include <QObject>
#include <QIntValidator>

/*Traiteur_camera::Traiteur_camera(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Traiteur_camera)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0,9999999,this));
    ui->le_prix->setValidator(new QIntValidator(0,9999999,this));
    ui->le_id_theme->setValidator(new QIntValidator(0,9999999,this));
    ui->le_prix_theme->setValidator(new QIntValidator(0,9999999,this));
}

Traiteur_camera::~Traiteur_camera()
{
    delete ui;
}

void Traiteur_camera::on_Ok_Ajoutsalle_clicked()
{
    int id_tr=ui->le_id->text().toInt();
    QString nom_tr=ui->le_nom->text();
    QString adresse_tr=ui->le_adresse->text();
    int prix_tr=ui->le_prix->text().toInt();
    traiteur t(id_tr,nom_tr,adresse_tr,prix_tr);
    bool test=t.ajouter();
  /* msg.setText("Ajout avec succes");
     msg.setText("Ajout avec succes");
      ui->tab_salle->setModel(t.afficher());
    }
    else
      msg.setText("Echec de l'Ajout");
    msg.exec();*/
   /* if(test)
           {

               QMessageBox::information(nullptr, QObject::tr("database is open"),
                           QObject::tr("ajout avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);

               // qDebug()<<"Connection successful";
           }
           else

               QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                           QObject::tr("echec d ajout\n""Click Cancel to exit."), QMessageBox::Cancel);

}

void Traiteur_camera::on_pb_supprimer1_clicked()
{
    traiteur t1; t1.setid_tr(ui->le_id_supp->text().toInt());
    bool test =t1.supprimer(t1.getid_tr());
    QMessageBox msgBox;
    if(test)

        {
          msgBox.setText("suppression avec succes.");
          ui->tab_salle->setModel(t1.afficher());
        }
        else
         msgBox.setText("Echec de suppression.");
    msgBox.exec();
}

void Traiteur_camera::on_Ok_Ajouttheme_clicked()
{
    int id=ui->le_id_theme->text().toInt();
    QString nom=ui->le_nom_dec->text();
    QString theme=ui->le_nom_theme->text();
    QString adressec=ui->le_adresse_dec->text();
    int prix=ui->le_prix_theme->text().toInt();
    cameraman c(id,nom,adressec,theme,prix);
    QMessageBox msg;
    bool test=c.ajoutert();
    if(test)
    {
   msg.setText("Ajout avec succes");
      ui->tab_theme->setModel(c.affichert());
    }
    else
      msg.setText("Echec de l'Ajout");
    msg.exec();

}

void Traiteur_camera::on_pb_supprimertheme_clicked()
{
    cameraman c1; c1.setid(ui->le_supp_theme->text().toInt());
     bool test =c1.supprimert(c1.getid());
     QMessageBox msgBox;
     if(test)

         {
           msgBox.setText("suppression avec succes.");
           ui->tab_theme->setModel(c1.affichert());
         }
         else
          msgBox.setText("Echec de suppression.");
     msgBox.exec();

}

void Traiteur_camera::on_Modifier_Modifiersalle_clicked()
{
    int id_tr=ui->le_id->text().toInt();
    QString nom_tr=ui->le_nom->text();
    QString adresse_tr=ui->le_adresse->text();
    int prix_tr=ui->le_prix->text().toInt();
    traiteur t1(id_tr,nom_tr,adresse_tr,prix_tr);
    bool test=t1.modifier();
  /* msg.setText("Ajout avec succes");
     msg.setText("Ajout avec succes");
      ui->tab_salle->setModel(t.afficher());
    }
    else
      msg.setText("Echec de l'Ajout");
    msg.exec();*/
    /*if(test)
           {

               QMessageBox::information(nullptr, QObject::tr("database is open"),
                           QObject::tr("ajout avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);

               // qDebug()<<"Connection successful";
           }
           else

               QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                           QObject::tr("echec d ajout\n""Click Cancel to exit."), QMessageBox::Cancel);
}

void Traiteur_camera::on_Modifier_Modifiertheme_clicked()
{
    int id=ui->le_id_theme->text().toInt();
    QString nom=ui->le_nom_dec->text();
    QString theme=ui->le_nom_theme->text();
    QString adressec=ui->le_adresse_dec->text();
    int prix=ui->le_prix_theme->text().toInt();
    cameraman c1(id,nom,adressec,theme,prix);
    QMessageBox msg;
    bool test=c1.modifiert();
    if(test)
    {
   msg.setText("Ajout avec succes");
      ui->tab_theme->setModel(c.affichert());
    }
    else
      msg.setText("Echec de l'Ajout");
    msg.exec();

}

void Traiteur_camera::on_pushButton_5_clicked()
{
    QMessageBox msgBox ;

            QSqlQueryModel *model = new QSqlQueryModel();
                     model->setQuery("SELECT * FROM TRAITEUR order by nom ASC");
                     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_tr"));
                     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_tr"));
                     model->setHeaderData(2, Qt::Horizontal, QObject::tr("theme_tr"));
                     model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse_tr"));
                     model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix_tr"));

                     ui->tab_salle->setModel(model);
                     ui->tab_salle->show();
                     msgBox.setText("Tri avec succès.");
                     msgBox.exec();
}/*
