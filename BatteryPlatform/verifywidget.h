#pragma once

#include <QWidget>
#include "ui_verifywidget.h"

class VerifyWidget : public QWidget
{
	Q_OBJECT

public:
	VerifyWidget(QWidget *parent = Q_NULLPTR);
	~VerifyWidget();

	void updateCheckInfo(QList<QString> list);
	void returnBtnSlot();
signals:
	void returnHome();
private:
	Ui::VerifyWidget ui;
};
