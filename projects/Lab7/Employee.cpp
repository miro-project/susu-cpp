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
	Employee() : id(0) {} // ��� ��������������
	Employee(int id, std::string name, std::string department)
		: id(id), name(name), department(department) {
	}
	// ������������ ������ ���������� � ������
	std::string serialize() const {
		return std::to_string(id) + ";" + name + ";" + department;
	}
	// �������������� ������ � ������ ����������
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
	employees.push_back(Employee(1, "���� ������", "����������"));
	employees.push_back(Employee(2, "���� ������", "���������"));
	// ������ � ����
	writeEmployeesToFile(employees, "employees.txt");
	// ������ �� �����
	std::vector<Employee> loadedEmployees;
	readEmployeesFromFile(loadedEmployees, "employees.txt");
	// ����� �����������, ����������� �� �����
	for (const auto& employee : loadedEmployees) {
		std::cout << employee.id << " " << employee.name << " " << employee.department << std::endl;
	}
	return 0;
}
