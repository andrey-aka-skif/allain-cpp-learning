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

namespace NumberGuesserGame {
	int const DEFAULT_LOW_BOUND = 1;
	int const DEFAULT_HIGH_BOUND = 100;

	enum Result { UNKNOWN, NUMBER_IS_LESS_THEN_SECRET, NUMBER_IS_MORE_THEN_SECRET, EQUALS };

	int secret_number = 0;
	int low_bound = DEFAULT_LOW_BOUND;
	int high_bound = DEFAULT_HIGH_BOUND;

	static int get_rnd_value(int low, int high) {
		return rand() % (high - low + 1) + low;
	}

	static void init_game(int low = DEFAULT_LOW_BOUND, int high = DEFAULT_HIGH_BOUND) {
		low_bound = low;
		high_bound = high;

		srand(time(NULL));
		secret_number = get_rnd_value(DEFAULT_LOW_BOUND, DEFAULT_HIGH_BOUND);
	}

	static Result get_guess_result(int guess) {
		if (guess < secret_number)
			return NUMBER_IS_LESS_THEN_SECRET;
		else if (guess > secret_number)
			return NUMBER_IS_MORE_THEN_SECRET;
		else
			return EQUALS;
	}

	static void run_number_guesser_game() {
		NumberGuesserGame::init_game();

		std::cout
			<< "Угадайте число от "
			<< DEFAULT_LOW_BOUND
			<< " до "
			<< DEFAULT_HIGH_BOUND
			<< ":"
			<< std::endl;

		Result result = UNKNOWN;
		int user_guess_number = 0;
		int attempt_count = 0;

		do
		{
			std::cout
				<< "Вы думаете, что загаданное число: ";

			try
			{
				user_guess_number = CustomInput::int_cin();
				result = get_guess_result(user_guess_number);
				attempt_count++;
			}
			catch (const std::exception&)
			{
				std::cout
					<< "Ошибка ввода. Нужно число. Попробуйте ещё раз."
					<< std::endl;
				continue;
			}

			if (result == NUMBER_IS_LESS_THEN_SECRET) {
				std::cout
					<< "Слишком мало! (число попыток: "
					<< attempt_count
					<< ")."
					<< std::endl;
			}
			else if (result == NUMBER_IS_MORE_THEN_SECRET) {
				std::cout
					<< "Слишком много! (число попыток: "
					<< attempt_count
					<< ")."
					<< std::endl;
			}
		} while (result != EQUALS);

		std::cout
			<< "Вы угадали число "
			<< NumberGuesserGame::secret_number
			<< " за "
			<< attempt_count
			<< " попыток."
			<< std::endl;
	}
}

int main() {
	SetConsoleOutputCP(CP_UTF8);

	try
	{
		NumberGuesserGame::run_number_guesser_game();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
