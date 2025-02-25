#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <vector>
#include <functional>
#include <fstream>
#include <algorithm>

using namespace std;

mutex mutexCout;

class DataProcessor
{
public:
	virtual void process(const string &inputFile, const string &outputFile) = 0;
	virtual ~DataProcessor() = default;
};

class UpperText : public DataProcessor
{
public:
	void process(const string &inputFile, const string &outputFile) override
	{
		ifstream inFile(inputFile);
		ofstream outFile(outputFile);

		if (!inFile || !outFile)
		{
			lock_guard<mutex> guard(mutexCout);
			cerr << "Error opening file: " << inputFile << " or " << outputFile << endl;
			return;
		}

		string line;
		while (getline(inFile, line))
		{
			transform(line.begin(), line.end(), line.begin(), [](unsigned char c)
					  { return toupper(c); });
			outFile << line << endl;
		}

		lock_guard<mutex> guard(mutexCout);
		cout << "Processed file: " << inputFile << " -> " << outputFile << endl;
	}
};

class WordCount : public DataProcessor
{
public:
	void process(const string &inputFile, const string &outputFile) override
	{
		ifstream inFile(inputFile);
		ofstream outFile(outputFile);

		if (!inFile || !outFile)
		{
			lock_guard<mutex> guard(mutexCout);
			cerr << "Error opening file: " << inputFile << " or " << outputFile << endl;
			return;
		}

		string word;
		int count = 0;

		while (inFile >> word)
		{
			count++;
		}

		outFile << "Word count: " << count << endl;

		lock_guard<mutex> guard(mutexCout);
		cout << "Processed file: " << inputFile << " -> " << outputFile << endl;
	}
};

int main()
{
	vector<string> inputFiles = {"1.txt", "2.txt"};
	vector<string> outputFiles = {"out1.txt", "out2.txt"};

	vector<thread> threads;
	WordCount wordCount;
	UpperText upperText;

	for (size_t i = 0; i < inputFiles.size(); i++)
	{
		threads.emplace_back([&, i]()
							 {
			if (i % 2 == 0) {
				wordCount.process(inputFiles[i], outputFiles[i]);
			} else {
				upperText.process(inputFiles[i], outputFiles[i]);
			} });
	}

	for (auto &thread : threads)
	{
		thread.join();
	}

	return 0;
}
