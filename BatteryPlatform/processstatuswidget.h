#pragma once

#include <QWidget>
#include "ui_processstatuswidget.h"
#include <QTimer>


class ProcessStatusWidget : public QWidget
{
	Q_OBJECT

public:
	ProcessStatusWidget(QWidget *parent = Q_NULLPTR);
	~ProcessStatusWidget();

	void paintEvent(QPaintEvent *event);
	void init_test_UI(const QStringList test);
	void proceed_next_test();
	void draw_test_item_initial(int _test_num);
	void draw_tested_item(int _tested_num);
	void draw_testing_item(int _testing_num);

	void clear_alldata();

private:
	Ui::ProcessStatusWidget ui;

	int test_num{ 0 };
	int testing_num{ 1 };
	int tested_num{ 0 };
	QStringList test_type_list;
	QTimer *timer{ nullptr };
	bool is_change{ false };
};
