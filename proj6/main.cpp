/******************************************************************************
 * Name: Adam Tygart                                                          * 
 * Date: April 10.                                                            * 
 * Assignment: Project 6: Sets                                                * 
 * ************************************************************************** *
 * Input sets and calculate the Unions and Intersections of the sets          *
 *****************************************************************************/
#include "set.cpp"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

/*
 * Main. Ask for two sets of integers.
 * Print the sorted sets
 * Ask for an intersection or union
 * Print the intersection or union
 */
int main(void) {
	string buff;
	cout << "Input Set 1 (  like num1,num2,...,numN): ";
	cin >> buff;

	char *tmp = strdup(buff.c_str());


	char *result = strtok(tmp, "(,)");

	Set<int> *s1 = new Set<int>;

	s1->Add(atoi(result));

	while(result != NULL) {
		result = strtok(NULL, "(,)");
		if (result != NULL)
			s1->Add(atoi(result));
	}

	cout << "Input Set 2 (  like num1,num2,...,numN): ";
	cin >> buff;

	free(tmp);

	tmp = strdup(buff.c_str());

	result = strtok(tmp, "(,)");
	Set<int> *s2 = new Set<int>;

	s2->Add(atoi(result));

	while(result != NULL) {
		result = strtok(NULL, "(,)");
		if (result != NULL)
			s2->Add(atoi(result));
	}

	free(tmp);

	cout << endl << "The sorted sets are:" << endl;
	for (int i = 0; i < s1->GetLength(); i++)
		cout << s1->Get(i) << " ";
	cout << endl << endl;
	for (int i = 0; i < s2->GetLength(); i++)
		cout << s2->Get(i) << " ";

	while ((buff != "u") && (buff != "i")) {
		cout << endl << endl << "Enter (i)ntersect or (u)nion: ";
		cin >> buff;
	}

	Set<int> *out;
	if (buff == "u") {
		cout << "Union: " << endl;
		out = s1->Union(s2);
	} else {
		cout << "Intersection: " << endl;
		out = s1->Intersection(s2);
	}

	for (int i = 0; i < out->GetLength(); i++)
		cout << out->Get(i) << " ";

	cout << endl;


	delete s1;
	delete s2;
	delete out;
	return 0;
}
