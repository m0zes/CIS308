#include "Formula.h"

class Variable : public Formula {
	public:
		Variable();
		~Variable();
		void print();
		void print(int);
		Formula * derivative();
		int evaluate();
};
