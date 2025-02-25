#include <iostream>
#include <string>
class LogFile {
public:
	std::string logMessage;
	// Конструктор
	LogFile(std::string message) : logMessage(message) {
		std::cout << "Файл открыт: " << logMessage << std::endl;
	}
	// Деструктор
	~LogFile() {
		std::cout << "Файл закрыт" << std::endl;
	}
};void simulateFileOperation() {
	LogFile log("Это лог-сообщение.");
	// Деструктор будет автоматически вызван, когда эта функция закончит выполнение
	// и объект `log` выйдет из области видимости.
}

//int main() {
//	simulateFileOperation();
//	std::cout << "Вернулись в main, после simulateFileOperation" << std::endl;
//	return 0;
//}