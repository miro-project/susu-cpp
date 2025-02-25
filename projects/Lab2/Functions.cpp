#include <iostream>

using namespace std;

int addNumbers(int a, int b)
{
	return a + b;
}

int subtractionNumbers(int a, int b)
{
	return a - b;
}

int multiplyNumbers(int a, int b)
{
	return a * b;
}

int divideNumbers(int a, int b)
{
	return a / b;
}

int main()
{
	int num1;
	int num2;
	char operation;
	int res;

	cout << "Enter number 1: ";
	cin >> num1;
	cout << "Enter number 2: ";
	cin >> num2;
	cout << "Enter operator (+, -, *, /): ";
	cin >> operation;

	if (operation == '+')
	{
		res = addNumbers(num1, num2);
	}
	else if (operation == '-')
	{
		res = subtractionNumbers(num1, num2);
	}
	else if (operation == '*')
	{
		res = multiplyNumbers(num1, num2);
	}
	else if (operation == '/' && num2 != 0)
	{
		res = divideNumbers(num1, num2);
	}
	else
	{
		cout << "Error" << endl;
	}

	cout << "Result: " << res << endl;
}