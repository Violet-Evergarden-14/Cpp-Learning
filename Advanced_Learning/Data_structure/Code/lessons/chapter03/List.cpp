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

