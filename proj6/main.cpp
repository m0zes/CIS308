#include "set.cpp"
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(void) {
	string buff;
	cout << "Input Set 1 (  like num1,num2,...,numN): ";
	cin >> buff;

	char *result = strtok(buff.c_str(), "(,)");
	Set<int> *s1 = new Set<int>;
	s1->Add(atoi(result));
	try {
		while(true) {
			result = strtok(NULL, " ,:");
			s1->Add(atoi(result));
		}
	} catch (...)

	cout << "Input Set 2 (  like num1,num2,...,numN): ";
	cin >> buff;

	*result = strtok(buff.c_str(), "(,)");
	Set<int> *s2 = new Set<int>;
	s2->Add(atoi(result));
	try {
		while(true) {
			result = strtok(NULL, " ,:");
			s2->Add(atoi(result));
		}
	} catch (...)

	cout << endl << "The sorted sets are:" << endl;
	for (int i = 0; i < s1->GetLength(); i++)
		cout << s1->Get(i) << " ";
	cout << endl << endl;
	for (int i = 0; i < s2->GetLength(); i++)
		cout << s2->Get(i) << " ";


	cout << endl << tmp->GetLength() << endl;
	delete tmp;
	return 0;
}
