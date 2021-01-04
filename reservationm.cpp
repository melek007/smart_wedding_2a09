#include "reservationm.h"
#include "ui_reservationm.h"
#include <QDialog>
#include "bandM.h"
#include "singerM.h"
#include<QPrinter>
#include<QPainter>
#include<QPdfWriter>
#include <QMessageBox>
#include<QVBoxLayout>
#include<QtDebug>
#include<QFileInfo>
#include<QFileDialog>
#include <QSettings>
#include <QProcess>
#include <QDebug>
#include <QtPrintSupport>
#include<QMediaPlayer>
#include <QDate>

reservationM::reservationM(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reservationM)
{
    ui->setupUi(this);
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


}

reservationM::~reservationM()
{
    delete ui;
}


void reservationM::on_pushButton_clicked()
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





void reservationM::on_pushButton_2_clicked()
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

