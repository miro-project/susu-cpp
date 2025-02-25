#include <iostream>
#include <list>
#include "locale.h"
int main() {
	setlocale(LC_ALL, "Russian");
	// Создание списка для хранения целых чисел
	std::list<int> numbers;
	// Добавление элементов в список
	numbers.push_back(10); // Добавление в конец списка
	numbers.push_back(20);
	numbers.push_front(5); // Добавление в начало списка
	// Итерация по списку с использованием итератора для доступа к элементам
	std::cout << "Содержимое списка: ";
	for (auto it = numbers.begin(); it != numbers.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	// Удаление элемента из списка
	numbers.remove(20); // Удаление всех вхождений элемента со значением 20
	// Повторная итерация по списку для вывода его содержимого после удаления элемента
	std::cout << "Содержимое списка после удаления элемента: ";
	for (int num : numbers) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
	return 0;
}
