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

private:
    Ui::voiture *ui;
     voitureplus tmpvoitureplus;
};

#endif // VOITURE_H
