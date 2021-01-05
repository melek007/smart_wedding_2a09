#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>

#include<QPropertyAnimation>
#include<QSequentialAnimationGroup>
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
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
    void readSerial();
    void updateTemperature(QString);



private:
    Ui::MainWindow *ui;
     QPropertyAnimation *animation;
     QPropertyAnimation *animation1;
     QSerialPort *arduino;
     static const quint16 arduino_uno_vendor_id = 9025;
     static const quint16 arduino_uno_product_id = 67;
     QByteArray serialData;
     QString serialBuffer;
     QString parsed_data;
     double temperature_value;
};

#endif // MAINWINDOW_H
