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

    void on_recherche_clicked();

    void on_tri_par_cartegrise_clicked();

    void on_tri_par_couleur_clicked();

    void on_tri_par_marque_clicked();

    void on_get_data_voiture_by_id_clicked();

    void on_modifer_clicked();

    void on_Supprimer_clicked();

    void on_Ajouter_voiture_clicked();

    void on_renitialisation_clicked();

private:
    Ui::voiture *ui;
    voitureplus tmpvoitureplus;
};

#endif // VOITURE_H
