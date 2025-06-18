#include <iostream>
using namespace std;
int main()
{
	double dividend;
	double divider;
	cout << "dividend: \n";
	cin >> dividend;
	/*
	* При вводе текста cin будет содержать ошибку, но не выбросит исключение.
	* При этом мы сразу попадем в последнюю строку (вычисление суммы) без запроса второго аргумента.
	* Костыльное решение - использовать сброс ошибки.
	* cin.clear();
	* cin.ignore(numeric_limits<streamsize>::max(), '\n');
	* Но в рамках задачи это бессмысленное усложнение
	*/
	cout << "divider: \n";
	cin >> divider;
	cout << "quotient = " << dividend / divider << endl;
}
