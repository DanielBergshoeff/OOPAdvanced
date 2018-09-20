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
}

void GameManager::showField() {
	for (int i = 0; i < fieldWidth * fieldHeight; i++)
	{
		if ((field[i]) == false) {
			std::cout << "-";
		}
		else if ((field[i]) == true) {
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
		field.push_back(false);
		
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

	field[((fieldWidth * fieldHeight) / 2)] = true;

	for (size_t i = 0; i < nrs1.size(); i++)
	{
		srand(time(0));
		int rnd = rand() % 2;
		if (rnd == 0) {
			field[((fieldWidth * fieldHeight) / 2) + nrs1[i]] = false;
		}
		else {
			field[((fieldWidth * fieldHeight) / 2) + nrs1[i]] = true;
		}
	}

	/*
	field[(fieldWidth * fieldHeight) / 2] = 1;
	field[(fieldWidth * fieldHeight) / 2 + 1] = 1;
	field[(fieldWidth * fieldHeight) / 2 - 1] = 1;
	field[(fieldWidth * fieldHeight) / 2 + fieldWidth] = 1;
	field[(fieldWidth * fieldHeight) / 2 - fieldWidth] = 1; */
}

void GameManager::applyRules() {
	std::vector<bool> tempField(field);
	std::vector<int> nrs0;
	std::vector<int> nrs1 = { 1, -1, fieldWidth, -fieldWidth, fieldWidth + 1, -fieldWidth + 1, fieldWidth - 1, -fieldWidth - 1 };
	std::vector<int> nrs2 = { 1, -1, fieldWidth, fieldWidth + 1, fieldWidth - 1 };
	std::vector<int> nrs3 = { 1, -1, -fieldWidth, -fieldWidth + 1, -fieldWidth - 1 };
	std::vector<int> nrs4 = { 1, -fieldWidth, -fieldWidth + 1, fieldWidth, fieldWidth + 1 };
	std::vector<int> nrs5 = { -1, -fieldWidth, -fieldWidth - 1, fieldWidth, fieldWidth - 1 };
	std::vector<int> nrs6 = { 1, fieldWidth, fieldWidth + 1 };
	std::vector<int> nrs7 = { -1, -fieldWidth, -fieldWidth - 1 };
	for (int i = 0; i < fieldWidth * fieldHeight; i++)
	{
		int amtOfLiveNeighbors = 0;

		if (i == 0) {
			nrs0 = nrs6;
		}
		else if (i == fieldWidth * fieldHeight - 1) {
			nrs0 = nrs7;
		}
		else if (i - fieldWidth < 0) {
			nrs0 = nrs2;
		}
		else if (i + fieldWidth >= fieldWidth * fieldHeight) {
			nrs0 = nrs3;
		}
		else if (i % fieldWidth == 0) {
			nrs0 = nrs4;
		}
		else if (i % fieldWidth == fieldWidth - 1) {
			nrs0 = nrs5;
		}
		else {
			nrs0 = nrs1;
		}
		
		for (int j = 0; j < nrs0.size(); j++)
		{			
			if (tempField[i + nrs0[j]] == true) {
				amtOfLiveNeighbors++;
			}
		}

		if (tempField[i] == true && amtOfLiveNeighbors < 2) {
			field[i] = false;
		}
		else if (tempField[i] == true && amtOfLiveNeighbors > 3) {
			field[i] = false;
		}
		else if (tempField[i] == false && amtOfLiveNeighbors == 3) {
			field[i] = true;
		}
	}

	std::system("cls");
	showField();
}

GameManager::~GameManager()
{
}
