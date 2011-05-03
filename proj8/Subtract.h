#include "Formula.h"

class Subtract : public Formula {
	public:
		Subtract(Formula*, Formula*);
		~Subtract(void);
		void print();
		void print(int);
		Formula *derivative();
		int evaluate();
	private:
		Formula *left;
		Formula *right;
};
