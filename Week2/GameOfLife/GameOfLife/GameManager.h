#pragma once
#include <vector>

class GameManager
{
public:
	int fieldWidth;
	int fieldHeight;

	std::vector<bool> field;

	void showField();

	void initField();
	void applyRules();

	GameManager(int fieldWidthPara, int fieldHeightPara);
	~GameManager();
};

