#include <iostream>
#include "Sorting.h"
#include <string>
#include <vector>
#include <algorithm>


//Test making use of std::sort function
template <typename T, size_t size>
T* mySort(T(&array)[size])
{
	std::vector<T> tempVector (array, array+size);

	std::sort(tempVector.begin(), tempVector.end());

	for (size_t i = 0; i < size; i++)
	{
		array[i] = tempVector[i];
		cout << array[i] << " ";
	}

	return array;
}


//My own sorting function
template <typename T, size_t size>
T* mySecondSort(T(&array)[size])
{
	bool done = false;

	while (!done) {
		done = true;

		for (int i = 0; i < size; i++)
		{
			if (i != size - 1) {
				if (array[i] > array[i + 1])
				{
					auto temp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = temp;
					done = false;
				}
			}
		}

		for (size_t i = 0; i < size; i++)
		{
			cout << array[i] << " ";
		}

		cout << endl;
	}

	return array;
}

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

	int numbers[] = { 5, 3, 8, 22, 0, 100, 9, 4, 19 };
	string names[] = { "Peter", "Aaron", "Jack", "Daniel", "Valentine", "Bas" };
	mySecondSort(names);
	mySecondSort(numbers);
	
	//std::cout << f;

	char l = 'e';
	std::cin >> l;
}
