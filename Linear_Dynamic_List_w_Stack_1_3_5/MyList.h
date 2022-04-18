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

	namespace My_Stack
	{
		/* ��� ������� ����� */
		struct stackElement
		{
			stackElement* previous_element;
			Node* node;
		};

		/*  ������� ������������� �����  */
		stackElement* init(Node* node);

		/// <summary>
		/// ������� ���������� �������� � �����
		/// </summary>
		/// <param name="previous_ptr">��������� �� ��������� �������</param>
		/// <param name="data"></param>
		void add(stackElement*& previous_ptr, Node* node);

		/// <summary>
		/// ������� �������� ���������� ��������
		/// </summary>
		/// <param name="last_ptr">��������� �� ��������� �������</param>
		void remove_at(stackElement*& last_ptr);

		/// <summary>
		/// ������� ������ ��������� ����� � �������
		/// </summary>
		/// <param name="last_el">��������� �� ��������� �������</param>
		void show(stackElement* last_el);

		/// <summary>
		/// ��������������� �������, ��� ���������� ������
		/// </summary>
		/// <param name="stack">������� ������</param>
		void clean_memory(stackElement*& stack);

	}

	/* ��� ������ */
	struct My_List
	{
		int count;
		Node* phead;
		My_Stack::stackElement* stack;
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


	/// <summary>
	/// ������� ���������� ���� � ������ ������
	/// </summary>
	/// <param name="pHead">�������� ��������� �� ��� ������</param>
	/// <param name="data">�������� ������, ������� ����� ����� ������� � ����� ����</param>
	void push_front(My_List* pHead, int data);

	/// <summary>
	/// ������� ���������� ����
	/// </summary>
	/// <param name="pHead">�������� ��������� �� ��� ������</param>
	/// <param name="data">�������� ������, ������� ����� ����� ������� � ����� ����</param>
	/// <param name="find_data">�� ������ �������� ����� ���� ����� �����</param>
	/// <param name="after">�������� ����� �������� ����� ��� �� ���������</param>
	void add(My_List* pHead, int data, int find_data, bool after);

	/// <summary>
	/// ������� �������� ����
	/// </summary>
	/// <param name="pHead">�������� ��������� �� ��� ������</param>
	/// <param name="find_data">�������� </param>
	void remove(My_List* pHead, int find_data);


	/// <summary>
	/// ������� ������� ������
	/// </summary>
	/// <param name="pHead">�������� ��������� �� ��� ������</param>
	void cleanMemory(My_List* pHead);

	/// <summary>
	/// ������� ������ �� �����
	/// </summary>
	/// <param name="pHead"></param>
	void show(My_List* pHead);

}


