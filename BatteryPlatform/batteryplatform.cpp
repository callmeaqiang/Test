#include "batteryplatform.h"
#include <QSettings>
#include <QComboBox>
#include <QMessageBox>
#include "message_box.h"
#include <QFileInfo>


BatteryPlatform::BatteryPlatform(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	UI_init(); //界面初始化
	registerMetaType(); //注册自定义数据类型
	child_thread_init(); //子线程初始化

}

BatteryPlatform::~BatteryPlatform()
{
}

void BatteryPlatform::UI_init()
{
	ui.PactBox->addItem(tr("Zhili Pact"));
	ui.PactBox->addItem(tr("Lishen Pact"));
	ui.PactBox->addItem(tr("Peicheng Pact"));
	//添加状态栏自定义控件
	pact_type = new QLabel("Pact");
	ui.statusBar->addWidget(pact_type);
	//测试界面
	reference = new MainReference;
	ui.stackedWidget->addWidget(reference);
	//校验界面
	verify_widget = new VerifyWidget;
	ui.stackedWidget->addWidget(verify_widget);
	
	QFileInfo fileinfo(QCoreApplication::applicationDirPath() +"/UI_init.ini");
	if (fileinfo.isFile())
	{
		QSettings inifile(QCoreApplication::applicationDirPath() + "/UI_init.ini", QSettings::IniFormat);
		inifile.beginGroup("setting");
		ui.PactBox->setCurrentIndex(inifile.value("pact").toString().toInt());
		ui.lineEdit_CVoltage->setText(inifile.value("voltage").toString());
		ui.lineEdit_Capacity->setText(inifile.value("capacity").toString());
		ui.label_log_path->setText(inifile.value("path").toString());
	}

}

void BatteryPlatform::registerMetaType()
{
	//注册自定义传输数据
	qRegisterMetaType<QNetworkDatagram>("QNetworkDatagram");
	qRegisterMetaType<Data_Zhili>("Data_Zhili");
	qRegisterMetaType<QList<QList<int>>>("QList<QList<int>>");
	qRegisterMetaType<QList<QString>>("QList<QString>");
	qRegisterMetaType<QVector<double>>("QVector<double>");
}

void BatteryPlatform::child_thread_init()
{
	//子线程设置
	m_threadR = new QThread;
	m_threadA = new QThread;
	m_threadL = new QThread;
	m_threadH = new QThread;
	m_thread_xlsx = new QThread;

	m_receive = new DataReceive;
	m_analyze = new DataAnalyze;
	m_logsave = new LogSave;
	m_handele = new TestInstructHandle;
	m_execl = new Data_WriteTOExecl;

	m_analyze->moveToThread(m_threadA);
	m_logsave->moveToThread(m_threadL);
	m_handele->moveToThread(m_threadH);
	m_receive->moveToThread(m_threadR);
	m_execl->moveToThread(m_thread_xlsx);

	m_threadR->start();
	m_threadA->start();
	m_threadL->start();
	m_threadH->start();
	m_thread_xlsx->start();

	connect(this, &BatteryPlatform::sendPort, m_receive, &DataReceive::connect_to_Server);
	connect(m_receive, &DataReceive::sendFor_analyze_save, m_analyze, &DataAnalyze::dataanalyze);
	connect(m_receive, &DataReceive::show_connect_waring, this, &BatteryPlatform::show_warning);
	//对应三种协议的log
	connect(m_analyze, &DataAnalyze::analyzeOver_pactOne, m_logsave, &LogSave::saveLog_zhili);
	connect(m_analyze, &DataAnalyze::analyzeOver_pactTwo, m_logsave, &LogSave::saveLog_lishen);

	connect(m_threadR, &QThread::finished, m_receive, &DataReceive::deleteLater);
	connect(m_threadA, &QThread::finished, m_analyze, &DataAnalyze::deleteLater);
	connect(m_threadL, &QThread::finished, m_logsave, &LogSave::deleteLater);
	connect(m_threadH, &QThread::finished, m_handele, &TestInstructHandle::deleteLater);
	connect(m_thread_xlsx, &QThread::finished, m_execl, &Data_WriteTOExecl::deleteLater);

	//更新UI
	connect(m_analyze, &DataAnalyze::analyzeOver_pactOne, reference, &MainReference::updatepactOne);
	
	connect(m_analyze, &DataAnalyze::analyzeOver_pactTwo, reference, &MainReference::updatepactTwo);
	connect(m_analyze, &DataAnalyze::analyzeOver_pactOne, m_execl, &Data_WriteTOExecl::get_whatWriteToExecl);

	//log保存
	connect(this, &BatteryPlatform::startSaveLog, m_logsave, &LogSave::updateSaveState);
	connect(this, &BatteryPlatform::brandPactType, m_analyze, &DataAnalyze::updateBrandTypePact);
	connect(this, &BatteryPlatform::brandPactType, m_handele, &TestInstructHandle::updateBrandTypePact);
	connect(this, &BatteryPlatform::startAnalyze, m_analyze, &DataAnalyze::updateAnalyzeAuthority);
	connect(this, &BatteryPlatform::brandPactType, m_execl, &Data_WriteTOExecl::update_pact_type);
	connect(this, &BatteryPlatform::update_event_loop_pass, m_handele, &TestInstructHandle::update_loop_pass);

	//协议校验 
	connect(this, &BatteryPlatform::startVerify, m_analyze, &DataAnalyze::updateVerifyState);
	connect(verify_widget, &VerifyWidget::returnHome, this, &BatteryPlatform::on_ReturnHome_triggered);
	connect(m_analyze, &DataAnalyze::checked_info, verify_widget, &VerifyWidget::updateCheckInfo);
	connect(m_analyze, &DataAnalyze::checked_info, m_execl, &Data_WriteTOExecl::write_smoking_data);
	connect(m_analyze, &DataAnalyze::test_soc_Value, m_handele, &TestInstructHandle::update_Soc_Value);


	//测试流程
	connect(reference, &MainReference::instructDataList, m_handele, &TestInstructHandle::get_testInstructList);
	connect(reference, &MainReference::end_all_test, m_handele, &TestInstructHandle::send_EndofData);
	connect(this, &BatteryPlatform::test_now_free, m_handele, &TestInstructHandle::testing_state_free);
	connect(this, &BatteryPlatform::data_report_path, m_execl, &Data_WriteTOExecl::update_execl_path);
	connect(m_handele, &TestInstructHandle::sendInstructArray, m_receive, &DataReceive::writePactToVcu);
	connect(m_handele, &TestInstructHandle::sendHysteresisData, m_execl, &Data_WriteTOExecl::getHysteresisData);
	connect(m_execl, &Data_WriteTOExecl::overfall_state, m_receive, &DataReceive::update_overfall_state);
	connect(m_execl, &Data_WriteTOExecl::teminate_device, m_handele, &TestInstructHandle::send_EndofData);
	connect(m_execl, &Data_WriteTOExecl::start_next_Alone, m_handele, &TestInstructHandle::update_next_alone);
	connect(m_execl, &Data_WriteTOExecl::start_next_multiple, m_handele, &TestInstructHandle::update_next_mulitiple);
	connect(m_execl, &Data_WriteTOExecl::start_verify_test, m_analyze, &DataAnalyze::updateVerifyState);
	connect(reference, &MainReference::update_event_loop_pass, m_handele, &TestInstructHandle::update_loop_pass);

	//测试状态更新在界面
	connect(m_handele, &TestInstructHandle::testing_name_father, reference, &MainReference::write_tessting_name_father);
	connect(m_handele, &TestInstructHandle::testing_name_child, reference, &MainReference::write_tessting_name_child);
	connect(m_handele, &TestInstructHandle::testing_name_logsave, m_logsave, &LogSave::update_test_name);
	connect(m_handele, &TestInstructHandle::write_execl_test_condition, m_execl, &Data_WriteTOExecl::write_test_condition);
	connect(m_execl, &Data_WriteTOExecl::tested_result_bool, reference, &MainReference::write_tested_result_bool);
	connect(m_execl, &Data_WriteTOExecl::tested_result_str, reference, &MainReference::write_tested_result_str);
	connect(m_execl, &Data_WriteTOExecl::tested_end, reference, &MainReference::write_test_end);
	connect(m_execl, &Data_WriteTOExecl::painter_data_for_CD_test, reference->plot_widget, &PainterPlotWidget::update_Plot_for_CD_test);
	connect(m_execl, &Data_WriteTOExecl::painter_data_for_SOC_test, reference->plot_widget, &PainterPlotWidget::update_Plot_for_SOC_test);
}

void BatteryPlatform::closeEvent(QCloseEvent * event)
{
	Message_Box ibox(tr("Are you sure to close the program ?"), 1, this);
	ibox.move((this->width() - ibox.width()) / 2, (this->height() - ibox.height()) / 2);
	ibox.exec();
	if (!ibox.get_accept_status())
	{
		event->ignore();
		return;
	}
	//保存ini文件
	QSettings iniFile(QCoreApplication::applicationDirPath() +"/UI_init.ini", QSettings::IniFormat);
	iniFile.setIniCodec(QTextCodec::codecForName("utf-8"));
	iniFile.beginGroup("setting");
	iniFile.setValue("pact", selectedPact);
	iniFile.setValue("voltage", ui.lineEdit_CVoltage->text());
	iniFile.setValue("capacity", ui.lineEdit_Capacity->text());
	iniFile.setValue("path", ui.label_log_path->text());
	iniFile.endArray();
	iniFile.sync();

	if (m_threadR)
	{
		m_threadR->quit();
		m_threadR->wait();
		m_threadR->deleteLater();
	}
	if (m_threadA)
	{
		m_threadA->quit();
		m_threadA->wait();
		m_threadA->deleteLater();
	}
	if (m_threadL)
	{
		m_threadL->quit();
		m_threadL->wait();
		m_threadL->deleteLater();
	}

	if (m_thread_xlsx)
	{
		m_thread_xlsx->quit();
		m_thread_xlsx->wait();
		m_thread_xlsx->deleteLater();
	}
	if (m_threadH)
	{
		emit update_event_loop_pass(true);
		qDebug() << "---------------------------------->>>>>>>>>>>>>>>>>>>>> dkskdsk" << endl;
		m_threadH->quit();
		m_threadH->wait();
		delete m_threadH;
	}
	QWidget::closeEvent(event);
}

int BatteryPlatform::deal_for_decimal(QString voll)
{
	if (voll.contains("."))
	{
		int index = voll.indexOf(".");
		int str_size = voll.size();
		voll.remove(".");
		int tem_val = voll.toInt() / pow(10, str_size - index - 2);
		return tem_val;
	}

	return voll.toInt() * 10;
}
void BatteryPlatform::show_warning(const QString data, const int type)
{	
	Message_Box ibox(data, type, this);
	ibox.move((this->width() - ibox.width()) / 2, (this->height() - ibox.height()) / 2);
	ibox.exec();
}
void BatteryPlatform::on_StartBtn_clicked()
{
	if (ui.label_log_path->text().isEmpty())
	{
		QMessageBox::warning(this, tr("Warning"), tr("Please choose report path!"));
		return;
	}
	//开始前，结束当前的数据解析
	emit startAnalyze(false);
	emit startSaveLog(false, " ");
	m_receive->self_init();
	reference->self_init(ui.lineEdit_CVoltage->text(), ui.lineEdit_Capacity->text());
	
	selectedPact = ui.PactBox->currentIndex();
	if (selectedPact == 0)
	{
		QMessageBox::warning(this, tr("Choose Pact"), tr("Please choose pact"));
		return;
	}
	switch (selectedPact)
	{
	case 1:
		pact_type->setText(tr("Zhili pact"));
		break;
	case 2:
		pact_type->setText(tr("Lishen pact"));
		break;
	case 3:
		pact_type->setText(tr("Peicheng pact"));
		break;
	default:
		break;
	}
	emit brandPactType(selectedPact, deal_for_decimal(ui.lineEdit_Capacity->text()));
	emit sendPort(m_port_ethernet, m_ip_etheret);
	emit data_report_path(ui.label_log_path->text());
	emit startAnalyze(true);
	emit startSaveLog(true, ui.label_log_path->text());
	emit test_now_free(true);
}

void BatteryPlatform::on_Verify_Btn_clicked()
{
	ui.stackedWidget->setCurrentIndex(2);
	emit startVerify(true);   // ---------->>开启数据校验
}

void BatteryPlatform::on_TurnToUIBtn_clicked()
{
	ui.stackedWidget->setCurrentIndex(1);
}

void BatteryPlatform::on_pushButton_path_clicked()
{
	LogSavePath = QFileDialog::getExistingDirectory(this, tr("choose log save path"), QCoreApplication::applicationDirPath());
	ui.label_log_path->setText(LogSavePath);
}

void BatteryPlatform::on_ReturnHome_triggered()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void BatteryPlatform::on_Closeexe_triggered()
{
	this->close();
}

void BatteryPlatform::on_actionVerify_Data_triggered()
{
	ui.stackedWidget->setCurrentIndex(2);
	emit startVerify(true);   // ---------->>开启数据校验
}

void BatteryPlatform::on_actionUI_triggered()
{
	ui.stackedWidget->setCurrentIndex(1);
}
