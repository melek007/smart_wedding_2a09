#ifndef GESTTHEME_H
#define GESTTHEME_H

#include <QDialog>

namespace Ui {
class gesttheme;
}

class gesttheme : public QDialog
{
    Q_OBJECT

public:
    explicit gesttheme(QWidget *parent = nullptr);
    ~gesttheme();

private:
    Ui::gesttheme *ui;
};

#endif // GESTTHEME_H
