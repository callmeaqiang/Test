#include "dataanalyze.h"
#include <bitset>
#include <QFile>
#include <QCoreApplication>

DataAnalyze::DataAnalyze(QObject *parent) : 
	QObject(parent), readyToRead(false),verifyState(false)
{

}

void DataAnalyze::dataanalyze(const QNetworkDatagram datagram)
{
	if (!readyToRead)
	{
		return;
	}
	QByteArray data = datagram.data();

	if (data.isEmpty())
	{
		return;
	}
	//判断协议类型 再去决定如何解析
	switch (brandPactType)
	{
	case zhili:
		analyzeForPactOne(data);
		break;
	case lishen:
		analyzeForPactTwo(data);
		break;
	case peicheng:
		analyzeForPactThree(data);
		break;
	default:
		break;
	}
}

void DataAnalyze::analyzeForPactOne(QByteArray data)
{
	Data_Zhili value = pact_one.selfInit(data);
	emit analyzeOver_pactOne(value);
	emit test_soc_Value(value.Soc);
	if (verifyState)
	{
		//校验
		verifyState = false;
		VerifyBatteryData(data);
	}
	//检测是否有报警信息
	check_warning_status(value);
}

void DataAnalyze::analyzeForPactTwo(QByteArray data)
{
	Data_lishen value = pact_two.self_Init(data);
	emit analyzeOver_pactTwo(value);
	if (verifyState)
	{
		bool dataValueState = true;
		if (value.voltage > 70 || value.charge_current > 60 || value.discharge_current > 60)
		{
			dataValueState = false;
		}
		VerifyBatteryData(data);
		verifyState = false;
	}
}
void DataAnalyze::analyzeForPactThree(QByteArray data)
{
	if (data.at(0x010C) == 0x01) //代表后半包
	{
		if(is_complete == 0)
		{
			return;
		}
		else
		{
			m_warning = pact_three.alarmData_Init(data);
			//两包组合
			fusion_data(m_value, m_warning);
			is_complete = 0;
		}
	}
	else
	{
		if (is_complete == 1)
		{
			is_complete = 0;
			return;
		}
		else
		{
			m_value = pact_three.simiulateData_Init(data);
			is_complete ++;
		}
	}

	if (verifyState)
	{
		bool dataValueState = true;
		if (m_value.voltage > 70 || m_value.charge_current > 60 || m_value.discharge_current > 60)
		{
			dataValueState = false;
		}
		VerifyBatteryData(data);
		verifyState = false;
	}
}
//--------->>>数据校验
void DataAnalyze::VerifyBatteryData(QByteArray data)
{
	//CRC校验  // 和校验 
	QList<QString> verify_data;
	switch (brandPactType)
	{
	case 1:
	{
		verify_data.append(tr("Data Validation"));
		verify_data.append(" ");
		QByteArray realdata = data.mid(GZ_Net_Header_len, Battery_Data_len);
		//长度校验
		int real_len = realdata.lastIndexOf(0x7E) + 1;
		int pact_len = QByteArray::fromHex(realdata.mid(7, 4)).toHex().toInt(NULL, 16);
		verify_data.append(tr("Len verification of data"));
		if (real_len == pact_len)
		{	
			QString str = tr("The data length check is correct!");
			verify_data.append(str);
		}
		else
		{
			QString str = tr("The data length check is error!");
			verify_data.append(str);
		}

		QByteArray v_Data = realdata.mid(0, realdata.lastIndexOf(0x7E) + 1);
		bool checkSum = pact_one.VerifyData_one(v_Data); //------>>>>和校验
		verify_data.append(tr("Sum verification of data"));
		if (checkSum)
		{
			QString str = tr("The data sum check is correct!");
			verify_data.append(str);
		}
		else
		{
			QString str = tr("The data sum check is error!");
			verify_data.append(str);
		}
		format_verification(v_Data, verify_data);
		emit checked_info(verify_data);
	}
	break;
	case 2:
	{
		bool checkSum = pact_two.VerifyData_two(data);
	}
	break;
	case 3:
	{
		bool checkSum = pact_three.VerifyData_three(data);
	}
	break;
	default:
		break;
	}

	//数据校验
}

void DataAnalyze::updateBrandTypePact(const int brand, const int cap)
{
	this->brandPactType = brand;
	is_complete = 0;
}

void DataAnalyze::updateAnalyzeAuthority(bool val)
{
	this->readyToRead = val;
}

void DataAnalyze::updateVerifyState(bool val)
{
	this->verifyState = val;
}

void DataAnalyze::check_warning_status(Data_Zhili data)
{

}

void DataAnalyze::format_verification(QByteArray &data, QList<QString> &list)
{
	QString result_str1, result_str2;
	int _offset_ = 0;
	result_str1 = QString(data.mid(_offset_, 1));
	result_str2 = "//SOI";
	list.append(result_str1);
	list.append(result_str2);
	_offset_ += 1;

	result_str1 = QString(data.mid(_offset_, 2));
	result_str2 = "//Addr";
	list.append(result_str1);
	list.append(result_str2);
	_offset_ += 2;

	result_str1 = QString(data.mid(_offset_, 2));
	result_str2 =  "//Cmd";
	list.append(result_str1);
	list.append(result_str2);
	_offset_ += 2;

	result_str1 = QString(data.mid(_offset_, 2));
	result_str2 = "//Ver";
	list.append(result_str1);
	list.append(result_str2);
	_offset_ += 2;

	result_str1 = QString(data.mid(_offset_, 4));
	result_str2 = "//Len = ";
	int _len_t = QByteArray::fromHex(data.mid(_offset_, 4)).toHex().toInt(NULL, 16);
	result_str2 += QString::number(_len_t);
	list.append(result_str1);
	list.append(result_str2);
	_offset_ += 4;

	result_str1 = QString(data.mid(_offset_, 14));
	result_str2 = "//Time";
	list.append(result_str1);
	list.append(result_str2);
	_offset_ += 14;

	result_str1 = QString(data.mid(_offset_, 4));
	result_str2 = "//Voltage = ";
	float _VBat_t = (float)QByteArray::fromHex(data.mid(_offset_, 4)).toHex().toInt(NULL, 16)/500; //电压须乘2
	result_str2 += QString("%1").arg(_VBat_t, 0, 'f', 3);
	list.append(result_str1);
	list.append(result_str2);
	_offset_ += 4;

	result_str1 = QString(data.mid(_offset_, 2));
	result_str2 = "//Vcell_num = ";
	int _Vcell_num_t = QByteArray::fromHex(data.mid(_offset_, 2)).toHex().toInt(NULL, 16);
	if (_Vcell_num_t >= 1 && _Vcell_num_t <= 16)
	{
		result_str2 += QString::number(_Vcell_num_t) + "         " + "right";
	}
	else
	{
		result_str2 += QString::number(_Vcell_num_t) + "         " +  "error";
	}
	list.append(result_str1);
	list.append(result_str2);
	_offset_ += 2;

	float normal_cell_v = _VBat_t / _Vcell_num_t;  //电芯电压判断基准
	for (int i = 0; i < _Vcell_num_t; i ++)
	{
		result_str1 = QString(data.mid(_offset_, 4));
		float _Vcell_t = (float)QByteArray::fromHex(data.mid(_offset_, 4)).toHex().toInt(NULL, 16)/1000;
		QString str_t_ = "Vcell_num[" + QString("%1] = ").arg(i);
		if (fabs(_Vcell_t - normal_cell_v)/ normal_cell_v < 0.05)
		{
			result_str2 = "//" + str_t_ + QString("%1         ").arg(_Vcell_t, 0, 'f', 3) + "right";
		}
		else
		{
			result_str2 = "//" + str_t_ + QString("%1         ").arg(_Vcell_t, 0, 'f', 3) + "error";
		}
		list.append(result_str1);
		list.append(result_str2);
		_offset_ += 4;
	}
	
	result_str1 = QString(data.mid(_offset_, 4));
	result_str2 = "//Curr[0] = ";
	int _Curr0_t = QByteArray::fromHex(data.mid(_offset_, 4)).toHex().toInt(NULL, 16);
	result_str2 += QString("%1").arg(_Curr0_t);
	list.append(result_str1);
	list.append(result_str2);
	_offset_ += 4;

	result_str1 = QString(data.mid(_offset_, 4));
	result_str2 = "//Curr[1] = ";
	int _Curr1_t = QByteArray::fromHex(data.mid(_offset_, 4)).toHex().toInt(NULL, 16);
	result_str2 += QString("%1").arg(_Curr1_t);
	list.append(result_str1);
	list.append(result_str2);
	_offset_ += 4;

	result_str1 = QString(data.mid(_offset_, 2));
	result_str2 = "//TempNum = ";
	int _Tempnum_t = QByteArray::fromHex(data.mid(_offset_, 2)).toHex().toInt(NULL, 16);
	if (_Tempnum_t >=1 && _Tempnum_t <= 8)
	{
		result_str2 += QString::number(_Tempnum_t)+ "         " + "right";
	}
	else
	{
		result_str2 += QString::number(_Tempnum_t) + "         "  + "error";
	}
	list.append(result_str1);
	list.append(result_str2);
	_offset_ += 2;

	for (int i = 0; i < _Tempnum_t; i++)
	{
		result_str1 = QString(data.mid(_offset_, 2));
		int _Tempnum_t = QByteArray::fromHex(data.mid(_offset_, 2)).toHex().toInt(NULL, 16) - 40;
		QString str_t_ = "TempVal[" + QString("%1] = ").arg(i);
		if (_Tempnum_t >= -20 && _Tempnum_t <= 50)
		{
			result_str2 = "//" + QString("%1         ").arg(_Tempnum_t) + "right";
		}
		else
		{
			result_str2 = "//" + QString("%1         ").arg(_Tempnum_t) + "error";
		}
		list.append(result_str1);
		list.append(result_str2);
		_offset_ += 2;
	}
	result_str1 = QString(data.mid(_offset_, 4));
	result_str2 = "//VState";
	list.append(result_str1);
	list.append(result_str2);
	_offset_ += 4;
	result_str1 = QString(data.mid(_offset_, 4));
	result_str2 ="//CState";
	list.append(result_str1);
	list.append(result_str2);
	_offset_ += 4;
	result_str1 = QString(data.mid(_offset_, 4));
	result_str2 = "//TState";
	list.append(result_str1);
	list.append(result_str2);
	_offset_ += 4;
	result_str1 = QString(data.mid(_offset_, 4));
	result_str2 = "//Alarm";
	list.append(result_str1);
	list.append(result_str2);
	_offset_ += 4;
	result_str1 = QString(data.mid(_offset_, 2));
	result_str2 = "//FETState";
	list.append(result_str1);
	list.append(result_str2);
	_offset_ += 2;
	result_str1 = QString(data.mid(_offset_, 4));
	result_str2 = "//NUM_VOV";
	list.append(result_str1);
	list.append(result_str2);
	_offset_ += 4;
	result_str1 = QString(data.mid(_offset_, 4));
	result_str2 ="//NUM_VUV";
	list.append(result_str1);
	list.append(result_str2);
	_offset_ += 4;
	result_str1 = QString(data.mid(_offset_, 4));
	result_str2 = "//NUM_WARN_VHIGH";
	list.append(result_str1);
	list.append(result_str2);
	_offset_ += 4;
	result_str1 = QString(data.mid(_offset_, 4));
	result_str2 = "//NUM_WARN_VLOW";
	list.append(result_str1);
	list.append(result_str2);
	_offset_ += 4;
	result_str1 = QString(data.mid(_offset_, 4));
	result_str2 = "//Blance State";
	list.append(result_str1);
	list.append(result_str2);
	_offset_ += 4;
	result_str1 = QString(data.mid(_offset_, 4));
	result_str2 = "//Dchg Num";
	list.append(result_str1);
	list.append(result_str2);
	_offset_ += 4;
	result_str1 = QString(data.mid(_offset_, 4));
	result_str2 = "//Chg Num";
	list.append(result_str1);
	list.append(result_str2);
	_offset_ += 4;

	result_str1 = QString(data.mid(_offset_, 2));
	result_str2 = "//Soc = ";
	int _soc_t = QByteArray::fromHex(data.mid(_offset_, 2)).toHex().toInt(NULL, 16);
	if (_soc_t>= 0 && _soc_t<= 100)
	{
		result_str2 += QString::number(_soc_t) + "         " + "right";
	}
	else
	{
		result_str2 += QString::number(_soc_t) + "         " + "error";
	}
	list.append(result_str1);
	list.append(result_str2);
	_offset_ += 2;

	result_str1 = QString(data.mid(_offset_, 4));
	result_str2 = "//CapNow = ";
	int _CapNow_t = QByteArray::fromHex(data.mid(_offset_, 4)).toHex().toInt(NULL, 16);
	result_str2 += QString::number(_CapNow_t);
	list.append(result_str1);
	list.append(result_str2);
	_offset_ += 4;

	result_str1 = QString(data.mid(_offset_, 4));
	result_str2 = "//CapFul = ";
	int _CapFul_t = QByteArray::fromHex(data.mid(_offset_, 4)).toHex().toInt(NULL, 16);
	result_str2 += QString::number(_CapFul_t);
	list.append(result_str1);
	list.append(result_str2);
	_offset_ += 4;

	result_str1 = QString(data.mid(_offset_, 2));
	result_str2 = "//CRC";
	list.append(result_str1);
	list.append(result_str2);
	_offset_ += 2;
	result_str1 = QString(data.mid(_offset_, 1));
	result_str2 = "//EOI";
	list.append(result_str1);
	list.append(result_str2);
}


Data_peicheng_Total DataAnalyze::fusion_data(Data_peicheng data, Data_peicheng_warning waning)
{
	//沛城数据，模拟量和警告量进行组合
	Data_peicheng_Total data_total;
	data_total.cellNum = data.cellNum;
	data_total.tempretureNum = data.tempretureNum;
	data_total.fullCapicity = data.cellNum;
	data_total.now_capicity = data.cellNum;
	data_total.cycleCount = data.cellNum;
	data_total.Soc = data.cellNum;
	data_total.voltage = data.cellNum;
	data_total.charge_current = data.cellNum;
	data_total.discharge_current = data.discharge_current;
	data_total.dischargeCycle = data.discharge_current;
	data_total.designCapicity = data.designCapicity;
	data_total.cellVoltageList = data.cellVoltageList;
	data_total.tempList = data.tempList;
	data_total.chargeCurrent_warning = waning.chargeCurrent_warning;
	data_total.voltage_warning = waning.voltage_warning;
	data_total.dischargeCurrent_warning = waning.dischargeCurrent_warning;
	data_total.protectState1 = waning.protectState1;
	data_total.protectState2 = waning.protectState2;
	data_total.instructorState = waning.instructorState;
	data_total.controllState = waning.controllState;
	data_total.malfunctionState = waning.malfunctionState;
	data_total.balanceState1 = waning.balanceState1;
	data_total.balanceState2 = waning.balanceState2;
	data_total.alarmState1 = waning.alarmState1;
	data_total.alarmState2 = waning.alarmState2;
	data_total.cellVoltage_WarningList = waning.cellVoltage_WarningList;
	data_total.temp_warningList = waning.temp_warningList;

	return data_total;
}
