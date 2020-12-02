#ifndef admin_CONFIGURATION_H
#define admin_CONFIGURATION_H
#include "adminM.h"
#include "ui_admin_configurationW.h"
#include <QDialog>
#include "connection_db.h"


namespace Ui {
class admin_configuration;
}

class admin_configuration : public QDialog
{
    Q_OBJECT

public:

    explicit admin_configuration(QWidget *parent = nullptr);
    ~admin_configuration();

private:
    void on_ceate_1_clicked();

    void on_update_3_clicked();

    void on_delete_4_clicked();

    void on_tridegree_clicked();

    void on_search_login_clicked();




    Ui::admin_configuration*ui;
    admin tmpadmin_configuration;
};

#endif // admin_CONFIGURATION_H
