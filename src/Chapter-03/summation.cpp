#include <iostream>
using namespace std;
int main()
{
	double number1;
	double number2;
	cout << "First number: \n";
	cin >> number1;
	/*
	* ��� ����� ������ cin ����� ��������� ������, �� �� �������� ����������.
	* ��� ���� �� ����� ������� � ��������� ������ (���������� �����) ��� ������� ������� ���������.
	* ���������� ������� - ������������ ����� ������.
	* cin.clear();
	* cin.ignore(numeric_limits<streamsize>::max(), '\n');
	* �� � ������ ������ ��� ������������� ����������
	*/
	cout << "Second number: \n";
	cin >> number2;
	cout << "Sum = " << number1 + number2 << endl;
}
