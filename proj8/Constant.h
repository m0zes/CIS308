#pragma once
#include "Formula.h"

class Constant : public Formula {
	public:
		Constant(int);
		~Constant();
		void print();
		void print(int);
		Formula * derivative();
		int evaluate(int);

	private:
		int val;

};
