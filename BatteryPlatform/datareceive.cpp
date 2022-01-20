#include "datareceive.h"
#include "dataanalyze.h"
#include <QThread>


DataReceive::DataReceive(QObject *parent) : QObject(parent)
{

}


DataReceive::~DataReceive()
{
}

void DataReceive::connect_to_Server(const int port1,const QString ip)
{
	//只进行端口绑定操作
		//用于数据接收
	if (!udpsocket_1)
	{
		udpsocket_1 = new QUdpSocket;
		connect(udpsocket_1, &QUdpSocket::readyRead, this, &DataReceive::transimitData);
		bool ok = udpsocket_1->bind(port1, QAbstractSocket::ShareAddress | QAbstractSocket::ReuseAddressHint);
		while (!ok)
		{
			ok = udpsocket_1->bind(port1, QAbstractSocket::ShareAddress | QAbstractSocket::ReuseAddressHint);
			QThread::sleep(100);
			bind_error_num++;
			if (bind_error_num > 20)
			{
				emit show_connect_waring(tr("Port binding failed!"), 2);
				bind_error_num = 0;
				delete udpsocket_1;
				return;
			}
		}

	}	
	//用于数据下发
	if (!udpsocket_2)
	{
		udpsocket_2 = new QUdpSocket;
		bool ok2 = udpsocket_2->bind(port1, QAbstractSocket::ShareAddress | QAbstractSocket::ReuseAddressHint);
		while (!ok2)
		{
			ok2 = udpsocket_2->bind(port1, QAbstractSocket::ShareAddress | QAbstractSocket::ReuseAddressHint);
			QThread::sleep(100);
			bind_error_num++;
			if (bind_error_num > 20)
			{
				emit show_connect_waring(tr("Port binding failed!"), 2);
				bind_error_num = 0;
				delete udpsocket_2;
				return;
			}
		}
	}

	m_port_etherNet = port1;

	if (first_link)
	{
		first_link = false;
		QTimer::singleShot(2000, this, &DataReceive::judge_linkStatus);
	}
	m_ip = ip;
}

void DataReceive::update_overfall_state(const bool val)
{
	m_battery_overfall = val;
}

void DataReceive::transimitData()
{
	link_OK = true;

	while (udpsocket_1->hasPendingDatagrams())
	{
		QNetworkDatagram datagram = udpsocket_1->receiveDatagram();
		datagram_queue.append(datagram);
		if (datagram_queue.size() == 4)
		{ 
			if (m_battery_overfall)
			{
				emit sendFor_analyze_save(cache_data);
			}
			else
			{
				if (data_check(datagram_queue.head()))
				{
					cache_data = datagram;
					emit sendFor_analyze_save(datagram_queue.dequeue());
				}
				else
				{
					qDebug() << "data format false" << endl;
					m_error_second++;
					if (m_error_second > 4)
					{
						m_error_second = 0;
						//emit show_connect_waring(tr("Battery data error!"), 2);
					}
					if (!cache_data.data().isEmpty())
					{
						emit sendFor_analyze_save(cache_data);
					}
				}
			}

			datagram_queue.clear();
		}
		
	}
}

bool DataReceive::data_check(QNetworkDatagram datagram)
{
	QByteArray realdata = datagram.data().mid(GZ_Net_Header_len, Battery_Data_len);
	//长度校验 --- zhili pact
	if (realdata.lastIndexOf(0x7E) == -1)
	{
		return false;
	}
	bool lent_check = true, crc_check = true;
	int real_len = realdata.lastIndexOf(0x7E) + 1;
	int pact_len = QByteArray::fromHex(realdata.mid(7, 4)).toHex().toInt(NULL, 16);
	if (real_len != pact_len)
	{
		lent_check = false;
	}
	crc_check = CRC_Check_Zhili(realdata.mid(0, real_len));
	if (lent_check && crc_check)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool DataReceive::CRC_Check_Zhili(const QByteArray data)
{
	//去头去尾
	quint8 crcsum = 0x00;
	for (int i = 1; i < data.size() - 3; i++)
	{
		crcsum += data.at(i);
	}
	crcsum ^= 0xff;

	QByteArray data_t = data.mid(data.size() - 3, 2);
	QByteArray data_ti = QByteArray::fromHex(data_t).toHex();
	int datasum = data_ti.toInt(NULL, 16);

	if (crcsum == datasum)
	{
		return true;
	}
	return false;
}
//向下位机发送指令回包，指令未定
void DataReceive::writePactToVcu(const QByteArray instruct_data)
{
	//向VCU发送指定命令，让其回包
	int a = udpsocket_2->writeDatagram(instruct_data, instruct_data.size(), QHostAddress(m_ip), m_port_etherNet);
}

void DataReceive::judge_linkStatus()
{
	QString tips;
	if (link_OK)
	{
		tips = tr("Communication established successfully");
		emit show_connect_waring(tips, 0);
	}
	else
	{
		tips = tr("Communication established failed");
		emit show_connect_waring(tips, 2);
	}
	first_link = true;
	link_OK = false;
}

void DataReceive::self_init()
{
	first_link = true;
	link_OK = false;
}
