#pragma once
#include "Formula.h"

class Add : public Formula {
	public:
		Add(Formula*, Formula*);
		~Add(void);
		void print();
		void print(int);
		Formula *derivative();
		int evaluate(int);
	private:
		Formula *left;
		Formula *right;
};
