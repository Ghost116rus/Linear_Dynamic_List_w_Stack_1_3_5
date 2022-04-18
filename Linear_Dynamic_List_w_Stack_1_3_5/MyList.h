#pragma once
#include<iostream>


namespace MyList
{
	/* ������� ������� ������ */
	struct Node
	{
		int data = -1;
		Node* next_ptr = nullptr;
	};

	/* ��� ������ */
	struct My_List
	{
		int count_list;
		int count_delete;
		Node* phead;
		Node* stack;
	};

	/// <summary>
	/// ������� �������������
	/// </summary>
	/// <returns>���������� ��������� �� ��������� ���������, ��� � ��������� ������</returns>
	My_List* init();

	/// <summary>
	/// ������� ������ ����, ��������������� ���� � ��������� �������
	/// </summary>
	/// <param name="pHead">��������� �� ���� ���������</param>
	/// <param name="data">������� ������</param>
	/// <returns>��������� ��������� �� �������������� ����</returns>
	Node* find(My_List* pHead, int find_data);

	void push_front(My_List* pHead, int data);

	void add(My_List* pHead, int data, int find_data, bool after);

	void remove(My_List* pHead, int find_data);

	void cleanMemory(Node* pHead);

	void show(Node* pHead, const int count);

}


