#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
	const char addition_operation_sign = '+';
	const char subtraction_operation_sign = '-';
	const char multiplication_operation_sign = '*';
	const char division_operation_sign = '/';

	char operation_sign;
	int operand1;
	int operand2;

	try
	{
		cout << "Enter operation sign:" << endl;
		cin >> operation_sign;

		if (operation_sign != addition_operation_sign
			&& operation_sign != subtraction_operation_sign
			&& operation_sign != multiplication_operation_sign
			&& operation_sign != division_operation_sign)
		{
			throw invalid_argument("Invalid operation sign!");
		}

		cout << "Enter operand 1:" << endl;
		cin >> operand1;

		cout << "Enter operand 2:" << endl;
		cin >> operand2;

		float result;

		cout << "'" << operation_sign << "'" << endl;

		if (operation_sign == addition_operation_sign)
			result = operand1 + operand2;
		else if (operation_sign == subtraction_operation_sign)
			result = operand1 - operand2;
		else if (operation_sign == multiplication_operation_sign)
			result = operand1 * operand2;
		else if (operation_sign == division_operation_sign)
		{
			if (operand2 == 0)
				throw runtime_error("Division by zero!");

			result = static_cast<float>(operand1) / operand2;
		}

		cout << result << endl;
	}
	catch (const std::exception& e)
	{
		cerr << "Error: " << e.what() << endl;
	}

	return 0;
}
