/*
* Alex Allain. Jumping into c++.
* Глава 5. функции
*
* 3. Измените написанную ранее программу ввода пароля так,
* чтобы проверка пароля выполнялась в специальной функции
* отдельно от остальной части программы.
*/

#include <iostream>
#include <stdexcept>
#include <Windows.h>

int input_password(int max_attempts = 3);
bool validate_password(int password);

int main() {
	SetConsoleOutputCP(CP_UTF8);

	input_password(2);
}

int input_password(int max_attempts) {
	int password;

	for (size_t i = 0; i < max_attempts; i++)
	{
		std::cout << "Введите пароль:" << std::endl;
		std::cin >> password;
		if (validate_password(password)) {
			std::cout << "Пароль принят!" << std::endl;
			return 0;
		}
		std::cout << "Неверный пароль. Осталось попыток: " << max_attempts - i - 1 << std::endl;
	}

	std::cout << "Превышено максимальное количество попыток. Доступ запрещен." << std::endl;
	return 1;
}

bool validate_password(int password) {
	int const VALID_PASSWORD = 1234;

	if (password == VALID_PASSWORD)
		return true;

	return false;
}
