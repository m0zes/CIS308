/******************************************************************************
 * Name: Adam Tygart                                                          * 
 * Date: April 10.                                                            * 
 * Assignment: Project 6: Sets                                                * 
 * ************************************************************************** *
 * Input sets and calculate the Unions and Intersections of the sets          *
 *****************************************************************************/

/*
 * Set Class. Defines a templated class that holds a unique set of sorted items
 */
template <class T>
class Set {
	public:
		Set<T>* Union(Set<T>*);
		Set<T>* Intersection(Set<T>*);
		Set(void);
		~Set(void);
		void Add(T);
		int GetLength();
		T Get(int);
	private:
		T *list;
		bool *used;
		int length;
		int maxlength;
};

/*
 * Constructor. Creates a Typed Set object, and containers to hold the objects
 */
template <class T>
Set<T>::Set(void) {
	length = 0;
	maxlength = 3;
	list = new T[maxlength+1];
	used = new bool[maxlength+1];
	for (int i = 0; i < maxlength; i++ )
		used[i] = false;
}

/*
 * Destructor. Deletes the relevant allocated memory.
 */
template <class T>
Set<T>::~Set(void) {
	delete [] list;
	delete [] used;
}

/*
 * Union. Compares this Set object with another, and returns a Set object
 * containing the items in either.
 */
template <class T>
Set<T>* Set<T>::Union(Set<T> *other) {
	Set<T> *out = new Set<T>;
	for (int i = 0; i < length; i++)
		out->Add(list[i]);
	for (int i = 0; i < other->GetLength(); i++)
		out->Add(other->Get(i));

	return out;
}

/*
 * Intersection. Compares this Set object with another and returns a Set object
 * that contains the items that are in both of them.
 */
template <class T>
Set<T>* Set<T>::Intersection(Set<T> *other) {
	Set<T> *out = new Set<T>;

	int m = 0, o = 0;
	for (int i = 0; i < length + other->GetLength(); i++) {

		if (m >= length) {
			break;
		} else if (o >= other->GetLength()) {
			break;
		}

		if (list[m] == other->Get(o)) {
			out->Add(list[m]);
			m++;
			o++;
		} else if (list[m] < other->Get(o)) {
			m++;
		} else if (list[m] > other->Get(o)) {
			o++;
		}
	}

	return out;
}

/*
 * Add. Adds an item to the Set object. Checks for unique and sorts the list.
 * Resizes the underlying arrays as necessary.
 */
template <class T>
void Set<T>::Add(T i) {
	// Resize arrays
	if (length == maxlength) {
		maxlength *= 2;
		T *tmp = new T[maxlength+1];
		bool *btmp = new bool[maxlength+1];
		for (int j = 0; j <= length; j++) {
			tmp[j] = list[j];
			btmp[j] = used[j];
		}
		for (int j = length+1; j < maxlength; j++)
			btmp[j] = false;
		delete [] list;
		delete [] used;
		list = tmp;
		used = btmp;
	}

	// add item.
	for (int j = 0; j <= length; j++) {
		if ((i == list[j]) && (used[j] == true))
			break;

		if ((i < list[j]) && (used[j] == true)) {
			for (int k = length; k > j; k--) {
				list[k] = list[k-1];
				used[k] = true;
			}
			list[j] = i;
			used[j] = true;
			length++;
			break;
		} else if (used[j] == false) {
			list[j] = i;
			length++;
			used[j] = true;
			break;
		}
	}
}

/*
 * GetLength. Getter for the length property.
 */
template <class T>
int Set<T>::GetLength() {
	return length;
}

/*
 * Get. Returns the object at index i.
 */
template <class T>
T Set<T>::Get(int i) {
	return list[i];
}
