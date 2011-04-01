template <class T>
class Set {
	public:
		Set<T> Union(Set<T>*);
		Set<T> Intersection(Set<T>*);
		Set(void);
		~Set(void);
		void Add(T);
		int GetLength();
		T Get(int);
	private:
		T *list;
		int length;
		int maxlength;
};

template <class T>
Set<T>::Set(void) {
	length = 0;
	maxlength = 3;
	list = new T[maxlength+1];
}

template <class T>
Set<T>::~Set(void) {
	delete list;
}

template <class T>
Set<T> Set<T>::Union (Set<T> *other) {
	return new Set<T>;
}

template <class T>
Set<T> Set<T>::Intersection(Set<T> *other) {
	return new Set<T>;
}

template <class T>
void Set<T>::Add(T i) {
	if (length == maxlength) {
		maxlength *= 2;
		T *tmp = new T[maxlength+1];
		for (int j = 0; j <= length; j++)
			tmp[j] = list[j];
		delete list;
		list = tmp;
	}
	list[length++] = i;
}

template <class T>
int Set<T>::GetLength() {
	return length;
}

template <class T>
T Set<T>::Get(int i) {
	return list[i];
}
