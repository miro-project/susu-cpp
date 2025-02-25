#include <iostream>
#include <string>
using namespace std;
// Определение структуры Student
struct Student {
	string name;
	int id;
	float grades[5]; // Массив для хранения 5 оценок студента
};
// Функция для заполнения записи студента
void populateStudent(Student& s) {
	cout << "Введите имя студента: ";
	cin >> s.name;
	cout << "Введите ID студента: ";
	cin >> s.id;
	for (int i = 0; i < 5; ++i) {
		cout << "Введите оценку " << (i + 1) << ": ";
		cin >> s.grades[i];
	}
}
// Функция для отображения записи студента
void displayStudent(const Student& s) {
	cout << "Имя: " << s.name << ", ID: " << s.id << ", Оценки: ";
	for (int i = 0; i < 5; ++i) {
		cout << s.grades[i] << " ";
	}
	cout << endl;
}
// Функция для расчета и отображения средней оценки студента
void displayAverageGrade(const Student& s) {
	float sum = 0;
	for (int i = 0; i < 5; ++i) {
		sum += s.grades[i];
	}
	cout << "Средняя оценка для " << s.name << ": " << (sum / 5) << endl;
}
int main() {
	const int NUM_STUDENTS = 3; // Количество студентов
	Student students[NUM_STUDENTS]; // Массив структур Student
	// Заполнение и отображение данных каждого студента
	for (int i = 0; i < NUM_STUDENTS; ++i) {
		cout << "Студент " << (i + 1) << endl;
		populateStudent(students[i]);
		displayStudent(students[i]);
		displayAverageGrade(students[i]);
		cout << endl;
	}
	return 0;
}
