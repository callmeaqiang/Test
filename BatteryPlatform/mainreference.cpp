#include "mainreference.h"
#include <QStandardItemModel>
#include <QAction>
#include <QMouseEvent>
#include <QModelIndex>
#include <QFileDialog>
#include <QtXlsx/QtXlsx>
#include <qmath.h>

MainReference::MainReference(QWidget *parent)
	: QWidget(parent), modifyingRow(0), selectedItemRow(0),m_testNum(0)
{
	ui.setupUi(this);

	//初始化UI界面
	plot_widget = new PainterPlotWidget();
	ui.stackedWidget->addWidget(plot_widget);
	ui.stackedWidget->setCurrentIndex(0);
	Initplot();
	ui.tabWidget->setCurrentIndex(0);

	model = new QStandardItemModel;
	ui.tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
	ui.listView->setContextMenuPolicy(Qt::CustomContextMenu);
	menu_tablewidget = new QMenu(ui.tableWidget);
	menu_listview = new QMenu(ui.listView);
	QAction *Delaction_tablewidget = new QAction("delete");
	menu_tablewidget->addAction(Delaction_tablewidget);
	connect(Delaction_tablewidget, &QAction::triggered, this, &MainReference::dealForDeleteInstructing_tablewidget);

	QAction *Delaction_listview = new QAction("delete");
	menu_listview->addAction(Delaction_listview);
	connect(Delaction_listview, &QAction::triggered, this, &MainReference::dealForDeleteInstructing_listview);	
}

MainReference::~MainReference()
{
	self_dataDelete();
}

void MainReference::Initplot()
{
	//分裂器初始化
	QList<int> sizes;
	// 在保持比例的情况下，绝对值要尽量大
	sizes << 30000 << 20000 << 50000;
	ui.splitter->setSizes(sizes);
	//customplot
	//实时电压
	ui.customplot->addGraph();
	ui.customplot->graph(0)->setPen(QPen(Qt::blue, 1));
	ui.customplot->graph(0)->setName(tr("ChargeCurrent"));
	ui.customplot->addGraph();
	ui.customplot->graph(1)->setPen(QPen(Qt::red, 1));
	ui.customplot->graph(1)->setName(tr("DischargeCurrent"));
	ui.customplot->addGraph();
	ui.customplot->graph(2)->setPen(QPen(QBrush(QColor()), 1));
	ui.customplot->graph(2)->setName(tr("Voltage"));
	ui.customplot->axisRect()->setBackground(QBrush(Qt::white));//背景色
	QColor colorLightBlue = QColor("#67c2ff");

	ui.customplot->xAxis->grid()->setPen(QPen(QColor(255, 255, 255, 0), 1, Qt::PenStyle::DashLine));//网格白色虚线
	ui.customplot->xAxis->grid()->setSubGridPen(QPen(QColor(255, 255, 255, 0), 1, Qt::PenStyle::DashLine));//网格白色虚线
	//显示图例，图例背景透明
	ui.customplot->legend->setVisible(true);
	ui.customplot->legend->setBrush(QColor(255, 255, 255, 0));
	//设置chart的拖拽、放缩属性
	ui.customplot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
		QCP::iSelectLegend | QCP::iSelectPlottables);
	ui.customplot->graph(0)->setScatterStyle(QCPScatterStyle::ssDisc);
	ui.customplot->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);
	ui.customplot->graph(2)->setScatterStyle(QCPScatterStyle::ssDisc);
	//设置x轴，y轴
	ui.customplot->yAxis->setLabel(tr("/A"));
	ui.customplot->xAxis->setLabel(tr("time"));
	//设置x轴坐标格式
	QSharedPointer<QCPAxisTickerDateTime> dateTick(new QCPAxisTickerDateTime);
	dateTick->setDateTimeFormat(tr("hh:mm:ss\nyyyy-MM-dd"));
	dateTick->setTickCount(10);
	ui.customplot->xAxis->setTicker(dateTick);
	ui.customplot->yAxis->ticker()->setTickCount(10);//11个主刻度
	ui.customplot->xAxis->setTickLabels(true);
	//设置y轴坐标范围
	ui.customplot->yAxis->setRange(-2, 102);
	ui.customplot->axisRect()->setupFullAxesBox();//四边安装轴并显示

	//tabwidget初始化
	ui.tableWidget->setColumnCount(3);
	ui.tableWidget->setColumnWidth(0, 200);
	ui.tableWidget->setColumnWidth(1, 100);
	ui.tableWidget->setColumnWidth(2, 100);
	ui.tableWidget->horizontalHeader()->setFixedHeight(30);
	ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
	ui.tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
	ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
	ui.tableWidget->verticalHeader()->hide();

	//tabwidget_testingState初始化
	//初始化表格属性
	QStringList header;
	header << "Test type" << "Test process" << "Test result";
	ui.tableWidget_testingInfo->setColumnCount(3);
	ui.tableWidget_testingInfo->setColumnWidth(0, 200);
	ui.tableWidget_testingInfo->setColumnWidth(1, 400);
	ui.tableWidget_testingInfo->setColumnWidth(2, 100);
	ui.tableWidget_testingInfo->setHorizontalHeaderLabels(header);
	ui.tableWidget_testingInfo->horizontalHeader()->setFixedHeight(30);
	ui.tableWidget_testingInfo->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tableWidget_testingInfo->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
	ui.tableWidget_testingInfo->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
	ui.tableWidget_testingInfo->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
	ui.tableWidget_testingInfo->verticalHeader()->hide();

	// 拖拽设置
	ui.listView->setDragDropMode(QAbstractItemView::InternalMove);  // 内部移动
	ui.listView->setDropIndicatorShown(true);  // drop位置 提示
	ui.listView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.listView->viewport()->installEventFilter(this);
}

void MainReference::updatepactOne(Data_Zhili data)
{
	ui.Voltage->setText(QString("%1").arg(data.voltage, 0, 'f', 3));
	ui.socLable->setText(QString::number(data.Soc));
	ui.chargeNum->setText(QString::number(data.ChgNum));
	ui.dischargeNum->setText(QString::number(data.DchgNum));
	ui.capicityLable->setText(QString("%1").arg(data.CapNow, 0, 'f', 3));
	ui.fill_capicityLable->setText(QString("%1").arg(data.CapFull, 0, 'f', 3));
	ui.charge_Current->setText(QString("%1").arg(data.charge_current, 0, 'f', 3));
	ui.discharge_Current->setText(QString("%1").arg(data.discharge_current, 0, 'f', 3));
	ui.CState->setText(QString::number(data.cstate_list));
	ui.VState->setText(QString::number(data.vstate_list));
	ui.FETState->setText(QString::number(data.fetstate_list));
	//电芯电压更新
	if (data.Vcell_num < 8)
	{
		return;
	}
	ui.voltage_1->setText(QString("%1").arg(data.Vcell_list.at(0), 0, 'f', 3));
	ui.voltage_2->setText(QString("%1").arg(data.Vcell_list.at(1), 0, 'f', 3));
	ui.voltage_3->setText(QString("%1").arg(data.Vcell_list.at(2), 0, 'f', 3));
	ui.voltage_4->setText(QString("%1").arg(data.Vcell_list.at(3), 0, 'f', 3));
	ui.voltage_5->setText(QString("%1").arg(data.Vcell_list.at(4), 0, 'f', 3));
	ui.voltage_6->setText(QString("%1").arg(data.Vcell_list.at(5), 0, 'f', 3));
	ui.voltage_7->setText(QString("%1").arg(data.Vcell_list.at(6), 0, 'f', 3));
	ui.voltage_8->setText(QString("%1").arg(data.Vcell_list.at(7), 0, 'f', 3));
	if (data.Vcell_num == 8)
	{
		ui.frame_cell8->show();
		ui.frame_cell12->show();
		ui.frame_cell16->hide();
	} //电芯电压
	else if (data.Vcell_num == 12)
	{
		ui.frame_cell8->show();
		ui.frame_cell12->show();
		ui.frame_cell16->hide();
		ui.voltage_9->setText(QString("%1").arg(data.Vcell_list.at(8), 0, 'f', 3));
		ui.voltage_10->setText(QString("%1").arg(data.Vcell_list.at(9), 0, 'f', 3));
		ui.voltage_11->setText(QString("%1").arg(data.Vcell_list.at(10), 0, 'f', 3));
		ui.voltage_12->setText(QString("%1").arg(data.Vcell_list.at(11), 0, 'f', 3));
	}
	else if (data.Vcell_num == 16)
	{
		ui.frame_cell8->show();
		ui.frame_cell12->show();
		ui.frame_cell16->show();
		ui.voltage_9->setText(QString("%1").arg(data.Vcell_list.at(8), 0, 'f', 3));
		ui.voltage_10->setText(QString("%1").arg(data.Vcell_list.at(9), 0, 'f', 3));
		ui.voltage_11->setText(QString("%1").arg(data.Vcell_list.at(10), 0, 'f', 3));
		ui.voltage_12->setText(QString("%1").arg(data.Vcell_list.at(11), 0, 'f', 3));
		ui.voltage_13->setText(QString("%1").arg(data.Vcell_list.at(12), 0, 'f', 3));
		ui.voltage_14->setText(QString("%1").arg(data.Vcell_list.at(13), 0, 'f', 3));
		ui.voltage_15->setText(QString("%1").arg(data.Vcell_list.at(14), 0, 'f', 3));
		ui.voltage_16->setText(QString("%1").arg(data.Vcell_list.at(15), 0, 'f', 3));
	}
	else
	{
		return;
	}
	//温度值更新
	if (data.Temp_Num >= 5)
	{
		ui.temp_1->setText(QString("%1").arg(data.temp_list.at(0)));
		ui.temp_2->setText(QString("%1").arg(data.temp_list.at(1)));
		ui.temp_3->setText(QString("%1").arg(data.temp_list.at(2)));
		ui.temp_4->setText(QString("%1").arg(data.temp_list.at(3)));
		ui.temp_5->setText(QString("%1").arg(data.temp_list.at(4)));
	}


	ui.label_ChargerStatus->setText(QString::number(data.Charger_Status));
	ui.label_CVF->setText(QString("%1").arg(data.Charger_Voltage, 0, 'f', 3));
	ui.label_CCF->setText(QString("%1").arg(data.Charger_Current, 0, 'f', 3));
	ui.label_BVM->setText(QString("%1").arg(data.Battery_Voltage_Measured, 0, 'f', 3));
	ui.label_CCM->setText(QString("%1").arg(data.Charging_Current_Measured, 0, 'f', 3));
	ui.label_PSD1Temperature->setText(QString::number(data.PSD1_Temperature));
	ui.label_PSD2Temperature->setText(QString::number(data.PSD2_Temperature));
	ui.label_PCM_1->setText(QString("%1").arg(data.PSD1_Current_Measured, 0, 'f', 3));
	ui.label_PCM2->setText(QString("%1").arg(data.PSD2_Current_Measured, 0, 'f', 3));

	QDateTime time = QDateTime::currentDateTime();
	timeVec.append(time.toMSecsSinceEpoch()*0.001);
	chargeCurr.append(data.charge_current);
	dischargeCurr.append(data.discharge_current);
	voltage.append(data.voltage);
	if (scroll_state)
	{
		ui.customplot->xAxis->setRange((time.toMSecsSinceEpoch() - 10000)*0.001, time.toMSecsSinceEpoch()*0.001);
	}
	

	ui.customplot->graph(0)->setData(timeVec, chargeCurr);
	ui.customplot->graph(1)->setData(timeVec, dischargeCurr);
	ui.customplot->graph(2)->setData(timeVec, voltage);
	ui.customplot->replot();
}

void MainReference::updatepactTwo(Data_lishen data)
{
	ui.Voltage->setText(QString("%1").arg(data.voltage, 0, 'f', 2));
	ui.socLable->setText(QString::number(data.Soc));
}

void MainReference::dealForConstructData(const QString name, const QString WhatsThis, const QList<int> list)
{
	ui.tableWidget->insertRow(m_testNum);
	ui.tableWidget->setRowHeight(m_testNum, 50);
	QLabel *label = new QLabel(name);
	ui.tableWidget->setCellWidget(m_testNum, 0, label);
	QPushButton *btn = new QPushButton(tr("Modify"));
	btn->setWhatsThis(WhatsThis + "Btn");
	connect(btn, &QPushButton::clicked, this, &MainReference::ModifyBtnSlot);
	ui.tableWidget->setCellWidget(m_testNum, 1, btn);
	QPushButton* begainBtn = new QPushButton(tr("LoadIn"));
	begainBtn->setWhatsThis(WhatsThis + "LoadInBtn");
	connect(begainBtn, &QPushButton::clicked, this, &MainReference::dealForLoadInSlot);
	ui.tableWidget->setCellWidget(m_testNum, 2, begainBtn);

	instructList.append(list);
	m_testNum++;
	user_select_testname.append(name);
	qDebug() << "22222222222222" << endl;
}

void MainReference::dealForModifyData(const QList<int> data)
{
	instructList.removeAt(modifyingRow);
	instructList.insert(modifyingRow, data);
}

void MainReference::dealForLoadInSlot()
{
	QPushButton *btn = qobject_cast<QPushButton*>(sender());

	for (int i = 0; i < ui.tableWidget->rowCount(); i++)
	{
		QPushButton *btn_t = qobject_cast<QPushButton*>(ui.tableWidget->cellWidget(i, 2));
		if (btn_t->whatsThis() == btn->whatsThis())
		{
			QLabel *lab = qobject_cast<QLabel*>(ui.tableWidget->cellWidget(i, 0));
			instructingList.append(instructList.at(i));
			QStandardItem *item = new QStandardItem(lab->text());
			model->appendRow(item);
			ui.listView->setModel(model);
			break;
		}
	}
}

void MainReference::dealForDeleteInstructing_tablewidget()
{
	ui.tableWidget->model()->removeRow(selectedItemRow);
	instructList.removeAt(selectedItemRow);
	user_select_testname.removeAt(selectedItemRow);
	m_testNum--;
}

void MainReference::dealForDeleteInstructing_listview()
{
	ui.listView->model()->removeRow(selectedItemRow);
	instructingList.removeAt(selectedItemRow);
}

void MainReference::ModifyBtnSlot()
{
	QPushButton *btn = qobject_cast<QPushButton*>(sender());
	QString test = btn->whatsThis();

	for (int i = 0; i < ui.tableWidget->rowCount(); i++)
	{
		QPushButton *btn_t = qobject_cast<QPushButton*>(ui.tableWidget->cellWidget(i, 1));
		if (btn_t->whatsThis() == test)
		{
			if (test.contains("Simple_Charge"))
			{
				int num_index = test.indexOf("Simple_Charge") + QString("Simple_Charge").size();
				QString unique_id = test.mid(num_index, test.indexOf("Btn") - num_index);
				for (int j = 0; j < chargeDialogList.size(); j++)
				{
					if (chargeDialogList.at(j)->whatsThis() == "Simple_Charge_Dialog" + unique_id)
					{
						modifyingRow = i;
						chargeDialogList.at(j)->ModifyInit();
						chargeDialogList.at(j)->exec();
						return;
					}
				}
			}
			if (test.contains("Simple_Discharge"))
			{
				int num_index = test.indexOf("Simple_Discharge") + QString("Simple_Discharge").size();
				QString unique_id = test.mid(num_index, test.indexOf("Btn") - num_index);
				for (int j = 0; j < dischargeDialogList.size(); j++)
				{
					if (dischargeDialogList.at(j)->whatsThis() == "Simple_Discharge_Dialog" + unique_id)
					{
						modifyingRow = i;
						dischargeDialogList.at(j)->ModifyInit();
						dischargeDialogList.at(j)->exec();
						return;
					}
				}
			}
			if (test.contains("Smoking"))
			{
				int num_index = test.indexOf("Smoking") + QString("Smoking").size();
				QString unique_id = test.mid(num_index, test.indexOf("Btn") - num_index);
				for (int j = 0; j < smokingDialogList.size(); j++)
				{
					if (smokingDialogList.at(j)->whatsThis() == "Smoking_Test_Dialog" + unique_id)
					{
						modifyingRow = i;
						smokingDialogList.at(j)->ModifyInit();
						smokingDialogList.at(j)->exec();
						return;
					}
				}
			}
			if (test.contains("Capacity"))
			{
				int num_index = test.indexOf("Capacity") + QString("Capacity").size();
				QString unique_id = test.mid(num_index, test.indexOf("Btn") - num_index);
				for (int j = 0; j < capacityDialogList.size(); j++)
				{
					if (capacityDialogList.at(j)->whatsThis() == "Capacity_Test_Dialog" + unique_id)
					{
						modifyingRow = i;
						capacityDialogList.at(j)->ModifyInit();
						capacityDialogList.at(j)->exec();
						return;
					}
				}
			}
			if (test.contains("Charge_Discharge"))
			{
				int num_index = test.indexOf("Charge_Discharge") + QString("Charge_Discharge").size();
				QString unique_id = test.mid(num_index, test.indexOf("Btn") - num_index);
				for (int j = 0; j < CD_chargeDialogList.size(); j++)
				{
					if (CD_chargeDialogList.at(j)->whatsThis() == "Charge_Discharge_Test_Dialog" + unique_id)
					{
						modifyingRow = i;
						CD_chargeDialogList.at(j)->ModifyInit();
						CD_chargeDialogList.at(j)->exec();
						return;
					}
				}
			}
			if (test.contains("SOC"))
			{
				int num_index = test.indexOf("SOC") + QString("SOC").size();
				QString unique_id = test.mid(num_index, test.indexOf("Btn") - num_index);
				for (int j = 0; j < SOCDialogList.size(); j++)
				{
					if (SOCDialogList.at(j)->whatsThis() == "SOC_Test_Dialog" + unique_id)
					{
						modifyingRow = i;
						SOCDialogList.at(j)->ModifyInit();
						SOCDialogList.at(j)->exec();
						return;
					}
				}
			}
			if (test.contains("Current_Accuracy"))
			{
				int num_index = test.indexOf("Current_Accuracy") + QString("Current_Accuracy").size();
				QString unique_id = test.mid(num_index, test.indexOf("Btn") - num_index);
				for (int j = 0; j < currencyDialogList.size(); j++)
				{
					if (currencyDialogList.at(j)->whatsThis() == "Current_Accuracy_Test_Dialog" + unique_id)
					{
						modifyingRow = i;
						currencyDialogList.at(j)->ModifyInit();
						currencyDialogList.at(j)->exec();
						return;
					}
				}
			}
			if (test.contains("Voltage_Accuracy"))
			{
				int num_index = test.indexOf("Voltage_Accuracy") + QString("Voltage_Accuracy").size();
				QString unique_id = test.mid(num_index, test.indexOf("Btn") - num_index);
				for (int j = 0; j < voltageDialogList.size(); j++)
				{
					if (voltageDialogList.at(j)->whatsThis() == "Voltage_Accuracy_Test_Dialog" + unique_id)
					{
						modifyingRow = i;
						voltageDialogList.at(j)->ModifyInit();
						voltageDialogList.at(j)->exec();
						return;
					}
				}
			}
			if (test.contains("Protection_Parameters"))
			{
				int num_index = test.indexOf("Protection_Parameters") + QString("Protection_Parameters").size();
				QString unique_id = test.mid(num_index, test.indexOf("Btn") - num_index);
				for (int j = 0; j < protectionDialogList.size(); j++)
				{
					if (protectionDialogList.at(j)->whatsThis() == "Protection_Parameters_Test_Dialog" + unique_id)
					{
						modifyingRow = i;
						protectionDialogList.at(j)->ModifyInit();
						protectionDialogList.at(j)->exec();
						return;
					}
				}
			}
		}		
	}
}

void MainReference::showTestList(bool val)
{
	if (!val)
	{
		if (m_testnamelist.last().contains("Simple_Charge_Dialog"))
		{
			delete chargeDialogList.last();
			chargeDialogList.removeLast();
		}
		else if (m_testnamelist.last().contains("Simple_Discharge_Dialog"))
		{
			delete dischargeDialogList.last();
			dischargeDialogList.removeLast();
		}
		else if (m_testnamelist.last().contains("Smoking_Test_Dialog"))
		{
			delete smokingDialogList.last();
			smokingDialogList.removeLast();
		}
		else if (m_testnamelist.last().contains("Capacity_Test_Dialog"))
		{
			delete capacityDialogList.last();
			capacityDialogList.removeLast();
		}
		else if (m_testnamelist.last().contains("Charge_Discharge_Test_Dialog"))
		{
			delete CD_chargeDialogList.last();
			CD_chargeDialogList.removeLast();
		}
		else if (m_testnamelist.last().contains("SOC_Test_Dialog"))
		{
			delete SOCDialogList.last();
			SOCDialogList.removeLast();
		}
		else if (m_testnamelist.last().contains("Current_Accuracy_Test_Dialog"))
		{
			delete currencyDialogList.last();
			currencyDialogList.removeLast();
		}
		else if (m_testnamelist.last().contains("Voltage_Accuracy_Test_Dialog"))
		{
			delete voltageDialogList.last();
			voltageDialogList.removeLast();
		}
		else if (m_testnamelist.last().contains("Protection_Parameters_Test_Dialog"))
		{
			delete protectionDialogList.last();
			protectionDialogList.removeLast();
		}
	}
}

bool MainReference::eventFilter(QObject * watched, QEvent * event)
{
	if (watched == ui.listView->viewport())
	{
		if (event->type() == QEvent::Drop)
		{
			int row_src, row_dst;
			row_src = ui.listView->currentIndex().row();
			qDebug() << row_src;// 原行号 可加if
			QModelIndex index = ui.listView->indexAt(((QDropEvent *)event)->pos()); // 获取落点的item
			if (index.isValid()) {                                        // 判断是否为空
				row_dst = index.row();                                 // 不为空 获取其行号
				if (row_dst == row_src)
				{
					return true;
				}
			}
			else // 落点没有item 说明拖动到了最下面
			{                          
				return true;// 获取行总数
			}
			instructingList.swap(row_src, row_dst);

			//处理列表名称交换
			if (row_src > row_dst)
			{
				QStandardItem *item0 = model->item(row_src);
				QStandardItem *item1 = model->item(row_dst);
				QString text0 = item0->text();
				QString text1 = item1->text();
				model->removeRow(row_src);
				model->removeRow(row_dst);
				QStandardItem *Item2 = new QStandardItem(text0);
				QStandardItem *Item3 = new QStandardItem(text1);

				model->insertRow(row_dst, Item2);
				model->insertRow(row_src, Item3);
			}
			else
			{
				QStandardItem *item0 = model->item(row_dst);
				QStandardItem *item1 = model->item(row_src);
				QString text0 = item0->text();
				QString text1 = item1->text();
				model->removeRow(row_dst);
				model->removeRow(row_src);
				QStandardItem *Item2 = new QStandardItem(text0);
				QStandardItem *Item3 = new QStandardItem(text1);

				model->insertRow(row_src, Item2);
				model->insertRow(row_dst, Item3);
			}
			ui.listView->setModel(model);
			ui.listView->setCurrentIndex(ui.listView->model()->index(row_dst, 0));
			// 执行移动 并移除原行
			return true;
		}
		else
		{
			return QWidget::eventFilter(watched, event);
		}
	}
	return QWidget::eventFilter(watched, event);
}

void MainReference::self_dataDelete()
{
	for (int i = 0;i < chargeDialogList.size();i++)
	{
		if (chargeDialogList.at(i))
		{
			delete chargeDialogList.at(i);
		}
	}
	for (int i = 0;i < dischargeDialogList.size();i++)
	{
		if (dischargeDialogList.at(i))
		{
			delete dischargeDialogList.at(i);
		}
	}
	for (int i = 0;i < currencyDialogList.size();i++)
	{
		if (currencyDialogList.at(i))
		{
			delete currencyDialogList.at(i);
		}
	}
	for (int i = 0;i < voltageDialogList.size();i++)
	{
		if (voltageDialogList.at(i))
		{
			delete voltageDialogList.at(i);
		}
	}
	for (int i = 0;i < smokingDialogList.size();i++)
	{
		if (smokingDialogList.at(i))
		{
			delete smokingDialogList.at(i);
		}
	}
	for (int i = 0;i < CD_chargeDialogList.size();i++)
	{
		if (CD_chargeDialogList.at(i))
		{
			delete CD_chargeDialogList.at(i);
		}
	}
	for (int i = 0;i < SOCDialogList.size();i++)
	{
		if (SOCDialogList.at(i))
		{
			delete SOCDialogList.at(i);
		}
	}
	for (int i = 0;i < capacityDialogList.size();i++)
	{
		if (capacityDialogList.at(i))
		{
			delete capacityDialogList.at(i);
		}
	}
	for (int i = 0;i < protectionDialogList.size();i++)
	{
		if (protectionDialogList.at(i))
		{
			delete protectionDialogList.at(i);
		}
	}
	
}

void MainReference::self_init(QString voll, QString capacity)
{
	m_capacity = capacity;
	m_voltage = voll;
	modifyingRow = 0;
	selectedItemRow = 0;
	m_testNum = 0;
	m_testnamelist.clear();
	self_dataDelete();
	//dialog窗口列表清空
	chargeDialogList.clear();
	dischargeDialogList.clear();
	smokingDialogList.clear();
	capacityDialogList.clear();
	CD_chargeDialogList.clear();
	SOCDialogList.clear();
	instructList.clear();
	instructingList.clear();
	model->clear();
	ui.listView->setModel(model);
	int rowcount = ui.tableWidget->rowCount();
	for (int i = 0; i < rowcount; i++)
	{
		ui.tableWidget->removeRow(i);
	}
	//图表清空
	timeVec.clear();
	chargeCurr.clear();
	dischargeCurr.clear();
	voltage.clear();
	ui.customplot->graph(0)->data().data()->clear();
	ui.customplot->graph(1)->data().data()->clear();
	ui.customplot->graph(2)->data().data()->clear();
}

int MainReference::deal_for_decimal(QString voll)
{
	if (voll.contains("."))
	{
		int index = voll.indexOf(".");
		int str_size = voll.size();
		voll.remove(".");
		int tem_val = voll.toInt() / pow(10, str_size - index -2);
		return tem_val;
	}

	return voll.toInt() * 10;
}

void MainReference::write_tessting_name_father(const QString name)
{
	testing_row = ui.tableWidget_testingInfo->rowCount();
	ui.tableWidget_testingInfo->insertRow(testing_row);
	QTableWidgetItem *item1 = new QTableWidgetItem(name);
	item1->setFont(QFont("Microsoft YaHei", 12, 10));
	ui.tableWidget_testingInfo->setItem(testing_row, 0, item1);
}

void MainReference::write_tessting_name_child(const QString name)
{
	QTableWidgetItem *item1 = new QTableWidgetItem(name);
	item1->setFont(QFont("Microsoft YaHei", 12, 10));
	item1->setTextColor(QColor(200, 0, 0));
	ui.tableWidget_testingInfo->setItem(testing_row, 1, item1);
}

void MainReference::write_tested_result_bool(const QString str, const bool val)
{
	int num_t = ui.tableWidget_testingInfo->rowCount();
	ui.tableWidget_testingInfo->insertRow(num_t);
	QTableWidgetItem *item1 = new QTableWidgetItem(str);
	QTableWidgetItem *item2;
	if (val)
	{
		item2 = new QTableWidgetItem("Pass");
		item2->setTextColor(QColor(0, 200, 0));
	}
	else
	{
		item2 = new QTableWidgetItem("False");
		item2->setTextColor(QColor(200, 0, 0));
	}
	
	item1->setFont(QFont("Microsoft YaHei", 10, 6));
	item2->setFont(QFont("Microsoft YaHei", 10, 6));
	ui.tableWidget_testingInfo->setItem(num_t, 1, item1);
	ui.tableWidget_testingInfo->setItem(num_t, 2, item2);
}

void MainReference::write_tested_result_str(const QString str, const QString val)
{
	int num_t = ui.tableWidget_testingInfo->rowCount();
	ui.tableWidget_testingInfo->insertRow(num_t);
	QTableWidgetItem *item1 = new QTableWidgetItem(str);
	QTableWidgetItem *item2 = new QTableWidgetItem(val);
	item1->setFont(QFont("Microsoft YaHei", 10, 6));
	item2->setFont(QFont("Microsoft YaHei", 10, 6));
	ui.tableWidget_testingInfo->setItem(num_t, 1, item1);
	ui.tableWidget_testingInfo->setItem(num_t, 2, item2);
}

void MainReference::write_test_end(const bool val)
{
	QTableWidgetItem *item1 = new QTableWidgetItem(tr("Finished"));
	QTableWidgetItem *item2;
	if (val)
	{
		item2  = new QTableWidgetItem("Pass");
		item2->setTextColor(QColor(0, 200, 0));
	}
	else
	{
		item2 = new QTableWidgetItem("False");
		item2->setTextColor(QColor(200, 0, 0));
	}
	item1->setFont(QFont("Microsoft YaHei", 12, 10));
	item2->setTextColor(QColor(0, 200, 0));
	item2->setFont(QFont("Microsoft YaHei", 12, 10));
	ui.tableWidget_testingInfo->setItem(testing_row, 1, item1);
	ui.tableWidget_testingInfo->setItem(testing_row, 2, item2);
}

void MainReference::on_TestStartBtn_clicked()
{
	if (instructingList.isEmpty())
		return;
	emit update_event_loop_pass(false); //开启测试循环
	emit instructDataList(instructingList);

}

void MainReference::create_testdialog_from_parameters(int type, QString name, QList<int> temp_l)
{
	switch (type)
	{
	case _simple_charge_:
	{
		ChargeTestDialog *charge_dialog = new ChargeTestDialog(name, test_unique_id, temp_l);
		charge_dialog->setWhatsThis("Simple_Charge_Dialog" + QString::number(test_unique_id));
		m_testnamelist.append("Simple_Charge_Dialog" + QString::number(test_unique_id));
		chargeDialogList.append(charge_dialog);
		connect(charge_dialog, &ChargeTestDialog::construct_data, this, &MainReference::dealForConstructData);
		connect(charge_dialog, &ChargeTestDialog::returnBefore, this, &MainReference::showTestList);
		connect(charge_dialog, &ChargeTestDialog::modify_data, this, &MainReference::dealForModifyData);
		charge_dialog->press_save_btn();
		test_unique_id++;
	}
	break;
	case _simple_discharge_: //普通放电
	{
		DischargeTestDialog *discharge_dialog = new DischargeTestDialog(name, test_unique_id, temp_l);
		discharge_dialog->setWhatsThis("Simple_Discharge_Dialog" + QString::number(test_unique_id));
		m_testnamelist.append("Simple_Discharge_Dialog" + QString::number(test_unique_id));
		dischargeDialogList.append(discharge_dialog);
		connect(discharge_dialog, &DischargeTestDialog::construct_data, this, &MainReference::dealForConstructData);
		connect(discharge_dialog, &DischargeTestDialog::returnBefore, this, &MainReference::showTestList);
		connect(discharge_dialog, &DischargeTestDialog::modify_data, this, &MainReference::dealForModifyData);
		discharge_dialog->press_save_btn();
		test_unique_id++;
	}
	break;
	case _smoking_test_: //冒烟测试
	{
		SmokingTestDialog *smoking_dialog = new SmokingTestDialog(name, test_unique_id, temp_l);
		smoking_dialog->setWhatsThis("Smoking_Test_Dialog" + QString::number(test_unique_id));
		m_testnamelist.append("Smoking_Test_Dialog" + QString::number(test_unique_id));
		smokingDialogList.append(smoking_dialog);
		connect(smoking_dialog, &SmokingTestDialog::construct_data, this, &MainReference::dealForConstructData);
		connect(smoking_dialog, &SmokingTestDialog::returnBefore, this, &MainReference::showTestList);
		connect(smoking_dialog, &SmokingTestDialog::modify_data, this, &MainReference::dealForModifyData);
		smoking_dialog->press_save_btn();
		test_unique_id++;
	}
	break;
	case _capacity_test_://容量测试
	{
		CapacityTestDialog *capacity_dialog = new CapacityTestDialog(name, test_unique_id, temp_l);
		capacity_dialog->setWhatsThis("Capacity_Test_Dialog" + QString::number(test_unique_id));
		m_testnamelist.append("Capacity_Test_Dialog" + QString::number(test_unique_id));
		capacityDialogList.append(capacity_dialog);
		capacity_dialog->constructInit();
		connect(capacity_dialog, &CapacityTestDialog::construct_data, this, &MainReference::dealForConstructData);
		connect(capacity_dialog, &CapacityTestDialog::returnBefore, this, &MainReference::showTestList);
		connect(capacity_dialog, &CapacityTestDialog::modify_data, this, &MainReference::dealForModifyData);
		capacity_dialog->press_save_btn();
		test_unique_id++;
	}
	break;
	case _charge_discharge_test_: //充放电测试
	{
		ChargeAndDischargeTestDialog *CD_chargetestdialog = new ChargeAndDischargeTestDialog(name, test_unique_id, temp_l);
		CD_chargetestdialog->setWhatsThis("Charge_Discharge_Test_Dialog" + QString::number(test_unique_id));
		m_testnamelist.append("Charge_Discharge_Test_Dialog" + QString::number(test_unique_id));
		CD_chargeDialogList.append(CD_chargetestdialog);
		connect(CD_chargetestdialog, &ChargeAndDischargeTestDialog::construct_data, this, &MainReference::dealForConstructData);
		connect(CD_chargetestdialog, &ChargeAndDischargeTestDialog::returnBefore, this, &MainReference::showTestList);
		connect(CD_chargetestdialog, &ChargeAndDischargeTestDialog::modify_data, this, &MainReference::dealForModifyData);
		CD_chargetestdialog->press_save_btn();
		test_unique_id++;
	}
	break;
	case _soc_test_: //SOC测试
	{
		SOCTestDialog *soctestdialog = new SOCTestDialog(name, test_unique_id, temp_l);
		soctestdialog->setWhatsThis("SOC_Test_Dialog" + QString::number(test_unique_id));
		m_testnamelist.append("SOC_Test_Dialog" + QString::number(test_unique_id));
		SOCDialogList.append(soctestdialog);
		connect(soctestdialog, &SOCTestDialog::construct_data, this, &MainReference::dealForConstructData);
		connect(soctestdialog, &SOCTestDialog::returnBefore, this, &MainReference::showTestList);
		connect(soctestdialog, &SOCTestDialog::modify_data, this, &MainReference::dealForModifyData);
		soctestdialog->press_save_btn();
		test_unique_id++;
	}
	break;
	case _current_accuracy_: //电流精度测试
	{
		CurrentAccuracyTestDialog *current_accuracy = new CurrentAccuracyTestDialog(name, test_unique_id, temp_l);
		current_accuracy->setWhatsThis("Current_Accuracy_Test_Dialog" + QString::number(test_unique_id));
		m_testnamelist.append("Current_Accuracy_Test_Dialog" + QString::number(test_unique_id));
		currencyDialogList.append(current_accuracy);
		connect(current_accuracy, &CurrentAccuracyTestDialog::construct_data, this, &MainReference::dealForConstructData);
		connect(current_accuracy, &CurrentAccuracyTestDialog::returnBefore, this, &MainReference::showTestList);
		connect(current_accuracy, &CurrentAccuracyTestDialog::modify_data, this, &MainReference::dealForModifyData);
		current_accuracy->press_save_btn();
		test_unique_id++;
	}
	break;
	case _voltage_accuracy_: //电压精度测试
	{
		VoltageAccuracyTestDialog *voltage_accuracy = new VoltageAccuracyTestDialog(name, test_unique_id, temp_l);
		voltage_accuracy->setWhatsThis("Voltage_Accuracy_Test_Dialog" + QString::number(test_unique_id));
		m_testnamelist.append("Voltage_Accuracy_Test_Dialog" + QString::number(test_unique_id));
		voltageDialogList.append(voltage_accuracy);
		connect(voltage_accuracy, &VoltageAccuracyTestDialog::construct_data, this, &MainReference::dealForConstructData);
		connect(voltage_accuracy, &VoltageAccuracyTestDialog::returnBefore, this, &MainReference::showTestList);
		connect(voltage_accuracy, &VoltageAccuracyTestDialog::modify_data, this, &MainReference::dealForModifyData);
		voltage_accuracy->press_save_btn();
		test_unique_id++;
	qDebug() << "33333333333333" << endl;
	}
	break;
	default:
		break;
	}

}

void MainReference::on_comboBox_activated(int index)
{
	switch (index)
	{
	case 1: //普通充电
	{
		ChargeTestDialog *charge_dialog = new ChargeTestDialog(_simple_charge_, test_unique_id, m_voltage, m_capacity);
		charge_dialog->setWhatsThis("Simple_Charge_Dialog" + QString::number(test_unique_id));
		m_testnamelist.append("Simple_Charge_Dialog" + QString::number(test_unique_id));
		chargeDialogList.append(charge_dialog);
		charge_dialog->constructInit();
		connect(charge_dialog, &ChargeTestDialog::construct_data, this, &MainReference::dealForConstructData);
		connect(charge_dialog, &ChargeTestDialog::returnBefore, this, &MainReference::showTestList);
		connect(charge_dialog, &ChargeTestDialog::modify_data, this, &MainReference::dealForModifyData);
		charge_dialog->exec();
		test_unique_id++;
	}
	break;
	case 2: //普通放电
	{
		DischargeTestDialog *discharge_dialog = new DischargeTestDialog(_simple_discharge_, test_unique_id, m_capacity);
		discharge_dialog->setWhatsThis("Simple_Discharge_Dialog" + QString::number(test_unique_id));
		m_testnamelist.append("Simple_Discharge_Dialog" + QString::number(test_unique_id));
		dischargeDialogList.append(discharge_dialog);
		discharge_dialog->constructInit();
		connect(discharge_dialog, &DischargeTestDialog::construct_data, this, &MainReference::dealForConstructData);
		connect(discharge_dialog, &DischargeTestDialog::returnBefore, this, &MainReference::showTestList);
		connect(discharge_dialog, &DischargeTestDialog::modify_data, this, &MainReference::dealForModifyData);
		discharge_dialog->exec();
		test_unique_id++;
	}
	break;
	case 3: //冒烟测试
	{
		SmokingTestDialog *smoking_dialog = new SmokingTestDialog(_smoking_test_, test_unique_id, m_voltage, m_capacity);
		smoking_dialog->setWhatsThis("Smoking_Test_Dialog" + QString::number(test_unique_id));
		m_testnamelist.append("Smoking_Test_Dialog" + QString::number(test_unique_id));
		smokingDialogList.append(smoking_dialog);
		smoking_dialog->constructInit();
		connect(smoking_dialog, &SmokingTestDialog::construct_data, this, &MainReference::dealForConstructData);
		connect(smoking_dialog, &SmokingTestDialog::returnBefore, this, &MainReference::showTestList);
		connect(smoking_dialog, &SmokingTestDialog::modify_data, this, &MainReference::dealForModifyData);
		smoking_dialog->exec();
		test_unique_id++;
	}
	break;
	case 4://容量测试
	{
		CapacityTestDialog *capacity_dialog = new CapacityTestDialog(_capacity_test_, test_unique_id, m_voltage, m_capacity);
		capacity_dialog->setWhatsThis("Capacity_Test_Dialog" + QString::number(test_unique_id));
		m_testnamelist.append("Capacity_Test_Dialog" + QString::number(test_unique_id));
		capacityDialogList.append(capacity_dialog);
		capacity_dialog->constructInit();
		connect(capacity_dialog, &CapacityTestDialog::construct_data, this, &MainReference::dealForConstructData);
		connect(capacity_dialog, &CapacityTestDialog::returnBefore, this, &MainReference::showTestList);
		connect(capacity_dialog, &CapacityTestDialog::modify_data, this, &MainReference::dealForModifyData);
		capacity_dialog->exec();
		test_unique_id++;
	}
	break;
	case 5: //充放电测试
	{
		ChargeAndDischargeTestDialog *CD_chargetestdialog = new ChargeAndDischargeTestDialog(_charge_discharge_test_, test_unique_id, m_voltage, m_capacity);
		CD_chargetestdialog->setWhatsThis("Charge_Discharge_Test_Dialog" + QString::number(test_unique_id));
		m_testnamelist.append("Charge_Discharge_Test_Dialog" + QString::number(test_unique_id));
		CD_chargeDialogList.append(CD_chargetestdialog);
		CD_chargetestdialog->constructInit();
		connect(CD_chargetestdialog, &ChargeAndDischargeTestDialog::construct_data, this, &MainReference::dealForConstructData);
		connect(CD_chargetestdialog, &ChargeAndDischargeTestDialog::returnBefore, this, &MainReference::showTestList);
		connect(CD_chargetestdialog, &ChargeAndDischargeTestDialog::modify_data, this, &MainReference::dealForModifyData);
		CD_chargetestdialog->exec();
		test_unique_id++;
	}
	break;
	case 6: //SOC测试
	{
		SOCTestDialog *soctestdialog = new SOCTestDialog(_soc_test_, test_unique_id, m_voltage, m_capacity);
		soctestdialog->setWhatsThis("SOC_Test_Dialog" + QString::number(test_unique_id));
		m_testnamelist.append("SOC_Test_Dialog" + QString::number(test_unique_id));
		SOCDialogList.append(soctestdialog);
		soctestdialog->constructInit();
		connect(soctestdialog, &SOCTestDialog::construct_data, this, &MainReference::dealForConstructData);
		connect(soctestdialog, &SOCTestDialog::returnBefore, this, &MainReference::showTestList);
		connect(soctestdialog, &SOCTestDialog::modify_data, this, &MainReference::dealForModifyData);
		soctestdialog->exec();
		test_unique_id++;
	}
	break;
	case 7: //电流精度测试
	{
		CurrentAccuracyTestDialog *current_accuracy = new CurrentAccuracyTestDialog(_current_accuracy_, test_unique_id, m_voltage, m_capacity);
		current_accuracy->setWhatsThis("Current_Accuracy_Test_Dialog" + QString::number(test_unique_id));
		m_testnamelist.append("Current_Accuracy_Test_Dialog" + QString::number(test_unique_id));
		currencyDialogList.append(current_accuracy);
		current_accuracy->constructInit();
		connect(current_accuracy, &CurrentAccuracyTestDialog::construct_data, this, &MainReference::dealForConstructData);
		connect(current_accuracy, &CurrentAccuracyTestDialog::returnBefore, this, &MainReference::showTestList);
		connect(current_accuracy, &CurrentAccuracyTestDialog::modify_data, this, &MainReference::dealForModifyData);
		current_accuracy->exec();
		test_unique_id++;
	}
	break;
	case 8: //电流精度测试
	{
		VoltageAccuracyTestDialog *voltage_accuracy = new VoltageAccuracyTestDialog(_voltage_accuracy_, test_unique_id, m_voltage, m_capacity);
		voltage_accuracy->setWhatsThis("Voltage_Accuracy_Test_Dialog" + QString::number(test_unique_id));
		m_testnamelist.append("Voltage_Accuracy_Test_Dialog" + QString::number(test_unique_id));
		voltageDialogList.append(voltage_accuracy);
		voltage_accuracy->constructInit();
		connect(voltage_accuracy, &VoltageAccuracyTestDialog::construct_data, this, &MainReference::dealForConstructData);
		connect(voltage_accuracy, &VoltageAccuracyTestDialog::returnBefore, this, &MainReference::showTestList);
		connect(voltage_accuracy, &VoltageAccuracyTestDialog::modify_data, this, &MainReference::dealForModifyData);
		voltage_accuracy->exec();
		test_unique_id++;
	}
	break;
	case 9: //电流精度测试
	{
		ProtectionParametersDialog *protection_dialog = new ProtectionParametersDialog(_protection_parameters_, test_unique_id, m_voltage, m_capacity);
		protection_dialog->setWhatsThis("Protection_Parameters_Test_Dialog" + QString::number(test_unique_id));
		m_testnamelist.append("Protection_Parameters_Test_Dialog" + QString::number(test_unique_id));
		protectionDialogList.append(protection_dialog);
		protection_dialog->constructInit();
		connect(protection_dialog, &ProtectionParametersDialog::construct_data, this, &MainReference::dealForConstructData);
		connect(protection_dialog, &ProtectionParametersDialog::returnBefore, this, &MainReference::showTestList);
		connect(protection_dialog, &ProtectionParametersDialog::modify_data, this, &MainReference::dealForModifyData);
		protection_dialog->exec();
		test_unique_id++;
	}
	break;
	default:
		break;
	}
}

void MainReference::on_tableWidget_customContextMenuRequested(const QPoint & pos)
{
	if (!ui.tableWidget->indexAt(pos).isValid())
	{
		return;
	}
	QModelIndex index = ui.tableWidget->indexAt(pos);
	selectedItemRow = index.row();
	menu_tablewidget->exec(QCursor::pos());
}

void MainReference::on_listView_customContextMenuRequested(const QPoint & pos)
{
	if (!ui.listView->indexAt(pos).isValid())
	{
		return;
	}
	QModelIndex index = ui.listView->indexAt(pos);
	selectedItemRow = index.row();
	menu_listview->exec(QCursor::pos());
}

void MainReference::on_pushButtons_scrool_clicked()
{
	if (scroll_state)
	{
		scroll_state = false;
	}
	else
	{
		scroll_state = true;
	}
}
//参数导出
void MainReference::on_pushButton_export_parameters_clicked()
{

	QString parameters_test = QCoreApplication::applicationDirPath() + "/init.xlsx";
	QXlsx::Document xlsx;
	QXlsx::Format centerAlign;
	centerAlign.setHorizontalAlignment(QXlsx::Format::AlignHCenter); //设置横向、纵向居中
	centerAlign.setVerticalAlignment(QXlsx::Format::AlignVCenter);   //

	centerAlign.setTopBorderStyle(QXlsx::Format::BorderThin);//设置上下左右的线类型
	centerAlign.setBottomBorderStyle(QXlsx::Format::BorderThin);
	centerAlign.setLeftBorderStyle(QXlsx::Format::BorderThin);
	centerAlign.setRightBorderStyle(QXlsx::Format::BorderThin);

	for (int i = 0; i < instructList.size(); i++)
	{
		QList<int> _temp_ = instructList.at(i);
		switch (_temp_.at(0))
		{
		case 0:
		{
			if (!xlsx.selectSheet("Simple charge"))
			{
				xlsx.addSheet("Simple charge");
			}	
			int row_count = xlsx.dimension().rowCount();
			centerAlign.setFontBold(true);          //字体加粗
			centerAlign.setFontColor(Qt::blue);     //设置字体颜色
			centerAlign.setFontSize(16);            //设置字体大小	
			xlsx.setColumnWidth(1, 2, 40);  //设置列宽
			xlsx.mergeCells(QXlsx::CellRange(row_count + 1, 1, row_count + 1, 2), centerAlign); //合并单元表格
			xlsx.write("A" + QString::number(row_count + 1), tr("Simple charge"));       //总标题
			centerAlign.setFontColor(Qt::black);     //设置字体颜色
			centerAlign.setFontSize(12);            //设置字体大小	
			xlsx.mergeCells(QXlsx::CellRange(row_count + 2, 1, row_count + 2, 2), centerAlign); //合并单元表格
			xlsx.write("A" + QString::number(row_count + 2), user_select_testname.at(i));       //总标题

			centerAlign.setFontBold(false);          //字体加粗
			centerAlign.setFontColor(Qt::black);     //设置字体颜色
			centerAlign.setFontSize(10);            //设置字体大小	
			xlsx.write(row_count + 3, 1, tr("voltage/0.1V"), centerAlign);
			xlsx.write(row_count + 3, 2, _temp_.at(1), centerAlign);
			xlsx.write(row_count + 4, 1, tr("charge current/0.1A"), centerAlign);
			xlsx.write(row_count + 4, 2, _temp_.at(2), centerAlign);
			xlsx.write(row_count + 5, 1, tr("(cutoff)full of charge"), centerAlign);
			xlsx.write(row_count + 5, 2, _temp_.at(3), centerAlign);
			xlsx.write(row_count + 6, 1, tr("(cutoff)Soc>= "), centerAlign);
			xlsx.write(row_count + 6, 2, _temp_.at(4), centerAlign);
		}
		break;
		case 1:
		{
			if (!xlsx.selectSheet("Simple discharge"))
			{
				xlsx.addSheet("Simple discharge");
			}
			int row_count = xlsx.dimension().rowCount();
			centerAlign.setFontBold(true);          //字体加粗
			centerAlign.setFontColor(Qt::blue);     //设置字体颜色
			centerAlign.setFontSize(16);            //设置字体大小	
			xlsx.setColumnWidth(1, 2, 40);  //设置列宽
			xlsx.mergeCells(QXlsx::CellRange(row_count + 1, 1, row_count + 1, 2), centerAlign); //合并单元表格
			xlsx.write("A" + QString::number(row_count + 1), tr("Simple discharge"));       //总标题
			centerAlign.setFontColor(Qt::black);     //设置字体颜色
			centerAlign.setFontSize(12);            //设置字体大小	
			xlsx.mergeCells(QXlsx::CellRange(row_count + 2, 1, row_count + 2, 2), centerAlign); //合并单元表格
			xlsx.write("A" + QString::number(row_count + 2), user_select_testname.at(i));       //总标题

			centerAlign.setFontBold(false);          //字体加粗
			centerAlign.setFontColor(Qt::black);     //设置字体颜色
			centerAlign.setFontSize(10);            //设置字体大小	
			xlsx.write(row_count + 3, 1, tr("charge current/0.1A"), centerAlign);
			xlsx.write(row_count + 3, 2, _temp_.at(1), centerAlign);
			xlsx.write(row_count + 4, 1, tr("(cutoff)full of discharge"), centerAlign);
			xlsx.write(row_count + 4, 2, _temp_.at(2), centerAlign);
			xlsx.write(row_count + 5, 1, tr("(cutoff)Soc<= "), centerAlign);
			xlsx.write(row_count + 5, 2, _temp_.at(3), centerAlign);
		}
		break;
		case 2:
		{
			if (!xlsx.selectSheet("Smoking test"))
			{
				xlsx.addSheet("Smoking test");
			}
			int row_count = xlsx.dimension().rowCount();
			centerAlign.setFontBold(true);          //字体加粗
			centerAlign.setFontColor(Qt::blue);     //设置字体颜色
			centerAlign.setFontSize(16);            //设置字体大小	
			xlsx.setColumnWidth(1, 2, 40);  //设置列宽
			xlsx.mergeCells(QXlsx::CellRange(row_count + 1, 1, row_count + 1, 2), centerAlign); //合并单元表格
			xlsx.write("A" + QString::number(row_count + 1), tr("Smoking test"));       //总标题
			centerAlign.setFontColor(Qt::black);     //设置字体颜色
			centerAlign.setFontSize(12);            //设置字体大小	
			xlsx.mergeCells(QXlsx::CellRange(row_count + 2, 1, row_count + 2, 2), centerAlign); //合并单元表格
			xlsx.write("A" + QString::number(row_count + 2), user_select_testname.at(i));       //总标题

			centerAlign.setFontBold(false);          //字体加粗
			centerAlign.setFontColor(Qt::black);     //设置字体颜色
			centerAlign.setFontSize(10);            //设置字体大小	
			xlsx.write(row_count + 3, 1, tr("charge voltage/0.1V"), centerAlign);
			xlsx.write(row_count + 3, 2, _temp_.at(1), centerAlign);
			xlsx.write(row_count + 4, 1, tr("charge current/0.1A"), centerAlign);
			xlsx.write(row_count + 4, 2, _temp_.at(2), centerAlign);
			xlsx.write(row_count + 5, 1, tr("discharge current/0.1A"), centerAlign);
			xlsx.write(row_count + 5, 2, _temp_.at(3), centerAlign);
		}
		break;
		case 3:
		{
			if (!xlsx.selectSheet("Capacity test"))
			{
				xlsx.addSheet("Capacity test");
			}
			int row_count = xlsx.dimension().rowCount();
			centerAlign.setFontBold(true);          //字体加粗
			centerAlign.setFontColor(Qt::blue);     //设置字体颜色
			centerAlign.setFontSize(16);            //设置字体大小	
			xlsx.setColumnWidth(1, 2, 40);  //设置列宽
			xlsx.mergeCells(QXlsx::CellRange(row_count + 1, 1, row_count + 1, 2), centerAlign); //合并单元表格
			xlsx.write("A" + QString::number(row_count + 1), tr("Capacity test"));       //总标题
			centerAlign.setFontColor(Qt::black);     //设置字体颜色
			centerAlign.setFontSize(12);            //设置字体大小	
			xlsx.mergeCells(QXlsx::CellRange(row_count + 2, 1, row_count + 2, 2), centerAlign); //合并单元表格
			xlsx.write("A" + QString::number(row_count + 2), user_select_testname.at(i));       //总标题

			centerAlign.setFontBold(false);          //字体加粗
			centerAlign.setFontColor(Qt::black);     //设置字体颜色
			centerAlign.setFontSize(10);            //设置字体大小	
			xlsx.write(row_count + 3, 1, tr("charge voltage/0.1V"), centerAlign);
			xlsx.write(row_count + 3, 2, _temp_.at(1), centerAlign);
			xlsx.write(row_count + 4, 1, tr("charge current/0.1A"), centerAlign);
			xlsx.write(row_count + 4, 2, _temp_.at(2), centerAlign);
			xlsx.write(row_count + 5, 1, tr("discharge current/0.1A"), centerAlign);
			xlsx.write(row_count + 5, 2, _temp_.at(3), centerAlign);
			xlsx.write(row_count + 6, 1, tr("cycle count"), centerAlign);
			xlsx.write(row_count + 6, 2, _temp_.at(4), centerAlign);
		}
		break;
		case 4:
		{
			if (!xlsx.selectSheet("ChargeDischarge test"))
			{
				xlsx.addSheet("ChargeDischarge test");
			}
			int row_count = xlsx.dimension().rowCount();
			centerAlign.setFontBold(true);          //字体加粗
			centerAlign.setFontColor(Qt::blue);     //设置字体颜色
			centerAlign.setFontSize(16);            //设置字体大小	
			xlsx.setColumnWidth(1, 2, 40);  //设置列宽
			xlsx.mergeCells(QXlsx::CellRange(row_count + 1, 1, row_count + 1, 2), centerAlign); //合并单元表格
			xlsx.write("A" + QString::number(row_count + 1), tr("ChargeDischarge test"));       //总标题
			centerAlign.setFontColor(Qt::black);     //设置字体颜色
			centerAlign.setFontSize(12);            //设置字体大小	
			xlsx.mergeCells(QXlsx::CellRange(row_count + 2, 1, row_count + 2, 2), centerAlign); //合并单元表格
			xlsx.write("A" + QString::number(row_count + 2), user_select_testname.at(i));       //总标题

			centerAlign.setFontBold(false);          //字体加粗
			centerAlign.setFontColor(Qt::black);     //设置字体颜色
			centerAlign.setFontSize(10);            //设置字体大小	
			xlsx.write(row_count + 3, 1, tr("charge voltage/0.1V"), centerAlign);
			xlsx.write(row_count + 3, 2, _temp_.at(1), centerAlign);
			xlsx.write(row_count + 4, 1, tr("standard charge current/0.1A"), centerAlign);
			xlsx.write(row_count + 4, 2, _temp_.at(2), centerAlign);
			xlsx.write(row_count + 5, 1, tr("fast charge current/0.1A"), centerAlign);
			xlsx.write(row_count + 5, 2, _temp_.at(3), centerAlign);
			xlsx.write(row_count + 6, 1, tr("standard discharge current/0.1A"), centerAlign);
			xlsx.write(row_count + 6, 2, _temp_.at(4), centerAlign);
			xlsx.write(row_count + 7, 1, tr("fast discharge current/0.1A"), centerAlign);
			xlsx.write(row_count + 7, 2, _temp_.at(5), centerAlign);
		}
		break;
		case 5:
		{
			if (!xlsx.selectSheet("SOC test"))
			{
				xlsx.addSheet("SOC test");
			}
			int row_count = xlsx.dimension().rowCount();
			centerAlign.setFontBold(true);          //字体加粗
			centerAlign.setFontColor(Qt::blue);     //设置字体颜色
			centerAlign.setFontSize(16);            //设置字体大小	
			xlsx.setColumnWidth(1, 2, 40);  //设置列宽
			xlsx.mergeCells(QXlsx::CellRange(row_count + 1, 1, row_count + 1, 2), centerAlign); //合并单元表格
			xlsx.write("A" + QString::number(row_count + 1), tr("SOC test"));       //总标题
			centerAlign.setFontColor(Qt::black);     //设置字体颜色
			centerAlign.setFontSize(12);            //设置字体大小	
			xlsx.mergeCells(QXlsx::CellRange(row_count + 2, 1, row_count + 2, 2), centerAlign); //合并单元表格
			xlsx.write("A" + QString::number(row_count + 2), user_select_testname.at(i));       //总标题

			centerAlign.setFontBold(false);          //字体加粗
			centerAlign.setFontColor(Qt::black);     //设置字体颜色
			centerAlign.setFontSize(10);            //设置字体大小	
			xlsx.write(row_count + 3, 1, tr("charge voltage/0.1V"), centerAlign);
			xlsx.write(row_count + 3, 2, _temp_.at(1), centerAlign);
			xlsx.write(row_count + 4, 1, tr("charge current/0.1A"), centerAlign);
			xlsx.write(row_count + 4, 2, _temp_.at(2), centerAlign);
			xlsx.write(row_count + 5, 1, tr("discharge current/0.1A"), centerAlign);
			xlsx.write(row_count + 5, 2, _temp_.at(3), centerAlign);
			xlsx.write(row_count + 6, 1, tr("soc gap"), centerAlign);
			xlsx.write(row_count + 6, 2, _temp_.at(4), centerAlign);
		}
		break;
		case 6:
		{
			if (!xlsx.selectSheet("Current accuracy test"))
			{
				xlsx.addSheet("Current accuracy test");
			}
			int row_count = xlsx.dimension().rowCount();
			centerAlign.setFontBold(true);          //字体加粗
			centerAlign.setFontColor(Qt::blue);     //设置字体颜色
			centerAlign.setFontSize(16);            //设置字体大小	
			xlsx.setColumnWidth(1, 2, 40);  //设置列宽
			xlsx.mergeCells(QXlsx::CellRange(row_count + 1, 1, row_count + 1, 2), centerAlign); //合并单元表格
			xlsx.write("A" + QString::number(row_count + 1), tr("Current accuracy test"));       //总标题
			centerAlign.setFontColor(Qt::black);     //设置字体颜色
			centerAlign.setFontSize(12);            //设置字体大小	
			xlsx.mergeCells(QXlsx::CellRange(row_count + 2, 1, row_count + 2, 2), centerAlign); //合并单元表格
			xlsx.write("A" + QString::number(row_count + 2), user_select_testname.at(i));       //总标题

			centerAlign.setFontBold(false);          //字体加粗
			centerAlign.setFontColor(Qt::black);     //设置字体颜色
			centerAlign.setFontSize(10);            //设置字体大小	
			xlsx.write(row_count + 3, 1, tr("charge voltage/0.1V"), centerAlign);
			xlsx.write(row_count + 3, 2, _temp_.at(1), centerAlign);
			xlsx.write(row_count + 4, 1, tr("max current/0.1A"), centerAlign);
			xlsx.write(row_count + 4, 2, _temp_.at(2), centerAlign);
			xlsx.write(row_count + 5, 1, tr("current Sample interval/A"), centerAlign);
			xlsx.write(row_count + 5, 2, _temp_.at(3), centerAlign);
			xlsx.write(row_count + 6, 1, tr("Use a percentage as error vlaue/%"), centerAlign);
			xlsx.write(row_count + 6, 2, _temp_.at(4), centerAlign);
			xlsx.write(row_count + 7, 1, tr("Use a fixed current as error vlaue/0.1A"), centerAlign);
			xlsx.write(row_count + 7, 2, _temp_.at(5), centerAlign);
		}
		break;
		case 7:
		{
			if (!xlsx.selectSheet("Voltage accuracy test"))
			{
				xlsx.addSheet("Voltage accuracy test");
			}
			int row_count = xlsx.dimension().rowCount();
			centerAlign.setFontBold(true);          //字体加粗
			centerAlign.setFontColor(Qt::blue);     //设置字体颜色
			centerAlign.setFontSize(16);            //设置字体大小	
			xlsx.setColumnWidth(1, 2, 40);  //设置列宽
			xlsx.mergeCells(QXlsx::CellRange(row_count + 1, 1, row_count + 1, 2), centerAlign); //合并单元表格
			xlsx.write("A" + QString::number(row_count + 1), tr("Voltage accuracy test"));       //总标题
			centerAlign.setFontColor(Qt::black);     //设置字体颜色
			centerAlign.setFontSize(12);            //设置字体大小	
			xlsx.mergeCells(QXlsx::CellRange(row_count + 2, 1, row_count + 2, 2), centerAlign); //合并单元表格
			xlsx.write("A" + QString::number(row_count + 2), user_select_testname.at(i));       //总标题

			centerAlign.setFontBold(false);          //字体加粗
			centerAlign.setFontSize(10);            //设置字体大小	
			xlsx.write(row_count + 3, 1, tr("charge voltage/0.1V"), centerAlign);
			xlsx.write(row_count + 3, 2, _temp_.at(1), centerAlign);
			xlsx.write(row_count + 4, 1, tr("charge current/0.1A"), centerAlign);
			xlsx.write(row_count + 4, 2, _temp_.at(2), centerAlign);
			xlsx.write(row_count + 5, 1, tr("discharge current/0.1A"), centerAlign);
			xlsx.write(row_count + 5, 2, _temp_.at(3), centerAlign);
			xlsx.write(row_count + 6, 1, tr("Soc Sample interval/A"), centerAlign);
			xlsx.write(row_count + 6, 2, _temp_.at(4), centerAlign);
			xlsx.write(row_count + 7, 1, tr("Use a percentage as error vlaue /%"), centerAlign);
			xlsx.write(row_count + 7, 2, _temp_.at(5), centerAlign);
			xlsx.write(row_count + 8, 1, tr("Use a fixed current as error vlaue/0.1A"), centerAlign);
			xlsx.write(row_count + 8, 2, _temp_.at(6), centerAlign);
			xlsx.write(row_count + 9, 1, tr("reasonable min voltage/0.1V"), centerAlign);
			xlsx.write(row_count + 9, 2, _temp_.at(8), centerAlign);
			xlsx.write(row_count + 10, 1, tr("reasonable max voltage/0.1V"), centerAlign);
			xlsx.write(row_count + 10, 2, _temp_.at(9), centerAlign);
		}
		break;
		default:
			break;
		}
	}

	xlsx.saveAs(parameters_test);
}
//参数导入
void MainReference::on_pushButton_import_parameters_clicked()
{
	QString parameters_test = QCoreApplication::applicationDirPath() + "/init.xlsx";
	QFileInfo infofile(parameters_test);
	if (!infofile.isFile())
	{
		qDebug() << "No such file!!!" << endl;
		return;
	}
	QXlsx::Document xlsx(parameters_test);
	if (!xlsx.selectSheet("Simple charge"))
	{
		xlsx.addSheet("Simple charge");
	}
	int row_count = xlsx.dimension().rowCount();
	if (row_count !=0)
	{
		int SC_num = row_count / 6;
		for (int i = 0; i < SC_num; i++)
		{
			QString name = xlsx.read(i * 6 + 2, 1).toString();
			QList<int> tem_l;
			tem_l.append(_simple_charge_);
			tem_l.append(xlsx.read(i * 6 + 3, 2).toInt());
			tem_l.append(xlsx.read(i * 6 + 4, 2).toInt());
			tem_l.append(xlsx.read(i * 6 + 5, 2).toInt());
			tem_l.append(xlsx.read(i * 6 + 6, 2).toInt());
			create_testdialog_from_parameters(_simple_charge_, name, tem_l);
		}	
	}

	if (!xlsx.selectSheet("Simple discharge"))
	{
		xlsx.addSheet("Simple discharge");
	}
	row_count = xlsx.dimension().rowCount();
	if (row_count != 0)
	{
		int SC_num = row_count / 5;
		for (int i = 0; i < SC_num; i++)
		{
			QString name = xlsx.read(i * 5 + 2, 1).toString();
			QList<int> tem_l;
			tem_l.append(_simple_discharge_);
			tem_l.append(xlsx.read(i * 5 + 3, 2).toInt());
			tem_l.append(xlsx.read(i * 5 + 4, 2).toInt());
			tem_l.append(xlsx.read(i * 5 + 5, 2).toInt());
			create_testdialog_from_parameters(_simple_discharge_, name, tem_l);
		}
	}

	if (!xlsx.selectSheet("Smoking test"))
	{
		xlsx.addSheet("Smoking test");
	}
	row_count = xlsx.dimension().rowCount();
	if (row_count != 0)
	{
		int SC_num = row_count / 5;
		for (int i = 0; i < SC_num; i++)
		{
			QString name = xlsx.read(i * 5 + 2, 1).toString();
			QList<int> tem_l;
			tem_l.append(_smoking_test_);
			tem_l.append(xlsx.read(i * 5 + 3, 2).toInt());
			tem_l.append(xlsx.read(i * 5 + 4, 2).toInt());
			tem_l.append(xlsx.read(i * 5 + 5, 2).toInt());
			create_testdialog_from_parameters(_smoking_test_, name, tem_l);
		}
	}

	if (!xlsx.selectSheet("Capacity test"))
	{
		xlsx.addSheet("Capacity test");
	}
	row_count = xlsx.dimension().rowCount();
	if (row_count != 0)
	{
		int SC_num = row_count / 6;
		for (int i = 0; i < SC_num; i++)
		{
			QString name = xlsx.read(i * 6 + 2, 1).toString();
			QList<int> tem_l;
			tem_l.append(_capacity_test_);
			tem_l.append(xlsx.read(i * 6 + 3, 2).toInt());
			tem_l.append(xlsx.read(i * 6 + 4, 2).toInt());
			tem_l.append(xlsx.read(i * 6 + 5, 2).toInt());
			tem_l.append(xlsx.read(i * 6 + 6, 2).toInt());
			create_testdialog_from_parameters(_capacity_test_, name, tem_l);
		}
	}

	if (!xlsx.selectSheet("ChargeDischarge test"))
	{
		xlsx.addSheet("ChargeDischarge test");
	}
	row_count = xlsx.dimension().rowCount();
	if (row_count != 0)
	{
		int SC_num = row_count / 7;
		for (int i = 0; i < SC_num; i++)
		{
			QString name = xlsx.read(i * 7 + 2, 1).toString();
			QList<int> tem_l;
			tem_l.append(_charge_discharge_test_);
			tem_l.append(xlsx.read(i * 7 + 3, 2).toInt());
			tem_l.append(xlsx.read(i * 7 + 4, 2).toInt());
			tem_l.append(xlsx.read(i * 7 + 5, 2).toInt());
			tem_l.append(xlsx.read(i * 7 + 6, 2).toInt());
			tem_l.append(xlsx.read(i * 7 + 7, 2).toInt());
			create_testdialog_from_parameters(_charge_discharge_test_, name, tem_l);
		}
	}

	if (!xlsx.selectSheet("SOC test"))
	{
		xlsx.addSheet("SOC test");
	}
	row_count = xlsx.dimension().rowCount();
	if (row_count != 0)
	{
		int SC_num = row_count / 6;
		for (int i = 0; i < SC_num; i++)
		{
			QString name = xlsx.read(i * 6 + 2, 1).toString();
			QList<int> tem_l;
			tem_l.append(_soc_test_);
			tem_l.append(xlsx.read(i * 6 + 3, 2).toInt());
			tem_l.append(xlsx.read(i * 6 + 4, 2).toInt());
			tem_l.append(xlsx.read(i * 6 + 5, 2).toInt());
			tem_l.append(xlsx.read(i * 6 + 6, 2).toInt());
			create_testdialog_from_parameters(_soc_test_, name, tem_l);
		}
	}

	if (!xlsx.selectSheet("Current accuracy test"))
	{
		xlsx.addSheet("Current accuracy test");
	}
	row_count = xlsx.dimension().rowCount();
	if (row_count != 0)
	{
		int SC_num = row_count / 7;
		for (int i = 0; i < SC_num; i++)
		{
			QString name = xlsx.read(i * 7 + 2, 1).toString();
			QList<int> tem_l;
			tem_l.append(_current_accuracy_);
			tem_l.append(xlsx.read(i * 7 + 3, 2).toInt());
			tem_l.append(xlsx.read(i * 7 + 4, 2).toInt());
			tem_l.append(xlsx.read(i * 7 + 5, 2).toInt());
			tem_l.append(xlsx.read(i * 7 + 6, 2).toInt());
			tem_l.append(xlsx.read(i * 7 + 7, 2).toInt());
			create_testdialog_from_parameters(_current_accuracy_, name, tem_l);
		}
	}

	if (!xlsx.selectSheet("Voltage accuracy test"))
	{
		xlsx.addSheet("Voltage accuracy test");
	}
	row_count = xlsx.dimension().rowCount();
	if (row_count != 0)
	{
		int SC_num = row_count / 10;
		for (int i = 0; i < SC_num; i++)
		{
			QString name = xlsx.read(i * 10 + 2, 1).toString();
			QList<int> tem_l;
			tem_l.append(_voltage_accuracy_);
			tem_l.append(xlsx.read(i * 10 + 3, 2).toInt());
			tem_l.append(xlsx.read(i * 10 + 4, 2).toInt());
			tem_l.append(xlsx.read(i * 10 + 5, 2).toInt());
			tem_l.append(xlsx.read(i * 10 + 6, 2).toInt());
			tem_l.append(xlsx.read(i * 10 + 7, 2).toInt());
			tem_l.append(xlsx.read(i * 10 + 8, 2).toInt());
			tem_l.append(xlsx.read(i * 10 + 9, 2).toInt());
			tem_l.append(xlsx.read(i * 10 + 10, 2).toInt());
			create_testdialog_from_parameters(_voltage_accuracy_, name, tem_l);
		}
	}
}

void MainReference::on_TestPauseBtn_clicked()
{
	emit update_event_loop_pass(true); //退出当前测试循环
	emit end_all_test();
}

void MainReference::on_TestTerminateBtn_clicked()
{
	ui.stackedWidget->setCurrentIndex(1);
}
