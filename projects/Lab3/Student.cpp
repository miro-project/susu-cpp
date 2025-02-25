#include <iostream>
#include <string>

using namespace std;

class Student {
public:
	// Member Variables
	string name;
	string id;
	double examScore;
	double assignmentScore;

	// Constructor
	Student(string n, string i) : name(n), id(i), examScore(0), assignmentScore(0) {}
	
	// Method to input scores
	void inputScores(double exam, double assignment) {
		examScore = exam;
		assignmentScore = assignment;
	}
	
	// Method to calculate final grade
	double calculateGrade() {
		return (examScore + assignmentScore) / 2.0;
	}
	
	// Method to display student details and grade
	void displayDetails() {
		cout << "Student Name: " << name << endl;
		cout << "Student ID: " << id << endl;
		cout << "Exam Score: " << examScore << endl;
		cout << "Assignment Score: " << assignmentScore << endl;
		cout << "Final Grade: " << calculateGrade() << endl;
	}
};//int main() {
//	// Creating a Student object
//	Student student1("John Doe", "S1234567");
//
//	// Inputting scores
//	student1.inputScores(85.5, 92.3);
//
//	// Displaying student details and final grade
//	student1.displayDetails();
//
//	return 0;
//}