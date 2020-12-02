#include "mainwindow.h"
#include "admin_configurationW.h"
#include "ui_admin_configurationW.h"
#include "vip_weddingW.h"
#include "ui_vip_weddingW.h"
#include "vip_weddingM.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QIntValidator>

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


void MainWindow::on_admin_manager_clicked()
{ admin_configuration z;
    z.show();
    z.exec();
}


void MainWindow::on_vip_wedding_manager_clicked()
{ vip_wedding b;
    b.show();



}
