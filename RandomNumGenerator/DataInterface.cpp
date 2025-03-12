#include "pch.h"
#include "DataInterface.h"

DataInterface::DataInterface(){}

DataInterface::~DataInterface(){}

void DataInterface::SetFilePath(CString FilePath)
{
	this->FilePath = FilePath;
}

