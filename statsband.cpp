#include "statsband.h"
#include "ui_statsband.h"
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

statsband::statsband(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statsband)
{
      ui->setupUi(this);
      QBarSet *set0 = new QBarSet("oriental");
      QBarSet *set1 = new QBarSet("orchestra");
      QBarSet *set2 = new QBarSet("symphonic");
      QBarSet *set3 = new QBarSet("jazz");
       QBarSet *set4 = new QBarSet("classique");
        QBarSet *set5 = new QBarSet("variété");

      *set0 <<  E.calculerm("oriental") << 0 << 0 << 0 << 0 << 0;
      *set1 << 0 << E.calculerm("orchestra") << 0 << 0 << 0 << 0;
      *set2 << 0 << 0 << E.calculerm("symphonic") << 0 << 0 << 0;
      *set3 << 0 << 0 << 0 << E.calculerm("jazz") << 0 << 0;
      *set4 << 0 << 0 << 0 << 0 << E.calculerm("calssique") << 0;
      *set5 << 0 << 0 << 0 << 0 << 0 << E.calculerm("variété");
      QBarSeries *series = new QBarSeries();
      series->append(set0);
      series->append(set1);
      series->append(set2);
      series->append(set3);
      series->append(set4);
      series->append(set5);

      QChart *chart = new QChart();
      chart->addSeries(series);
      chart->setTitle("Simple barchart example");
      chart->setAnimationOptions(QChart::SeriesAnimations);

      QStringList categories;
      categories << "oriental"
                 << "orchestra"
                 << "symphonic"
                 << "jazz"
                 << "calssique"
                 << "variété" ;

      QBarCategoryAxis *axis = new QBarCategoryAxis();
      axis->append(categories);
      chart->createDefaultAxes();
      chart->setAxisX(axis, series);

      chart->legend()->setVisible(true);
      chart->legend()->setAlignment(Qt::AlignBottom);

      QChartView *chartview = new QChartView(chart);
      chartview->setRenderHint(QPainter::Antialiasing);
      QGridLayout *mainLayout = new QGridLayout;
      mainLayout->addWidget(chartview, 1, 1);
      setLayout(mainLayout);
}

statsband::~statsband()
{
    delete ui;

}
