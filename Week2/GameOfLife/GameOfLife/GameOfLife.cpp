// GameOfLife.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GameManager.h"
#include <iostream>


int main()
{
	GameManager* gm = new GameManager(31, 21);

	char checkLetter = 'r';
	while (checkLetter != 's') {
		std::cin.get(checkLetter);
		if (checkLetter == '\n') {
			gm->applyRules();
			double percentage = gm->getPercentageLiving();
			if (percentage < 40) {
				gm->ruleSet = gm->ruleSetHealthy;
			}
			else if (percentage < 60) {
				gm->ruleSet = gm->ruleSetNormal;
			}
			else if (percentage > 80) {
				gm->ruleSet = gm->ruleSetPlague;
			}
		}
	}

	char returnLetter;
	std::cin >> returnLetter;

    return 0;
}

