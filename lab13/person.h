#pragma once
#include <iostream>
using namespace std;
class Person {
	protected:
		string name;
		int age;
	public:
		Person(string, int);
		virtual void print(void);
};
