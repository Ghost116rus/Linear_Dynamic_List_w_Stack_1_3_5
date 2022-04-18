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
	Node* find(Node* pHead, int find_data);

	void push_front(My_List* list, Node* pHead, int data);

	/// <summary>
	/// Функция добавления узла
	/// </summary>
	/// <param name="pHead">Получает указатель на сам список</param>
	/// <param name="data">Получает данные, которые нужно будет занести в новый узел</param>
	/// <param name="find_data">По данным выясняем какой узел нужно найти</param>
	/// <param name="after">Выясняем нужно вставить после или до заданного</param>
	void add(My_List* list, Node* current, int data, bool after);

	void remove(My_List* list, Node* previous);

	void cleanMemory(Node* pHead);

	void show(Node* pHead, const int count);

}


