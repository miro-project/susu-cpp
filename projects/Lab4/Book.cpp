#include <iostream>
#include <string>

using namespace std;

class Book
{
private:
	string name;
	string writer;
	int year;
	bool available;

public:
	Book() : name("Неизвестно"), writer("Неизвестно"), year(0), available(false)
	{
		cout << "Создана книга с параметрами по умолчанию" << endl;
	}

	Book(string n, string w, int y, bool avail) : name(n), writer(w), year(y), available(avail)
	{
		cout << "Создана книга" << endl;
	}

	~Book()
	{
		cout << "Удалена книга \"" << name << "\" автора " << writer << endl;
	}

	// Методы обновления информации (перегруженные)
	void setInfo(string n, string w, int y, bool avail)
	{
		name = n;
		writer = w;
		year = y;
		available = avail;
	}

	void setInfo(string n, string w)
	{
		name = n;
		writer = w;
	}

	void setInfo(int y, bool avail)
	{
		year = y;
		available = avail;
	}

	// Вывод информации
	void showDetails()
	{
		cout << "Название: " << name << endl;
		cout << "Автор: " << writer << endl;
		cout << "Год публикации: " << year << endl;
		cout << "Доступность: " << (available ? "Да" : "Нет") << endl;
		cout << endl;
	}
};

// int main() {
//     Literature book1;
//     book1.showDetails();
//
//     Literature book2("Война и мир", "Толстой", 1860, false);
//     book2.showDetails();
//
//     book1.setInfo("Название книги", "Автор книги", 5200, true);
//     book1.showDetails();
//
//     return 0;
// }
