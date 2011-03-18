#include "fraction.h"
#include <iostream>
using namespace std;

void Fraction::setValues(int num, int den) {
	numerator = num;
	denominator = den;
	Fraction::reduce(numerator, denominator);
}

Fraction Fraction::plus(Fraction input) {
	Fraction out;
	int n, d;
	n = (numerator * input.denominator) + (input.numerator * denominator);
	d = denominator * input.denominator;
	out.setValues(n, d);
	return out;
}

Fraction Fraction::minus(Fraction input) {
	Fraction out;
	int n, d;
	n = (numerator * input.denominator) - (input.numerator * denominator);
	d = denominator * input.denominator;
	out.setValues(n, d);
	return out;
}

Fraction Fraction::times(Fraction input) {
	Fraction out;
	int n, d;
	n = (numerator * input.numerator);
	d = denominator * input.denominator;
	out.setValues(n, d);
	return out;
}

Fraction Fraction::divide(Fraction input) {
	Fraction out;
	int n, d;
	n = (numerator * input.denominator);
	d = denominator * input.numerator;
	out.setValues(n, d);
	return out;
}

void Fraction::print(void) {
	cout << numerator << '/' << denominator;
}

void Fraction::reduce(int a, int b) {
	if (a%b == 0) {
		numerator /= b;
		denominator /= b;
	} else {
		Fraction::reduce(b, a%b);
	}
}
