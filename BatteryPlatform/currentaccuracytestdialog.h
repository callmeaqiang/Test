#pragma once

#include <QDialog>
#include "ui_currentaccuracytestdialog.h"

class CurrentAccuracyTestDialog : public QDialog
{
	Q_OBJECT

public:
	CurrentAccuracyTestDialog(int testtype, int unique_id, QString voltage, QString capacity, QWidget *parent = Q_NULLPTR);
	CurrentAccuracyTestDialog(QString testname, int unique_id, QList<int> temp_list, QWidget *parent = Q_NULLPTR);
	
	~CurrentAccuracyTestDialog();

	void constructInit();
	void ModifyInit();
	int deal_for_decimal(QString voll);
	void closeEvent(QCloseEvent *event);
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
	Ui::CurrentAccuracyTestDialog ui;

	int m_test_type{ 0 };
	int test_unique_id{ 0 };
	bool constructOrNot{ false };
};
