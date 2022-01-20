#pragma once

#include <QByteArray>
#include <QDateTime>



//数据传送格式
struct Data_Zhili
{
	char Addr;
	char Cmd;
	char Ver;
	int data_Len;  //数据长度
	QList<int> time; //当前时间
	float voltage; //电池电压
	int Vcell_num; //电池串数
	QList<float> Vcell_list; // 每一节电压
	float max_cell_voltage;
	float charge_current;
	float discharge_current;
	int Temp_Num; //
	QList<int> temp_list; //
	int max_temperature;
	int vstate_list;
	int cstate_list;
	int tstate_list;
	int alarm_list;
	int fetstate_list;

	int NUM_VOV; //单体高压对应的电芯的序号
	int NUM_VUV; //单体欠压对应的电芯的序号
	int NUM_WARN_VHIGH; //单体高压警告对应的电芯的序号
	int NUM_WARN_VLOW; //单体低压警告对应的电芯的序号
	int BlanceState; // 均衡状态，表示那一节电压开启均衡
	int DchgNum; //放电次数
	int ChgNum; //充电次数
	int Soc; //当前电池百分比
	float CapNow; //当前电池容量
	float CapFull; //总电池容量

	//测试数据
	//16 字节 用于 Parameter Status

	float Charger_Voltage;
	float Charger_Current;
	int Charger_Status;
	float Battery_Voltage_Measured;
	float Charging_Current_Measured;
	int PSD1_Temperature;
	int PSD2_Temperature;
	float PSD1_Current_Measured;
	float PSD2_Current_Measured;
	int battery_ack;

	//Reserved 32字节
};

struct Data_lishen
{
	int lenth; //报文长度
	int statelist; //电池型号 和 充满状态
	int doublebyteCount; //遥信测双字节个数
	int bytecount; //遥信字节数
	QList<float> cellVoltageList;
	float designeCapicity;
	float now_capicity;
	int cycleCount;
	QList<float> tempList;
	float max_cellvoltage;
	float min_cellvoltage;
	float voltage;
	float charge_current;
	float discharge_current;
	float Soc;
	int batteryState;
	int warning_1;
	int warning_2;
	int warning_3;
	int warning_4;


	//16 字节 用于 Parameter Status
	int Charger_Enable;
	float Charger_Voltage;
	float Charger_Current;
	int Charger_Status;
	float Battery_Voltage_Measured;
	float Charging_Current_Measured;
	int PSD1_Enable;
	int PSD2_Enable;
	float PSD1_Temperature;
	float PSD2_Temperature;
	int PSD1_Error;
	int PSD2_Error;
	float PSD1_Current_Measured;
	float PSD2_Current_Measured;

	//Reserved 32字节
};


struct Data_peicheng   //--->>>>>>>>>>>>>>>>>Brand : peicheng 
{
	// 1.simiulate data
	int lenth;
	int cellNum;
	int tempretureNum;
	float fullCapicity;
	float now_capicity;
	int cycleCount;
	float Soc;
	float voltage;
	float charge_current;
	float discharge_current;
	float dischargeCycle;
	float designCapicity;
	QList<float> cellVoltageList;
	QList<float> tempList;
};

struct Data_peicheng_warning   //--->>>>>>>>>>>>>>>>>Brand : peicheng  
{
	// 2.alarm data
	int lenth;
	int cellNum;
	int tempretureNum;
	int chargeCurrent_warning;
	int voltage_warning;
	int dischargeCurrent_warning;
	int protectState1;
	int protectState2;
	int instructorState;
	int controllState;
	int malfunctionState;
	int balanceState1;
	int balanceState2;
	int alarmState1;
	int alarmState2;
	int cellVoltage_WarningList;
	QList<int> temp_warningList;

};
struct Data_peicheng_Total
{
	int cellNum;
	int tempretureNum;
	float fullCapicity;
	float now_capicity;
	int   cycleCount;
	float Soc;
	float voltage;
	float charge_current;
	float discharge_current;
	float dischargeCycle;
	float designCapicity;
	QList<float> cellVoltageList;
	QList<float> tempList;

	int chargeCurrent_warning;
	int voltage_warning;
	int dischargeCurrent_warning;
	int protectState1;
	int protectState2;
	int instructorState;
	int controllState;
	int malfunctionState;
	int balanceState1;
	int balanceState2;
	int alarmState1;
	int alarmState2;
	int cellVoltage_WarningList;
	QList<int> temp_warningList;
};


enum waringType
{
	b_normal = 0,
	b_lower = 1,
	b_high = 2,
	b_other = 240
};

enum pactType
{
	zhili = 1,
	lishen = 2,
	peicheng = 3
};
