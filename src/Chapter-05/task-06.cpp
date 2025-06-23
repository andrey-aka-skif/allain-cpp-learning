/*
* Alex Allain. Jumping into c++.
* Глава 5. Циклы
*
* 6. Напишите программу, которая отображает квадраты первых 20 целых чисел.
*/

#include <iostream>

using namespace std;

int main()
{
	for (size_t i = 0; i < 20; i++)
	{
		cout << i * i << endl;
	}
}
