//#include "globaldata.h"
//#include <QDebug>
//
////��ʼ����̬��Ա����
//GlobalData *GlobalData::m_SingleInstance = new (std::nothrow) GlobalData;;
//
//GlobalData  *&GlobalData::GetInstance()
//{
//	return m_SingleInstance;
//}
//
//QEventLoop * GlobalData::get_eventloop()
//{
//	if (!el)
//	{
//		el = new QEventLoop();
//	}
//	return this->el;
//}
//
//GlobalData::GlobalData()
//{
//
//}
//
//GlobalData::~GlobalData()
//{
//	if (el)
//	{
//		qDebug() << "------------------------------------------->>>>>>>>>>>>>ffffff" << endl;
//		el->quit();
//		delete el;
//	}
//}
//
//void GlobalData::deleteInstance()
//{
//	if (m_SingleInstance)
//	{
//		delete m_SingleInstance;
//		m_SingleInstance = NULL;
//	}
//}
