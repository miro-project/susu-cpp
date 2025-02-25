#include <iostream>
#include <string>
using namespace std;
// ����������� ��������� Student
struct Student {
	string name;
	int id;
	float grades[5]; // ������ ��� �������� 5 ������ ��������
};
// ������� ��� ���������� ������ ��������
void populateStudent(Student& s) {
	cout << "������� ��� ��������: ";
	cin >> s.name;
	cout << "������� ID ��������: ";
	cin >> s.id;
	for (int i = 0; i < 5; ++i) {
		cout << "������� ������ " << (i + 1) << ": ";
		cin >> s.grades[i];
	}
}
// ������� ��� ����������� ������ ��������
void displayStudent(const Student& s) {
	cout << "���: " << s.name << ", ID: " << s.id << ", ������: ";
	for (int i = 0; i < 5; ++i) {
		cout << s.grades[i] << " ";
	}
	cout << endl;
}
// ������� ��� ������� � ����������� ������� ������ ��������
void displayAverageGrade(const Student& s) {
	float sum = 0;
	for (int i = 0; i < 5; ++i) {
		sum += s.grades[i];
	}
	cout << "������� ������ ��� " << s.name << ": " << (sum / 5) << endl;
}
int main() {
	const int NUM_STUDENTS = 3; // ���������� ���������
	Student students[NUM_STUDENTS]; // ������ �������� Student
	// ���������� � ����������� ������ ������� ��������
	for (int i = 0; i < NUM_STUDENTS; ++i) {
		cout << "������� " << (i + 1) << endl;
		populateStudent(students[i]);
		displayStudent(students[i]);
		displayAverageGrade(students[i]);
		cout << endl;
	}
	return 0;
}
