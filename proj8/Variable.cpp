//#include "Formula.h"
//
//class Variable : public Formula {
//	public:
//		Variable();
//		~Variable();
//		void print();
//		void print(int);
//		Formula * derivative();
//		int evaluate();
//};
#include "Variable.h"

Variable::Variable() {
	return;
}

Variable::~Variable() {
	return;
}

void Variable::print() {
	cout << "x";
}

void Variable::print(int i) {
	cout << i;
}

Formula * derivative() {
	return new Constant(1);
}

int evaluate() {
	throw "Cannot Evaluate a Variable!";
}
