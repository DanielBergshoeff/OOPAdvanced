#include <iostream>
#include <algorithm>
#include <utility> 
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
	// gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
	// 1) de vector in 2 nieuwe vectoren te splitsen, 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na
	sort(colours.begin(), colours.end());

	auto lower_than_purple = [](string s) {return s < "purple"; };
	auto pt = partition(colours.begin(), colours.end(), lower_than_purple);

	vector<string> beforePurple;
	std::copy(colours.begin(), pt, back_inserter(beforePurple));
	vector<string> afterPurple;
	std::copy(pt, colours.end(), back_inserter(afterPurple));

	for (vector<string>::iterator it = beforePurple.begin(); it != beforePurple.end(); it++)
	{
		cout << *it << " ";
	}


	cout << endl;

	for (vector<string>::iterator it = afterPurple.begin(); it != afterPurple.end(); it++)
	{
		cout << *it << " ";
	}



	// 2) alle elementen UPPERCASE te maken.
	// 3) alle dubbele te verwijderen



	vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
	// gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
	// 1) alle negatieve elementen te verwijderen
	// 2) voor alle elementen te bepalen of ze even of oneven zijn
	// 3) de som, het gemiddelde, en het product van alle getallen te berekenen


	char l = 'd';
	cin >> l;

	return 0;
}