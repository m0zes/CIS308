/******************************************************************************
 * Name: Adam Tygart                                                          *
 * Date: 3/27/11                                                              *
 * Assignment: Project 5: Fractions                                           *
 * ****************************************************************************
 * Reads in two "Fractions" and a Maths operator, and performs that Maths     *
 * operation on the fraction. Prints out the Maths operation and the result.  *
 *****************************************************************************/
#pragma once
class Fraction{
	public:
		void setValues(int, int);
		Fraction plus(Fraction);
		Fraction minus(Fraction);
		Fraction times(Fraction);
		Fraction divide(Fraction);
		void print(void);
	private:
		int numerator;
		int denominator;
		void reduce(int, int);
};
