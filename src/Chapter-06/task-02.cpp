/*
* Alex Allain. Jumping into c++.
* Глава 5. Функции
*
* 2. Структурируйте программу-калькулятор так, чтобы каждый тип вычислений выполнялся в отдельной функции.
*/

#include <iostream>
#include <stdexcept>
#include <Windows.h>

double calculate(char operation_sign, double operand1, double operand2);
int add(int addend1, int addend2);
int subtract(int minuend, int subtrahend);
int multiply(int factor1, int factor2);
double divide(int dividend, int divisor);

int main() {
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
