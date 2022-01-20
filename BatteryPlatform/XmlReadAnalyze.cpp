#include "XmlReadAnalyze.h"
#include <QFile>



XmlReadAnalyze::XmlReadAnalyze()
{
}


XmlReadAnalyze::~XmlReadAnalyze()
{
}
bool XmlReadAnalyze::readFile(const QString &fileName)
{
	QFile file(fileName);
	if (!file.open(QFile::ReadOnly | QFile::Text))
	{
		return false;
	}
	reader.setDevice(&file);
	reader.readNext();

	while (!reader.atEnd())
	{
		if (reader.isStartElement() && reader.name() == QString("DeviceDescription"))
		{
			readDeviceDescriptionElement();
		}
		else
		{
			reader.readNext();
		}
	}
	file.close();

	return true;
}

void XmlReadAnalyze::readDeviceDescriptionElement()
{
	reader.readNext();
	while (!reader.atEnd())
	{
		if (reader.isEndElement() && reader.name() == "DeviceDescription")
		{
			reader.readNext();
			break;
		}
		if (reader.isStartElement() && reader.name() == "Types")
		{
			readTypesElement();
		}
		else
		{
			reader.readNext();
		}
	}
}

void XmlReadAnalyze::readTypesElement()
{
	reader.readNext();
	while (!reader.atEnd())
	{
		if (reader.isEndElement() && reader.name() == "Types")
		{
			reader.readNext();
			break;
		}
		if (reader.isStartElement() && reader.name() == "ArrayType")
		{
			readArrayTypeElement();
		}
		else if (reader.isStartElement() && reader.name() == "BitfieldType")
		{
			readBitfieldTypeElement();
		}
		else
		{
			reader.readNext();
		}
	}
}

void XmlReadAnalyze::readBitfieldTypeElement()
{
	reader.readNext();
	while (!reader.atEnd())
	{
		if (reader.isEndElement() && reader.name() == "BitfieldType")
		{
			reader.readNext();
			break;
		}
		if (reader.isStartElement() && reader.name() == "Component")
		{
			readComponentElement();
		}
		else
		{
			reader.readNext();
		}
	}
}

void XmlReadAnalyze::readComponentElement( )
{
	reader.readNext();
	while (!reader.atEnd())
	{
		if (reader.isEndElement() && reader.name() == "Component")
		{
			reader.readNext();
			break;
		}
		if (reader.isStartElement() && reader.name() == "Default")
		{
			readDefaultElement();
		}
		else if (reader.isStartElement() && reader.name() == "VisibleName")
		{
			readVisibleNameElement();
		}
		else if (reader.isStartElement() && reader.name() == "Description")
		{
			readDescriptionElement();
		}
		else
		{
			reader.readNext();
		}
	}
}

void XmlReadAnalyze::readDefaultElement()
{
	QString val = reader.attributes().value("Default").toString();
	if (val == "FALSE")
	{
		
	}
	else
	{
		
	}
	if (reader.isEndElement())
	{
		reader.readNext();
	}
}

void XmlReadAnalyze::readVisibleNameElement()
{
	QString val = reader.attributes().value("VisibleName").toString();
	

	if (reader.isEndElement())
	{
		reader.readNext();
	}
}

void XmlReadAnalyze::readDescriptionElement()
{
	QString val = reader.attributes().value("Description").toString();
	if (reader.isEndElement())
	{
		reader.readNext();
	}
}

void XmlReadAnalyze::readArrayTypeElement()
{

	QString name = reader.attributes().value("name").toString();
	QString basetype = reader.attributes().value("basetype").toString();

	reader.readNext();
	while (!reader.atEnd())
	{
		if (reader.isEndElement() && reader.name() == "ArrayType")
		{
			reader.readNext();
			break;
		}
		if (reader.isStartElement() && reader.name() == "FirstDimension")
		{
			readerFirstDimension();
		}
		else
			reader.readNext();

	}

}

void XmlReadAnalyze::readerFirstDimension()
{
	reader.readNext();

	while (!reader.atEnd())
	{
		if (reader.isEndElement() && reader.name() == "FirstDimension")
		{
			reader.readNext();
			break;
		}
		if (reader.isStartElement() && reader.name() == "LowerBorder")
		{
			readerLowerBorder();
		}
		else if (reader.isStartElement() && reader.name() == "UpperBorder")
		{
			readerUpperBorder();
		}
		else
			reader.readNext();

	}

}

void XmlReadAnalyze::readerLowerBorder()
{
	int lower = reader.readElementText().toInt();

	if (reader.isEndElement())
	{
		reader.readNext();
	}
}

void XmlReadAnalyze::readerUpperBorder()
{
	int upper = reader.readElementText().toInt();

	if (reader.isEndElement())
	{
		reader.readNext();
	}
}

