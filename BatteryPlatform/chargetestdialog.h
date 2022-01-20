#pragma once

#include <QDialog>
#include "ui_chargetestdialog.h"

class ChargeTestDialog : public QDialog
{
	Q_OBJECT

public:
	ChargeTestDialog(int testtype, int unique_id, QString voltage, QString capacity, QWidget *parent = Q_NULLPTR);
	ChargeTestDialog(QString testname,int unique_id, QList<int> temp_list, QWidget *parent = Q_NULLPTR);
	~ChargeTestDialog();

	void constructInit();
	void ModifyInit();
	int deal_for_decimal(QString voll);
	void closeEvent(QCloseEvent * event);
	void press_save_btn();
signals:
	void returnBefore(const bool val);
	void construct_data(const QString testname, const QString WhatsThis, const QList<int> list);
	void modify_data(const QList<int> list);

private slots:
	void on_SaveBtn_clicked();
	void on_ModifyBtn_clicked();
	void on_ReturnBtn_clicked();

private:
	Ui::ChargeTestDialog ui;
	int m_test_type{ 0 };
	int test_unique_id{ 0 };
	bool constructOrNot{ false };
};
