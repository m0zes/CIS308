#pragma once
#include "Formula.h"
#include "Add.h"

class Multiply : public Formula {
	public:
		Multiply(Formula*, Formula*);
		~Multiply(void);
		void print();
		void print(int);
		Formula *derivative();
		int evaluate(int);
	private:
		Formula *left;
		Formula *right;
};
