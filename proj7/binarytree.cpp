#include <iostream>
using namespace std;
#include "binarytree.h"
BinaryTree::BinaryTree(int i) {
	root = new Node(i);
	reversed = false;
	count = 1;
}
BinaryTree::~BinaryTree(void) {
	root->Delete();
	delete root;
}
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
void BinaryTree::Reverse(void) {
	reversed = !reversed;
}
void BinaryTree::Print(void) {
	cout << "Tree size = " << count << endl;
	cout << "---------------" << endl;
	root->Print(reversed);
}
