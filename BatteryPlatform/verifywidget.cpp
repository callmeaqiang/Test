
#include "verifywidget.h"


VerifyWidget::VerifyWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.pushButton, &QPushButton::clicked, this, &VerifyWidget::returnBtnSlot);
}

VerifyWidget::~VerifyWidget()
{

}

void VerifyWidget::updateCheckInfo(QList<QString> list)
{
	QString tem_str;
	for (int i = 0; i < list.size(); i+=2)
	{
		tem_str = list.at(i) + "        " + list.at(i+1);
		ui.textBrowser->append(tem_str);
	}
	
}


void VerifyWidget::returnBtnSlot()
{
	emit returnHome();
}
