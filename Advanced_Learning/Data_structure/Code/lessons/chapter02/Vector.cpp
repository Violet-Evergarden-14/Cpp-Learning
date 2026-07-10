#include "Vector.h"
#include <iostream>
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
	T* oldelem = _elem; _elem = new T[_capacity <<= 1];
	for (int i = 0; i < _size; i++) _elem[i] = oldelem[i];
	delete[] oldelem;
}

template <typename T> void Vector<T>::shrink() {
	if (_capacity < DEFAULT_CAPACITY << 1) return;
	if (_size > _capacity >> 2) return;
	T* oldelem = _elem; _elem = new T[_capacity >>= 1];
	for (int i = 0; i < _size; i++) _elem[i] = oldelem[i];
	delete[] oldelem;
}

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

