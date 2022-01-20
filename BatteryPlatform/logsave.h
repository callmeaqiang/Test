#pragma once

#include <QNetworkDatagram>
#include <QObject>
#include <QTimer>
#include "CustomDataType.h"

class LogSave : public QObject
{
	Q_OBJECT
public:
	explicit LogSave(QObject *parent = Q_NULLPTR);

	void saveLog_zhili(const Data_Zhili data);
	void saveLog_lishen(const Data_lishen data);
	void saveLog_peicheng(const Data_peicheng data);
	void updateSaveState(const bool state, const QString filepath);
	void update_test_name(const QString name, const int state);

	void timer_slot();

signals:

private:
	bool m_startSave{ false };
	QString m_filepath;
	QString m_testname;
	int test_state{ 0 };
	QTimer *timer{ nullptr };
};
