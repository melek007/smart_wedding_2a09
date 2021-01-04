#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"zingeeer.h"
#include"the_band.h"
#include <QPixmap>
#include <QPixelFormat>
#include <qpixmap.h>
#include "reservationm.h"
#include "compte.h"
#include "connexion_base.h"
#include "QMessageBox"
#include <QMediaPlayer>

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







void MainWindow::on_pushButton_clicked()
{ the_band b;
    b.show();
    b.exec();


}



void MainWindow::on_pushButton_login_clicked()
{



    //extract userId and password

    QString given_password= ui->lineEdit_mdp->text();
  QString user= ui->lineEdit_login->text();


    //check if userid is a number
    bool num ;
    int a=given_password.toInt(&num,10);
    a++;

    //check if user is in default list
    QString users="adminRH adminCL"; // you add your ID in format admin(first 2 letters of your departement name)
    bool user_ex = users.contains(user);

    //check if password is in default list
    QString password ="ADM-RH ADM-CL"; // you add your password in format ADM-(first 2 letters of your departement name)
    bool pass_ex = password.contains(given_password);


QSqlQuery qry;
 int count=0;
if(qry.exec( "select * from compte where login='"+user+"'and mot_de_passe='"+given_password+"'" ))
{

    while(qry.next()) {

        count++;
    }

if (count<1)

QMessageBox::information(nullptr, QObject::tr("database is open"),
            QObject::tr("wrong password or login.\n""Click Cancel to exit."), QMessageBox::Ok);
}
if(count==1 || (user_ex && pass_ex)){

    QMessageBox::information(nullptr, QObject::tr("database is open"),
                QObject::tr("correct password.\n""Click Cancel to exit."), QMessageBox::Ok);
    QMediaPlayer * music =new QMediaPlayer;
     music->setMedia(QUrl("qrc:/sounds/welcome.mp3")) ;
     music->play();
the_band *ws;
ws = new the_band(nullptr);
ws->setWindowTitle("Smart wedding");
ws->show();
}









}



