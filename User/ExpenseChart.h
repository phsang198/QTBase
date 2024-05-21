#pragma once
#ifndef CHARTDIALOG_H
#define CHARTDIALOG_H

#include <QDialog>
#include <QVBoxLayout>

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QDate>
#include <QDateTimeAxis>

#include "src/object.h"
#include <memory>
// Class: ChartDialog
// Description: [To be used to show amount chart ].
// 
class ChartDialog : public QDialog {
public:
    ChartDialog(QWidget* parent, std::vector<std::shared_ptr<expense>> expenses, std::string type ) : QDialog(parent) {
        QVBoxLayout* layout = new QVBoxLayout(this);

        QChart* chart = new QChart();
        QDateTimeAxis* axisX = new QDateTimeAxis;

        axisX->setTickCount(10);
        axisX->setFormat("yyyy-MM-dd");
        axisX->setTitleText("Date");
        chart->addAxis(axisX, Qt::AlignBottom);

        QValueAxis* axisY = new QValueAxis;
        axisY->setLabelFormat("%d");
        axisY->setTitleText("Amount");
        chart->addAxis(axisY, Qt::AlignLeft);

        std::map<std::string, QLineSeries*> categorySeriesMap;

        if (type == "category")
        {
            std::string cat = "";
            for (const auto& _expense : expenses)
            {
                cat = _expense->category;
                if (categorySeriesMap.find(_expense->category) == categorySeriesMap.end())
                {
                    QLineSeries* series = new QLineSeries();
                    categorySeriesMap[_expense->category] = series;
                }

                QString line = _expense->date.c_str(); 
                QStringList values = line.split(QLatin1Char('-'), Qt::SkipEmptyParts);

                QDateTime momentInTime;
                momentInTime.setDate(QDate(values[0].toInt(), values[1].toInt(), values[2].toInt()));
                qint64 tmp = momentInTime.toMSecsSinceEpoch(); 
                categorySeriesMap[_expense->category]->append(tmp, _expense->amount);
                //categorySeriesMap[_expense->category]->append(QPointF(_expense->id, _expense->amount));
            }
            cat += " Expense Chart";
            chart->setTitle(cat.c_str());

        }
        else
        {
            std::string cat = "", subcat = "";
            for (const auto& _expense : expenses)
            {
                cat = _expense->category;
                subcat = _expense->subcategory;
                if (categorySeriesMap.find(_expense->subcategory) == categorySeriesMap.end())
                {
                    QLineSeries* series = new QLineSeries();
                    categorySeriesMap[_expense->subcategory] = series;
                }

                QString line = _expense->date.c_str();
                QStringList values = line.split(QLatin1Char('_'), Qt::SkipEmptyParts);

                QDateTime momentInTime;
                momentInTime.setDate(QDate(values[0].toInt(), values[1].toInt(), values[2].toInt()));
                categorySeriesMap[_expense->subcategory]->append(momentInTime.toMSecsSinceEpoch(), _expense->amount);
                //categorySeriesMap[_expense->subcategory]->append(QPointF(_expense->id, _expense->amount));
            }
            cat += (" Expense Chart : " + subcat);
            chart->setTitle(cat.c_str());
        }


        for (const auto& seri : categorySeriesMap) {
            chart->addSeries(seri.second);
            seri.second->attachAxis(axisX);
            seri.second->attachAxis(axisY);
        }

        chart->legend()->setVisible(true); // Show the legend

        QChartView* chartView = new QChartView(chart);
        layout->addWidget(chartView);
    }
};
// Class: ChartDialog2
// Description: [To be used to show Balance chart ].
//
class ChartDialog2 : public QDialog {
public:
    ChartDialog2(QWidget* parent, std::vector<std::shared_ptr<expense>> expenses, std::string type) : QDialog(parent) {
        QVBoxLayout* layout = new QVBoxLayout(this);

        QChart* chart = new QChart();
        QDateTimeAxis* axisX = new QDateTimeAxis;

        axisX->setTickCount(10);
        axisX->setFormat("yyyy-MM-dd");
        axisX->setTitleText("Date");
        chart->addAxis(axisX, Qt::AlignBottom);

        QValueAxis* axisY = new QValueAxis;
        axisY->setLabelFormat("%d");
        axisY->setTitleText("Balance");
        chart->addAxis(axisY, Qt::AlignLeft);

        std::map<std::string, QLineSeries*> categorySeriesMap;

        if (type == "category")
        {
            std::string cat = "";
            for (const auto& _expense : expenses)
            {
                cat = _expense->category;
                if (categorySeriesMap.find(_expense->category) == categorySeriesMap.end())
                {
                    QLineSeries* series = new QLineSeries();
                    categorySeriesMap[_expense->category] = series;
                }

                QString line = _expense->date.c_str();
                QStringList values = line.split(QLatin1Char('-'), Qt::SkipEmptyParts);

                QDateTime momentInTime;
                momentInTime.setDate(QDate(values[0].toInt(), values[1].toInt(), values[2].toInt()));
                qint64 tmp = momentInTime.toMSecsSinceEpoch();
                categorySeriesMap[_expense->category]->append(tmp, _expense->balance);
                //categorySeriesMap[_expense->category]->append(QPointF(_expense->id, _expense->amount));
            }
            cat += " Expense Chart";
            chart->setTitle(cat.c_str());

        }
        else
        {
            std::string cat = "", subcat = "";
            for (const auto& _expense : expenses)
            {
                cat = _expense->category;
                subcat = _expense->subcategory;
                if (categorySeriesMap.find(_expense->subcategory) == categorySeriesMap.end())
                {
                    QLineSeries* series = new QLineSeries();
                    categorySeriesMap[_expense->subcategory] = series;
                }

                QString line = _expense->date.c_str();
                QStringList values = line.split(QLatin1Char('_'), Qt::SkipEmptyParts);

                QDateTime momentInTime;
                momentInTime.setDate(QDate(values[0].toInt(), values[1].toInt(), values[2].toInt()));
                categorySeriesMap[_expense->subcategory]->append(momentInTime.toMSecsSinceEpoch(), _expense->balance);
                //categorySeriesMap[_expense->subcategory]->append(QPointF(_expense->id, _expense->amount));
            }
            cat += (" Expense Chart : " + subcat);
            chart->setTitle(cat.c_str());
        }


        for (const auto& seri : categorySeriesMap) {
            chart->addSeries(seri.second);
            seri.second->attachAxis(axisX);
            seri.second->attachAxis(axisY);
        }

        chart->legend()->setVisible(true); // Show the legend

        QChartView* chartView = new QChartView(chart);
        layout->addWidget(chartView);
    }
};
#endif // CHARTDIALOG_H