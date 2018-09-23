#include "stdafx.h"
#include "GameManager.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


GameManager::GameManager(int fieldWidthPara, int fieldHeightPara)
	:fieldWidth(fieldWidthPara), fieldHeight(fieldHeightPara)
{
	initField();
	showField();
	ruleSetNormal = new NormalRules();
	ruleSetHealthy = new HealthyRules();
	ruleSetPlague = new PlagueRules();
	ruleSet = ruleSetHealthy;
}

void GameManager::applyRules() {
	field =	ruleSet->applyRules(field, fieldWidth, fieldHeight);
	showField();
}

double GameManager::getPercentageLiving() {
	int living = 0;

	for (size_t i = 0; i < field.size(); i++)
	{
		if (*field[i] == true) {
			living++;
		}
	}

	double percentage = living / fieldWidth * fieldHeight;

	return percentage;
}

void GameManager::showField() {
	std::system("cls");

	for (int i = 0; i < fieldWidth * fieldHeight; i++)
	{
		if (*((field[i])) == false) {
			std::cout << "-";
		}
		else if (*(field[i]) == true) {
			std::cout << "*";
		}

		if (i % fieldWidth == fieldWidth - 1) {
			std::cout << "\n";
		}
	}
}

void GameManager::initField() {

	for (int i = 0; i < fieldWidth * fieldHeight; i++)
	{
		field.push_back(new bool(false));
		
		//SET ALL RANDOM
		/*
		int rnd = rand() % 2;
		if (rnd == 0) {
			field.push_back(false);
		}
		else {
			field.push_back(true);
		}*/
	}

	std::vector<int> nrs1 = { 1, -1, fieldWidth, -fieldWidth, fieldWidth + 1, -fieldWidth + 1, fieldWidth - 1, -fieldWidth - 1 };

	*(field[((fieldWidth * fieldHeight) / 2)]) = true;

	int rnd;
	srand(time(NULL));

	for (size_t i = 0; i < nrs1.size(); i++)
	{
		rnd = rand() % 2;
		if (rnd == 0) {
			*(field[((fieldWidth * fieldHeight) / 2) + nrs1[i]]) = false;
		}
		else {
			*(field[((fieldWidth * fieldHeight) / 2) + nrs1[i]]) = true;
		}
	}
}

GameManager::~GameManager()
{
}
