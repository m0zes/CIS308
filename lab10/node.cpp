template <class T>
class Node {
	public:
		T node;
		Node<T> *next;
		Node<T>(T);
};

template <class T>
Node<T>::Node(T val) {
	node = val;
}
