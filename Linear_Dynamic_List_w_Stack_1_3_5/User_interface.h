#pragma once
#include <iostream>
#include "MyList.h"

enum Options
{
	Init = 1,
	Add_new_element = 2,
	Delete_element = 3,
	Show_list = 4,
	Show_stack = 5,
	Show_main_menu = 6,
	Write_author = 7,
	Exit = 8,

	Natural_number = 14,
	O_Or_1 = 15,
	Menu_Commands = 16
};

/* Функция со мной ещё со 2 - ого семестра, когда об объектной обработки исключений ничего не было известно  */
int getValue(int condition, const char* string);

/*  Вывод главного меню  */
void show_main_menu();

/*  Вывод информации об авторе  */
void write_author();


void add_new_element(MyList::My_List* list);


void delete_element(MyList::My_List* list);

/*  основная программная реализация интерфейса  */
void menu(MyList::My_List* list);