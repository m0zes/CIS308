/******************************************************************************
 * Name: Adam Tygart                                                          *
 * Date: 3/27/11                                                              *
 * Assignment: Project 5: Fractions                                           *
 * ****************************************************************************
 * Reads in two "Fractions" and a Maths operator, and performs that Maths     *
 * operation on the fraction. Prints out the Maths operation and the result.  *
 *****************************************************************************/
#include <iostream>
#include <string>
#include "fraction.h"
#include <stdlib.h>
#include <string.h>
using namespace std;

/*
 * main: Reads in two fractions and a maths operator. performs the maths and
 * outputs the operation and the resultant fraction.
 */
int main(void) {
	string temp, ns, ds;
	int index, n, d, i;
	Fraction f1, f2;
	cout << "Enter the first fraction (e.g. 9/5): ";
	cin >> temp;
	index = temp.find('/');
	n = atoi(temp.substr(0, index ).c_str());
	d = atoi(temp.substr(index+1).c_str());
	f1.setValues(n,d);
	cout << "Enter the second fraction (e.g. 9/5): ";
	cin >> temp;
	index = temp.find('/');
	n = atoi(temp.substr(0, index ).c_str());
	d = atoi(temp.substr(index+1).c_str());
	f2.setValues(n,d);
	cout << "Enter the operator (+, -, *, /): ";
	cin >> temp;
	Fraction fout;
	if (temp.at(0) == '/')
		fout = f1.divide(f2);
	else if (temp.at(0) == '*')
		fout = f1.times(f2);
	else if (temp.at(0) == '+')
		fout = f1.plus(f2);
	else if (temp.at(0) == '-')
		fout = f1.minus(f2);
	else {
		cout << "invalid operator!\n";
		return 5;
	}

	f1.print();
	cout << temp.at(0);
	f2.print();
	cout << " = ";
	fout.print();
	cout << "\n";
	//cout << "\n";
	//f1.print();
	//cout << "\n";
	//f2.print();
	return 0;
}
