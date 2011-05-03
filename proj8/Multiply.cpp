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
	cout << left->print() << "*" << right->print();
}
void Multiply::print(int i) {
	cout << left->print(i) << "*" << right->print(i);
}
Formula *Multiply::derivative() {
	return new Add(new Multiply(left->derivative(), right), new Multiply(left, right->derivative()));
}
int Multiply::evaluate() {
	return (left->evaluate() * right->evaluate());
}
