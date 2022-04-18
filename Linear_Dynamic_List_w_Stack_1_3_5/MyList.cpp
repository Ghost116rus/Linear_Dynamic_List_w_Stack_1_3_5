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

void MyList::push_front(My_List* list, Node* pHead, int data)
{
	Node* Temp = new Node;
	Temp->data = data;
	Temp->next_ptr = pHead->next_ptr;
	pHead->next_ptr = Temp;
	list->count_list++;
}

void MyList::add(My_List* list, Node* current, int data, bool after)
{
	if (after)								// В случае, если нужно вставить после искомого
	{
		current = current->next_ptr;		// мы сразу берем следующий индекс
	}

	Node* next = current->next_ptr;		// Запоминаем указатель на следующий элемент
	current->next_ptr = new Node;			// И создаем новый узел

	current->next_ptr->data = data;		// Дальше заносим данные
	current->next_ptr->next_ptr = next;	// и указатель на следующий элемент

	list->count_list++; std::cout << "Добавление выполнено успешно\n";

}

void MyList::remove(My_List* list, Node* previous)
{
	Node* Temp = previous->next_ptr;
	previous->next_ptr = (previous->next_ptr)->next_ptr;
	Temp->next_ptr = list->stack->next_ptr;
	list->stack->next_ptr = Temp;

	list->count_list--; list->count_delete++;

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

void MyList::show(Node* head, const int count) 
{
	if (!(count))
	{
		std::cout << "Список пустой!\n"; return;
	}

	int number = 1;
	head = head->next_ptr;

	while (head)
	{
		std::cout << number++ << "-ый элемент списка, Данные: " << head->data << "\n";
		head = head->next_ptr;
	}
}
