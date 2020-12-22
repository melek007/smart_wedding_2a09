#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"voiture.h"
#include"honeymoonplus.h"

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
