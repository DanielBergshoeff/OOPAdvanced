#include <iostream>
#include "Parent.h"

using namespace std;

int main() {

    Parent* p1 = new Parent("Parent1");
    cout << "P1:" << *p1 << endl;

    Parent* p2 = new Parent(*p1); // roept de copy constructor aan
    cout << "P2:" << *p2 << endl;

    Parent* p3 = new Parent("Parent3");
    cout << "P3:" << *p3 << endl;

    *p3 = *p1; // roept de assignment operator aan
    cout << "P3:" << *p3 << endl;

    delete p1;
    delete p2;
    delete p3;

    return 0;
}