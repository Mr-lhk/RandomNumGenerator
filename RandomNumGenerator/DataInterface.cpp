#include "pch.h"
#include "DataInterface.h"
#include <fstream>

DataInterface::DataInterface() {}

DataInterface::~DataInterface() {}

void DataInterface::SetFilePath(CString FilePath)
{
	this->FilePath = FilePath;
}

void DataInterface::Open()
{
	// 清空上个链表
	if (p_list != nullptr)
	{
		delete p_list;
	}
	p_list = new List;

	// 文件输入流打开文件
	ifstream inputstream;
	inputstream.open(this->FilePath, ios::in);

	// 读取长度
	inputstream >> this->length;

	// 读取内容
	int num, value;
	string name;


	for (int i = 0; i < this->length; i++)
	{
		inputstream >> num >> name >> value;
		this->p_list->add_tail(num, name, value);
	}

	inputstream.close();
}

