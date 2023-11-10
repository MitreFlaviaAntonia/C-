#include <vector>
#include <iostream>
using namespace std;

class Student
{	
	vector<int> myGrades;
	const string& myName;
	const string& myAddress;
	int myAge;
	bool myIsMale;

public:

	Student(const string& name, const string& address, int age, bool isMale)
		: myName(name)
		, myAddress(address)
		, myAge(age)
		, myIsMale(isMale)
	{

	}

	void PrintInfo()
	{
		cout << "Name: " << myName << "\nAge: " << myAge << "\nAddress: " << myAddress << endl;

		cout << "Grades: ";

		for (const int grade : myGrades)
		{
			cout << grade << " ";
		}
		cout << endl;
	}
	void AddGrade(const int grade) { myGrades.push_back(grade); }
};

class School
{
	vector<Student> myStudents;

	string myAddress;

public:

	void EnrollStudent(const Student &stud) { myStudents.push_back(stud); }//passing stud by reference instead of by value

	void GradeStudent(Student& stud, int grade) { stud.AddGrade(grade); }

	void ExpellStudent(const Student& stud) 
	{
		std::remove_if(myStudents.begin(), myStudents.end(), [stud](Student &s) { return &s == &stud; });//passing s by reference instead of by value
	}
};

int main()
{
	Student* st = new Student("Max", "Ubisoft", 21, true);

	Student* st2 = new Student("Mia", "Ubisoft", 20, false);

	School* sc = new School();

	sc->EnrollStudent(*st);

	sc->EnrollStudent(*st2);

	sc->ExpellStudent(*st);

	delete sc;
	delete st2;
	delete st;

	return 0;
}