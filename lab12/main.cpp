#include <iostream>
using namespace std;

#include "rectangle.h"
#include "square.h"

int main(void) {
	Rectangle rect(3,4);
	Square sq(5);
	cout << rect.area() << endl;
	cout << sq.area() << endl;
	rect.print();
	sq.print();
	return 0;
}
