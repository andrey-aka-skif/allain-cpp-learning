/*
* Alex Allain. Jumping into c++.
* Глава 8. Случайные числа и отладка
*
* 1. Напишите программу, которая имитирует подбрасывание монеты.
*/

#include <Windows.h>
#include <iostream>

void run_coin_tosser();
int get_rnd_coin_value();
int get_rnd_value(int low, int high);

int main() {
	SetConsoleOutputCP(CP_UTF8);

	try
	{
		run_coin_tosser();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void run_coin_tosser() {
	srand(time(NULL));

	int value = get_rnd_coin_value();

	if (value == 0)
		std::cout << "Решка";
	else if (value == 1)
		std::cout << "Орёл";
	else
		throw std::runtime_error("На ребро...");
}

int get_rnd_coin_value() {
	return get_rnd_value(0, 1);
}

int get_rnd_value(int low, int high) {
	return rand() % (high - low + 1) + low;
}
