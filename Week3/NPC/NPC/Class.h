#pragma once
#include <string>
#include <iostream>

class Class
{
public:
	std::string name;

	virtual std::string render() = 0;

	Class(std::string n);
	~Class();
};

