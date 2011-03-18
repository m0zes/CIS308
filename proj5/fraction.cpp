/******************************************************************************
 * Name: Adam Tygart                                                          *
 * Date: 3/27/11                                                              *
 * Assignment: Project 5: Fractions                                           *
 * ****************************************************************************
 * Reads in two "Fractions" and a Maths operator, and performs that Maths     *
 * operation on the fraction. Prints out the Maths operation and the result.  *
 *****************************************************************************/
#include "fraction.h"
#include <iostream>
using namespace std;

/*
 * setValues: A "new" function for those that don't know new yet
 * num is the numerator of the fraction.
 * den is the denominator of the fration.
 * Reduces the fraction immediately.
 */
void Fraction::setValues(int num, int den) {
	numerator = num;
	denominator = den;
	Fraction::reduce(numerator, denominator);
}

/*
 * plus: adds the fractions together, returning a new fraction.
 * input one of the fractions to add, with this being the other.
 * Returns the resultant fraction.
 */
Fraction Fraction::plus(Fraction input) {
	Fraction out;
	int n, d;
	n = (numerator * input.denominator) + (input.numerator * denominator);
	d = denominator * input.denominator;
	out.setValues(n, d);
	return out;
}

/*
 * minus: subtracts the fractions together, returning a new fraction.
 * input one of the fractions to subtract, with this being the other.
 * Returns the resultant fraction.
 */
Fraction Fraction::minus(Fraction input) {
	Fraction out;
	int n, d;
	n = (numerator * input.denominator) - (input.numerator * denominator);
	d = denominator * input.denominator;
	out.setValues(n, d);
	return out;
}

/*
 * times: multiplys the fractions together, returning a new fraction.
 * input one of the fractions to multiply, with this being the other.
 * Returns the resultant fraction.
 */
Fraction Fraction::times(Fraction input) {
	Fraction out;
	int n, d;
	n = (numerator * input.numerator);
	d = denominator * input.denominator;
	out.setValues(n, d);
	return out;
}

/*
 * divide: divides the fractions together, returning a new fraction.
 * input one of the fractions to divide, with this being the other.
 * Returns the resultant fraction.
 */
Fraction Fraction::divide(Fraction input) {
	Fraction out;
	int n, d;
	n = (numerator * input.denominator);
	d = denominator * input.numerator;
	out.setValues(n, d);
	return out;
}

/*
 * print: prints out this fraction. does not output a newline.
 */
void Fraction::print(void) {
	cout << numerator << '/' << denominator;
}

/*
 * reduce: finds the greatest common denominator and reduces the fraction.
 * a: "numerator"
 * b: "denominator"
 * if the denominator divides into the numerator evenly, that is the gcd,
 * if not, the denominator becomes the numerator and the remainder becomes the
 * denominator for the next pass. See: Euclid's Algorithm.
 */
void Fraction::reduce(int a, int b) {
	if (a%b == 0) {
		numerator /= b;
		denominator /= b;
	} else {
		Fraction::reduce(b, a%b);
	}
}
