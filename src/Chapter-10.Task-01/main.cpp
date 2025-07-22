/*
* Alex Allain. Jumping into c++.
* Глава 10. Массивы
*
* 1. Напишите функцию insertion_sort, которая использует созданный
* нами код для сортировки методом вставки, но работает с массивами
* любого размера.
*/

#include <Windows.h>
#include <iostream>

void run_insertion_sort();

int main() {
	SetConsoleOutputCP(CP_UTF8);

	try
	{
		run_insertion_sort();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void run_insertion_sort() {
}
