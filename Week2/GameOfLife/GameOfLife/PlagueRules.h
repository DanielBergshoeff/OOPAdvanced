#pragma once
#include "RuleSet.h"
class PlagueRules : public RuleSet
{
public:
	std::vector<bool*> applyRules(std::vector<bool*> field, int fieldWidth, int fieldHeight);

	PlagueRules();
	~PlagueRules();
};

