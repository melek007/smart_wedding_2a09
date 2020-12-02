#include "loginW.h"
#include "ui_loginW.h"
#include "adminM.h"


login::login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::login)
{
}

login::~login()
{
    delete ui;
}
void on_connect_clicked()
{

}
