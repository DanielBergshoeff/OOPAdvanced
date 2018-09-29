#pragma once
#include "Elf.h"


Elf::Elf(std::string n)
	:Class(n)
{
}

std::string Elf::render() {
	return "Elf " + name;
}


Elf::~Elf()
{
}
