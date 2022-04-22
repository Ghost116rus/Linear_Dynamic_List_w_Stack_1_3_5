#include "user_interface.h"


int getValue(int condition, const char* string)
{
	while (true)													// ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
	{
		int a;
		std::cin >> a;

		if (std::cin.fail())										// ���� ���������� ���������� ��������� ���������,
		{
			std::cout << "������! ����������, ��������� ����! \n";
			std::cin.clear();										// �� ���������� cin � '�������' ����� ������
			std::cin.ignore(32767, '\n');							// � ������� �������� ����������� ����� �� �������� ������
			std::cout << string;
		}
		else // ���� �� ������ � ���������� �������, �� ���������� a
		{
			switch (condition)
			{
			case Natural_number:
				if (a > 0) { return a; }

				std::cout << "�� ������ ������ ����������� �����\n";
				std::cin.ignore(32767, '\n');						// � ������� �������� ����������� ����� �� �������� ������
				continue;

			case O_Or_1:												// �� �������

				if ((a == 0) || (a == 1)) { return a; }

				std::cout << "�� ������ ������ ���� 0, ���� 1\n";
				std::cin.ignore(32767, '\n');						// � ������� �������� ����������� ����� �� �������� ������
				continue;

			case Menu_Commands:

				if (((int)a > 0) && ((int)a < 9)) { return a; }

				std::cout << "� ���� ����� 8 �������! ��������� ����: ";
				std::cin.ignore(32767, '\n');						// � ������� �������� ����������� ����� �� �������� ������
				continue;

			default:
				return a;
			}

		}

	}
}

void show_main_menu()
{
	std::cout	<< "  ���������� ���������:\n"
				<< "1. ������������� ������\n"
				<< "2. ���������� ������ ��������\n"
				<< "3. �������� �������� ������\n"
				<< "4. �������� ���������� ������\n"
				<< "5. �������� ���������� �����\n"
				<< "6. �������� ������� ����\n"
				<< "7. ������� ������ ���������\n"
				<< "\n8. ���������� ������\n\n";
}

void write_author()
{
	std::cout << "������ �������� ������ �.�., ������ 4211\n";
}

void add_new_element(MyList::My_List* list)
{
	std::cout << "�������, ������ ������� ������ ��������: ";
	int temp_data = getValue(1, "������� ������: ");

	if (!(list->phead->next_ptr))
	{
		MyList::add(list->phead, temp_data, 0); list->count_list++; return;
	}


	std::cout << "������� �������, �� �������� �� ����� �������������: ";
	int find_data = getValue(Natural_number, "������� �������, �� �������� �� ����� �������������: ");

	MyList::Node* previous = MyList::find(list->phead, find_data);

	if (previous)
	{
		std::cout << "�� ������ �������� ������ �� ��������� �������� ��� �����? 0 - ��, 1 - �����\n �������: ";
		int after = getValue(O_Or_1, "�� ������ �������� ������ �� ��������� �������� ��� �����? 0 - ��, 1 - �����\n �������: ");

		MyList::add(previous, temp_data, after); list->count_list++;
	}
	else
	{
		std::cout << "�������� ������� �� ������!\n";
	}
}

void delete_element(MyList::My_List* list)
{
	std::cout << "������� ������, ������� ������ �� �������: ";
	int find_data = getValue(1, "������� ������: ");

	MyList::Node* previous = MyList::find(list->phead, find_data);

	if (previous)
	{
		MyList::remove(previous, list->stack); list->count_delete++; list->count_list--;
	}
	else
	{
		std::cout << "���������� �������, �.� ������� ������� �� ������!\n";
	}
}


void menu(MyList::My_List* list)
{
	int user_choice = 0;
	bool complete_init = false;

	show_main_menu();
	std::cout << "�������� �������: ";
	user_choice = getValue(Menu_Commands, "�������� �������: ");

	while (user_choice != Exit)
	{
		switch (user_choice)
		{

		case Init:

			if (!complete_init)
			{
				list = MyList::init(); std::cout << "C����� ���������������.\n";
				complete_init = true;
			}
			else
			{
				std::cout << "C����� ��� ���������������!\n";
			}
			break;

		case Add_new_element:

			if (complete_init) { add_new_element(list);}
			else
			{
				std::cout << "���������� ��������� ��������, �.� ������ �� ���������������\n";
			}
			break;

		case Delete_element:

			if (complete_init)
			{
				if (!(list->phead->next_ptr))
				{
					std::cout << "������ ������!\n";
				}
				else
				{
					delete_element(list);
				}
			}
			else
			{
				std::cout << "���������� ���-���� �������, �.� ������ �� ���������������!\n";
			}
			break;

		case Show_list:

			if (complete_init) { MyList::show(list->phead, "��������� ������"); }
			else { std::cout << "������ �� ���������������!\n"; }

			break;

		case Show_stack:

			if (complete_init) { MyList::show(list->stack, "���������������� ������"); }
			else { std::cout << "������ �� ���������������!\n"; }

			break;

		case Show_main_menu:

			std::cout << "\n\n";
			show_main_menu();
			break;

		case Write_author:

			write_author();
			break;

		default:
			break;
		}
		std::cout << "\n�������� �������: ";
		user_choice = getValue(Menu_Commands, "�������� �������: ");
	}

	if (complete_init)
	{
		MyList::cleanMemory(list->phead);
		MyList::cleanMemory(list->stack);
		delete list;
	}

	std::cout << "���������� ������\n";
}