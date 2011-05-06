//#include "Formula.h"
//
//class Constant : public Formula {
//	public:
//		Constant(int);
//		~Constant();
//		void print();
//		void print(int);
//		Formula * derivative();
//		int evaluate();
//
//	private:
//		int val;
//
//};

#include "Constant.h"
#include <iostream>
using namespace std;

Constant::Constant(int i) {
	val = i;
}

Constant::~Constant() {
	return;
}

void Constant::print() {
	cout << val;
}

void Constant::print(int i) {
	cout << val;
}

Formula *Constant::derivative() {
	return new Constant(0);
}

int Constant::evaluate(int i) {
	return val;
}
