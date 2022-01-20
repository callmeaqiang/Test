#include "processstatuswidget.h"
#include <QDebug>
#include <QPainter>

ProcessStatusWidget::ProcessStatusWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	timer = new QTimer(this);
	connect(timer, &QTimer::timeout, [=]() 
	{
		this->update();
	});
}

ProcessStatusWidget::~ProcessStatusWidget()
{

}

void ProcessStatusWidget::paintEvent(QPaintEvent * event)
{
	draw_test_item_initial(test_num);
	draw_tested_item(tested_num);
	draw_testing_item(testing_num);
	QWidget::paintEvent(event);
}

void ProcessStatusWidget::init_test_UI(const QStringList test)
{
	timer->start(200);
	this->test_type_list = test;
	this->test_num = test.size();
	tested_num = 0;
	testing_num = 1;
	this->update();
}

void ProcessStatusWidget::proceed_next_test()
{
	if (testing_num > test_num)
	{
		testing_num = 1;
		tested_num  = 0;
		timer->stop();
		this->update();
		return;
	}
	else
	{
		testing_num ++;
		tested_num ++;
		this->update();
	}
}

void ProcessStatusWidget::draw_test_item_initial(int _test_num)
{
	QPainter painter(this);
	painter.setPen(QPen(Qt::blue, 1));
	painter.setBrush(QBrush(QColor(255, 0, 0)));
	for (int i = 0; i < _test_num; i++)
	{
		painter.drawEllipse(QRectF(100 + 100 * i, 100, 50, 50));
	}
}

void ProcessStatusWidget::draw_tested_item(int _tested_num)
{
	if (_tested_num > test_num)
	{
		_tested_num = test_num;
	}
	QPainter painter(this);
	painter.setPen(QPen(Qt::blue, 1));
	painter.setBrush(QBrush(QColor(0, 255, 0)));
	for (int i = 1; i <= _tested_num; i ++)
	{
		painter.drawEllipse(QRectF(100* i, 100, 50, 50));
	}
	for (int i = 1; i <= _tested_num; i++)
	{
		if (i == test_num)
		{
			return;
		}
		painter.drawLine(QPointF(100 * i + 90, 120), QPointF(100 * i + 95, 125));
		painter.drawLine(QPointF(100 * i + 55, 125), QPointF(100 * i + 95, 125));
		painter.drawLine(QPointF(100 * i + 90, 130), QPointF(100 * i + 95, 125));
	}
	
}

void ProcessStatusWidget::draw_testing_item(int _testing_num)
{
	if (_testing_num > test_num)
	{
		return;
	}
	QPainter painter(this);
	painter.setPen(QPen(Qt::blue, 1));
	if (is_change)
	{
		painter.setBrush(QBrush(QColor(0, 255, 0)));
		is_change = false;
	}
	else
	{
		painter.setBrush(QBrush(QColor(255, 0, 0)));
		is_change = true;
	}
	painter.drawEllipse(QRectF(100 * _testing_num, 100, 50, 50));
}

void ProcessStatusWidget::clear_alldata()
{
	timer->stop();
	test_num = 0;
	testing_num = 0;
}
