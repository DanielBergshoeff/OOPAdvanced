#pragma once
#include "Module.h"
#include "Person.h"

class Module;

class Student : public Person
{
public:
	using Person::Person;

	bool addModule(Module* m);

	int getECcount();

	Student(std::string personFirstName, std::string personLastName);
	Student();
	~Student();
private:
	int moduleCount;
	Module* modules[3];
};

