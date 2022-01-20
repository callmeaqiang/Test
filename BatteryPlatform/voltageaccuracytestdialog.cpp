#include "voltageaccuracytestdialog.h"


VoltageAccuracyTestDialog::VoltageAccuracyTestDialog(int testtype, int unique_id, QString voltage, QString capacity, QWidget *parent)
	: QDialog(parent), m_test_type(testtype), test_unique_id(unique_id)
{
	ui.setupUi(this);
	ui.lineEdit_voltage->setText(voltage);
	ui.lineEdit_charge_current->setText(capacity);
	ui.lineEdit_discharge_current->setText(capacity);
	ui.radioButton_error_percentage->setChecked(true);
}

VoltageAccuracyTestDialog::VoltageAccuracyTestDialog(QString testname, int unique_id, QList<int> temp_list, QWidget * parent)
	: QDialog(parent), test_unique_id(unique_id)
{
	ui.setupUi(this);
	m_test_type = temp_list.at(0);
	ui.lineEdit_testname->setText(testname);
	ui.lineEdit_voltage->setText(QString("%1").arg((float)temp_list.at(1) / 10, 0, 'f', 1));
	ui.lineEdit_charge_current->setText(QString("%1").arg((float)temp_list.at(2) / 10, 0, 'f', 1));
	ui.lineEdit_discharge_current->setText(QString("%1").arg((float)temp_list.at(3) / 10, 0, 'f', 1));
	ui.lineEdit_soc_gap->setText(QString("%1").arg(temp_list.at(4)));
	if (temp_list.at(5) != 0)
	{
		ui.radioButton_error_percentage->setChecked(true);
		ui.lineEdit_error_percentage->setText(QString::number(temp_list.at(5)));
	}
	else
	{
		ui.radioButton_error_voltage->setChecked(true);
		ui.lineEdit_error_voltage->setText(QString("%1").arg((float)temp_list.at(6) / 10, 0, 'f', 1));
	}
	ui.lineEdit_min_voltage->setText(QString("%1").arg((float)temp_list.at(7) / 10, 0, 'f', 1));
	ui.lineEdit_max_voltage->setText(QString("%1").arg((float)temp_list.at(8) / 10, 0, 'f', 1));
}
VoltageAccuracyTestDialog::~VoltageAccuracyTestDialog()
{

}

void VoltageAccuracyTestDialog::constructInit()
{
	ui.ModifyBtn->hide();
	ui.SaveBtn->show();
}

void VoltageAccuracyTestDialog::ModifyInit()
{
	ui.SaveBtn->hide();
	ui.ModifyBtn->show();
}



void VoltageAccuracyTestDialog::closeEvent(QCloseEvent * event)
{
	QDialog::closeEvent(event);
	emit returnBefore(constructOrNot);
}

int VoltageAccuracyTestDialog::deal_for_decimal(QString voll)
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

void VoltageAccuracyTestDialog::on_SaveBtn_clicked()
{
	if (ui.lineEdit_soc_gap->text().toInt() == 0)
	{
		return;
	}
	QList<int> infolist;
	infolist.append(m_test_type);
	infolist.append(deal_for_decimal(ui.lineEdit_voltage->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_charge_current->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_discharge_current->text()));
	infolist.append(ui.lineEdit_soc_gap->text().toInt());
	int error_current = 0;
	if (ui.radioButton_error_percentage->isChecked())
	{
		if (ui.lineEdit_error_percentage->text().toInt() == 0)
		{
			return;
		}
		error_current = deal_for_decimal(ui.lineEdit_voltage->text()) * ui.lineEdit_error_percentage->text().toInt();
		infolist.append(ui.lineEdit_error_percentage->text().toInt());
	}
	else
	{
		infolist.append(0);
	}
	if (ui.radioButton_error_voltage->isChecked())
	{
		if (deal_for_decimal(ui.lineEdit_error_voltage->text()) == 0)
		{
			return;
		}
		error_current = deal_for_decimal(ui.lineEdit_error_voltage->text()) * 100;
		infolist.append(deal_for_decimal(ui.lineEdit_error_voltage->text()));
	}
	else
	{
		infolist.append(0);
	}
	infolist.append(error_current);
	infolist.append(deal_for_decimal(ui.lineEdit_min_voltage->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_max_voltage->text()));

	constructOrNot = true;
	emit construct_data(ui.lineEdit_testname->text(), "Voltage_Accuracy" + QString::number(test_unique_id), infolist);
	this->close();
}
void VoltageAccuracyTestDialog::on_ModifyBtn_clicked()
{
	if (ui.lineEdit_soc_gap->text().toInt() == 0)
	{
		return;
	}
	QList<int> infolist;
	infolist.append(m_test_type);
	infolist.append(deal_for_decimal(ui.lineEdit_voltage->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_charge_current->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_discharge_current->text()));
	infolist.append(ui.lineEdit_soc_gap->text().toInt());
	int error_current = 0;
	if (ui.radioButton_error_percentage->isChecked())
	{
		if (ui.lineEdit_error_percentage->text().toInt() == 0)
		{
			return;
		}
		error_current = deal_for_decimal(ui.lineEdit_voltage->text()) * ui.lineEdit_error_percentage->text().toInt();
		infolist.append(ui.lineEdit_error_percentage->text().toInt());
	}
	else
	{
		infolist.append(0);
	}
	if (ui.radioButton_error_voltage->isChecked())
	{
		if (deal_for_decimal(ui.lineEdit_error_voltage->text()) == 0)
		{
			return;
		}
		error_current = deal_for_decimal(ui.lineEdit_error_voltage->text()) * 100;
		infolist.append(deal_for_decimal(ui.lineEdit_error_voltage->text()));
	}
	else
	{
		infolist.append(0);
	}
	infolist.append(error_current);
	infolist.append(deal_for_decimal(ui.lineEdit_min_voltage->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_max_voltage->text()));

	emit modify_data(infolist);
	this->close();
}
void VoltageAccuracyTestDialog::on_ReturnBtn_clicked()
{	
	this->close();
}

void VoltageAccuracyTestDialog::press_save_btn()
{
	on_SaveBtn_clicked();
}


