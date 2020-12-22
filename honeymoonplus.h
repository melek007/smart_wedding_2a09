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

private:
    Ui::honeymoonplus *ui;
    honeymoon tmphoneymoon;
};


#endif // HONEYMOON_H
