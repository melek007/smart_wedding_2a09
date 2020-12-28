#ifndef GESTION_THEME_H
#define GESTION_THEME_H

#include <QDialog>

namespace Ui {
class gestion_theme;
}

class gestion_theme : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_theme(QWidget *parent = nullptr);
    ~gestion_theme();

private:
    Ui::gestion_theme *ui;
};

#endif // GESTION_THEME_H
