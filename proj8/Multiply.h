#include "Formula.h"

class Multiply : public Formula {
	public:
		Multiply(Formula*, Formula*);
		~Multiply(void);
		void print();
		void print(int);
		Formula *derivative();
		int evaluate();
	private:
		Formula *left;
		Formula *right;
};
