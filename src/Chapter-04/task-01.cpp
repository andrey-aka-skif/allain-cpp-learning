#include <iostream>

using namespace std;

int main()
{
	int user1_age;
	int user2_age;

	cout << "Please enter user 1 age: ";
	cin >> user1_age;
	cout << "Please enter user 2 age: ";
	cin >> user2_age;

	if (user1_age > 100 && user2_age > 100)
	{
		cout << "Both are too old";
		return 0;
	}

	if (user1_age > user2_age)
		cout << "1st is older";
	else
		cout << "2nd is older";
}
