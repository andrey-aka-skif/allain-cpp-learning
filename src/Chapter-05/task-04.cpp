/*
* Alex Allain. Jumping into c++.
* Глава 5. Циклы
*
* 4. Напишите программу, которая запрашивает у пользователя пароль
* с ограниченным числом попыток ввода, чтобы пользователь не мог
* легко создать программу для взлома пароля.
*/

#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(CP_UTF8);

	int const valid_password = 1234;
	int const max_attempts = 3;

	int password;

	for (size_t i = 0; i < max_attempts; i++)
	{
		cout << "Введите пароль:" << endl;
		cin >> password;
		if (password == valid_password) {
			cout << "Пароль принят!" << endl;
			return 0;
		}
		cout << "Неверный пароль. Осталось попыток: " << max_attempts - i - 1 << endl;
	}

	cout << "Превышено максимальное количество попыток. Доступ запрещен." << endl;
	return 1;
}

