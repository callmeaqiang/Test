#include "XmlThreadPool.h"

XmlThreadPool::XmlThreadPool(QString &path)
{
	this->filepath = path;
}

void XmlThreadPool::run()
{
	reader.readFile(this->filepath);
}
