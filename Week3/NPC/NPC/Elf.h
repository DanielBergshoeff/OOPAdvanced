#pragma once
#include "Class.h"

class Elf : public Class
{
public:
	Elf(std::string n);

	std::string render();

	~Elf();
};

