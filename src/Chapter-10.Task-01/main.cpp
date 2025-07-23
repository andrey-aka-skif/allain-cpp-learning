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
#include <cstdlib>
#include <ctime>

void run_sort();
void display_array(int array[], int size);

namespace SortSelection {
	static int find_smallest_remaining_element(int array[], int size, int index) {
		int index_of_smallest_value = index;

		for (int i = index + 1; i < size; i++)
		{
			if (array[i] < array[index_of_smallest_value]) {
				index_of_smallest_value = i;
			}
		}

		return index_of_smallest_value;
	}

	static void swap(int array[], int first_index, int second_index) {
		int temp = array[first_index];
		array[first_index] = array[second_index];
		array[second_index] = temp;
	}

	static void selection_sort(int array[], int size) {
		for (int i = 0; i < size; i++) {
			int index = find_smallest_remaining_element(array, size, i);
			swap(array, i, index);
		}
	}
}

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

int main() {
	SetConsoleOutputCP(CP_UTF8);

	try
	{
		run_sort();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void run_sort() {
	srand(time(NULL));

	int array[10]{};

	for (int i = 0; i < 10; i++)
	{
		array[i] = rand() % 100;
	}
	std::cout << "Исходный массив:" << std::endl;
	display_array(array, 10);
	SortInsertion::insertion_sort(array, 10);
	std::cout << "Отсортированный массив:" << std::endl;
	display_array(array, 10);
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
