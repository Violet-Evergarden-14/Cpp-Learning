#include "Vector.h"
#include <iostream>
// #include "..\fibonacci\fib.h" we think that there is a file called "fib.h"
using namespace std;

template <typename T>
void Vector<T>::copy_from(T* const A, Rank lo, Rank hi) {
	if (_elem) delete[] _elem;
	_elem = new T[_capacity = 2 * (hi - lo)]; _size = 0;
	while (lo < hi) _elem[_size++] = A[lo++];
} // already get _size, _capacity, _elem

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T> const& V) {
	if (_elem) delete[] _elem;
	copy_from(V._elem, 0, V.size());
	return *this;
}

template <typename T> Vector<T>::~Vector() {delete[] _elem;}

template <typename T> void Vector<T>::expand() {
	if (_size < _capacity) return;
	if (_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;
	T* old_elem = _elem; _elem = new T[_capacity <<= 1];
	for (int i = 0; i < _size; i++) _elem[i] = old_elem[i];
	delete[] old_elem;
}

template <typename T> void Vector<T>::shrink() {
	if (_capacity < DEFAULT_CAPACITY << 1) return;
	if (_size > _capacity >> 2) return;
	T* old_elem = _elem; _elem = new T[_capacity >>= 1];
	for (int i = 0; i < _size; i++) _elem[i] = old_elem[i];
	delete[] old_elem;
} // you can use this to copy 0~n-1 of the elements(first set _size = n, then use shrink() directly)

template <typename T> T& Vector<T>::operator[](Rank r) const {return _elem[r];}

template <typename T>
void permute(Vector<T>& V) {
	for (int i = V._size; i > 0; i--) {
		swap(V[i - 1], V[rand() % i])
	}
}

template <typename T> void Vector<T>::unsort(Rank lo, Rank hi) {
	T* V = _elem + lo;   // view V as a son-Vector
	for (int i = hi - lo; i > 0; i--) {
		swap(V[i - 1], V[rand() % i]);
	}
}

template <typename T>
Rank Vector<T>::find(T const& e, Rank lo, Rank hi) {
	while ((lo < hi--) && e != _elem[hi])
	return hi;  // hi < lo indicates that position do not exist
}

template <typename T>
Rank Vector<T>::insert(Rank r, T const& e) {
	expand();
	for (int i = _size; i > r; i--) _elem[i] = _elem[i - 1];
	_elem[r] = e; _size++;
	return r;
}

template <typename T>
int Vector<T>::remove(Rank lo, Rank hi) {
	if (lo == hi) return 0;
	while (hi < _size) _elem[lo++] = _elem[hi++];
	_size = lo;
	shrink();
	return hi - lo;  // return the number of elements deleted
}

template <typename T>
T Vector<T>::remove(Rank r) {
	T e = _elem[r];
	remove(r, r + 1);
	return e;
}

template <typename T> int Vector<T>::deduplicate() {
	int old_size = _size;
	Rank i = 1;
	while (i < _size) {
		(find(_elem[i], 0, i) < 0) ? i++ : remove(i);
	}
	return old_size - _size;
}

template <typename T> void Vector<T>::traverse(void (*visit)(T&)) {
	for (int i = 0; i < _size; i++) visit(_elem[i]);
}

template <typename T> template <typename VST>
void Vector<T>::traverse(VST& visit) {
	for (int i = 0; i < _size; i++) visit(_elem[i]);
}

template <typename T> struct Increase {
	virtual void operator()(T& e) {e++;}
};

template <typename T> void increase(Vector<T>& V) {
	V.traverse(Increase<T>());
}

template <typename T> int Vector<T>::disordered() const {
	int n = 0;
	for (int i = 1; i < _size; i++) {
		if (_elem[i - 1] > _elem[i]) n++;
	}
	return n;
}

// ordered vector
// low version
/*
template <typename T> int Vector<T>::uniquify() {
	int old_size = _size; int i = 0;
	while (i < _size) {
		(_elem[i] == _elem[i - 1]) ? remove(i) : i++;
	}
	return old_size - _size;
}
*/

// high version
template <typename T> int Vector<T>::uniquify() {
	Rank i = 0, j = 0;
	while (++j < _size) {
		if (_elem[i] != _elem[j]) _elem[i++] = _elem[j];
	}
	_size = ++i; shrink(); // set _size and use shrink() to just keep _size elements
	return j - i;
}

template <typename T> Rank Vector<T>::search(T const& e, Rank lo, Rank hi) {
	return (rand() % 2) ? bin_search(_elem, e, lo, hi) : fib_search(_elem, e, lo, hi);
}

// version A - bin
template <typename T> Rank bin_search(Vector<T>& V, T const& e, Rank lo, Rank hi) {
	Rank mi = (lo + hi) >> 1;
	while (lo < hi) {
		Rank mi = (lo + hi) >> 1;
		if (e > V[mi]) lo = mi + 1;
		else if (e < V[mi]) hi = mi;
		else return mi;
	}
	return -1;
}

// version A - fib
/*
template <typename T> Rank fib_search(Vector<T>& V, T const& e, Rank lo, Rank hi) {
	Fib fib(hi - lo);
	while (lo < hi) {
		while (hi - lo < fib.get()) fib.prev();
		Rank mi = lo + fib.get() - 1;
		if (e > V[mi]) lo = mi + 1;
		else if (e < V[mi]) hi = mi;
		else return mi;
	}
	return -1;
}
*/

// version B - bin
/*
template <typename T> Rank bin_search(Vector<T>& V, T const& e, Rank lo, Rank hi) {
	while (hi - lo > 1) {
		Rank mi = (lo + hi) >> 1;
		(e < V[mi]) ? hi = mi : lo = mi;
	}
	return (e == V[lo]) ? lo : -1;
}
*/

// version C - bin (this version aims to find the last element not bigger than the target)
/*
template <typename T> Rank bin_search(Vector<T>& V, T const& e, Rank lo, Rank hi) {
	while (lo < hi) {
		Rank mi = (lo + hi) >> 1;
		(e < V[mi]) ? hi = mi : lo = mi + 1;
	}
	return --lo;
}
*/

template <typename T>
void Vector<T>::sort(Rank lo, Rank hi) {
	switch (rand() % 5) {
		case 1: bubble_sort(lo, hi); break;
		case 2: selection_sort(lo, hi); break;
		case 3: merge_sort(lo, hi); break;
		case 4: heap_sort(lo, hi); break;
		default: quich_sort(lo, hi); break;
	}
}

template <typename T>
void Vector<T>::bubble_sort(Rank lo, Rank hi) {
	while (!(bubble(lo, hi--)));
}

template <typename T>
bool Vector<T>::bubble(Rank lo, Rank hi) {
	bool sorted = true;
	while (++lo < hi) {
		if (_elem[lo - 1] > _elem[lo]) {
			sorted = false;
			swap(_elem[lo - 1], _elem[lo]);
		}
	}
	return sorted;
}

template <typename T>
void Vector<T>::merge_sort(Rank lo, Rank hi) {
	if (hi - lo < 2) return;
	Rank mi = (lo + hi) >> 1;
	merge_sort(lo, mi); merge_sort(mi, hi);
	merge(lo, mi, hi);
}

template <typename T>
void Vector<T>::merge(Rank lo, Rank mi, Rank hi) {
	T* A = _elem + lo;
	lb = mi - lo; T* B = new T[lb];
	for (Rank i = 0; i < lb; B[i] = A[i++]);
	int lc = hi - mi; T* C = _elem + mi;
	for (Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc);) {
		if ((j < lb) && (!(k < lc) || (B[j] <=  C[k]))) A[i++] = B[j++];
		if ((k < lc) && (!(j < lb) || (B[j] > C[k]))) A[i++] = C[k++];
	}
	delete[] B;
}