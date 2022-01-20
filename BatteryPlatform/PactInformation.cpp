#include "PactInformation.h"
#include <QtMath>
#include <QFile>
#include "QCoreApplication"


PactInformation::PactInformation()
{
}


PactInformation::~PactInformation()
{
}

PactOne::PactOne()
{
}

Data_Zhili PactOne::selfInit(const QByteArray data)
{
	////数据开辟对应的大小
	int battery_offset = 0, psd_offset = 0;
	battery_offset = GZ_Net_Header_len + 11; //电池数据 index = 11 后 才是所需数据 

	//对bytearray 进行填值
	this->m_time = data.mid(battery_offset, 14);
	battery_offset += 14;
	this->m_Vbat = data.mid(battery_offset, 4);
	battery_offset += 4;
	this->m_Vcell_Num = data.mid(battery_offset, 2);
	battery_offset += 2;
	this->m_Vcell = data.mid(battery_offset, 4 * serilizeInit(m_Vcell_Num));
	battery_offset += m_Vcell.size();
	this->m_Curr = data.mid(battery_offset, 8);
	battery_offset += 8;
	this->m_TempNum = data.mid(battery_offset, 2);
	battery_offset += 2;
	this->m_Temp = data.mid(battery_offset, 2 * serilizeInit(m_TempNum));
	battery_offset += m_Temp.size();
	this->m_VState = data.mid(battery_offset, 4);
	battery_offset += 4;
	this->m_CState = data.mid(battery_offset, 4);
	battery_offset += 4;
	this->m_TState = data.mid(battery_offset, 4);
	battery_offset += 4;
	this->m_Alarm = data.mid(battery_offset, 4);
	battery_offset += 4;
	this->m_FETState = data.mid(battery_offset, 2);
	battery_offset += 2;
	this->m_NUM_VOV = data.mid(battery_offset, 4);
	battery_offset += 4;
	this->m_NUM_VUV = data.mid(battery_offset, 4);
	battery_offset += 4;
	this->m_NUM_WARN_VHIGH = data.mid(battery_offset, 4);
	battery_offset += 4;
	this->m_NUM_WARN_VLOW = data.mid(battery_offset, 4);
	battery_offset += 4;
	this->m_BlanceState = data.mid(battery_offset, 4);
	battery_offset += 4;
	this->m_DchgNum = data.mid(battery_offset, 4);
	battery_offset += 4;
	this->m_ChgNum = data.mid(battery_offset, 4);
	battery_offset += 4;
	this->m_SOC = data.mid(battery_offset, 2);
	battery_offset += 2;
	this->m_CapNow = data.mid(battery_offset, 4);
	battery_offset += 4;
	this->m_CapFull = data.mid(battery_offset, 4);
	battery_offset += 4;


	//psd测量值	int Charger_Enable;
	psd_offset += GZ_Net_Header_len + Battery_Data_len; //跳过batterydata区
	psd_offset += 16;  //跳过上传参数
	this->Charger_Voltage_feedback = data.mid(psd_offset, 4);
	psd_offset += 4;
	this->Charger_Current_feedback = data.mid(psd_offset, 4);
	psd_offset += 4;
	this->Charger_Status = data.mid(psd_offset, 4);
	psd_offset += 4;
	this->Battery_Voltage_Measured = data.mid(psd_offset, 4);
	psd_offset += 4;
	this->Charging_Current_Measured = data.mid(psd_offset, 4);
	psd_offset += 4;
	this->PSD1_Temperature = data.mid(psd_offset, 2);
	psd_offset += 2;
	this->PSD2_Temperature = data.mid(psd_offset, 2);
	psd_offset += 2;
	this->PSD1_Current_Measured = data.mid(psd_offset, 4);
	psd_offset += 4;
	this->PSD2_Current_Measured = data.mid(psd_offset, 4);
	psd_offset += 4;

	//将数据转成十进制，然后传递出去；
	Data_Zhili data_z;

	for (int i = 0; i < 7; i++)
	{
		if (i == 3)
		{
			continue;
		}
		data_z.time.append(serilizeInit(m_time.mid(i * 2, 2)));
	}
	data_z.voltage = (float)serilizeInit(m_Vbat) / 500 ;
	data_z.Vcell_num = serilizeInit(m_Vcell_Num);
	float max_cell_v = 0;
	for (int i = 0; i < data_z.Vcell_num; i++)
	{
		float cell_vv = (float)serilizeInit(m_Vcell.mid(i * 4, 4)) / 1000;
		if (cell_vv > max_cell_v)
		{
			max_cell_v = cell_vv;
		}
		data_z.Vcell_list.append(cell_vv);
	}
	data_z.max_cell_voltage = max_cell_v;
	data_z.charge_current = (float)serilizeInit(m_Curr.mid(0, 4))/ 100;
	data_z.discharge_current = (float)serilizeInit(m_Curr.mid(4, 4))/ 100;
	data_z.Temp_Num = serilizeInit(m_TempNum);
	int max_temper = 0;
	for (int j = 0; j < data_z.Temp_Num; j++)
	{
		int tempe_t = serilizeInit(m_Temp.mid(j * 2, 2)) - 40;
		data_z.temp_list.append(tempe_t);
		if (j >0)
		{
			if (max_temper < tempe_t)
			{
				max_temper = tempe_t;
			}
		}

	}
	data_z.max_temperature = max_temper;
	data_z.vstate_list = serilizeInit(m_VState);
	data_z.cstate_list = serilizeInit(m_CState);
	data_z.tstate_list = serilizeInit(m_TState);
	data_z.alarm_list = serilizeInit(m_Alarm);
	data_z.fetstate_list = serilizeInit(m_FETState);
	data_z.NUM_VOV = (float)serilizeInit(m_NUM_VOV);
	data_z.NUM_VUV = (float)serilizeInit(m_NUM_VUV);
	data_z.NUM_WARN_VHIGH = serilizeInit(m_NUM_WARN_VHIGH);
	data_z.NUM_WARN_VLOW = serilizeInit(m_NUM_WARN_VLOW);
	data_z.BlanceState = serilizeInit(m_BlanceState);
	data_z.DchgNum =serilizeInit(m_DchgNum);
	data_z.ChgNum = serilizeInit(m_ChgNum);
	data_z.Soc = serilizeInit(m_SOC);
	data_z.CapNow = (float)serilizeInit(m_CapNow) / 10;
	data_z.CapFull = (float)serilizeInit(m_CapFull) / 10;

	data_z.Charger_Voltage = (float)HighTurnToLower(Charger_Voltage_feedback).toHex().toInt(NULL, 16)/ 1000;
	data_z.Charger_Current = (float)HighTurnToLower(Charger_Current_feedback).toHex().toInt(NULL, 16) / 1000;
	data_z.Charger_Status = HighTurnToLower(Charger_Status).toHex().toInt(NULL, 16);
	data_z.Battery_Voltage_Measured = (float)HighTurnToLower(Battery_Voltage_Measured).toHex().toInt(NULL, 16) / 1000;
	data_z.Charging_Current_Measured = (float)HighTurnToLower(Charging_Current_Measured).toHex().toInt(NULL, 16) / 1000;
	data_z.PSD1_Temperature = HighTurnToLower(PSD1_Temperature).toHex().toInt(NULL, 16); // 正负值
	data_z.PSD2_Temperature = HighTurnToLower(PSD2_Temperature).toHex().toInt(NULL, 16); // 正负值
	data_z.PSD1_Current_Measured = (float)HighTurnToLower(PSD1_Current_Measured).toHex().toInt(NULL, 16) / 1000;
	data_z.PSD2_Current_Measured = (float)HighTurnToLower(PSD2_Current_Measured).toHex().toInt(NULL, 16)/ 1000;
	//最后是CRC校验，但是要看使用者是否需要校验 1字节-》2个字节
	if (data_z.discharge_current > 50)
	{
		QString filepath = QCoreApplication::applicationDirPath() + "/123_test.log";
		QFile file(filepath);
		file.open(QIODevice::WriteOnly | QIODevice::Append);
		file.write(data);
		file.write("\r\n");
		file.close();
	}
	return data_z;
}

int PactOne::serilizeInit(const QByteArray array)
{
	int atu = QByteArray::fromHex(array).toHex().toInt(NULL, 16);
	return atu;
}

QByteArray PactOne::HighTurnToLower(const QByteArray data)
{

	QByteArray arr;
	for (int i = data.size() - 1; i >= 0; i --)
	{
		arr.append(data.at(i));
	}
	return arr;

}

int PactOne::dealForComplememt(const QByteArray data)
{
	int temp_num = serilizeInit(data);
	int val[16] = { 0 };

	for (int j = 15; j >= 0; j--)
	{
		if (temp_num == 0)
		{
			break;
		}
		else
		{
			val[j] = temp_num % 2;
			temp_num /= 2;
		}
	}
	//负数还是正数 状态
	bool iszOrf = false;
	if (val[0] == 0)
	{
		iszOrf = true;
	}

	if (iszOrf)
	{
		return temp_num;
	}
	else
	{
		int realValue = temp_num - qPow(2, 15);
		return -realValue;
	}
}

bool PactOne::VerifyData_one(const QByteArray data)
{
	//去头去尾
	quint8 crcsum = 0x00;
	for (int i = 1; i < data.size() - 3; i++)
	{
		crcsum += data.at(i);
	}
	crcsum ^= 0xff;

	QByteArray data_t = data.mid(data.size() - 3, 2);
	QByteArray data_ti =  QByteArray::fromHex(data_t).toHex();
	int datasum = data_ti.toInt(NULL, 16);

	if (crcsum == datasum)
	{
		return true;
	}
	return false;
}

PactTwo::PactTwo()
{

}

Data_lishen PactTwo::self_Init(const QByteArray data)
{
	int startnum = data.indexOf(0x7E);
	startnum += 3;
	this->lenth = data.mid(startnum, 2);
	startnum += 2;
	this->batstate = data.mid(startnum, 1);
	startnum += 1;
	this->doublebyteCount = data.mid(startnum, 1);
	startnum += 1;
	this->bytecount = data.mid(startnum, 1);
	startnum += 1;
	this->cellVoltage = data.mid(startnum, 32);
	startnum += 32;
	this->designeCapicity = data.mid(startnum, 2);
	startnum += 2;
	this->now_capicity = data.mid(startnum, 2);
	startnum += 2;
	startnum += 2;
	//中间预留两个字节
	this->cycleCount = data.mid(startnum, 2);
	startnum += 2;
	this->temperature = data.mid(startnum, 8);
	startnum += 8;
	this->max_cellvoltage = data.mid(startnum, 2);
	startnum += 2;
	this->min_cellvoltage = data.mid(startnum, 2);
	startnum += 2;
	this->voltage = data.mid(startnum, 2);
	startnum += 2;
	this->charge_current = data.mid(startnum, 2);
	startnum += 2;
	this->discharge_current = data.mid(startnum, 2);
	startnum += 2;
	this->Soc = data.mid(startnum, 2);
	startnum += 2;
	this->batteryState = data.mid(startnum, 2);
	startnum += 2;
	this->alarm_1 = data.mid(startnum, 1);
	startnum += 1;
	this->alarm_2 = data.mid(startnum, 1);
	startnum += 1;
	this->alarm_3 = data.mid(startnum, 1);
	startnum += 1;
	this->alarm_4 = data.mid(startnum, 1);
	startnum += 1;

	//最后两个字节  crc校验 暂时不搞

	//将数据转成十进制，然后传递出去；
	Data_lishen d_data;
	d_data.lenth = HighTurnToLower(this->lenth).toHex().toInt(NULL, 16);
	d_data.statelist = this->batstate.toHex().toInt(NULL, 16);
	d_data.doublebyteCount = this->doublebyteCount.toHex().toInt(NULL, 16);
	d_data.bytecount = this->bytecount.toHex().toInt(NULL, 16);
	for (int i = 0; i < 16; i++)
	{
		QByteArray temparr = this->cellVoltage.mid(i * 2, 2);
		d_data.cellVoltageList.append((float)HighTurnToLower(temparr).toHex().toInt(NULL, 16) / 1000);
	}
	d_data.designeCapicity = (float)designeCapicity.toHex().toInt(NULL, 16) / 10000;
	d_data.now_capicity = (float)now_capicity.toHex().toInt(NULL, 16) / 10000;

	d_data.cycleCount = cycleCount.toHex().toInt(NULL, 16);
	for (int j = 0; j < 4; j++)
	{
		QByteArray temparr = this->cellVoltage.mid(j * 2, 2);
		d_data.tempList.append((float)HighTurnToLower(temparr).toHex().toInt(NULL, 16) / 10);
	}
	d_data.max_cellvoltage = (float)HighTurnToLower(max_cellvoltage).toHex().toInt(NULL, 16) / 1000;
	d_data.min_cellvoltage = (float)HighTurnToLower(min_cellvoltage).toHex().toInt(NULL, 16) / 1000;
	d_data.voltage = (float)HighTurnToLower(voltage).toHex().toInt(NULL, 16) / 1000;
	d_data.charge_current = (float)HighTurnToLower(charge_current).toHex().toInt(NULL, 16) / 10;
	d_data.discharge_current = (float)HighTurnToLower(discharge_current).toHex().toInt(NULL, 16) / 10;
	d_data.Soc = (float)HighTurnToLower(Soc).toHex().toInt(NULL, 16) / 10;
	d_data.batteryState = batteryState.toHex().toInt(NULL, 16);
	d_data.warning_1 = alarm_1.toHex().toInt(NULL, 16);
	d_data.warning_2 = alarm_1.toHex().toInt(NULL, 16);
	d_data.warning_3 = alarm_1.toHex().toInt(NULL, 16);
	d_data.warning_4 = alarm_1.toHex().toInt(NULL, 16);
	return d_data;

}


bool PactTwo::VerifyData_two(const QByteArray data)
{
	quint8 buf;
	quint16 crc16 = 0xFFFF;
	QByteArray verifydata = data.mid(data.indexOf(0x7E) + 1, 73);//去掉帧头 和 校验位

	for (int i = 0; i < verifydata.size(); ++i)  
	{
		buf = data.at(i) ^ crc16;
		crc16 >>= 8;
		crc16 ^= crc16Table[buf];
	}
	quint16 thisdata = data.mid(data.indexOf(0x7E) + 74, 2).toHex().toInt(NULL, 16);
	if (crc16 == thisdata)
	{
		return true;
	}
	return false;
}

PactThree::PactThree()
{

}

Data_peicheng PactThree::simiulateData_Init(const QByteArray data)
{
	int offsetnum = data.indexOf(0x7E);
	offsetnum += 9;
	m_lenth = data.mid(offsetnum, 4);

	offsetnum += 4;

	//数据区第一个是ADR占用两个字节
	offsetnum += 2;

	m_Vcell_Num = data.mid(offsetnum, 2);
	offsetnum += 2;
	m_Vcell = data.mid(offsetnum, 4 * serilizeInit(m_Vcell_Num));
	offsetnum += m_Vcell.size();
	m_TempNum = data.mid(offsetnum, 2);
	offsetnum += 2;
	m_Temp = data.mid(offsetnum, 4 * serilizeInit(m_TempNum));
	offsetnum += m_Temp.size();
	m_Curr = data.mid(offsetnum, 4);
	offsetnum += 4;
	m_voltage = data.mid(offsetnum, 4);
	offsetnum += 4;
	m_CapNow = data.mid(offsetnum, 4);
	offsetnum += 4;

	//用户自定义区 2个字节
	offsetnum += 2;

	m_CapFull = data.mid(offsetnum, 4);
	offsetnum += 4;
	m_cycle = data.mid(offsetnum, 4);
	offsetnum += 4;
	m_CapDesign = data.mid(offsetnum, 4);
	offsetnum += 4;

	//16进制 -》 十进制
	Data_peicheng d_data;
	d_data.lenth =serilizeInit(m_lenth);
	d_data.cellNum = serilizeInit(m_Vcell_Num);
	for (int i = 0; i < d_data.cellNum; i++)
	{
		d_data.cellVoltageList.append((float)serilizeInit(m_Vcell.mid(i * 4, 4)) / 1000);
	}
	d_data.tempretureNum = serilizeInit(m_TempNum);
	for (int j = 0; j < d_data.tempretureNum; j++)
	{
		d_data.tempList.append(serilizeInit(m_Temp.mid(j * 4, 4)));
	}
	if (dealForComplememt(m_Curr) < 0)
	{
		d_data.charge_current = 0;
		d_data.discharge_current = (float)-dealForComplememt(m_Curr);
	}
	else
	{
		d_data.charge_current = (float)dealForComplememt(m_Curr)/100;
		d_data.discharge_current = 0;
	}
	d_data.voltage = (float)serilizeInit(m_voltage) / 1000;
	d_data.now_capicity = (float)serilizeInit(m_CapNow) / 100;
	d_data.fullCapicity = (float)serilizeInit(m_CapFull) / 100;
	d_data.designCapicity = (float)serilizeInit(m_CapDesign) / 100;
	d_data.dischargeCycle = serilizeInit(m_cycle);
	d_data.Soc = (float)(d_data.now_capicity / d_data.fullCapicity) * 100;

	return d_data;
}

Data_peicheng_warning PactThree::alarmData_Init(const QByteArray data)
{
	int offsetnum = 9;
	m_lenth = data.mid(offsetnum, 4);
	offsetnum += 4;
	//跳过地址信息
	offsetnum += 2;
	m_Vcell_Num = data.mid(offsetnum, 2);
	offsetnum += 2;
	m_cellvoltage_warning = data.mid(offsetnum, 2 * serilizeInit(m_Vcell_Num));
	offsetnum += m_cellvoltage_warning.size();
	m_TempNum = data.mid(offsetnum, 2);
	offsetnum += 2;
	m_temperature_warning = data.mid(offsetnum, 2 * serilizeInit(m_TempNum));
	offsetnum += m_temperature_warning.size();

	m_chargeCurent_warning = data.mid(offsetnum, 2);
	offsetnum += 2;
	m_totalvoltage_warning = data.mid(offsetnum, 2);
	offsetnum += 2;
	m_dischargeCurrent_warning = data.mid(offsetnum, 2);
	offsetnum += 2;
	m_protectState1 = data.mid(offsetnum, 2);
	offsetnum += 2;
	m_protectState2 = data.mid(offsetnum, 2);
	offsetnum += 2;
	m_instructorState = data.mid(offsetnum, 2);
	offsetnum += 2;
	m_controllState = data.mid(offsetnum, 2);
	offsetnum += 2;
	m_malfunctionState = data.mid(offsetnum, 2);
	offsetnum += 2;
	m_balanceState1 = data.mid(offsetnum, 2);
	offsetnum += 2;
	m_balanceState2 = data.mid(offsetnum, 2);
	offsetnum += 2;
	m_alarmState1 = data.mid(offsetnum, 2);
	offsetnum += 2;
	m_alarmState2 = data.mid(offsetnum, 2);
	offsetnum += 2;

	Data_peicheng_warning d_data;
	d_data.lenth = m_lenth.toInt(NULL, 16);
	d_data.cellNum = m_Vcell_Num.toInt(NULL, 16);
	for (int i = 0; i < d_data.cellNum; i++)
	{
		d_data.cellVoltage_WarningList = serilizeInit(m_Vcell.mid(i * 2, 2));
	}
	d_data.tempretureNum = m_TempNum.toInt(NULL, 16);
	for (int i = 0; i < d_data.tempretureNum; i++)
	{
		d_data.temp_warningList.append(serilizeInit(m_Temp.mid(i * 2, 2)));
	}

	d_data.chargeCurrent_warning = serilizeInit(m_chargeCurent_warning);
	d_data.voltage_warning = serilizeInit(m_totalvoltage_warning);
	d_data.dischargeCurrent_warning = serilizeInit(m_dischargeCurrent_warning);
	d_data.protectState1 = serilizeInit(m_protectState1);
	d_data.protectState2 = serilizeInit(m_protectState2);
	d_data.instructorState = serilizeInit(m_instructorState);
	d_data.controllState = serilizeInit(m_controllState);
	d_data.malfunctionState = serilizeInit(m_malfunctionState);
	d_data.balanceState1 = serilizeInit(m_balanceState1);
	d_data.balanceState2 = serilizeInit(m_balanceState2);
	d_data.alarmState1 = serilizeInit(m_alarmState1);
	d_data.alarmState2 = serilizeInit(m_alarmState2);

	return d_data;
}

bool PactThree::VerifyData_three(const QByteArray data)
{
	quint16 crcsum = 0x0000;
	for (int i = 1; i < data.size() - 3; i++)
	{
		crcsum += data.at(i);
	}

	crcsum %= 65535; //对65535取余
	crcsum ^= 0xffff; //对余数进行取反
	crcsum += 1;

	quint16 datasum = serilizeInit(data.mid(data.size() - 6, 5));
	if (crcsum == datasum)
	{
		return true;
	}
	return false;
}
