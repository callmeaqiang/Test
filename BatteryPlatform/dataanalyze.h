#pragma once

#include <QNetworkDatagram>
#include <QObject>
#include "CustomDataType.h"
#include "PactInformation.h"



class DataAnalyze : public QObject
{
	Q_OBJECT
public:
	explicit DataAnalyze(QObject *parent = Q_NULLPTR);

	void dataanalyze(const QNetworkDatagram datagram);
	void analyzeForPactOne(QByteArray data);
	void analyzeForPactTwo(QByteArray data);
	void analyzeForPactThree(QByteArray data);
	void VerifyBatteryData(QByteArray data);
	void updateBrandTypePact(const int brand, const int cap);
	void updateAnalyzeAuthority(bool val);
	void updateVerifyState(bool val);
	void check_warning_status(Data_Zhili data);
	void format_verification(QByteArray &data, QList<QString> &list);

	Data_peicheng_Total fusion_data(Data_peicheng data, Data_peicheng_warning waning);

signals:
	void analyzeOver_pactOne(const Data_Zhili data);
	void analyzeOver_pactTwo(const Data_lishen data);

	void checked_info(QList<QString> list);
	void test_soc_Value(const int val);
	void warning_data(const QString data, const int type);

private:

	bool readyToRead{ false };
	bool verifyState{ false };
	int brandPactType{ 0 }; //协议类型
	
	int is_complete{ 0 };//两包数据是否完整
	Data_peicheng m_value;
	Data_peicheng_warning m_warning;

	PactOne pact_one;
	PactTwo pact_two;
	PactThree pact_three;
};

