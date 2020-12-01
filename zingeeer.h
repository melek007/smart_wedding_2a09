#ifndef ZINGEEER_H
#define ZINGEEER_H
#include"singerM.h"
#include <QDialog>

namespace Ui {
class zingeeer;
}

class zingeeer : public QDialog
{
    Q_OBJECT

public:
    explicit zingeeer(QWidget *parent = nullptr);
    ~zingeeer();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::zingeeer *ui;
    drake tmpdrake;
};

#endif // ZINGEEER_H
