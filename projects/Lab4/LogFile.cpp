#include <iostream>
#include <string>
class LogFile {
public:
	std::string logMessage;
	// �����������
	LogFile(std::string message) : logMessage(message) {
		std::cout << "���� ������: " << logMessage << std::endl;
	}
	// ����������
	~LogFile() {
		std::cout << "���� ������" << std::endl;
	}
};void simulateFileOperation() {
	LogFile log("��� ���-���������.");
	// ���������� ����� ������������� ������, ����� ��� ������� �������� ����������
	// � ������ `log` ������ �� ������� ���������.
}

//int main() {
//	simulateFileOperation();
//	std::cout << "��������� � main, ����� simulateFileOperation" << std::endl;
//	return 0;
//}