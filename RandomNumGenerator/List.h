#pragma once
class List
{
public:
	List();
	~List();

	struct node
	{
		int id; // 编号

		int num; // 学号
		string name; // 姓名
		int value; // 权值

		bool isHead;
		bool isTail;

		node* prev;
		node* next;
	};

	void add_tail(int num, std::string name, int value);
	void del(int num);
	node* query(int num); // 读取链表第 num 项

	int len; // 链表长度

private:
	int cnt; // 节点编号计数 下一个节点编号=cnt
	node* head;
};
