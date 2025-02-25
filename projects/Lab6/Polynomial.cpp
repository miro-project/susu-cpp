#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Polynomial
{
private:
	int *coeffs;
	int degree;

public:
	Polynomial() : degree(0)
	{
		coeffs = new int[degree + 1]();
	}

	Polynomial(int deg) : degree(deg)
	{
		coeffs = new int[degree + 1]();
	}

	~Polynomial()
	{
		delete[] coeffs;
	}

	void setDegree(int deg)
	{
		delete[] coeffs;
		degree = deg;
		coeffs = new int[degree + 1]();
	}

	int getDegree() const
	{
		return degree;
	}

	void setCoefficient(int index, int value)
	{
		if (index >= 0 && index <= degree)
			coeffs[index] = value;
	}

	int getCoefficient(int index) const
	{
		return (index >= 0 && index <= degree) ? coeffs[index] : 0;
	}

	void inputCoefficients()
	{
		for (int i = degree; i >= 0; --i)
		{
			cout << "Введите коэффициент для x^" << i << ": ";
			cin >> coeffs[i];
		}
	}

	int evaluate(int x) const
	{
		int result = 0;
		for (int i = degree; i >= 0; --i)
		{
			result += coeffs[i] * static_cast<int>(pow(x, i));
		}
		return result;
	}

	void displayValue(int x) const
	{
		cout << "Значение многочлена при x = " << x << ": " << evaluate(x) << endl;
	}

	Polynomial operator+(const Polynomial &other) const
	{
		int maxDegree = max(degree, other.degree);
		Polynomial sum(maxDegree);

		for (int i = 0; i <= maxDegree; ++i)
		{
			sum.setCoefficient(i, getCoefficient(i) + other.getCoefficient(i));
		}

		return sum;
	}

	void print() const
	{
		cout << "Многочлен: ";
		for (int i = degree; i >= 0; --i)
		{
			if (coeffs[i] != 0)
			{
				cout << coeffs[i] << "x^" << i;
				if (i > 0)
					cout << " + ";
			}
		}
		cout << endl;
	}
};

int main()
{
	Polynomial poly1(2);
	poly1.inputCoefficients();
	poly1.print();
	poly1.displayValue(2);

	cout << endl;

	Polynomial poly2(5);
	poly2.inputCoefficients();
	poly2.print();

	cout << endl;

	Polynomial result = poly1 + poly2;
	result.print();
	result.displayValue(2);

	return 0;
}