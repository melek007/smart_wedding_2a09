#ifndef VOITURE_H
#define VOITURE_H
#include <voitureplus.h>

#include <QDialog>

namespace Ui {
class voiture;
}

class voiture : public QDialog
{
    Q_OBJECT

public:
    explicit voiture(QWidget *parent = nullptr);
    ~voiture();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_recherche_clicked();

    void on_tri_par_cartegrise_clicked();

    void on_tri_par_couleur_clicked();

    void on_tri_par_marque_clicked();

    void on_get_data_voiture_by_id_clicked();

private:
    Ui::voiture *ui;
     voitureplus tmpvoitureplus;
};

#endif // VOITURE_H
