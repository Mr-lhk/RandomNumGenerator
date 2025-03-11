#pragma once
class List
{
public:
	List();
	~List();

	struct node
	{
		int id; // ���

		int num; // ѧ��
		std::string name; // ����
		int value; // Ȩֵ

		bool isHead;
		bool isTail;

		node* prev;
		node* next;
	};

	void add_tail(int num, std::string name, int value);
	void del(int num);
	node* query(int num);

private:
	int len; // ������
	int cnt; // �ڵ��ż��� ��һ���ڵ���=cnt
	node* head;
};
