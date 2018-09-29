#pragma once
#include "Role.h"

class Soldier : public Role
{
public:
	Soldier(Class* c);

	std::string render();

	~Soldier();
};

