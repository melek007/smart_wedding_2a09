#include "the_band.h"
#include "ui_the_band.h"
#include"boudinar.h"
#include <QMessageBox>
#include <QIntValidator>

the_band::the_band(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::the_band)
{
    ui->setupUi(this);
    ui->table_band->setModel(tmpboudinar.afficher());

}

the_band::~the_band()
{
    delete ui;
}

void the_band::on_pushButton_2_clicked()
{

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

             // qDebug()<<"Connection successful";
         }
         else

             QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                         QObject::tr("echec d ajout\n""Click Cancel to exit."), QMessageBox::Cancel);


    }



void the_band::on_pushButton_3_clicked()
{
    boudinar s;
    s.setID(ui->LineEdit_key1->text().toInt());
    bool test=s.supprimer(s.getID());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->table_band->setModel(s.afficher());

    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
}

void the_band::on_pushButton_4_clicked()
{

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
                 // qDebug()<<"Connection successful";
             }
             else

                 QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                             QObject::tr("echec de modification\n""Click Cancel to exit."), QMessageBox::Cancel);





}

