#include "capacitytestdialog.h"

CapacityTestDialog::CapacityTestDialog(int testtype, int unique_id, QString voltage, QString capacity, QWidget *parent)
	: QDialog(parent), m_test_type(testtype), test_unique_id(unique_id)
{
	ui.setupUi(this);
	ui.lineEdit_chargeCurrent->setText(capacity);
	ui.lineEdit_chargeVoltage->setText(voltage);
	ui.lineEdit_dischargeCurrent->setText(capacity);
}

CapacityTestDialog::CapacityTestDialog(QString testname, int unique_id, QList<int> temp_list, QWidget * parent)
	: QDialog(parent), test_unique_id(unique_id)
{
	ui.setupUi(this);
	m_test_type = temp_list.at(0);
	ui.lineEdit_testname->setText(testname);
	ui.lineEdit_chargeVoltage->setText(QString("%1").arg((float)temp_list.at(1) / 10, 0, 'f', 1));
	ui.lineEdit_chargeCurrent->setText(QString("%1").arg((float)temp_list.at(2) / 10, 0, 'f', 1));
	ui.lineEdit_dischargeCurrent->setText(QString("%1").arg((float)temp_list.at(3) / 10, 0, 'f', 1));
	ui.lineEdit_cycles->setText(QString("%1").arg(temp_list.at(4)));
}

CapacityTestDialog::~CapacityTestDialog()
{
}

void CapacityTestDialog::constructInit()
{
	ui.ModifyBtn->hide();
	ui.SaveBtn->show();
}

void CapacityTestDialog::ModifyInit()
{
	ui.ModifyBtn->show();
	ui.SaveBtn->hide();
}

void CapacityTestDialog::on_SaveBtn_clicked()
{
	if (ui.lineEdit_cycles->text().contains(".") || ui.lineEdit_cycles->text().toInt() < 3)
	{
		return;
	}
	QList<int> infolist;
	infolist.append(m_test_type);
	infolist.append(deal_for_decimal(ui.lineEdit_chargeVoltage->text()));//充电电压
	infolist.append(deal_for_decimal(ui.lineEdit_chargeCurrent->text()));//充电电流
	infolist.append(deal_for_decimal(ui.lineEdit_dischargeCurrent->text()));//放电电流
	infolist.append(ui.lineEdit_cycles->text().toInt()); //循环次数

	constructOrNot = true;
	emit construct_data(ui.lineEdit_testname->text(), "Capacity" + QString::number(test_unique_id), infolist);
	this->close();
}
void CapacityTestDialog::on_ModifyBtn_clicked()
{
	if (ui.lineEdit_cycles->text().contains(".") || ui.lineEdit_cycles->text().toInt() < 3)
	{
		return;
	}
	QList<int> infolist;
	infolist.append(m_test_type);
	infolist.append(deal_for_decimal(ui.lineEdit_chargeVoltage->text()));//充电电压
	infolist.append(deal_for_decimal(ui.lineEdit_chargeCurrent->text()));//充电电流
	infolist.append(deal_for_decimal(ui.lineEdit_dischargeCurrent->text()));//放电电流
	infolist.append(ui.lineEdit_cycles->text().toInt()); //循环次数

	emit modify_data(infolist);
	this->close();
}
void CapacityTestDialog::on_ReturnBtn_clicked()
{
	this->close();
}

int CapacityTestDialog::deal_for_decimal(QString voll)
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

void CapacityTestDialog::closeEvent(QCloseEvent * event)
{
	QDialog::closeEvent(event);
	emit returnBefore(constructOrNot);
}

void CapacityTestDialog::press_save_btn()
{
	on_SaveBtn_clicked();
}
