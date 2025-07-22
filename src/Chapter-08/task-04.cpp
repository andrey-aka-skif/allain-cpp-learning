/*
* Alex Allain. Jumping into c++.
* Глава 8. Случайные числа и отладка
*
* 4. Создайте эмулятор игрового автомата, который отображает игроку
* случайные результаты с помощью как минимум трех различных значений на каждом барабане.
* Можете не выводить надпись типа "барабан вращается"; просто генерируйте результат,
* отобразите его и определите размер выигрыша (для этого задайте выиграшные комбинации).
*/

#include <iostream>
#include <Windows.h>

void run_slot_machine();
int get_rnd_value(int low, int high);

int main() {
	SetConsoleOutputCP(CP_UTF8);

	try
	{
		run_slot_machine();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void run_slot_machine() {
	int const MIN_VALUE = 1;
	int const MAX_VALUE = 3;

	int value1 = 0;
	int value2 = 0;
	int value3 = 0;

	int const WIN_1_VALUE = 111;
	int const WIN_2_VALUE = 222;
	int const WIN_3_VALUE = 333;

	int const WIN_1_PRICE = 10;
	int const WIN_2_PRICE = 20;
	int const WIN_3_PRICE = 30;

	srand(time(NULL));
	value1 = get_rnd_value(MIN_VALUE, MAX_VALUE);
	value2 = get_rnd_value(MIN_VALUE, MAX_VALUE);
	value3 = get_rnd_value(MIN_VALUE, MAX_VALUE);

	int value = 100 * value1 + 10 * value2 + value3;

	std::cout << "Выпало:" << value << std::endl;

	if (value == WIN_1_VALUE)
		std::cout << "Выигрыш:" << WIN_1_PRICE << std::endl;
	else if (value == WIN_2_VALUE)
		std::cout << "Выигрыш:" << WIN_2_PRICE << std::endl;
	else if (value == WIN_3_VALUE)
		std::cout << "Выигрыш:" << WIN_3_PRICE << std::endl;
	else
		std::cout << "Потрачено" << std::endl;
}

static int get_rnd_value(int low, int high) {
	return rand() % (high - low + 1) + low;
}
