#include <iostream>
#include <vector>
#include <algorithm> // ��� std::for_each
#include <functional> // ��� std::function

// ������� ����� Processor � ����������� �������� process ��� ��������� ������
class Processor {
public:
	// ������� ��� ��������� ������, ��������� ������ � ������-���������
	virtual void process(std::vector<int>& data, std::function<void(int&)> func) = 0;
};

// ����������� ����� LambdaProcessor, ����������� �� Processor
class LambdaProcessor : public Processor {
public:
	// ��������������� ������� process � �������������� ������-��������� � �������� ���������
	void process(std::vector<int>& data, std::function<void(int&)> func) override {
		// ���������� ������-��������� � ������� �������� �������
		std::for_each(data.begin(), data.end(), func);
	}
};

//int main() {
//	std::vector<int> data = { 1, 2, 3, 4, 5 }; // �������� ������
//	LambdaProcessor processor; // �������� ���������� ������������ ������
//
//	// ����� ������� ��������� ������ � ������-���������� ��� ���������� ������� �������� �� 1
//	processor.process(data, [](int& val) { val += 1; });
//
//	// ����� ����������� ����� ������ ���������
//	for (int val : data) {
//		std::cout << val << " "; // ������ ������� 2 3 4 5 6
//	}
//
//	std::cout << std::endl;
//
//	// ����� ������� ��������� ������ � ������ ������-���������� ��� ��������� ������� �������� �� 2
//	processor.process(data, [] (int& val) {val *= 100;});
//
//	// ����� ����������� ����� ������ ���������
//	for (int val : data) {
//		std::cout << val << " "; // ������ ������� 4 6 8 10 12
//	}
//
//	std::cout << std::endl;
//
//	return 0;
//}




//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//const long double EPS = 0.0001;
//
//long double f(long double x, long double a, long double b, long double c, long double d) {
//	return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
//}
//
//long double f_dash(long double x, long double a, long double b, long double c) {
//	return a * 3 * pow(x, 2) + b * 2 * x + c;
//}
//
//int main() {
//	long double a, b, c, d;
//	cin >> a;
//	cin >> b;
//	cin >> c;
//	cin >> d;
//
//	long double x = f(-10, a, b, c, d);
//	long double xn = f(10, a, b, c, d);
//
//	while (abs(xn - x) > EPS) {
//		cout << long double(x) << endl;
//		cout << long double(xn) << endl;
//
//		x = xn - f(xn, a, b, c, d) / f_dash(xn, a, b, c);
//		long double temp = x;
//		x = xn;
//		xn = temp;
//	}
//
//	cout << long double(x);
//
//	return 0;
//}