#pragma once

#include <string>
#include <ostream>
#include "Child.h"

using namespace std;

class Parent {
    public:
        Parent(string name);

        Parent(Parent& other);

        virtual ~Parent();

        Parent& operator=(Parent& other);

        friend ostream& operator<<(ostream& os, const Parent& parent);

    private:
        string name;
		unique_ptr<Child> child;
};

