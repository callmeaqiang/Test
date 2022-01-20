#include "chargetestdialog.h"
#include <QTimer>
/*
	list.at(0)  :测试类型
	list.at(1)  :充放电
	list.at(2)  :充电电压
	list.at(3)  :充电电流
	list.at(4)	:放电电流
	list.at(5)  :满充截止 0否 1是
	list.at(6)  :Soc 截止 0否 1是
*/


ChargeTestDialog::ChargeTestDialog(int testtype, int unique_id, QString voltage, QString capacity, QWidget *parent)
	: QDialog(parent), m_test_type(testtype), test_unique_id(unique_id)
{
	ui.setupUi(this);
	ui.lineEdit_Current_simple->setText(capacity);
	ui.lineEdit_Voltage_simple->setText(voltage);
	ui.radioButton_fullCharge->setChecked(true);
}

ChargeTestDialog::ChargeTestDialog(QString testname, int unique_id, QList<int> temp_list, QWidget * parent)
	:QDialog(parent), test_unique_id(unique_id)
{
	ui.setupUi(this);
	m_test_type = temp_list.at(0);
	ui.lineEdit_testname->setText(testname);
	ui.lineEdit_Voltage_simple->setText(QString("%1").arg((float)temp_list.at(1) / 10, 0, 'f', 1));
	ui.lineEdit_Current_simple->setText(QString("%1").arg((float)temp_list.at(2) / 10, 0, 'f', 1));
	if (temp_list.at(3) == 1)
	{
		ui.radioButton_fullCharge->setChecked(true);
	}
	else
	{
		ui.radioButton_SOC->setChecked(true);
		ui.lineEdit_SOC->setText(QString::number(temp_list.at(4)));
	}	
}

ChargeTestDialog::~ChargeTestDialog()
{

}

void ChargeTestDialog::constructInit()
{
	ui.ModifyBtn->hide();
	ui.SaveBtn->show();
}

void ChargeTestDialog::ModifyInit()
{
	ui.ModifyBtn->show();
	ui.SaveBtn->hide();
}

void ChargeTestDialog::on_SaveBtn_clicked()
{
	QList<int> infolist;
	infolist.append(m_test_type);
	infolist.append(deal_for_decimal(ui.lineEdit_Voltage_simple->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_Current_simple->text()));
	if (ui.radioButton_fullCharge->isChecked())
	{
		infolist.append(1);
	}
	else
	{
		infolist.append(0);
	}
	if (ui.radioButton_SOC->isChecked())
	{
		if (ui.lineEdit_SOC->text().toInt() == 0)
		{
			return;
		}
		infolist.append(ui.lineEdit_SOC->text().toInt());
	}
	else
	{
		infolist.append(0);
	}

	constructOrNot = true;
	emit construct_data(ui.lineEdit_testname->text(), "Simple_Charge" + QString::number(test_unique_id), infolist);
	this->close();
}
void ChargeTestDialog::on_ModifyBtn_clicked()
{
	QList<int> infolist;
	infolist.append(m_test_type);
	infolist.append(deal_for_decimal(ui.lineEdit_Voltage_simple->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_Current_simple->text()));
	if (ui.radioButton_fullCharge->isChecked())
	{
		infolist.append(1);
	}
	else
	{
		infolist.append(0);
	}
	if (ui.radioButton_SOC->isChecked())
	{
		if (ui.lineEdit_SOC->text().toInt() == 0)
		{
			return;
		}
		infolist.append(ui.lineEdit_SOC->text().toInt());

	}
	else
	{
		infolist.append(0);
	}

	emit modify_data(infolist);
	this->close();
}
void ChargeTestDialog::on_ReturnBtn_clicked()
{
	this->close();
}

int ChargeTestDialog::deal_for_decimal(QString voll)
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

void ChargeTestDialog::closeEvent(QCloseEvent * event)
{
	QDialog::closeEvent(event);
	emit returnBefore(constructOrNot);
}

void ChargeTestDialog::press_save_btn()
{
	on_SaveBtn_clicked();
}
