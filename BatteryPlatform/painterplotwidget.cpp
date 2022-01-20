#include "painterplotwidget.h"
#include <QtXlsx/QtXlsx>


PainterPlotWidget::PainterPlotWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	init_plot_UI();
	timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &PainterPlotWidget::stagnation_for_plot);
}

PainterPlotWidget::~PainterPlotWidget()
{
}

void PainterPlotWidget::init_plot_UI()
{
	ui.qcustomplot_voltage->addGraph();
	ui.qcustomplot_voltage->graph(0)->setPen(QPen(Qt::blue));
	ui.qcustomplot_voltage->graph(0)->setName("Voltage");

	ui.qcustomplot_current->addGraph();
	ui.qcustomplot_current->graph(0)->setPen(QPen(Qt::green));
	ui.qcustomplot_current->graph(0)->setName("charge_Current");
	ui.qcustomplot_current->addGraph();
	ui.qcustomplot_current->graph(1)->setPen(QPen(Qt::blue));
	ui.qcustomplot_current->graph(1)->setName("discharge_Current");

	ui.qcustomplot_Soc->addGraph();
	ui.qcustomplot_Soc->graph(0)->setPen(QPen(Qt::blue));
	ui.qcustomplot_Soc->graph(0)->setName("SOC");

	ui.qcustomplot_temperature->addGraph();
	ui.qcustomplot_temperature->graph(0)->setPen(QPen(Qt::magenta));
	ui.qcustomplot_temperature->graph(0)->setName("MaxTemperature");

	//显示图例，图例背景透明setBorderPen(Qt::NoPen);
	ui.qcustomplot_voltage->legend->setVisible(true);
	ui.qcustomplot_voltage->legend->setBrush(QColor(255, 255, 255, 0));
	ui.qcustomplot_voltage->legend->setBorderPen(Qt::NoPen);
	ui.qcustomplot_current->legend->setVisible(true);
	ui.qcustomplot_current->legend->setBrush(QColor(255, 255, 255, 0));
	ui.qcustomplot_current->legend->setBorderPen(Qt::NoPen);
	ui.qcustomplot_Soc->legend->setVisible(true);
	ui.qcustomplot_Soc->legend->setBrush(QColor(255, 255, 255, 0));
	ui.qcustomplot_Soc->legend->setBorderPen(Qt::NoPen);
	ui.qcustomplot_temperature->legend->setVisible(true);
	ui.qcustomplot_temperature->legend->setBrush(QColor(255, 255, 255, 0));
	ui.qcustomplot_temperature->legend->setBorderPen(Qt::NoPen);

	//设置x轴，y轴
	ui.qcustomplot_voltage->yAxis->setLabel("/V");
	ui.qcustomplot_current->yAxis->setLabel("/A");
	ui.qcustomplot_Soc->yAxis->setLabel("/%");
	ui.qcustomplot_temperature->yAxis->setLabel("/t");

	QSharedPointer<QCPAxisTickerDateTime> dateTick(new QCPAxisTickerDateTime);
	dateTick->setDateTimeFormat("hh:mm:ss\nyy-MM-dd");
	dateTick->setTickCount(9);
	dateTick->setTickStepStrategy(QCPAxisTicker::tssMeetTickCount);
	ui.qcustomplot_voltage->xAxis->setTicker(dateTick);
	ui.qcustomplot_current->xAxis->setTicker(dateTick);
	ui.qcustomplot_Soc->xAxis->setTicker(dateTick);
	ui.qcustomplot_temperature->xAxis->setTicker(dateTick);
	ui.qcustomplot_voltage->xAxis2->setTicker(dateTick);
	ui.qcustomplot_current->xAxis2->setTicker(dateTick);
	ui.qcustomplot_Soc->xAxis2->setTicker(dateTick);
	ui.qcustomplot_temperature->xAxis2->setTicker(dateTick);

	ui.qcustomplot_voltage->axisRect()->setupFullAxesBox();//四边安装轴并显示
	ui.qcustomplot_current->axisRect()->setupFullAxesBox();
	ui.qcustomplot_Soc->axisRect()->setupFullAxesBox();
	ui.qcustomplot_temperature->axisRect()->setupFullAxesBox();

	ui.qcustomplot_voltage->xAxis->setTickLabels(false);
	ui.qcustomplot_current->xAxis->setTickLabels(false);
	ui.qcustomplot_Soc->xAxis->setTickLabels(true);
	ui.qcustomplot_temperature->xAxis->setTickLabels(false);
	ui.qcustomplot_voltage->xAxis2->setTickLabels(false);
	ui.qcustomplot_current->xAxis2->setTickLabels(false);
	ui.qcustomplot_Soc->xAxis2->setTickLabels(false);
	ui.qcustomplot_temperature->xAxis2->setTickLabels(false);

	ui.qcustomplot_voltage->yAxis->setRange(10, 70);
	ui.qcustomplot_current->yAxis->setRange(-5, 85);
	ui.qcustomplot_Soc->yAxis->setRange(-5, 105);
	ui.qcustomplot_temperature->yAxis->setRange(-15, 75);

	QSharedPointer<QCPAxisTickerFixed> ticker(new QCPAxisTickerFixed);
	ticker.data()->setTickCount(9);
	ticker.data()->setTickStep(11);
	ui.qcustomplot_Soc->yAxis->setTicker(ticker);
	ui.qcustomplot_Soc->yAxis2->setTicker(ticker);


	ui.qcustomplot_voltage->axisRect()->setMinimumMargins(QMargins(0, 0, 0, 0));
	ui.qcustomplot_current->axisRect()->setMinimumMargins(QMargins(0, 0, 0, 0));
	ui.qcustomplot_Soc->axisRect()->setMinimumMargins(QMargins(0, 0, 0, 0));
	ui.qcustomplot_temperature->axisRect()->setMinimumMargins(QMargins(0, 0, 0, 0));

	ui.qcustomplot_voltage->yAxis->setLabelPadding(15);
	ui.qcustomplot_current->yAxis->setLabelPadding(15);
	ui.qcustomplot_Soc->yAxis->setLabelPadding(15);
	ui.qcustomplot_temperature->yAxis->setLabelPadding(15);
	ui.qcustomplot_voltage->yAxis->setLabelFont(QFont("Microsoft YaHei", 8));
	ui.qcustomplot_current->yAxis->setLabelFont(QFont("Microsoft YaHei", 8));
	ui.qcustomplot_Soc->yAxis->setLabelFont(QFont("Microsoft YaHei", 8));
	ui.qcustomplot_temperature->yAxis->setLabelFont(QFont("Microsoft YaHei", 8));

}

void PainterPlotWidget::set_plot_yAxs_ticker(QVector<double> &data, QCustomPlot * plot, QSharedPointer<QCPAxisTickerFixed> ticker)
{
	//设置坐标轴有9个刻度值
	ticker.data()->setTickCount(9);
	double max_n = 0, min_n = 100;
	for (int i = 0; i < data.size(); i++)
	{
		if (data.at(i) < min_n)
		{
			min_n = data.at(i);
		}
		if (data.at(i) > max_n)
		{
			max_n = data.at(i);
		}
	}
	int _offset_t = 10 - ((int)max_n - (int)min_n) % 10;
	if (((int)max_n - (int)min_n) % 10 != 0)
	{
		ticker.data()->setTickStep(((int)max_n - (int)min_n + _offset_t) / 10);
		if (_offset_t % 2 == 0)
		{
			plot->yAxis->setRange((int)min_n - _offset_t / 2, (int)max_n + _offset_t / 2);
			plot->yAxis2->setRange((int)min_n - _offset_t / 2, (int)max_n + _offset_t / 2);
		}
		else
		{
			plot->yAxis->setRange((int)min_n - _offset_t / 2, (int)max_n + _offset_t / 2 + 1);
			plot->yAxis2->setRange((int)min_n - _offset_t / 2, (int)max_n + _offset_t / 2 + 1);
		}

	}
	else
	{
		if ((int)max_n - (int)min_n == 0)
		{
			ticker.data()->setTickStep(1);
			plot->yAxis->setRange((int)min_n - 10 / 2, (int)max_n + 10 / 2);
			plot->yAxis2->setRange((int)min_n - 10 / 2, (int)max_n + 10 / 2);
		}
		else
		{
			ticker.data()->setTickStep(_offset_t / 10);
			plot->yAxis->setRange((int)min_n - _offset_t / 2, (int)max_n + _offset_t / 2);
			plot->yAxis2->setRange((int)min_n - _offset_t / 2, (int)max_n + _offset_t / 2);
		}
	}
}

void PainterPlotWidget::update_Plot_for_SOC_test(const int type, const QString str, QVector<double> tim, QVector<double> soc)
{
	double begain_tim = tim.first();
	double end_tim = tim.last();
	ui.qcustomplot_Soc->xAxis->setRange(begain_tim, end_tim);
	ui.qcustomplot_Soc->xAxis2->setRange(begain_tim, end_tim);
	ui.qcustomplot_Soc->graph(0)->addData(tim, soc);
	if (type)
	{
		ui.qcustomplot_Soc->graph(0)->setName("SOC of discharge");
	}
	else
	{
		ui.qcustomplot_Soc->graph(0)->setName("SOC of charge");
	}	
	ui.qcustomplot_Soc->replot();
	m_type = _SOC_plot;
	file_path = str;
	timer->start(10000);
}

void PainterPlotWidget::update_Plot_for_CD_test(const int type, QString path, QVector<double> timer_v, QVector<double> voltage, QVector<double> chargecurrent, QVector<double> dischargecurrent, QVector<double> soc, QVector<double> temper)
{
	if (timer_v.isEmpty())
	{
		return;
	}
	double begaintime = timer_v.first();
	double endtime = timer_v.last();

	ui.qcustomplot_voltage->xAxis->setRange(begaintime, endtime);
	ui.qcustomplot_voltage->xAxis2->setRange(begaintime, endtime);
	ui.qcustomplot_current->xAxis->setRange(begaintime, endtime);
	ui.qcustomplot_current->xAxis2->setRange(begaintime, endtime);
	ui.qcustomplot_Soc->xAxis->setRange(begaintime, endtime);
	ui.qcustomplot_Soc->xAxis2->setRange(begaintime, endtime);
	ui.qcustomplot_temperature->xAxis->setRange(begaintime, endtime);
	ui.qcustomplot_temperature->xAxis2->setRange(begaintime, endtime);

	QSharedPointer<QCPAxisTickerFixed> ticker_v(new QCPAxisTickerFixed);
	set_plot_yAxs_ticker(voltage, ui.qcustomplot_voltage, ticker_v);
	ui.qcustomplot_voltage->yAxis->setTicker(ticker_v);
	ui.qcustomplot_voltage->yAxis2->setTicker(ticker_v);
	QSharedPointer<QCPAxisTickerFixed> ticker_c(new QCPAxisTickerFixed);
	if (type)
	{
		set_plot_yAxs_ticker(dischargecurrent, ui.qcustomplot_current, ticker_c);
	}
	else
	{
		set_plot_yAxs_ticker(chargecurrent, ui.qcustomplot_current, ticker_c);
	}
	ui.qcustomplot_current->yAxis->setTicker(ticker_c);
	ui.qcustomplot_current->yAxis2->setTicker(ticker_c);

	QSharedPointer<QCPAxisTickerFixed> ticker_t(new QCPAxisTickerFixed);
	set_plot_yAxs_ticker(temper, ui.qcustomplot_temperature, ticker_t);
	ui.qcustomplot_temperature->yAxis->setTicker(ticker_t);
	ui.qcustomplot_temperature->yAxis2->setTicker(ticker_t);

	ui.qcustomplot_voltage->graph(0)->addData(timer_v, voltage);
	ui.qcustomplot_current->graph(0)->addData(timer_v, chargecurrent);
	ui.qcustomplot_current->graph(1)->addData(timer_v, dischargecurrent);
	ui.qcustomplot_Soc->graph(0)->addData(timer_v, soc);
	ui.qcustomplot_temperature->graph(0)->addData(timer_v, temper);

	if (type == 1)
	{
		ui.qcustomplot_Soc->graph(0)->setName("Standard_discharge SOC");
	}
	else if(type == 2)
	{
		ui.qcustomplot_Soc->graph(0)->setName("Standard_charge SOC");
	}
	else if (type == 3)
	{
		ui.qcustomplot_Soc->graph(0)->setName("Fast_discharge SOC");
	}
	else 
	{
		ui.qcustomplot_Soc->graph(0)->setName("Fast_charge SOC");
	}
	ui.qcustomplot_temperature->replot();
	ui.qcustomplot_voltage->replot();
	ui.qcustomplot_current->replot();
	ui.qcustomplot_Soc->replot();

	m_type = _CD_plot;
	file_path = path;
	timer->start(10000);
}

void PainterPlotWidget::stagnation_for_plot()
{
	timer->stop();
	if (m_type == _SOC_plot)
	{
		QPixmap img = ui.qcustomplot_Soc->toPixmap(1000, 210);
		QXlsx::Document xlsx(file_path);
		if (!xlsx.selectSheet("SOC Test"))
		{
			xlsx.addSheet("SOC Test");
		}
		xlsx.insertImage(fabs(xlsx.dimension().rowCount() - 20), 4, img.toImage());
		xlsx.save();
		ui.qcustomplot_Soc->graph(0)->data().data()->clear();
		ui.qcustomplot_Soc->replot();
	}
	else if (m_type == _CD_plot)
	{
		QPixmap img1 = ui.qcustomplot_voltage->toPixmap(1000, 210);
		QPixmap img2 = ui.qcustomplot_current->toPixmap(1000, 210);
		QPixmap img3 = ui.qcustomplot_temperature->toPixmap(1000, 210);
		QPixmap img4 = ui.qcustomplot_Soc->toPixmap(1000, 210);


		QPixmap newImg(1000, 840);
		QPainter p(&newImg);
		QRect rect1(0, 0, 1000, 210);
		QRect rect2(0, 210, 1000, 210);
		QRect rect3(0, 420, 1000, 210);
		QRect rect4(0, 630, 1000, 210);
		p.drawImage(rect1, img1.toImage());
		p.drawImage(rect2, img2.toImage());
		p.drawImage(rect3, img3.toImage());
		p.drawImage(rect4, img4.toImage());

		QXlsx::Document xlsx(file_path);
		if (!xlsx.selectSheet("Charge&discharge Test"))
		{
			xlsx.addSheet("Charge&discharge Test");
		}
		xlsx.insertImage(xlsx.dimension().rowCount() - 6, 3, newImg.toImage());
		xlsx.save();
		//数据清空
		ui.qcustomplot_voltage->graph(0)->data().data()->clear();
		ui.qcustomplot_current->graph(0)->data().data()->clear();
		ui.qcustomplot_current->graph(1)->data().data()->clear();
		ui.qcustomplot_Soc->graph(0)->data().data()->clear();
		ui.qcustomplot_temperature->graph(0)->data().data()->clear();
	}
}

