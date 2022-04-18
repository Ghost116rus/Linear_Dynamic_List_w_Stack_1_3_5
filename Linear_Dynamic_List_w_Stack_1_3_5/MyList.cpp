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
			push_front(pHead, data);										// Просто вставляем в начало
		}
		else
		{
			node_ptr = pHead->phead->next_ptr;								// Запоминаем указатель на следующий элемент
			pHead->phead->next_ptr = new Node;								// Создаем новый узел и записываем его после головы
			pHead->phead->next_ptr->data = data;							// Заносим данные в созданный узел
			pHead->phead->next_ptr->next_ptr = node_ptr;					// Заносим указатель на следующий элемент в созданный узел
			pHead->count++; std::cout << "Добавление выполнено успешно\n";
		}

		return;
	}
	node_ptr = find(pHead, find_data);


	if (node_ptr)
	{
		if (after)								// В случае, если нужно вставить после искомого
		{
			node_ptr = node_ptr->next_ptr;		// мы сразу берем следующий индекс
		}

		Node* next = node_ptr->next_ptr;		// Запоминаем указатель на следующий элемент
		node_ptr->next_ptr = new Node;			// И создаем новый узел

		node_ptr->next_ptr->data = data;		// Дальше заносим данные
		node_ptr->next_ptr->next_ptr = next;	// и указатель на следующий элемент

		pHead->count++; std::cout << "Добавление выполнено успешно\n";
	}
	else
	{
		std::cout << "Заданный элемент не найден!\n";
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
			std::cout << "Удаление выполнено успешно\n"; pHead->count--;
			return;
		}

		previous = find(pHead, find_data);

		if (previous)
		{
			My_Stack::add(pHead->stack, previous->next_ptr);
			previous->next_ptr = (previous->next_ptr)->next_ptr;
			pHead->count--;
			std::cout << "Удаление выполнено успешно\n";
		}
		else
		{
			std::cout << "Не смог найти такой элемент(\n";
		}

	}
	else
	{
		std::cout << "Удаление невозможно, т.к список пустой!\n";
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
		std::cout << number++ << "-ый элемент списка, Данные: " << current->data << "\n";
		current = current->next_ptr;
	}
}
