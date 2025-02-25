#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Book
{
private:
	string title;
	string author;
	string genre;
	int publicationYear;
	bool borrowed;

public:
	Book() : title("Unknown"), author("Unknown"), genre("Unknown"), publicationYear(0), borrowed(false) {}

	Book(string t, string a, string g, int year, bool isBorrowed) : title(t), author(a), genre(g), publicationYear(year), borrowed(isBorrowed) {}

	string serialize() const
	{
		return title + ";" + author + ";" + genre + ";" + to_string(publicationYear) + ";" + to_string(borrowed);
	}

	void deserialize(const string &data)
	{
		size_t pos = 0, next_pos;
		next_pos = data.find(';', pos);
		title = data.substr(pos, next_pos - pos);

		pos = next_pos + 1;
		next_pos = data.find(';', pos);
		author = data.substr(pos, next_pos - pos);

		pos = next_pos + 1;
		next_pos = data.find(';', pos);
		genre = data.substr(pos, next_pos - pos);

		pos = next_pos + 1;
		next_pos = data.find(';', pos);
		publicationYear = stoi(data.substr(pos, next_pos - pos));

		pos = next_pos + 1;
		borrowed = stoi(data.substr(pos));
	}

	void updateInfo(string t, string a, string g, int year, bool isBorrowed)
	{
		title = t;
		author = a;
		genre = g;
		publicationYear = year;
		borrowed = isBorrowed;
	}

	void setBorrowed(bool isBorrowed)
	{
		borrowed = isBorrowed;
	}

	bool isBorrowed() const
	{
		return borrowed;
	}

	void displayDetails() const
	{
		cout << "Title: " << title << endl;
		cout << "Author: " << author << endl;
		cout << "Genre: " << genre << endl;
		cout << "Publication Year: " << publicationYear << endl;
		cout << "Is borrowed: " << (borrowed ? "Yes" : "No") << endl;
		cout << endl;
	}

	string getTitle() const
	{
		return title;
	}
};

class Library
{
private:
	vector<Book> books;
	string filename;

public:
	Library(string fn = "library.txt") : filename(fn) {}

	void addBook(const Book &book)
	{
		books.push_back(book);
	}

	void removeBook(int index)
	{
		if (index >= 0 && index < books.size())
		{
			books.erase(books.begin() + index);
		}
	}

	void borrowBook(const string &title)
	{
		for (auto &book : books)
		{
			if (book.getTitle() == title)
			{
				if (!book.isBorrowed())
				{
					book.setBorrowed(true);
					cout << "You have borrowed the book: \"" << title << "\"" << endl;
				}
				else
				{
					cout << "The book is already taken" << endl;
				}
				return;
			}
		}
		cout << "The book wasn't found" << endl;
	}

	void returnBook(const string &title)
	{
		for (auto &book : books)
		{
			if (book.getTitle() == title)
			{
				if (book.isBorrowed())
				{
					book.setBorrowed(false);
					cout << "You have returned the book: \"" << title << "\"" << endl;
				}
				else
				{
					cout << "The book wasn't taken" << endl;
				}
				return;
			}
		}
		cout << "The book wasn't found" << endl;
	}

	void saveLibrary()
	{
		ofstream fileOut(filename);
		for (const auto &book : books)
		{
			fileOut << book.serialize() << endl;
		}
	}

	void loadLibrary()
	{
		ifstream fileIn(filename);
		string line;
		while (getline(fileIn, line))
		{
			Book book;
			book.deserialize(line);
			books.push_back(book);
		}
	}

	void printLibrary() const
	{
		for (const auto &book : books)
		{
			book.displayDetails();
		}
	}
};

int main()
{
	string title = "Книга 1";
	string author = "Автор 1";
	string genre = "Жанр 1";
	int year = 2000;
	bool borrowed = false;

	Book book(title, author, genre, year, borrowed);

	Library library;
	library.addBook(book);

	Book book2("Название 2", "Автор 2", "Жанр 2", 2100, true);
	library.addBook(book2);

	Book book3("Название 3", "Автор 3", "Жанр 3", 3500, false);
	library.addBook(book3);

	library.printLibrary();

	// Library library;
	// library.loadLibrary();
	// library.printLibrary();

	return 0;
}
