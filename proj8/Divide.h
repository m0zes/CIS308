#pragma once
#include "Formula.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Exponent.h"

class Divide : public Formula {
	public:
		Divide(Formula*, Formula*);
		~Divide(void);
		void print();
		void print(int);
		Formula *derivative();
		int evaluate(int);
	private:
		Formula *top;
		Formula *bottom;
};
