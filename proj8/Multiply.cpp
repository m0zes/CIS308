//class Multiply : public Formula {
//	public:
//		Multiply(Formula*, Formula*);
//		~Multiply(void);
//		void print();
//		void print(int);
//		Formula *derivative();
//		int evaluate();
//	private:
//		Formula *left;
//		Formula *right;
//};

#include "Multiply.h"
#include "Add.h"
#include <iostream>
using namespace std;

Multiply::Multiply(Formula* l, Formula* r) {
	left = l;
	right = r;
}
Multiply::~Multiply() {
	if (left != NULL) 
		delete left;
	if (right != NULL)
		delete right;
}
void Multiply::print() {
	cout << "(";
	left->print();
	cout << "*";
	right->print();
	cout << ")";
}
void Multiply::print(int i) {
	cout << "(";
	left->print(i);
	cout << "*";
	right->print(i);
	cout << ")";
}
Formula *Multiply::derivative() {
	return new Add(new Multiply(left->derivative(), right), new Multiply(left, right->derivative()));
}
int Multiply::evaluate(int i) {
	return (left->evaluate(i) * right->evaluate(i));
}
