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

bool DataInterface::isOpen()
{
	return FilePath != "";
}

List::node* DataInterface::Generate() // 抽号/生成随机数 方法
{
	if (p_list->len == 0)
	{
		return nullptr;
	}

	int randNum;
	List::node* p_present = nullptr;
	while (true) // 为实现权值 每次抽中 id=i 时，若 randNum>value ，则再抽一次
	{
		randNum = getRandNum(1, p_list->len);
		p_present = p_list->query(randNum);
		if (getRandNum(1, 100) > p_present->value) // 权值判断
		{
			continue;
		}
		break;
	}
	return p_present;
}

void DataInterface::delItem(int num)
{
	p_list->del(num);
}


int DataInterface::getRandNum(int l, int r)
{
	return rand()%(r-l+1)+l;
}
