
#include "voiture.h"
#include "ui_voiture.h"
#include"voitureplus.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QMediaPlayer>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>

#include <QPalette>

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
    QMediaPlayer * music =new QMediaPlayer;
     music->setMedia(QUrl("qrc:/Aniss/clic/clic.mp3")) ;
     music->play();

    int CARTE_GRISE=ui->lineEdit_CARTE_GRISE->text().toInt();
        QString couleur=ui->lineEdit_couleur->text();
        QString marque=ui->lineEdit_marque->text();
         QString matricule=ui->lineEdit_matricule->text();
         int prix=ui->lineEdit_prix->text().toInt();
         voitureplus v;
          if(v.checkExisteVoiture(ui->lineEdit_CARTE_GRISE->text()))
            {  msgBox.setText("Voiture existe deja");
               msgBox.exec();
               return;
          }

         voitureplus V(CARTE_GRISE,couleur,marque,prix,matricule);
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
    QMediaPlayer * music =new QMediaPlayer;
     music->setMedia(QUrl("qrc:/Aniss/clic/clic.mp3")) ;
     music->play();
QString requete = createRequete();
execute(requete);
}

void voiture::on_tri_par_cartegrise_clicked()
{
    QMediaPlayer * music =new QMediaPlayer;
     music->setMedia(QUrl("qrc:/Aniss/clic/clic.mp3")) ;
     music->play();
QString requete = createRequete();
requete+= " order by carte_grise ASC";
execute(requete);
}

void voiture::on_tri_par_couleur_clicked()
{   QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/Aniss/clic/clic.mp3")) ;
    music->play();

QString requete = createRequete();
requete+= " order by couleur ASC";
    execute(requete);
}

void voiture::on_tri_par_marque_clicked()
{   QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/Aniss/clic/clic.mp3")) ;
    music->play();
QString requete = createRequete();
requete+= " order by marque ASC";
    execute(requete);
}

void voiture::on_get_data_voiture_by_id_clicked()
{   QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/Anisee/clic.mp3")) ;
    music->play();
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
   ui->edit_supp_input_matricule->setText(voitureExiste.getMatricule());
}

void voiture::on_modifer_clicked()
{   QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
    int CARTE_GRISE=ui->carte_grise_edit_supp->text().toInt();
    QString couleur=ui->edit_supp_input_color->text();
      QString marque=ui->edit_supp_input_marque->text();
     int prix= ui->edit_supp_input_prix->text().toInt();
      QString matricule=ui->edit_supp_input_matricule->text();

    voitureplus  V1 (CARTE_GRISE,couleur ,marque,prix,matricule);
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
{   QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/Aniss/clic/clic.mp3")) ;
    music->play();
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
{   QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/Aniss/clic/clic.mp3")) ;
    music->play();
    ui->lineEdit_CARTE_GRISE->setText("");
    ui->lineEdit_couleur->setText("");
    ui->lineEdit_marque->setText("");
    ui->lineEdit_prix->setText("");
     ui->lineEdit_matricule->setText("");
}

void voiture::execute(QString requete){
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(requete);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CARTE_GRISE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("matricule"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("couleur"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("marque"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));
    ui->table_voiture->setModel(model);
    ui->table_voiture->show();
}

QString voiture::createRequete(){

    QString requete="SELECT carte_grise,matricule,couleur,marque,prix FROM voiture";
    QString critaire = "";
        QString CARTE_GRISE=ui->recherche_par_cartegrise->text();
        QString couleur=ui->recherche_par_couleur->text();
        QString marque=ui->recherche_par_marque->text();
        if(CARTE_GRISE != NULL or couleur != NULL or marque !=NULL){
            critaire = " where ";
        }
        if(CARTE_GRISE != NULL){
            critaire += " carte_grise="+CARTE_GRISE;
        }
        if(couleur != NULL){
            if(critaire != " where ")
                critaire+= " and ";
            critaire += " couleur='"+couleur+"'";
        }
        if(marque != NULL){
            if(critaire != " where ")
                critaire+= " and ";
            critaire += " marque='"+marque+"'";
        }
requete+=critaire;
return requete;
}



void voiture::on_refresh_clicked()
{

    QString requete = createRequete();
    execute(requete);
    }

void voiture::on_imprimer_clicked()
{
    QPrinter *printer = new QPrinter(QPrinter::HighResolution);
           printer->setOutputFormat(QPrinter::NativeFormat);
           printer->setPageSize(QPrinter::A4);
           printer->setOrientation(QPrinter::Portrait);
           printer->setFullPage(true);


       QPrintDialog *printDialog = new QPrintDialog(printer,this);
       printDialog->setWindowTitle("Impression PDF");
       if(printDialog->exec())
       {
          QPainter painter;
          if(painter.begin(printer))
          {
              double xscale = double(ui->table_voiture->width() / 65);
              double yscale = double(ui->table_voiture->height() / 65);
              painter.scale(xscale, yscale);
              ui->table_voiture->render(&painter);
              painter.end();
          }
          else
          {
              qWarning("failed to open file");
             QMessageBox::warning(nullptr,QObject::tr("PDF echoue"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
          }
       }

}
