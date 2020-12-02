#include "admin_configurationW.h"
#include "ui_admin_configurationW.h"
#include "adminM.h"
#include "adminM.cpp"
#include <QMessageBox>
#include <QIntValidator>

admin_configuration::admin_configuration(QWidget *parent) :
    QDialog(parent)
    ,ui(new Ui::admin_configuration)
{
    ui->setupUi(this);
    ui->admin_table_2->setModel(tmpadmin_configuration.show());
}

admin_configuration::~admin_configuration()
{
    delete ui;
}



void admin_configuration::on_ceate_1_clicked()
{

        QString login=ui->lineEdit_ID_1->text();
            QString password=ui->lineEdit_password_1->text();
             int degree=ui->comboBox_degree_1->currentText().toInt();


             admin b(login,password,degree);
         bool test=b.add();
         QMessageBox msgBox;

         if(test)
           {  msgBox.setText("Ajout avec succes.");
             ui->admin_table_2->setModel(tmpadmin_configuration.show());

         }
         else
            { msgBox.setText("Echec d'ajout");
             msgBox.exec();
        }
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



void admin_configuration::on_update_3_clicked()
{

            QString login=ui->lineEdit_insert_ID_3->text();
              QString password=ui->lineEdit_change_password_3->text();
                int degree=ui->comboBox_degree_3->currentText().toInt();




            admin E1 (login,password,degree);
             bool test=E1.modify();
             if(test)
             {

                 QMessageBox::information(nullptr, QObject::tr("database is open"),
                             QObject::tr("modification reussite.\n""Click Cancel to exit."), QMessageBox::Ok);
    ui->admin_table_2->setModel(E1.show());
                 // qDebug()<<"Connection successful";
             }
             else

                 QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                             QObject::tr("echec de modification\n""Click Cancel to exit."), QMessageBox::Cancel);





}


void admin_configuration::on_delete_4_clicked()
{
    admin s;
    s.setlogin(ui->lineEdit_ID_4->text());
    bool test=s.erase(s.getlogin());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->admin_table_2->setModel(s.show());

    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
}




void admin_configuration::on_tridegree_clicked()

    {
        bool test = true;
              if (test)
                  {
                  ui->admin_table_2->setModel(tmpadmin_configuration.show());

                      ui->admin_table_2->setModel(tmpadmin_configuration.tridegree());



                  }

              else
              {
                  QMessageBox::critical(nullptr, QObject::tr("tridegree"),
                                        QObject::tr("Erreur !.\n"
                                                    "Click ok to exit."), QMessageBox::Cancel);
              }

        }





void admin_configuration::on_search_login_clicked()
{
    ui->admin_table_2->setModel(tmpadmin_configuration.show());
            QString login = ui->lineEdit_search->text();
           ui->admin_table_2->setModel(tmpadmin_configuration.searchlogin(login));
}





