#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::cout;
using std::string;
using std::endl;
using std::left;
using std::setw;

class Student {
public:
	//defines array size 
	const static int arrayNumOfDaysSize = 3;
private:
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	string age;
	double numDays[arrayNumOfDaysSize];
	DegreeProgram degreeProgram;
public:
	Student();//Constructor-sets to defaults
	Student(string studentId, string firstName, string lastName, string emailAddress, string age, double numDays[], DegreeProgram degreeProgram);
	~Student();//Destructor

	//Getters-ancestors
	string getId();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	string getAge();
	const double* getNumDays();
	DegreeProgram getDegreeProgram();

	//Setters-mutators
	void setId(string studentId);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(string age);
	void setNumDays(const double NumDays[]);
	void setDegreeProgram(DegreeProgram dp);

	//Displays Header
	static void printHeader();

	//Displays 'This' student
	void print();

};