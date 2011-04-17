/******************************************************************************
 * Name: Adam Tygart                                                          * 
 * Date: April 21.                                                            * 
 * Assignment: Project 7: BinaryTrees                                         * 
 * ************************************************************************** *
 * Create a menu to input print and reverse binary trees.                     *
 *****************************************************************************/

#include <iostream>
using namespace std;
#include "binarytree.h"

/*
 * Constructor for BinaryTree. Takes in an int
 * Creates a new Node root, and sets initial values for the internal state
 */
BinaryTree::BinaryTree(int i) {
	root = new Node(i);
	reversed = false;
	count = 1;
}

/*
 * Destructor for BinaryTree. Tells root to delete it's children, then deletes
 * root
 */
BinaryTree::~BinaryTree(void) {
	root->Delete();
	delete root;
}

/*
 * Add: takes in an int, recurses down the tree and adds the item to the
 * correct place on the tree.
 */
void BinaryTree::Add(int i) {
	Node *tmp = root;
	bool added = false;
	while (!added) {
		if (i < tmp->Data) {
			if (tmp->lcu) {
				tmp = tmp->lc;
			} else {
				tmp->lc = new Node(i);
				count++;
				tmp->lcu = true;
				break;
			}
		} else if (i > tmp->Data) {
			if (tmp->rcu) {
				tmp = tmp->rc;
			} else {
				tmp->rc = new Node(i);
				tmp->rcu = true;
				count++;
				break;
			}
		} else {
			break;
		}
	}
}

/*
 * Reverse: changes the direction of the print statement.
 */
void BinaryTree::Reverse(void) {
	reversed = !reversed;
}

/*
 * Print: outputs the size of the tree, then calls print on the node, with an
 * argument telling it the direction.
 */
void BinaryTree::Print(void) {
	cout << "Tree size = " << count << endl;
	cout << "---------------" << endl;
	root->Print(reversed);
}
