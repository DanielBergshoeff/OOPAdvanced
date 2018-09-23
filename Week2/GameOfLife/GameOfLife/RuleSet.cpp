#include "stdafx.h"
#include "RuleSet.h"


RuleSet::RuleSet()
{
	
}


int RuleSet::getAmtOfNeighbours(int i, std::vector<bool*> field, int fieldWidth, int fieldHeight) {
	nrs1 = { 1, -1, fieldWidth, -fieldWidth, fieldWidth + 1, -fieldWidth + 1, fieldWidth - 1, -fieldWidth - 1 };
	nrs2 = { 1, -1, fieldWidth, fieldWidth + 1, fieldWidth - 1 };
	nrs3 = { 1, -1, -fieldWidth, -fieldWidth + 1, -fieldWidth - 1 };
	nrs4 = { 1, -fieldWidth, -fieldWidth + 1, fieldWidth, fieldWidth + 1 };
	nrs5 = { -1, -fieldWidth, -fieldWidth - 1, fieldWidth, fieldWidth - 1 };
	nrs6 = { 1, fieldWidth, fieldWidth + 1 };
	nrs7 = { -1, -fieldWidth, -fieldWidth - 1 };

	int amtOfLiveNeighbors = 0;
	std::vector<int> nrs0;

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
		if (*(field[i + nrs0[j]]) == true) {
			amtOfLiveNeighbors++;
		}
	}

	return amtOfLiveNeighbors;
}

RuleSet::~RuleSet()
{
}
