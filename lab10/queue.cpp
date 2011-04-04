#include <iostream>
using namespace std;
#include "node.cpp"
template <class T>
class Queue {
	public: 
		Node<T> *head;
		Node<T> *tail;
		int size;
		void enqueue(T);
		T dequeue();
		void print();
		Queue<T>(T);
		~Queue<T>(void);
};

template <class T>
void Queue<T>::enqueue(T val) {
	tail->next = new Node<T>(val);	
	tail = tail->next;
	size++;
}

template <class T>
T Queue<T>::dequeue() {
	T tmp = head->node;
	Node<T> *t = head->next;
	delete head;
	head = t;
	size--;
	return tmp;
}

template <class T>
void Queue<T>::print() {
	cout << head->node;
}

template <class T>
Queue<T>::Queue(T val) {
	head = new Node<T>(val);
	tail = head;
	size = 1;
}

template <class T> 
Queue<T>::~Queue() {
	for (int i = 0; i < size; i++)
		dequeue();
}
