#include <iostream>
#include <string>
using namespace std;
class Person {
protected: // ���������� ����� ������
	string name;
	int age;
public:
	Person(string n, int a) : name(n), age(a) {}
	void display() {
		cout << "Name: " << name << ", Age: " << age << endl;
	}
};
class Student : public Person {
protected: // �������������� ���������� ����� ����������� ��� ��������
	string studentID;
public:
	Student(string n, int a, string id) : Person(n, a), studentID(id) {}
	void display() {
		Person::display(); // ����� ������ display �������� ������
		cout << "Student ID: " << studentID << endl;
	}
};
class Teacher : public Person {
protected: // �������������� ���������� ����� ����������� ��� �������
	string subject;
public:
	Teacher(string n, int a, string sub) : Person(n, a), subject(sub) {}
	void display() {
		Person::display(); // ����� ������ display �������� ������
		cout << "Teaches: " << subject << endl;
	}
};
int main() {
	Student student1("Alice", 20, "S12345");
	Teacher teacher1("Bob", 45, "Mathematics");
	student1.display();
	cout << "----------------" << endl;
	teacher1.display();
	return 0;
}