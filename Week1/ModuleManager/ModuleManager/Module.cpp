#include "stdafx.h"
#include "Module.h"


Module::Module()
{
}

Module::Module(std::string moduleName, int moduleEC) 
	:name(moduleName), ec(moduleEC)
{
	studentCount = 0;
}

bool Module::setTeacher(Teacher* t)
{
	teacher = t;
	return true;
}

bool Module::addStudent(Student* s) {
	if (studentCount < 30) {
		if (s->addModule(this)) {
			students.push_back(s);
			studentCount++;
			return true;
		}
	}
	
	return false;
}

bool Module::removeStudent(Student* s) {
	auto it = std::find(students.begin(), students.end(), s);
	if (it != students.end()) {
		students.erase(it);
		studentCount--;
		return true;
	}
	return false;
}

bool Module::setEc(int newEcCount) {
	ec = newEcCount;
	return true;
}

int Module::getEc() {
	return ec;
}

std::string Module::getInformation() {
	std::string tempString;
	tempString = "Module name: " + name + "\nEC count: " + std::to_string(ec) + "\nTeacher: " + teacher->firstName + " " + teacher->lastName + "\n";
	for (int i = 0; i < studentCount; i++)
	{
		tempString += "Student " + std::to_string(i) + ": " + students[i]->firstName + " " + students[i]->lastName + "\n";
	}
	tempString += "\n";
	return tempString;
}


Module::~Module()
{
}
