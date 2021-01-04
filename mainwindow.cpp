#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"voiture.h"
#include"honeymoonplus.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

        animation= new QPropertyAnimation(ui->pushButton, "geometry");
        animation->setDuration(20000);
        animation->setLoopCount(-1);
        animation->setStartValue(QRect(-100, 10, 371, 150));/*(QRect(-400, 10, 371, 71));*/
        animation->setEndValue(QRect(700, 10, 371, 150));
        animation->start();
            animation = new QPropertyAnimation(ui->pushButton_2, "geometry");
            animation->setDuration(20000);
            animation->setLoopCount(-1);
            animation->setStartValue(QRect(-100, 10, 371, 71));/*(QRect(-400, 10, 371, 71));*/
            animation->setEndValue(QRect(700, 10, 371, 71));
            animation->start();
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{ voiture z;
    z.show();
    z.exec();
}


void MainWindow::on_pushButton_clicked()
{ honeymoonplus b;
    b.show();
    b.exec();


}
