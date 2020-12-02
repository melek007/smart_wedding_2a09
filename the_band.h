#ifndef THE_BAND_H
#define THE_BAND_H
#include"bandM.h"
#include <QDialog>

namespace Ui {
class the_band;
}

class the_band : public QDialog
{
    Q_OBJECT

public:
    explicit the_band(QWidget *parent = nullptr);
    ~the_band();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::the_band *ui;
    boudinar tmpboudinar;
};

#endif // THE_BAND_H
