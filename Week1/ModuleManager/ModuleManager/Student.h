#pragma once
#include "Module.h"

class Module;

class Student
{
public:
	std::string firstName;
	std::string lastName;

	bool addModule(Module* m);

	int getECcount();

	Student();
	Student(std::string studentFirstName, std::string studentLastName);
	~Student();
private:
	int moduleCount;
	Module* modules[3];
};

