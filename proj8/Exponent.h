#include "Formula.h"

class Exponent : public Formula {
	public:
		Exponent(Formula*, Formula*);
		~Exponent(void);
		void print();
		void print(int);
		Formula *derivative();
		int evaluate();
	private:
		Formula *left;
		Formula *right;
};
