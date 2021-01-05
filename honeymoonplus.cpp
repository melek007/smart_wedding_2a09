#include "honeymoonplus.h"
#include "ui_honeymoonplus.h"
#include"honeymoon.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QMediaPlayer>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>

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

void honeymoonplus::on_ajouter_honeymoon_clicked()
{QMessageBox msgBox;
    QMediaPlayer * music =new QMediaPlayer;
     music->setMedia(QUrl("qrc:/Aniss/clic/clic.mp3")) ;
     music->play();

        int id=ui->lineEdit_ID0->text().toInt();
            QString lieu=ui->lineEdit_lieu1->text();
            int prix=ui->lineEdit_prix1->text().toInt();
             QString nom_hotel=ui->lineEdit_nomhotel_2->text();

             honeymoon v;
              if(v.checkExisteHoneymoon(ui->lineEdit_ID0->text()))
                {  msgBox.setText("honeymoon existe deja");
                   msgBox.exec();
                   return;
              }

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





void honeymoonplus::on_modifier1_clicked()
{ QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/Aniss/clic/clic.mp3")) ;
    music->play();

            int ID=ui->id_edit_supp->text().toInt();
            QString lieu=ui->lieu_edit_supp->text();

                int prix=ui->prix_edit_supp->text().toInt();
               QString nom_hotel=ui->nom_hotel_edit_supp->text();




            honeymoon H1 (ID,lieu ,prix,nom_hotel);
             bool updated=H1.modifier();
             if(updated)
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


void honeymoonplus::on_get_data_by_id_clicked()
{
    { QMediaPlayer * music =new QMediaPlayer;
        music->setMedia(QUrl("qrc:/Aniss/clic/clic.mp3")) ;
        music->play();
        QMessageBox msgBox;
        honeymoon E1;
        QString honey = ui->id_edit_supp->text();
        if(honey == NULL){
            msgBox.setText("S'il vous plait saisir une ID");
            msgBox.exec();
            return;
        }
       honeymoon  honeymoonExiste = E1.findByID(honey);
       if(honeymoonExiste.getID() == NULL){
           msgBox.setText("honeymoon n'existe pas");
           msgBox.exec();
           return;
       }
       ui->nom_hotel_edit_supp->setText(honeymoonExiste.getnom_hotel());
       ui->lieu_edit_supp->setText(honeymoonExiste.getlieu());
       ui->prix_edit_supp->setText(QString::number(honeymoonExiste.getprix()));
    }
}

void honeymoonplus::on_reinitialisation_clicked()
{ QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/Aniss/clic/clic.mp3")) ;
    music->play();
    ui->lineEdit_ID0->setText("");
    ui->lineEdit_lieu1->setText("");
    ui->lineEdit_nomhotel_2->setText("");
    ui->lineEdit_prix1->setText("");
}

void honeymoonplus::on_supprimer_honeymoon_clicked()
{ QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/Aniss/clic/clic.mp3")) ;
    music->play();

    QMessageBox msgBox;
    honeymoon E1;
    QString carte = ui->id_edit_supp->text();
    if(carte == NULL){
        msgBox.setText("S'il vous plait saisir une carte grise");
        msgBox.exec();
        return;
    }
   honeymoon  honeymoonExiste = E1.findByID(carte);
   if(honeymoonExiste.getID() == NULL){
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

void honeymoonplus::on_tri_par_id_clicked()
{ QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();

    QString requete = createRequete();
    requete+= " order by ID ASC";
        execute(requete);
}

void honeymoonplus::on_tri_par_lieu_clicked()
{
    QMediaPlayer * music =new QMediaPlayer;
     music->setMedia(QUrl("qrc:/Aniss/clic/clic.mp3")) ;
     music->play();
    QString requete = createRequete();
    requete+= " order by lieu ASC";
        execute(requete);
}

void honeymoonplus::on_tri_par_prix_clicked()
{ QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/Aniss/clic/clic.mp3")) ;
    music->play();

    QString requete = createRequete();
    requete+= " order by prix ASC";
        execute(requete);
}
void honeymoonplus::on_recherche_honeymoon_clicked()
{ QMediaPlayer * music =new QMediaPlayer;
    music->setMedia(QUrl("qrc:/sounds/wave.mp3")) ;
    music->play();
QString requete = createRequete();
execute(requete);
}
QString honeymoonplus::createRequete(){

    QString requete="SELECT ID,lieu,prix,nom_hotel FROM honeymoon";
    QString critaire = "";
        QString ID=ui->recherche_par_id->text();
        QString lieu=ui->recherche_par_lieu->text();
        QString prix=ui->recherche_par_prix->text();
        if(ID != NULL or lieu != NULL or prix !=NULL){
            critaire = " where ";
        }
        if(ID != NULL){
            critaire += " id="+ID;
        }
        if(lieu != NULL){
            if(critaire != " where ")
                critaire+= " and ";
            critaire += " lieu='"+lieu+"'";
        }
        if(prix != NULL){
            if(critaire != " where ")
                critaire+= " and ";
            critaire += " prix="+prix;
        }
requete+=critaire;
return requete;
}


void honeymoonplus::execute(QString requete){
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(requete);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Lieu"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom hotel"));
    ui->table_honeymoon->setModel(model);
    ui->table_honeymoon->show();
}

void honeymoonplus::on_refresh_honeymoon_clicked()
{
    QString requete = createRequete();
    execute(requete);

}


void honeymoonplus::on_imprimer_honeymoon_clicked()
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
              double xscale = double(ui->table_honeymoon->width() / 65);
              double yscale = double(ui->table_honeymoon->height() / 65);
              painter.scale(xscale, yscale);
              ui->table_honeymoon->render(&painter);
              painter.end();
          }
          else
          {
              qWarning("failed to open file");
             QMessageBox::warning(nullptr,QObject::tr("Erreur de generation PDF"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
          }
       }
}