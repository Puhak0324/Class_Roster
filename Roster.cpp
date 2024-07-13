#include "roster.h"
#include <string>
#include <cmath>
#include <iostream>


void Roster::parse(string studentData)//parses each row one at a time
{
	DegreeProgram dp = DegreeProgram::SECURITY;//<--Default value
	//I chose to identify degree program by second number in Student ID
	//could have chosen it based off first name, last name, or days in course
	if (studentData.at(1) == '3') dp = DegreeProgram::SOFTWARE;
	else if (studentData.at(1) == '2') dp = DegreeProgram::NETWORK;
	else if (studentData.at(1) == '5') dp = DegreeProgram::SOFTWARE;

	int rhs = studentData.find(",");//<-Finds the first commma
	string studentId = studentData.substr(0, rhs);//extracts substring in front of comma
	//first value obtained is student Id

	int lhs = rhs + 1;//<-move past previous comma
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, rhs - lhs);
	//second value obtained as student first name

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);
	//third value obtained as student last name

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string emailAddress = studentData.substr(lhs, rhs - lhs);
	//fourth value obtained as email address

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string age = studentData.substr(lhs, rhs - lhs);
	//fifth value obtained as age

	//the next three operations will obtain the 1st, 2nd, and 3rd numDays values
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	double numDays1 = stod(studentData.substr(lhs, static_cast<std::basic_string<char,
		std::char_traits<char>, std::allocator<char>>::size_type>(rhs) - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	double numDays2 = stod(studentData.substr(lhs, static_cast<std::basic_string<char,
		std::char_traits<char>, std::allocator<char>>::size_type>(rhs) - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	double numDays3 = stod(studentData.substr(lhs, static_cast<std::basic_string<char,
		std::char_traits<char>, std::allocator<char>>::size_type>(rhs) - lhs));

	//degreeProgram already obtained from first if statement
	//combine all values located
	add(studentId, firstName, lastName, emailAddress, age,
		numDays1, numDays2, numDays3, dp);
}

void Roster::add(string studentId, string firstName, string lastName, string emailAddress, string age,
	double daysInCourse1, double daysInCourse2, double daysInCourse3, DegreeProgram dp)
{
	//creates an array to hold all three numDaysInCourse values
	double daysInCourseArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	studentRosterArray[++lastIndex] = new Student(studentId, firstName,
		lastName, emailAddress, age, daysInCourseArray, dp);
	cout << "Student added to class roster at row" << lastIndex + 1 << endl;
}

//Remove Student by ID Function
void Roster::remove(string studentId) {
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (studentRosterArray[i]->getId() == studentId) {
			success = true;
			if (i < numStudents - 1) {
				Student* temp = studentRosterArray[i];
				studentRosterArray[i] = studentRosterArray[numStudents - 1];
				studentRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;
			//Last student is actually just hidden from view, not actually removed,
			//however, that accomplishes the goal of not seeing that student when ran.
		}
	}
	if (success) {
		cout << studentId << " removed from roster." << endl;
		cout << endl;
		this->printAll();
		//displays the students, except for the one hidden.
	}
	else cout << studentId << " not found." << endl;
	cout << endl;
}

//Print All Function
void Roster::printAll()
{
	//for loop will systematically work through each value until
		//it reaches the end value
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) Roster::studentRosterArray[i]->print();
}


//Print Average Days in Course Function
void Roster::printAverageDaysInCourse(string studentId) {
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (studentRosterArray[i]->getId() == studentId) {
			cout << studentId << ":";
			cout << (studentRosterArray[i]->getNumDays()[0]
				+ studentRosterArray[i]->getNumDays()[1]
				+ studentRosterArray[i]->getNumDays()[2]) / 3.0 << endl;

			//This program will search through all student Id's systematically
			//gather all three days in course, and divides by 3.0
			//need to divide by a double, not an int to ensure a float answer.
		}
	}
}

//Prints students with Invalid Emails
void Roster::printInvalidEmails() {
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		//This checks for any spaces within email address
		string emailAddress = (studentRosterArray[i]->getEmailAddress());
		if (!(emailAddress.find(' ') == string::npos || (emailAddress.find('@') == string::npos
			&& (emailAddress.find('.') == string::npos))))

		{
			any = true;
			cout << emailAddress << ": " << studentRosterArray[i]->getId() << endl;
		}
		//this checks for any without a period 
		if (emailAddress.find('.') == string::npos)
		{
			any = true;
			cout << emailAddress << ": " << studentRosterArray[i]->getId() << endl;
		}
		//and this checks for any missing the @ symbol
		if (emailAddress.find('@') == string::npos)
		{
			any = true;
			cout << emailAddress << ": " << studentRosterArray[i]->getId() << endl;
		}
	}
	if (!any) cout << "NONE FOUND" << std::endl;
}
//if statement will check if email has any spaces
//else if statement is checking for both a period and @ sign.
//if any conditions are true, student id is displayed with email
//if none fail, NONE FOUND is diplayed



//Prints by Degree Program
void Roster::printByDegreeProgram(DegreeProgram dp)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::studentRosterArray[i]->getDegreeProgram() == dp) studentRosterArray[i]->print();
	}
}

//Destructor
Roster::~Roster()
{
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Destructor Called!" << studentRosterArray[i]->getId() << endl;
		delete studentRosterArray[i];
		studentRosterArray[i] = nullptr;
	}
}