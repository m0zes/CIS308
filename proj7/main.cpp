/******************************************************************************
 * Name: Adam Tygart                                                          * 
 * Date: April 21.                                                            * 
 * Assignment: Project 7: BinaryTrees                                         * 
 * ************************************************************************** *
 * Create a menu to input print and reverse binary trees.                     *
 *****************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;

#include "binarytree.h"

/*
 * Main: Prints a menu to create a binary tree.
 * allows you to add, print, reverse, and quit.
 */
int main(void) {
	BinaryTree *bt;
	bool btused = false;
	int ans = 0;
	while (ans != 4) {
		cout << "Menu Display" << endl;
	        cout << "-------------" << endl;
		cout << "1) Enter Data" << endl;
		cout << "2) Print Tree" << endl;
		cout << "3) Reverse Tree" << endl;
		cout << "4) Quit" << endl;
		cout << "Enter your choice: ";
		cin >> ans;
		switch (ans) {
			case 1:
				cout << "Enter data for the tree: ";
				int tmp;
				cin >> tmp;
				if (btused)
					bt->Add(tmp);
				else { 
					bt = new BinaryTree(tmp);
					btused = true;
				}
				break;
			case 2:
				if (btused)
					bt->Print();
				break;
			case 3:
				if (btused)
					bt->Reverse();
				break;
			default:
				break;
		}
	}
	cout << "Press any key to continue . . . ";
	getc(stdin);
	if (btused)
		delete bt;
	return 0;
}
