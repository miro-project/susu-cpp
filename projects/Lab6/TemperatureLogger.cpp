#include <iostream>
#include <Windows.h>

using namespace std;
class TemperatureLogger {
private:
	int* temperatures; // ��������� �� ������ ����������
	int capacity; // ������������ ���������� ���������
	int numReadings; // ������� ���������� ���������
public:
	// �����������
	TemperatureLogger(int cap) : capacity(cap), numReadings(0) {
		temperatures = new int[capacity]; // ������������ ��������� ������
		for (int i = 0; i < capacity; ++i) {
			temperatures[i] = 0;
		}
	}
	// ����������
	~TemperatureLogger() {
		delete[] temperatures; // ������������ ���������� ������
	}
	// ����� ��� ���������� ��������� �����������
	void addReading(int temp) {
		if (numReadings < capacity) {
			temperatures[numReadings++] = temp;
		}
		else {
			cout << "���������� ������������ �������, �������� ������ ��������� ����������." << endl;
		}
	}
	// ����� ��� ������� ������� �����������
	double calculateAverage() const {
		if (numReadings == 0) return 0; // �������������� ������� �� ����
		int sum = 0;
		for (int i = 0; i < numReadings; ++i) {
			sum += temperatures[i];
		}
		return static_cast<double>(sum) / numReadings;
	}
	// ������ ������ (findMaxTemperature, findMinTemperature) �������� ������������ � ������� ��� ���������
};
int main() {
	SetConsoleOutputCP(1251);

	TemperatureLogger logger(365); // �������� ������� logger � �������� ��� 365 ���������
	// ������ �������������
	logger.addReading(23);
	logger.addReading(25);
	// ���������� �������������� ��������� �� ���� �������������...
	cout << "������� �����������: " << logger.calculateAverage() << endl;
	return 0;
}
