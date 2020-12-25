
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

void voiture::on_Ajouter_voiture_clicked()

{QMessageBox msgBox;

    int CARTE_GRISE=ui->lineEdit_CARTE_GRISE->text().toInt();
        QString couleur=ui->lineEdit_couleur->text();
        QString marque=ui->lineEdit_marque->text();
         int prix=ui->lineEdit_prix->text().toInt();
         voitureplus v;
          if(v.checkExisteVoiture(ui->lineEdit_CARTE_GRISE->text()))
            {  msgBox.setText("Voiture existe deja");
               msgBox.exec();
               return;
          }

         voitureplus V(CARTE_GRISE,couleur,marque,prix);
     if(V.ajouter())
     {

         QMessageBox::information(nullptr, QObject::tr("database is open"),
                     QObject::tr("ajout avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);

         // qDebug()<<"Connection successful";
     }
     else

         QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                     QObject::tr("echec d ajout\n""Click Cancel to exit."), QMessageBox::Cancel);


}


void voiture::on_recherche_clicked()
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

void voiture::on_tri_par_cartegrise_clicked()
{

}

void voiture::on_tri_par_couleur_clicked()
{

}

void voiture::on_tri_par_marque_clicked()
{

}

void voiture::on_get_data_voiture_by_id_clicked()
{
    QMessageBox msgBox;
    voitureplus E1;
    QString carte = ui->carte_grise_edit_supp->text();
    if(carte == NULL){
        msgBox.setText("S'il vous plait saisir une carte grise");
        msgBox.exec();
        return;
    }
   voitureplus  voitureExiste = E1.findByCarteGrise(carte);
   if(voitureExiste.getCARTE_GRISE() == NULL){
       msgBox.setText("Voiture n'existe pas");
       msgBox.exec();
       return;
   }
   ui->edit_supp_input_color->setText(voitureExiste.getcouleur());
   ui->edit_supp_input_marque->setText(voitureExiste.getmarque());
   ui->edit_supp_input_prix->setText(QString::number(voitureExiste.getprix()));
}

void voiture::on_modifer_clicked()
{
    int CARTE_GRISE=ui->carte_grise_edit_supp->text().toInt();
    QString couleur=ui->edit_supp_input_color->text();
      QString marque=ui->edit_supp_input_marque->text();
     int prix= ui->edit_supp_input_prix->text().toInt();

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

void voiture::on_Supprimer_clicked()
{
    QMessageBox msgBox;
    voitureplus E1;
    QString carte = ui->carte_grise_edit_supp->text();
    if(carte == NULL){
        msgBox.setText("S'il vous plait saisir une carte grise");
        msgBox.exec();
        return;
    }
   voitureplus  voitureExiste = E1.findByCarteGrise(carte);
   if(voitureExiste.getCARTE_GRISE() == NULL){
       msgBox.setText("Voiture n'existe pas");
       msgBox.exec();
       return;
   }
    bool deleted=E1.supprimer(carte.toInt());
    if(deleted)
        msgBox.setText("Suppression avec succes.");
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}

void voiture::on_renitialisation_clicked()
{
    ui->lineEdit_CARTE_GRISE->setText("");
    ui->lineEdit_couleur->setText("");
    ui->lineEdit_marque->setText("");
    ui->lineEdit_prix->setText("");
}
