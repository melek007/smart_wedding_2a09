#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "traiteur.h"
#include "cameraman.h"
#include <iostream>
#include <QMessageBox>
#include  <QDebug>
#include <QRadioButton>
#include<QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include <QPainter>
#include<QFileDialog>
#include<QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include<QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QVector>
#include <QSqlQuery>
#include<QDesktopServices>
#include <QMessageBox>
#include<QUrl>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>
#include <QPrintDialog>
#include<QtSql/QSqlQuery>
#include<QVariant>
#include"arduino.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_Ok_Ajoutsalle_clicked()
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
    if(test)
           {
        ui->tab_salle->setModel(t.afficher());

               QMessageBox::information(nullptr, QObject::tr("database is open"),
                           QObject::tr("ajout avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);

               // qDebug()<<"Connection successful";
           }
           else

               QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                           QObject::tr("echec d ajout\n""Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_supprimer1_clicked()
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

void MainWindow::on_Ok_Ajouttheme_clicked()
{
    int id=ui->le_id_theme->text().toInt();
    QString nom=ui->le_nom_dec->text();
    QString theme=ui->le_nom_theme->text();
    QString adrese=ui->le_adresse_dec->text();
    int prix=ui->le_prix_theme->text().toInt();
    cameraman c(id,nom,theme,adrese,prix);
    QMessageBox msg;
    bool test=c.ajoutert();
    if(test)
    {
        ui->tab_theme->setModel(c.affichert());
   /*msg.setText("Ajout avec succes");

    }
    else
      msg.setText("Echec de l'Ajout");
    msg.exec();*/
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("ajout avec succes.\n""Click Cancel to exit."), QMessageBox::Ok);

        // qDebug()<<"Connection successful";
    }
    else

        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("echec d ajout\n""Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimertheme_clicked()
{
    cameraman c; c.setid(ui->le_supp_theme->text().toInt());
     bool test =c.supprimert(c.getid());
     QMessageBox msgBox;
     if(test)

         {
           msgBox.setText("suppression avec succes.");
           ui->tab_theme->setModel(c.affichert());
         }
         else
          msgBox.setText("Echec de suppression.");
     msgBox.exec();

}

void MainWindow::on_Modifier_Modifiersalle_clicked()
{
        int id_tr=ui->lineEdit_idmodifiersalle->text().toInt();
        QString nom_tr=ui->lineEdit_nommodifiersalle->text();
        QString adresse_tr = ui->lineEdit_adressemodifiersalle->text();
        int prix_tr = ui->lineEdit_prixmodifiersalle->text().toInt();
       traiteur t(id_tr,nom_tr,adresse_tr,prix_tr);
       QMessageBox msg;
       bool test=t.modifier(id_tr,nom_tr,adresse_tr,prix_tr);

       if(test)
       {
           ui->lineEdit_idmodifiersalle->clear();
           ui->lineEdit_nommodifiersalle->clear();
           ui->lineEdit_adressemodifiersalle->clear();
           ui->lineEdit_prixmodifiersalle->clear();
           ui->tab_salle->setModel(t.afficher());

           msg.setText("modifiction avec succes");


       }

           else {
           msg.setText("Echec au niveau de la modification d un traiteur");
       }
       msg.exec();
}

void MainWindow::on_Modifier_Modifiertheme_clicked()
{
        int id=ui->lineEdit_idmodifiersalle_2->text().toInt();
        QString nom=ui->lineEdit_nommodifiertheme->text();
        QString theme=ui->lineEdit_nom2modifiertheme->text();
        QString adrese = ui->lineEdit_prixmodifiertheme_2->text();
        int prix = ui->lineEdit_prixmodifiertheme->text().toInt();
       cameraman c(id,nom,theme,adrese,prix);
       QMessageBox msg;
       bool test=c.modifiert(id,nom,theme,adrese,prix);

       if(test)
       {
           ui->lineEdit_idmodifiersalle_2->clear();
           ui->lineEdit_nommodifiertheme->clear();
           ui->lineEdit_nom2modifiertheme->clear();
           ui->lineEdit_prixmodifiertheme_2->clear();
           ui->lineEdit_prixmodifiertheme->clear();
           ui->tab_theme->setModel(c.affichert());
           msg.setText("modifiction avec succes");
       }

           else {
           msg.setText("Echec au niveau de la modification d un cameraman");
       }
       msg.exec();

}

void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox msgBox ;

            QSqlQueryModel *model = new QSqlQueryModel();
                     model->setQuery("SELECT * FROM TRAITEUR order by id_tr ASC");
                     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_tr"));
                     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_tr"));
                     model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse_tr"));
                     model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix_tr"));

                     ui->tab_salle->setModel(model);
                     ui->tab_salle->show();
                     msgBox.setText("Tri avec succès.");
                     msgBox.exec();
}





void MainWindow::on_pushButton_6_clicked()
{
    QMessageBox msgBox ;

            QSqlQueryModel *model = new QSqlQueryModel();
                     model->setQuery("SELECT * FROM cameraman order by id ASC");
                     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
                     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
                     model->setHeaderData(2, Qt::Horizontal, QObject::tr("theme"));
                     model->setHeaderData(3, Qt::Horizontal, QObject::tr("adrese"));
                     model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));

                     ui->tab_theme->setModel(model);
                     ui->tab_theme->show();
                     msgBox.setText("Tri avec succès.");
                     msgBox.exec();
}


void MainWindow::on_pushButton_clicked()
{
    bool test;
      traiteur t;
          int id_tr=0;
          QString nom_tr=ui->lineEdit->text();
          QString adresse_tr=ui->lineEdit->text();
          QString choix=ui->comboBox->currentText();
      if(choix=="id_tr")
      {
          id_tr= nom_tr.toInt();
          test=t.rechercher(id_tr,nom_tr,adresse_tr);
      }
      if(choix=="nom_tr")
      {

         test=t.rechercher(id_tr,nom_tr,adresse_tr);
      }
      if(choix=="adresse_tr")
      {

          test=t.rechercher(id_tr,nom_tr,adresse_tr);
      }
   if(test)
   {
   ui->tab_salle->setModel(t.afficher());
   }
}


void MainWindow::on_pushButton_3_clicked()
{
    bool test;
      cameraman c;
          int id=0;
          QString nom=ui->lineEdit_2->text();
          QString adrese=ui->lineEdit_2->text();
          QString choix=ui->comboBox_2->currentText();
      if(choix=="id")
      {
          id= nom.toInt();
          test=c.recherchert(id,nom,adrese);
      }
      if(choix=="nom")
      {

         test=c.recherchert(id,nom,adrese);
      }
      if(choix=="adrese")
      {

          test=c.recherchert(id,nom,adrese);
      }
   if(test)
   {
   ui->tab_theme->setModel(c.affichert());
   }
}


void MainWindow::on_pdf_tr_clicked()
{
    QString strStream;
                      QTextStream out(&strStream);

                      const int rowCount = ui->tab_salle->model()->rowCount();
                      const int columnCount = ui->tab_salle->model()->columnCount();

                      out <<  "<html>\n"
                          "<head>\n"
                          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                          <<  QString("<title>%1</title>\n").arg("strTitle")
                          <<  "</head>\n"
                          "<body bgcolor=#ffffff link=#5000A0>\n"

                         //     "<align='right'> " << datefich << "</align>"
                          "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                      // headers
                      out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                      for (int column = 0; column < columnCount; column++)
                          if (!ui->tab_salle->isColumnHidden(column))
                              out << QString("<th>%1</th>").arg(ui->tab_salle->model()->headerData(column, Qt::Horizontal).toString());
                      out << "</tr></thead>\n";

                      // data table
                      for (int row = 0; row < rowCount; row++) {
                          out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                          for (int column = 0; column < columnCount; column++) {
                              if (!ui->tab_salle->isColumnHidden(column)) {
                                  QString data = ui->tab_salle->model()->data(ui->tab_salle->model()->index(row, column)).toString().simplified();
                                  out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                              }
                          }
                          out << "</tr>\n";
                      }
                      out <<  "</table> </center>\n"
                          "</body>\n"
                          "</html>\n";

                QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                  if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                 QPrinter printer (QPrinter::PrinterResolution);
                  printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setPaperSize(QPrinter::A4);
                printer.setOutputFileName(fileName);

                 QTextDocument doc;
                  doc.setHtml(strStream);
                  doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                  doc.print(&printer);
}

void MainWindow::on_imp_tr_clicked()
{
    //imprimer

           QPrinter printer;

           printer.setPrinterName("desiered printer name");

         QPrintDialog dialog(&printer,this);

           if(dialog.exec()== QDialog::Rejected)

               return;
}

void MainWindow::on_imp_ca_clicked()
{
    //imprimer

           QPrinter printer;

           printer.setPrinterName("desiered printer name");

         QPrintDialog dialog(&printer,this);

           if(dialog.exec()== QDialog::Rejected)

               return;
}


void MainWindow::on_pdf_ca_clicked()
{
    QString strStream;
                      QTextStream out(&strStream);

                      const int rowCount = ui->tab_theme->model()->rowCount();
                      const int columnCount = ui->tab_theme->model()->columnCount();

                      out <<  "<html>\n"
                          "<head>\n"
                          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                          <<  QString("<title>%1</title>\n").arg("strTitle")
                          <<  "</head>\n"
                          "<body bgcolor=#ffffff link=#5000A0>\n"

                         //     "<align='right'> " << datefich << "</align>"
                          "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                      // headers
                      out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                      for (int column = 0; column < columnCount; column++)
                          if (!ui->tab_theme->isColumnHidden(column))
                              out << QString("<th>%1</th>").arg(ui->tab_theme->model()->headerData(column, Qt::Horizontal).toString());
                      out << "</tr></thead>\n";

                      // data table
                      for (int row = 0; row < rowCount; row++) {
                          out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                          for (int column = 0; column < columnCount; column++) {
                              if (!ui->tab_theme->isColumnHidden(column)) {
                                  QString data = ui->tab_theme->model()->data(ui->tab_theme->model()->index(row, column)).toString().simplified();
                                  out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                              }
                          }
                          out << "</tr>\n";
                      }
                      out <<  "</table> </center>\n"
                          "</body>\n"
                          "</html>\n";

                QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                  if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                 QPrinter printer (QPrinter::PrinterResolution);
                  printer.setOutputFormat(QPrinter::PdfFormat);
                 printer.setPaperSize(QPrinter::A4);
                printer.setOutputFileName(fileName);

                 QTextDocument doc;
                  doc.setHtml(strStream);
                  doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                  doc.print(&printer);
}
