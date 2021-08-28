#include "Person.h"
#include <fstream>
#include <iostream>
using namespace std;
Person::Person()
{
	name = nullptr;
	age = 0;
}

Person::~Person()
{
	delete[] name;
}

Person::Person(const char* name)
{
	this->name = _strdup(name);
	age = 0;
}
Person::Person(const char* name,int age)
{
	this->name = _strdup(name);
	this->age = age;
}
char* Person::getName()const
{
	return name;
}

int Person::getAge()const
{
	return age;
}

void Person::SaveFile(const char* filename)
{
	ofstream outdata;
	outdata.open(filename);
	if (!outdata) {
		cout << "Saving error!\n";
		return;
	}
	outdata << name << endl << age;
	cout << "Saved\n";
}

void Person::LoadFile(const char* filename)
{
	ifstream indata;
	indata.open(filename);
	if (!indata) {
		cout << "Load error!\n";
		return;
	}
	name = new char[256];
	char* buf = new char[256];
	if (!indata.eof())
		indata >> name;
	if (!indata.eof())
		indata >> buf;

	age = atoi(buf);
	cout << "Loaded\n";
}

std::ostream& operator<<(std::ostream& os, const Person* person)
{
	os << "Person name: "<<person->getName()<<std::endl<<"Person age: "<<person->getAge()<<std::endl;
	return os;
}



//bool Person::operator==(const Person* obj)const
//{
//	if (obj->age == this->age && strcmp(obj->name, this->name)) {
//		return true;
//	}
//	return false;
//}
