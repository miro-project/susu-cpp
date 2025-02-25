#include <iostream>
#include <string>
class Person {
public:
	std::string name;
	int age;
	//  онструктор по умолчанию
	Person() : name("Unknown"), age(0) {}
	// ѕараметризованный конструктор
	Person(std::string n, int a) : name(n), age(a) {}
};//int main() {
//	// »спользование конструктора по умолчанию
//	Person person1;
//	std::cout << "Person 1: " << person1.name << ", " << person1.age << std::endl;
//	// »спользование параметризованного конструктора
//	Person person2("John Doe", 30);
//	std::cout << "Person 2: " << person2.name << ", " << person2.age << std::endl;
//	return 0;
//}