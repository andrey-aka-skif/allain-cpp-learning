/*
* Alex Allain. Jumping into c++.
* Глава 8. Случайные числа и отладка
*
* 2. Напишите программу, которая выбирает число от 1 до 100
* и позволяет пользователю угадать его.
* Программа должна информировать пользователя, что предложенное из значение
* слишком мало, слишком велико или он угадал задуманное число
*/

#include <iostream>
#define NOMINMAX
#include <Windows.h>
#include <limits>

void run_number_guesser();
int get_rnd_value(int low, int high);
int int_cin();

int main() {
	SetConsoleOutputCP(CP_UTF8);

	try
	{
		run_number_guesser();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void run_number_guesser() {
	srand(time(NULL));

	int const LOW = 1;
	int const HIGH = 100;

	int hidden_number = get_rnd_value(LOW, HIGH);
	int user_number = 0;
	int attempts_number = 0;

	std::cout << "Угадайте число от " << LOW << " до " << HIGH << ":" << std::endl;

	while (user_number != hidden_number)
	{
		std::cout << "Вы думаете, что загаданное число: ";

		try
		{
			user_number = int_cin();
			attempts_number++;
		}
		catch (const std::exception&)
		{
			std::cout << "Ошибка ввода. Нужно число. Попробуйте ещё раз." << std::endl;
			continue;
		}

		if (user_number < hidden_number) {
			std::cout << "Слишком мало! (число попыток: " << attempts_number << ")." << std::endl;
		}
		else {
			std::cout << "Слишком много! (число попыток: " << attempts_number << ")." << std::endl;
		}
	}

	std::cout << "Вы угадали число " << hidden_number << " за " << attempts_number << " попыток." << std::endl;
}

int get_rnd_value(int low, int high) {
	return rand() % (high - low + 1) + low;
}

int int_cin() {
	int input = 0;
	std::cin >> input;

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		throw std::runtime_error("Ошибка: введено не целое число");
	}

	return input;
}
