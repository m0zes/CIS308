#include <iostream>
using namespace std;
#include "mystring.h"
#include "mystring.cpp"

int main(void) {
	MyString ms;

	cin >> ms;
	ms[0] = 'B';

	cout << ms;

	return 0;
}
