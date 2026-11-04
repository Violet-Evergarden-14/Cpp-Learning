#include "BinTree.h"
#include "../chapter04/Stack.h"
#include "../chapter04/Queue.h"

template <typename T>
int BinTree<T>::update_height(BinNodePos(T) x) {
	return x->height = 1 + max(stature(x->lc), stature(x->rc));
}

template <typename T>
void BinTree<T>::update_height_above(BinNodePos(T) x) {
	while (x) {update_height(x); x = x->parent;}
}

template <typename T>
BinNodePos(T) BinTree<T>::insert_as_root(const T& e) {
	_size = 1; return _root = new BinNode(e);
}

template <typename T>
BinNodePos(T) BinTree<T>::insert_as_lc(BinNodePos(T) x, const T& e) {
	_size++; x->insert_as_lc(e);
	update_height_above(x);
	return x->lc;
}

template <typename T>
BinNodePos(T) BinTree<T>::insert_as_rc(BinNodePos(T) x, const T& e) {
	_size++; x->insert_as_rc(e);
	update_height_above(x);
	return x->rc;
}

template <typename T>
static void release(BinNodePos(T) x) {
    if (x == nullptr) return;
    release(x->lc);
    release(x->rc);
    delete x;
}

template <typename T>
static void release(BinTree<T>*& S) {
    if (S) {
        release(S->_root);  // 释放 S 的节点
        delete S;           // 释放 BinTree 对象本身，不包含 S 这个指针
    }
}

template <typename T>
BinNodePos(T) BinTree<T>::attach_as_lc(BinNodePos(T) x, BinTree<T>*& Tree) {
	x->lc = Tree->_root;
	if (x->lc != nullptr) x->lc->parent = x;
	_size += Tree->_size; update_height_above(x);
	Tree->_root = nullptr; Tree->_size = 0; release(Tree); Tree = nullptr;
	return x;
}

template <typename T>
BinNodePos(T) BinTree<T>::attach_as_rc(BinNodePos(T) x, BinTree<T>*& Tree) {
	x->rc = Tree->_root;
	if (x->rc != nullptr) x->rc->parent = x; 
	Tree->_root = nullptr; Tree->_size = 0; release(Tree); Tree = nullptr;
	return x;
}

template <typename T>
static int remove_at(BinNodePos(T) x) {
	if (x == nullptr) return 0;
	int n = remove_at(x->lc) + remove_at(x->rc) + 1;
	delete x->data; delete x;
	return n;
}

template <typename T>
int BinTree<T>::remove(BinNodePos(T) x) {
	from_parent_to(*x) = nullptr;
	update_height_above(x->parent);
	int n = remove_at(x); _size -= n; return n;
}

template <typename T>
BinTree<T>* BinTree<T>::secede(BinNodePos(T) x) {
	from_parent_to(*x) = nullptr;
	update_height_above(x->parent);
	BinTree<T>* Tree = new BinTree<T>(); Tree->_root = x; x->parent = nullptr;
	Tree->_size = x->size(); _size -= Tree->_size;
	return Tree;
}

template <typename T, typename VST>
void trav_pre_r(BinNodePos(T) x, VST& visit) {
	if (x == nullptr) return;
	visit(x->data);
	trav_pre_r(x->lc);
	trav_pre_r(x->rc);
}

template <typename T, typename VST>
void trav_post_r(BinNodePos(T) x, VST& visit) {
	if (x == nullptr) return;
	trav_pre_r(x->lc);
	trav_pre_r(x->rc);
	visit(x->data);
}

template <typename T, typename VST>
void trav_in_r(BinNodePos(T) x, VST& visit) {
	if (x == nullptr) return;
	trav_pre_r(x->lc);
	visit(x->data);
	trav_pre_r(x->rc);
}

template <typename T, typename VST>
static void visit_along_left_branch(BinNodePos(T) x, VST& visit, Stack<BinNodePos(T)>& s) {
	while (x != nullptr) {
		visit(x->data);
		s.push(x->rc);
		x = x->lc;
	}
}

template <typename T, typename VST>
void trav_pre_i2(BinNodePos(T) x, VST& visit) {
	Stack<BinNodePos(T)> s;
	while (true) {
		visit_along_left_branch(x, visit, s);
		if (s.empty() == true) break;
		x = s.pop();
	}
}

template <typename T>
static void go_along_left_branch(BinNodePos(T) x, Stack<BinNodePos(T)>& s) {
	while (x != nullptr) {
		s.push(x);
		x = x->lc;
	}
}

template <typename T, typename VST>
void trav_in_i1(BinNodePos(T) x, VST& visit) {
	Stack<BinNodePos(T)> s;
	while (true) {
		go_along_left_branch(x, s);
		if (s.empty() == true) break;
		x = s.pop(); visit(x->data);
		x = x->rc;
	}
}

template <typename T>
BinNodePos(T) BinNode<T>::succ() {                // trav_in's succ
	BinNodePos(T) s = this;
	if (rc) {
		s = rc;
		while (has_left_child(s)) s = s->lc;
	} else {
		while (is_right_child(*s)) s = s->parent;
		s = s->parent;
	}
	return s;
}

template <typename T, typename VST>
void trav_in_i2(BinNodePos(T) x, VST& visit) {
	Stack<BinNodePos(T)> s;
	while (true) {
		if (x) {s.push(x); x = x->lc}
		else if (!s.empty()) {x = s.pop(); visit(x->data); x = x->rc;}
		else break;
	}
}

template <typename T, typename VST>
void trav_in_i3(BinNodePos(T) x, VST& visit) {
	bool backtrack = false;
	while (true) {
		if (backtrack == false && has_left_child(*x)) x = x->lc;
		else {
			visit(x->data);
			if (has_right_child(*x)) {
				x = x->rc;
				backtrack = false;
			} else {
				x = x->succ();
				if (x == nullptr) break;
				backtrack = true;
			}
		}
	}
}

template <typename T>
static void goto_HLVFL(Stack<BinNodePos(T)>& s) {
	while (BinNodePos(T) x = s.top()) {
		if (has_left_child(*x)) {
			if (has_right_child(*x)) s.push(x->rc);
			s.push(x->lc);
		} else s.push(x->rc);
	}
	s.pop();
}

template <typename T, typename VST>
void trav_post_i(BinNodePos(T) x, VST& visit) {
	Stack<BinNodePos(T)> s; 
	if (x) s.push(x);
	while (!s.empty()) {
		if (s.top() != x->parent) goto_HLVFL(s);
		x = s.pop(); visit(x->data);
	}
}

template <typename T> template <typename VST>
void BinNode<T>::trav_level(VST& visit) {
	Queue<BinNodePos(T)> q;
	q.enqueue(this);
	while (!q.empty()) {
		BinNodePos(T) x = q.dequeue(); visit(x->data);
		if (has_left_child(*x)) q.enqueue(x->lc);
		if (has_right_child(*x)) q.enqueue(x->rc);
	}
}