#include "testinstructhandle.h"
#include <QDebug>

TestInstructHandle::TestInstructHandle(QObject *parent)
	: QObject(parent), Soc_status(0)
{
	timer = new QTimer(this);
	timer_notest = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &TestInstructHandle::SendData_ToVCU);
	connect(timer_notest, &QTimer::timeout, this, &TestInstructHandle::send_EndofData);
	timer_stagnation = new QTimer(this);
	connect(timer_stagnation, &QTimer::timeout, this, &TestInstructHandle::timer_stagnation_slot);
}

TestInstructHandle::~TestInstructHandle()
{

}

void TestInstructHandle::get_testInstructList(QList<QList<int>> list)
{
	if (list.isEmpty())
	{
		return;
	}
	timer_notest->stop(); //关闭单纯的电池数据采集
	timer->stop();
	is_spliter = true;
	m_queue.clear(); //上一次数据进行清空

	for (int i = 0; i < list.size(); i++)
	{
		m_queue.append(list.at(i));
	}

	test_start();
}


void TestInstructHandle::test_start()
{
	if (m_queue.isEmpty())
	{
		//测试结
		timer_notest->start(500);
		emit testing_name_logsave("No Test", 0);
		return;
	}
	QList<int> list = m_queue.dequeue();	
	//普通充放电
	if (list.at(0) == 0) 
	{
		QList<int> tem_l;
		tem_l.append(0);
		tem_l.append(0);
		tem_l.append(list.at(1));
		tem_l.append(list.at(2));
		tem_l.append(0);
		tem_l.append(list.at(3));
		tem_l.append(list.at(4));
		temp_list = tem_l;
		testing_name_cache = "Simple charge ";
		emit sendHysteresisData(temp_list);
		emit testing_name_logsave("Simple charge start", 1);
		emit testing_name_father(tr("Simple charge"));
		emit testing_name_child(tr("Simple charge underway"));
		timer->start(500);
		
	} 
	else if (list.at(0) == 1)
	{
		QList<int> tem_l;
		tem_l.append(1);
		tem_l.append(1);
		tem_l.append(0);
		tem_l.append(0);
		tem_l.append(list.at(1));
		tem_l.append(list.at(2));
		tem_l.append(list.at(3));
		temp_list = tem_l;
		testing_name_cache = "Simple discharge ";
		emit sendHysteresisData(temp_list);
		emit testing_name_logsave("Simple discharge start", 1);
		emit testing_name_father(tr("Simple discharge"));
		emit testing_name_child(tr("Simple discharge underway"));
		timer->start(500);
	}
	//冒烟测试
	else if (list.at(0) == 2)
	{
		if (is_spliter)
		{
			is_spliter = false;
			QQueue<QList<int>> m_child_queue;
			if (Soc_status> 50)
			{
				QList<int> list_1;
				list_1.append(2);
				list_1.append(1);
				list_1.append(0);
				list_1.append(0);
				list_1.append(list.at(3));
				m_child_queue.append(list_1);
				QList<int> list_2;
				list_2.append(2);
				list_2.append(0);
				list_2.append(list.at(1));
				list_2.append(list.at(2));
				list_2.append(0);
				m_child_queue.append(list_2);
			}
			else
			{
				QList<int> list_1;
				list_1.append(2);
				list_1.append(0);
				list_1.append(list.at(1));
				list_1.append(list.at(2));
				list_1.append(0);
				m_child_queue.append(list_1);
				QList<int> list_2;
				list_2.append(2);
				list_2.append(1);
				list_2.append(0);
				list_2.append(0);
				list_2.append(list.at(3));
				m_child_queue.append(list_2);
			}
			for (int i = 0; i < m_queue.size(); i++)
			{
				m_child_queue.append(m_queue.dequeue());
			}
			m_queue = m_child_queue;
			emit write_execl_test_condition(list);
			emit sendHysteresisData(m_queue.head());
			temp_list = m_queue.dequeue();
			testing_name_cache = "Somking test ";
			emit testing_name_logsave("Somking test start", 1);
			emit testing_name_father(tr("Smoking test"));
			if (temp_list.at(1) == 0)
			{
				emit testing_name_child(tr("Charge attempt underway"));
			}
			else
			{
				emit testing_name_child(tr("Discharge attempt underway"));
			}
		}
		else
		{
			temp_list = list;
			emit sendHysteresisData(temp_list);		
			if (temp_list.at(1) == 0)
			{
				emit testing_name_child(tr("Charge attempt underway"));
			}
			else
			{
				emit testing_name_child(tr("Discharge attempt underway"));
			}
		}
		timer->start(500);
	}
	//容量测试 
	else if (list.at(0) == 3)
	{
		if (is_spliter)
		{
			is_spliter = false;
			QQueue<QList<int>> m_child_queue;
			for (int i = 0; i < list.at(4); i++)
			{
				QList<int> list_1;
				list_1.append(3);
				list_1.append(0);
				list_1.append(list.at(1));
				list_1.append(list.at(2));
				list_1.append(0);
				list_1.append(0);
				list_1.append(i+1);
				m_child_queue.append(list_1);
				QList<int> list_2;
				list_2.append(3);
				list_2.append(1);
				list_2.append(0);
				list_2.append(0);
				list_2.append(list.at(3));
				list_2.append(list.at(4));
				list_2.append(i+1);
				m_child_queue.append(list_2);
			}
			for (int i = 0; i < m_queue.size(); i++)
			{
				m_child_queue.append(m_queue.dequeue());
			}
			m_queue = m_child_queue;
			emit write_execl_test_condition(list);
			emit sendHysteresisData(m_queue.head());
			temp_list = m_queue.dequeue();
			testing_name_cache = "Capacity test ";
			emit testing_name_logsave("Capacity test start", 1);
			emit testing_name_father(tr("Capacity test"));
			emit testing_name_child(tr("Cycle 1 charge underway"));

		}
		else
		{
			temp_list = list;
			emit sendHysteresisData(temp_list);	
			if (temp_list.at(1) == 0)
			{
				QString test_name_underway = tr("Cycle") +  QString::number(temp_list.at(6)) + tr("Charge underway");
				emit testing_name_child(test_name_underway);
			}
			else
			{
				QString test_name_underway = tr("Cycle") + QString::number(temp_list.at(6)) + tr("Discharge underway");
				emit testing_name_child(test_name_underway);
			}
		}
		timer->start(500);
	}	
	//充放电测试
	else if (list.at(0) == 4) 
	{
		if (is_spliter)
		{
			is_spliter = false;
			QQueue<QList<int>> m_child_queue;
			QList<int> list_0;
			list_0.append(4);
			list_0.append(0);//充电
			list_0.append(list.at(1)); 
			list_0.append(list.at(3));
			list_0.append(0);
			list_0.append(0); //0 充满电
			m_child_queue.append(list_0);
			QList<int> list_1;
			list_1.append(4);
			list_1.append(1);//放电
			list_1.append(0); 
			list_1.append(0);
			list_1.append(list.at(4));
			list_1.append(1); //1 标准放电
			m_child_queue.append(list_1);
			QList<int> list_2;
			list_2.append(4);
			list_2.append(0);//充电
			list_2.append(list.at(1));
			list_2.append(list.at(2));
			list_2.append(0);
			list_2.append(2); //2 标准充电
			m_child_queue.append(list_2);
			QList<int> list_3;
			list_3.append(4);
			list_3.append(1);//放电
			list_3.append(0);
			list_3.append(0);
			list_3.append(list.at(5));
			list_3.append(3); //3 快速放电
			m_child_queue.append(list_3);
			QList<int> list_4;
			list_4.append(4);
			list_4.append(0);//充电
			list_4.append(list.at(1));
			list_4.append(list.at(3));
			list_4.append(0);
			list_4.append(4); //4 快速充电
			m_child_queue.append(list_4);
			for (int i = 0; i < m_queue.size(); i++)
			{
				m_child_queue.append(m_queue.dequeue());
			}
			m_queue = m_child_queue;
			emit write_execl_test_condition(list);
			emit sendHysteresisData(m_queue.head());
			temp_list = m_queue.dequeue();
			testing_name_cache = "Charge and discharge test ";
			emit testing_name_logsave("Charge and discharge test start", 1);
			emit testing_name_father(tr("Charge and discharge test"));
			emit testing_name_child(tr("Pre-fill underway"));
		}
		else
		{
			temp_list = list;
			emit sendHysteresisData(temp_list);
			switch (temp_list.at(5))
			{
			case 1:
				emit testing_name_child(tr("Standard discharge underway"));
				break;
			case 2:
				emit testing_name_child(tr("Standard charge underway"));
				break;
			case 3:
				emit testing_name_child(tr("Fast discharge underway"));
				break;
			case 4:
				emit testing_name_child(tr("Fast charge underway"));
				break;
			default:
				break;
			}
		}
		timer->start(500);
	}
	//SOC测试
	else if (list.at(0) == 5)
	{
		timer->stop();
		if (is_spliter)
		{
			is_spliter = false;
			QQueue<QList<int>> m_child_queue;
			QList<int> list_0;
			list_0.append(5);
			list_0.append(0);//充电
			list_0.append(list.at(1));
			list_0.append(list.at(2));
			list_0.append(0);
			list_0.append(list.at(4));
			list_0.append(0); //0 预充满
			m_child_queue.append(list_0);
			QList<int> list_1;
			list_1.append(5);
			list_1.append(1);//放电
			list_1.append(0);
			list_1.append(0);
			list_1.append(list.at(3));
			list_1.append(list.at(4));
			list_1.append(1); //放电
			m_child_queue.append(list_1);
			QList<int> list_2;
			list_2.append(5);
			list_2.append(0);//充电
			list_2.append(list.at(1));
			list_2.append(list.at(2));
			list_2.append(0);
			list_2.append(list.at(4));
			list_2.append(2); //充电
			m_child_queue.append(list_2);
			for (int i = 0; i < m_queue.size(); i++)
			{
				m_child_queue.append(m_queue.dequeue());
			}
			m_queue = m_child_queue;
			emit write_execl_test_condition(list);
			emit sendHysteresisData(m_queue.head());
			temp_list = m_queue.dequeue();
			testing_name_cache = "SOC test ";
			emit testing_name_logsave("SOC test start", 1);
			emit testing_name_father(tr("SOC test"));
			emit testing_name_child(tr("Pre-fill underway"));
		}
		else
		{
			temp_list = list;
			emit sendHysteresisData(temp_list);
			switch (temp_list.at(6))
			{
			case 1:
				emit testing_name_child(tr("Discharge underway"));
				break;
			case 2:
				emit testing_name_child(tr("Charge underway"));
				break;
			default:
				break;
			}
		}
		timer->start(500);
	}
	//电流精度测试
	else if (list.at(0) == 6)
	{
		timer->stop();
		if (is_spliter)
		{
			is_spliter = false;
			QList<int> ttt_1;
			ttt_1.append(6);
			ttt_1.append(1);
			ttt_1.append(0);
			ttt_1.append(0);
			ttt_1.append(list.at(2));
			ttt_1.append(0);
			ttt_1.append(3); //放电过程
			temp_discharge_order = ttt_1;
			QList<int> ttt_0;
			ttt_0.append(6);
			ttt_0.append(0);
			ttt_0.append(list.at(1));
			ttt_0.append(list.at(2));
			ttt_0.append(0);
			ttt_0.append(0);
			ttt_0.append(2); //冲电过程
			temp_charge_order = ttt_0;

			QQueue<QList<int>> m_child_queue;
			m_child_queue.append(temp_discharge_order);
			int cycle_num = list.at(2) / (list.at(3)*10);
			for (int i = 0; i < cycle_num; i++)
			{
				QList<int> list_0;
				list_0.append(6);
				list_0.append(0);//充电
				list_0.append(list.at(1));
				list_0.append(list.at(2) - list.at(3) *10 * i);
				list_0.append(0);
				list_0.append(list.at(6));
				list_0.append(0);
				m_child_queue.append(list_0);
			}

			if (list.at(2) % (list.at(3) * 10) != 0)
			{
				QList<int> list_1;
				list_1.append(6);
				list_1.append(0);//充电
				list_1.append(list.at(1));
				list_1.append(10);
				list_1.append(0);
				list_1.append(list.at(6));
				list_1.append(0);
				m_child_queue.append(list_1);
			}
			else
			{
				if (list.at(3) > 1)
				{
					QList<int> list_1;
					list_1.append(6);
					list_1.append(0);//充电
					list_1.append(list.at(1));
					list_1.append(10);
					list_1.append(0);
					list_1.append(list.at(6));
					list_1.append(0);
					m_child_queue.append(list_1);
				}

			}

			m_child_queue.append(temp_charge_order);
			for (int i = 0; i < cycle_num; i++)
			{
				QList<int> list_0;
				list_0.append(6);
				list_0.append(1);//放电
				list_0.append(0);
				list_0.append(0);
				list_0.append(list.at(2) - list.at(3) * 10 * i);
				list_0.append(list.at(6));
				list_0.append(1);
				m_child_queue.append(list_0);
			}
			if (list.at(2) % (list.at(3) * 10) != 0)
			{
				QList<int> list_1;
				list_1.append(6);
				list_1.append(1);//放电
				list_1.append(0);
				list_1.append(0);
				list_1.append(10);
				list_1.append(list.at(6));
				list_1.append(1);
				m_child_queue.append(list_1);
			}
			else
			{
				if (list.at(3) > 1)
				{
					QList<int> list_1;
					list_1.append(6);
					list_1.append(1);//放电
					list_1.append(0);
					list_1.append(0);
					list_1.append(10);
					list_1.append(list.at(6));
					list_1.append(1);
					m_child_queue.append(list_1);
				}
			}

			for (int i = 0; i < m_queue.size(); i++)
			{
				m_child_queue.append(m_queue.dequeue());
			}
			m_queue = m_child_queue;
			emit write_execl_test_condition(list);
			emit sendHysteresisData(m_queue.head());
			temp_list = m_queue.dequeue();
			testing_name_cache = "Current accuracy test ";
			emit testing_name_logsave("Current accuracy test start", 1);
			emit testing_name_father(tr("Current accuracy test"));
			emit testing_name_child(tr("Pre-empty underway"));
		}
		else
		{
			temp_list = list;
			former_test_order = temp_list;
			emit sendHysteresisData(temp_list);
			if (temp_list.at(6) == 0)
			{
				testing_name_child(tr("Charge current accuracy underway"));
			}
			else if (temp_list.at(6) == 1)
			{
				testing_name_child(tr("Discharge current accuracy underway"));
			}
			else if (temp_list.at(6) == 2)
			{
				testing_name_child(tr("Pre-full underway"));
			}
			else
			{
				testing_name_child(tr("Pre-empty underway"));
			}
		}
		timer->start(500);
	}
	//电压精度测试
	else if (list.at(0) == 7)
	{
		timer->stop();
		if (is_spliter)
		{
			is_spliter = false;
			QList<int> ttt_1;
			ttt_1.append(7);
			ttt_1.append(1);
			ttt_1.append(0);
			ttt_1.append(0);
			ttt_1.append(list.at(3));
			ttt_1.append(0);
			ttt_1.append(0);
			ttt_1.append(0);
			ttt_1.append(0);
			ttt_1.append(3); //放电过程
			temp_discharge_order = ttt_1;
			QList<int> ttt_0;
			ttt_0.append(7);
			ttt_0.append(0);
			ttt_0.append(list.at(1));
			ttt_0.append(list.at(2));
			ttt_0.append(0);
			ttt_0.append(0);
			ttt_0.append(0);
			ttt_0.append(0);
			ttt_0.append(0);
			ttt_0.append(2); //冲电过程
			temp_charge_order = ttt_0;

			QQueue<QList<int>> m_child_queue;
			m_child_queue.append(temp_discharge_order);

			int cycle_num = 100 / list.at(4);
			for (int i = 0; i <= cycle_num; i++)
			{
				QList<int> list_0;
				list_0.append(7);
				list_0.append(0);//充电
				list_0.append(list.at(1));
				list_0.append(list.at(2));
				list_0.append(0);
				list_0.append(list.at(4) * i);
				list_0.append(list.at(7));
				list_0.append(list.at(8));
				list_0.append(list.at(9));
				list_0.append(0);
				m_child_queue.append(list_0);
			}
			if (100 % list.at(4) != 0)
			{
				QList<int> list_1;
				list_1.append(7);
				list_1.append(0);//充电
				list_1.append(list.at(1));
				list_1.append(list.at(2));
				list_1.append(0);
				list_1.append(100);
				list_1.append(list.at(7));
				list_1.append(list.at(8));
				list_1.append(list.at(9));
				list_1.append(0);
				m_child_queue.append(list_1);
			}

			m_child_queue.append(temp_charge_order);
			for (int i = 0; i <= cycle_num; i++)
			{
				QList<int> list_0;
				list_0.append(7);
				list_0.append(1);//放电
				list_0.append(0);
				list_0.append(0);
				list_0.append(list.at(3));
				list_0.append(100 - list.at(4) * i);
				list_0.append(list.at(7));
				list_0.append(list.at(8));
				list_0.append(list.at(9));
				list_0.append(1);
				m_child_queue.append(list_0);
			}
			if (100 % list.at(4) != 0)
			{
				QList<int> list_1;
				list_1.append(7);
				list_1.append(1);//放电
				list_1.append(0);
				list_1.append(0);
				list_1.append(list.at(3));
				list_1.append(0);
				list_1.append(list.at(7));
				list_1.append(list.at(8));
				list_1.append(list.at(9));
				list_1.append(1);
				m_child_queue.append(list_1);
			}

			for (int i = 0; i < m_queue.size(); i++)
			{
				m_child_queue.append(m_queue.dequeue());
			}
			m_queue = m_child_queue;
			emit write_execl_test_condition(list);
			emit sendHysteresisData(m_queue.head());
			temp_list = m_queue.dequeue();
			testing_name_cache = "Voltage accuracy test ";
			emit testing_name_logsave("Voltage accuracy test start", 1);
			emit testing_name_father(tr("Voltage accuracy test"));
			emit testing_name_child(tr("Pre-empty underway"));
		}
		else
		{
			temp_list = list;
			former_test_order = temp_list;
			emit sendHysteresisData(temp_list);
			if (temp_list.at(9) == 0)
			{
				testing_name_child(tr("Charge voltage accuracy underway"));
			}
			else if(temp_list.at(9) == 1)
			{
				testing_name_child(tr("Discharge voltage accuracy underway"));
			}
			else if (temp_list.at(9) == 2)
			{
				testing_name_child(tr("Pre-full underway"));
			}
			else
			{
				testing_name_child(tr("Pre-empty underway"));
			}
		}
		timer->start(500);
	}
	//
	else if (list.at(0) == 8)
	{
		timer->stop();
		if (is_spliter)
		{
			is_spliter = false;
			QQueue<QList<int>> m_child_queue;
			QList<int> list_1;
			list_1.append(8);
			list_1.append(1);
			list_1.append(0);
			list_1.append(0);
			list_1.append(list.at(3));
			list_1.append(3);
			list_1.append(0);
			m_child_queue.append(list_1);
			QList<int> list_2;
			list_2.append(8);
			list_2.append(0);
			list_2.append(list.at(1));
			list_2.append(list.at(2));
			list_2.append(0);
			list_2.append(0);
			list_2.append(list.at(4));
			m_child_queue.append(list_2);
			
			for (int i = 0; i < m_queue.size(); i++)
			{
				m_child_queue.append(m_queue.dequeue());
			}
			m_queue = m_child_queue;
			emit write_execl_test_condition(list);
			emit sendHysteresisData(m_queue.head());
			temp_list = m_queue.dequeue();
			testing_name_cache = "Current accuracy test ";
			emit testing_name_logsave("Current accuracy test start", 1);
			emit testing_name_father(tr("Current accuracy test"));
			emit testing_name_child(tr("Pre-empty underway"));

		}
		else
		{
			temp_list = list;
			emit sendHysteresisData(temp_list);
		}
		timer->start(500);
	}
}

void TestInstructHandle::updateBrandTypePact(const int index, const int cap)
{
	type_pact = index;
}

void TestInstructHandle::test_adjust_accuracy(const int type)
{
	timer->stop();
	timer_stagnation->start(15000);
	timer_notest->start(500);
	if (type)
	{
		temp_list = temp_discharge_order;
	}
	else
	{
		temp_list = temp_charge_order;
	}
	emit testing_name_logsave(testing_name_cache + "idle", 2);
	adjust_test = true;	
}

void TestInstructHandle::update_next_alone()
{
	is_spliter = true;
	timer->stop(); //暂停测试指令
	timer_stagnation->start(15000);
	emit testing_name_logsave(testing_name_cache + "end", 3);
	timer_notest->start(500); //发送空闲包
}

void TestInstructHandle::update_next_mulitiple()
{
	timer->stop();
	timer_stagnation->start(15000);
	timer_notest->start(500);
	if (adjust_test)
	{
		adjust_test = false;
		send_former_order = true;
		temp_list = former_test_order;
	}
	else
	{
		emit testing_name_logsave(testing_name_cache + "idle", 2);
	}
}

void TestInstructHandle::testing_state_free(bool val)
{
	if (val)
	{
		timer_notest->start(500);
		emit testing_name_logsave("No Test", 0);
	}
	else
	{
		timer_notest->stop();
	}
}

void TestInstructHandle::timer_stagnation_slot()
{
	timer_stagnation->stop();
	timer_notest->stop();
	if (adjust_test) //电流精度测试SOC不满足时
	{
		emit sendHysteresisData(temp_list);
		timer->start();
	}
	else if (send_former_order)
	{
		send_former_order = false;
		emit sendHysteresisData(temp_list);
		timer->start();
	}
	else
	{
		test_start();
	}

}

void TestInstructHandle::update_Soc_Value(const int val)
{
	this->Soc_status = val;
}

QByteArray TestInstructHandle::instruct_data_TobyteArray(const QList<int> &list)
{
	QByteArray send_data;
	//GZnet 头
	init_GZnet_header(send_data);
	//
	init_ParameterSet(send_data, list);
	//
	init_instruct_data(send_data, list);
	//
	intit_Reserved_data(send_data);

	return send_data;
}

void TestInstructHandle::init_GZnet_header(QByteArray & data) //10 byte
{
	char _version_GZ = 0x00;
	char _segement_GZ = 0x01;
	int _offset_GZ = 0;
	short _len_GZ = data_len;

	QByteArray temp;
	temp = QByteArray(const_cast<char *>(reinterpret_cast<const char *>(&_Sequence_GZ)), sizeof(_Sequence_GZ));
	data.append(temp);
	data.append(_version_GZ);
	data.append(_segement_GZ);
	temp = QByteArray(const_cast<char *>(reinterpret_cast<const char *>(&_offset_GZ)), sizeof(_offset_GZ));
	data.append(temp);
	temp = QByteArray(const_cast<char *>(reinterpret_cast<const char *>(&_len_GZ)), sizeof(_len_GZ));
	data.append(temp);
	_Sequence_GZ++;
}

void TestInstructHandle::init_ParameterSet(QByteArray & data, const QList<int> &list) // 16 byte
{
	char pact_ = char(type_pact);
	char Battery_ACK = 0x00;
	char charge_enable;
	char PSD1_Clear_Error = 0x00;
	char PSD2_Clear_Error = 0x00;
	char PSD1_Enable;
	char PSD2_Enable;
	if (list.at(1) == 0)
	{
		charge_enable = 0x01;
		PSD1_Enable = 0x00;
		PSD2_Enable = 0x00;
	}
	else
	{
		charge_enable = 0x00;
		if (list.at(4) > 500) //500单位 /0.1A
		{
			PSD1_Enable = 0x01;
			PSD2_Enable = 0x01;
		}
		else
		{
			PSD1_Enable = 0x01;
			PSD2_Enable = 0x00;
		}
	}
	data.append(pact_);
	data.append(Battery_ACK);
	if (type_pact == 2)
	{
		if (pact_peicheng)
		{
			char aa = 0x00;
			data.append(aa);
			pact_peicheng = false;
		}
		else
		{
			char aa = 0x01;
			data.append(aa);
			pact_peicheng = true;
		}
	}
	else
	{
		char tem = 0x00;
		data.append(tem);
	}
	data.append(charge_enable);
	data.append(PSD1_Enable);
	data.append(PSD2_Enable);
	data.append(PSD1_Clear_Error);
	data.append(PSD2_Clear_Error);

	for (int i = 0; i < 8; i++)
	{
		char aa = 0x00;
		data.append(aa);
	}
}

void TestInstructHandle::init_instruct_data(QByteArray & data, const QList<int>& list) //22 byte
{
	QByteArray temp;
	int Voltage, Charger_Current, PSD1_Current, PSD2_Current; 
	if (list.at(1) == 0)
	{
		Voltage = list.at(2) * 100;
		Charger_Current = list.at(3) * 100;
		PSD1_Current = 0;
		PSD2_Current = 0;
	}
	else
	{
		if (list.at(4) > 500)  //链表电流电压数据以0.1A/  协议 0.001A/ 
		{
			Voltage = 0;
			Charger_Current = 0;
			PSD1_Current = 50000;
			PSD2_Current = list.at(4) * 100 - 50000;
		}
		else
		{
			Voltage = 0;
			Charger_Current = 0;
			PSD1_Current = list.at(4) * 100;
			PSD2_Current = 0;
		}
	}
	temp = QByteArray(const_cast<char *>(reinterpret_cast<const char *>(&Voltage)), sizeof(Voltage));
	data.append(temp);
	temp = QByteArray(const_cast<char *>(reinterpret_cast<const char *>(&Charger_Current)), sizeof(Charger_Current));
	data.append(temp);
	temp = QByteArray(const_cast<char *>(reinterpret_cast<const char *>(&PSD1_Current)), sizeof(PSD1_Current));
	data.append(temp);
	temp = QByteArray(const_cast<char *>(reinterpret_cast<const char *>(&PSD2_Current)), sizeof(PSD2_Current));
	data.append(temp);
}

void TestInstructHandle::intit_Reserved_data(QByteArray & data) // 32 byte
{
	for (int i = 0; i < 32; i++)
	{
		char aa = 0x00;
		data.append(aa);
	}
}

void TestInstructHandle::SendData_ToVCU()
{
	QByteArray temp_data = instruct_data_TobyteArray(temp_list);
	emit sendInstructArray(temp_data);
}

void TestInstructHandle::send_EndofData() //对充放电进行停滞
{
	QByteArray send_data;
	//GZnet 头
	init_GZnet_header(send_data);
	char pact_value = char(type_pact);
	send_data.append(pact_value);
	for (int i = 0; i < 15; i++)
	{
		char aaa = 0x00;
		send_data.append(aaa);
	}

	for (int i = 0; i < 48; i++)
	{
		char aa = 0x00;
		send_data.append(aa);
	}
	emit sendInstructArray(send_data);
}

void TestInstructHandle::update_loop_pass(bool val)
{
	timer->stop();
	m_queue.clear();
	test_start();
}


