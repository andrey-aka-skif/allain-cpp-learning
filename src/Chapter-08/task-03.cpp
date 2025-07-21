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

namespace NumberPicker {
	static int get_guess(int down_limit, int up_limit) {
		return NumberGuesserGame::get_rnd_value(down_limit, up_limit);
	}

	static void run_number_picker() {
		NumberGuesserGame::init_game();

		std::cout
			<< "Загаданное число: "
			<< NumberGuesserGame::secret_number
			<< std::endl;

		NumberGuesserGame::Result result = NumberGuesserGame::UNKNOWN;
		int guess = 0;
		int attempt_count = 0;
		int low_bound = NumberGuesserGame::DEFAULT_LOW_BOUND;
		int high_bound = NumberGuesserGame::DEFAULT_HIGH_BOUND;

		while (result != NumberGuesserGame::EQUALS)
		{
			guess = get_guess(low_bound, high_bound);
			result = NumberGuesserGame::get_guess_result(guess);
			attempt_count++;

			std::cout
				<< "Попытка № "
				<< attempt_count
				<< ": "
				<< guess
				<< std::endl;

			if (result == NumberGuesserGame::NUMBER_IS_MORE_THEN_SECRET)
				high_bound = guess - 1;
			else if (result == NumberGuesserGame::NUMBER_IS_LESS_THEN_SECRET)
				low_bound = guess + 1;
		}
	}
}

int main() {
	SetConsoleOutputCP(CP_UTF8);

	try
	{
		NumberPicker::run_number_picker();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
