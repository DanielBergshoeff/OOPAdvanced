// NPC.cpp : Defines the entry point for the console application.
//
#pragma once
#include "Farmer.h"
#include "Orc.h"
#include "Elf.h"
#include "Shaman.h"
#include "Soldier.h"

int main()
{
	Class* c0 = new Soldier(new Orc("Raka"));
	Class* c1 = new Farmer(new Elf("Legolas"));
	Class* c2 = new Orc("Roughbone");
	Class* c3 = new Shaman(new Elf("Rakatic"));
	Class* c4 = new Shaman(new Farmer(new Soldier(new Elf("Maester"))));

	std::cout << c0->render() << std::endl;
	std::cout << c1->render() << std::endl;
	std::cout << c2->render() << std::endl;
	std::cout << c3->render() << std::endl;
	std::cout << c4->render() << std::endl;


	char i;
	std::cin >> i;

    return 0;
}

