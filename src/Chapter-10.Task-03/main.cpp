/*
* Alex Allain. Jumping into c++.
* Глава 10. Массивы
*
* 3. Напишите программу, которая определяет, отсортирован ли массив,
* и, если он не отсортирован, сортирует его.
*/

#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

namespace SortInsertion {
	static void insertion_sort(int array[], int size) {
		for (int i = 1; i < size; i++) {
			int key = array[i];
			int j = i - 1;

			while (j >= 0 && array[j] > key) {
				array[j + 1] = array[j];
				j--;
			}
			array[j + 1] = key;
		}
	}
}

void run_check();
void display_array(int array[], int size);

int main() {
	SetConsoleOutputCP(CP_UTF8);

	try
	{
		run_check();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void run_check() {
	/*
	* Задачу можно решить немного более оптимально.
	* Т.к. начало массива может быть отсортировано, можно передать в функцию сортировки
	* индекс, с которого нужно начинать сортировку.
	* Формально это не требуется.
	*/

	int const SIZE = 10;
	int array[SIZE]{ 0,1,2,3,4,50,16,7,80,9 };

	display_array(array, SIZE);

	for (int i = 0; i < SIZE; i++)
	{
		if (i == 0)continue;

		if (array[i - 1] > array[i]) {
			std::cout << "Не отсортирован, начиная с array[" << i << "]=" << array[i] << "]." << std::endl;
			SortInsertion::insertion_sort(array, SIZE);
		}
	}

	display_array(array, SIZE);
}

static void display_array(int array[], int size) {
	std::cout << "{";
	for (int i = 0; i < size; i++)
	{
		if (i != 0) {
			std::cout << ", ";
		}
		std::cout << array[i];
	}
	std::cout << "}";
	std::cout << std::endl;
}
