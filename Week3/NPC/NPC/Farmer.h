#pragma once
#include "Role.h"

class Farmer : public Role
{
public:
	Farmer(Class* c);

	std::string render();

	~Farmer();
};

