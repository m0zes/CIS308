//#include "Formula.h"
//
//class Exponent : public Formula {
//	public:
//		Exponent(Formula*, Formula*);
//		~Exponent(void);
//		void print();
//		void print(int);
//		Formula *derivative();
//		int evaluate();
//	private:
//		Formula *left;
//		Formula *right;
//};

#include "Exponent.h"
#include "Multiply.h"
#include "Subtract.h"
#include "Constant.h"
#include <iostream>
#include <cmath>
using namespace std;

Exponent::Exponent(Formula* l, Formula* r) {
	left = l;
	right = r;
}
Exponent::~Exponent() {
	if (left != NULL) 
		delete left;
	if (right != NULL)
		delete right;
	
}
void Exponent::print() {
	cout << "(";
	left->print();
	cout << "^";
	right->print();
	cout << ")";
}
void Exponent::print(int i) {
	cout << "(";
	left->print(i);
	cout << "^";
	right->print(i);
	cout << ")";
}
Formula *Exponent::derivative() {
	return new Multiply(right, new Exponent(left, new Subtract(right, new Constant(1))));
}
int Exponent::evaluate(int i) {
	return (int) pow(left->evaluate(i), right->evaluate(i));
}
