#include <iostream>
using namespace std;
int main()
{
	double dividend;
	double divider;
	cout << "dividend: \n";
	cin >> dividend;
	/*
	* ��� ����� ������ cin ����� ��������� ������, �� �� �������� ����������.
	* ��� ���� �� ����� ������� � ��������� ������ (���������� �����) ��� ������� ������� ���������.
	* ���������� ������� - ������������ ����� ������.
	* cin.clear();
	* cin.ignore(numeric_limits<streamsize>::max(), '\n');
	* �� � ������ ������ ��� ������������� ����������
	*/
	cout << "divider: \n";
	cin >> divider;
	cout << "quotient = " << dividend / divider << endl;
}
