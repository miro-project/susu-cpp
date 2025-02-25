#include <iostream>
#include <map>
#include <string>
#include "locale.h"
int main() {
	setlocale(LC_ALL, "Russian");
	// �������� �����, ��� ���� - ������, � �������� - int
	std::map<std::string, int> ageMap;
	// ���������� ��� ����-�������� � �����
	ageMap["����"] = 25;
	ageMap["�����"] = 30;
	ageMap["�������"] = 28;
	// ����� �������� � ����� �� ����� � ����� ��� ��������
	std::string name = "�����";
	if (ageMap.find(name) != ageMap.end()) {
		std::cout << "������� " << name << ": " << ageMap[name] << std::endl;
	}
	else {
		std::cout << name << " �� ������ � �����." << std::endl;
	}
	// �������� �� ����� � ����� ���� ��� ����-��������
	std::cout << "���� ������ ���������:" << std::endl;
	for (const auto& pair : ageMap) {
		std::cout << pair.first << ": " << pair.second << std::endl;
	}
	return 0;
}