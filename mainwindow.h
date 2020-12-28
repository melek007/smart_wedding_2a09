#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "salle.h"
#include <QMainWindow>
#include "theme.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_ajouter_salle_clicked();

    void on_btn_supprimer_clicked();

    void on_btn_modifier_clicked();

    void on_refresh_clicked();

    void on_refresh_3_clicked();

    void on_btn_nom_trier_clicked();

    void on_btn_id_trier_clicked();

    void on_btn_pdf_clicked();

    void on_btn_chercher_clicked();

    void on_btn_ajouter_clicked();

    void on_btn_tri_nom_clicked();

    void on_btn_tri_id_clicked();

    void on_btn_refresh_clicked();

    void on_btn_ajouter_th_clicked();

    void on_btn_modifier_th_clicked();

    void on_btn_supprimer_th_clicked();

    void on_btn_refresh_th_clicked();

    void on_btn_tri_concept_clicked();

    void on_btn_tri_id_th_clicked();

    void on_btn_pdf_th_clicked();

    void on_btn_chercher_th_clicked();

    void on_btn_rate_clicked();

private:
    Ui::MainWindow *ui;
     Salle tmpsalle;
     theme tmptheme;
};
#endif // MAINWINDOW_H
