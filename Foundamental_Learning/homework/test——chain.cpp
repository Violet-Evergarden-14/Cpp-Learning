#include <iostream>
using namespace std;

class Node
{
public:
	int x;
	Node *next;
};

Node* create_node(int number[])
{
	Node* list = new Node;

	Node* p = new Node;
	p = list;
	p->x = number[0];
	
	for (int i = 1; i < 11; i++)
	{
		Node* temp = new Node;
		p->next = temp;
		temp->x = number[i];
		p = temp;
	}
	p->next = nullptr;
	return list;
}

Node* head_add_node(Node* list, int m)
{
	Node* head = new Node;
	head->next = list;
	head->x = m;
	return head;	
}

void show_all_value(Node* list)
{
	Node* p = list;
	while (p->next != nullptr)
	{
		cout << p->x << endl;
		p = p->next;
	}
}

void delete_list(Node* list)
{
	Node* p = list;
	
	while (p != nullptr)
	{
		Node* temp = p->next;
		delete p;
		p = temp;
	}

	list = nullptr;
}

void insert_node(Node* list, int m, int num)
{
	Node* p = list;
	Node* temp;
	for (int i = 0; i < m - 1; i++)
	{
		temp = p->next;
		p = temp;
	}
	
	Node* add = new Node;
	add->x = num;
	add->next = p->next;
	p->next = add;
}

void delete_node(Node* list, int m)
{
	Node* p = list;
	Node* temp;
	for (int i = 0; i < m - 2; i++)
	{
		temp = p->next;
		p = temp;
	}
	temp = p->next;   //在此之后，temp指向的地址不变
	p->next = temp->next;
	delete temp;
	temp = nullptr;   ///注意，要将temp转换为nullptr，不能有悬空指针
}

int main()
{
	int number[10];
	for (int i = 0; i < 10; i++)
	{
		number[i] = i;
	}

	Node* list =  create_node(number);
	insert_node(list, 1, 5);
	cout << list->x << " " << list->next->x << " " << list->next->next->x << " " << list->next->next->next->x << endl;;

	delete_node(list, 2);
	cout << list->x << " " << list->next->x << " " << list->next->next->x << " " << list->next->next->next->x;

	delete_list(list);
	
}