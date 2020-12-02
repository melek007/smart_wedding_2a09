#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "salle.h"
#include "theme.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tab_salle->setModel(tmpsalle.afficher());
ui->tab_theme->setModel(tmptheme.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{

    QString ID_salle= ui->lineEdit_id->text();
    int capacite = ui->lineEdit_capacite->text().toInt();
    QString adresse = ui->lineEdit_adresse->text();
    float prix = ui->lineEdit_prix->text().toInt();


  salle sle(ID_salle,capacite,adresse,prix);
  bool test=sle.ajouter();
  if(test)
{ui->tab_salle->setModel(tmpsalle.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une salle"),
                  QObject::tr("employee ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une salle"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
QString id_salle = ui->lineEdit_id_2->text();
bool test=tmpsalle.supprimer(id_salle);
if(test)
{ui->tab_salle->setModel(tmpsalle.afficher());//refresh
    /*ui->tableView->setModel(tmpsalle.afficher_salle_trier());*/
    QMessageBox::information(nullptr, QObject::tr("Supprimer une salle "),
                QObject::tr("salle supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un salle"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
void MainWindow::on_pb_modifier_clicked()
{

    QString ID_salle= ui->lineEdit_id_5->text();
    int capacite= ui->lineEdit_capacite_2->text().toInt();
    QString adresse = ui->lineEdit_adresse2->text();
    float prix = ui->lineEdit_prix2->text().toInt();

    salle sle(ID_salle,capacite,adresse,prix);
  bool test=sle.modifier(ID_salle);
  if(test)
{ui->tab_salle->setModel(tmpsalle.afficher());
/* ui->tableView->setModel(tmpsalle.afficher_salle_trier())*/;//refresh
QMessageBox::information(nullptr, QObject::tr("modifier une salle"),
                  QObject::tr("modifier ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier une salle"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pb_recherche_clicked()
{
    QString id_salle = ui->lineEdit_id_6->text();
    ui->tableView_2->setModel(tmpsalle.rechercher_salle(id_salle));
    }


void MainWindow::on_pushButton_2_clicked()
{
    ui->tab_salle->setModel(tmpsalle.afficher_salle_trier());

}
//theme
void MainWindow::on_pb_ajouter_2_clicked()
{
        int ID_theme = ui->lineEdit_id_3->text().toInt();
        QString concept= ui->lineEdit_concept->text();
        float prix = ui->lineEdit_prix3->text().toInt();


      theme t(ID_theme,concept,prix);
      bool test=t.ajouter();
      if(test)
    {ui->tab_theme->setModel(tmptheme.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un theme"),
                      QObject::tr("theme ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un theme"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);


    }

void MainWindow::on_pb_supprimer_2_clicked()
{
    int id = ui->lineEdit_id_4->text().toInt();
    bool test=tmptheme.supprimer(id);
    if(test)
    {ui->tab_theme->setModel(tmptheme.afficher());//refresh
        /*ui->tableView->setModel(tmptheme.afficher_trier());*/
        QMessageBox::information(nullptr, QObject::tr("Supprimer un theme"),
                    QObject::tr("theme supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un theme"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_modifier_2_clicked()
{
    int ID_theme = ui->lineEdit_id_8->text().toInt();
    QString concept= ui->lineEdit_concept_2->text();
    float prix = ui->lineEdit_prix4->text().toInt();

    theme t (ID_theme,concept,prix);
    bool test=t.modifier(ID_theme);
  if(test)
{ui->tab_theme->setModel(tmptheme.afficher());
/* ui->tableView->setModel(tmptheme.afficher_trier())*/;//refresh
QMessageBox::information(nullptr, QObject::tr("modifier un theme"),
                  QObject::tr("modifier ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un theme"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_recherche_2_clicked()
{
    int id= ui->lineEdit_id_7->text().toInt();
    ui->tableView_3->setModel(tmptheme.rechercher(id));
    ui->tab_theme->setModel(tmptheme.afficher());
}
