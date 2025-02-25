#include <iostream>
#include <map>
#include <string>
#include "locale.h"
int main() {
	setlocale(LC_ALL, "Russian");
	// Создание карты, где ключ - строка, а значение - int
	std::map<std::string, int> ageMap;
	// Добавление пар ключ-значение в карту
	ageMap["Иван"] = 25;
	ageMap["Елена"] = 30;
	ageMap["Алексей"] = 28;
	// Поиск элемента в карте по ключу и вывод его значения
	std::string name = "Елена";
	if (ageMap.find(name) != ageMap.end()) {
		std::cout << "Возраст " << name << ": " << ageMap[name] << std::endl;
	}
	else {
		std::cout << name << " не найден в карте." << std::endl;
	}
	// Итерация по карте и вывод всех пар ключ-значение
	std::cout << "Весь список возрастов:" << std::endl;
	for (const auto& pair : ageMap) {
		std::cout << pair.first << ": " << pair.second << std::endl;
	}
	return 0;
}