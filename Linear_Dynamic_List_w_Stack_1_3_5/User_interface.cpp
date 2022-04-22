#include "user_interface.h"


int getValue(int condition, const char* string)
{
	while (true)													// цикл продолжается до тех пор, пока пользователь не введет корректное значение
	{
		int a;
		std::cin >> a;

		if (std::cin.fail())										// если предыдущее извлечение оказалось неудачным,
		{
			std::cout << "Ошибка! Пожалуйста, повторите ввод! \n";
			std::cin.clear();										// то возвращаем cin в 'обычный' режим работы
			std::cin.ignore(32767, '\n');							// и удаляем значения предыдущего ввода из входного буфера
			std::cout << string;
		}
		else // если всё хорошо и выполнятся условия, то возвращаем a
		{
			switch (condition)
			{
			case Natural_number:
				if (a > 0) { return a; }

				std::cout << "Вы должны ввести натуральное число\n";
				std::cin.ignore(32767, '\n');						// и удаляем значения предыдущего ввода из входного буфера
				continue;

			case O_Or_1:												// На будущее

				if ((a == 0) || (a == 1)) { return a; }

				std::cout << "Вы должны ввести либо 0, либо 1\n";
				std::cin.ignore(32767, '\n');						// и удаляем значения предыдущего ввода из входного буфера
				continue;

			case Menu_Commands:

				if (((int)a > 0) && ((int)a < 9)) { return a; }

				std::cout << "У меню всего 8 функций! Повторите ввод: ";
				std::cin.ignore(32767, '\n');						// и удаляем значения предыдущего ввода из входного буфера
				continue;

			default:
				return a;
			}

		}

	}
}

void show_main_menu()
{
	std::cout	<< "  Функционал программы:\n"
				<< "1. Инициализация списка\n"
				<< "2. Добавление нового элемента\n"
				<< "3. Удаление элемента списка\n"
				<< "4. Показать содержимое списка\n"
				<< "5. Показать содержимое стека\n"
				<< "6. Показать главное меню\n"
				<< "7. Вывести автора программы\n"
				<< "\n8. Завершение работы\n\n";
}

void write_author()
{
	std::cout << "Работу выполнил Калеев Д.А., группа 4211\n";
}

void add_new_element(MyList::My_List* list)
{
	std::cout << "Введите, данные которые хотите добавить: ";
	int temp_data = getValue(1, "Введите данные: ");

	if (!(list->phead->next_ptr))
	{
		MyList::add(list->phead, temp_data, 0); list->count_list++; return;
	}


	std::cout << "Введите элемент, от которого мы будем отталкиваться: ";
	int find_data = getValue(Natural_number, "Введите элемент, от которого мы будем отталкиваться: ");

	MyList::Node* previous = MyList::find(list->phead, find_data);

	if (previous)
	{
		std::cout << "Вы хотите вставить данные до заданного элемента или после? 0 - до, 1 - после\n Введите: ";
		int after = getValue(O_Or_1, "Вы хотите вставить данные до заданного элемента или после? 0 - до, 1 - после\n Введите: ");

		MyList::add(previous, temp_data, after); list->count_list++;
	}
	else
	{
		std::cout << "Заданный элемент не найден!\n";
	}
}

void delete_element(MyList::My_List* list)
{
	std::cout << "Введите данные, которые хотели бы удалить: ";
	int find_data = getValue(1, "Введите данные: ");

	MyList::Node* previous = MyList::find(list->phead, find_data);

	if (previous)
	{
		MyList::remove(previous, list->stack); list->count_delete++; list->count_list--;
	}
	else
	{
		std::cout << "Невозможно удалить, т.к заданый элемент не найден!\n";
	}
}


void menu(MyList::My_List* list)
{
	int user_choice = 0;
	bool complete_init = false;

	show_main_menu();
	std::cout << "Выберите команду: ";
	user_choice = getValue(Menu_Commands, "Выберите команду: ");

	while (user_choice != Exit)
	{
		switch (user_choice)
		{

		case Init:

			if (!complete_init)
			{
				list = MyList::init(); std::cout << "Cписок инициализирован.\n";
				complete_init = true;
			}
			else
			{
				std::cout << "Cписок уже инициализирован!\n";
			}
			break;

		case Add_new_element:

			if (complete_init) { add_new_element(list);}
			else
			{
				std::cout << "Невозможно выполнить операцию, т.к список не инициализирован\n";
			}
			break;

		case Delete_element:

			if (complete_init)
			{
				if (!(list->phead->next_ptr))
				{
					std::cout << "Список пустой!\n";
				}
				else
				{
					delete_element(list);
				}
			}
			else
			{
				std::cout << "Невозможно что-либо удалить, т.к список не инициализирован!\n";
			}
			break;

		case Show_list:

			if (complete_init) { MyList::show(list->phead, "основного списка"); }
			else { std::cout << "Список не инициализирован!\n"; }

			break;

		case Show_stack:

			if (complete_init) { MyList::show(list->stack, "вспомогательного списка"); }
			else { std::cout << "Список не инициализирован!\n"; }

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
		std::cout << "\nВыберите команду: ";
		user_choice = getValue(Menu_Commands, "Выберите команду: ");
	}

	if (complete_init)
	{
		MyList::cleanMemory(list->phead);
		MyList::cleanMemory(list->stack);
		delete list;
	}

	std::cout << "Завершение работы\n";
}