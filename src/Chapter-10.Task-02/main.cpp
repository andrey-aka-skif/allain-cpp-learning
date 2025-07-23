/*
* Alex Allain. Jumping into c++.
* Глава 10. Массивы
*
* 2. Напишите программу, которая принимает 50 значений и выводит
* наибольшее, наименьшее и среднее значения, затем сами введенные
* значения по одному в строке.
*/

#define NOMINMAX
#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

namespace CustomInput {
	static int int_cin() {
		int input = 0;
		std::cin >> input;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			throw std::runtime_error("Ошибка: введено не целое число");
		}

		return input;
	}
}

void run_interaction();

int main() {
	SetConsoleOutputCP(CP_UTF8);

	try
	{
		run_interaction();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void run_interaction() {
	/*
	* Для подсчета наибольшего, наименьшего и среднего не обязательно
	* второй раз проходить массив. Считаем сразу.
	* Но появляется дополнительная проверка i == 0
	*/

	int const SIZE = 5;

	int array[SIZE]{};
	int greatest = 0;
	int smallest = 0;
	int sum = 0;
	float average = 0;

	int current = 0;

	std::cout << "Введите " << SIZE << " чисел." << std::endl;

	for (int i = 0; i < SIZE; i++)
	{
		std::cout << "Число № " << i << ": ";

		current = CustomInput::int_cin();

		sum += current;
		average = (float)sum / (i + 1);

		if (i == 0 || current < smallest)
			smallest = current;

		if (i == 0 || current > greatest)
			greatest = current;

		array[i] = current;
	}

	std::cout << "Сумма: " << sum << std::endl;
	std::cout << "Наибольшее: " << greatest << std::endl;
	std::cout << "Наименьшее: " << smallest << std::endl;
	std::cout << "Среднее: " << average << std::endl;

	for (int i = 0; i < SIZE; i++)
	{
		std::cout << i << ") " << array[i] << std::endl;
	}
}
