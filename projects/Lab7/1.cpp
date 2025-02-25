#include <iostream>
#include <vector>
#include "locale.h"
int main() {
	setlocale(LC_ALL, "Russian");
	// Создание вектора для хранения целых чисел
	std::vector<int> numbers;
	// Добавление элементов в вектор
	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(30);
	// Доступ к элементам с использованием оператора []
	std::cout << "Элемент с индексом 1: " << numbers[1] << std::endl;
	// Итерация по вектору с использованием цикла range-based for
	std::cout << "Содержимое вектора: ";
	for (int num : numbers) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
	return 0;
}