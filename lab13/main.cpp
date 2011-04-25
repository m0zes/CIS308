#include <iostream>
using namespace std;
#include <stdlib.h>

#include "person.h"
#include "student.h"

int main(void) {
	Person **parr = (Person **) malloc(3 * sizeof(Person*));

	parr[0] = new Student("Adam", 23, "CmpSci");
	parr[1] = new Student("Bob", 18, "CmpEn");
	parr[2] = new Person("Kuffs", 26);

	parr[0]->print();
	parr[1]->print();
	parr[2]->print();

	delete parr[0];
	delete parr[1];
	delete parr[2];

	free(parr);
	return 0;
}
