#include <iostream>
#include "queue.cpp"
using namespace std;

int main(void) {
	Queue<int> *q = new Queue<int>(1);
	for (int i = 2; i <= 100; i++) {
		q->enqueue(i);
	}

	for (int i = 1; i <= 100; i++) {
		q->print();
		q->dequeue();
	}

	delete q;
	return 0;
}
