#ifndef RESERVATIONM_H
#define RESERVATIONM_H
#include "bandM.h"
#include "singerM.h"
#include "reservation.h"
#include <QDialog>

namespace Ui {
class reservationM;
}

class reservationM : public QDialog
{
    Q_OBJECT

public:
    explicit reservationM(QWidget *parent = nullptr);
    ~reservationM();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::reservationM *ui;
    boudinar c1;
    drake c2;
    reservation cc;
    reservation tmpreservation;
};

#endif // RESERVATIONM_H
