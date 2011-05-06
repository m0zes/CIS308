#pragma once
#include "Formula.h"
#include "Multiply.h"
#include "Subtract.h"
#include "Constant.h"

class Exponent : public Formula {
	public:
		Exponent(Formula*, Formula*);
		~Exponent(void);
		void print();
		void print(int);
		Formula *derivative();
		int evaluate(int);
	private:
		Formula *left;
		Formula *right;
};
