#include "Orc.h"


Orc::Orc(std::string n)
	:Class(n)
{
}

std::string Orc::render() {
	return "Orc " + name;
}


Orc::~Orc()
{
}
