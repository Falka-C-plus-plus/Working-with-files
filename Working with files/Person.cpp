#include "Person.h"

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

std::ostream& operator<<(std::ostream& os, const Person* person)
{
	os << "Person name: "<<person->getName()<<std::endl<<"Person age: "<<person->getAge()<<std::endl;
	return os;
}



bool Person::operator==(Person* obj)
{
	if (obj->age == this->age && strcmp(obj->name, this->name)) {
		return true;
	}
	return false;
}
