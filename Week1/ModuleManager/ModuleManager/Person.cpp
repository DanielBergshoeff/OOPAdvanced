#include "stdafx.h"
#include "Person.h"


Person::Person(std::string personFirstName, std::string personLastName)
	:firstName(personFirstName), lastName(personLastName)
{
	id = currentId;
	currentId++;
}

Person::Person() {}


int Person::currentId = 0;


Person::~Person()
{
}
