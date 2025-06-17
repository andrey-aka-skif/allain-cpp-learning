#include <iostream>

using namespace std;

static int show_name()
{
	cout << "My name is Andrey" << endl;

	return 0;
}

static int show_multiply_lines()
{
	cout << "My friend name:"
		<< endl
		<< "John Dow";

	return 0;
}

int main()
{
	cout << "Hey, you, I'm alive!\n";

	show_name();
	show_multiply_lines();
}
