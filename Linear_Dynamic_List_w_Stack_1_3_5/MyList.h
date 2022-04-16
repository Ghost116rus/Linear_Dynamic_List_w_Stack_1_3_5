#pragma once
#include<iostream>


namespace MyList
{
	/* Узловой элемент списка */
	struct Node
	{
		int data = -1;
		Node* next_ptr = nullptr;
	};

	namespace My_Stack
	{
		/* Наш элемент стека */
		struct stackElement
		{
			stackElement* previous_element;
			Node* node;
		};

		/*  Функция инициализации стека  */
		stackElement* init(Node* node);

		/// <summary>
		/// Функция добавления элемента в конец
		/// </summary>
		/// <param name="previous_ptr">Указатель на последний элемент</param>
		/// <param name="data"></param>
		void add(stackElement*& previous_ptr, Node* node);

		/// <summary>
		/// Функция удаления последнего элемента
		/// </summary>
		/// <param name="last_ptr">Указатель на последний элемент</param>
		void remove_at(stackElement*& last_ptr);

		/// <summary>
		/// Функция вывода элементов стека в консоль
		/// </summary>
		/// <param name="last_el">Указатель на последний элемент</param>
		void show(stackElement* last_el);

		/// <summary>
		/// Вспомогательная функция, для завершения работы
		/// </summary>
		/// <param name="stack">Очистка памяти</param>
		void clean_memory(stackElement*& stack);

	}

	/* Сам список */
	struct My_List
	{
		int count;
		Node* phead;
		My_Stack::stackElement* stack;
	};

	/// <summary>
	/// Функция инициализации
	/// </summary>
	/// <returns>Возвращает указатель на созданную структуру, уже с созданным стеком</returns>
	My_List* init();

	/// <summary>
	/// Функция поиска узла, предшествующего узлу с заданными данными
	/// </summary>
	/// <param name="pHead">Указатель на саму структуру</param>
	/// <param name="data">Искомые данные</param>
	/// <returns>Возращает указатель на предшествующий узел</returns>
	Node* find(My_List* pHead, int find_data);

	void push_front(My_List* pHead, int data);

	void add(My_List* pHead, int data, int find_data, bool after);

	void remove(My_List* pHead, int find_data);

	void cleanMemory(My_List* pHead);

	void show(My_List* pHead);

}


