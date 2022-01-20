#include "protectionparametersdialog.h"

ProtectionParametersDialog::ProtectionParametersDialog(int testtype, int unique_id, QString voltage, QString capacity, QWidget *parent)
	: QDialog(parent), m_test_type(testtype), test_unique_id(unique_id)
{
	ui.setupUi(this);
	ui.lineEdit_chargeVoltage->setText(voltage);
	ui.lineEdit_chargeCurrent->setText(capacity);
	ui.lineEdit_dischargeCurrent->setText(capacity);
}

ProtectionParametersDialog::ProtectionParametersDialog(QString testname, int unique_id, QList<int> temp_list, QWidget * parent)
	: QDialog(parent), test_unique_id(unique_id)
{
	ui.setupUi(this);
}

ProtectionParametersDialog::~ProtectionParametersDialog()
{

}

void ProtectionParametersDialog::constructInit()
{
	ui.ModifyBtn->hide();
	ui.SaveBtn->show();
}

void ProtectionParametersDialog::ModifyInit()
{
	ui.ModifyBtn->show();
	ui.SaveBtn->hide();
}

void ProtectionParametersDialog::on_SaveBtn_clicked()
{
	QList<int> infolist;
	infolist.append(m_test_type);
	infolist.append(deal_for_decimal(ui.lineEdit_chargeVoltage->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_chargeCurrent->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_dischargeCurrent->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_total_voltage_overshoot_warning->text()));
<<<<<<< HEAD
=======
	infolist.append(deal_for_decimal(ui.lineEdit_total_voltage_overshoot_protect->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_total_voltage__overshoot_relieve->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_single_voltage_overshoot_warning->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_single_voltage_overshoot_protect->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_single_voltage_overshoot_relieve->text()));
>>>>>>> cbe78ec (2022.1.20 12.45.30)

	constructOrNot = true;
	emit construct_data(ui.lineEdit_testname->text(), "Protection_Parameters" + QString::number(test_unique_id), infolist);
	this->close();
}
void ProtectionParametersDialog::on_ModifyBtn_clicked()
{
	QList<int> infolist;
	infolist.append(m_test_type);
	infolist.append(deal_for_decimal(ui.lineEdit_chargeVoltage->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_chargeCurrent->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_dischargeCurrent->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_total_voltage_overshoot_warning->text()));
<<<<<<< HEAD

=======
	infolist.append(deal_for_decimal(ui.lineEdit_total_voltage_overshoot_protect->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_total_voltage__overshoot_relieve->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_single_voltage_overshoot_warning->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_single_voltage_overshoot_protect->text()));
	infolist.append(deal_for_decimal(ui.lineEdit_single_voltage_overshoot_relieve->text()));
>>>>>>> cbe78ec (2022.1.20 12.45.30)
	emit modify_data(infolist);
	this->close();
}
void ProtectionParametersDialog::on_ReturnBtn_clicked()
{
	this->close();
}

int ProtectionParametersDialog::deal_for_decimal(QString voll)
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

void ProtectionParametersDialog::closeEvent(QCloseEvent * event)
{
	QDialog::closeEvent(event);
	emit returnBefore(constructOrNot);
}

void ProtectionParametersDialog::press_save_btn()
{
	on_SaveBtn_clicked();
}
