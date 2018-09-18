#pragma once
class Teacher
{
public:
	std::string firstName;
	std::string lastName;

	Teacher();
	Teacher(std::string teacherFirstName, std::string teacherLastName);
	~Teacher();
};

