#include <iostream>
#include <windows.h>

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int n = 0;
	int sum = 0;
	int i = 1;
	std::cout << "��������� ��� ����������� ����� �� 1 �� n" << std::endl;
	std::cout << "������� ����� n: ";
	std::cin >> n;

	int choice = 1;
	std::cout << "�������� ��� ����� (1 - for, 2 - while, 3 - do-while): ";
	std::cin >> choice;

	switch (choice) {
		case 1:
			for (i; i <= n; i++) {
				sum += i;
			}
			std::cout << "����� ����� �� 1 �� " << n << " ����� " << sum << std::endl;
			break;

		case 2:
			while (i <= n) {
				sum += i;
				i++;
			}
			std::cout << "����� ����� �� 1 �� " << n << " ����� " << sum << std::endl;
			break;
		
		case 3:
			do {
				sum += i;
				i++;
			} while (i <= n);
			std::cout << "����� ����� �� 1 �� " << n << " ����� " << sum << std::endl;
			break;

		default:
			std::cout << "������������ �����." << std::endl;
			break;
	}

	return 0;
}
