#include "pch.h"
#include "List.h"

List::List()
{
	len = 0;
	cnt = 1;
	head = nullptr;
}

List::~List()
{
	if (len == 0)
	{
		return;
	}

	node* p = head;
	node* q = nullptr;
	while(p->isTail == false)
	{
		q = p;
		p = p->next;
		delete q;
	}
	delete p;

	return;
}

void List::add_tail(int num, std::string name, int value)
{
	if (this->len == 0)
	{
		head = new node;
		head->id = this->cnt;
		this->cnt++;
		head->num = num;
		head->name = name;
		head->value = value;
		head->isHead = true;
		head->isTail = true;
		head->prev = nullptr;
		head->next = nullptr;

		this->len++;
		return;
	}

	node* p = head; // 尾节点
	while (p->isTail == false)
	{
		p = p->next;
	}
	node* q = new node; // 新节点

	q->id = this->cnt;
	cnt++;
	q->num = num;
	q->name = name;
	q->value = value;
	q->isHead = false;
	q->isTail = true;
	q->prev = p;
	q->next = nullptr;

	p->isTail = false;
	p->next = q;

	this->len++;
	return;
}

void List::del(int num)
{
	if (num == this->head->num)
	{
		node* p = this->head;
		this->head = p->next;
		delete p;
		head->isHead = true;
		this->len--;
		return;
	}

	node* p = head;
	while (p->num != num)
	{
		if (p->isTail == true)
		{
			return;
		}
		p = p->next;
	}

	if (p->isTail == true)
	{
		p->prev->isTail = true;
		p->prev->next = nullptr;
		delete p;
		this->len--;
		return;
	}

	p->prev->next = p->next;
	p->next->prev = p->prev;
	delete p;
	this->len--;
	return;
}

List::node* List::query(int num)
{
	node* p = head;
	while (p->num != num)
	{
		if (p->isTail == true)
		{
			return nullptr;
		}
		p = p->next;
	}
	return p;
}
