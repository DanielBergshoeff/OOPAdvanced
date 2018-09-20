#include "stdafx.h"
#include "Teacher.h"


Teacher::Teacher()
{
}

Teacher::Teacher(std::string teacherFirstName, std::string teacherLastName)
	:Person(teacherFirstName, teacherLastName)
{
}


Teacher::~Teacher()
{
}
