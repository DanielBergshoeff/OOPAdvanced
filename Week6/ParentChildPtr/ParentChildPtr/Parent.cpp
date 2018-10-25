#include <iostream>
#include "Parent.h"
#include <memory>
#include <utility>


Parent::Parent(string name) {
    this->name = name;
    string childName = "ChildOf" + name;
    this->child = make_unique<Child>(childName);
}

Parent::Parent(Parent& other) {
    cout << "Parent cctor" << endl;
    this->name = other.name;
    this->child = std::move(other.child);
}

Parent::~Parent() {
	cout << "Parent distructor" << endl;
}

Parent& Parent::operator=(Parent& other) {
    cout << "Parent assignment" << endl;

    if (this == &other) {
        return *this;
    }

    this->name = other.name;
    this->child = std::move(other.child);

    return *this;
}

ostream& operator<<(ostream& os, const Parent& parent) {
    os << "name: " << parent.name << " child: " << *parent.child;
    return os;
}
