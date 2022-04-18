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
	Node* find(Node* pHead, int find_data);

	void push_front(My_List* list, Node* pHead, int data);

	/// <summary>
	/// ������� ���������� ����
	/// </summary>
	/// <param name="pHead">�������� ��������� �� ��� ������</param>
	/// <param name="data">�������� ������, ������� ����� ����� ������� � ����� ����</param>
	/// <param name="find_data">�� ������ �������� ����� ���� ����� �����</param>
	/// <param name="after">�������� ����� �������� ����� ��� �� ���������</param>
	void add(My_List* list, Node* current, int data, bool after);

	void remove(My_List* list, Node* previous);

	void cleanMemory(Node* pHead);

	void show(Node* pHead, const int count);

}


