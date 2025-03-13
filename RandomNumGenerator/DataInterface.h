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
	void Generate();

private:
	CString FilePath;
	List* p_list = nullptr;
	int length;

	int randSeed;
	int getRandNum(int l, int r); // 获取 [l, r] 范围内的随机数
};

