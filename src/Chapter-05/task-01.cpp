#include <iostream>

using namespace std;

int main() {
	for (int i = 99; i > 0; i--) {
		if (i > 1) {
			cout << i
				<< " bottles of beer on the wall, "
				<< i
				<< " bottles of beer." << endl
				<< "Take one down & pass it around, now there's "
				<< i - 1
				<< " bottles of beer on the wall"
				<< endl;
		}
		else
		{
			cout << i
				<< " bottle of beer on the wall, "
				<< i
				<< " bottles of beer." << endl
				<< "Take one down & pass it around, now there's no more bottles of beer on the wall!"
				<< endl;
		}
	}
}
