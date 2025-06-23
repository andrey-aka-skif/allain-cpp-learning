/*
* Alex Allain. Jumping into c++.
* Глава 5. Циклы
*
* 7. Напишите программу, которая подсчитывает результаты опроса с тремя
* возможными значениями. Первым входным параметром программы
* является вопрос, остальные три параметра - варианты ответа на него.
* Первому ответу соответствует число 1, второму - число 2, третьему - число 3.
* Ответы принимаются, пока не будет введен 0. После этого
* программа отображает результаты опроса. Создайте столбчатую диаграмму,
* которая показывает правильно масштабированные результаты независимо
* от количества введенных результатов.
*/

#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main()
{
	SetConsoleOutputCP(CP_UTF8);

	string question;
	string answer1;
	string answer2;
	string answer3;

	int selected_answer;

	int answer1_count = 0;
	int answer2_count = 0;
	int answer3_count = 0;

	cout << "Вопрос: ";
	cin >> question;

	cout << "Варианты:" << endl;

	cout << "1. ";
	cin >> answer1;
	cout << endl;

	cout << "2. ";
	cin >> answer2;
	cout << endl;

	cout << "3. ";
	cin >> answer3;
	cout << endl;

	cout << "Вводите ответы (1-3), 0 для завершения:" << endl;

	while (true)
	{
		cin >> selected_answer;

		if (selected_answer == 0)
			break;
		else if (selected_answer == 1)
			answer1_count++;
		else if (selected_answer == 2)
			answer2_count++;
		else if (selected_answer == 3)
			answer3_count++;
		else
			cout << "Выберите вариант от 1 до 3" << endl;
	}

	cout << endl;
	cout << "Результаты:" << endl;

	cout << "1. " << answer1 << ": " << answer1_count << endl;
	cout << "2. " << answer2 << ": " << answer2_count << endl;
	cout << "3. " << answer3 << ": " << answer3_count << endl;

	cout << endl;
	cout << "Диаграмма:" << endl;

	cout << "1. ";
	for (size_t i = 0; i < answer1_count; i++)
	{
		cout << "#";
	}
	cout << endl;

	cout << "2. ";
	for (size_t i = 0; i < answer2_count; i++)
	{
		cout << "#";
	}
	cout << endl;

	cout << "3. ";
	for (size_t i = 0; i < answer3_count; i++)
	{
		cout << "#";
	}
	cout << endl;
}
