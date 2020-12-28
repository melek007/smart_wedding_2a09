#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPrinter>
#include "mainwindow.h"
#include <QPrintDialog>
#include <QPainter>
#include "salle.h"
#include <QMessageBox>
#include <QColor>
#include <QPalette>
#include <QSqlQuery>
#include <QMessageBox>
#include <QTableWidget>
#include <QPixmap>
#include "theme.h"
#include "rates.h"

MainWindow::MainWindow(QWidget *parent):
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_btn_supprimer_clicked()
{
    QSqlQuery query;

        int id = ui->id_a_supprimer->text().toInt();

        query.prepare("delete from salle where id=:id");
        query.bindValue(":id", id);
        bool v =query.exec();
        if(v)
        {ui->tab_salle->setModel(tmpsalle.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("Supprimer une salle"),
                        QObject::tr("Salle supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer une salle"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_btn_modifier_clicked()
{
    int id=ui->ex_id->text().toInt();

        QString adresse= ui->nv_adresse->text();
        int capacite= ui->nv_capacite->text().toInt();
        int prix= ui->nv_prix->text().toInt();


       Salle p(id,adresse,capacite,prix);
      bool test=p.modifier(id,adresse,capacite,prix);
      if(test)
    {
          ui->tab_salle->setModel(tmpsalle.afficher());
    QMessageBox::information(nullptr, QObject::tr("Modifier une Salle"),
                      QObject::tr("Salle modifiée.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier une Salle"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_refresh_clicked()
{
     ui->tab_salle->setModel(tmpsalle.afficher());
}



void MainWindow::on_btn_nom_trier_clicked()
{
     ui->tab_salle->setModel(tmpsalle.trier());
}

void MainWindow::on_btn_id_trier_clicked()
{
   ui->tab_salle->setModel(tmpsalle.trier1());
}

void MainWindow::on_btn_pdf_clicked()
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
              double xscale = double(ui->tab_salle->width() / 65);
              double yscale = double(ui->tab_salle->height() / 65);
              painter.scale(xscale, yscale);
              ui->tab_salle->render(&painter);
              painter.end();
          }
          else
          {
              qWarning("failed to open file");
             QMessageBox::warning(nullptr,QObject::tr("PDF echoue"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
          }
       }
}

void MainWindow::on_btn_chercher_clicked()
{  QString nomsalle = ui->id_a_chercher->text();
    if(tmpsalle.verifierExnoms(nomsalle)==false)
    {QMessageBox::warning(this,"ERREUR","Salle n'existe pas");}
    else
    ui->tab_salle->setModel(tmpsalle.recherche_nom(nomsalle));
}

void MainWindow::on_btn_ajouter_clicked()
{

    int id=ui->id->text().toInt();
    QString adresse= ui->adresse->text();
    int capacite = ui->capacite->text().toInt();
    int prix = ui->prix->text().toInt();

  Salle p(id,adresse,capacite,prix);
  bool test=p.ajouter();
  if(test)
{ui->tab_salle->setModel(tmpsalle.afficher()); //refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une Salle"),
                  QObject::tr("Salle ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une Salle"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_btn_refresh_clicked()
{
    ui->tab_salle->setModel(tmpsalle.afficher());
}

void MainWindow::on_btn_ajouter_th_clicked()
{
    int id=ui->id_th->text().toInt();
    QString concept= ui->concept_th->text();
    int prix = ui->prix_th->text().toInt();


  theme p(id,concept,prix);
  bool test=p.ajouter();
  if(test)
{ui->tab_theme->setModel(tmptheme.afficher()); //refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un theme"),
                  QObject::tr("Theme ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un theme"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_btn_modifier_th_clicked()
{
    int id=ui->ex_id_th->text().toInt();

        QString concept= ui->nv_adresse_th->text();
        int prix= ui->nv_prix_th->text().toInt();



       theme p(id,concept,prix);
      bool test=p.modifier(id,concept,prix);
      if(test)
    {
          ui->tab_theme->setModel(tmptheme.afficher());
    QMessageBox::information(nullptr, QObject::tr("Modifier un theme"),
                      QObject::tr("Theme modifiée.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier un theme"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_btn_supprimer_th_clicked()
{
    QSqlQuery query;

        int id = ui->id_a_supprimer_th->text().toInt();

        query.prepare("delete from theme where id=:id");
        query.bindValue(":id", id);
        bool v =query.exec();
        if(v)
        {ui->tab_theme->setModel(tmptheme.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("Supprimer un theme"),
                        QObject::tr("theme supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un theme"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}






void MainWindow::on_btn_pdf_th_clicked()
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
              double xscale = double(ui->tab_theme->width() / 65);
              double yscale = double(ui->tab_theme->height() / 65);
              painter.scale(xscale, yscale);
              ui->tab_theme->render(&painter);
              painter.end();
          }
          else
          {
              qWarning("failed to open file");
             QMessageBox::warning(nullptr,QObject::tr("PDF echoue"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
          }
       }
}

void MainWindow::on_btn_chercher_th_clicked()
{
       QString concept = ui->id_a_chercher_2->text();
       if(tmptheme.verifierExnoms(concept)==false)
       {QMessageBox::warning(this,"ERREUR","Theme n'existe pas");}
       else
       ui->tab_theme->setModel(tmptheme.recherche_nom(concept));

}





void MainWindow::on_btn_tri_id_clicked()
{
    ui->tab_theme->setModel(tmptheme.trier());

}

void MainWindow::on_btn_tri_nom_clicked()
{
    ui->tab_salle->setModel(tmpsalle.trier());

}
