#include "batterywarnningdialog.h"
#include <QDateTime>
#include <QLabel>
#include <QTableWidgetItem>
#include <QPushButton>

BatteryWarnningDialog::BatteryWarnningDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	init_tableWidget();
}

BatteryWarnningDialog::~BatteryWarnningDialog()
{

}

void BatteryWarnningDialog::init_tableWidget()
{
	QStringList header1, header2;
	header1 << tr("Time") << tr("Type") << tr("Data") << tr("Treate");
	header2 << tr("Time") << tr("Type") << tr("Data");
	ui.tableWidget->setColumnCount(4);
	ui.tableWidget_2->setColumnCount(3);
	ui.tableWidget->setColumnWidth(0, 200);
	ui.tableWidget->setColumnWidth(1, 100);
	ui.tableWidget->setColumnWidth(2, 200);
	ui.tableWidget->setHorizontalHeaderLabels(header1);
	ui.tableWidget_2->setHorizontalHeaderLabels(header2);
	ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
	ui.tableWidget_2->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
	ui.tableWidget->verticalHeader()->hide();
	ui.tableWidget_2->verticalHeader()->hide();
}

void BatteryWarnningDialog::transport_waring()
{
	QPushButton *btn = qobject_cast<QPushButton*>(sender());
	for (int i = 0; i < ui.tableWidget->rowCount(); i++)
	{	
		if (ui.tableWidget->cellWidget(i, 3)->whatsThis() == btn->whatsThis())
		{
			btn->setText(tr("Processed"));
			int row_count = ui.tableWidget_2->rowCount();
			ui.tableWidget_2->insertRow(row_count);
			ui.tableWidget_2->setRowHeight(row_count, 50);
			QTableWidgetItem *item1 = new QTableWidgetItem(ui.tableWidget->item(i, 0)->text());
			QTableWidgetItem *item2 = new QTableWidgetItem(ui.tableWidget->item(i, 1)->text());
			QTableWidgetItem *item3 = new QTableWidgetItem(ui.tableWidget->item(i, 2)->text());
			ui.tableWidget_2->setItem(row_count, 0, item1);
			ui.tableWidget_2->setItem(row_count, 1, item2);
			ui.tableWidget_2->setItem(row_count, 2, item3);
			ui.tableWidget->removeRow(i);
			emit decrease_warningCount();
			return;
		}
	}

}

void BatteryWarnningDialog::interpolate_warning(const QString data, const int type)
{
	QDateTime current_date_time = QDateTime::currentDateTime();
	QString current_date = current_date_time.toString("yyyy.MM.dd hh:mm:ss");
	QString data_type;
	switch (type)
	{
	case 0:
		data_type = tr("Information");
		break;
	case 1:
		data_type = tr("Warning");
		break;
	case 2:
		data_type = tr("Error");
		break;
	default:
		break;
	}

	int row_count = ui.tableWidget->rowCount();
	ui.tableWidget->insertRow(row_count);
	ui.tableWidget->setRowHeight(row_count, 50);
	QTableWidgetItem *item1 = new QTableWidgetItem(current_date);
	QTableWidgetItem *item2 = new QTableWidgetItem(data_type);
	QTableWidgetItem *item3 = new QTableWidgetItem(data);

	QPushButton *btn = new QPushButton(tr("Untreated"));
	connect(btn, &QPushButton::clicked, this, &BatteryWarnningDialog::transport_waring);
	btn->setWhatsThis("Warning" + QString::number(m_warning_count));
	ui.tableWidget->setItem(row_count, 0, item1);
	ui.tableWidget->setItem(row_count, 1, item2);
	ui.tableWidget->setItem(row_count, 2, item3);
	ui.tableWidget->setCellWidget(row_count, 3, btn);

	m_warning_count++;
}

void BatteryWarnningDialog::on_pushButton_DealAll_clicked()
{
	if (ui.tableWidget->rowCount() == 0)
	{
		return;
	}
	for (int i = ui.tableWidget->rowCount() -1; i >= 0 ; i--)
	{
		int row_count = ui.tableWidget_2->rowCount();
		ui.tableWidget_2->insertRow(row_count);
		ui.tableWidget_2->setRowHeight(row_count, 50);
		QTableWidgetItem *item1 = new QTableWidgetItem(ui.tableWidget->item(i, 0)->text());
		QTableWidgetItem *item2 = new QTableWidgetItem(ui.tableWidget->item(i, 1)->text());
		QTableWidgetItem *item3 = new QTableWidgetItem(ui.tableWidget->item(i, 2)->text());
		ui.tableWidget_2->setItem(row_count, 0, item1);
		ui.tableWidget_2->setItem(row_count, 1, item2);
		ui.tableWidget_2->setItem(row_count, 2, item3);
		ui.tableWidget->removeRow(i);
		emit decrease_warningCount();
	}
}
