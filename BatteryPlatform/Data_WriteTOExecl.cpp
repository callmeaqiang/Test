#include "Data_WriteTOExecl.h"
#include <bitset>
#include <xlsxdocument.h>
#include <xlsxcell.h>

Data_WriteTOExecl::Data_WriteTOExecl(QObject *parent) : QObject(parent)
{

}

Data_WriteTOExecl::~Data_WriteTOExecl()
{
}

void Data_WriteTOExecl::update_pact_type(const int pact, const int capacity)
{
	m_pact = pact;
	standard_capacity = capacity;
}

void Data_WriteTOExecl::update_execl_path(const QString filepath)
{
	m_execl_path = filepath + "/" +"batter_report.xlsx";
	QFileInfo infofile(m_execl_path);
	if (infofile.isFile())
	{
		return;
	}
	Document xlsx;
	if (!xlsx.selectSheet("Battery Report"))
	{/*在当前打开的xlsx文件中，找一个名字为的sheet*/
		xlsx.addSheet("Battery Report");//找不到的话就添加一个名为ziv的sheet
	}
	Format centerAlign;
	centerAlign.setHorizontalAlignment(QXlsx::Format::AlignHCenter); //设置横向、纵向居中
	centerAlign.setVerticalAlignment(QXlsx::Format::AlignVCenter);   //

	centerAlign.setTopBorderStyle(QXlsx::Format::BorderThin);//设置上下左右的线类型
	centerAlign.setBottomBorderStyle(QXlsx::Format::BorderThin);
	centerAlign.setLeftBorderStyle(QXlsx::Format::BorderThin);
	centerAlign.setRightBorderStyle(QXlsx::Format::BorderThin);
	centerAlign.setFontBold(true);          //字体加粗

	centerAlign.setFontColor(Qt::blue);     //设置字体颜色
	centerAlign.setFontSize(18);            //设置字体大小	
	xlsx.setColumnWidth(1, 1, 60);  //设置列宽
	xlsx.setColumnWidth(2, 2, 20);  //设置列宽
	xlsx.mergeCells(CellRange(1, 1, 2, 2), centerAlign); //合并单元表格
	xlsx.write("A1", tr("Battery Report"));       //总标题
	xlsx.saveAs(m_execl_path);
}

void Data_WriteTOExecl::testconditionReset()  //测试指标复位
{
	pass_num = 0;
	fullcharge = false;
	fulldischarge = false;
	m_cutSoc = 0;			 //soc截止值
}
void Data_WriteTOExecl::write_test_condition(const QList<int> data)
{
	Format centerAlign;
	centerAlign.setHorizontalAlignment(QXlsx::Format::AlignHCenter); //设置横向、纵向居中
	centerAlign.setVerticalAlignment(QXlsx::Format::AlignVCenter);   //

	centerAlign.setTopBorderStyle(QXlsx::Format::BorderThin);//设置上下左右的线类型
	centerAlign.setBottomBorderStyle(QXlsx::Format::BorderThin);
	centerAlign.setLeftBorderStyle(QXlsx::Format::BorderThin);
	centerAlign.setRightBorderStyle(QXlsx::Format::BorderThin);
	switch (data.at(0))
	{
	//第7行为冒烟测试结果
	case 2:
	{
		Document xlsx(m_execl_path);
		//设置表头样式
		if (!xlsx.selectSheet("Smoking Test"))
		{
			xlsx.addSheet("Smoking Test");
		}
		int row_count = xlsx.dimension().rowCount();
		centerAlign.setFontBold(true);          //字体加粗
		centerAlign.setFontColor(Qt::blue);     //设置字体颜色
		centerAlign.setFontSize(16);            //设置字体大小	
		xlsx.setColumnWidth(1, 1, 20);  //设置列宽
		xlsx.setColumnWidth(2, 2, 40);  //设置列宽
		xlsx.setColumnWidth(3, 3, 10);  //设置列宽
		xlsx.mergeCells(CellRange(row_count +1, 1, row_count +1, 3), centerAlign); //合并单元表格
		xlsx.write("A" + QString::number(row_count + 1), tr("Smoking Test"));       //总标题
		centerAlign.setHorizontalAlignment(QXlsx::Format::AlignLeft); //设置横向、纵向居中	
		centerAlign.setFontSize(12);            //设置字体大小	
		xlsx.write(row_count +2, 1, tr("Test condition"), centerAlign);
		xlsx.write(row_count +2, 2, " ", centerAlign);
		xlsx.write(row_count +2, 3, " ", centerAlign);
		centerAlign.setFontColor(Qt::black);     //设置字体颜色
		centerAlign.setFontBold(false);          //字体加粗
		centerAlign.setFontSize(10);            //设置字体大小	
		xlsx.write(row_count +3, 1, tr("Charge voltage"), centerAlign);
		xlsx.write(row_count +3, 2, QString("%1 V").arg((float)data.at(1) / 10, 0, 'f', 2), centerAlign);
		xlsx.write(row_count +3, 3, " ", centerAlign);
		xlsx.write(row_count +4, 1, tr("Charge current"), centerAlign);
		xlsx.write(row_count +4, 2, QString("%1 A").arg((float)data.at(2) / 10, 0, 'f', 2), centerAlign);
		xlsx.write(row_count +4, 3, " ", centerAlign);
		xlsx.write(row_count +5, 1, tr("Discharge current A"), centerAlign);
		xlsx.write(row_count +5, 2, QString("%1 A").arg((float)data.at(3) / 10, 0, 'f', 2), centerAlign);
		xlsx.write(row_count +5, 3, " ", centerAlign);
		xlsx.write(row_count +6, 1, tr("Pact type"), centerAlign);
		switch (m_pact)
		{
		case 1:
			xlsx.write(row_count + 6, 2, tr("zhili"), centerAlign);
			break;
		case 2:
			xlsx.write(row_count + 6, 2, tr("lishen"), centerAlign);
			break;
		case 3:
			xlsx.write(row_count + 6, 2, tr("peicheng"), centerAlign);
			break;
		default:
			break;
		}
		xlsx.write(row_count + 6, 3, " ", centerAlign);
		centerAlign.setFontColor(Qt::blue);     //设置字体颜色
		centerAlign.setFontBold(true);          //字体加粗
		centerAlign.setFontSize(12);            //设置字体大小
		result_row_count = row_count + 7;
		xlsx.write(row_count + 7, 1, tr("Test result"), centerAlign);
		xlsx.write(row_count + 7, 3, " ", centerAlign);
		xlsx.save();
	}
	break;
	//第8行为容量测试结果
	case 3:
	{
		Document xlsx(m_execl_path);
		//设置表头样式
		if (!xlsx.selectSheet("Capacity Test"))
		{
			xlsx.addSheet("Capacity Test");
		}
		int row_count = xlsx.dimension().rowCount();
		centerAlign.setFontBold(true);          //字体加粗
		centerAlign.setFontColor(Qt::blue);     //设置字体颜色
		centerAlign.setFontSize(16);            //设置字体大小	
		xlsx.setColumnWidth(1, 1, 20);  //设置列宽
		xlsx.setColumnWidth(2, 2, 20);  //设置列宽
		xlsx.setColumnWidth(3, 3, 10);  //设置列宽
		xlsx.mergeCells(CellRange(row_count + 1, 1, row_count + 1, 3), centerAlign); //合并单元表格
		xlsx.write("A1", tr("Capacity Test"));       //总标题
		centerAlign.setHorizontalAlignment(QXlsx::Format::AlignLeft); //设置横向、纵向居中	
		centerAlign.setFontSize(12);            //设置字体大小	
		xlsx.write(row_count + 2, 1, tr("Test condition"), centerAlign);
		xlsx.write(row_count + 2, 2, " ", centerAlign);
		xlsx.write(row_count + 2, 3, " ", centerAlign);
		centerAlign.setFontColor(Qt::black);     //设置字体颜色
		centerAlign.setFontBold(false);          //字体加粗
		centerAlign.setFontSize(10);            //设置字体大小	
		xlsx.write(row_count + 3, 1, tr("Standard capacity"), centerAlign);
		xlsx.write(row_count + 3, 2, QString("%1 Ah").arg((float)data.at(2) / 10, 0, 'f', 2), centerAlign);
		xlsx.write(row_count + 3, 3, " ", centerAlign);
		xlsx.write(row_count + 4, 1, tr("Charge voltage"), centerAlign);
		xlsx.write(row_count + 4, 2, QString("%1 V").arg((float)data.at(1) / 10, 0, 'f', 2), centerAlign);
		xlsx.write(row_count + 4, 3, " ", centerAlign);
		xlsx.write(row_count + 5, 1, tr("Charge current"), centerAlign);
		xlsx.write(row_count + 5, 2, QString("%1 A").arg((float)data.at(2) / 10, 0, 'f', 2), centerAlign);
		xlsx.write(row_count + 5, 3, " ", centerAlign);
		xlsx.write(row_count + 6, 1, tr("Discharge current"), centerAlign);
		xlsx.write(row_count + 6, 2, QString("%1 A").arg((float)data.at(3) / 10, 0, 'f', 2), centerAlign);
		xlsx.write(row_count + 6, 3, " ", centerAlign);
		xlsx.write(row_count + 7, 1, tr("Cycle count"), centerAlign);
		xlsx.write(row_count + 7, 2, data.at(4), centerAlign);
		xlsx.write(row_count + 7, 3, " ", centerAlign);
		centerAlign.setFontColor(Qt::blue);     //设置字体颜色
		centerAlign.setFontBold(true);          //字体加粗
		centerAlign.setFontSize(12);            //设置字体大小
		result_row_count = row_count + 8;
		xlsx.write(row_count + 8, 1, tr("Test result"), centerAlign);
		xlsx.write(row_count + 8, 3, " ", centerAlign);
		xlsx.save();
	}
	break;
	//充放电测试无结果
	case 4:
	{
		Document xlsx(m_execl_path);
		//设置表头样式
		if (!xlsx.selectSheet("Charge&discharge Test"))
		{
			xlsx.addSheet("Charge&discharge Test");
		}
		int row_count = xlsx.dimension().rowCount();
		centerAlign.setFontBold(true);          //字体加粗
		centerAlign.setFontColor(Qt::blue);     //设置字体颜色
		centerAlign.setFontSize(16);            //设置字体大小	
		xlsx.setColumnWidth(1, 1, 20);  //设置列宽
		xlsx.setColumnWidth(2, 2, 20);  //设置列宽
		xlsx.mergeCells(CellRange(row_count + 1, 1, row_count + 1, 2), centerAlign); //合并单元表格
		xlsx.write("A1", tr("Charge&discharge Test"));       //总标题
		centerAlign.setHorizontalAlignment(QXlsx::Format::AlignLeft); //设置横向、纵向居中	
		centerAlign.setFontSize(12);            //设置字体大小	
		xlsx.write(row_count + 2, 1, tr("Test condition"), centerAlign);
		xlsx.write(row_count + 2, 2, " ", centerAlign);

		centerAlign.setFontColor(Qt::black);     //设置字体颜色
		centerAlign.setFontBold(false);          //字体加粗
		centerAlign.setFontSize(10);            //设置字体大小	
		xlsx.write(row_count + 3, 1, tr("Charge voltage"), centerAlign);
		xlsx.write(row_count + 3, 2, QString("%1 V").arg((float)data.at(1) / 10, 0, 'f', 2), centerAlign);
		xlsx.write(row_count + 4, 1, tr("Standard charge current"), centerAlign);
		xlsx.write(row_count + 4, 2, QString("%1 A").arg((float)data.at(2) / 10, 0, 'f', 2), centerAlign);
		xlsx.write(row_count + 5, 1, tr("Standard discharge current"), centerAlign);
		xlsx.write(row_count + 5, 2, QString("%1 A").arg((float)data.at(4) / 10, 0, 'f', 2), centerAlign);
		xlsx.write(row_count + 5, 1, tr("Fast charge current"), centerAlign);
		xlsx.write(row_count + 5, 2, QString("%1 A").arg((float)data.at(3) / 10, 0, 'f', 2), centerAlign);
		xlsx.write(row_count + 5, 1, tr("Fast discharge current"), centerAlign);
		xlsx.write(row_count + 5, 2, QString("%1 A").arg((float)data.at(5) / 10, 0, 'f', 2), centerAlign);		
		xlsx.save();
	}
	break;
	//SOC测试无结果
	case 5:
	{
		Document xlsx(m_execl_path);
		//设置表头样式
		if (!xlsx.selectSheet("SOC Test"))
		{
			xlsx.addSheet("SOC Test");
		}
		int row_count = xlsx.dimension().rowCount();
		centerAlign.setFontBold(true);          //字体加粗
		centerAlign.setFontColor(Qt::blue);     //设置字体颜色
		centerAlign.setFontSize(16);            //设置字体大小	
		xlsx.setColumnWidth(1, 2, 20);  //设置列宽
		xlsx.setColumnWidth(3, 3, 10);  //设置列宽
		xlsx.mergeCells(CellRange(row_count + 1, 1, row_count + 1, 3), centerAlign); //合并单元表格
		xlsx.write("A1", tr("SOC Test"));       //总标题
		centerAlign.setHorizontalAlignment(QXlsx::Format::AlignLeft); //设置横向、纵向居中
		centerAlign.setFontSize(12);            //设置字体大小	
		xlsx.write(row_count + 2, 1, tr("Test condition"), centerAlign);
		xlsx.write(row_count + 2, 2, " ", centerAlign);
		xlsx.write(row_count + 2, 3, " ", centerAlign);
		centerAlign.setFontColor(Qt::black);     //设置字体颜色
		centerAlign.setFontBold(false);          //字体加粗
		centerAlign.setFontSize(10);            //设置字体大小	
		xlsx.write(row_count + 3, 1, tr("Charge voltage"), centerAlign);
		xlsx.write(row_count + 3, 2, QString("%1 V").arg((float)data.at(1) / 10, 0, 'f', 2), centerAlign);
		xlsx.write(row_count + 3, 3, " ", centerAlign);
		xlsx.write(row_count + 4, 1, tr("Charge current"), centerAlign);
		xlsx.write(row_count + 4, 2, QString("%1 A").arg((float)data.at(2) / 10, 0, 'f', 2), centerAlign);
		xlsx.write(row_count + 4, 3, " ", centerAlign);
		xlsx.write(row_count + 5, 1, tr("Discharge current"), centerAlign);
		xlsx.write(row_count + 5, 2, QString("%1 A").arg((float)data.at(3) / 10, 0, 'f', 2), centerAlign);
		xlsx.write(row_count + 5, 3, " ", centerAlign);
		xlsx.write(row_count + 6, 1, tr("Sample interval"), centerAlign);
		xlsx.write(row_count + 6, 2, QString("%1 %").arg(data.at(4)), centerAlign);
		xlsx.write(row_count + 6, 3, " ", centerAlign);
		xlsx.save();
	}
		break;
	//电流精度测试无结果
	case 6:
	{
		Document xlsx(m_execl_path);
		//设置表头样式
		if (!xlsx.selectSheet("Current_Accuracy Test"))
		{
			xlsx.addSheet("Current_Accuracy Test");
		}
		int row_count = xlsx.dimension().rowCount();
		centerAlign.setFontBold(true);          //字体加粗
		centerAlign.setFontColor(Qt::blue);     //设置字体颜色
		centerAlign.setFontSize(16);            //设置字体大小	
		xlsx.setColumnWidth(1, 5, 20);  //设置列宽
		xlsx.mergeCells(CellRange(row_count + 1, 1, row_count + 1, 5), centerAlign); //合并单元表格
		xlsx.write("A" + QString::number(row_count + 1), tr("Current_Accuracy Test"));       //总标题
		centerAlign.setHorizontalAlignment(QXlsx::Format::AlignLeft); //设置横向、纵向居中
		centerAlign.setFontColor(Qt::black);     //设置字体颜色
		centerAlign.setFontBold(false);          //字体加粗
		centerAlign.setFontSize(10);            //设置字体大小	
		xlsx.write(row_count + 2, 1, tr("Charge voltage"), centerAlign);
		xlsx.write(row_count + 2, 2, QString("%1 V").arg((float)data.at(1) / 10, 0, 'f', 2), centerAlign);
		xlsx.write(row_count + 2, 3, " ", centerAlign);
		xlsx.write(row_count + 2, 4, " ", centerAlign);
		xlsx.write(row_count + 2, 5, " ", centerAlign);
		xlsx.write(row_count + 3, 1, tr("Charge current"), centerAlign);
		xlsx.write(row_count + 3, 2, QString("%1 A").arg((float)data.at(2) / 10, 0, 'f', 2), centerAlign);
		xlsx.write(row_count + 3, 3, " ", centerAlign);
		xlsx.write(row_count + 3, 4, " ", centerAlign);
		xlsx.write(row_count + 3, 5, " ", centerAlign);
		xlsx.write(row_count + 4, 1, tr("Discharge current"), centerAlign);
		xlsx.write(row_count + 4, 2, QString("%1 A").arg((float)data.at(2) / 10, 0, 'f', 2), centerAlign);
		xlsx.write(row_count + 4, 3, " ", centerAlign);
		xlsx.write(row_count + 4, 4, " ", centerAlign);
		xlsx.write(row_count + 4, 5, " ", centerAlign);
		xlsx.write(row_count + 5, 1, tr("Current Sample interval"), centerAlign);
		xlsx.write(row_count + 5, 2, QString("%1 A").arg(data.at(3)), centerAlign);
		xlsx.write(row_count + 5, 3, " ", centerAlign);
		xlsx.write(row_count + 5, 4, " ", centerAlign);
		xlsx.write(row_count + 5, 5, " ", centerAlign);
		xlsx.write(row_count + 6, 1, tr("Error current max"), centerAlign);
		xlsx.write(row_count + 6, 2, QString("%1 A").arg((float)data.at(6) / 1000, 0, 'f', 2), centerAlign);
		xlsx.write(row_count + 6, 3, " ", centerAlign);
		xlsx.write(row_count + 6, 4, " ", centerAlign);
		xlsx.write(row_count + 6, 5, " ", centerAlign);
		xlsx.save();
	}
	break;
	//电压精度测试无结果
	case 7:
	{	
		Document xlsx(m_execl_path);
		//设置表头样式
		if (!xlsx.selectSheet("Voltage_Accuracy Test"))
		{
			xlsx.addSheet("Voltage_Accuracy Test");
		}
		int row_count = xlsx.dimension().rowCount();
		centerAlign.setFontBold(true);          //字体加粗
		centerAlign.setFontColor(Qt::blue);     //设置字体颜色
		centerAlign.setFontSize(16);            //设置字体大小	
		xlsx.setColumnWidth(1, 5, 20);  //设置列宽
		xlsx.mergeCells(CellRange(row_count + 1, 1, row_count + 1, 5), centerAlign); //合并单元表格
		xlsx.write("A" + QString::number(row_count + 1), tr("Voltage_Accuracy Test"));       //总标题
		centerAlign.setHorizontalAlignment(QXlsx::Format::AlignLeft); //设置横向、纵向居中
		centerAlign.setFontColor(Qt::black);     //设置字体颜色
		centerAlign.setFontBold(false);          //字体加粗
		centerAlign.setFontSize(10);            //设置字体大小	
		xlsx.write(row_count + 2, 1, tr("Charge voltage"), centerAlign);
		xlsx.write(row_count + 2, 2, QString("%1 V").arg((float)data.at(1) / 10, 0, 'f', 2), centerAlign);
		xlsx.write(row_count + 2, 3, " ", centerAlign);
		xlsx.write(row_count + 2, 4, " ", centerAlign);
		xlsx.write(row_count + 2, 5, " ", centerAlign);
		xlsx.write(row_count + 3, 1, tr("Charge current"), centerAlign);
		xlsx.write(row_count + 3, 2, QString("%1 A").arg((float)data.at(2) / 10, 0, 'f', 2), centerAlign);
		xlsx.write(row_count + 3, 3, " ", centerAlign);
		xlsx.write(row_count + 3, 4, " ", centerAlign);
		xlsx.write(row_count + 3, 5, " ", centerAlign);
		xlsx.write(row_count + 4, 1, tr("Discharge current"), centerAlign);
		xlsx.write(row_count + 4, 2, QString("%1 A").arg((float)data.at(3) / 10, 0, 'f', 2), centerAlign);
		xlsx.write(row_count + 4, 3, " ", centerAlign);
		xlsx.write(row_count + 4, 4, " ", centerAlign);
		xlsx.write(row_count + 4, 5, " ", centerAlign);
		xlsx.write(row_count + 5, 1, tr("Sample interval"), centerAlign);
		xlsx.write(row_count + 5, 2, QString("%1 %").arg(data.at(4)), centerAlign);
		xlsx.write(row_count + 5, 3, " ", centerAlign);
		xlsx.write(row_count + 5, 4, " ", centerAlign);
		xlsx.write(row_count + 5, 5, " ", centerAlign);
		xlsx.write(row_count + 6, 1, tr("Error voltage max"), centerAlign);
		xlsx.write(row_count + 6, 2, QString("%1 V").arg((float)data.at(7)/1000, 0, 'f', 2), centerAlign);
		xlsx.write(row_count + 6, 3, " ", centerAlign);
		xlsx.write(row_count + 6, 4, " ", centerAlign);
		xlsx.write(row_count + 6, 5, " ", centerAlign);
		xlsx.write(row_count + 7, 1, tr("Resonable voltage range"), centerAlign);
		xlsx.write(row_count + 7, 2, QString("%1 - %2 V").arg((float)data.at(8) / 1000, 0, 'f', 2).arg((float)data.at(9) / 1000, 0, 'f', 2), centerAlign);
		xlsx.write(row_count + 7, 3, " ", centerAlign);
		xlsx.write(row_count + 7, 4, " ", centerAlign);
		xlsx.write(row_count + 7, 5, " ", centerAlign);
		xlsx.save();
	}
	break;
	default:
		break;
	}
}

void Data_WriteTOExecl::getHysteresisData(QList<int> data)
{
	testconditionReset(); //每次进来均复位一次
	switch (data.at(0))
	{
	case 0://普通充电
	{
		if (data.at(5) == 1)
		{
			fullcharge = true;
		}
		else
		{
			cutoff_Soc_charge = true;
			m_cutSoc = data.at(6);
		}
	}
	break;
	case 1://普通放电
	{
		if (data.at(5) == 1)
		{
			fulldischarge = true;
		}
		else
		{
			cutoff_Soc_discharge = true;
			m_cutSoc = data.at(6);
		}
	}
	break;
	case 2://冒烟测试
	{
		if (data.at(1) == 0)
		{
			smoking_test_charge = true;
		}
		else
		{
			smoking_test_discharge = true;
		}
	}
	break;
	case 3: //容量测试
	{
		if (data.at(1) == 0)
		{
			capacity_test_charge = true;
		}
		else
		{
			capacity_total_cycle = data.at(5);
			capacity_test_state = true;
		}
		
	}
	break;
	case 4: //充放电测试
	{
		if (data.at(5) == 0)
		{
			CD_charge_simplecharge = true;
		}
		else if(data.at(5) == 1)
		{
			CD_charge_standarddischarge = true;
		}
		else if (data.at(5) == 2)
		{
			CD_charge_standardcharge = true;
		}
		else if (data.at(5) == 3)
		{
			CD_charge_fastdischarge = true;
		}
		else if (data.at(5) == 4)
		{
			CD_charge_fastcharge = true;
		}
	}
	break;
	case 5://SOC测试
	{
		if (data.at(6) == 0)
		{
			SOC_Test_precharge = true;
		}
		if (data.at(6) == 1)
		{
			SOC_Test_Discharge = true;
			soc_percentage = data.at(5);
			soc_test_gap = ((float)data.at(4) /100) * data.at(5) * 100;
		}
		if (data.at(6) == 2)
		{
			SOC_Test_Charge = true;
		}
	}
	break;
	case 6://电流精度测试
	{
		if (data.at(6) == 0)
		{
			current_accuracy_charge_num++;
			current_accuracy_charge = true;
			test_now_current = data.at(3);
			standard_err_current = data.at(5);
		}
		else if (data.at(6) == 1)
		{
			current_accuracy_discharge_num++;
			current_accuracy_discharge = true;
			test_now_current = data.at(4);
			standard_err_current = data.at(5);
		}
		else if (data.at(6) == 2)
		{
			current_accuracy_Pre_full = true;
		}
		else
		{
			current_accuracy_Pre_empty = true;
		}
	}
	break;
	case 7://电压精度测试
	{
		if (data.at(6) == 0)
		{
			voltage_accuracy_charge_num++;
			voltage_accuracy_charge = true;
			test_now_soc = data.at(5);
			standard_err_voltage = data.at(6);
		}
		else if (data.at(6) == 1)
		{
			voltage_accuracy_discharge_num++;
			voltage_accuracy_discharge = true;
			test_now_soc = data.at(5);
			standard_err_voltage = data.at(6);
		}
		else if (data.at(6) == 2)
		{
			voltage_accuracy_Pre_full = true;
		}
		else
		{
			voltage_accuracy_Pre_empty = true;
		}
	}
	break;
	case 8://电压精度测试
	{
		if (data.at(5) == 0)
		{
			protection_overshoot_test = true;
			overshoot_warning_voltatge = data.at(6);
		}
		else if (data.at(5) == 1)
		{
			protection_overfall_test = true;
		}
		else if (data.at(5) == 2)
		{
			protection_pre_charge = true;
		}
		else if (data.at(5) == 3)
		{
			protection_pre_discharge = true;
		}
	
	}
	break;
	default:
		break;
	}

}

void Data_WriteTOExecl::get_whatWriteToExecl(Data_Zhili data)
{
	temp_data_zhili = data;
	//普通充放
	if (fullcharge)
	{
		std::bitset<16> bitset1_t(data.vstate_list);
		if (bitset1_t.test(0) || bitset1_t.test(2))
		{
			emit tested_end(true);
			emit start_next_Alone(); //进行父项
		}
	}
	if (fulldischarge)
	{
		std::bitset<16> bitset1_t(data.vstate_list);
		if (bitset1_t.test(1) || bitset1_t.test(3))
		{
			emit tested_end(true);
			emit overfall_state(true);
			emit start_next_Alone(); //进行父项
		}
	}
	if (cutoff_Soc_charge)
	{
		if (data.Soc > m_cutSoc)
		{
			cutoff_Soc_charge = false;
			emit tested_end(true);
			emit start_next_Alone();
		}
	}
	if (cutoff_Soc_discharge)
	{
		if (data.Soc < m_cutSoc)
		{
			cutoff_Soc_discharge = false;
			emit tested_end(true);
			emit start_next_Alone();
		}
	}
	//冒烟测试
	if (smoking_test_charge)
	{
		smoking_test_charge = false;
		smoking_now = 1;
		smoking_status++;
		QTimer::singleShot(15000, this, &Data_WriteTOExecl::deal_for_smoking);
	}
	if (smoking_test_discharge)
	{
		smoking_test_discharge = false;
		smoking_now = 2;
		smoking_status++;
		QTimer::singleShot(15000, this, &Data_WriteTOExecl::deal_for_smoking);
	}
	//容量测试
	if (capacity_test_charge) //充
	{
		pass_num++;
		if (pass_num > 10)
		{
			std::bitset<16> bitset1_t(data.vstate_list);
			if (bitset1_t.test(0) || bitset1_t.test(2))
			{
				pass_num = 0;
				capacity_test_charge = false;
				emit start_next_multiple(); //进行子项
			}
		}
	}
	if (capacity_test_state) //放
	{
		std::bitset<16> bitset1_t(data.vstate_list);
		if (bitset1_t.test(1) || bitset1_t.test(3))
		{
			capfull_list.append((int)(data.CapFull * 100));
			pass_num = 0;
			capacity_test_state = false;
			deal_for_capacity();
		}
		else
		{
			cap_current_B.append(data.discharge_current);
			cap_current_M.append(data.PSD1_Current_Measured);
		}
	}
	//充放电测试
	if (CD_charge_simplecharge)
	{
		pass_num++;
		if (pass_num > 10)
		{
			std::bitset<16> bitset1_t(data.vstate_list);
			if (bitset1_t.test(0) || bitset1_t.test(2))
			{
				pass_num = 0;
				CD_charge_simplecharge = false;
				emit start_next_multiple(); //进行子项
			}
		}
	}
	if (CD_charge_standarddischarge)
	{
		deal_for_CD_test(data, 1, tr("Standard discharge"));
	}
	if (CD_charge_standardcharge)
	{
		deal_for_CD_test(data, 2, tr("Standard charge"));
	}
	if (CD_charge_fastdischarge)
	{
		deal_for_CD_test(data, 3, tr("Fast discharge"));
	}
	if (CD_charge_fastcharge)
	{
		deal_for_CD_test(data, 4, tr("Fast charge"));
	}	
	//SOC测试
	if (SOC_Test_precharge)
	{
		pass_num++;
		if (pass_num > 8)
		{
			std::bitset<16> bitset1_t(data.vstate_list);
			if (bitset1_t.test(0) || bitset1_t.test(2))
			{
				pass_num = 0;
				SOC_Test_precharge = false;
				emit start_next_multiple(); //进行子项
			}
		}
	}
	if (SOC_Test_Discharge)
	{
		deal_for_SOCTest_discharge(data);
	}
	if (SOC_Test_Charge)
	{
		deal_for_SOCTest_charge(data);
	}
	//电流精度测试
	if (current_accuracy_Pre_empty)
	{
		if (data.Soc <= 10)
		{
			current_accuracy_Pre_empty = false;
			emit start_next_multiple();
		}
	}
	if (current_accuracy_Pre_full)
	{
		if (data.Soc >= 20)
		{
			current_accuracy_Pre_full = false;
			emit start_next_multiple();
		}
	}
	if (current_accuracy_charge)
	{
		if (data.Soc > 15)
		{
			pass_num = 0;
			current_accuracy_charge = false;
			current_accuracy_charge_num--;
			emit start_test_adjust(1);		
			return;
		}
		pass_num++;
		if (pass_num > 30)
		{
			pass_num = 0;
			current_accuracy_charge = false;
			deal_current_accuracy(data, 0);
		}
		
	}
	if (current_accuracy_discharge)
	{
		if (data.Soc < 15)
		{
			pass_num = 0;
			current_accuracy_discharge = false;
			current_accuracy_discharge_num--;
			emit start_test_adjust(0);
			return;
		}
		pass_num++;
		if (pass_num > 30)
		{
			pass_num = 0;
			current_accuracy_discharge = false;
			deal_current_accuracy(data, 1);
		}
	}
	//电压精度测试
	if (voltage_accuracy_Pre_empty)
	{
		std::bitset<16> bitset1_t(data.vstate_list);
		if(bitset1_t.test(1) || bitset1_t.test(3))
		{
			voltage_accuracy_Pre_empty = false;
			emit start_next_multiple();
		}
	}
	if (voltage_accuracy_Pre_full)
	{
		std::bitset<16> bitset1_t(data.vstate_list);
		if (bitset1_t.test(0) || bitset1_t.test(2))
		{
			voltage_accuracy_Pre_full = false;
			emit start_next_multiple();
		}
	}
	if (voltage_accuracy_charge)
	{
		if (data.Soc > test_now_soc)
		{
			voltage_accuracy_charge_num--;
			voltage_accuracy_charge = false;
			emit start_next_multiple();
		}
		if (data.Soc == test_now_soc)
		{
			voltage_accuracy_charge = false;
			deal_voltage_accuracy(data, 0);
		}
	}
	if (voltage_accuracy_discharge)
	{
		if (data.Soc < test_now_soc)
		{
			voltage_accuracy_discharge_num--;
			voltage_accuracy_discharge = false;
			emit start_next_multiple();
		}
		if (data.Soc == test_now_soc)
		{
			voltage_accuracy_discharge = false;
			deal_voltage_accuracy(data, 1);
		}
	}

	if (protection_pre_discharge)
	{
		if (data.voltage <95)
		{
			protection_pre_discharge = false;
			emit start_next_multiple();
		}
	}
	if (protection_overshoot_test)
	{
		std::bitset<16> bitset1_t(data.vstate_list);
		if (bitset1_t.test(4))
		{
			qDebug() <<"max cell voltage"<< data.max_cell_voltage << endl;
		}
	}
}

void Data_WriteTOExecl::deal_for_smoking()
{
	Document xlsx(m_execl_path);
	//设置表头样式
	if (!xlsx.selectSheet("Smoking Test"))
	{
		xlsx.addSheet("Smoking Test");
	}	
	Format centerAlign;
	centerAlign.setHorizontalAlignment(QXlsx::Format::AlignLeft); //设置横向、纵向居中
	centerAlign.setVerticalAlignment(QXlsx::Format::AlignVCenter);   //
											
	centerAlign.setTopBorderStyle(QXlsx::Format::BorderThin);//设置上下左右的线类型
	centerAlign.setBottomBorderStyle(QXlsx::Format::BorderThin);
	centerAlign.setLeftBorderStyle(QXlsx::Format::BorderThin);
	centerAlign.setRightBorderStyle(QXlsx::Format::BorderThin);

	int row_count = xlsx.dimension().rowCount();
	centerAlign.setFontSize(10);
	centerAlign.setFontBold(false);          //字体取消加粗
	std::bitset<16> bitset1_t(temp_data_zhili.cstate_list);
	if (smoking_now == 1) //----------------------充电
	{
		if (temp_data_zhili.Charger_Current > 0 && bitset1_t.test(0))
		{
			centerAlign.setFontBold(true);          //字体加粗
			centerAlign.setFontColor(Qt::black);  //设置字体颜色
			xlsx.write(row_count + 1, 1, tr("Charge attempt"), centerAlign);
			centerAlign.setFontBold(false);          //字体加粗
			xlsx.write(row_count + 1, 2, tr("The charging function is normal"), centerAlign);
			centerAlign.setFontColor(Qt::green);  //设置字体颜色
			xlsx.write(row_count + 1, 3, "Pass", centerAlign);

			//ui界面显示结果
			emit tested_result_bool(tr("Charge attempt"), true);
		}
		else
		{
			smoking_err_num ++; //smoking_err_num 不为零，即代表测试没通过
			centerAlign.setFontBold(true);          //字体加粗		
			centerAlign.setFontColor(Qt::black);  //设置字体颜色
			xlsx.write(row_count + 1, 1, tr("Charge attempt"), centerAlign);
			centerAlign.setFontBold(false);          //字体加粗	
			xlsx.write(row_count + 1, 2, tr("The charging function is unusual"), centerAlign);       //总标题
			centerAlign.setFontColor(Qt::red);  //设置字体颜色
			xlsx.write(row_count + 1, 3, "False", centerAlign);       //总标题

			QString tem_str1, tem_str2, tem_str3, tem_str4;
			tem_str1 = "CState = " + QString::number(temp_data_zhili.cstate_list);
			tem_str2 = "FETState = " + QString::number(temp_data_zhili.fetstate_list);
			std::bitset<16> bitset1_t(temp_data_zhili.cstate_list);
			if (bitset1_t.test(0))
			{
				tem_str3 = tr("Charging state is set 1");     
				centerAlign.setFontColor(Qt::green);  //设置字体颜色
				xlsx.write(row_count + 2, 3, "Pass", centerAlign);      
			}
			else
			{
				tem_str3 = tr("Charging state is not set 1");       
				centerAlign.setFontColor(Qt::red);  //设置字体颜色
				xlsx.write(row_count + 2, 3, "False", centerAlign);       
			}
			centerAlign.setFontColor(Qt::black);  //设置字体颜色
			xlsx.write(row_count + 2, 1, tem_str1, centerAlign);
			xlsx.write(row_count + 2, 2, tem_str3, centerAlign);

			std::bitset<8> bitset2_t(temp_data_zhili.fetstate_list);
			if (bitset2_t.test(0))
			{
				tem_str4 = tr("The charging switch is on");     
				centerAlign.setFontColor(Qt::green);  //设置字体颜色
				xlsx.write(row_count + 3, 3, "Pass", centerAlign);      
			}
			else
			{
				tem_str4 = tr("The charging switch is not on");   
				centerAlign.setFontColor(Qt::red);  //设置字体颜色
				xlsx.write(row_count + 3, 3, "False", centerAlign);      
			} 
			centerAlign.setFontColor(Qt::black);  //设置字体颜色
			xlsx.write(row_count + 3, 1, tem_str2, centerAlign);
			xlsx.write(row_count + 3, 2, tem_str4, centerAlign);
			xlsx.write(row_count + 3, 3, " ", centerAlign);
			xlsx.write(row_count + 4, 1, tr("BMS charge current"), centerAlign);
			xlsx.write(row_count + 4, 2, QString("%1").arg(temp_data_zhili.charge_current, 0, 'f', 3), centerAlign);
			xlsx.write(row_count + 4, 3, " ", centerAlign);
			xlsx.write(row_count + 5, 1, tr("Charging Mesured Current"), centerAlign);
			xlsx.write(row_count + 5, 2, QString("%1").arg(temp_data_zhili.Charger_Current, 0, 'f', 3), centerAlign);
			xlsx.write(row_count + 5, 3, " ", centerAlign);

			emit tested_result_bool(tr("Charge attempt"), false);
		}	

	}
	else
	{
		if (temp_data_zhili.PSD1_Current_Measured > 0 && bitset1_t.test(1))
		{
			centerAlign.setFontBold(true);          //字体加粗
			centerAlign.setFontColor(Qt::black);  //设置字体颜色
			xlsx.write(row_count + 1, 1, tr("Discharge attempt"),centerAlign);
			centerAlign.setFontBold(false);          //字体加粗
			xlsx.write(row_count + 1, 2, tr("The discharging function is normal"), centerAlign);
			centerAlign.setFontColor(Qt::green);  //设置字体颜色
			xlsx.write(row_count + 1, 3, "Pass", centerAlign);

			emit tested_result_bool(tr("Disharge attempt"), true);
		}
		else
		{
			smoking_err_num++;
			centerAlign.setFontBold(true);          //字体加粗
			centerAlign.setFontColor(Qt::black);  //设置字体颜色
			xlsx.write(row_count + 1, 1, tr("Discharge attempt"), centerAlign);
			centerAlign.setFontBold(false);          //字体加粗	
			xlsx.write(row_count + 1, 2, tr("The discharging function is unusual"), centerAlign);  
			centerAlign.setFontColor(Qt::red);  //设置字体颜色
			xlsx.write(row_count + 1, 3, "False", centerAlign);

			QString tem_str1, tem_str2, tem_str3, tem_str4;
			tem_str1 = "CState = " + QString::number(temp_data_zhili.cstate_list);
			tem_str2 = "FETState = " + QString::number(temp_data_zhili.fetstate_list);
			std::bitset<16> bitset1_t(temp_data_zhili.cstate_list);
			if (bitset1_t.test(1))
			{
				tem_str3 = tr("Discharging state is set 1");
				centerAlign.setFontColor(Qt::green);  //设置字体颜色
				xlsx.write(row_count + 2, 3, "Pass", centerAlign);
			}
			else
			{
				tem_str3 = tr("Discharging state is not set 1");
				centerAlign.setFontColor(Qt::red);  //设置字体颜色
				xlsx.write(row_count + 2, 3, "False", centerAlign);
			}
			centerAlign.setFontColor(Qt::black);  //设置字体颜色
			xlsx.write(row_count + 2, 1, tem_str1, centerAlign);
			xlsx.write(row_count + 2, 2, tem_str3, centerAlign);

			std::bitset<8> bitset2_t(temp_data_zhili.fetstate_list);
			if (bitset2_t.test(1))
			{
				tem_str4 = tr("The discharging switch is on");
				centerAlign.setFontColor(Qt::green);  //设置字体颜色
				xlsx.write(row_count + 3, 3, "Pass", centerAlign);
			}
			else
			{
				tem_str4 = tr("The discharging switch is not on");
				centerAlign.setFontColor(Qt::red);  //设置字体颜色
				xlsx.write(row_count + 3, 3, "False", centerAlign);
			}
			centerAlign.setFontColor(Qt::black);  //设置字体颜色
			xlsx.write(row_count + 3, 1, tem_str2, centerAlign);
			xlsx.write(row_count + 3, 2, tem_str4, centerAlign);
			xlsx.write(row_count + 3, 3, " ", centerAlign);
			xlsx.write(row_count + 4, 1, tr("BMS discharge current"), centerAlign);
			xlsx.write(row_count + 4, 2, QString("%1").arg(temp_data_zhili.discharge_current, 0, 'f', 3), centerAlign);
			xlsx.write(row_count + 4, 3, " ", centerAlign);
			xlsx.write(row_count + 5, 1, tr("PSD1 Current"), centerAlign);
			xlsx.write(row_count + 5, 2, QString("%1").arg(temp_data_zhili.PSD1_Current_Measured, 0, 'f', 3), centerAlign);
			xlsx.write(row_count + 5, 3, " ", centerAlign);

			emit tested_result_bool(tr("Disharge attempt"), false);
		}
	}
	xlsx.save();
	if (smoking_status < 2)
	{
		emit start_next_multiple();
		is_format_data_write = true;
	}
	else
	{
		is_format_data_write = true;
		emit start_verify_test(true);
		smoking_status = 0;
		smoking_now = 0;
	}
}

void Data_WriteTOExecl::write_smoking_data(QList<QString> list)
{
	if (!is_format_data_write)
	{
		return;
	}
	is_format_data_write = false;
	Document xlsx(m_execl_path);
	//设置表头样式
	if (!xlsx.selectSheet("Smoking Test"))
	{/*在当前打开的xlsx文件中，找一个名字为ziv的sheet*/
		xlsx.addSheet("Smoking Test");//找不到的话就添加一个名为ziv的sheet
	}
	Format centerAlign;
	centerAlign.setHorizontalAlignment(QXlsx::Format::AlignLeft); //设置横向、纵向居中
	centerAlign.setVerticalAlignment(QXlsx::Format::AlignVCenter);   //

	centerAlign.setTopBorderStyle(QXlsx::Format::BorderThin);//设置上下左右的线类型
	centerAlign.setBottomBorderStyle(QXlsx::Format::BorderThin);
	centerAlign.setLeftBorderStyle(QXlsx::Format::BorderThin);
	centerAlign.setRightBorderStyle(QXlsx::Format::BorderThin);
	centerAlign.setFontSize(10);
	int row_count = xlsx.dimension().rowCount(); 
	centerAlign.setFontBold(true);
	centerAlign.setFontColor(Qt::black);  //设置字体颜色
	xlsx.mergeCells(CellRange(row_count + 1, 1, row_count + 1, 3), centerAlign); //合并单元表格
	xlsx.write("A" + QString::number(row_count + 1), list.at(0));       //总标题
	row_count += 2;
	bool result_right = true;
	centerAlign.setFontBold(false);         
	for (int i = 2 ; i < list.size(); i+= 2)
	{
		centerAlign.setFontColor(Qt::black);  //设置字体颜色
		xlsx.write(row_count, 1, list.at(i), centerAlign);       
		xlsx.write(row_count, 2, list.at(i+1), centerAlign);       
		if (list.at(i + 1).contains("error"))
		{
			smoking_err_num++;
			result_right = false;
			centerAlign.setFontColor(Qt::red);  //设置字体颜色
			xlsx.write(row_count, 3, "False", centerAlign);       
		}
		else
		{
			centerAlign.setFontColor(Qt::green);  //设置字体颜色
			xlsx.write(row_count, 3, "Pass", centerAlign);       
		}
		row_count++;
	}
	if (result_right)
	{
		emit tested_result_bool(tr("Communication Test"), true);
	}
	else
	{
		emit tested_result_bool(tr("Communication Test"), false);
	}
	if (smoking_err_num)
	{
		centerAlign.setFontSize(12);
		centerAlign.setFontColor(Qt::red);  //设置字体颜色
		xlsx.write(result_row_count, 2, "False", centerAlign);
	}
	else
	{
		centerAlign.setFontSize(12);
		centerAlign.setFontColor(Qt::green);  //设置字体颜色
		xlsx.write(result_row_count, 2, "Pass", centerAlign);
	}

	if (!xlsx.selectSheet("Battery Report"))
	{
		xlsx.addSheet("Battery Report");
	}
	int row_count_final = xlsx.dimension().rowCount();
	centerAlign.setFontBold(true);          
	centerAlign.setFontColor(Qt::black);  
	centerAlign.setFontSize(10);
	xlsx.write(row_count_final + 1, 1, tr("Smoking Test"), centerAlign);
	if (smoking_err_num)
	{
		smoking_err_num = 0;
		centerAlign.setFontColor(Qt::red);  
		xlsx.write(row_count_final + 1, 2, tr("False"), centerAlign);
		emit tested_end(false);	
	}
	else
	{
		centerAlign.setFontColor(Qt::green);  
		xlsx.write(row_count_final + 1, 2, tr("Pass"), centerAlign);
		emit tested_end(true);
	}
	emit start_next_Alone();
	xlsx.save();
}

void Data_WriteTOExecl::deal_for_capacity()
{
	capacity_count_now++;

	Document xlsx(m_execl_path);
	//设置表头样式
	if (!xlsx.selectSheet("Capacity Test"))
	{
		xlsx.addSheet("Capacity Test");
	}
	Format centerAlign;
	centerAlign.setHorizontalAlignment(QXlsx::Format::AlignLeft); //设置横向、纵向居中
	centerAlign.setVerticalAlignment(QXlsx::Format::AlignVCenter);   //
	centerAlign.setTopBorderStyle(QXlsx::Format::BorderThin);//设置上下左右的线类型
	centerAlign.setBottomBorderStyle(QXlsx::Format::BorderThin);
	centerAlign.setLeftBorderStyle(QXlsx::Format::BorderThin);
	centerAlign.setRightBorderStyle(QXlsx::Format::BorderThin);
	int row_count = xlsx.dimension().rowCount();
	centerAlign.setFontSize(10);
	centerAlign.setFontColor(Qt::black);     //设置字体颜色
	centerAlign.setFontBold(false);          //字体加粗
	float capacity_total_B = 0, capacity_total_M = 0;
	for (int i = 0; i < cap_current_B.size(); i++)
	{
		capacity_total_B += cap_current_B.at(i) / 3600;
		capacity_total_M += cap_current_M.at(i) / 3600;
	}
	QString temp_Ui_cap_P = tr("Cycle") + QString::number(capacity_count_now) + tr("Actual discharge capacity");
	QString temp_Ui_cap_B = tr("Cycle") + QString::number(capacity_count_now) + tr("BMS discharge capacity") ;
	xlsx.write(row_count + 1, 1, temp_Ui_cap_P, centerAlign);
	xlsx.write(row_count + 1, 2, QString("%1 Ah").arg(capacity_total_M, 0, 'f', 3), centerAlign);
	xlsx.write(row_count + 2, 1, temp_Ui_cap_B, centerAlign);
	xlsx.write(row_count + 2, 2, QString("%1 Ah").arg(capacity_total_B, 0, 'f', 3), centerAlign);
	//主界面更新一次容量值
	emit tested_result_str(temp_Ui_cap_P , QString(" %1 Ah").arg(capacity_total_M, 0, 'f', 3));
	emit tested_result_str(temp_Ui_cap_B, QString(" %1 Ah").arg(capacity_total_B, 0, 'f', 3));
	//记录下最大容量
	if (capacity_total_M > max_capatcity)
	{
		max_capatcity = capacity_total_M;
	}
	
	//数据清空，等待下一次测试
	cap_current_B.clear();
	cap_current_M.clear();
	if (capacity_count_now == capacity_total_cycle)  //测试结束
	{
		//容量学习结论
		int first_capfull = capfull_list.at(0);
		bool cap_study = false;
		for (int i = 1; i < capfull_list.size(); i++)
		{
			if (first_capfull != capfull_list.at(i))
			{
				cap_study = true;
			}
		}
		if (cap_study)
		{
			emit tested_result_bool(tr("Capacity study"), true);
			centerAlign.setFontColor(Qt::black);  //设置字体颜色
			xlsx.write(row_count + 3, 1, tr("Capacity study"), centerAlign);
			centerAlign.setFontColor(Qt::green);  //设置字体颜色
			xlsx.write(row_count + 3, 2, "Pass", centerAlign);
		}
		else
		{
			capacity_err_num++;
			emit tested_result_bool(tr("Capacity study"), false);
			centerAlign.setFontColor(Qt::black);  //设置字体颜色
			xlsx.write(row_count + 3, 1, tr("Capacity study"), centerAlign);
			centerAlign.setFontColor(Qt::red);  //设置字体颜色
			xlsx.write(row_count + 3, 2, "False", centerAlign);
		}

		if (max_capatcity > (float)standard_capacity/10) //  /10将单位0.1Ah转为1Ah
		{
			emit tested_result_bool(tr("Capacity estimation"), true);
			centerAlign.setFontColor(Qt::black);  //设置字体颜色
			xlsx.write(row_count + 4, 1, tr("Capacity estimation"), centerAlign);
			centerAlign.setFontColor(Qt::green);  //设置字体颜色
			xlsx.write(row_count + 4, 2, "Pass", centerAlign);
		}
		else
		{
			capacity_err_num++;
			emit tested_result_bool(tr("Capacity estimation"), false);
			centerAlign.setFontColor(Qt::black);  //设置字体颜色
			xlsx.write(row_count + 4, 1, tr("Capacity estimation"), centerAlign);
			centerAlign.setFontColor(Qt::red);  //设置字体颜色
			xlsx.write(row_count + 4, 2, "False", centerAlign);
		}
		if (capacity_err_num)
		{
			centerAlign.setFontColor(Qt::red);  //设置字体颜色
			xlsx.write(result_row_count, 2, "False", centerAlign);
		}
		else
		{
			centerAlign.setFontColor(Qt::green);  //设置字体颜色
			xlsx.write(result_row_count, 2, "Pass", centerAlign);
		}
		//总测试结论
		if (!xlsx.selectSheet("Battery Report"))
		{
			xlsx.addSheet("Battery Report");
		}
		int row_count_final = xlsx.dimension().rowCount();
		if (capacity_err_num == 0)
		{
			centerAlign.setFontColor(Qt::black);  //设置字体颜色
			xlsx.write(row_count_final + 1, 1, tr("Capacity Test"), centerAlign);
			centerAlign.setFontColor(Qt::green);  //设置字体颜色
			xlsx.write(row_count_final + 1, 2, "Pass", centerAlign);
			emit tested_end(true);
		}
		else
		{
			centerAlign.setFontColor(Qt::black);  //设置字体颜色
			xlsx.write(row_count_final + 1, 1, tr("Capacity Test"), centerAlign);
			centerAlign.setFontColor(Qt::red);  //设置字体颜色
			xlsx.write(row_count_final + 1, 2, "False", centerAlign);
			emit tested_end(false);
		}

		//数据复位
		capacity_count_now = 0;
		capacity_total_cycle = 0;
		max_capatcity = 0;
		capacity_err_num = 0;
		emit start_next_Alone(); //进行下一个父项
	}
	else
	{	
		emit start_next_multiple(); //进行子项
	}
	xlsx.save();
}

void Data_WriteTOExecl::deal_for_CD_test(Data_Zhili & data, int type, QString str)
{
	if (is_first_coming)
	{
		is_first_coming = false;
		Document xlsx(m_execl_path);
		//设置表头样式
		if (!xlsx.selectSheet("Charge&discharge Test"))
		{
			xlsx.addSheet("Charge&discharge Test");
		}
		Format centerAlign;
		centerAlign.setHorizontalAlignment(QXlsx::Format::AlignHCenter); //设置横向、纵向居中
		centerAlign.setVerticalAlignment(QXlsx::Format::AlignVCenter);   //

		centerAlign.setTopBorderStyle(QXlsx::Format::BorderThin);//设置上下左右的线类型
		centerAlign.setBottomBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setLeftBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setRightBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setFontBold(true);          //字体加粗
		centerAlign.setFontColor(Qt::black);     //设置字体颜色
		centerAlign.setFontSize(12);            //设置字体大小	
		int rowCount = xlsx.dimension().rowCount();
		if (rowCount < 40)
		{
			xlsx.mergeCells(CellRange(rowCount + 2, 1, rowCount + 2, 2), centerAlign); //合并单元表格
			xlsx.write("A" + QString::number(rowCount + 44), str);
		}
		else
		{
			xlsx.mergeCells(CellRange(rowCount + 44, 1, rowCount + 44, 2), centerAlign); //合并单元表格
			xlsx.write("A" + QString::number(rowCount + 44), str);
		}
		
		xlsx.save();

		start_voltage = data.voltage;
		start_temperature = data.max_temperature;
	}
	std::bitset<16> bitset1_t(data.vstate_list);
	//充电
	if (type%2 == 0) //充电
	{
		if (bitset1_t.test(0) || bitset1_t.test(2))
		{
			CD_charge_standardcharge = false;
			CD_charge_fastcharge = false;

			Document xlsx(m_execl_path);
			//设置表头样式
			if (!xlsx.selectSheet("Charge&discharge Test"))
			{
				xlsx.addSheet("Charge&discharge Test");
			}
			Format centerAlign;
			centerAlign.setHorizontalAlignment(QXlsx::Format::AlignHCenter); //设置横向、纵向居中
			centerAlign.setVerticalAlignment(QXlsx::Format::AlignVCenter);   //
			centerAlign.setTopBorderStyle(QXlsx::Format::BorderThin);//设置上下左右的线类型
			centerAlign.setBottomBorderStyle(QXlsx::Format::BorderThin);
			centerAlign.setLeftBorderStyle(QXlsx::Format::BorderThin);
			centerAlign.setRightBorderStyle(QXlsx::Format::BorderThin);
			centerAlign.setFontBold(false);          //字体加粗
			centerAlign.setFontColor(Qt::black);     //设置字体颜色
			centerAlign.setFontSize(10);
			int rowcount = xlsx.dimension().rowCount();

			xlsx.write(rowcount + 1, 1, tr("Start voltage"), centerAlign);
			xlsx.write(rowcount + 1, 2, QString("%1").arg(start_voltage, 0, 'f', 3), centerAlign);
			xlsx.write(rowcount + 2, 1, tr("End voltage"), centerAlign);
			xlsx.write(rowcount + 2, 2, QString("%1").arg(data.voltage, 0, 'f', 3), centerAlign);
			quint16 cc[] = { 0xfe12, 0x0043, 0 };
			xlsx.write(rowcount + 3, 1, tr("Start Max temperature"), centerAlign);
			xlsx.write(rowcount + 3, 2, QString("%1 ").arg(start_temperature) + QString::fromUtf16(cc), centerAlign);
			xlsx.write(rowcount + 4, 1, tr("End Max temperature"), centerAlign);
			xlsx.write(rowcount + 4, 2, QString("%1").arg(data.max_temperature) + QString::fromUtf16(cc), centerAlign);
			xlsx.write(rowcount + 5, 1, tr("End current"), centerAlign);
			xlsx.write(rowcount + 5, 2, QString("%1").arg(data.PSD1_Current_Measured, 0, 'f', 3), centerAlign);
			xlsx.write(rowcount + 6, 1, tr("End of condition"), centerAlign);
			if (bitset1_t.test(0))
			{
				xlsx.write(rowcount + 6, 2, tr("Monomer overvoltage"), centerAlign);
			}
			else
			{
				xlsx.write(rowcount + 6, 2, tr("Battery pack overvoltage"), centerAlign);
			}

			if (type == 2)
			{
				emit tested_result_bool(tr("Standard charge test"), true);
				emit start_next_multiple(); //进行子项
			}
			else
			{
				//总测试结论
				if (!xlsx.selectSheet("Battery Report"))
				{
					xlsx.addSheet("Battery Report");
				}
				int row_count_final = xlsx.dimension().rowCount();
				centerAlign.setFontColor(Qt::black);  //设置字体颜色
				xlsx.write(row_count_final + 1, 1, tr("Charge discharge Test"), centerAlign);
				centerAlign.setFontColor(Qt::green);  //设置字体颜色
				xlsx.write(row_count_final + 1, 2, "Pass", centerAlign);

				emit tested_result_bool(tr("Fast charge test"), true);
				emit tested_end(true);
				emit start_next_Alone(); //进行下一个父项目
			}
			xlsx.save();
			emit painter_data_for_CD_test(type, m_execl_path, m_time_vector, m_voltage_CD, m_chargeCurrent_CD, m_dischargeCurrent_CD, m_Soc_vector, m_Maxtemperature_CD);
					
			is_first_coming = true;
			m_time_vector.clear();
			m_voltage_CD.clear();
			m_chargeCurrent_CD.clear();
			m_dischargeCurrent_CD.clear();
			m_Soc_vector.clear();
			m_Maxtemperature_CD.clear();
			
		}
		else
		{
			QDateTime time = QDateTime::currentDateTime();
			m_time_vector.append(time.toMSecsSinceEpoch()*0.001);
			m_voltage_CD.append(data.voltage);
			m_chargeCurrent_CD.append(data.charge_current);
			m_dischargeCurrent_CD.append(data.discharge_current);
			m_Maxtemperature_CD.append(data.max_temperature);
			m_Soc_vector.append(data.Soc);
		}
	}
	//放电
	else
	{
		if (bitset1_t.test(1) || bitset1_t.test(3))
		{
			CD_charge_standarddischarge = false;
			CD_charge_fastdischarge = false;

			Document xlsx(m_execl_path);
			//设置表头样式
			if (!xlsx.selectSheet("Charge&discharge Test"))
			{
				xlsx.addSheet("Charge&discharge Test");
			}
			Format centerAlign;
			centerAlign.setHorizontalAlignment(QXlsx::Format::AlignHCenter); //设置横向、纵向居中
			centerAlign.setVerticalAlignment(QXlsx::Format::AlignVCenter);   //
			centerAlign.setTopBorderStyle(QXlsx::Format::BorderThin);//设置上下左右的线类型
			centerAlign.setBottomBorderStyle(QXlsx::Format::BorderThin);
			centerAlign.setLeftBorderStyle(QXlsx::Format::BorderThin);
			centerAlign.setRightBorderStyle(QXlsx::Format::BorderThin);
			centerAlign.setFontBold(false);          //字体加粗
			centerAlign.setFontColor(Qt::black);     //设置字体颜色
			centerAlign.setFontSize(10);
			int rowcount = xlsx.dimension().rowCount();

			xlsx.write(rowcount + 1, 1, tr("Start voltage"), centerAlign);
			xlsx.write(rowcount + 1, 2, QString("%1").arg(start_voltage, 0, 'f', 3), centerAlign);
			xlsx.write(rowcount + 2, 1, tr("End voltage"), centerAlign);
			xlsx.write(rowcount + 2, 2, QString("%1").arg(data.voltage, 0, 'f', 3), centerAlign);
			xlsx.write(rowcount + 3, 1, tr("Start Max temperature"), centerAlign);
			xlsx.write(rowcount + 3, 2, QString("%1").arg(start_temperature), centerAlign);
			xlsx.write(rowcount + 4, 1, tr("End Max temperature"), centerAlign);
			xlsx.write(rowcount + 4, 2, QString("%1").arg(data.max_temperature), centerAlign);
			xlsx.write(rowcount + 5, 1, tr("End current"), centerAlign);
			xlsx.write(rowcount + 5, 2, QString("%1").arg(data.PSD1_Current_Measured, 0, 'f', 3), centerAlign);
			xlsx.write(rowcount + 6, 1, tr("End of condition"), centerAlign);
			if (bitset1_t.test(1))
			{
				xlsx.write(rowcount + 6, 2, tr("Monomer undervoltage"), centerAlign);
			}
			else
			{
				xlsx.write(rowcount + 6, 2, tr("Battery pack undervoltage"), centerAlign);
			}
			xlsx.save();
			emit painter_data_for_CD_test(type, m_execl_path, m_time_vector, m_voltage_CD, m_chargeCurrent_CD, m_dischargeCurrent_CD, m_Soc_vector, m_Maxtemperature_CD);


			if (type == 1)
			{
				emit tested_result_bool(tr("Standard discharge test"), true);
			}
			else
			{
				emit tested_result_bool(tr("Fast discharge test"), true);
			}

			emit start_next_multiple(); //进行子项
			is_first_coming = true;
			m_time_vector.clear();
			m_voltage_CD.clear();
			m_chargeCurrent_CD.clear();
			m_dischargeCurrent_CD.clear();
			m_Soc_vector.clear();
			m_Maxtemperature_CD.clear();
		}
		else
		{
			QDateTime time = QDateTime::currentDateTime();
			m_time_vector.append(time.toMSecsSinceEpoch()*0.001);
			m_voltage_CD.append(data.voltage);
			m_chargeCurrent_CD.append(data.charge_current);
			m_dischargeCurrent_CD.append(data.discharge_current);
			m_Maxtemperature_CD.append(data.max_temperature);
			m_Soc_vector.append(data.Soc);
		}
	}

}

void Data_WriteTOExecl::deal_for_SOCTest_discharge(Data_Zhili & data)
{
	if (is_first_coming)
	{
		is_first_coming = false;
		Document xlsx(m_execl_path);
		//设置表头样式
		if (!xlsx.selectSheet("SOC Test"))
		{
			xlsx.addSheet("SOC Test");
		}
		Format centerAlign;
		centerAlign.setHorizontalAlignment(QXlsx::Format::AlignHCenter); //设置横向、纵向居中
		centerAlign.setVerticalAlignment(QXlsx::Format::AlignVCenter);   //
		centerAlign.setTopBorderStyle(QXlsx::Format::BorderThin);//设置上下左右的线类型
		centerAlign.setBottomBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setLeftBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setRightBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setFontBold(true);          //字体加粗
		centerAlign.setFontColor(Qt::black);     //设置字体颜色
		centerAlign.setFontSize(12);            //设置字体大小
		int row_count = xlsx.dimension().rowCount();
		xlsx.mergeCells(CellRange(row_count + 1, 1, row_count + 1, 3), centerAlign); //合并单元表格
		xlsx.write("A" + QString::number(row_count + 1), tr("SOC test of discharge"));
		centerAlign.setFontSize(10);            //设置字体大小
		xlsx.write(row_count + 2, 1, tr("decrease capacity Ah"), centerAlign);
		xlsx.write(row_count + 2, 2, tr("Current Soc %"), centerAlign);
		xlsx.write(row_count + 2, 3, tr("Status"), centerAlign);
		centerAlign.setFontBold(false);          //字体加粗		
		xlsx.write(row_count + 3, 1, 0, centerAlign);
		xlsx.write(row_count + 3, 2, data.Soc, centerAlign);  //第一次初始值
		if (data.Soc < 100)
		{
			centerAlign.setFontColor(Qt::red);     //设置字体颜色
			xlsx.write(row_count + 3, 3, tr("Fail"), centerAlign);
		}
		else
		{
			xlsx.write(row_count + 3, 3, " ", centerAlign);
		}	
		xlsx.save();

		start_voltage = data.voltage;
		start_temperature = data.max_temperature;
	}

	std::bitset<16> bitset1_t(data.vstate_list);
	if (bitset1_t.test(1) || bitset1_t.test(3))
	{
		SOC_Test_Discharge = false;
		Document xlsx(m_execl_path);
		//设置表头样式
		if (!xlsx.selectSheet("SOC Test"))
		{
			xlsx.addSheet("SOC Test");
		}
		Format centerAlign;
		centerAlign.setHorizontalAlignment(QXlsx::Format::AlignHCenter); //设置横向、纵向居中
		centerAlign.setVerticalAlignment(QXlsx::Format::AlignVCenter);   //
		centerAlign.setTopBorderStyle(QXlsx::Format::BorderThin);//设置上下左右的线类型
		centerAlign.setBottomBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setLeftBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setRightBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setFontBold(false);          //字体加粗
		centerAlign.setFontColor(Qt::black);     //设置字体颜色
		centerAlign.setFontSize(10);
		int row_count = xlsx.dimension().rowCount();
		float final_change_capicity = 0;
		for (int i = 0; i < change_capacity_vector.size(); i++)
		{
			final_change_capicity += change_capacity_vector.at(i);
		}
		xlsx.write(row_count + 1, 1, QString("%1").arg(final_change_capicity, 0, 'f', 2), centerAlign);
		xlsx.write(row_count + 1, 2, QString("%1").arg(data.Soc), centerAlign);

		xlsx.write(row_count + 2, 1, tr("Soc  test Actual discharge capacity"), centerAlign);
		xlsx.write(row_count + 2, 2, QString("%1 Ah").arg(capacity_addOrdecrease, 0, 'f', 2), centerAlign);

		xlsx.write(row_count + 3, 1, tr("Start voltage"), centerAlign);
		xlsx.write(row_count + 3, 2, QString("%1 V").arg(start_voltage, 0, 'f', 3), centerAlign);
		
		xlsx.write(row_count + 4, 1, tr("End voltage"), centerAlign);
		xlsx.write(row_count + 4, 2, QString("%1 V").arg(data.voltage, 0, 'f', 3), centerAlign);

		quint16 cc[] = { 0xfe12, 0x0043, 0 };
		xlsx.write(row_count + 5, 1, tr("Start max temperature"), centerAlign);
		xlsx.write(row_count + 5, 2, QString("%1 ").arg(start_temperature) + QString::fromUtf16(cc), centerAlign);

		xlsx.write(row_count + 6, 1, tr("End max temperature"), centerAlign);
		xlsx.write(row_count + 6, 2, QString("%1 ").arg(data.max_temperature) + QString::fromUtf16(cc), centerAlign);

		xlsx.write(row_count + 7, 1, tr("End current"), centerAlign);
		xlsx.write(row_count + 7, 2, QString("%1 A").arg(data.PSD1_Current_Measured, 0, 'f', 3), centerAlign);

		xlsx.write(row_count + 8, 1, tr("End of condition"), centerAlign);
		if (bitset1_t.test(1))
		{
			xlsx.write(row_count + 8, 2, tr("Monomer undervoltage"), centerAlign);
		}
		else if(bitset1_t.test(3))
		{
			xlsx.write(row_count + 8, 2, tr("Battery pack undervoltage"), centerAlign);
		}
		xlsx.save();
		//保存图像
		emit painter_data_for_SOC_test(_discharge_, m_execl_path, m_time_vector, m_Soc_vector);

		gap_num = 1;
		is_first_coming = true;
		soc_test_gap = ((capacity_addOrdecrease / 10) * soc_percentage * 100);
		capacity_addOrdecrease = 0;
		change_capacity_vector.clear();
		m_time_vector.clear();
		m_Soc_vector.clear();
		emit tested_result_bool(tr("SOC test of discharge"), true);
		emit start_next_multiple(); //进行子项
	}
	else
	{
		QDateTime time = QDateTime::currentDateTime();
		m_time_vector.append(time.toMSecsSinceEpoch()*0.001);
		m_Soc_vector.append(data.Soc);

		capacity_addOrdecrease += data.PSD1_Current_Measured / 3600;
		change_capacity_vector.append(data.PSD1_Current_Measured / 3600);
		if( ((int)(capacity_addOrdecrease *100)) *10 >= soc_test_gap * gap_num)
		{
			gap_num++;
			change_capacity_vector.clear();		
			Document xlsx(m_execl_path);
			//设置表头样式
			if (!xlsx.selectSheet("SOC Test"))
			{
				xlsx.addSheet("SOC Test");
			}
			Format centerAlign;
			centerAlign.setHorizontalAlignment(QXlsx::Format::AlignHCenter); //设置横向、纵向居中
			centerAlign.setVerticalAlignment(QXlsx::Format::AlignVCenter);   //
			centerAlign.setTopBorderStyle(QXlsx::Format::BorderThin);//设置上下左右的线类型
			centerAlign.setBottomBorderStyle(QXlsx::Format::BorderThin);
			centerAlign.setLeftBorderStyle(QXlsx::Format::BorderThin);
			centerAlign.setRightBorderStyle(QXlsx::Format::BorderThin);
			centerAlign.setFontBold(false);          //字体加粗
			centerAlign.setFontColor(Qt::black);     //设置字体颜色
			centerAlign.setFontSize(10);
			int row_count = xlsx.dimension().rowCount();
			xlsx.write(row_count + 1, 1, QString("%1").arg((float)soc_test_gap/1000, 0, 'f', 3), centerAlign);
			xlsx.write(row_count + 1, 2, QString("%1").arg(data.Soc), centerAlign);
			xlsx.write(row_count + 1, 3, "", centerAlign);
			xlsx.save();
		}
	}
}

void Data_WriteTOExecl::deal_for_SOCTest_charge(Data_Zhili & data)
{
	if (is_first_coming)
	{
		is_first_coming = false;
		Document xlsx(m_execl_path);
		//设置表头样式
		if (!xlsx.selectSheet("SOC Test"))
		{
			xlsx.addSheet("SOC Test");
		}
		Format centerAlign;
		centerAlign.setHorizontalAlignment(QXlsx::Format::AlignHCenter); //设置横向、纵向居中
		centerAlign.setVerticalAlignment(QXlsx::Format::AlignVCenter);   //

		centerAlign.setTopBorderStyle(QXlsx::Format::BorderThin);//设置上下左右的线类型
		centerAlign.setBottomBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setLeftBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setRightBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setFontSize(10);            //设置字体大小
		centerAlign.setFontBold(true);          //字体加粗
		int row_count = xlsx.dimension().rowCount();
		xlsx.mergeCells(CellRange(row_count + 2, 1, row_count + 2, 2), centerAlign); //合并单元表格
		xlsx.write("A" + QString::number(row_count + 2), tr("SOC test of charge"));
		xlsx.write(row_count + 3, 1, tr("increase capacity Ah"), centerAlign);
		xlsx.write(row_count + 3, 2, tr("Current Soc %"), centerAlign);
		xlsx.write(row_count + 3, 3, tr("Status"), centerAlign);
		centerAlign.setFontBold(false);          //字体加粗
		xlsx.write(row_count + 4, 1, 0, centerAlign);
		xlsx.write(row_count + 4, 2, data.Soc, centerAlign);  //第一次初始值
		if (data.Soc > 0)
		{
			centerAlign.setFontColor(Qt::red);     //设置字体颜色
			xlsx.write(row_count + 4, 3, "Fail", centerAlign);
		}
		xlsx.save();

		start_voltage = data.voltage;
		start_temperature = data.max_temperature;
	}

	std::bitset<16> bitset1_t(data.vstate_list);
	if (bitset1_t.test(0) || bitset1_t.test(2))
	{
		SOC_Test_Charge = false;
		Document xlsx(m_execl_path);
		//设置表头样式
		if (!xlsx.selectSheet("SOC Test"))
		{
			xlsx.addSheet("SOC Test");
		}
		Format centerAlign;
		centerAlign.setHorizontalAlignment(QXlsx::Format::AlignHCenter); //设置横向、纵向居中
		centerAlign.setVerticalAlignment(QXlsx::Format::AlignVCenter);   //
		centerAlign.setTopBorderStyle(QXlsx::Format::BorderThin);//设置上下左右的线类型
		centerAlign.setBottomBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setLeftBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setRightBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setFontBold(false);          //字体加粗
		centerAlign.setFontColor(Qt::black);     //设置字体颜色
		centerAlign.setFontSize(10);
		float final_change_capicity = 0;
		for (int i = 0; i < change_capacity_vector.size(); i++)
		{
			final_change_capicity += change_capacity_vector.at(i);
		}
		int row_count = xlsx.dimension().rowCount();
		xlsx.write(row_count + 1, 1, QString("%1").arg(final_change_capicity, 0, 'f', 3), centerAlign);
		xlsx.write(row_count + 1, 2, QString("%1").arg(data.Soc), centerAlign);

		xlsx.write(row_count + 2, 1, tr("Soc test Actual charge capacity"), centerAlign);
		xlsx.write(row_count + 2, 2, QString("%1 Ah").arg(capacity_addOrdecrease, 0, 'f', 3), centerAlign);

		xlsx.write(row_count + 3, 1, tr("Start voltage"), centerAlign);
		xlsx.write(row_count + 3, 2, QString("%1 V").arg(start_voltage, 0, 'f', 3), centerAlign);

		xlsx.write(row_count + 4, 1, tr("End voltage"), centerAlign);
		xlsx.write(row_count + 4, 2, QString("%1 V").arg(data.voltage, 0, 'f', 3), centerAlign);

		quint16 cc[] = { 0xfe12, 0x0043, 0 };
		xlsx.write(row_count + 5, 1, tr("Start max temperature"), centerAlign);
		xlsx.write(row_count + 5, 2, QString("%1 ").arg(start_temperature) + QString::fromUtf16(cc), centerAlign);

		xlsx.write(row_count + 6, 1, tr("End max temperature"), centerAlign);
		xlsx.write(row_count + 6, 2, QString("%1 ").arg(data.max_temperature) + QString::fromUtf16(cc), centerAlign);

		xlsx.write(row_count + 7, 1, tr("End current"), centerAlign);
		xlsx.write(row_count + 7, 2, QString("%1 A").arg(data.Charging_Current_Measured, 0, 'f', 3), centerAlign);

		xlsx.write(row_count + 8, 1, tr("End of condition"), centerAlign);
		if (bitset1_t.test(0))
		{
			xlsx.write(row_count + 8, 2, tr("Monomer overvoltage"), centerAlign);
		}
		else if (bitset1_t.test(2))
		{
			xlsx.write(row_count + 8, 2, tr("Battery pack overvoltage"), centerAlign);
		}

		//总测试结论
		if (!xlsx.selectSheet("Battery Report"))
		{
			xlsx.addSheet("Battery Report");
		}
		int row_count_final = xlsx.dimension().rowCount();
		if (capacity_err_num == 0)
		{
			centerAlign.setFontColor(Qt::black);  //设置字体颜色
			xlsx.write(row_count_final + 1, 1, tr("Capacity Test"), centerAlign);
			centerAlign.setFontColor(Qt::green);  //设置字体颜色
			xlsx.write(row_count_final + 1, 2, "Pass", centerAlign);
		}
		else
		{
			centerAlign.setFontColor(Qt::black);  //设置字体颜色
			xlsx.write(row_count_final + 1, 1, tr("Capacity Test"), centerAlign);
			centerAlign.setFontColor(Qt::red);  //设置字体颜色
			xlsx.write(row_count_final + 1, 2, "False", centerAlign);
		}

		xlsx.save();
		//保存图像
		emit painter_data_for_SOC_test(_charge_, m_execl_path, m_time_vector, m_Soc_vector);

		gap_num = 1;
		is_first_coming = true;
		m_time_vector.clear();
		m_Soc_vector.clear();
		change_capacity_vector.clear();
		capacity_addOrdecrease = 0;
		emit tested_result_bool(tr("SOC test of charge"), true);
		emit tested_end(true);
		emit start_next_Alone(); //进行下一个父项
	}
	else
	{
		QDateTime time = QDateTime::currentDateTime();
		m_time_vector.append(time.toMSecsSinceEpoch()*0.001);
		m_Soc_vector.append(data.Soc);

		capacity_addOrdecrease += data.Charging_Current_Measured / 3600;
		change_capacity_vector.append(data.Charging_Current_Measured /3600);

		if (((int)(capacity_addOrdecrease * 100)) * 10 >= soc_test_gap * gap_num)
		{
			gap_num++;
			change_capacity_vector.clear();
			Document xlsx(m_execl_path);
			//设置表头样式
			if (!xlsx.selectSheet("SOC Test"))
			{
				xlsx.addSheet("SOC Test");
			}
			Format centerAlign;
			centerAlign.setHorizontalAlignment(QXlsx::Format::AlignHCenter); //设置横向、纵向居中
			centerAlign.setVerticalAlignment(QXlsx::Format::AlignVCenter);   //
			centerAlign.setTopBorderStyle(QXlsx::Format::BorderThin);//设置上下左右的线类型
			centerAlign.setBottomBorderStyle(QXlsx::Format::BorderThin);
			centerAlign.setLeftBorderStyle(QXlsx::Format::BorderThin);
			centerAlign.setRightBorderStyle(QXlsx::Format::BorderThin);
			centerAlign.setFontBold(false);          //字体加粗
			centerAlign.setFontColor(Qt::black);     //设置字体颜色
			centerAlign.setFontSize(10);
			int row_count = xlsx.dimension().rowCount();
			xlsx.write(row_count + 1, 1, QString("%1").arg((float)soc_test_gap / 1000, 0, 'f', 3), centerAlign);
			xlsx.write(row_count + 1, 2, QString("%1").arg(data.Soc), centerAlign);
			xlsx.save();
		}
	}
}

void Data_WriteTOExecl::deal_current_accuracy(Data_Zhili & data, int cOrd)
{
	if (current_accuracy_charge_num == 0)
	{
		Document xlsx(m_execl_path);
		//设置表头样式
		if (!xlsx.selectSheet("Current_Accuracy Test"))
		{
			xlsx.addSheet("Current_Accuracy Test");
		}
		Format centerAlign;
		centerAlign.setHorizontalAlignment(QXlsx::Format::AlignHCenter); //设置横向、纵向居中
		centerAlign.setVerticalAlignment(QXlsx::Format::AlignVCenter);   //
		centerAlign.setTopBorderStyle(QXlsx::Format::BorderThin);//设置上下左右的线类型
		centerAlign.setBottomBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setLeftBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setRightBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setFontBold(true);          //字体加粗
		centerAlign.setFontColor(Qt::black);     //设置字体颜色
		centerAlign.setFontSize(12);            //设置字体大小
		int row_count = xlsx.dimension().rowCount();
		xlsx.write(row_count + 1, 1, tr("Charge current accuracy"),centerAlign);
		xlsx.write(row_count + 1, 2, tr("BMS current"), centerAlign);
		xlsx.write(row_count + 1, 3, tr("Real current"), centerAlign);
		xlsx.write(row_count + 1, 4, tr("Different value"), centerAlign);
		xlsx.write(row_count + 1, 5, tr("Result"), centerAlign);
		centerAlign.setFontBold(false);          //字体加粗
		centerAlign.setFontColor(Qt::black);     //设置字体颜色
		centerAlign.setFontSize(10);            //设置字体大小
		xlsx.write(row_count + 2, 1, QString("%1").arg((float)test_now_current / 10, 0, 'f', 2), centerAlign);
		xlsx.write(row_count + 2, 2, QString("%1").arg(data.charge_current, 0, 'f', 2), centerAlign);
		xlsx.write(row_count + 2, 3, QString("%1").arg(data.Charging_Current_Measured, 0, 'f', 2), centerAlign);
		if (data.charge_current > data.Charging_Current_Measured)
		{
			xlsx.write(row_count + 2, 4, QString("%1").arg((data.charge_current - data.Charging_Current_Measured), 0, 'f', 2), centerAlign);
		}
		else
		{
			xlsx.write(row_count + 2, 4, QString("%1").arg((data.Charging_Current_Measured - data.charge_current), 0, 'f', 2), centerAlign);
		}
		
		if ((int)fabs((data.charge_current - data.Charging_Current_Measured)*1000) < standard_err_current)
		{
			centerAlign.setFontColor(Qt::green);     //设置字体颜色
			xlsx.write(row_count + 2, 5, tr("Pass"), centerAlign);
		}
		else
		{
			centerAlign.setFontColor(Qt::red);     //设置字体颜色
			xlsx.write(row_count + 2, 5, tr("false"), centerAlign);
		}		
		xlsx.save();

		emit start_next_multiple();
	}
	else if (current_accuracy_discharge_num == 0)
	{
		Document xlsx(m_execl_path);
		//设置表头样式
		if (!xlsx.selectSheet("Current_Accuracy Test"))
		{
			xlsx.addSheet("Current_Accuracy Test");
		}
		Format centerAlign;
		centerAlign.setHorizontalAlignment(QXlsx::Format::AlignHCenter); //设置横向、纵向居中
		centerAlign.setVerticalAlignment(QXlsx::Format::AlignVCenter);   //
		centerAlign.setTopBorderStyle(QXlsx::Format::BorderThin);//设置上下左右的线类型
		centerAlign.setBottomBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setLeftBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setRightBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setFontBold(true);          //字体加粗
		centerAlign.setFontColor(Qt::black);     //设置字体颜色
		centerAlign.setFontSize(12);            //设置字体大小

		int row_count = xlsx.dimension().rowCount();
		xlsx.write(row_count + 1, 1, tr("Discharge current accuracy"), centerAlign);
		xlsx.write(row_count + 1, 2, tr("BMS current"), centerAlign);
		xlsx.write(row_count + 1, 3, tr("Real current"), centerAlign);
		xlsx.write(row_count + 1, 4, tr("Different value"), centerAlign);
		xlsx.write(row_count + 1, 5, tr("Result"), centerAlign);

		centerAlign.setFontBold(false);          //字体加粗
		centerAlign.setFontSize(10);            //设置字体大小
		xlsx.write(row_count + 2, 1, QString("%1").arg((float)test_now_current / 10, 0, 'f', 2), centerAlign);
		xlsx.write(row_count + 2, 2, QString("%1").arg(data.discharge_current, 0, 'f', 2), centerAlign);
		xlsx.write(row_count + 2, 3, QString("%1").arg(data.PSD1_Current_Measured, 0, 'f', 2), centerAlign);
		if (data.discharge_current > data.PSD1_Current_Measured)
		{
			xlsx.write(row_count + 2, 4, QString("%1").arg((data.discharge_current - data.PSD1_Current_Measured), 0, 'f', 2), centerAlign);
		}
		else
		{
			xlsx.write(row_count + 2, 4, QString("%1").arg((data.PSD1_Current_Measured - data.discharge_current), 0, 'f', 2), centerAlign);
		}

		if ((int)fabs((data.discharge_current - data.PSD1_Current_Measured) * 1000) < standard_err_current)
		{
			centerAlign.setFontColor(Qt::green);     //设置字体颜色
			xlsx.write(row_count + 2, 5, tr("Pass"), centerAlign);
		}
		else
		{
			centerAlign.setFontColor(Qt::red);     //设置字体颜色
			xlsx.write(row_count + 2, 5, tr("false"), centerAlign);
		}
		xlsx.save();
		emit start_next_multiple();
	}
	else
	{
		Document xlsx(m_execl_path);
		//设置表头样式
		if (!xlsx.selectSheet("Current_Accuracy Test"))
		{
			xlsx.addSheet("Current_Accuracy Test");
		}
		Format centerAlign;
		centerAlign.setHorizontalAlignment(QXlsx::Format::AlignHCenter); //设置横向、纵向居中
		centerAlign.setVerticalAlignment(QXlsx::Format::AlignVCenter);   //
		centerAlign.setTopBorderStyle(QXlsx::Format::BorderThin);//设置上下左右的线类型
		centerAlign.setBottomBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setLeftBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setRightBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setFontBold(false);          //字体加粗
		centerAlign.setFontColor(Qt::black);     //设置字体颜色
		centerAlign.setFontSize(10);            //设置字体大小

		int row_count = xlsx.dimension().rowCount();

		xlsx.write(row_count + 1, 1, QString("%1").arg((float)test_now_current / 10, 0, 'f', 2), centerAlign);
		if (cOrd == 0)
		{
			xlsx.write(row_count + 1, 2, QString("%1").arg(data.charge_current, 0, 'f', 2), centerAlign);
			xlsx.write(row_count + 1, 3, QString("%1").arg(data.Charging_Current_Measured, 0, 'f', 2), centerAlign);
			if (data.charge_current > data.Charging_Current_Measured)
			{
				xlsx.write(row_count + 1, 4, QString("%1").arg((data.charge_current - data.Charging_Current_Measured), 0, 'f', 2), centerAlign);
			}
			else
			{
				xlsx.write(row_count + 1, 4, QString("%1").arg((data.Charging_Current_Measured - data.charge_current), 0, 'f', 2), centerAlign);
			}

			if ((int)fabs((data.charge_current - data.Charging_Current_Measured) * 1000) < standard_err_current)
			{
				centerAlign.setFontColor(Qt::green);     //设置字体颜色
				xlsx.write(row_count + 1, 5, tr("Pass"), centerAlign);
			}
			else
			{
				centerAlign.setFontColor(Qt::red);     //设置字体颜色
				xlsx.write(row_count + 1, 5, tr("false"), centerAlign);
			}
		}
		else
		{
			xlsx.write(row_count + 1, 2, QString("%1").arg(data.discharge_current, 0, 'f', 2), centerAlign);
			xlsx.write(row_count + 1, 3, QString("%1").arg(data.PSD1_Current_Measured, 0, 'f', 2), centerAlign);
			if (data.discharge_current > data.PSD1_Current_Measured)
			{
				xlsx.write(row_count + 1, 4, QString("%1").arg((data.discharge_current - data.PSD1_Current_Measured), 0, 'f', 2), centerAlign);
			}
			else
			{
				xlsx.write(row_count + 1, 4, QString("%1").arg((data.PSD1_Current_Measured - data.discharge_current), 0, 'f', 2), centerAlign);
			}

			if ((int)fabs((data.discharge_current - data.PSD1_Current_Measured) * 1000) < standard_err_current)
			{
				centerAlign.setFontColor(Qt::green);     //设置字体颜色
				xlsx.write(row_count + 1, 5, tr("Pass"), centerAlign);
			}
			else
			{
				centerAlign.setFontColor(Qt::red);     //设置字体颜色
				xlsx.write(row_count + 1, 5, tr("false"), centerAlign);
			}
		}
		if (current_accuracy_discharge_num != -1 && test_now_current == 10)
		{
			//总测试结论
			if (!xlsx.selectSheet("Battery Report"))
			{
				xlsx.addSheet("Battery Report");
			}
			int row_count_final = xlsx.dimension().rowCount();
			centerAlign.setFontColor(Qt::black);  //设置字体颜色
			xlsx.write(row_count_final + 1, 1, tr("Voltage Accuracy Test"), centerAlign);
			centerAlign.setFontColor(Qt::green);  //设置字体颜色
			xlsx.write(row_count_final + 1, 2, "Pass", centerAlign);

			test_now_current = 0;
			current_accuracy_discharge_num = -1;
			current_accuracy_charge_num = -1;
			emit tested_end(true);
			emit start_next_Alone();
		}
		else
		{
			emit start_next_multiple();
		}

		xlsx.save();
	}

}

void Data_WriteTOExecl::deal_voltage_accuracy(Data_Zhili & data, int cOrd)
{
	if (voltage_accuracy_charge_num == 0 || voltage_accuracy_discharge_num == 0)
	{
		Document xlsx(m_execl_path);
		//设置表头样式
		if (!xlsx.selectSheet("Voltage_Accuracy Test"))
		{
			xlsx.addSheet("Voltage_Accuracy Test");
		}
		Format centerAlign;
		centerAlign.setHorizontalAlignment(QXlsx::Format::AlignHCenter); //设置横向、纵向居中
		centerAlign.setVerticalAlignment(QXlsx::Format::AlignVCenter);   //
		centerAlign.setTopBorderStyle(QXlsx::Format::BorderThin);//设置上下左右的线类型
		centerAlign.setBottomBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setLeftBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setRightBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setFontBold(true);          //字体加粗
		centerAlign.setFontColor(Qt::black);     //设置字体颜色
		centerAlign.setFontSize(12);            //设置字体大小
		int row_count = xlsx.dimension().rowCount();
		if (cOrd == 0)
		{
			xlsx.write(row_count + 1, 1, tr("Charge voltage accuracy"), centerAlign);
		}
		else
		{
			xlsx.write(row_count + 1, 1, tr("Discharge voltage accuracy"), centerAlign);
		}
		
		xlsx.write(row_count + 1, 2, tr("BMS voltage"), centerAlign);
		xlsx.write(row_count + 1, 3, tr("Real voltage"), centerAlign);
		xlsx.write(row_count + 1, 4, tr("Different value"), centerAlign);
		xlsx.write(row_count + 1, 5, tr("Result"), centerAlign);
		centerAlign.setFontBold(false);          //字体加粗
		centerAlign.setFontColor(Qt::black);     //设置字体颜色
		centerAlign.setFontSize(10);            //设置字体大小
		xlsx.write(row_count + 2, 1, QString("%1").arg(test_now_soc), centerAlign);
		xlsx.write(row_count + 2, 2, QString("%1").arg(data.voltage, 0, 'f', 2), centerAlign);
		xlsx.write(row_count + 2, 3, QString("%1").arg(data.Battery_Voltage_Measured, 0, 'f', 2), centerAlign);
		if (data.voltage > data.Battery_Voltage_Measured)
		{
			xlsx.write(row_count + 2, 4, QString("%1").arg((data.voltage - data.Battery_Voltage_Measured), 0, 'f', 2), centerAlign);
		}
		else
		{
			xlsx.write(row_count + 2, 4, QString("%1").arg((data.Battery_Voltage_Measured - data.voltage), 0, 'f', 2), centerAlign);
		}

		if ((int)fabs((data.voltage - data.Battery_Voltage_Measured) * 1000) < standard_err_voltage)
		{
			centerAlign.setFontColor(Qt::green);     //设置字体颜色
			xlsx.write(row_count + 2, 5, tr("Pass"), centerAlign);
		}
		else
		{
			centerAlign.setFontColor(Qt::red);     //设置字体颜色
			xlsx.write(row_count + 2, 5, tr("false"), centerAlign);
		}
		xlsx.save();
		emit start_next_multiple();
	}
	
	else
	{
		Document xlsx(m_execl_path);
		if (!xlsx.selectSheet("Voltage_Accuracy Test"))
		{
			xlsx.addSheet("Voltage_Accuracy Test");
		}
		Format centerAlign;
		centerAlign.setHorizontalAlignment(QXlsx::Format::AlignHCenter); //设置横向、纵向居中
		centerAlign.setVerticalAlignment(QXlsx::Format::AlignVCenter);   //
		centerAlign.setTopBorderStyle(QXlsx::Format::BorderThin);//设置上下左右的线类型
		centerAlign.setBottomBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setLeftBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setRightBorderStyle(QXlsx::Format::BorderThin);
		centerAlign.setFontBold(false);          //字体加粗
		centerAlign.setFontColor(Qt::black);     //设置字体颜色
		centerAlign.setFontSize(10);            //设置字体大小

		int row_count = xlsx.dimension().rowCount();

		xlsx.write(row_count + 1, 1, QString("%1").arg(test_now_soc), centerAlign);
		xlsx.write(row_count + 1, 2, QString("%1").arg(data.voltage, 0, 'f', 2), centerAlign);
		xlsx.write(row_count + 1, 3, QString("%1").arg(data.Battery_Voltage_Measured, 0, 'f', 2), centerAlign);
		if (data.voltage > data.Battery_Voltage_Measured)
		{
			xlsx.write(row_count + 1, 4, QString("%1").arg((data.voltage - data.Battery_Voltage_Measured), 0, 'f', 2), centerAlign);
		}
		else
		{
			xlsx.write(row_count + 1, 4, QString("%1").arg((data.Battery_Voltage_Measured - data.voltage), 0, 'f', 2), centerAlign);
		}

		if ((int)fabs((data.voltage - data.Battery_Voltage_Measured) * 1000) < standard_err_current)
		{
			centerAlign.setFontColor(Qt::green);     //设置字体颜色
			xlsx.write(row_count + 1, 5, tr("Pass"), centerAlign);
		}
		else
		{
			centerAlign.setFontColor(Qt::red);     //设置字体颜色
			xlsx.write(row_count + 1, 5, tr("false"), centerAlign);
		}
		xlsx.save();

		if (voltage_accuracy_discharge_num != -1 && voltage_accuracy_charge_num !=-1 && test_now_soc == 0)
		{
			//总测试结论
			if (!xlsx.selectSheet("Battery Report"))
			{
				xlsx.addSheet("Battery Report");
			}
			int row_count_final = xlsx.dimension().rowCount();
			centerAlign.setFontColor(Qt::black);  //设置字体颜色
			xlsx.write(row_count_final + 1, 1, tr("Voltage Accuracy Test"), centerAlign);
			centerAlign.setFontColor(Qt::green);  //设置字体颜色
			xlsx.write(row_count_final + 1, 2, "Pass", centerAlign);

			//维护数据复位
			test_now_soc = 0;
			voltage_accuracy_discharge_num = -1;
			voltage_accuracy_charge_num = -1;
			emit tested_end(true);
			emit start_next_Alone();
		}
		else
		{
			emit start_next_multiple();
		}
	}
}
