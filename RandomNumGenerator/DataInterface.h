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
	bool isOpen();
	List::node* Generate();
	void delItem(int num);

private:
	CString FilePath = NULL;
	List* p_list = nullptr;
	int length;

	int randSeed;
	int getRandNum(int l, int r); // ��ȡ [l, r] ��Χ�ڵ������
};

