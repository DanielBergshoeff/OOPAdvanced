#pragma once
#include <vector>

using namespace std;

template<class T>
class Sorting {
public:
	void put(T t);
	T get();
	int size();

private:
	T* elements;
	int sizeArray = 0;
};

template<class T>
inline void Sorting<T>::put(T t)
{
	T* temp = new T[sizeArray];
	for (int i = 0; i < sizeArray; i++)
	{
		temp[i] = elements[i];
	}
	sizeArray++;

	elements = new T[sizeArray];
	for (int i = 0; i < sizeArray-1; i++)
	{
		elements[i] = temp[i];
	}

	elements[sizeArray - 1] = t;

	cout << "Added element: " << t << endl;
}

template<class T>
inline T Sorting<T>::get() {
	T t = elements[0];

	sizeArray--;
	T* temp = new T[sizeArray];
	for (int i = 0; i < sizeArray; i++)
	{
		temp[i] = elements[i+1];
	}

	elements = new T[sizeArray];
	for (int i = 0; i < sizeArray; i++)
	{
		elements[i] = temp[i];
	}


	cout << "Returned element: " << t << endl;
	return t;	
}

template<class T>
inline int Sorting<T>::size() {
	cout << "The array has size: " << sizeArray << endl;
	return sizeArray;
}
