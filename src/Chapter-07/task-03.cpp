/*
* Alex Allain. Jumping into c++.
* Глава 7. Переключатели и перечисления
*
* 3. Напишите игру «крестики-нолики» для двух игроков;
* по возможности представляйте содержимое игрового поля
* с помощью перечислений
*/

#include <iostream>
#include <stdexcept>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <cstdlib>

enum Sign { EMPTY, X, O };
enum Input { UNKNOWN, UP, DOWN, LEFT, RIGHT, SELECT, QUITE };

void run_tic_tac_game();
Input get_input();
Input get_arrow_input();
bool handle_input(Input input);
void handle_up();
void handle_down();
void handle_left();
void handle_right();
bool try_select();
void inverse_current_sign();
void clear();
void draw_field();
void show_help();
void show_current_sign();
char sign_to_char(Sign sign);
std::string sign_with_cursor_to_string(int x, int y, Sign sign);
bool check_line(Sign a, Sign b, Sign c);
void check_win();
void show_final_message();

int main() {
	SetConsoleOutputCP(CP_UTF8);

	try
	{
		run_tic_tac_game();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

namespace Game {
	Sign cell_0_0 = EMPTY;
	Sign cell_0_1 = EMPTY;
	Sign cell_0_2 = EMPTY;

	Sign cell_1_0 = EMPTY;
	Sign cell_1_1 = EMPTY;
	Sign cell_1_2 = EMPTY;

	Sign cell_2_0 = EMPTY;
	Sign cell_2_1 = EMPTY;
	Sign cell_2_2 = EMPTY;

	int cursor_row = 1;
	int cursor_column = 1;

	Sign current_sign = X;

	bool is_play = true;

	int step_count = 0;

	std::string final_message;
}

void run_tic_tac_game() {
	bool handle_input_result = true;
	Input input = UNKNOWN;

	show_help();
	show_current_sign();
	draw_field();

	do
	{
		input = get_input();
		handle_input_result = handle_input(input);
		clear();
		show_help();
		show_current_sign();
		draw_field();
	} while (handle_input_result && Game::is_play);

	show_final_message();
}

void show_final_message() {
	std::cout << std::endl << Game::final_message << std::endl;
}

#pragma region Handle Logic
void check_win() {
	Game::step_count++;
	if (Game::step_count >= 9) {
		Game::is_play = false;
		Game::final_message = "Ничья";
		return;
	}

	// Проверка горизонталей
	if (check_line(Game::cell_0_0, Game::cell_0_1, Game::cell_0_2)) {
		Game::is_play = false;
	}
	else if (check_line(Game::cell_1_0, Game::cell_1_1, Game::cell_1_2)) {
		Game::is_play = false;
	}
	else if (check_line(Game::cell_2_0, Game::cell_2_1, Game::cell_2_2)) {
		Game::is_play = false;
	}

	// Проверка вертикалей
	else if (check_line(Game::cell_0_0, Game::cell_1_0, Game::cell_2_0)) {
		Game::is_play = false;
	}
	else if (check_line(Game::cell_0_1, Game::cell_1_1, Game::cell_2_1)) {
		Game::is_play = false;
	}
	else if (check_line(Game::cell_0_2, Game::cell_1_2, Game::cell_2_2)) {
		Game::is_play = false;
	}

	// Проверка диагоналей
	else if (check_line(Game::cell_0_0, Game::cell_1_1, Game::cell_2_2)) {
		Game::is_play = false;
	}
	else if (check_line(Game::cell_0_2, Game::cell_1_1, Game::cell_2_0)) {
		Game::is_play = false;
	}

	if (!Game::is_play) {
		Game::final_message = std::string("Победа: ") + sign_to_char(Game::current_sign);
	}
}

bool check_line(Sign a, Sign b, Sign c) {
	return a != EMPTY && a == b && b == c;
}
#pragma endregion

#pragma region Handle Control
void handle_up() {
	if (Game::cursor_row > 0)
		Game::cursor_row--;
}

void handle_down() {
	if (Game::cursor_row < 2)
		Game::cursor_row++;
}

void handle_left() {
	if (Game::cursor_column > 0)
		Game::cursor_column--;
}

void handle_right() {
	if (Game::cursor_column < 2)
		Game::cursor_column++;
}

bool try_select() {
	if (Game::cursor_row == 0 && Game::cursor_column == 0 && Game::cell_0_0 == EMPTY) {
		Game::cell_0_0 = Game::current_sign;
		return true;
	}
	if (Game::cursor_row == 0 && Game::cursor_column == 1 && Game::cell_0_1 == EMPTY) {
		Game::cell_0_1 = Game::current_sign;
		return true;
	}
	if (Game::cursor_row == 0 && Game::cursor_column == 2 && Game::cell_0_2 == EMPTY) {
		Game::cell_0_2 = Game::current_sign;
		return true;
	}

	if (Game::cursor_row == 1 && Game::cursor_column == 0 && Game::cell_1_0 == EMPTY) {
		Game::cell_1_0 = Game::current_sign;
		return true;
	}
	if (Game::cursor_row == 1 && Game::cursor_column == 1 && Game::cell_1_1 == EMPTY) {
		Game::cell_1_1 = Game::current_sign;
		return true;
	}
	if (Game::cursor_row == 1 && Game::cursor_column == 2 && Game::cell_1_2 == EMPTY) {
		Game::cell_1_2 = Game::current_sign;
		return true;
	}

	if (Game::cursor_row == 2 && Game::cursor_column == 0 && Game::cell_2_0 == EMPTY) {
		Game::cell_2_0 = Game::current_sign;
		return true;
	}
	if (Game::cursor_row == 2 && Game::cursor_column == 1 && Game::cell_2_1 == EMPTY) {
		Game::cell_2_1 = Game::current_sign;
		return true;
	}
	if (Game::cursor_row == 2 && Game::cursor_column == 2 && Game::cell_2_2 == EMPTY) {
		Game::cell_2_2 = Game::current_sign;
		return true;
	}

	return false;
}

void inverse_current_sign() {
	if (Game::current_sign == X)
		Game::current_sign = O;
	else if (Game::current_sign == O)
		Game::current_sign = X;
}
#pragma endregion

#pragma region Handle Input
bool handle_input(Input input) {
	switch (input)
	{
	case UP:
		handle_up();
		break;
	case DOWN:
		handle_down();
		break;
	case LEFT:
		handle_left();
		break;
	case RIGHT:
		handle_right();
		break;
	case SELECT:
		if (try_select()) {
			check_win();
			inverse_current_sign();
		};
		break;
	case QUITE:
		return false;
	default:
		break;
	}

	return true;
}

Input get_input() {
	int key = _getch();

	switch (key)
	{
	case 'w':
	case 'W':
		return UP;
	case 's':
	case 'S':
		return DOWN;
	case 'a':
	case 'A':
		return LEFT;
	case 'd':
	case 'D':
		return RIGHT;
	case ' ':
		return SELECT;
	case 'q':
	case 'Q':
		return QUITE;
	default:
		break;
	}

	// Стрелки (возвращают два кода: 224 + код стрелки)
	const int ARROW_PREFIX = 224;
	if (key == ARROW_PREFIX || key == 0) {
		return get_arrow_input();
	}

	return UNKNOWN;
}

Input get_arrow_input() {
	// Стрелки (возвращают два кода: 224 + код стрелки)
	const int UP_ARROW = 72;
	const int DOWN_ARROW = 80;
	const int LEFT_ARROW = 75;
	const int RIGHT_ARROW = 77;

	int second_key = _getch();  // Читаем второй код
	switch (second_key)
	{
	case UP_ARROW:
		return UP;
	case DOWN_ARROW:
		return DOWN;
	case LEFT_ARROW:
		return LEFT;
	case RIGHT_ARROW:
		return RIGHT;
	default:
		return UNKNOWN;
	}
}
#pragma endregion

#pragma region Handle Drow
void clear() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void show_current_sign() {
	std::cout << "Сейчас ходит: " << sign_to_char(Game::current_sign) << std::endl;
}

void show_help() {
	std::cout << "Управление:" << std::endl;
	std::cout << "w/↑ - вверх" << std::endl;
	std::cout << "s/↓ - вниз" << std::endl;
	std::cout << "a/← - влево" << std::endl;
	std::cout << "d/→ - вправо" << std::endl;
	std::cout << "Space - ход" << std::endl;
	std::cout << "q - выход" << std::endl;
}

void draw_field() {

	// линия 0
	std::cout << "┌───┬───┬───┐" << std::endl;

	// строка 0
	std::cout << "│";
	std::cout << sign_with_cursor_to_string(0, 0, Game::cell_0_0);
	std::cout << "│";
	std::cout << sign_with_cursor_to_string(1, 0, Game::cell_0_1);
	std::cout << "│";
	std::cout << sign_with_cursor_to_string(2, 0, Game::cell_0_2);
	std::cout << "│";
	std::cout << std::endl;

	// линия 1
	std::cout << "├───┼───┼───┤" << std::endl;

	// строка 1
	std::cout << "│";
	std::cout << sign_with_cursor_to_string(0, 1, Game::cell_1_0);
	std::cout << "│";
	std::cout << sign_with_cursor_to_string(1, 1, Game::cell_1_1);
	std::cout << "│";
	std::cout << sign_with_cursor_to_string(2, 1, Game::cell_1_2);
	std::cout << "│";
	std::cout << std::endl;

	// линия 2
	std::cout << "├───┼───┼───┤" << std::endl;

	// строка 2
	std::cout << "│";
	std::cout << sign_with_cursor_to_string(0, 2, Game::cell_2_0);
	std::cout << "│";
	std::cout << sign_with_cursor_to_string(1, 2, Game::cell_2_1);
	std::cout << "│";
	std::cout << sign_with_cursor_to_string(2, 2, Game::cell_2_2);
	std::cout << "│";
	std::cout << std::endl;

	// линия 3
	std::cout << "└───┴───┴───┘" << std::endl;
}

char sign_to_char(Sign sign) {
	switch (sign)
	{
	case X:
		return 'X';
	case O:
		return 'O';
	default:
		return ' ';
	}
}

std::string sign_with_cursor_to_string(int column, int row, Sign sign) {
	if (row == Game::cursor_row && column == Game::cursor_column)
		return std::string("[") + sign_to_char(sign) + "]";

	return std::string(" ") + sign_to_char(sign) + " ";
}
#pragma endregion
