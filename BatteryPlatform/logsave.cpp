#include "logsave.h"
#include <QCoreApplication>
#include <QFile>
#include <QDir>
#include "qmath.h"
#include "QTimer"

LogSave::LogSave(QObject *parent) : QObject(parent), timer(new QTimer(this))
{
	connect(timer, &QTimer::timeout, this, &LogSave::timer_slot);
}

void LogSave::saveLog_zhili(const Data_Zhili data)
{
	if (!m_startSave)
	{
		return;
	}
	QByteArray datatime = QDateTime::currentDateTime().toString("yyyy.MM.dd hh.mm.ss").toUtf8();
	QByteArray  header = QByteArray("<") + datatime + QByteArray("> (") + m_testname.toUtf8() + QByteArray(")\r\n");// 2021 - 09-08 17:48 : 09.728

	//第一行尽量是单个信息
	QByteArray FirstLine = QByteArray("voltage=") + QByteArray::number((int)(data.voltage * 1000)) + QByteArray(",")
		+ QByteArray("charge_current=") + QByteArray::number((int)(data.charge_current * 1000)) + QByteArray(",")
		+ QByteArray("discharge_current=") + QByteArray::number((int)(data.discharge_current * 1000)) + QByteArray(",")
		+ QByteArray("ChgNum=") + QByteArray::number(data.ChgNum) + QByteArray(",")
		+ QByteArray("DchgNum=") + QByteArray::number(data.DchgNum) + QByteArray(",")
		+ QByteArray("Soc=") + QByteArray::number(data.Soc) + QByteArray(",")
		+ QByteArray("CapNow=") + QByteArray::number(data.CapNow * 10) + QByteArray(",")
		+ QByteArray("CapFull=") + QByteArray::number(data.CapFull * 10) + QByteArray(",\r\n");
	//第二行为电池电芯串信息
	QByteArray SecondLine = QByteArray("cell_voltage:");
	for (int i = 0; i < data.Vcell_num; i++)
	{
		SecondLine += QByteArray::number((int)(data.Vcell_list.at(i) * 1000)) + QByteArray(",");
	}
	SecondLine += QByteArray("\r\n");
	//第三行填写状态位
	QByteArray ThirdLine = QByteArray("VState=") + QByteArray::number(data.vstate_list)+ QByteArray(",")
		+ QByteArray("CState=") + QByteArray::number(data.cstate_list) + QByteArray(",")
		+ QByteArray("TState=") + QByteArray::number(data.tstate_list) + QByteArray(",")
		+ QByteArray("Alarm=") + QByteArray::number(data.alarm_list) + QByteArray(",")
		+ QByteArray("FETState=") + QByteArray::number(data.fetstate_list) + QByteArray(",")
		+ QByteArray("NUM_VOV=") + QByteArray::number(data.fetstate_list) + QByteArray(",")
		+ QByteArray("NUM_VUV=") + QByteArray::number(data.fetstate_list) + QByteArray(",")
		+ QByteArray("NUM_WARN_VHIGH=") + QByteArray::number(data.fetstate_list) + QByteArray(",")
		+ QByteArray("NUM_WARN_VLOW=") + QByteArray::number(data.fetstate_list) + QByteArray(",")
		+ QByteArray("BlanceState=") + QByteArray::number(data.fetstate_list) + QByteArray(",\r\n");
	//第四行填写 温度 智锂温度为整数
	QByteArray FourLine = QByteArray("temperature:");
	for (int i = 0; i < data.Temp_Num; i++)
	{
		FourLine += QByteArray::number(data.temp_list.at(i)) + QByteArray(",");
	}
	FourLine += QByteArray("\r\n");

	QByteArray FiveLine = QByteArray("Battery_Voltage_Measured=") + QByteArray::number((int)(data.Battery_Voltage_Measured *1000)) + QByteArray(",")
		+ QByteArray("Charging_Current_Measured=")+ QByteArray::number((int)(data.Charging_Current_Measured* 1000)) + QByteArray(",")
		+ QByteArray("PSD1_Current_Measured=") + QByteArray::number((int)(data.PSD1_Current_Measured * 1000)) + QByteArray(",\r\n");

	QByteArray total_data =header + FirstLine + SecondLine + ThirdLine + FourLine + FiveLine;
	QDir dir(QString("%1/log").arg(m_filepath));
	if (!dir.exists())
	{
		dir.mkpath(QString("%1/log").arg(m_filepath));
	}
	QString filepath = QString("%1/log").arg(m_filepath);
	//获取系统当前时间
	QDateTime time = QDateTime::currentDateTime();
	QString formaldate = time.toString("yyyy.MM.dd_hh.mm.ss"); //年月日

	if (dir.isEmpty())
	{
		QFile file(QString("%1/(%2).log").arg(filepath).arg(formaldate));

		bool isOk = file.open(QIODevice::WriteOnly | QIODevice::Append);
		if (!isOk)
		{
			qDebug() << " file open failed1" << endl;
			return;
		}
		file.write(total_data);
		file.write("\r\n");
		file.close();
	}
	else
	{
		QStringList datafilter;
		datafilter << "*.log";
		dir.setSorting(QDir::Time);
		QFileInfoList infolist = dir.entryInfoList(datafilter, QDir::Files);

		QString oldstr = infolist.at(0).fileName().mid(1, 19);
		QDateTime oldtime = QDateTime::fromString(oldstr, "yyyy.MM.dd_hh.mm.ss");

		if (oldtime.secsTo(time) >= 24 * 3600)
		{
			QFile file(QString("%1/(%2).log").arg(filepath).arg(formaldate));
			bool isOk = file.open(QIODevice::WriteOnly | QIODevice::Append);
			if (!isOk)
			{
				qDebug() << " file open failed2" << endl;
				return;
			}
			file.write(total_data);
			file.write("\r\n");
			file.close();
		}
		else
		{
			QFile file(infolist.at(0).absoluteFilePath());
			bool isOk = file.open(QIODevice::WriteOnly | QIODevice::Append);
			if (!isOk)
			{
				qDebug() << " file open failed3" << endl;
				return;
			}
			file.write(total_data);
			file.write("\r\n");
			file.close();
		}

	}
}

void LogSave::saveLog_lishen(const Data_lishen data)
{
	if (!m_startSave)
	{
		return;
	}
	QByteArray  header = QByteArray("<") + QByteArray("><SaveLog>:<IEC>");// 2021 - 09-08 17:48 : 09.728
	QByteArray datetime = QDateTime::currentDateTime().toString("yyyy.MM.dd hh.mm.ss").toUtf8();
	QByteArray FirstLine = header + datetime + QByteArray("  Voltage=") + QByteArray::number((int)(data.voltage * 2 * 1000)) + QByteArray(",")
		+ QByteArray("Charge_current=") + QByteArray::number((int)(data.charge_current * 10)) + QByteArray(",")
		+ QByteArray("Discharge_current=") + QByteArray::number((int)(data.discharge_current * 10)) + QByteArray(",")
		+ QByteArray("Cycle=") + QByteArray::number(data.cycleCount) + QByteArray(",")
		+ QByteArray("Soc=") + QByteArray::number((int)data.Soc * 10 ) + QByteArray(",")
		+ QByteArray("now_capicity=") + QByteArray::number((int)(data.now_capicity * 10000)) + QByteArray(",")
		+ QByteArray("designeCapicity=") + QByteArray::number((int)(data.designeCapicity * 10000)) + QByteArray(",");

	QByteArray SecondLine = header + datetime + QByteArray("  cell_voltage:");
	for (int i = 0; i < 16 ; i++)
	{
		SecondLine += QByteArray::number((int)data.cellVoltageList.at(i) * 1000) + QByteArray(",");
	}
	//cell_max_v=3152,cell_min_v=3132
	QByteArray ThirdLine = header + datetime + QByteArray("  cell_max_v=") + QByteArray::number((int)data.max_cellvoltage * 1000) + QByteArray(",")
		+ QByteArray("cell_min_v=") + QByteArray::number((int)data.min_cellvoltage * 1000) + QByteArray(",")
		+ QByteArray("batteryState=") + QByteArray::number(data.batteryState) + QByteArray(",")
		+ QByteArray("alarm1=") + QByteArray::number(data.warning_1) + QByteArray(",")
		+ QByteArray("alarm2=") + QByteArray::number(data.warning_2) + QByteArray(",")
		+ QByteArray("alarm3=") + QByteArray::number(data.warning_3) + QByteArray(",")
		+ QByteArray("alarm4=") + QByteArray::number(data.warning_4) + QByteArray(",");

	QByteArray FourLine = header + datetime + QByteArray("  temperature:");
	for (int i = 0; i < 4; i++)
	{
		FourLine += QByteArray::number((int)data.tempList.at(i) * 10);
	}

	QFile file(m_filepath + "/" + "lishen.log");
	bool st = file.open(QIODevice::WriteOnly | QIODevice::Append);
	file.write(FirstLine);
	file.write("\r\n");
	file.write(SecondLine);
	file.write("\r\n");
	file.write(ThirdLine);
	file.write("\r\n");
	file.write(FourLine);
	file.write("\r\n");
	file.write("\r\n");
	file.close();


}

void LogSave::saveLog_peicheng(const Data_peicheng data)
{

}

void LogSave::updateSaveState(const bool state, const QString filepath)
{
	this->m_startSave = state;
	this->m_filepath = filepath;
}

void LogSave::update_test_name(const QString name, const int state)
{
	m_testname = name;
	test_state = state;
	if (test_state == 1)
	{		
		timer->start(500);
	}
	else if (test_state == 2)
	{
		timer->start(15000);
	}	
}

void LogSave::timer_slot()
{
	timer->stop();
	if (test_state == 1)
	{
		m_testname = m_testname.mid(0, m_testname.indexOf("start"));
	}
	else if(test_state == 2)
	{
		m_testname = m_testname.mid(0, m_testname.indexOf("idle"));
	}
}

