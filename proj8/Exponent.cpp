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

Exponent::Exponent(Formula* l, Formula* r) {

}
Exponent::~Exponent() {
	if (left != NULL) 
		delete left;
	if (right != NULL)
		delete right;
	
}
void Exponent::print() {
	cout << left->print() << "^" << right->print();
}
void Exponent::print(int i) {
	cout << left->print(i) << "^" << right->print(i);
}
Formula *Exponent::derivative() {
	return new Multiply(right, new Exponent(left, new Subtract(right, new Constant(1))));
}
int Exponent::evaluate() {
	return (left->evaluate() ** right->evaluate());
}
