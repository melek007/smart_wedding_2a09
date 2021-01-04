#include "statistiques.h"
#include "ui_statistiques.h"

#include "singerM.h"
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

statistiques::statistiques(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistiques)
{
      ui->setupUi(this);
      QBarSet *set0 = new QBarSet("oriental");
      QBarSet *set1 = new QBarSet("house");
      QBarSet *set2 = new QBarSet("jazz");
      QBarSet *set3 = new QBarSet("salsa");
       QBarSet *set4 = new QBarSet("classique");
        QBarSet *set5 = new QBarSet("variété");

      *set0 <<  E.calculer("oriental") << 0 << 0 << 0 << 0 << 0;
      *set1 << 0 << E.calculer("house") << 0 << 0 << 0 << 0;
      *set2 << 0 << 0 << E.calculer("jazz") << 0 << 0 << 0;
      *set3 << 0 << 0 << 0 << E.calculer("salsa") << 0 << 0;
      *set4 << 0 << 0 << 0 << 0 << E.calculer("calssique") << 0;
      *set5 << 0 << 0 << 0 << 0 << 0 << E.calculer("variété");
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
                 << "house"
                 << "jazz"
                 << "salsa"
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

statistiques::~statistiques()
{
    delete ui;

}
