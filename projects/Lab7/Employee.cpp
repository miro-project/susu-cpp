#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "locale.h"

class Employee {
public:
	int id;
	std::string name;
	std::string department;
	Employee() : id(0) {} // Для десериализации
	Employee(int id, std::string name, std::string department)
		: id(id), name(name), department(department) {
	}
	// Сериализация данных сотрудника в строку
	std::string serialize() const {
		return std::to_string(id) + ";" + name + ";" + department;
	}
	// Десериализация строки в данные сотрудника
	void deserialize(const std::string& data) {
		size_t pos1 = data.find(';');
		size_t pos2 = data.find(';', pos1 + 1);
		id = std::stoi(data.substr(0, pos1));
		name = data.substr(pos1 + 1, pos2 - pos1 - 1);
		department = data.substr(pos2 + 1);
	}
};void writeEmployeesToFile(const std::vector<Employee>& employees, const std::string& filename) {
	std::ofstream fileOut(filename);
	for (const auto& employee : employees) {
		fileOut << employee.serialize() << std::endl;
	}
	fileOut.close();
}

void readEmployeesFromFile(std::vector<Employee>& employees, const std::string& filename) {
	std::ifstream fileIn(filename);
	std::string line;
	while (std::getline(fileIn, line)) {
		Employee emp;
		emp.deserialize(line);
		employees.push_back(emp);
	}
	fileIn.close();
}int main() {
	setlocale(LC_ALL, "Russian");
	std::vector<Employee> employees;
	employees.push_back(Employee(1, "Иван Иванов", "Разработка"));
	employees.push_back(Employee(2, "Петр Петров", "Маркетинг"));
	// Запись в файл
	writeEmployeesToFile(employees, "employees.txt");
	// Чтение из файла
	std::vector<Employee> loadedEmployees;
	readEmployeesFromFile(loadedEmployees, "employees.txt");
	// Вывод сотрудников, загруженных из файла
	for (const auto& employee : loadedEmployees) {
		std::cout << employee.id << " " << employee.name << " " << employee.department << std::endl;
	}
	return 0;
}
