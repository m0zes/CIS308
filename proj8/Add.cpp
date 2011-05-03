//class Add : public Formula {
//	public:
//		Add(Formula*, Formula*);
//		~Add(void);
//		void print();
//		void print(int);
//		Formula *derivative();
//		int evaluate();
//	private:
//		Formula *left;
//		Formula *right;
//};

#include "Add.h"

Add::Add(Formula* l, Formula* r) {
	left = l;
	right = r;
}
Add::~Add() {
	if (left != NULL) 
		delete left;
	if (right != NULL)
		delete right;
}
void Add::print() {
	cout << left->print() << "+" << right->print();
}
void Add::print(int i) {
	cout << left->print(i) << "+" << right->print(i);
}
Formula *Add::derivative() {
	return new Add(left->derivative(), right->derivative());
}
int Add::evaluate() {
	return (left->evaluate() + right->evaluate());
}
