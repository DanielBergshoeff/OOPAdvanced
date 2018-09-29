#include "Shaman.h"


Shaman::Shaman(Class* c)
	:Role(c)
{
}

std::string Shaman::render() {
	return "Shaman " + classSelf->render();
}


Shaman::~Shaman()
{
}
