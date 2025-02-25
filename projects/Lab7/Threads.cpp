#include <iostream>
#include <thread>
#include <mutex>
#include <locale.h>
// **������� ��� ������������� ������� � ������������ ������ (cout)**
std::mutex coutMutex;
// **�������, ��������������� ������ ������ � ������������ ������ ������**
//
// @param threadNum - ����� ������
// @param start - ��������� ������ �������������� ������
// @param end - �������� ������ �������������� ������
void threadWork(int threadNum, int start, int end) {
	for (int i = start; i < end; ++i) {
		// **���������� �������� ��� ����������� ����������� ������� � cout**
		{
			std::lock_guard<std::mutex> guard(coutMutex);
			// **����� ��������� � ���, ��� ����� �������� ��� ������������ ���������**
			std::cout << "����� " << threadNum << " ������������ ������� " << i << std::endl;
		}
		// **�������� ������ ������ ����� �������� ��������� ��������**
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}
int main() {
	setlocale(LC_ALL, "Russian");
	// **������ ���� �������, ������ �� ������� ������������ ���� ����� ������**
	std::thread t1(threadWork, 1, 0, 5);
	std::thread t2(threadWork, 2, 5, 10);
	// **�������� ���������� ������ �������**
	t1.join();
	t2.join();
	return 0;
}