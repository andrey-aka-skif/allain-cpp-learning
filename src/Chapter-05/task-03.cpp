/*
* Alex Allain. Jumping into c++.
* Глава 5. Циклы
*
* 3. Напишите программу, которая накапливает сумму чисел, вводимых пользователем.
* Программа завершает работу, если пользователь вводит ноль.
*/

#include <iostream>

using namespace std;

int main()
{
	int sum = 0;
	int number;

	while (true)
	{
		cin >> number;

		if (number == 0)
			break;

		sum += number;

		cout << "sum: " << sum << endl;
	}
}
