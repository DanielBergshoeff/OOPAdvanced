#pragma once
#include <vector>
class RuleSet
{
public:
	int getAmtOfNeighbours(int i, std::vector<bool*> field, int fieldWidth, int fieldHeight);
	virtual std::vector<bool*> applyRules(std::vector<bool*> field, int fieldWidth, int fieldHeight) = 0;

	RuleSet();
	~RuleSet();

private:
	std::vector<int> nrs1;
	std::vector<int> nrs2;
	std::vector<int> nrs3;
	std::vector<int> nrs4;
	std::vector<int> nrs5;
	std::vector<int> nrs6;
	std::vector<int> nrs7;
};

