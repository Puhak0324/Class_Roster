#include "student.h"
//do not need to specify path since file is in same project

//Constructor-Default Values, set empty values rather than null values
Student::Student() {
	this->studentId = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = "";
	for (int i = 0; i < arrayNumOfDaysSize; i++) this->numDays[i] = 0;
	this->degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(string studentId, string firstName, string lastName, string emailAddress,
	string age, double numDays[], DegreeProgram degreeProgram)
{
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < arrayNumOfDaysSize; i++) this->numDays[i] = numDays[i];
	this->degreeProgram = degreeProgram;
}

//Destructor
Student::~Student() {}

string Student::getId() { return this->studentId; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
string Student::getAge() { return this->age; }
const double* Student::getNumDays() { return this->numDays; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

void Student::setId(string studentId) { this->studentId = studentId; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(string age) { this->age = age; }
void Student::setNumDays(const double NumDays[]) {
	for (int i = 0; i < arrayNumOfDaysSize; i++) this->numDays[i] = numDays[i];
}
void Student::setDegreeProgram(DegreeProgram dp) { this->degreeProgram = dp; }

void Student::printHeader()
//used to print the header
{
	cout << "Output format: Student ID|First Name|LastName|Email|Age|Days in Course|Degree Program" << endl;
}
//can use endl or \n to signify a new line, user choice, but endl is more popular.

void Student::print()
//\t signifies using a tab
{
	cout << this->studentId << '\t';
	cout << this->firstName << '\t';
	cout << this->lastName << '\t';
	cout << this->emailAddress << '\t';
	cout << this->age << '\t';
	cout << this->numDays[0] << ',';
	cout << this->numDays[1] << ',';
	cout << this->numDays[2] << '\t';
	cout << degreeProgramStrings[(int)this->degreeProgram] << '\n';
	cout << endl;
	//translates enumerated value into a string so it makes sense 
}