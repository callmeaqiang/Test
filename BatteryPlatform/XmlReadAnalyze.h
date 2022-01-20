#pragma once

#include <QObject>
#include <QXmlStreamReader>


#include "CustomDataType.h"

class XmlReadAnalyze
{
public:
	XmlReadAnalyze();
	~XmlReadAnalyze();

	//读取节点数据
	bool readFile(const QString &fileName);
	void readDeviceDescriptionElement();
	void readTypesElement();

	void readBitfieldTypeElement();
	void readComponentElement();
	void readDefaultElement();
	void readVisibleNameElement();
	void readDescriptionElement();

	void readArrayTypeElement();
	void readerFirstDimension();
	void readerLowerBorder();
	void readerUpperBorder();


private:
	//xml路径
	QString filePath;
	QXmlStreamReader reader;	
};

