#include <iostream>
#include <cmath>

using namespace std;

bool checkPrime(int value)
{
	if (value < 2)
		return false;
	for (int divisor = 2; divisor <= sqrt(value); ++divisor)
	{
		if (value % divisor == 0)
			return false;
	}
	return true;
}

void displayMultiplicationTable(int value)
{
	cout << "Multiplication Table for " << value << ":" << endl;
	for (int multiplier = 1; multiplier <= 10; ++multiplier)
	{
		cout << value << " x " << multiplier << " = " << (value * multiplier) << endl;
	}
	cout << "--------------------" << endl;
}

int main()
{
	int input;

	for (int count = 0; count < 5; ++count)
	{
		cout << "Input a number: ";
		cin >> input;

		if (checkPrime(input))
		{
			cout << "Number " << input << " is a prime number." << endl;
		}
		else
		{
			cout << "Number " << input << " is not a prime number." << endl;
		}

		displayMultiplicationTable(input);
	}

	return 0;
}
