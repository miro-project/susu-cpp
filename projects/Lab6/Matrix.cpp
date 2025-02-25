#include <iostream>
using namespace std;
class Matrix {
private:
	static const int ROWS = 2; // �������� ��� ������������
	static const int COLS = 2; // �������� ��� ������������
	int data[ROWS][COLS]; // 2D ������ ��� �������� ������ �������
public:
	// ����������� ��� ������������� ��������� ������� ������
	Matrix() {
		for (int i = 0; i < ROWS; ++i) {
			for (int j = 0; j < COLS; ++j) {
				data[i][j] = 0;
			}
		}
	}
	// ������� ��� ����� ������ �������
	void inputMatrix() {
		cout << "������� ������ ������� (" << ROWS << "x" << COLS << "):\n";
		for (int i = 0; i < ROWS; ++i) {
			for (int j = 0; j < COLS; ++j) {
				cin >> data[i][j];
			}
		}
	}
	// ���������� ��������� + ��� �������� ���� ������
	Matrix operator+(const Matrix& other) const {
		Matrix result;
		for (int i = 0; i < ROWS; ++i) {
			for (int j = 0; j < COLS; ++j) {
				result.data[i][j] = this->data[i][j] + other.data[i][j];
			}
		}
		return result;
	}
	// ������� ��� ����������� �������
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
	cout << "���� ������ ��� ������� 1:\n";
	m1.inputMatrix();
	cout << "���� ������ ��� ������� 2:\n";
	m2.inputMatrix();
	result = m1 + m2; // ������������� �������������� ��������� +
	cout << "��������� ��������:\n";
	result.display();
	return 0;
}