#pragma once
#include <vector>
#include <mutex>
#include <iostream>

template<typename T>
class concurrent_vector
{
public:
	void push_back(T t);
	T getByIndex(int i);
private:
	std::vector<T> myVector;
	std::mutex myVector_mutex;
};

template<typename T>
void concurrent_vector<T>::push_back(T t) {
	std::lock_guard<std::mutex> lock(myVector_mutex);
	myVector.push_back(t);
	std::cout << myVector.back() << std::endl;
}

template<typename T>
T concurrent_vector<T>::getByIndex(int i) {
	std::lock_guard<std::mutex> lock(myVector_mutex);
	return myVector[i];
}
