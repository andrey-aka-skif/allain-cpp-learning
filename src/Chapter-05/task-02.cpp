/*
* Alex Allain. Jumping into c++.
* Глава 5. Циклы
* 
* 2. Напишите программу-меню, которая предлагает пользователю выбрать
* один вариант списка. Если пользователь вводит вариант, которого
* нет в списке, список выводится заново
*/

#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(CP_UTF8);

	int selected;

	do
	{
		cout << "1. Выбор первого элемента" << endl;
		cout << "2. Выбор второго элемента" << endl;
		cout << "3. Выбор третьего элемента" << endl;
		cout << endl;
		cout << "Выберите пункт меню (укажите номер):" << endl;
		cin >> selected;
		cout << endl;

	} while (selected < 1 || selected > 3);

	cout << "Выбран пункт [" << selected << "]" << endl;
}
