#pragma once

#include <QDialog>
#include "ui_message_box.h"

class Message_Box : public QDialog
{
	Q_OBJECT

public:
	Message_Box(QString data, int type, QWidget *parent = Q_NULLPTR);
	~Message_Box();

	bool get_accept_status() { return is_accept; }
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

private slots:
	void on_pushButton_accept_clicked();
	void on_pushButton_cancel_clicked();
	void on_pushButton_close_clicked();

private:
	Ui::Message_Box ui;
	int m_type{ 0 }; // 0 Ã·–—°¢ 1 æØ∏Ê°¢ 2 ¥ÌŒÛ
	bool is_accept{ false };

	QPoint m_z;
	QPoint press_point;
	bool is_intitle{ false };
	bool is_press{ false };
};
