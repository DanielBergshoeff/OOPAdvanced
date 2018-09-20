// ModuleManager.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Module.h"
#include "Student.h"
#include "Teacher.h"
#include <vector>
#include <iostream>

using namespace std;

//Print relevant module information
void ShowModuleInformation(vector<Module*> tempModules) {
	auto i = tempModules.begin();
	while (i != tempModules.end()) {
		cout << (*i)->getInformation();
		i++;
	}
}

//Print EC count per student
void ShowStudentECCount(vector<Student*> tempStudents) {
	auto i = tempStudents.begin();
	while (i != tempStudents.end()) {
		cout << (*i)->firstName + " " + (*i)->lastName + " will receive " + std::to_string((*i)->getECcount()) + " ECs\n";
		i++;
	}
}

//Assign a student at least 1 module and at most all three modules
void AssignStudentRandomModules(Student* s, vector<Module*> modules) {
	int rndNumber1 = rand() % 2;
	int rndNumber2 = rand() % 2;
	int rndNumber3 = rand() % 2;
	if (rndNumber1 == 0) {
		modules[0]->addStudent(s);
	}
	if (rndNumber2 == 0) {
		modules[1]->addStudent(s);
	}
	if (rndNumber3 == 0) {
		modules[2]->addStudent(s);
	}
	if (rndNumber1 == 1 && rndNumber2 == 1 && rndNumber3 == 1) {
		int rndNumber4 = rand() % 3;
		if (rndNumber4 == 0) {
			modules[0]->addStudent(s);
		}
		else if (rndNumber4 == 1) {
			modules[1]->addStudent(s);
		}
		else if (rndNumber4 == 2) {
			modules[2]->addStudent(s);
		}
	}
}

int main()
{
	vector<Student*> students;
	vector<Module*> modules;
	Teacher* teachers[3];

	//Add three modules to the module vector
	for (size_t i = 0; i < 3; i++)
	{
		Module* module = new Module("Module nr. " + std::to_string(i), 3);
		modules.push_back(module);
	}

	//Add 10 students to the student vector and assign random modules to the student
	for (size_t i = 0; i < 10; i++)
	{
		Student* student = new Student("Student nr.", std::to_string(i));
		students.push_back(student);

		AssignStudentRandomModules(student, modules);
	}

	//Add special student Jack to all three modules
	Student* student0 = new Student("Special", "Jack");
	students.push_back(student0);
	modules[0]->addStudent(student0);
	modules[1]->addStudent(student0);
	modules[2]->addStudent(student0);

	//Add three students and assign them to the modules
	Teacher* teacher0 = new Teacher("James", "Bond");
	Teacher* teacher1 = new Teacher("Mr", "Smith");
	Teacher* teacher2 = new Teacher("Jack", "Black");
	teachers[0] = teacher0;
	teachers[1] = teacher1;
	teachers[2] = teacher2;

	modules[0]->setTeacher(teachers[0]);
	modules[1]->setTeacher(teachers[1]);
	modules[2]->setTeacher(teachers[2]);

	ShowModuleInformation(modules);
	ShowStudentECCount(students);

	//Set ecs from module 1 to 5 ec
	if (modules[1]->setEc(5)) {
		cout << "\n" + modules[1]->name + " has been changed to contain 5 EC\n\n";
	}
	ShowStudentECCount(students);

	//Remove special student Jack from module 0
	modules[0]->removeStudent(student0);

	ShowModuleInformation(modules);

	char returnLetter;
	cin >> returnLetter;

    return 0;
}



