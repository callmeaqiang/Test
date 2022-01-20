#pragma once

#include <QDialog>
#include "ui_voltageaccuracytestdialog.h"

class VoltageAccuracyTestDialog : public QDialog
{
	Q_OBJECT

public:
	VoltageAccuracyTestDialog(int testtype, int unique_id, QString voltage, QString capacity, QWidget *parent = Q_NULLPTR);
	VoltageAccuracyTestDialog(QString testname, int unique_id, QList<int> temp_list, QWidget * parent = Q_NULLPTR);
	~VoltageAccuracyTestDialog();

	void constructInit();
	void ModifyInit();
	void closeEvent(QCloseEvent *event);
	int deal_for_decimal(QString voll);
	void press_save_btn();
signals:
	void returnBefore(const bool val);
	void construct_data(const QString testname, const QString WhatsThis, QList<int> list);
	void modify_data(const QList<int> list);

private slots:
	void on_SaveBtn_clicked();
	void on_ModifyBtn_clicked();
	void on_ReturnBtn_clicked();

private:
	Ui::VoltageAccuracyTestDialog ui;
	int m_test_type{ 0 };
	int test_unique_id{ 0 };
	bool constructOrNot{ false };

};
