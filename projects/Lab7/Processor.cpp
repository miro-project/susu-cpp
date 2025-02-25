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
int main() {
	std::vector<int> data = { 1, 2, 3, 4, 5 }; // �������� ������
	LambdaProcessor processor; // �������� ���������� ������������ ������
	// ����� ������� ��������� ������ � ������-���������� ��� ���������� ������� �������� �� 1
	processor.process(data, [](int& val) { val += 1; });
	// ����� ����������� ����� ������ ���������
	for (int val : data) {
		std::cout << val << " "; // ������ ������� 2 3 4 5 6
	}
	std::cout << std::endl;
	// ����� ������� ��������� ������ � ������ ������-���������� ��� ��������� ������� �������� �� 2
	processor.process(data, [](int& val) { val *= 2; });
	// ����� ����������� ����� ������ ���������
	for (int val : data) {
		std::cout << val << " "; // ������ ������� 4 6 8 10 12
	}
	std::cout << std::endl;
	return 0;
}