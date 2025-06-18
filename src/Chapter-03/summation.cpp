#include <iostream>
using namespace std;
int main()
{
	double number1;
	double number2;
	cout << "First number: \n";
	cin >> number1;
	/*
	* При вводе текста cin будет содержать ошибку, но не выбросит исключение.
	* При этом мы сразу попадем в последнюю строку (вычисление суммы) без запроса второго аргумента.
	* Костыльное решение - использовать сброс ошибки.
	* cin.clear();
	* cin.ignore(numeric_limits<streamsize>::max(), '\n');
	* Но в рамках задачи это бессмысленное усложнение
	*/
	cout << "Second number: \n";
	cin >> number2;
	cout << "Sum = " << number1 + number2 << endl;
}
