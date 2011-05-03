#include "Formula.h"

class Add : public Formula {
	public:
		Add(Formula*, Formula*);
		~Add(void);
		void print();
		void print(int);
		Formula *derivative();
		int evaluate();
	private:
		Formula *left;
		Formula *right;
};
