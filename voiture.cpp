
#include "voiture.h"
#include "ui_voiture.h"
#include"voitureplus.h"
#include <QMessageBox>
#include <QIntValidator>

voiture::voiture(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::voiture)
{
    ui->setupUi(this);
    ui->table_voiture->setModel(tmpvoitureplus.afficher());

}

voiture::~voiture()
{
    delete ui;
}


void voiture::on_pushButton_clicked()
{

    int CARTE_GRISE=ui->lineEdit_CARTE_GRISE->text().toInt();
        QString couleur=ui->lineEdit_couleur->text();
        QString marque=ui->lineEdit_marque->text();
         int prix=ui->lineEdit_prix->text().toInt();

         voitureplus V(CARTE_GRISE,couleur,marque,prix);
     bool test=V.ajouter();
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


void voiture::on_pushButton_3_clicked()
{

    voitureplus E1;
    E1.setCARTE_GRISE(ui->lineEdit_5->text().toInt());
    bool test=E1.supprimer(E1.getCARTE_GRISE());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->table_voiture->setModel(E1.afficher());

    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();

}


void voiture::on_pushButton_4_clicked()
{
        int CARTE_GRISE=ui->lineEdit->text().toInt();
        QString couleur=ui->lineEdit_2->text();
          QString marque=ui->lineEdit_3->text();
         int prix= ui->lineEdit_4->text().toInt();

        voitureplus  V1 (CARTE_GRISE,couleur ,marque,prix);
         bool test=V1.modifier();
         if(test)
         {

             QMessageBox::information(nullptr, QObject::tr("database is open"),
                         QObject::tr("modification avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);
         ui->table_voiture->setModel(V1.afficher());
             // qDebug()<<"Connection successful";
         }
         else

             QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                         QObject::tr("echec de modification\n""Click Cancel to exit."), QMessageBox::Cancel);




}

void voiture::on_pushButton_5_clicked()
{
    QMessageBox msgBox ;
            QSqlQueryModel *model = new QSqlQueryModel();
                     model->setQuery("SELECT * FROM voiture order by nom ASC");
                     model->setHeaderData(1, Qt::Horizontal, QObject::tr("CARTE_GRISE"));
                     model->setHeaderData(1, Qt::Horizontal, QObject::tr("couleur"));

                     model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
                     model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
                     ui->table_voiture->setModel(model);
                     ui->table_voiture->show();
                     msgBox.setText("Tri avec succès.");
                     msgBox.exec();
}

