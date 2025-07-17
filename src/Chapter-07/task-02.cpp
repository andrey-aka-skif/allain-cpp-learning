/*
* Alex Allain. Jumping into c++.
* Глава 7. Переключатели и перечисления
*
* 2. Напишите программу, которая которая выводит на экран весь текст песни
* The Twelve Days of Christmas с помощью оператора switch-case (совет:
* воспользуйтесь сквозным выполнением операторов case)
*/

#include <iostream>
#include <stdexcept>
#include <Windows.h>

int show_song_text_the_twelve_days_of_christmas();

int main()
{
	SetConsoleOutputCP(CP_UTF8);

	try
	{
		show_song_text_the_twelve_days_of_christmas();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

/**
 * @brief Вывод текста песниThe Twelve Days of Christmas. Реализация от нейросети
 * \return
 */
int show_song_text_the_twelve_days_of_christmas() {
	for (int day = 1; day <= 12; day++) {
		std::cout << "On the ";

		// Выводим порядковое числительное для дня
		switch (day) {
		case 1:  std::cout << "first"; break;
		case 2:  std::cout << "second"; break;
		case 3:  std::cout << "third"; break;
		case 4:  std::cout << "fourth"; break;
		case 5:  std::cout << "fifth"; break;
		case 6:  std::cout << "sixth"; break;
		case 7:  std::cout << "seventh"; break;
		case 8:  std::cout << "eighth"; break;
		case 9:  std::cout << "ninth"; break;
		case 10: std::cout << "tenth"; break;
		case 11: std::cout << "eleventh"; break;
		case 12: std::cout << "twelfth"; break;
		}

		std::cout << " day of Christmas my true love gave to me\n";

		// Выводим подарки для каждого дня, используя сквозное выполнение case
		switch (day) {
		case 12: std::cout << "Twelve drummers drumming,\n";
		case 11: std::cout << "Eleven pipers piping,\n";
		case 10: std::cout << "Ten lords a-leaping,\n";
		case 9:  std::cout << "Nine ladies dancing,\n";
		case 8:  std::cout << "Eight maids a-milking,\n";
		case 7:  std::cout << "Seven swans a-swimming,\n";
		case 6:  std::cout << "Six geese a-laying,\n";
		case 5:  std::cout << "Five golden rings,\n";
		case 4:  std::cout << "Four calling birds,\n";
		case 3:  std::cout << "Three french hens,\n";
		case 2:  std::cout << "Two turtle doves, and\n";
		case 1:  std::cout << "A partridge in a pear tree.\n";
		}

		std::cout << std::endl;
	}

	return 0;
}
