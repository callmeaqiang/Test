#include "dischargetestdialog.h"


DischargeTestDialog::DischargeTestDialog(int testtype, int unique_id, QString capacity, QWidget *parent)
	: QDialog(parent), m_test_type(testtype), test_unique_id(unique_id)
{
	ui.setupUi(this);
	ui.lineEdit_Current_simple->setText(capacity);
	ui.radioButton_fullDischarge->setChecked(true);
}

DischargeTestDialog::DischargeTestDialog(QString testname, int unique_id, QList<int> temp_list, QWidget * parent)
	: QDialog(parent), test_unique_id(unique_id)
{
	ui.setupUi(this);
	m_test_type = temp_list.at(0);
	ui.lineEdit_testname->setText(testname);
	ui.lineEdit_Current_simple->setText(QString("%1").arg((float)temp_list.at(1)/10, 0, 'f', 1));
	if (temp_list.at(2) == 1)
	{
		ui.radioButton_fullDischarge->setChecked(true);
	}
	else
	{
		ui.radioButton_SOC->setChecked(true);
		ui.lineEdit_SOC->setText(QString::number(temp_list.at(3)));
	}
}

DischargeTestDialog::~DischargeTestDialog()
{
}

void DischargeTestDialog::constructInit()
{
	ui.ModifyBtn->hide();
	ui.SaveBtn->show();
}

void DischargeTestDialog::ModifyInit()
{
	ui.ModifyBtn->show();
	ui.SaveBtn->hide();
}

void DischargeTestDialog::closeEvent(QCloseEvent * event)
{
	QDialog::closeEvent(event);
	emit returnBefore(constructOrNot);
}

void DischargeTestDialog::press_save_btn()
{
	on_SaveBtn_clicked();
}

void DischargeTestDialog::on_SaveBtn_clicked()
{
	QList<int> infolist;
	infolist.append(m_test_type);
	infolist.append(deal_for_decimal(ui.lineEdit_Current_simple->text()));
	if (ui.radioButton_fullDischarge->isChecked())
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
	emit construct_data(ui.lineEdit_testname->text(), "Simple_Discharge" + QString::number(test_unique_id), infolist);
	this->close();
}
void DischargeTestDialog::on_ModifyBtn_clicked()
{
	QList<int> infolist;
	infolist.append(m_test_type);
	infolist.append(deal_for_decimal(ui.lineEdit_Current_simple->text()));
	if (ui.radioButton_fullDischarge->isChecked())
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

int DischargeTestDialog::deal_for_decimal(QString voll)
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

void DischargeTestDialog::on_ReturnBtn_clicked()
{
	this->close();
}
