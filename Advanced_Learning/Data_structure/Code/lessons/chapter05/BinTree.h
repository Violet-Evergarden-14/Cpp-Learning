#include "BinNode.h"

template <typename T>
class BinTree {
protected:
	int _size; BinNodePos(T) _root;
	virtual int update_height(BinNodePos(T) x);     // why virtual? some trees have different definition of height
													// so it will be overrided in some cases
	void update_height_above(BinNodePos(T) x);
public:
	BinTree(): _size(0), _root(nullptr) {};
	~BinTree() {if (_size > 0) remove(_root);}
	int size() const {return _size;}
	bool empty() const {return !_root;}
	BinNodePos(T) root() const {return _root;}
	BinNodePos(T) insert_as_root(const T& e);
	BinNodePos(T) insert_as_lc(BinNodePos(T) x, const T& e);           // insert as a child
	BinNodePos(T) insert_as_rc(BinNodePos(T) x, const T& e);
	BinNodePos(T) attach_as_lc(BinNodePos(T) x, BinTree<T>*& Tree);    // insert the whole tree
	BinNodePos(T) attach_as_rc(BinNodePos(T) x, BinTree<T>*& Tree);
	int remove(BinNodePos(T) x);
	BinTree<T>* secede(BinNodePos(T) x);        // delete the tree whose root is x, and then get the whole tree whose root is x
	
	template <typename VST> void trav_level(VST& visit) {if (_root) _root->trav_level(visit);}
	template <typename VST> void trav_pre(VST& visit) {if (_root) _root->trav_pre(visit);}
	template <typename VST> void trav_in(VST& visit) {if (_root) _root->trav_in(visit);}
	template <typename VST> void trav_post(VST& visit) {if (_root) _root->trav_post(visit);}
	
	bool operator<(BinTree<T> const& t) {return _root && t._root && lt(_root, t._root);}
	bool operator==(BinTree<T> const& t) {return _root && t._root && (_root == t._root);}
};