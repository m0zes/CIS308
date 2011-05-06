//class Divide : public Formula {
//	public:
//		Divide(Formula*, Formula*);
//		~Divide(void);
//		void print();
//		void print(int);
//		Formula *derivative();
//		int evaluate();
//	private:
//		Formula *top;
//		Formula *bottom;
//};

#include "Divide.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Exponent.h"
#include <iostream>
using namespace std;

Divide::Divide(Formula* t, Formula* b) {
	top = t;
	bottom = b;
}
Divide::~Divide() {
	if (top != NULL) 
		delete top;
	if (bottom != NULL)
		delete bottom;
}
void Divide::print() {
	cout << "(";
	top->print();
	cout << "/";
	bottom->print();
	cout << ")";
}
void Divide::print(int i) {
	cout << "(";
	top->print(i);
	cout << "/";
	bottom->print(i);
	cout << ")";
}
Formula *Divide::derivative() {
	return new Divide(new Subtract(new Multiply(top->derivative(), bottom), new Multiply(top, bottom->derivative())), new Exponent(bottom, new Constant(2)));
}
int Divide::evaluate(int i) {
	return (top->evaluate(i) / bottom->evaluate(i));
}
