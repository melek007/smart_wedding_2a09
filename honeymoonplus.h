#ifndef HONEYMOONPLUS_H
#define HONEYMOONPLUS_H
#include"honeymoon.h"
#include <QDialog>

namespace Ui {
class honeymoonplus;
}

class honeymoonplus : public QDialog
{
    Q_OBJECT

public:
    explicit honeymoonplus(QWidget *parent = nullptr);
    ~honeymoonplus();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_recherche_honeymoon_clicked();

    void on_tri_par_prix_clicked();

    void on_tri_par_lieu_clicked();

    void on_tri_par_id_clicked();

private:
    Ui::honeymoonplus *ui;
    honeymoon tmphoneymoon;
};


#endif // HONEYMOON_H
