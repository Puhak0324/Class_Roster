#pragma once
//pragma once used to avoid using duplicate include values
#include "student.h"
#include <cstring>
#include <string.h>

class Roster {
public:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* studentRosterArray[numStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr };
	//this points at the array studentRosterArray
public:

	//seperates each field by a comma-to produce an object
	void parse(string studentData);
	//after parsing, this is what is extracted below
	void add(string studentId,
		string firstName, string lastName,
		string emailAddress, string age,
		double daysInCourse1, double daysInCourse2, double daysInCourse3, DegreeProgram dp);
	void remove(string studentId);
	//removes student based off student ID
	void printAll();
	//Prints all data in table
	void printAverageDaysInCourse(string studentId);
	//prints avg days in course based off given student ID
	void printInvalidEmails();
	//a valid email will include an @ sign, a . and no space
	//detects invalid emails and prints only those
	void printByDegreeProgram(DegreeProgram dp);
	//prints all students who are enrolled in a given degree program
	~Roster();
};
