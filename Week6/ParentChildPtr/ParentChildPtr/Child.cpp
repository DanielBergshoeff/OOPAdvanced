#include "Child.h"
#include <iostream>

Child::Child(string name) {
    this->name = name;
	cout << this->name << " has been created" << std::endl;
}

Child::Child(const Child& other) {
    this->name = other.name;
	cout << this->name << " has been created" << std::endl;
}

Child::~Child()
{
	cout << this->name << " has been destroyed" << std::endl;
}

ostream& operator<<(ostream& os, const Child& child) {
    os << "name: " << child.name;
    return os;
}

