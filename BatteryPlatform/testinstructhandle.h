#pragma once

#include <QObject>
#include <QTimer>
#include <QQueue>
#include <QEventLoop>

#define  data_len 64


class TestInstructHandle : public QObject
{
	Q_OBJECT

public:
	explicit TestInstructHandle(QObject *parent = Q_NULLPTR);
	~TestInstructHandle();

	void get_testInstructList(const QList<QList<int>> list);
	void test_start();
	void updateBrandTypePact(const int index, const int cap);
	void test_adjust_accuracy(const int type);
	void update_next_alone();
	void update_next_mulitiple();
	void testing_state_free(const bool val);
	void timer_stagnation_slot();
	void update_Soc_Value(const int val);
	QByteArray instruct_data_TobyteArray(const QList<int> &list);
	void init_GZnet_header(QByteArray &data);  //载入GZnet 协议头
	void init_ParameterSet(QByteArray &data, const QList<int> &list);
	void init_instruct_data(QByteArray &data, const QList<int> &list);
	void intit_Reserved_data(QByteArray &data);
	void SendData_ToVCU();

	void send_EndofData();
	void update_loop_pass(bool val);


signals:
	void sendInstructArray(QByteArray array);
	void sendHysteresisData(QList<int> data);
	//测试正在进行名称
	void write_execl_test_condition(const QList<int> data);
	void testing_name_father(const QString state);
	void testing_name_child(const QString state);
	void testing_name_logsave(const QString name, const int state);

private:
	bool is_spliter{ true };
	QList<QList<int>> m_instructList;
	QQueue<QList<int>> m_queue;
	
	QString testing_name_cache;
	int type_pact{ 0 };
	bool isSuitForResistance{ false };
	int Soc_status{ 0 };
	QTimer *timer{ nullptr };
	QTimer *timer_notest{ nullptr };
	QTimer *timer_stagnation{ nullptr };
	QList<int> temp_list;
	short _Sequence_GZ = 0;
	bool pact_peicheng{true};
	QEventLoop  *el{ nullptr };
	bool is_pass_all_loop{ false };

	//测试异常处理
	QList<int> former_test_order;
	QList<int> temp_charge_order;
	QList<int> temp_discharge_order;
	bool adjust_test{ false };
	bool send_former_order{ false };
};
