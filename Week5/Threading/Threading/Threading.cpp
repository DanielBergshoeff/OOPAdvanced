// Threading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include "concurrent_vector.h"

int currentNumber = 0;
std::mutex currentNumber_mutex; 
std::vector<int> integers = std::vector<int>();
concurrent_vector<int> integersConcurrent;

void addNumberToVector(int i) {
	integers.push_back(i);
}

void addNumberToConcurrentVector(int i) {
	integersConcurrent.push_back(i);
}

void checkIndedOfVector(int i) {
	std::cout << integers[i] << std::endl;
}

void addLotsOfNumbersToVector() {
	for (size_t i = 0; i < 100; i++)
	{
		std::thread t1(addNumberToVector, i * 2);
		t1.detach();
		std::thread t2(addNumberToVector, i * 2 + 1);
		t2.detach();
		std::cout << integers[i * 2] << std::endl;
		std::cout << integers[i * 2 + 1] << std::endl;
	}
}

void checkLotsOfNumbersOfVector() {
	for (size_t i = 1; i < 6000; i++)
	{
		std::cout << "checking " << i << std::endl;
		int check = integers[i] - integers[i - 1];
		if (abs(check) > 1) {
			std::cout << "An error has occured at index " << i << " where the values are: " << integers[i] << " and " << integers[i - 1] << std::endl;
		}
	}
}

int main()
{
	std::thread t0(addLotsOfNumbersToVector);
	std::thread t1(addLotsOfNumbersToVector);
	std::thread t2(addLotsOfNumbersToVector);
	t0.detach();
	t1.detach();
	t2.detach();

	char c;
	std::cin >> c;

	//std::thread t1(checkLotsOfNumbersOfVector);

	/*for (size_t i = 0; i < 1000; i++)
	{
		std::thread t1(addNumberToConcurrentVector, i * 2);
		std::thread t2(addNumberToConcurrentVector, i * 2 + 1);
		t1.detach();
		t2.detach();
	}*/

	/*for (size_t i = 1; i < 2000; i++)
	{
		int check = integersConcurrent.getByIndex(i) - integersConcurrent.getByIndex(i - 1);
		if (abs(check) > 1) {
			std::cout << "An error has occured at index " << i << " where the values are: " << integersConcurrent.getByIndex(i) << " and " << integersConcurrent.getByIndex(i - 1) << std::endl;
		}
	}*/

	
} 



