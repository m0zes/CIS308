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

Divide::Divide(Formula* l, Formula* r) {
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
	cout << top->print() << "/" << bottom->print();
}
void Divide::print(int i) {
	cout << top->print(i) << "/" << bottom->print(i);
}
Formula *Divide::derivative() {
	return new Divide(new Subtract(new Multiply(top->derivative(), bottom), new Multiply(top, bottom->derivative)), new Exponent(bottom, new Constant(2)));
}
int Divide::evaluate() {
	return (top->evaluate() / bottom->evaluate());
}
