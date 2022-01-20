#pragma once

#include <QWidget>
#include <QTimer>
#include "ui_painterplotwidget.h"
#include "qcustomplot.h"

class PainterPlotWidget : public QWidget
{
	Q_OBJECT

public:
	PainterPlotWidget(QWidget *parent = Q_NULLPTR);
	~PainterPlotWidget();

	enum plot_type
	{
		_SOC_plot, _CD_plot,
	};

	void init_plot_UI();
	void set_plot_yAxs_ticker(QVector<double> &data, QCustomPlot * plot, QSharedPointer<QCPAxisTickerFixed> ticker);
	void update_Plot_for_SOC_test(const int type, const QString str, QVector<double> tim, QVector<double> soc);
	void update_Plot_for_CD_test(const int type, QString path, QVector<double> timer_v, QVector<double> voltage, QVector<double> chargecurrent, QVector<double> dischargecurrent, QVector<double> soc, QVector<double> temper);

	void stagnation_for_plot();
private:
	Ui::PainterPlotWidget ui;
	QTimer *timer{ nullptr };
	QString file_path;
	int m_type{ 0 };
};
