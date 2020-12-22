#include "honeymoonplus.h"
#include "ui_honeymoonplus.h"
#include"honeymoon.h"
#include <QMessageBox>
#include <QIntValidator>

honeymoonplus::honeymoonplus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::honeymoonplus)
{
    ui->setupUi(this);
    ui->table_honeymoon->setModel(tmphoneymoon.afficher());

}

honeymoonplus::~honeymoonplus()
{
    delete ui;
}

void honeymoonplus::on_pushButton_2_clicked()
{

        int id=ui->lineEdit_ID0->text().toInt();
            QString lieu=ui->lineEdit_lieu1->text();
            int prix=ui->lineEdit_prix1->text().toInt();
             QString nom_hotel=ui->lineEdit_nomhotel_2->text();



             honeymoon b(id,lieu,prix,nom_hotel);
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

             // qDebug()<<"Connection successful";
         }
         else

             QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                         QObject::tr("echec d ajout\n""Click Cancel to exit."), QMessageBox::Cancel);


    }



void honeymoonplus::on_pushButton_3_clicked()
{
    honeymoon s;
    s.setID(ui->LineEdit_key->text().toInt());
    bool test=s.supprimer(s.getID());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->table_honeymoon->setModel(s.afficher());

    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
}

void honeymoonplus::on_pushButton_4_clicked()
{

            int ID=ui->LineEdit_10->text().toInt();
            QString lieu=ui->LineEdit_blasa->text();

                int prix=ui->LineEdit_soum->text().toInt();
               QString nom_hotel=ui->lineEdit_esm->text();




            honeymoon H1 (ID,lieu ,prix,nom_hotel);
             bool test=H1.modifier();
             if(test)
             {

                 QMessageBox::information(nullptr, QObject::tr("database is open"),
                             QObject::tr("modification reussite.\n""Click Cancel to exit."), QMessageBox::Ok);
    ui->table_honeymoon->setModel(H1.afficher());
                 // qDebug()<<"Connection successful";
             }
             else

                 QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                             QObject::tr("echec de modification\n""Click Cancel to exit."), QMessageBox::Cancel);





}
