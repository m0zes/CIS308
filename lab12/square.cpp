#include <iostream>
using namespace std;
#include "square.h"
Square::Square(int i) : Rectangle(i,i) {
}

void Square::print(void) {
	cout << "size " << width << " square" << endl;
}
