#pragma once
#include <QObject>
#include <QSharedPointer>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QTimer>
#include <QQueue>


class DataReceive :
	public QObject
{
	Q_OBJECT
public:
	explicit DataReceive(QObject *parent = Q_NULLPTR);
	~DataReceive();

	void connect_to_Server(const int port1, const QString ip);
	void update_overfall_state(const bool val);
	void transimitData();
	bool data_check(QNetworkDatagram datagram);
	bool CRC_Check_Zhili(const QByteArray data);
	void writePactToVcu(const QByteArray instruct_data);
	void judge_linkStatus();
	void self_init();
signals:
	void sendFor_analyze_save(const QNetworkDatagram datagram);
	void BegainToCheck();
	void show_connect_waring(const QString error, const int type);
private:
	QUdpSocket *udpsocket_1{ nullptr };//用来接收电池数据
	QUdpSocket *udpsocket_2{nullptr};//用来发送Can指令
	QQueue<QNetworkDatagram> datagram_queue;
	int bind_error_num{ 0 };
	int m_port_etherNet{ 0 }; //端口号
	bool first_link{ true }; //第一次连接
	bool link_OK{ false }; //连接状态
	QString m_ip; 
	int m_error_second{ 0 }; //数据错误次数 大于5次报错
	QNetworkDatagram cache_data; //缓存上一秒正确的网络数据
	bool m_battery_overfall{ false };  //电池过放状态 初始值为真可避免第一次启动时电池休眠
};
