#include "adminM.h"
#include "vip_weddingM.h"
#include "admin_configurationW.h"
#include "vip_weddingW.h"
#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connection_db.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    base_connection c;
    bool test=c.openConnection();
    MainWindow f;
         if(test)
         {
             f.show();
         }
         else

             QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                         QObject::tr("connection failed.\n""Click Cancel to exit."), QMessageBox::Cancel);

    return a.exec();

}

