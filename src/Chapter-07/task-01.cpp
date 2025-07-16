/*
* Alex Allain. Jumping into c++.
* Глава 7. Переключатели и перечисления
*
* 1. Перепишите созданную при решении практической задачи
* программу-меню из главы 6 «Функции», используя оператор switch-case
*/

#include <iostream>
#include <stdexcept>
#include <Windows.h>

void show_menu();
void show_song_text();
void show_calculator();
double calculate(char operation_sign, double operand1, double operand2);
int add(int addend1, int addend2);
int subtract(int minuend, int subtrahend);
int multiply(int factor1, int factor2);
double divide(int dividend, int divisor);

int main()
{
	SetConsoleOutputCP(CP_UTF8);

	try
	{
		show_menu();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void show_menu() {
	int selected_item;
	bool is_working = true;

	do
	{
		std::cout << "0. Выход" << std::endl;
		std::cout << "1. Калькулятор" << std::endl;
		std::cout << "2. 99 Bottles of Beer" << std::endl;
		std::cout << std::endl;
		std::cout << "Выберите пункт меню (укажите номер):" << std::endl;

		std::cin >> selected_item;
		std::cout << std::endl;

		switch (selected_item)
		{
		case 0:
			is_working = false;
			break;
		case 1:
			show_calculator();
			break;
		case 2:
			show_song_text();
			break;
		default:
			std::cout << "Выбор не распознан. Попробуйте снова." << std::endl;
			break;
		}
	} while (is_working);
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

void show_calculator() {
	char operation_sign;
	int operand1;
	int operand2;

	try
	{
		std::cout << "Enter operation sign:" << std::endl;
		std::cin >> operation_sign;

		std::cout << "Enter operand 1:" << std::endl;
		std::cin >> operand1;

		std::cout << "Enter operand 2:" << std::endl;
		std::cin >> operand2;

		double result = calculate(operation_sign, operand1, operand2);

		std::cout << operand1 << " " << operation_sign << " " << operand2 << " = " << result << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

double calculate(char operation_sign, double operand1, double operand2) {
	const char ADDITION_OPERATION_SIGN = '+';
	const char SUBTRACTION_OPERATION_SIGN = '-';
	const char MULTIPLICATION_OPERATION_SIGN = '*';
	const char DIVISION_OPERATION_SIGN = '/';

	if (operation_sign == ADDITION_OPERATION_SIGN)
		return add(operand1, operand2);
	else if (operation_sign == SUBTRACTION_OPERATION_SIGN)
		return subtract(operand1, operand2);
	else if (operation_sign == MULTIPLICATION_OPERATION_SIGN)
		return multiply(operand1, operand2);
	else if (operation_sign == DIVISION_OPERATION_SIGN)
		return divide(operand1, operand2);
	else
		throw std::invalid_argument("Unknown operator!");
}

int add(int addend1, int addend2) {
	return addend1 + addend2;
}

int subtract(int minuend, int subtrahend) {
	return minuend - subtrahend;
}

int multiply(int factor1, int factor2) {
	return factor1 * factor2;
}

/**
 * Делит два числа.
 *
 * \param dividend Делимое
 * \param divisor Делитель
 * \throw std::runtime_error("Division by zero!"), если делитель равен нулю
 * \return Результат деления
 */
double divide(int dividend, int divisor) {
	if (divisor == 0)
		throw std::runtime_error("Division by zero!");

	return static_cast<float>(dividend) / divisor;
}
