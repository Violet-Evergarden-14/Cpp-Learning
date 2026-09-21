#include "ListNode.h"
#include "List.h"
using namespace std;

template <typename T> void List<T>::init() {
	header = new ListNode<T>;
	trailer = new ListNode<T>;
	header->succ = trailer;
	header->pred = nullptr;
	trailer->pred = header;
	trailer->succ = nullptr;
	_size = 0;
}

template <typename T> T& List<T>::operator[](Rank r) const {
	ListNodePosi(T) p = first();
	while (r-- > 0) p = p->succ;
	return p->data;
}

template <typename T> ListNodePosi(T) List<T>::find(T const& e, int n, ListNodePosi(T) p) const {
	while (n-- > 0) {
		if (p->data == e) return p;
		else p = p->pred;
	}
	return nullptr;
}

template <typename T> ListNodePosi(T) List<T>::insert_as_first(T const& e) {
	_size++;
	header->insert_as_succ(e);
}

template <typename T> ListNodePosi(T) List<T>::insert_as_last(T const& e) {
	_size++;
	trailer->insert_as_pred(e);
}

template <typename T> ListNodePosi(T) List<T>::insert_before(ListNodePosi(T) p, T const& e) {
	_size++;
	p->insert_as_pred(e);
}

template <typename T> ListNodePosi(T) List<T>::insert_after(ListNodePosi(T) p, T const& e) {
	_size++;
	p->insert_as_succ(e);
}

template <typename T> ListNodePosi(T) ListNode<T>::insert_as_pred(T const& e) {
	ListNode<T> x = new ListNode<T>(e, pred, this);
	pred->succ = x; pred = x;
	return x;
}

template <typename T> ListNodePosi(T) ListNode<T>::insert_as_succ(T const& e) {
	ListNode<T> x = new ListNode<T>(e, this, succ);
	succ->pred = x; succ = x;
	return x;
}

template <typename T> void List<T>::copy_nodes(ListNodePosi(T) p, int n) {
	init();
	while (n-- > 0) {insert_as_last(p->data); p = p->succ;}
}

template <typename T> List<T>::List(List<T> const& L) {
	copy_nodes(L.first(), L._size);
}

template <typename T> List<T>::List(List<T> const& L, Rank r, int n) {
	copy_nodes(L[r], n);
}

template <typename T> List<T>::List(ListNodePosi(T) p, int n) {
	copy_nodes(p, n);
}

template <typename T> T List<T>::remove(ListNodePosi(T) p) {
	T e = p->data;
	p->pred->succ = p->succ; p->succ->pred = p->pred;
	delete p; _size--;
	return e;
}

template <typename T> int List<T>::clear() {
	int old_size = _size;
	while (_size > 0) remove(header->succ);
	return old_size;
}

template <typename T> List<T>::~List() {
	clear();
	delete header;
	delete trailer;
}

template <typename T> int List<T>::deduplicate() {
	if (_size < 2) return 0;
	int old_size = _size;
	ListNodePosi(T) p = first(); Rank r = 0;
	while (p != trailer) {
		ListNodePosi(T) q = find(p->data, r, p);
		if (q != nullptr) remove(q);
		else r++;
		p = p->succ;
	}
	return old_size - _size;
}

template <typename T> void List<T>::traverse(void (*visit)(T&)) {
	for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ) visit(p->data);
}

template <typename T> template <typename VST>
void List<T>::traverse(VST& visit) {
	for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ) visit(p->data);
}

template <typename T> int List<T>::uniquify() {
	if (_size < 2) return 0;
	int old_size = _size;
	ListNodePosi(T) p; ListNodePosi(T) q;
	for (p = header, q = p->succ; q != trailer; p = q, q = q->succ) {
		if (p != header && p->data = q->data) {
			remove(q);
			q = p;	
		} 
	}
	return old_size - _size;
}

template <typename T> ListNodePosi(T) List<T>::search(T const& e, int n, ListNodePosi(T) p) const {
	while (n-- > 0) {
		if ((p = p->pred)->data <= e) break;        // first, operate p = p->pred, set the result(current p) as the element; then, operate .element->data <= e
	}
	return p;
}

template <typename T> void List<T>::sort(ListNodePosi(T) p, int n) {
	switch (rand() % 3) {
		case 0: insertion_sort(p, n); break;
		case 1: selection_sort(p, n); break;
		default: merge_sort(p, n); break;
	}
}

template <typename T> void List<T>::insertion_sort(ListNodePosi(T)& p, int n) {
	for (int r = 0; r < n; r++) {
		insert_after(search(p->data, r, p), p->data);
		p = p->succ; remove(p->pred);
	}
}

