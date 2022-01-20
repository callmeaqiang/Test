#include "currentaccuracytestdialog.h"
#include <QDebug>
#include <QIcon>
#include <QPixmap> 


CurrentAccuracyTestDialog::CurrentAccuracyTestDialog(int testtype, int unique_id, QString voltage, QString capacity, QWidget *parent)
	: QDialog(parent),m_test_type(testtype), test_unique_id(unique_id)
{
	ui.setupUi(this);
	ui.lineEdit_voltage->setText(voltage);
	ui.lineEdit_max_current->setText(capacity);
	ui.radioButton_error_percentage->setChecked(true);
}

CurrentAccuracyTestDialog::CurrentAccuracyTestDialog(QString testname, int unique_id, QList<int> temp_list, QWidget * parent)
	: QDialog(parent), test_unique_id(unique_id)
{
	ui.setupUi(this);
	m_test_type = temp_list.at(0);
	ui.lineEdit_testname->setText(testname);
	ui.lineEdit_voltage->setText(QString("%1").arg((float)temp_list.at(1) / 10, 0, 'f', 1));
	ui.lineEdit_max_current->setText(QString("%1").arg((float)temp_list.at(2) / 10, 0, 'f', 1));
	ui.lineEdit_current_gap->setText(QString("%1").arg(temp_list.at(3)));
	if (temp_list.at(4) != 0)
	{
		ui.radioButton_error_percentage->setChecked(true);
		ui.lineEdit_error_percentage->setText(QString::number(temp_list.at(4)));
	}
	else
	{
		ui.radioButton_error_current->setChecked(true);
		ui.lineEdit_error_current->setText(QString("%1").arg((float)temp_list.at(5) / 10, 0, 'f', 1));
	}
}

CurrentAccuracyTestDialog::~CurrentAccuracyTestDialog()
{
	
}


void CurrentAccuracyTestDialog::constructInit()
{
	ui.ModifyBtn->hide();
	ui.SaveBtn->show();
}

void CurrentAccuracyTestDialog::ModifyInit()
{
	ui.SaveBtn->hide();
	ui.ModifyBtn->show();
}

int CurrentAccuracyTestDialog::deal_for_decimal(QString voll)
{
	if (voll.contains("."))
	{
		int index = voll.indexOf(".");
		int str_size = voll.size();
		voll.remove(".");
		int tem_val = voll.toInt() / pow(10, str_size - index - 2);
		return tem_val;
	}

	return voll.toInt() * 10;
}

void CurrentAccuracyTestDialog::closeEvent(QCloseEvent * event)
{	
	QDialog::closeEvent(event);
	emit returnBefore(constructOrNot);
}

void CurrentAccuracyTestDialog::press_save_btn()
{
	on_SaveBtn_clicked();
}

void CurrentAccuracyTestDialog::on_SaveBtn_clicked()
{
	if (ui.lineEdit_current_gap->text().toInt() == 0)
	{
		return;
	}
	QList<int> infolist;	
	infolist.append(m_test_type);
	infolist.append(deal_for_decimal(ui.lineEdit_voltage->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_max_current->text()));
	infolist.append(ui.lineEdit_current_gap->text().toInt());
	int error_current = 0;
	if (ui.radioButton_error_percentage->isChecked())
	{
		if (ui.lineEdit_error_percentage->text().toInt() == 0)
		{
			return;
		}
		error_current = deal_for_decimal(ui.lineEdit_max_current->text()) * ui.lineEdit_error_percentage->text().toInt();
		infolist.append(ui.lineEdit_error_percentage->text().toInt());	
	}
	else
	{
		infolist.append(0);
	}
	if(ui.radioButton_error_current->isChecked())
	{
		if (deal_for_decimal(ui.lineEdit_error_current->text()) == 0)
		{
			return;
		}
		error_current = deal_for_decimal(ui.lineEdit_error_current->text()) * 100;
		infolist.append(deal_for_decimal(ui.lineEdit_error_current->text()));
	}
	else
	{
		infolist.append(0);
	}
	infolist.append(error_current);

	constructOrNot = true;
	emit construct_data(ui.lineEdit_testname->text(), "Current_Accuracy" + QString::number(test_unique_id) ,infolist);
	this->close();
}
void CurrentAccuracyTestDialog::on_ModifyBtn_clicked()
{
	if (ui.lineEdit_current_gap->text().toInt() == 0)
	{
		return;
	}
	QList<int> infolist;
	infolist.append(m_test_type);
	infolist.append(deal_for_decimal(ui.lineEdit_voltage->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_max_current->text()));
	infolist.append(ui.lineEdit_current_gap->text().toInt());
	int error_current = 0;
	if (ui.radioButton_error_percentage->isChecked())
	{
		if (ui.lineEdit_error_percentage->text().toInt() == 0)
		{
			return;
		}
		error_current = deal_for_decimal(ui.lineEdit_max_current->text()) * ui.lineEdit_error_percentage->text().toInt();
		infolist.append(ui.lineEdit_error_percentage->text().toInt());
	}
	else
	{
		infolist.append(0);
	}
	if (ui.radioButton_error_current->isChecked())
	{
		if (deal_for_decimal(ui.lineEdit_error_current->text()) == 0)
		{
			return;
		}
		error_current = deal_for_decimal(ui.lineEdit_error_current->text()) * 100;
		infolist.append(deal_for_decimal(ui.lineEdit_error_current->text()));
	}
	else
	{
		infolist.append(0);
	}
	infolist.append(error_current);

	emit modify_data(infolist);
	this->close();
}
void CurrentAccuracyTestDialog::on_ReturnBtn_clicked()
{
	this->close();
}

