#pragma once
class Person
{
public:
	std::string firstName;
	std::string lastName;

	int id;
	static int currentId;

	Person(std::string personFirstName, std::string personLastName);
	Person();
	~Person();
};

