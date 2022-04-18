#include "MyList.h"

using namespace MyList;


My_List* MyList::init()
{
	My_List* list = new My_List;
	list->count = 0;
	list->phead = nullptr;
	list->stack = nullptr;

	return list;
}

Node* MyList::find(My_List* pHead, int find_data)
{
	Node* previous = pHead->phead;

	while (previous)
	{
		if (previous->next_ptr)
		{
			if (previous->next_ptr->data == find_data)
			{
				return previous;
			}

		}

		previous = previous->next_ptr;
	}

	return nullptr;
}

void MyList::push_front(My_List* pHead, int data)
{
	Node* Temp = pHead->phead;
	pHead->phead = new Node;
	pHead->phead->data = data;
	pHead->phead->next_ptr = Temp;
	pHead->count++;
}

void MyList::add(My_List* pHead, int data, int find_data, bool after)
{
	//if (pHead->count == 0)
	//{
	//	push_front(pHead, data);
	//}

	Node* node_ptr;

	if (pHead->phead->data == find_data)
	{
		if (!after)
		{
			push_front(pHead, data);										// ������ ��������� � ������
		}
		else
		{
			node_ptr = pHead->phead->next_ptr;								// ���������� ��������� �� ��������� �������
			pHead->phead->next_ptr = new Node;								// ������� ����� ���� � ���������� ��� ����� ������
			pHead->phead->next_ptr->data = data;							// ������� ������ � ��������� ����
			pHead->phead->next_ptr->next_ptr = node_ptr;					// ������� ��������� �� ��������� ������� � ��������� ����
			pHead->count++; std::cout << "���������� ��������� �������\n";
		}

		return;
	}
	node_ptr = find(pHead, find_data);


	if (node_ptr)
	{
		if (after)								// � ������, ���� ����� �������� ����� ��������
		{
			node_ptr = node_ptr->next_ptr;		// �� ����� ����� ��������� ������
		}

		Node* next = node_ptr->next_ptr;		// ���������� ��������� �� ��������� �������
		node_ptr->next_ptr = new Node;			// � ������� ����� ����

		node_ptr->next_ptr->data = data;		// ������ ������� ������
		node_ptr->next_ptr->next_ptr = next;	// � ��������� �� ��������� �������

		pHead->count++; std::cout << "���������� ��������� �������\n";
	}
	else
	{
		std::cout << "�������� ������� �� ������!\n";
	}
}

void MyList::remove(My_List* pHead, int find_data)
{
	if (pHead->count)
	{
		Node* previous;

		if (pHead->phead->data == find_data)
		{
			previous = pHead->phead;
			pHead->phead = pHead->phead->next_ptr;
			My_Stack::add(pHead->stack, previous);
			std::cout << "�������� ��������� �������\n"; pHead->count--;
			return;
		}

		previous = find(pHead, find_data);

		if (previous)
		{
			My_Stack::add(pHead->stack, previous->next_ptr);
			previous->next_ptr = (previous->next_ptr)->next_ptr;
			pHead->count--;
			std::cout << "�������� ��������� �������\n";
		}
		else
		{
			std::cout << "�� ���� ����� ����� �������(\n";
		}

	}
	else
	{
		std::cout << "�������� ����������, �.� ������ ������!\n";
	}
}

void MyList::cleanMemory(My_List* pHead)
{
	Node* current = pHead->phead;
	while (current)
	{
		Node* next = current->next_ptr;
		delete current;
		current = next;
	}
	My_Stack::clean_memory(pHead->stack);
}

void MyList::show(My_List* pHead)
{
	int number = 1;
	Node* current = pHead->phead;

	while (current)
	{
		std::cout << number++ << "-�� ������� ������, ������: " << current->data << "\n";
		current = current->next_ptr;
	}
}
