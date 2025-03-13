#pragma once

#include "List.h"
#include <fstream>

class DataInterface
{
public:
	DataInterface();
	~DataInterface();
	
	void SetFilePath(CString FilePath);
	void Open();

private:
	CString FilePath;
	List* p_list = nullptr;
	int length;
};

