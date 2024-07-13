#include "roster.h"
#include <iostream>

using namespace std;


int main() {
	cout << "Scripting and Programming Applications" << endl;
	cout << "Programming Language C++" << endl;
	cout << "Student ID: 010500702" << endl;
	cout << "Austin Puhak" << endl;

	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickso,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Austin,Puhak,Austinpuhak@gmail.com,24,10,15,20,SOFTWARE"
	};

	const int numStudents = 5;
	Roster roster;
	//This Displays all students in the required format
	for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]);
	cout << "Displaying all Students: " << endl;
	roster.printAll();
	cout << endl;


	//This displays students according to degree program
	for (int i = 0; i < 3; i++) {
		cout << "Displaying by Degree Program: " << degreeProgramStrings[i] << endl;
		roster.printByDegreeProgram((DegreeProgram)i);
		//cast integer to a string degree program
	}

	//This displays any students with a space, no @ or no . in email address
	cout << "Displaying Students with invalid Emails:" << endl;
	roster.printInvalidEmails();
	cout << endl;

	//This takes all three in each course and dives by 3.0 to get average
	cout << "Displaying Average Days in Course: " << endl;
	for (int i = 0; i < numStudents; i++) {
		roster.printAverageDaysInCourse
		(roster.studentRosterArray[i]->getId());
		cout << endl;
	}

	//Removes student with given ID-I chose A4
	cout << "Removing Student with ID: A4" << endl;
	roster.remove("A4");
	cout << endl;

	//Verifies student I have chosen was actually removed, will display not found
	cout << "Removing Student with ID: A4" << endl;
	roster.remove("A4");
	cout << endl;

	system("pause");
	return 0;
}