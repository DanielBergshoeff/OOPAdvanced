#pragma once
#include "Teacher.h"
#include "Student.h"
#include <vector>

class Teacher;
class Student;

class Module
{
public:
	std::string name;

	bool setTeacher(Teacher* t);
	bool addStudent(Student* s);
	bool removeStudent(Student* s);
	std::string getInformation();

	bool setEc(int newEcCount);
	int getEc();

	Module();
	Module(std::string moduleName, int moduleEC);
	~Module();

private:
	int studentCount;
	int ec;
	Teacher* teacher;
	std::vector<Student*> students;
};

