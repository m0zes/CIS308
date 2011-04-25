#pragma once
#include <iostream>
using namespace std;

#include "person.h"

class Student: public Person {
	protected:
		string major;
	public:
		void print(void);
		Student(string, int, string);
};
