// ParentChildPtr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Parent.h"

int main()
{
	shared_ptr<Parent> p1 = std::make_shared<Parent>("Parent1");
	cout << "P1:" << *p1 << endl;

	shared_ptr<Parent> p2 = std::make_shared<Parent>(*p1); // roept de copy constructor aan
	cout << "P2:" << *p2 << endl;

	shared_ptr<Parent> p3 = std::make_shared<Parent>("Parent3");
	cout << "P3:" << *p3 << endl;

	shared_ptr<Parent> p30 = p3;
	cout << *p30 << endl;
	cout << "Reference number: " << p3.use_count() << endl;

	shared_ptr<Parent> p31 = p30;
	cout << *p31 << endl;
	cout << "Reference number: " << p3.use_count() << endl;

	shared_ptr<Parent> p32 = p31;
	cout << *p32 << endl;
	cout << "Reference number: " << p3.use_count() << endl;

	*p3 = *p2; // roept de assignment operator aan
	cout << "P3:" << *p3 << endl;

	cout << *p32 << endl;

	return 0;
}
