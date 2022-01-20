#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_batteryplatform.h"
#include "XmlThreadPool.h"

#include "datareceive.h"
#include "dataanalyze.h"
#include "logsave.h"
#include "Data_WriteTOExecl.h"
#include <QThread>
#include <QFileDialog>
#include "CustomDataType.h"
#include "mainreference.h"
#include "verifywidget.h"
#include "testinstructhandle.h"
#include "selfdefinecheckwidget.h"
#include "batterywarnningdialog.h"
#include "painterplotwidget.h"

#define m_port_ethernet 20480
#define m_ip_etheret "192.168.0.2"


class BatteryPlatform : public QMainWindow
{
	Q_OBJECT

public:
	BatteryPlatform(QWidget *parent = Q_NULLPTR);
	~BatteryPlatform();

	//slot函数
	void UI_init();
	void registerMetaType();
	void child_thread_init();
	void sendPact(const int);
	void closeEvent(QCloseEvent *event);
	int deal_for_decimal(QString voll);
	void show_warning(const QString data, const int type);
signals:
	void sendPort(const int port1, const QString ip);
	void brandPactType(const int index, const int capacity);
	void startAnalyze(bool val);
	void startVerify(bool val);
	void startSaveLog(const bool val, const QString filepath);
	void update_event_loop_pass(bool val);
	void test_now_free(const bool val);
	void data_report_path(QString data);

private slots:
	void on_StartBtn_clicked();
	void on_Verify_Btn_clicked();
	void on_TurnToUIBtn_clicked();
	void on_pushButton_path_clicked();
	void on_ReturnHome_triggered();
	void on_Closeexe_triggered();
	void on_actionVerify_Data_triggered();
	void on_actionUI_triggered();
private:
	Ui::BatteryPlatformClass ui;
	int selectedPact{ 0 };
	QString LogSavePath;
	QLabel *pact_type{ nullptr };

	QThread *m_threadR{ nullptr };
	QThread *m_threadA{ nullptr };
	QThread *m_threadL{ nullptr };
	QThread *m_threadH{ nullptr };
	QThread *m_thread_xlsx;
	DataReceive *m_receive{ nullptr };
	DataAnalyze *m_analyze{ nullptr };
	LogSave *m_logsave{ nullptr };
	TestInstructHandle *m_handele{ nullptr };
	Data_WriteTOExecl *m_execl{ nullptr };
	MainReference *reference{ nullptr };
	VerifyWidget *verify_widget{ nullptr };

	int m_pact; //用下标表示当前协议
};
