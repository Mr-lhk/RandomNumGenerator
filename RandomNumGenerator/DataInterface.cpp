#include "pch.h"
#include "DataInterface.h"
#include <fstream>
#include <time.h>
#include <cstdlib>

DataInterface::DataInterface() 
{
	length = 0;
	randSeed = (unsigned)time(NULL);
	srand(randSeed);
}

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

int DataInterface::getRandNum(int l, int r)
{
	return rand()%(r-l+1)+l;
}
