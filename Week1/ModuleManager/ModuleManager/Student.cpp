#include "stdafx.h"
#include "Student.h"


Student::Student()
{
}

Student::Student(std::string studentFirstName, std::string studentLastName)
	:firstName(studentFirstName), lastName(studentLastName)
{
	moduleCount = 0;
}

bool Student::addModule(Module* m) {
	if (moduleCount < 3) {
		modules[moduleCount] = m;
		moduleCount++;
		return true;
	}
	else
		return false;
}

int Student::getECcount() {
	int ecCount = 0;
	for (int i = 0; i < moduleCount; i++)
	{
		ecCount += modules[i]->getEc();
	}
	return ecCount;
}


Student::~Student()
{
}
