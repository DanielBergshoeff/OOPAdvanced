#include "stdafx.h"
#include "HealthyRules.h"


HealthyRules::HealthyRules()
{
}

std::vector<bool*> HealthyRules::applyRules(std::vector<bool*> field, int fieldWidth, int fieldHeight) {
	std::vector<bool*> tempField;

	for (size_t i = 0; i < field.size(); i++)
	{
		tempField.push_back(new bool(*field[i]));
	}

	for (int i = 0; i < field.size(); i++)
	{
		int amtOfLiveNeighbors = getAmtOfNeighbours(i, field, fieldWidth, fieldHeight);

		if (*(field[i]) == true && amtOfLiveNeighbors < 2) {
			*(tempField[i]) = false;
		}
		else if (*(field[i]) == true && amtOfLiveNeighbors > 4) {
			*(tempField[i]) = false;
		}
		else if (*(field[i]) == false && (amtOfLiveNeighbors == 3 || amtOfLiveNeighbors == 2)) {
			*(tempField[i]) = true;
		}
	}

	return tempField;

}

HealthyRules::~HealthyRules()
{
}
