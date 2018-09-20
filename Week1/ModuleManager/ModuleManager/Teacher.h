#pragma once
#include "Person.h"

class Teacher : public Person
{
public:
	Teacher();
	Teacher(std::string teacherFirstName, std::string teacherLastName);
	~Teacher();
};

