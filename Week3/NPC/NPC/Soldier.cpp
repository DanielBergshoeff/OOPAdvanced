#include "Soldier.h"


Soldier::Soldier(Class* c)
	:Role(c)
{
}

std::string Soldier::render() {
	return "Soldier " + classSelf->render();
}


Soldier::~Soldier()
{
}
