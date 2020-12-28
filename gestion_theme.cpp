#include "gestion_theme.h"
#include "ui_gestion_theme.h"

gestion_theme::gestion_theme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_theme)
{
    ui->setupUi(this);
}

gestion_theme::~gestion_theme()
{
    delete ui;
}
