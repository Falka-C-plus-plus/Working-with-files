#pragma once
#include <iostream>
class Person
{
private:
	char* name;
	int age;
public:
	Person();
	~Person();
	Person(const char* name);
	Person(const char* name,int age);
	char* getName()const;
	int getAge()const;


	friend std::ostream& operator<< (std::ostream& out, const Person* person);
	bool operator==(Person* obj);
};
std::ostream& operator<<(std::ostream& os, const Person* person);

