#pragma once
#include <vector>
#include "RuleSet.h"
#include "NormalRules.h"
#include "HealthyRules.h"
#include "PlagueRules.h"
class GameManager
{
public:
	int fieldWidth;
	int fieldHeight;

	RuleSet* ruleSet;
	NormalRules* ruleSetNormal;
	HealthyRules* ruleSetHealthy;
	PlagueRules* ruleSetPlague;

	void applyRules();

	double getPercentageLiving();

	std::vector<bool*> field;

	void showField();

	void initField();

	GameManager(int fieldWidthPara, int fieldHeightPara);
	~GameManager();
};

