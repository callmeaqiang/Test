#pragma once

#include <QWidget>
#include "ui_selfdefinecheckwidget.h"

class SelfDefineCheckWidget : public QWidget
{
	Q_OBJECT

public:
	SelfDefineCheckWidget(QWidget *parent = Q_NULLPTR);
	~SelfDefineCheckWidget();
	void PushButtonSlot();
	void update_warning_count(const QString data, const int type);
	void decrease_warning_count();
signals:
	void show_warning();
private:
	Ui::SelfDefineCheckWidget ui;
	QString typeName;
	QString infoname;
	int warning_count{ 0 };
};
