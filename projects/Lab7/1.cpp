#include <iostream>
#include <vector>
#include "locale.h"
int main() {
	setlocale(LC_ALL, "Russian");
	// �������� ������� ��� �������� ����� �����
	std::vector<int> numbers;
	// ���������� ��������� � ������
	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(30);
	// ������ � ��������� � �������������� ��������� []
	std::cout << "������� � �������� 1: " << numbers[1] << std::endl;
	// �������� �� ������� � �������������� ����� range-based for
	std::cout << "���������� �������: ";
	for (int num : numbers) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
	return 0;
}