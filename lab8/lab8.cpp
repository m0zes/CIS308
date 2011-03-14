#include "vector3.h"
#include <iostream>
using namespace std;

int main() {
	Vector3 v1;
	Vector3 v2;
	v1.addElem(1,2,3);
	v2.addElem(4,5,6);
	cout << v1.length() << endl;
	cout << v2.length() << endl;
	cout << v1.dotProduct(v2) << endl;
	return 0;
}

