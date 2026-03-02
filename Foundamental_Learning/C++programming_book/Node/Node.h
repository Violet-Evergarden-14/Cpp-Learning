#ifndef NODE_H
#define NODE_H

template<class T>
class Node
{
private:
	Node<T>* next;
public:
	T data;

	Node(const T& _data, Node<T>* _next = 0): data(_data), next(_next) {};
	void insert_after(Node<T>* p);
	Node<T>* delete_after();
	Node<T>* next_node() {return next;}
	const Node<T>* next_node() const {return next;}
};

template<class T>
void Node<T>::insert_after(Node<T>* p) {
	p->next = next;
	next = p;
}

template<class T>
Node<T>* Node<T>::delete_after() {
	Node<T>* temp_ptr = next;
	if (next == nullptr) {return nullptr;}
	next = temp_ptr->next;
	return temp_ptr;
}



#endif