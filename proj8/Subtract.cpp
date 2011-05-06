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
#include <iostream>
using namespace std;

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
	cout << "(";
	left->print();
	cout << "-";
	right->print();
	cout << ")";
}
void Subtract::print(int i) {
	cout << "(";
	left->print(i);
	cout << "-";
	right->print(i);
	cout << ")";
}
Formula *Subtract::derivative() {
	return new Subtract(left->derivative(), right->derivative());
}
int Subtract::evaluate(int i) {
	return (left->evaluate(i) - right->evaluate(i));
}
