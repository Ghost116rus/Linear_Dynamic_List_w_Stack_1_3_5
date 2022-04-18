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

	/* Сам список */
	struct My_List
	{
		int count_list;
		int count_delete;
		Node* phead;
		Node* stack;
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

	void cleanMemory(Node* pHead);

	void show(Node* pHead, const int count);

}


