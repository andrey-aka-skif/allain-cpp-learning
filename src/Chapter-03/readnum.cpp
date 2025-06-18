#include <iostream>
using namespace std;
int main()
{
	int this_is_a_number;
	cout << "Please enter a number: ";
	cin >> this_is_a_number;
	cout << "You entered: " << this_is_a_number << "\n";
	cin.ignore();
	cin.get();
}
