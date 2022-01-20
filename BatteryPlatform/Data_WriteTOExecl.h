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
	void getHysteresisData(QList<int> data); //��ʼ�����Կ�ʼ����������
	void testconditionReset();              //����ָ�긴λ
	void write_test_condition(const QList<int> data);

	void get_whatWriteToExecl(Data_Zhili data);
	//ð�̲���
	void deal_for_smoking();
	void write_smoking_data(QList<QString> list);
	//��������
	void deal_for_capacity();
	//��ŵ����
	void deal_for_CD_test(Data_Zhili &data, int type, QString str);
	//SOC����
	void deal_for_SOCTest_discharge(Data_Zhili &data);
	void deal_for_SOCTest_charge(Data_Zhili &data);
	//�������Ȳ���
	void deal_current_accuracy(Data_Zhili &data, int cOrd);
	//��ѹ���Ȳ���
	void deal_voltage_accuracy(Data_Zhili &data, int cOrd);
<<<<<<< HEAD
=======
	//������������
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

	int m_pact{ 0 };       //Э������
	QString m_execl_path;  //execl���·��
	Data_Zhili temp_data_zhili; //��ʱ����

	int pass_num{ 0 };//������ʱ��¼����
	int result_row_count{ 0 };//���������
	bool is_first_coming{ true };//��һ��д��execl

	//ð�̲�����Ҫά���ı���
	bool smoking_test_charge{ false };//��糢��
	bool smoking_test_discharge{ false };//�ŵ糢��
	bool is_format_data_write{ false }; //д�����ݸ�ʽ����
	int smoking_status{ 0 }; //��������������еĴ���������2���ǲ��Խ���
	int smoking_now{ 0 }; //1�������糢�ԣ� 2����ŵ糢��
	int smoking_err_num{ 0 };//���Թ����д���������������㼴�ǲ���ʧ��

	// ��������
	int  standard_capacity{ 0 }; //ʹ����֪ ��׼���� ��λ0.1Ah 
	bool capacity_test_state{ false };//��ʼ��¼�ŵ����ֵ
	bool capacity_test_charge{ false };//�ſպ��ٴγ���
	int capacity_total_cycle{ 0 }; //ѭ������
	int capacity_count_now{ 0 }; //��ǰ���д���
	QVector<float> cap_current_B; //����ڲ�ֵ
	QVector<float> cap_current_M; //PSD����ֵ
	float max_capatcity{ 0 };//ѭ�������У����������ֵ�� ����������
	QList<int> capfull_list; //���ڼ�¼ѭ�����Թ����У� ������� capfull�Ƿ����仯�� ������ѧϰ
	int capacity_err_num{ 0 }; //���Թ����д���������������㼴�ǲ���ʧ��


	//��ŵ����
	bool CD_charge_simplecharge{ false }; //Ԥ����
	bool CD_charge_standardcharge{ false };//��׼���
	bool CD_charge_fastcharge{ false };//���ٳ��
	bool CD_charge_standarddischarge{ false };//��׼�ŵ�
	bool CD_charge_fastdischarge{ false };//���ٷŵ�
	QVector<double> m_time_vector;//��ͼ�������������
	QVector<double> m_voltage_CD;
	QVector<double> m_chargeCurrent_CD;
	QVector<double> m_dischargeCurrent_CD;
	QVector<double> m_Soc_vector;
	QVector<double> m_Maxtemperature_CD;

	//SOC����
	bool SOC_Test_precharge{ false };//Ԥ����
	bool SOC_Test_Charge{ false };//��羫��
	bool SOC_Test_Discharge{ false };//�ŵ羫��
	int soc_test_gap{ 0 };//��¼��� �����ͷ�Ah
	int soc_percentage{ 0 };//SOC���Ե��ΰٷֱ� ���ڼ����¼���
	QVector<float> change_capacity_vector{ 0 }; //���ڲ��Խ���ʱ���һ����������
	float capacity_addOrdecrease{ 0 }; //��Ź����������ܱ仯ֵ
	int gap_num{ 1 }; //�Ѿ����еļ������
	float start_voltage{ 0 };//��ʼ��ѹ
	float start_temperature{ 0 };//��ʼ�¶�

	//�������Ȳ���
	bool current_accuracy_Pre_full{ false };//Ԥ������Ŀǰ������ ���ݼǵø�20222,.1.19��
	bool current_accuracy_Pre_empty{ false };//Ԥ�ſ�
	bool current_accuracy_charge{ false };   //��羫��
	bool current_accuracy_discharge{ false };//�ŵ羫��
	int test_now_current{ 0 }; //��ǰ�����·��Ŀ��Ƶ���
	int standard_err_current{ 0 };//����������� ��λmA
	int current_accuracy_charge_num{ -1 };   //��羫�Ƚ��еĴ���
	int current_accuracy_discharge_num{ -1 };//�ŵ羫�Ƚ��еĴ���

	//��ѹ���Ȳ���
	bool voltage_accuracy_Pre_full{ false };  //Ԥ������Ŀǰ������ ���ݼǵø�20222,.1.19��
	bool voltage_accuracy_Pre_empty{ false }; //Ԥ�ſ�
	bool voltage_accuracy_charge{ false };    //��羫��
	bool voltage_accuracy_discharge{ false }; //�ŵ羫��
	int test_now_soc{ 0 };					  //��ȡ��ѹ�ı�־��BMS��SOC == test_now_soc, �Ͷ�ȡһ��
	int standard_err_voltage{ 0 };//����������� ��λmV
	int voltage_accuracy_charge_num{ -1 };   //��羫�Ƚ��еĴ���
	int voltage_accuracy_discharge_num{ -1 };//�ŵ羫�Ƚ��еĴ���

	//������������
	bool protection_pre_discharge{ false };
	bool protection_pre_charge{ false };
	bool protection_overshoot_test{ false };
	bool protection_overfall_test{ false };
	int overshoot_warning_voltatge{ 0 };

	//other
	bool fullcharge{ false };    //�����ֹ
	bool fulldischarge{ false }; //���Ž�ֹ
	bool cutoff_Soc_charge{ false };    //soc��ֹ��־
	bool cutoff_Soc_discharge{ false };    //soc��ֹ��־
	int  m_cutSoc{ 0 };			 //soc��ֵֹ
};

