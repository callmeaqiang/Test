#include "chargeanddischargetestdialog.h"

ChargeAndDischargeTestDialog::ChargeAndDischargeTestDialog(int testtype, int unique_id, QString voltage, QString capacity, QWidget *parent)
	: QDialog(parent), m_test_type(testtype), test_unique_id(unique_id)
{
	ui.setupUi(this);
	ui.lineEdit_chargeVoltage->setText(voltage);
	ui.lineEdit_chargeCurrent_standard->setText(QString("%1").arg((float)deal_for_decimal(capacity) /20, 0, 'f', 1));
	ui.lineEdit_chargeCurrent_fast->setText(capacity);
	ui.lineEdit_dischargeCurrent_standard->setText(QString("%1").arg((float)deal_for_decimal(capacity) / 20, 0, 'f', 1));
	ui.lineEdit_dischargeCurrent_fast->setText(capacity);
}

ChargeAndDischargeTestDialog::ChargeAndDischargeTestDialog(QString testname, int unique_id, QList<int> temp_list, QWidget * parent)
	: QDialog(parent), test_unique_id(unique_id)
{
	ui.setupUi(this);
	m_test_type = temp_list.at(0);
	ui.lineEdit_testname->setText(testname);
	ui.lineEdit_chargeVoltage->setText(QString("%1").arg((float)temp_list.at(1) / 10, 0, 'f', 1));
	ui.lineEdit_chargeCurrent_standard->setText(QString("%1").arg((float)temp_list.at(2) / 10, 0, 'f', 1));
	ui.lineEdit_chargeCurrent_fast->setText(QString("%1").arg((float)temp_list.at(3) / 10, 0, 'f', 1));
	ui.lineEdit_dischargeCurrent_standard->setText(QString("%1").arg((float)temp_list.at(4) / 10, 0, 'f', 1));
	ui.lineEdit_dischargeCurrent_fast->setText(QString("%1").arg((float)temp_list.at(5) / 10, 0, 'f', 1));
}

ChargeAndDischargeTestDialog::~ChargeAndDischargeTestDialog()
{
}

void ChargeAndDischargeTestDialog::constructInit()
{
	ui.ModifyBtn->hide();
	ui.SaveBtn->show();
}

void ChargeAndDischargeTestDialog::ModifyInit()
{
	ui.ModifyBtn->show();
	ui.SaveBtn->hide();
}

void ChargeAndDischargeTestDialog::on_SaveBtn_clicked()
{
	QList<int> infolist;
	infolist.append(m_test_type);
	infolist.append(deal_for_decimal(ui.lineEdit_chargeVoltage->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_chargeCurrent_standard->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_chargeCurrent_fast->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_dischargeCurrent_standard->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_dischargeCurrent_fast->text()));

	constructOrNot = true;
	emit construct_data(ui.lineEdit_testname->text(), "Charge_Discharge" + QString::number(test_unique_id), infolist);
	this->close();
}
void ChargeAndDischargeTestDialog::on_ModifyBtn_clicked()
{
	QList<int> infolist;
	infolist.append(m_test_type);
	infolist.append(deal_for_decimal(ui.lineEdit_chargeVoltage->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_chargeCurrent_standard->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_chargeCurrent_fast->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_dischargeCurrent_standard->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_dischargeCurrent_fast->text()));

	emit modify_data(infolist);
	this->close();
}
void ChargeAndDischargeTestDialog::on_ReturnBtn_clicked()
{
	this->close();
}

int ChargeAndDischargeTestDialog::deal_for_decimal(QString voll)
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

void ChargeAndDischargeTestDialog::closeEvent(QCloseEvent * event)
{
	QDialog::closeEvent(event);
	emit returnBefore(constructOrNot);
}

void ChargeAndDischargeTestDialog::press_save_btn()
{
	on_SaveBtn_clicked();
}
