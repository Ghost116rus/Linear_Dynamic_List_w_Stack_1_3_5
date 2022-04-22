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

	void add(Node* previous, int data, bool before);

	void remove(Node* previous, Node* stack);

	void cleanMemory(Node* pHead);

	void show(Node* head, std::string message);

}


