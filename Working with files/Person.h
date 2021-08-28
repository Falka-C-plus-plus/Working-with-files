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
	void SaveFile(const char* filename = "data.txt");
	void LoadFile(const char* filename = "data.txt");

	friend std::ostream& operator<< (std::ostream& out, const Person* person);
	//bool operator==(const Person* obj)const;
};
std::ostream& operator<<(std::ostream& os, const Person* person);

