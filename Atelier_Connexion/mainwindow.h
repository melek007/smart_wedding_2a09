#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "traiteur.h"
#include "cameraman.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
private slots:
    void on_Ok_Ajoutsalle_clicked();

    void on_pb_supprimer1_clicked();

    void on_Ok_Ajouttheme_clicked();

    void on_pb_supprimertheme_clicked();

    void on_Modifier_Modifiersalle_clicked();

    void on_Modifier_Modifiertheme_clicked();

    void on_pushButton_5_clicked();


    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    traiteur t;
    cameraman c;
};


#endif // MAINWINDOW_H
