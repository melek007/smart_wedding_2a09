#include "zingeeer.h"
#include "ui_zingeeer.h"
#include"singerM.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QtPrintSupport/QAbstractPrintDialog>

zingeeer::zingeeer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::zingeeer)
{
    ui->setupUi(this);
    ui->table_chant->setModel(tmpdrake.afficher());
    ui->lineEdit_ID->setValidator(new QIntValidator(0,999999,this));
    ui->LineEdit_key->setValidator(new QIntValidator(0,999999,this));
    ui->LineEdit_10->setValidator(new QIntValidator(0,999999,this));
}

zingeeer::~zingeeer()
{
    delete ui;
}


void zingeeer::on_pushButton_clicked()
{
    int id=ui->lineEdit_ID->text().toInt();
        QString nom=ui->lineEdit_nom->text();
        QString prenom=ui->lineEdit_prenom->text();
         QString typechant=ui->lineEdit_typechant->text();
         int prix=ui->lineEdit_prix->text().toInt();



         drake E(id,nom,prenom,typechant,prix);
     bool test=E.ajouter();
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

         // qDebug()<<"Connection successful";
     }
     else

         QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                     QObject::tr("echec d ajout\n""Click Cancel to exit."), QMessageBox::Cancel);


}


void zingeeer::on_pushButton_3_clicked()
{

    drake E1;
    E1.setID(ui->LineEdit_key->text().toInt());
    bool test=E1.supprimer(E1.getID());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->table_chant->setModel(E1.afficher());

    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();

}


void zingeeer::on_pushButton_4_clicked()
{
        int ID=ui->LineEdit_10->text().toInt();
        QString nom=ui->LineEdit_11->text();
          QString prenom=ui->LineEdit_12->text();
            QString typechant= ui->LineEdit_13->text();
            int prix=ui->lineEdit_price->text().toInt();


        drake  E1 (ID,nom ,prenom,typechant,prix);
         bool test=E1.modifier();
         if(test)
         {

             QMessageBox::information(nullptr, QObject::tr("database is open"),
                         QObject::tr("modification avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);
         ui->table_chant->setModel(E1.afficher());
             // qDebug()<<"Connection successful";
         }
         else

             QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                         QObject::tr("echec de modification\n""Click Cancel to exit."), QMessageBox::Cancel);




}


void zingeeer::on_pushButton_5_clicked()

    {
        bool test = true;
              if (test)
                  {
                  ui->table_chant->setModel(tmpdrake.afficher());

                      ui->table_chant->setModel(tmpdrake.trierID());



                  }

              else
              {
                  QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                        QObject::tr("Erreur !.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
              }

        }


void zingeeer::on_pushButton_6_clicked()

    {
        bool test = true;
              if (test)
                  {
                  ui->table_chant->setModel(tmpdrake.afficher());

                      ui->table_chant->setModel(tmpdrake.triernom());



                  }

              else
              {
                  QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                        QObject::tr("Erreur !.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
              }

        }


void zingeeer::on_pushButton_7_clicked()
{
    {
        bool test = true;
              if (test)
                  {
                  ui->table_chant->setModel(tmpdrake.afficher());

                      ui->table_chant->setModel(tmpdrake.trierprix());



                  }

              else
              {
                  QMessageBox::critical(nullptr, QObject::tr("trier client"),
                                        QObject::tr("Erreur !.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
              }

        }


}

void zingeeer::on_pushButton_8_clicked()
{
    ui->table_chant->setModel(tmpdrake.afficher());
            QString nom = ui->lineEdit_searchname->text();
           ui->table_chant->setModel(tmpdrake.cherchernom(nom));
}

void zingeeer::on_pushButton_9_clicked()
{
    ui->table_chant->setModel(tmpdrake.afficher());
QString typechant= ui->lineEdit_searchmusic->text();
ui->table_chant->setModel(tmpdrake.chercher(typechant));
}

void zingeeer::on_pushButton_10_clicked()
{
    ui->table_chant->setModel(tmpdrake.afficher());
            int prix=ui->lineEdit_searchprice->text().toInt();
           ui->table_chant->setModel(tmpdrake.chercherprix(prix));
}



