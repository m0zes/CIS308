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
#include <iostream>
using namespace std;

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
	cout << "(";
	left->print(); 
	cout << "+";
	right->print();
	cout << ")";
}
void Add::print(int i) {
	cout << "(";
	left->print(i); 
	cout << "+";
	right->print(i);
	cout << ")";
}
Formula *Add::derivative() {
	return new Add(left->derivative(), right->derivative());
}
int Add::evaluate(int i) {
	return (left->evaluate(i) + right->evaluate(i));
}
