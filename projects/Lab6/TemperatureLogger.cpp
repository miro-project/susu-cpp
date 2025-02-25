#include <iostream>
#include <Windows.h>

using namespace std;
class TemperatureLogger {
private:
	int* temperatures; // Указатель на массив температур
	int capacity; // Максимальное количество показаний
	int numReadings; // Текущее количество показаний
public:
	// Конструктор
	TemperatureLogger(int cap) : capacity(cap), numReadings(0) {
		temperatures = new int[capacity]; // Динамическое выделение памяти
		for (int i = 0; i < capacity; ++i) {
			temperatures[i] = 0;
		}
	}
	// Деструктор
	~TemperatureLogger() {
		delete[] temperatures; // Освобождение выделенной памяти
	}
	// Метод для добавления показания температуры
	void addReading(int temp) {
		if (numReadings < capacity) {
			temperatures[numReadings++] = temp;
		}
		else {
			cout << "Достигнута максимальная емкость, добавить больше показаний невозможно." << endl;
		}
	}
	// Метод для расчета средней температуры
	double calculateAverage() const {
		if (numReadings == 0) return 0; // Предотвращение деления на ноль
		int sum = 0;
		for (int i = 0; i < numReadings; ++i) {
			sum += temperatures[i];
		}
		return static_cast<double>(sum) / numReadings;
	}
	// Другие методы (findMaxTemperature, findMinTemperature) остаются аналогичными и опущены для краткости
};
int main() {
	SetConsoleOutputCP(1251);

	TemperatureLogger logger(365); // Создание объекта logger с емкостью для 365 показаний
	// Пример использования
	logger.addReading(23);
	logger.addReading(25);
	// Добавление дополнительных показаний по мере необходимости...
	cout << "Средняя температура: " << logger.calculateAverage() << endl;
	return 0;
}
