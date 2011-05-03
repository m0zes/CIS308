#include "Formula.h"

class Divide : public Formula {
	public:
		Divide(Formula*, Formula*);
		~Divide(void);
		void print();
		void print(int);
		Formula *derivative();
		int evaluate();
	private:
		Formula *top;
		Formula *bottom;
};
