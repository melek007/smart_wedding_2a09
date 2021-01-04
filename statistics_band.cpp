#include "statistics_band.h"
#include "ui_statistics_band.h"

statistics_band::statistics_band(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistics_band)
{
    ui->setupUi(this);
}

statistics_band::~statistics_band()
{
    delete ui;
}
