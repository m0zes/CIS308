#pragma once
#include "vector3.h"

void Vector3::addElem(int i,int j,int k) {
	v1 = i;
	v2 = j;
	v3 = k;
}

int Vector3::length() {
	return 3;
}

int Vector3::dotProduct(Vector3 v) {
	int t = v.v1 * v1;
	t += v.v2 * v2;
	t += v.v3 * v3;
	return t;
}
