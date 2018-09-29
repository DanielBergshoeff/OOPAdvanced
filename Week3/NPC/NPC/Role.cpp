#include "Role.h"


Role::Role(Class* c)
	:Class(c->name), classSelf(c)
{
}


Role::~Role()
{
}
