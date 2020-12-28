#include "gesttheme.h"
#include "ui_gesttheme.h"

gesttheme::gesttheme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gesttheme)
{
    ui->setupUi(this);
}

gesttheme::~gesttheme()
{
    delete ui;
}
