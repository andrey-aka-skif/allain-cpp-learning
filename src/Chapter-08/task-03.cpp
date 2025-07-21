/*
* Alex Allain. Jumping into c++.
* Глава 8. Случайные числа и отладка
*
* 3. Напишите программу, которая решает проблему игры на угадывание.
* Сколько угадываний требуется вашей программе?
*/

#include <iostream>
#define NOMINMAX
#include <Windows.h>
#include <ctime>

enum Result { UNKNOWN, NEED_MORE, NEED_LESS, EQUALS };

void run_number_guesser();
Result get_guess_result(int guess, int secret_number);
int get_rnd_value(int low, int high);
int get_guess(int down_limit, int up_limit);

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
	int const LOW = 1;
	int const HIGH = 100;

	srand(time(NULL));
	int secret_number = get_rnd_value(LOW, HIGH);

	std::cout << "Загаданное число: " << secret_number << std::endl;

	Result result = UNKNOWN;
	int guess = 0;
	int attempts_number = 0;
	int low_border = LOW;
	int high_border = HIGH;

	while (result != EQUALS)
	{
		guess = get_guess(low_border, high_border);
		result = get_guess_result(guess, secret_number);
		attempts_number++;

		std::cout << "Попытка № " << attempts_number << ": " << guess << std::endl;

		if (result == NEED_LESS)
			low_border = guess + 1;
		else if (result == NEED_MORE)
			high_border = guess - 1;
	}
}

Result get_guess_result(int guess, int secret_number) {
	if (guess < secret_number)
		return NEED_LESS;
	else if (guess > secret_number)
		return NEED_MORE;
	else
		return EQUALS;
}

int get_guess(int down_limit, int up_limit) {
	return get_rnd_value(down_limit, up_limit);
}

int get_rnd_value(int low, int high) {
	return rand() % (high - low + 1) + low;
}
