/*
* Alex Allain. Jumping into c++.
* Глава 5. Функции
*
* 1. Структурируйте «программу-меню», написанную ранее,
* в виде последовательности вызовов функций для каждого из пунктов меню.
* Добавьте калькулятор и «99 Bottles of Beer» в виде двух различных функций,
* которые можно вызывать.
*/

#include <iostream>
#include <stdexcept>
#include <Windows.h>

void show_song_text();
int show_calculator();

int main()
{
	SetConsoleOutputCP(CP_UTF8);

	int selectedItem;

	do
	{
		std::cout << "0. Выход" << std::endl;
		std::cout << "1. Калькулятор" << std::endl;
		std::cout << "2. 99 Bottles of Beer" << std::endl;
		std::cout << std::endl;
		std::cout << "Выберите пункт меню (укажите номер):" << std::endl;
		std::cin >> selectedItem;
		std::cout << std::endl;

		if (selectedItem == 0)
			break;
		else if (selectedItem == 1)
			show_calculator();
		else if (selectedItem == 2)
			show_song_text();
		else
			std::cout << "Выбор не распознан. Попробуйте снова." << std::endl;

	} while (true);
}

void show_song_text() {
	for (int i = 99; i > 0; i--) {
		if (i > 1) {
			std::cout << i
				<< " bottles of beer on the wall, "
				<< i
				<< " bottles of beer." << std::endl
				<< "Take one down & pass it around, now there's "
				<< i - 1
				<< " bottles of beer on the wall"
				<< std::endl;
		}
		else
		{
			std::cout << i
				<< " bottle of beer on the wall, "
				<< i
				<< " bottles of beer." << std::endl
				<< "Take one down & pass it around, now there's no more bottles of beer on the wall!"
				<< std::endl;
		}
	}
}

int show_calculator() {
	const char addition_operation_sign = '+';
	const char subtraction_operation_sign = '-';
	const char multiplication_operation_sign = '*';
	const char division_operation_sign = '/';

	char operation_sign;
	int operand1;
	int operand2;

	try
	{
		std::cout << "Enter operation sign:" << std::endl;
		std::cin >> operation_sign;

		if (operation_sign != addition_operation_sign
			&& operation_sign != subtraction_operation_sign
			&& operation_sign != multiplication_operation_sign
			&& operation_sign != division_operation_sign)
		{
			throw std::invalid_argument("Invalid operation sign!");
		}

		std::cout << "Enter operand 1:" << std::endl;
		std::cin >> operand1;

		std::cout << "Enter operand 2:" << std::endl;
		std::cin >> operand2;

		float result;

		std::cout << "'" << operation_sign << "'" << std::endl;

		if (operation_sign == addition_operation_sign)
			result = operand1 + operand2;
		else if (operation_sign == subtraction_operation_sign)
			result = operand1 - operand2;
		else if (operation_sign == multiplication_operation_sign)
			result = operand1 * operand2;
		else if (operation_sign == division_operation_sign)
		{
			if (operand2 == 0)
				throw std::runtime_error("Division by zero!");

			result = static_cast<float>(operand1) / operand2;
		}

		std::cout << result << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
