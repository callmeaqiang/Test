#pragma once
#include <QObject>
#include "CustomDataType.h"
#include <QtXlsx/QtXlsx>

using namespace QXlsx;



class Data_WriteTOExecl :public QObject
{
	Q_OBJECT
public:
	explicit Data_WriteTOExecl(QObject *parent = Q_NULLPTR);
	~Data_WriteTOExecl();
	enum battery_cahrge_discharge
	{
		_charge_,
		_discharge_,
	};
	void update_pact_type(const int pact, const int capacity);
	void update_execl_path(const QString filepath);
	void getHysteresisData(QList<int> data); //初始化测试开始、结束条件
	void testconditionReset();              //测试指标复位
	void write_test_condition(const QList<int> data);

	void get_whatWriteToExecl(Data_Zhili data);
	//冒烟测试
	void deal_for_smoking();
	void write_smoking_data(QList<QString> list);
	//容量测试
	void deal_for_capacity();
	//充放电测试
	void deal_for_CD_test(Data_Zhili &data, int type, QString str);
	//SOC测试
	void deal_for_SOCTest_discharge(Data_Zhili &data);
	void deal_for_SOCTest_charge(Data_Zhili &data);
	//电流精度测试
	void deal_current_accuracy(Data_Zhili &data, int cOrd);
	//电压精度测试
	void deal_voltage_accuracy(Data_Zhili &data, int cOrd);
<<<<<<< HEAD
=======
	//保护参数测试
	void deal_for_protection_parameters();
>>>>>>> cbe78ec (2022.1.20 12.45.30)

signals:
	void teminate_device();
	void start_next_Alone();
	void test_next_item();
	void start_next_multiple();
	void start_verify_test(bool val);
	void overfall_state(const bool val);
	void testing_testname(const QString str);
	void tested_result_bool(const QString str, const bool val);
	void tested_result_str(const QString str, const QString result);
	void tested_end(const bool val);
	void painter_data_for_CD_test(const int type, const QString path, QVector<double> timer, QVector<double> voltage, QVector<double> chargecurrent, QVector<double> dischargecurrent, QVector<double> soc, QVector<double> temper); 
	void painter_data_for_SOC_test(const int type, const QString str, QVector<double> timer, QVector<double> soc);
	void start_test_adjust(const int type);
private:

	int m_pact{ 0 };       //协议类型
	QString m_execl_path;  //execl存放路径
	Data_Zhili temp_data_zhili; //临时数据

	int pass_num{ 0 };//用于延时记录数据
	int result_row_count{ 0 };//结果所在行
	bool is_first_coming{ true };//第一次写入execl

	//冒烟测试需要维护的变量
	bool smoking_test_charge{ false };//充电尝试
	bool smoking_test_discharge{ false };//放电尝试
	bool is_format_data_write{ false }; //写入数据格式开关
	int smoking_status{ 0 }; //计数测试子项进行的次数，等于2即是测试结束
	int smoking_now{ 0 }; //1，代表充电尝试， 2代表放电尝试
	int smoking_err_num{ 0 };//测试过程中错误项个数，大于零即是测试失败

	// 容量测试
	int  standard_capacity{ 0 }; //使用须知 标准容量 单位0.1Ah 
	bool capacity_test_state{ false };//开始记录放电电流值
	bool capacity_test_charge{ false };//放空后再次充满
	int capacity_total_cycle{ 0 }; //循环次数
	int capacity_count_now{ 0 }; //当前进行次数
	QVector<float> cap_current_B; //电池内部值
	QVector<float> cap_current_M; //PSD测量值
	float max_capatcity{ 0 };//循环测试中，容量的最大值， 即容量估算
	QList<int> capfull_list; //用于记录循环测试过程中， 电池数据 capfull是否发生变化， 即容量学习
	int capacity_err_num{ 0 }; //测试过程中错误项个数，大于零即是测试失败


	//充放电测试
	bool CD_charge_simplecharge{ false }; //预充满
	bool CD_charge_standardcharge{ false };//标准充电
	bool CD_charge_fastcharge{ false };//快速充电
	bool CD_charge_standarddischarge{ false };//标准放电
	bool CD_charge_fastdischarge{ false };//快速放电
	QVector<double> m_time_vector;//绘图所需的数据容器
	QVector<double> m_voltage_CD;
	QVector<double> m_chargeCurrent_CD;
	QVector<double> m_dischargeCurrent_CD;
	QVector<double> m_Soc_vector;
	QVector<double> m_Maxtemperature_CD;

	//SOC测试
	bool SOC_Test_precharge{ false };//预充满
	bool SOC_Test_Charge{ false };//充电精度
	bool SOC_Test_Discharge{ false };//放电精度
	int soc_test_gap{ 0 };//记录间隔 单次释放Ah
	int soc_percentage{ 0 };//SOC测试单次百分比 用于计算记录间隔
	QVector<float> change_capacity_vector{ 0 }; //用于测试结束时最后一次容量计算
	float capacity_addOrdecrease{ 0 }; //充放过程中容量总变化值
	int gap_num{ 1 }; //已经进行的间隔次数
	float start_voltage{ 0 };//开始电压
	float start_temperature{ 0 };//开始温度

	//电流精度测试
	bool current_accuracy_Pre_full{ false };//预充满（目前测试中 数据记得改20222,.1.19）
	bool current_accuracy_Pre_empty{ false };//预放空
	bool current_accuracy_charge{ false };   //充电精度
	bool current_accuracy_discharge{ false };//放电精度
	int test_now_current{ 0 }; //当前测试下发的控制电流
	int standard_err_current{ 0 };//允许的最大误差 单位mA
	int current_accuracy_charge_num{ -1 };   //充电精度进行的次数
	int current_accuracy_discharge_num{ -1 };//放电精度进行的次数

	//电压精度测试
	bool voltage_accuracy_Pre_full{ false };  //预充满（目前测试中 数据记得改20222,.1.19）
	bool voltage_accuracy_Pre_empty{ false }; //预放空
	bool voltage_accuracy_charge{ false };    //充电精度
	bool voltage_accuracy_discharge{ false }; //放电精度
	int test_now_soc{ 0 };					  //读取电压的标志，BMS的SOC == test_now_soc, 就读取一次
	int standard_err_voltage{ 0 };//允许的最大误差 单位mV
	int voltage_accuracy_charge_num{ -1 };   //充电精度进行的次数
	int voltage_accuracy_discharge_num{ -1 };//放电精度进行的次数

	//保护参数测试
	bool protection_pre_discharge{ false };
	bool protection_pre_charge{ false };
	bool protection_overshoot_test{ false };
	bool protection_overfall_test{ false };
	int overshoot_warning_voltatge{ 0 };

	//other
	bool fullcharge{ false };    //满充截止
	bool fulldischarge{ false }; //满放截止
	bool cutoff_Soc_charge{ false };    //soc截止标志
	bool cutoff_Soc_discharge{ false };    //soc截止标志
	int  m_cutSoc{ 0 };			 //soc截止值
};

