#include "mainwindow.h"

#include <QApplication>
#include <QtCharts>

#include "chart.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QLineSeries *series = new QLineSeries();/*
    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);*/

    for (int i=0; i<101; ++i)
    {
        auto x = i/50.0 - 1; // x goes from -1 to 1
        auto y = x * x; // let's plot a quadratic function
        series->append(x, y);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Simple Line Chart");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(800, 600);
    chartView->show();

    Chart *chart1 = new Chart;
    chart1->setTitle("Dynamic spline chart");
    chart1->legend()->hide();
    chart1->setAnimationOptions(QChart::AllAnimations);
    QChartView chartView2(chart1);
    chartView2.setRenderHint(QPainter::Antialiasing);
    chartView2.show();

    return a.exec();
}
