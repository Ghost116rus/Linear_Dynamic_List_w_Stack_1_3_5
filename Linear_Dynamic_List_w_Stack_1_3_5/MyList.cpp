#include "MyList.h"

using namespace MyList;


My_List* MyList::init()
{
	My_List* list = new My_List;
	list->count_list = 0;
	list->count_delete = 0;
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
	pHead->count_list++;
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
			pHead->count_list++; std::cout << "���������� ��������� �������\n";
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

		pHead->count_list++; std::cout << "���������� ��������� �������\n";
	}
	else
	{
		std::cout << "�������� ������� �� ������!\n";
	}
}

void MyList::remove(My_List* pHead, int find_data)
{
	if (pHead->count_list)
	{
		Node* Temp;

		if (pHead->phead->data == find_data)
		{
			Temp = pHead->phead;
			pHead->phead = pHead->phead->next_ptr;
			
			Temp->next_ptr = pHead->stack;
			pHead->stack = Temp;

			std::cout << "�������� ��������� �������\n";
			pHead->count_list--;
			pHead->count_delete++;
			return;
		}

		Node* previous = find(pHead, find_data);

		if (previous)
		{
			Temp = previous->next_ptr;
			previous->next_ptr = (previous->next_ptr)->next_ptr;

			Temp->next_ptr = pHead->stack;
			pHead->stack = Temp;

			pHead->count_list--; pHead->count_delete++;
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

void MyList::cleanMemory(Node* pHead)
{
	while (pHead)
	{
		Node* next = pHead->next_ptr;
		delete pHead;
		pHead = next;
	}
}

void MyList::show(Node* current, const int count) 
{
	if (!(count))
	{
		std::cout << "������ ������!\n"; return;
	}

	int number = 1;

	while (current)
	{
		std::cout << number++ << "-�� ������� ������, ������: " << current->data << "\n";
		current = current->next_ptr;
	}
}
