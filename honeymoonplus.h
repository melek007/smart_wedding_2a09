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


    void on_recherche_honeymoon_clicked();

    void on_tri_par_prix_clicked();

    void on_tri_par_lieu_clicked();

    void on_tri_par_id_clicked();

    void on_ajouter_honeymoon_clicked();

    void on_modifier1_clicked();

    void on_get_data_by_id_clicked();

    void on_reinitialisation_clicked();

    void on_supprimer_honeymoon_clicked();

private:
    Ui::honeymoonplus *ui;
    honeymoon tmphoneymoon;
};


#endif // HONEYMOON_H
