#include <iostream>
#include <map>
#include <string>
#include "locale.h"

class Product {
public:
	int productID;
	std::string productName;
	double price;
	Product(int productID, std::string productName, double price)
		: productID(productID), productName(productName), price(price) {
	}
	virtual void display() {
		std::cout << "Product ID: " << productID << ", Name: " << productName << ", Price: " << price <<
			std::endl;
	}
};class Electronics : public Product {
public:
	Electronics(int productID, std::string productName, double price)
		: Product(productID, productName, price) {
	}
	void display() override {
		Product::display();
		std::cout << "Category: Electronics" << std::endl;
	}
};

class Clothing : public Product {
public:
	Clothing(int productID, std::string productName, double price)
		: Product(productID, productName, price) {
	}
	void display() override {
		Product::display();
		std::cout << "Category: Clothing" << std::endl;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	std::map<int, std::pair<Product*, int>> inventory;
	// Добавление продуктов в инвентарь
	inventory[1] = std::make_pair(new Electronics(1, "Smartphone", 500.0), 10);
	inventory[2] = std::make_pair(new Clothing(2, "T-Shirt", 20.0), 50);
	// Вывод инвентаря
	for (const auto& item : inventory) {
		std::cout << "Stock: " << item.second.second << " ";
		item.second.first->display();
	}
	// Очистка памяти
	for (auto& item : inventory) {
		delete item.second.first;
	}
	return 0;
}