#pragma once
#include "RuleSet.h"
#include <vector>

class NormalRules : public RuleSet
{
public:
	
	std::vector<bool*> applyRules(std::vector<bool*> field, int fieldWidth, int fieldHeight);
	
	NormalRules();
	~NormalRules();
};

