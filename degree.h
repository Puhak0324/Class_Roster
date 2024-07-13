#pragma once
#include <string>

//lists all possible values for degreeProgram,
enum class DegreeProgram { SECURITY, NETWORK, SOFTWARE };
//security has enum value of 0, 
//network has enum value of 1, 
//software has enum value of 2,
//in this case security will be used as my default throughout program
static const std::string degreeProgramStrings[] =
{ "SECURITY", "NETWORK", "SOFTWARE" };