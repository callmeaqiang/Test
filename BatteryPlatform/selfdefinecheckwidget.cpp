#include "selfdefinecheckwidget.h"

SelfDefineCheckWidget::SelfDefineCheckWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, &QPushButton::clicked, this, &SelfDefineCheckWidget::PushButtonSlot);
}

SelfDefineCheckWidget::~SelfDefineCheckWidget()
{

}

void SelfDefineCheckWidget::PushButtonSlot()
{
	emit show_warning();
}

void SelfDefineCheckWidget::update_warning_count(const QString data, const int type)
{
	this->warning_count++;
	ui.label_warning->setText(QString::number(warning_count));	
}

void SelfDefineCheckWidget::decrease_warning_count()
{
	this->warning_count--;
	ui.label_warning->setText(QString::number(warning_count));
}
