#include <iostream>
#include "Sorting.h"
#include <string>

int main()
{
	//I created this file with the intention of 
	//starting with the sorting function. Somehow
	//ended up making the queue-thing first, but
	//with sorting names. Sorry about that!

	Sorting<float> floatCollection;
	Sorting<std::string> stringCollection;

	floatCollection.put(1.0f);
	floatCollection.put(2.0f);
	floatCollection.put(3.0f);
	floatCollection.put(4.0f);

	floatCollection.size();

	floatCollection.get();
	floatCollection.get();
	float f = floatCollection.get();

	floatCollection.size();
	
	//std::cout << f;

	char l = 'e';
	std::cin >> l;
}
