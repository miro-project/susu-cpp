#include <iostream>
using namespace std;
class Matrix {
private:
	static const int ROWS = 2; // Упрощено для демонстрации
	static const int COLS = 2; // Упрощено для демонстрации
	int data[ROWS][COLS]; // 2D массив для хранения данных матрицы
public:
	// Конструктор для инициализации элементов матрицы нулями
	Matrix() {
		for (int i = 0; i < ROWS; ++i) {
			for (int j = 0; j < COLS; ++j) {
				data[i][j] = 0;
			}
		}
	}
	// Функция для ввода данных матрицы
	void inputMatrix() {
		cout << "Введите данные матрицы (" << ROWS << "x" << COLS << "):\n";
		for (int i = 0; i < ROWS; ++i) {
			for (int j = 0; j < COLS; ++j) {
				cin >> data[i][j];
			}
		}
	}
	// Перегрузка оператора + для сложения двух матриц
	Matrix operator+(const Matrix& other) const {
		Matrix result;
		for (int i = 0; i < ROWS; ++i) {
			for (int j = 0; j < COLS; ++j) {
				result.data[i][j] = this->data[i][j] + other.data[i][j];
			}
		}
		return result;
	}
	// Функция для отображения матрицы
	void display() const {
		for (int i = 0; i < ROWS; ++i) {
			for (int j = 0; j < COLS; ++j) {
				cout << data[i][j] << " ";
			}
			cout << endl;
		}
	}
};
int main() {
	Matrix m1, m2, result;
	cout << "Ввод данных для Матрицы 1:\n";
	m1.inputMatrix();
	cout << "Ввод данных для Матрицы 2:\n";
	m2.inputMatrix();
	result = m1 + m2; // Использование перегруженного оператора +
	cout << "Результат сложения:\n";
	result.display();
	return 0;
}