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
	// ����ϸ�����
	if (p_list != nullptr)
	{
		delete p_list;
	}
	p_list = new List;

	// �ļ����������ļ�
	ifstream inputstream;
	inputstream.open(this->FilePath, ios::in);

	// ��ȡ����
	inputstream >> this->length;

	// ��ȡ����
	int num, value;
	string name;


	for (int i = 0; i < this->length; i++)
	{
		inputstream >> num >> name >> value;
		this->p_list->add_tail(num, name, value);
	}

	inputstream.close();
}

