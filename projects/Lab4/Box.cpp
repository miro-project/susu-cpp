#include <iostream>
#include <Windows.h>

class Box {
public:
	double length;
	double width;
	double height;
	// Параметризованный конструктор
	Box(double l, double w, double h) : length(l), width(w), height(h) {}
	// Копирующий конструктор
	Box(const Box& b) : length(b.length), width(b.width), height(b.height) {
		std::cout << "Вызван копирующий конструктор" << std::endl;
	}
	// Функция для отображения размеров
	void display() const {
		std::cout << "Длина: " << length << ", Ширина: " << width << ", Высота: " << height << std::endl;
	}
};//int main() {
//	SetConsoleOutputCP(1251);
//	// Создание объекта Box с использованием параметризованного конструктора
//	Box box1(10.5, 8.3, 2.4);
//	std::cout << "Размеры Box 1: ";
//	box1.display();
//	// Создание другого объекта Box как копии первого
//	Box box2 = box1; // Вызывает копирующий конструктор
//	std::cout << "Размеры Box 2 (скопированы из Box 1): ";
//	box2.display();
//	return 0;
//}