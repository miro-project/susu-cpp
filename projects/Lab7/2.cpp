#include <iostream>
#include <list>
#include "locale.h"
int main() {
	setlocale(LC_ALL, "Russian");
	// �������� ������ ��� �������� ����� �����
	std::list<int> numbers;
	// ���������� ��������� � ������
	numbers.push_back(10); // ���������� � ����� ������
	numbers.push_back(20);
	numbers.push_front(5); // ���������� � ������ ������
	// �������� �� ������ � �������������� ��������� ��� ������� � ���������
	std::cout << "���������� ������: ";
	for (auto it = numbers.begin(); it != numbers.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	// �������� �������� �� ������
	numbers.remove(20); // �������� ���� ��������� �������� �� ��������� 20
	// ��������� �������� �� ������ ��� ������ ��� ����������� ����� �������� ��������
	std::cout << "���������� ������ ����� �������� ��������: ";
	for (int num : numbers) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
	return 0;
}
