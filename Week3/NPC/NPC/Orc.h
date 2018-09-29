#pragma once
#include "Class.h"

class Orc : public Class
{
public:
	Orc(std::string n);

	std::string render();

	~Orc();
};

