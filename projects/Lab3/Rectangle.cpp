#include <iostream>

using namespace std;

class Rectangle {
public:
	// Member Variables
	double length;
	double width;
	// Constructor
	Rectangle(double l, double w) : length(l), width(w) {}
	// Method to calculate area
	double calculateArea() {
		return length * width;
	}
	// Method to calculate perimeter
	double calculatePerimeter() {
		return 2 * (length + width);
	}
	// Method to check if it is a square
	bool isSquare() {
		return length == width;
	}
};

//int main() {
//	// Creating Rectangle objects
//	Rectangle rect1(10.5, 5.5);
//	Rectangle rect2(7.0, 7.0);
//
//	// Performing operations on rect1
//	cout << "Rectangle 1 Area: " << rect1.calculateArea() << endl;
//	cout << "Rectangle 1 Perimeter: " << rect1.calculatePerimeter() << endl;
//	cout << "Is Rectangle 1 a Square?: " << (rect1.isSquare() ? "Yes" : "No") << endl;
//
//	// Performing operations on rect2
//	cout << "\nRectangle 2 Area: " << rect2.calculateArea() << endl;
//	cout << "Rectangle 2 Perimeter: " << rect2.calculatePerimeter() << endl;
//	cout << "Is Rectangle 2 a Square?: " << (rect2.isSquare() ? "Yes" : "No") << endl;
//
//	return 0;
//}