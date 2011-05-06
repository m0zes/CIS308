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
#include "Constant.h"
#include <iostream>
using namespace std;

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

Formula * Variable::derivative() {
	return new Constant(1);
}

int Variable::evaluate(int i) {
	return i;
}
