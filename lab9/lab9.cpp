#include "vector3.h"
#include <iostream>
using namespace std;

int main() {
	int i = 0,j = 0,k = 0;
	cout << "Length of array1: ";
	cin >> i; 
	Vector3 *v1 = new Vector3(i);
	for (; i>0; i--) {
		cout << "num " << j++ << ": ";
		cin >> k;
		v1->addElem(k);
	}

	cout << "Length of array2: ";
	cin >> i; 
	Vector3 *v2 = new Vector3(i);
	j = 0;
	for (; i>0; i--) {
		cout << "num " << j++ << ": ";
		cin >> k;
		v2->addElem(k);
	}

	cout << v1->length() << endl;
	cout << v2->length() << endl;
	try {
		cout << v1->dotProduct(v2) << endl;
	} catch (...) {
		cout << "can't calculate dotProduct" << endl;
	}
	delete v1;
	delete v2;
	return 0;
}

