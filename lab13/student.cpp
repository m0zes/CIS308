#include "student.h"

Student::Student(string n, int a, string m) : Person(n, a) {
	major = m;
}

void Student::print(void) {
	cout << name << " " << age << " " << major << endl;
}
