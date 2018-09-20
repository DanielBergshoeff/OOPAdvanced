// GameOfLife.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameManager.h"
#include <iostream>


int main()
{
	GameManager* gm = new GameManager(51, 31);

	char checkLetter = 'r';
	while (checkLetter != 's') {
		std::cin.get(checkLetter);
		if (checkLetter == '\n') {
			gm->applyRules();
		}
	}

	char returnLetter;
	std::cin >> returnLetter;

    return 0;
}

