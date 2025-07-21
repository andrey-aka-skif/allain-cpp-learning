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

	enum Result { UNKNOWN, NUMBER_IS_LESS_THAN_SECRET, NUMBER_IS_MORE_THAN_SECRET, EQUALS };

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
			return NUMBER_IS_LESS_THAN_SECRET;
		else if (guess > secret_number)
			return NUMBER_IS_MORE_THAN_SECRET;
		else
			return EQUALS;
	}

	static void run_human_guesser() {
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
			}
			catch (const std::exception&)
			{
				std::cout
					<< "Ошибка ввода. Нужно число. Попробуйте ещё раз."
					<< std::endl;
				continue;
			}

			if (user_guess_number < low_bound || user_guess_number > high_bound) {
				std::cout
					<< "Число должно быть от "
					<< low_bound
					<< " до "
					<< high_bound
					<< std::endl;
				continue;
			}

			result = get_guess_result(user_guess_number);
			attempt_count++;

			if (result == NUMBER_IS_LESS_THAN_SECRET) {
				std::cout
					<< "Слишком мало! (число попыток: "
					<< attempt_count
					<< ")."
					<< std::endl;
			}
			else if (result == NUMBER_IS_MORE_THAN_SECRET) {
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
		return (down_limit + up_limit) / 2;
	}

	static void run_ai_guesser() {
		NumberGuesserGame::init_game(NumberGuesserGame::DEFAULT_LOW_BOUND, NumberGuesserGame::DEFAULT_HIGH_BOUND);

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

			if (result == NumberGuesserGame::NUMBER_IS_MORE_THAN_SECRET)
				high_bound = guess - 1;
			else if (result == NumberGuesserGame::NUMBER_IS_LESS_THAN_SECRET)
				low_bound = guess + 1;
		}

		std::cout
			<< "Число "
			<< NumberGuesserGame::secret_number
			<< " угадано за "
			<< attempt_count
			<< " попыток."
			<< std::endl;
	}
}

int main() {
	SetConsoleOutputCP(CP_UTF8);

	try
	{
		NumberPicker::run_ai_guesser();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
