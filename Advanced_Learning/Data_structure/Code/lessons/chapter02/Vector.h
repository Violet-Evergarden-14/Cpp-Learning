#ifndef VECTOR_H_
#define VECTOR_H_

typedef int Rank;
#define DEFAULT_CAPACITY 3

template <typename T> class Vector {
protected:
	Rank _size;
	int _capacity;
	T* _elem;
	void copy_from(T* const A, Rank lo, Rank hi);
	void expand();
	void shrink();
	bool bubble(Rank lo, Rank hi);
	void bubble_sort(Rank lo, Rank hi);
	Rank max(Rank lo, Rank hi);
	void selection_sort(Rank lo, Rank hi);
	void merge(Rank lo, Rank mi, Rank hi);
	void merge_sort(Rank lo, Rank hi);
	Rank partition(Rank lo, Rank hi);
	void quich_sort(Rank lo, Rank hi);
	void heap_sort(Rank lo, Rank hi);
public:
// constructor
	Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) {
		_elem = new T[_capacity = c];
		for (_size = 0; _size < s; _elem[_size++] = v);
	}
	Vector(T const* A, Rank lo, Rank hi) {copy_from(A, lo, hi);}
	Vector(T const* A, Rank n) {copy_from(A, 0, n);}
	Vector(Vector const& V, Rank lo, Rank hi) {copy_from(V._elem, lo, hi);}
	Vector(Vector const& V) {copy_from(V._elem, 0, V._size);}
// destructor
	~Vector() {delete[] _elem;}
// read-only interface
	Rank size() const {return _size;}
	bool empty() const {return !_size;}
	int disordered() const;
	Rank find(T const& e, Rank lo, Rank hi);					// ordered search
	Rank find(T const& e) {return find(e, 0, _size);}
	Rank search(T const& e, Rank lo, Rank hi);					// unordered search
	Rank search(T const& e) {return search(e, 0, _size);}
// mutable interface
	T& operator[](Rank r) const;
	Vector<T>& operator=(Vector<T> const& V);
	T remove(Rank r);
	int remove(Rank lo, Rank hi);
	Rank insert(Rank r, T const& e);
	Rank insert(T const& e) {insert(_size, e);}
	void sort(Rank lo, Rank hi);
	void sort() {sort(0, _size);}
	void unsort(Rank lo, Rank hi);
	void unsort() {unsort(0, _size);}
	int deduplicate();
	int uniquify();
// traverse
	void traverse(void (*)(T&));
	template <typename VST> void traverse(VST&);
};

#endif