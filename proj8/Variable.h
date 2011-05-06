#pragma once
#include "Formula.h"
#include "Constant.h"

class Variable : public Formula {
	public:
		Variable();
		~Variable();
		void print();
		void print(int);
		Formula * derivative();
		int evaluate(int);
};
