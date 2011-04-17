/******************************************************************************
 * Name: Adam Tygart                                                          * 
 * Date: April 21.                                                            * 
 * Assignment: Project 7: BinaryTrees                                         * 
 * ************************************************************************** *
 * Create a menu to input print and reverse binary trees.                     *
 *****************************************************************************/
#pragma once
#include <iostream>
using namespace std;

/*
 * Node: A node for a BinaryTree
 */
class Node {
	public:
		Node *lc;
		Node *rc;
		int Data;
		bool lcu;
		bool rcu;

		/*
		 * Constructor for node: Sets the Data and marks the childen as unused.
		 */
		Node(int i) {
			Data = i;
			lcu = false;
			rcu = false;
		}

		/*
		 * Delete: Recursively deletes the child nodes if they exist
		 */
		void Delete(void) {
			if (lcu) {
				lc->Delete();
				delete lc;
			}
			if (rcu) {
				rc->Delete();
				delete rc;
			}
		}

		/*
		 * Print: recursively prints the node and its children
		 * Takes in a boolean telling it what direction to print
		 */
		void Print(bool rev) {
			if (rev) {
				if (rcu)
					rc->Print(rev);
				cout << Data << endl;
				if (lcu)
					lc->Print(rev);
			} else {
				if (lcu)
					lc->Print(rev);
				cout << Data << endl;
				if (rcu)
					rc->Print(rev);
			}
		}
};

/*
 * BinaryTree: an object that holds Nodes and can quickly find items.
 */
class BinaryTree {
	public:
		void Add(int);
		void Reverse(void);
		void Print(void);
		BinaryTree(int);
		~BinaryTree(void);
	private:
		Node *root;
		bool reversed;
		int count;
};
