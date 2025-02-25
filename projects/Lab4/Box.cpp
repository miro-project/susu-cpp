#include <iostream>
#include <Windows.h>

class Box {
public:
	double length;
	double width;
	double height;
	// ����������������� �����������
	Box(double l, double w, double h) : length(l), width(w), height(h) {}
	// ���������� �����������
	Box(const Box& b) : length(b.length), width(b.width), height(b.height) {
		std::cout << "������ ���������� �����������" << std::endl;
	}
	// ������� ��� ����������� ��������
	void display() const {
		std::cout << "�����: " << length << ", ������: " << width << ", ������: " << height << std::endl;
	}
};//int main() {
//	SetConsoleOutputCP(1251);
//	// �������� ������� Box � �������������� ������������������ ������������
//	Box box1(10.5, 8.3, 2.4);
//	std::cout << "������� Box 1: ";
//	box1.display();
//	// �������� ������� ������� Box ��� ����� �������
//	Box box2 = box1; // �������� ���������� �����������
//	std::cout << "������� Box 2 (����������� �� Box 1): ";
//	box2.display();
//	return 0;
//}