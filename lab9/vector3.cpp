#include "vector3.h"
#include <iostream>
using namespace std;

Vector3::Vector3(int len) {
	vec = new int[len];
	size = len;
	curr = 0;
}

Vector3::~Vector3() {
	delete vec;
}

void Vector3::addElem(int i) {
	//cout << i << " curr: " << curr << endl;
	vec[curr++] = i;
}

int Vector3::length() {
	return size;
}

int Vector3::dotProduct(Vector3 *v) {
	int i;
	int t = 0;
	if (v->size == size) {
		for (i = 0; i < size; i++) {
			//cout << v->vec[i] << endl << vec[i] << endl;
			int j = v->vec[i] * vec[i];
			//cout << j << endl;
			t += j;
		}
	} else {
		throw "sizes not equal"; 
	}
	return t;
}
