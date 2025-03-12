#pragma once

#include "DataInterface.h"
#include <fstream>

class DataInterface
{
public:
	DataInterface();
	~DataInterface();
	
	void SetFilePath(CString FilePath);
	void Open(string FilePath);

private:
	CString FilePath;
};

