#include "person.h"

Person::Person(string n, int a) {
	name = n;
	age = a;
}

void Person::print(void) {
	cout << name << " " << age << endl;
}
