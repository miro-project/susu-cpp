#include <iostream>
#include <string>

using namespace std;

class Vehicle {
private:
	string make;
	int year;
public:
	Vehicle(string m, int y) : make(m), year(y) {}
	void setMake(string m) {
		make = m;
	}
	string getMake() const {
		return make;
	}
	void setYear(int y) {
		year = y;
	}
	int getYear() const {
		return year;
	}
	virtual void displayInfo() {
		cout << "Make: " << make << ", Year: " << year << endl;
	}
};

class Car : public Vehicle {
private:
	bool isSedan;
public:
	Car(string m, int y, bool isS) : Vehicle(m, y), isSedan(isS) {}
	void setIsSedan(bool isS) {
		isSedan = isS;
	}
	bool getIsSedan() const {
		return isSedan;
	}
	void displayInfo() override {
		Vehicle::displayInfo();
		cout << "Is Sedan: " << (isSedan ? "Yes" : "No") << endl;
	}
};

class Motorcycle : public Vehicle {
private:
	bool hasSidecar;
public:
	Motorcycle(string m, int y, bool hasS) : Vehicle(m, y), hasSidecar(hasS) {}
	void setHasSidecar(bool hasS) {
		hasSidecar = hasS;
	}
	bool getHasSidecar() const {
		return hasSidecar;
	}
	void displayInfo() override {
		Vehicle::displayInfo();
		cout << "Has Sidecar: " << (hasSidecar ? "Yes" : "No") << endl;
	}
};

int main() {
	Car car1("Toyota", 2020, true);
	Motorcycle motorcycle1("Harley-Davidson", 2019, false);
	car1.displayInfo(); // Демонстрация информации о машине
	motorcycle1.displayInfo(); // Демонстрация информации о мотоцикле
	return 0;
}
