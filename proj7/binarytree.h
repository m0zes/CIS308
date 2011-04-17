#pragma once
#include <iostream>
using namespace std;

class Node {
	public:
		Node *lc;
		Node *rc;
		int Data;
		bool lcu;
		bool rcu;
		Node(int i) {
			Data = i;
			lcu = false;
			rcu = false;
		}
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
