#pragma once
#include "RuleSet.h"
class HealthyRules : public RuleSet
{
public:
	std::vector<bool*> applyRules(std::vector<bool*> field, int fieldWidth, int fieldHeight);

	HealthyRules();
	~HealthyRules();
};

