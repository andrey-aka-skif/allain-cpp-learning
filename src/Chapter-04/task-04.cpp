#include <iostream>
#include <string>

using namespace std;

int main()
{
	const string user1 = "john";
	const int user1_password = 4;

	const string user2 = "jane";
	const int user2_password = 8;

	string username;
	int password;

	cout << "username:" << endl;
	cin >> username;
	cout << "password:" << endl;
	cin >> password;

	if (username == user1 && password == user1_password)
	{
		cout << "Access granted" << endl;
		return 0;
	}
	else if (username == user2 && password == user2_password)
	{
		cout << "Access granted" << endl;
		return 0;
	}

	cout << "Access Denied" << endl;
	cout << "Try Again" << endl;

	cout << "username:" << endl;
	cin >> username;
	cout << "password:" << endl;
	cin >> password;

	if (username == user1 && password == user1_password)
	{
		cout << "Access granted" << endl;
		return 0;
	}
	else if (username == user2 && password == user2_password)
	{
		cout << "Access granted" << endl;
		return 0;
	}

	cout << "Access Denied" << endl;
	cout << "Try Again" << endl;
	return 1;
}
