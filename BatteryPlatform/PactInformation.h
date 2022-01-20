#pragma once
#include <QObject>
#include "CustomDataType.h"

#define GZ_Net_Header_len 10
#define Battery_Data_len 256

static const quint16 crc16Table[] =
{
	0x0000, 0xC0C1, 0xC181, 0x0140, 0xC301, 0x03C0, 0x0280, 0xC241,
	0xC601, 0x06C0, 0x0780, 0xC741, 0x0500, 0xC5C1, 0xC481, 0x0440,
	0xCC01, 0x0CC0, 0x0D80, 0xCD41, 0x0F00, 0xCFC1, 0xCE81, 0x0E40,
	0x0A00, 0xCAC1, 0xCB81, 0x0B40, 0xC901, 0x09C0, 0x0880, 0xC841,
	0xD801, 0x18C0, 0x1980, 0xD941, 0x1B00, 0xDBC1, 0xDA81, 0x1A40,
	0x1E00, 0xDEC1, 0xDF81, 0x1F40, 0xDD01, 0x1DC0, 0x1C80, 0xDC41,
	0x1400, 0xD4C1, 0xD581, 0x1540, 0xD701, 0x17C0, 0x1680, 0xD641,
	0xD201, 0x12C0, 0x1380, 0xD341, 0x1100, 0xD1C1, 0xD081, 0x1040,
	0xF001, 0x30C0, 0x3180, 0xF141, 0x3300, 0xF3C1, 0xF281, 0x3240,
	0x3600, 0xF6C1, 0xF781, 0x3740, 0xF501, 0x35C0, 0x3480, 0xF441,
	0x3C00, 0xFCC1, 0xFD81, 0x3D40, 0xFF01, 0x3FC0, 0x3E80, 0xFE41,
	0xFA01, 0x3AC0, 0x3B80, 0xFB41, 0x3900, 0xF9C1, 0xF881, 0x3840,
	0x2800, 0xE8C1, 0xE981, 0x2940, 0xEB01, 0x2BC0, 0x2A80, 0xEA41,
	0xEE01, 0x2EC0, 0x2F80, 0xEF41, 0x2D00, 0xEDC1, 0xEC81, 0x2C40,
	0xE401, 0x24C0, 0x2580, 0xE541, 0x2700, 0xE7C1, 0xE681, 0x2640,
	0x2200, 0xE2C1, 0xE381, 0x2340, 0xE101, 0x21C0, 0x2080, 0xE041,
	0xA001, 0x60C0, 0x6180, 0xA141, 0x6300, 0xA3C1, 0xA281, 0x6240,
	0x6600, 0xA6C1, 0xA781, 0x6740, 0xA501, 0x65C0, 0x6480, 0xA441,
	0x6C00, 0xACC1, 0xAD81, 0x6D40, 0xAF01, 0x6FC0, 0x6E80, 0xAE41,
	0xAA01, 0x6AC0, 0x6B80, 0xAB41, 0x6900, 0xA9C1, 0xA881, 0x6840,
	0x7800, 0xB8C1, 0xB981, 0x7940, 0xBB01, 0x7BC0, 0x7A80, 0xBA41,
	0xBE01, 0x7EC0, 0x7F80, 0xBF41, 0x7D00, 0xBDC1, 0xBC81, 0x7C40,
	0xB401, 0x74C0, 0x7580, 0xB541, 0x7700, 0xB7C1, 0xB681, 0x7640,
	0x7200, 0xB2C1, 0xB381, 0x7340, 0xB101, 0x71C0, 0x7080, 0xB041,
	0x5000, 0x90C1, 0x9181, 0x5140, 0x9301, 0x53C0, 0x5280, 0x9241,
	0x9601, 0x56C0, 0x5780, 0x9741, 0x5500, 0x95C1, 0x9481, 0x5440,
	0x9C01, 0x5CC0, 0x5D80, 0x9D41, 0x5F00, 0x9FC1, 0x9E81, 0x5E40,
	0x5A00, 0x9AC1, 0x9B81, 0x5B40, 0x9901, 0x59C0, 0x5880, 0x9841,
	0x8801, 0x48C0, 0x4980, 0x8941, 0x4B00, 0x8BC1, 0x8A81, 0x4A40,
	0x4E00, 0x8EC1, 0x8F81, 0x4F40, 0x8D01, 0x4DC0, 0x4C80, 0x8C41,
	0x4400, 0x84C1, 0x8581, 0x4540, 0x8701, 0x47C0, 0x4680, 0x8641,
	0x8201, 0x42C0, 0x4380, 0x8341, 0x4100, 0x81C1, 0x8081, 0x4040
};
class PactInformation
{
public:
	PactInformation();
	~PactInformation();
};

//智锂协议
class PactOne
{
public:
	PactOne();
	Data_Zhili selfInit(const QByteArray array);
	int serilizeInit(const QByteArray array);
	QByteArray HighTurnToLower(const QByteArray data);
	int dealForComplememt(const QByteArray data);
	bool VerifyData_one(const QByteArray array);

private:
	//智锂数据段
	//均为ASCII码， 需要转换成十六进制
	int m_offset;
	QByteArray m_TopFrame;
	QByteArray m_time; // 7*2
	QByteArray m_Vbat; // 2*2
	QByteArray m_Vcell_Num; //1*2 ->N
	QByteArray m_Vcell; //1*2*N
	QByteArray m_Curr; //2*2*2
	QByteArray m_TempNum;
	QByteArray m_Temp;
	QByteArray m_VState;
	QByteArray m_CState;
	QByteArray m_TState;
	QByteArray m_Alarm;
	QByteArray m_FETState;
	QByteArray m_NUM_VOV;
	QByteArray m_NUM_VUV;
	QByteArray m_NUM_WARN_VHIGH;
	QByteArray m_NUM_WARN_VLOW;
	QByteArray m_BlanceState;
	QByteArray m_DchgNum;
	QByteArray m_ChgNum;
	QByteArray m_SOC;
	QByteArray m_CapNow;
	QByteArray m_CapFull;

	//psd测量值	int Charger_Enable;
	QByteArray Charger_Voltage_feedback;
	QByteArray Charger_Current_feedback;
	QByteArray Charger_Status;
	QByteArray Battery_Voltage_Measured;
	QByteArray Charging_Current_Measured;
	QByteArray PSD1_Temperature;
	QByteArray PSD2_Temperature;
	QByteArray PSD1_Current_Measured;
	QByteArray PSD2_Current_Measured;
};

//-------------》》》》  力神协议
class PactTwo: public PactOne
{
public:
	PactTwo();
	Data_lishen self_Init(const QByteArray array);

	bool VerifyData_two(const QByteArray array);

private:
	//均为16进制数据，无需转成ASCII
	// 7E 0A 01 开头三个无用数据
	QByteArray lenth;//双字节
	// 无用功能码 
	QByteArray batstate; //单字节
	QByteArray doublebyteCount; //单字节
	QByteArray bytecount; // 单字节
	QByteArray cellVoltage; //62 字节
	QByteArray designeCapicity;
	QByteArray now_capicity;
	//中间预留出两个字节
	QByteArray cycleCount;
	QByteArray temperature;
	QByteArray max_cellvoltage;
	QByteArray min_cellvoltage;
	QByteArray voltage;
	QByteArray charge_current;
	QByteArray discharge_current;
	QByteArray Soc;
	QByteArray batteryState;
	QByteArray alarm_1;
	QByteArray alarm_2;
	QByteArray alarm_3;
	QByteArray alarm_4;


	QByteArray Charger_Voltage_status;
	QByteArray Charger_Current_status;
	QByteArray Charger_Status;
	QByteArray Battery_Voltage_Measured;
	QByteArray Charging_Current_Measured;
	QByteArray PSD1_Temperature;
	QByteArray PSD2_Temperature;
	QByteArray PSD1_Error;
	QByteArray PSD2_Error;
	QByteArray PSD1_Current_Measured;
	QByteArray PSD2_Current_Measured;

};

// ---------->>>>>沛城协议
class PactThree : public PactOne
{
public:
	PactThree();
	Data_peicheng simiulateData_Init(const QByteArray data);
	Data_peicheng_warning alarmData_Init(const QByteArray data);
	bool VerifyData_three(const QByteArray array);

private:

	QByteArray m_lenth;
	QByteArray m_voltage; // 2*2
	QByteArray m_Vcell_Num; //1*2 ->N
	QByteArray m_Vcell; //1*2*N
	QByteArray m_Curr; //2*2*2
	QByteArray m_TempNum;
	QByteArray m_Temp;
	QByteArray m_SOC;
	QByteArray m_CapFull; //剩余容量
	QByteArray m_CapNow;
	QByteArray m_CapDesign; //设计容量
	QByteArray m_cycle;

	QByteArray m_cellvoltage_warning;
	QByteArray m_temperature_warning;
	QByteArray m_chargeCurent_warning;
	QByteArray m_totalvoltage_warning;
	QByteArray m_dischargeCurrent_warning;

	QByteArray m_protectState1;
	QByteArray m_protectState2;
	QByteArray m_instructorState;
	QByteArray m_controllState;
	QByteArray m_malfunctionState;
	QByteArray m_balanceState1;
	QByteArray m_balanceState2;
	QByteArray m_alarmState1;
	QByteArray m_alarmState2;

	QByteArray Charger_Voltage_status;
	QByteArray Charger_Current_status;
	QByteArray Charger_Status;
	QByteArray Battery_Voltage_Measured;
	QByteArray Charging_Current_Measured;
	QByteArray PSD1_Temperature;
	QByteArray PSD2_Temperature;
	QByteArray PSD1_Error;
	QByteArray PSD2_Error;
	QByteArray PSD1_Current_Measured;
	QByteArray PSD2_Current_Measured;
};
