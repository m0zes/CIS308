//class Subtract : public Formula {
//	public:
//		Subtract(Formula*, Formula*);
//		~Subtract(void);
//		void print();
//		void print(int);
//		Formula *derivative();
//		int evaluate();
//	private:
//		Formula *left;
//		Formula *right;
//};

#include "Subtract.h"

Subtract::Subtract(Formula* l, Formula* r) {
	left = l;
	right = r;
}
Subtract::~Subtract() {
	if (left != NULL) 
		delete left;
	if (right != NULL)
		delete right;
}
void Subtract::print() {
	cout << left->print() << "+" << right->print();
}
void Subtract::print(int i) {
	cout << left->print(i) << "+" << right->print(i);
}
Formula *Subtract::derivative() {
	return new Subtract(left->derivative(), right->derivative());
}
int Subtract::evaluate() {
	return (left->evaluate() - right->evaluate());
}
