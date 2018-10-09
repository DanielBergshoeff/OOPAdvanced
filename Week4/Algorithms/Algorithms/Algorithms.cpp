#include <iostream>
#include <algorithm>
#include <utility> 
#include <vector>
#include <string>
#include <cctype>
#include <locale>
#include <numeric>

template <typename T>
void PrintVector(std::vector<T> v) {
	for (std::vector<T>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::cout << *it << " ";
	}
}

bool IsOdd(int i) { return ((i % 2) == 1); }

int main() {
	std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
	// gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
	// 1) de vector in 2 nieuwe vectoren te splitsen, 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na
	sort(colours.begin(), colours.end());

	auto lower_than_purple = [](std::string s) {return s < "purple"; };
	auto pt = partition(colours.begin(), colours.end(), lower_than_purple);

	std::vector<std::string> beforePurple;
	std::copy(colours.begin(), pt, back_inserter(beforePurple));
	std::vector<std::string> afterPurple;
	std::copy(pt, colours.end(), back_inserter(afterPurple));

	std::cout << "All colours alphabetically before purple: " << std::endl;
	PrintVector(beforePurple);

	std::cout << std::endl << std::endl << "All colours alphabetically after purple: " << std::endl;
	PrintVector(afterPurple);


	// 2) alle elementen UPPERCASE te maken.
	for (std::string &s : colours) {
		std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::toupper(c, std::locale()); });
	}

	std::cout << std::endl << std::endl << "All colours capitalised " << std::endl;
	PrintVector(colours);


	// 3) alle dubbele te verwijderen
	colours.erase(std::unique(colours.begin(), colours.end()));

	std::cout << std::endl << std::endl << "All doubles removed from vector: " << std::endl;
	PrintVector(colours);



	std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
	// gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
	// 1) alle negatieve elementen te verwijderen
	auto removeIndex = remove_if(numbers.begin(), numbers.end(), [](double value) {
		return value < 0;
	});
	numbers.erase(removeIndex, numbers.end());

	std::cout << std::endl << std::endl << "All numbers higher than or equal to 0: " << std::endl;
	PrintVector(numbers);

	// 2) voor alle elementen te bepalen of ze even of oneven zijn
	auto moveIndex = remove_if(numbers.begin(), numbers.end(), IsOdd);

	std::cout << std::endl << std::endl << "All odd numbers in vector: " << std::endl;
	std::vector<double> oddNumbers;
	std::copy(numbers.begin(), moveIndex, back_inserter(oddNumbers));
	PrintVector(oddNumbers);


	std::cout << std::endl << std::endl << "All even numbers in vector: " << std::endl;
	std::vector<double> evenNumbers;
	std::copy(moveIndex, numbers.end(), back_inserter(evenNumbers));
	PrintVector(evenNumbers);
	

	// 3) de som, het gemiddelde, en het product van alle getallen te berekenen
	double sum{ std::accumulate(numbers.begin(), numbers.end(), 0.0) };
	std::cout << std::endl << std::endl << "The sum of all numbers: " << sum;

	std::cout << std::endl << std::endl << "The average of all numbers: " << sum / numbers.size();

	double product{ std::accumulate(numbers.begin(), numbers.end(), 1.0, std::multiplies<double>()) };
	std::cout << std::endl << std::endl << "The product of all numbers: " << product;


	char l = 'd';
	std::cin >> l;

	return 0;
}

