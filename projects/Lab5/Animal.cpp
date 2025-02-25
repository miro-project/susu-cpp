#include <iostream>
#include <string>

using namespace std;

class Animal
{
protected:
	string name;
	int age;

public:
	Animal() : name("Неизвестно"), age(0) {}

	Animal(string s, int l) : name(s), age(l) {}

	virtual void produceSound()
	{
		cout << "Это животное делает звук.";
	}
};

class Dog : public Animal
{
public:
	Dog() : Animal() {}

	Dog(string s, int l) : Animal(s, l) {}

	void produceSound() override
	{
		cout << "Собака гавкает.";
	}
};

class Cat : public Animal
{
public:
	Cat() : Animal() {}

	Cat(string s, int l) : Animal(s, l) {}

	void produceSound() override
	{
		cout << "Кошка мяукает.";
	}
};

int main()
{
	Dog dog("Собачка", 5);
	Cat cat("Кошка", 4);
	Animal animal("Кошка", 4);

	dog.produceSound();
	cat.produceSound();
	animal.produceSound();

	return 0;
}
