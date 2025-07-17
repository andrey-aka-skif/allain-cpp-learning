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
	} while (handle_input_result && is_play);

	show_final_message();
}

void show_final_message() {
	std::cout << std::endl << final_message << std::endl;
}

#pragma region Handle Logic
void check_win() {
	step_count++;
	if (step_count >= 9) {
		is_play = false;
		final_message = "Ничья";
		return;
	}

	// Проверка горизонталей
	if (cell_0_0 != EMPTY && cell_0_0 == cell_0_1 && cell_0_1 == cell_0_2) {
		is_play = false;
	}
	else if (cell_1_0 != EMPTY && cell_1_0 == cell_1_1 && cell_1_1 == cell_1_2) {
		is_play = false;
	}
	else if (cell_2_0 != EMPTY && cell_2_0 == cell_2_1 && cell_2_1 == cell_2_2) {
		is_play = false;
	}

	// Проверка вертикалей
	else if (cell_0_0 != EMPTY && cell_0_0 == cell_1_0 && cell_1_0 == cell_2_0) {
		is_play = false;
	}
	else if (cell_0_1 != EMPTY && cell_0_1 == cell_1_1 && cell_1_1 == cell_2_1) {
		is_play = false;
	}
	else if (cell_0_2 != EMPTY && cell_0_2 == cell_1_2 && cell_1_2 == cell_2_2) {
		is_play = false;
	}

	// Проверка диагоналей
	else if (cell_0_0 != EMPTY && cell_0_0 == cell_1_1 && cell_1_1 == cell_2_2) {
		is_play = false;
	}
	else if (cell_0_2 != EMPTY && cell_0_2 == cell_1_1 && cell_1_1 == cell_2_0) {
		is_play = false;
	}

	if (!is_play) {
		final_message = std::string("Победа: ") + sign_to_char(current_sign);
	}
}
#pragma endregion

#pragma region Handle Control
void handle_up() {
	if (cursor_row > 0)
		cursor_row--;
}

void handle_down() {
	if (cursor_row < 2)
		cursor_row++;
}

void handle_left() {
	if (cursor_column > 0)
		cursor_column--;
}

void handle_right() {
	if (cursor_column < 2)
		cursor_column++;
}

bool try_select() {
	if (cursor_row == 0 && cursor_column == 0 && cell_0_0 == EMPTY) {
		cell_0_0 = current_sign;
		return true;
	}
	if (cursor_row == 0 && cursor_column == 1 && cell_0_1 == EMPTY) {
		cell_0_1 = current_sign;
		return true;
	}
	if (cursor_row == 0 && cursor_column == 2 && cell_0_2 == EMPTY) {
		cell_0_2 = current_sign;
		return true;
	}

	if (cursor_row == 1 && cursor_column == 0 && cell_1_0 == EMPTY) {
		cell_1_0 = current_sign;
		return true;
	}
	if (cursor_row == 1 && cursor_column == 1 && cell_1_1 == EMPTY) {
		cell_1_1 = current_sign;
		return true;
	}
	if (cursor_row == 1 && cursor_column == 2 && cell_1_2 == EMPTY) {
		cell_1_2 = current_sign;
		return true;
	}

	if (cursor_row == 2 && cursor_column == 0 && cell_2_0 == EMPTY) {
		cell_2_0 = current_sign;
		return true;
	}
	if (cursor_row == 2 && cursor_column == 1 && cell_2_1 == EMPTY) {
		cell_2_1 = current_sign;
		return true;
	}
	if (cursor_row == 2 && cursor_column == 2 && cell_2_2 == EMPTY) {
		cell_2_2 = current_sign;
		return true;
	}

	return false;
}

void inverse_current_sign() {
	if (current_sign == X)
		current_sign = O;
	else if (current_sign == O)
		current_sign = X;
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
	case 'w'://119
	case 'W'://87
		return UP;
	case 's'://115
	case 'S'://83
		return DOWN;
	case 'a'://97
	case 'A'://65
		return LEFT;
	case 'd'://100
	case 'D'://68
		return RIGHT;
	case ' '://32
		return SELECT;
	case 'q'://113
	case 'Q'://81
		return QUITE;
	default:
		break;
	}

	// Стрелки (возвращают два кода: 224 + код стрелки)
	if (key == 224 || key == 0) {
		return get_arrow_input();
	}

	return UNKNOWN;
}

Input get_arrow_input() {
	// Стрелки (возвращают два кода: 224 + код стрелки)
	int second_key = _getch();  // Читаем второй код
	switch (second_key)
	{
	case 72:
		return UP;
	case 80:
		return DOWN;
	case 75:
		return LEFT;
	case 77:
		return RIGHT;
	default:
		return UNKNOWN;
	}
}
#pragma endregion

#pragma region Handle Drow
void clear() {
	system("cls");
}

void show_current_sign() {
	std::cout << "Сейчас ходит: " << sign_to_char(current_sign) << std::endl;
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
	std::cout << "|";
	std::cout << "---";
	std::cout << "|";
	std::cout << "---";
	std::cout << "|";
	std::cout << "---";
	std::cout << "|";
	std::cout << std::endl;

	// строка 0
	std::cout << "|";
	std::cout << sign_with_cursor_to_string(0, 0, cell_0_0);
	std::cout << "|";
	std::cout << sign_with_cursor_to_string(1, 0, cell_0_1);
	std::cout << "|";
	std::cout << sign_with_cursor_to_string(2, 0, cell_0_2);
	std::cout << "|";
	std::cout << std::endl;

	// линия 1
	std::cout << "|";
	std::cout << "---";
	std::cout << "|";
	std::cout << "---";
	std::cout << "|";
	std::cout << "---";
	std::cout << "|";
	std::cout << std::endl;

	// строка 1
	std::cout << "|";
	std::cout << sign_with_cursor_to_string(0, 1, cell_1_0);
	std::cout << "|";
	std::cout << sign_with_cursor_to_string(1, 1, cell_1_1);
	std::cout << "|";
	std::cout << sign_with_cursor_to_string(2, 1, cell_1_2);
	std::cout << "|";
	std::cout << std::endl;

	// линия 2
	std::cout << "|";
	std::cout << "---";
	std::cout << "|";
	std::cout << "---";
	std::cout << "|";
	std::cout << "---";
	std::cout << "|";
	std::cout << std::endl;

	// строка 2
	std::cout << "|";
	std::cout << sign_with_cursor_to_string(0, 2, cell_2_0);
	std::cout << "|";
	std::cout << sign_with_cursor_to_string(1, 2, cell_2_1);
	std::cout << "|";
	std::cout << sign_with_cursor_to_string(2, 2, cell_2_2);
	std::cout << "|";
	std::cout << std::endl;

	// линия 3
	std::cout << "|";
	std::cout << "---";
	std::cout << "|";
	std::cout << "---";
	std::cout << "|";
	std::cout << "---";
	std::cout << "|";
	std::cout << std::endl;
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
	if (row == cursor_row && column == cursor_column)
		return std::string("[") + sign_to_char(sign) + "]";

	return std::string(" ") + sign_to_char(sign) + " ";
}
#pragma endregion
