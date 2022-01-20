#pragma once

#include <QWidget>
#include "ui_mainreference.h"
#include "qcustomplot.h"
#include "CustomDataType.h"
#include <QMenu>
#include <QStandardItemModel>
#include "painterplotwidget.h"
#include "selfdefinecheckwidget.h"
#include "currentaccuracytestdialog.h"
#include "voltageaccuracytestdialog.h"
#include "chargetestdialog.h"
#include "dischargetestdialog.h"
#include "smokingtestdialog.h"
#include "capacitytestdialog.h"
#include "chargeanddischargetestdialog.h"
#include "soctestdialog.h"
#include "protectionparametersdialog.h"
#include <QEventLoop>

class MainReference : public QWidget
{
	Q_OBJECT

public:
	MainReference(QWidget *parent = Q_NULLPTR);
	~MainReference();
	enum Test_type_set
	{
		_simple_charge_, _simple_discharge_, _smoking_test_, _capacity_test_, _charge_discharge_test_, _soc_test_,
		_current_accuracy_, _voltage_accuracy_,_protection_parameters_,
	};

	void Initplot();
	void updatepactOne(Data_Zhili data);
	void updatepactTwo(Data_lishen data);

	void dealForConstructData(const QString name, const QString WhatsThis, const QList<int> list);
	void dealForModifyData(const QList<int> data);

	void dealForLoadInSlot();
	void ModifyBtnSlot();
	void dealForDeleteInstructing_tablewidget();
	void dealForDeleteInstructing_listview();
	void showTestList(bool val);
	bool eventFilter(QObject *watched, QEvent *event);
	void self_dataDelete();
	void self_init(QString voll,  QString capacity);
	int deal_for_decimal(QString voll);


	//测试状态更新
	void write_tessting_name_father(const QString name);
	void write_tessting_name_child(const QString name);
	void write_tested_result_bool(const QString str, const bool val);
	void write_tested_result_str(const QString str, const QString val);
	void write_test_end(const bool val);


	//创建导入参数界面
	void create_testdialog_from_parameters(int type, QString name, QList<int> temp_l);

public:
	PainterPlotWidget *plot_widget{ nullptr };

signals:
	void instructDataList(const QList<QList<int>> data);
	void execl_save_path(const QString filepath);
	void send_test_typelist(QStringList test);
	void update_event_loop_pass(bool val);
	void end_all_test();

private slots:
	void on_TestStartBtn_clicked();
	void on_TestPauseBtn_clicked();
	void on_TestTerminateBtn_clicked();
	void on_comboBox_activated(int index);
	void on_tableWidget_customContextMenuRequested(const QPoint &pos);
	void on_listView_customContextMenuRequested(const QPoint &pos);
	void on_pushButtons_scrool_clicked();
	void on_pushButton_export_parameters_clicked();
	void on_pushButton_import_parameters_clicked();
private:
	Ui::MainReference ui;
	int test_unique_id{ 0 }; //测试唯一的后缀Id
	bool scroll_state{ true };
	int modifyingRow{ 0 }; //修改当前行
	int selectedItemRow{ 0 };
	int m_testNum{ 0 };  //测试配方数
	QString m_capacity; //预设容量
	QString m_voltage;	//预设电压
	QStandardItemModel *model{ nullptr };
	QMenu *menu_listview{ nullptr };
	QMenu *menu_tablewidget{ nullptr };
	QStringList user_select_testname;
	QStringList m_testnamelist;

	QList<ChargeTestDialog*> chargeDialogList; //0
	QList<DischargeTestDialog*> dischargeDialogList;//1
	QList<SmokingTestDialog*> smokingDialogList;//2
	QList<CapacityTestDialog*> capacityDialogList;//3
	QList<ChargeAndDischargeTestDialog*> CD_chargeDialogList;//4
	QList<SOCTestDialog*> SOCDialogList;//5
	QList<CurrentAccuracyTestDialog*> currencyDialogList;//6
	QList<VoltageAccuracyTestDialog*> voltageDialogList;//7
	QList<ProtectionParametersDialog*> protectionDialogList;//4
	QList<QList<int>> instructList; //配方列表
	QList<QList<int>> instructingList; //待测试列表





	//主界面显示chart图像点集
	QVector<double> timeVec;
	QVector<double> chargeCurr;
	QVector<double> dischargeCurr;
	QVector<double> voltage;

	//测试进度变量
	int testing_row{ 0 }; //测试父项所在进度表的行数

	//充放电测试图像点集
	bool isfirst_getCD_data{ true };
	double begaintime{ 0 };
	QVector<double> m_time_CD;
	QVector<double> m_voltage_CD;
	QVector<double> m_chargeCurrent_CD;
	QVector<double> m_dischargeCurrent_CD;
	QVector<double> m_Soc_CD;
	QVector<double> m_Maxtemperature_CD;
};
