#pragma once
#include "Role.h"

class Shaman : public Role
{
public:
	Shaman(Class* c);

	std::string render();

	~Shaman();
};

