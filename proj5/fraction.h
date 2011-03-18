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
