#include <iostream>
#include <cmath> // For additional operations in overloaded method
class Calculator {
private:
	char operation;
public:
	// Constructor
	Calculator(char op) : operation(op) {}

	// Method to perform operation on two doubles
	void calculate(double a, double b) const {
		switch (operation) {
		case '+':
			std::cout << a << " + " << b << " = " << (a + b) << std::endl;
			break;
		case '-':
			std::cout << a << " - " << b << " = " << (a - b) << std::endl;
			break;
		case '*':
			std::cout << a << " * " << b << " = " << (a * b) << std::endl;
			break;
		case '/':
			if (b != 0) std::cout << a << " / " << b << " = " << (a / b) << std::endl;
			else std::cout << "Division by zero!" << std::endl;
			break;
		default:
			std::cout << "Invalid operation" << std::endl;
		}
	}
	// Overloaded method to perform a unary operation (e.g., square root)
	void calculate(double a) const {
		switch (operation) {
		case 's': // Assuming 's' for square root
			std::cout << "sqrt(" << a << ") = " << sqrt(a) << std::endl;
			break;
		default:
			std::cout << "Invalid operation for a single operand" << std::endl;
		}
	}
};

int main() {
	Calculator add('+');
	Calculator subtract('-');
	Calculator multiply('*');
	Calculator divide('/');
	Calculator sqrt('s'); // Unary operation calculator
	double a = 10.5, b = 2.5;
	add.calculate(a, b);
	subtract.calculate(a, b);
	multiply.calculate(a, b);
	divide.calculate(a, b);
	sqrt.calculate(a); // Demonstrating overloaded method usage
	return 0;
}
