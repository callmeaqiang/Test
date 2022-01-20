#pragma once

#include <QDialog>
#include "ui_batterywarnningdialog.h"

class BatteryWarnningDialog : public QDialog
{
	Q_OBJECT

public:
	BatteryWarnningDialog(QWidget *parent = Q_NULLPTR);
	~BatteryWarnningDialog();

	void init_tableWidget();
	void transport_waring();
	void interpolate_warning(const QString data, const int type);
signals:
	void decrease_warningCount();

private slots:
	void on_pushButton_DealAll_clicked();

private:
	Ui::BatteryWarnningDialog ui;

	int m_warning_count{ 0 };
	int toatal_warning{ 0 };
};
