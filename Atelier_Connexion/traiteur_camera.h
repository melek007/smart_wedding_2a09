#ifndef TRAITEUR_CAMERA_H
#define TRAITEUR_CAMERA_H

#include <QDialog>
#include "traiteur.h"
#include "cameraman.h"

namespace Ui {
class Traiteur_camera;
}

class Traiteur_camera : public QDialog
{
    Q_OBJECT

public:
    explicit Traiteur_camera(QWidget *parent = nullptr);
    ~Traiteur_camera();
/*
private slots:
    void on_Ok_Ajoutsalle_clicked();

    void on_pb_supprimer1_clicked();

    void on_Ok_Ajouttheme_clicked();

    void on_pb_supprimertheme_clicked();

    void on_Modifier_Modifiersalle_clicked();

    void on_Modifier_Modifiertheme_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Traiteur_camera *ui;
    traiteur t;
    cameraman c;
};*/

#endif // TRAITEUR_CAMERA_H
