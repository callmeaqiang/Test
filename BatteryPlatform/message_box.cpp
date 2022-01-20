#include "message_box.h"
#include <QMouseEvent>
#include <QPixmap>
#include "qwindowdefs_win.h"

Message_Box::Message_Box(QString data, int type, QWidget *parent)
	: QDialog(parent), m_type(type)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	this->resize(400, 240);
	ui.label_icon->setScaledContents(true);

	switch (m_type)
	{
	case 0:
		ui.label_icon->setPixmap(QPixmap(":/res/res/information.png"));
		ui.label_Title->setText(tr("information"));
		break;
	case 1:
		ui.label_icon->setPixmap(QPixmap(":/res/res/warning.png"));
		ui.label_Title->setText(tr("warning"));
		break;
	case 2:
		ui.label_icon->setPixmap(QPixmap(":/res/res/default.png"));
		ui.label_Title->setText(tr("error"));
		break;

	default:
		break;
	}
	ui.Edit_information->setText(data);
}

Message_Box::~Message_Box()
{
}

void Message_Box::mousePressEvent(QMouseEvent * event)
{
	QPoint y = event->globalPos();
	QPoint x = this->geometry().topLeft();
	m_z = y - x;
	if (ui.widget->geometry().contains(event->pos()))
	{
		is_intitle = true;
	}
	is_press = true;
}

void Message_Box::mouseMoveEvent(QMouseEvent * event)
{
	if (is_intitle)
	{
		QPoint y = event->globalPos();
		QPoint z = y - m_z;
		this->move(z);
	}
}

void Message_Box::mouseReleaseEvent(QMouseEvent * event)
{
	is_press = false;
}


void Message_Box::on_pushButton_cancel_clicked()
{
	is_accept = false;
	this->close();
}

void Message_Box::on_pushButton_accept_clicked()
{
	is_accept = true;
	this->close();
}
void Message_Box::on_pushButton_close_clicked()
{
	is_accept = false;
	this->close();
}
