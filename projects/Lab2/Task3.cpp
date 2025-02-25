#include <iostream>
#include <windows.h>

using namespace std;

// Использует рекурсию, не проверяет, является ли показатель степени отрицательным
// Это перегруженная функция
int power(int base, int exponent)
{
	if (exponent == 0)
		return 1;
	return base * power(base, exponent - 1);
}

// Также использует рекурсию, не проверяет, является ли показатель степени отрицательным
double power(double base, int exponent)
{
	if (exponent == 0)
		return 1.0;
	return base * power(base, exponent - 1);
}

// Точка входа в программу
int main()
{
	// Устанавливаем кодировку для консоли
	// Исправлено: с "CP_UTF8" на "1251"
	// В Windows "CP_UTF8" работает некорректно
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	// Объявление переменных
	int intBase, exponent;
	double doubleBase;
	char baseType;

	// Выводим сообщение и получаем ввод от пользователя (заполняем переменные)
	cout << "Введите 'i' для целого основания или 'd' для числа с плавающей запятой: ";
	cin >> baseType;
	cout << "Введите показатель степени (неотрицательное число): ";
	cin >> exponent;

	// Проверяем, является ли показатель степени отрицательным
	if (exponent < 0)
	{
		cout << "Показатель степени должен быть неотрицательным." << endl;
		return 1;
	}

	// В зависимости от выбора пользователя, вычисляем степень и выводим результат
	if (baseType == 'i')
	{
		cout << "Введите целое основание: ";
		cin >> intBase;
		cout << "Результат: " << power(intBase, exponent) << endl;
	}
	else if (baseType == 'd')
	{
		cout << "Введите число с плавающей запятой: ";
		cin >> doubleBase;
		cout << "Результат: " << power(doubleBase, exponent) << endl;
	}
	// Некорректный ввод
	else
	{
		cout << "Ошибка: некорректный ввод." << endl;
	}

	// Программа завершена успешно
	return 0;
}
