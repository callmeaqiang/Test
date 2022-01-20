#pragma once

#include <QThreadPool>
#include <QObject>

#include "XmlReadAnalyze.h"

class XmlThreadPool :
	public QObject, public QRunnable
{
	Q_OBJECT
public:
	XmlThreadPool(QString &path);
	void run() override;

signals:
	
private:
	QString filepath;
	XmlReadAnalyze reader;

};

