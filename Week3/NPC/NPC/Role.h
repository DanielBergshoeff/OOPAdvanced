#pragma once
#include "Class.h"

class Role : public Class
{
public:
	Class* classSelf;

	Role(Class* c);
	~Role();
};

