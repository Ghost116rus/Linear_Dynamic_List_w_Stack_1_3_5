#include "MyList.h"

using namespace MyList;

My_List* MyList::init()
{
	My_List* list = new My_List;
	list->count_list = 0;
	list->count_delete = 0;
	list->phead = new Node;
	list->stack = new Node;

	return list;
}

Node* MyList::find(Node* pHead, int find_data)
{
	Node* previous = pHead;

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


void MyList::add(Node* previous, int data, bool after)
{
	if (after)
	{
		previous = previous->next_ptr;
	}

	Node* temp = new Node();
	temp->data = data;
	temp->next_ptr = previous->next_ptr;
	previous->next_ptr = temp;

	std::cout << "Добавление выполнено успешно\n";
}

void addNode(Node* stack, Node* data)
{
	data->next_ptr = stack->next_ptr;
	stack->next_ptr = data;
}

void MyList::remove(Node* previous, Node* stack)
{
	Node* Temp = previous->next_ptr;
	previous->next_ptr = (previous->next_ptr)->next_ptr;

	addNode(stack, Temp);

	std::cout << "Удаление выполнено успешно\n";
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

void MyList::show(Node* head, std::string message) 
{
	head = head->next_ptr;

	if (!(head))
	{
		std::cout << "Список пустой!\n"; return;
	}

	int number = 1;
	while (head)
	{
		std::cout << number++ << "-ый элемент " << message << ", Данные: " << head->data << "\n";
		head = head->next_ptr;
	}
}
