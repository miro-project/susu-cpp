#include <iostream>
#include <vector>
#include <thread>
#include <functional>
#include <mutex>
#include <chrono>
#include <locale.h>

// **������� ��� ������������� ������� � ������������ ������ (cout)**
std::mutex coutMutex;

// **������� ����� ��� ��������� ������**
//
// ����������� ����� `process` ������ ���� ������������� � ����������� �������
// ��� ���������� ���������� ������ ��������� ������.
class DataProcessor {
public:
	virtual void process(std::vector<int>& data, std::function<void(int&)> func) = 0;
};

// **����������� �����, ����������� ������������ ��������� ������**
class ParallelDataProcessor : public DataProcessor {
public:
	// **��������������� ������ `process` �� �������� ������**
	void process(std::vector<int>& data, std::function<void(int&)> func) override {
		// **�������� ���������� ��� �������**
		std::vector<std::thread> threads;

		// **���������� ������� ����� ������ ��� ������� ������**
		// (��������������, ��� ������ ������ ������ 4)
		int partSize = data.size() / 4;

		// **������ ������� ��� ��������� ������ ����� ������**
		for (int i = 0; i < 4; ++i) {
			// �������� ������ ������ � �������������� ������-���������:
			// * [&]: ������ ������� ���������� �� ������ (��� ������� � coutMutex, data � ��.).
			// * [i, func]: ������ `i` (������ ����� ������) � `func` (������� ���������) �� ��������
			// * ��� ������������� ������ ������-�������.

			threads.emplace_back([&, i, func]() {
				// **����������� ��������� �������������� ������ ��� �������� ������**
				int start = i * partSize;
				int end = (i + 1) * partSize;

				// **��������� ������ � �����**
				for (int j = start; j < end; ++j) {
					// **�������� �������� ��� ������������ ����������� �������**
					std::this_thread::sleep_for(std::chrono::milliseconds(50 * (j - start + 1)));

					// **���������� ������� `func` ��� ������� �������� ������**
					func(data[j]);

					// **����� ��������� � ���������� ��������**
					std::lock_guard<std::mutex> guard(coutMutex);
					std::cout << "����� " << i << " ��������� ������� " << j << std::endl;
				}
				});
		}

		// **�������� ���������� ���� �������**
		for (auto& t : threads) {
			t.join();
		}
	}
};

//int main() {
//	setlocale(LC_ALL, "Russian");
//
//	// **������ ������**
//	std::vector<int> data = { 1, 2, 3, 4, 5, 6, 7, 8 };
//
//	// **�������� ������� ������ ParallelDataProcessor**
//	ParallelDataProcessor processor;
//
//	// **��������� ������ � ������� ������-���������, �������������� ������ ������� �� 1**
//	processor.process(data, [](int& n) { n += 1; });
//
//	// **����� ����������� ���������**
//	std::lock_guard<std::mutex> guard(coutMutex);
//
//	for (int n : data) {
//		std::cout << n << " ";
//	}
//
//	std::cout << std::endl;
//
//	return 0;
//}
