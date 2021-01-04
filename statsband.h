#ifndef STATSBAND_H
#define STATSBAND_H
#include "bandM.h"
#include <QDialog>
#include <QGridLayout>
#include <QWidget>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QChartView>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLegend>
#include <QtCharts/QLineSeries>

#include <QDialog>
QT_CHARTS_USE_NAMESPACE
namespace Ui {
class statsband;
}

class statsband : public QDialog
{
    Q_OBJECT

public:
    explicit statsband(QWidget *parent = nullptr);
    ~statsband();

private:
    Ui::statsband *ui;
    boudinar E;
    stat s;
};

#endif // STATSBAND_H
