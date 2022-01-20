#include "batteryplatform.h"
#include <QtWidgets/QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTranslator translator ;
	translator.load(":/BatteryPlatform/batteryplatform_zh.qm");
	qApp->installTranslator(&translator);
	BatteryPlatform w;
	w.show();
	return a.exec();
}
