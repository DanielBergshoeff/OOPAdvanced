#include "Farmer.h"


Farmer::Farmer(Class* c)
	:Role(c)
{
}

std::string Farmer::render() {
	return "Farmer " + classSelf->render();
}


Farmer::~Farmer()
{
}
