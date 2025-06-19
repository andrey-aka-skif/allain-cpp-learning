#include <iostream>

using namespace std;

int main()
{
	const int correct_password_1 = 4;
	const int correct_password_2 = 8;

	int password;

	cout << "Enter password as number:" << endl;

	cin >> password;

	if (password == correct_password_1 || password == correct_password_2)
		cout << "Access granted" << endl;
	else
		cout << "Access Denied" << endl;
}
