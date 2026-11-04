#ifndef BIN_NODE_H_
#define BIN_NODE_H_

#define BinNodePos(T) BinNode<T>*
#define stature(p) ((p) ? (p)->height : -1)

// macro
#define is_root(x) (!((x).parent))
#define is_left_child(x) (!is_root(x) && (&(x) == (x).parent->lc))
#define is_right_child(x) (!is_root(x) && (&(x) == (x).parent->rc))
#define has_parent(x) (!is_root(x))
#define has_left_child(x) ((x).lc)
#define has_right_child(x) ((x).rc)
#define has_child(x) (has_left_child(x) || has_right_child(x))
#define has_both_child(x) (has_left_child(x) && has_right_child(x))
#define is_leaf(x) (!has_both_child(x))
#define sibling(p) (is_left_child(*(p)) ? (p)->parent->rc : (p)->parent->lc)      // brother
#define uncle(p) (sibling((p)->parent))                                           // uncle
#define from_parent_to(x) (is_root(x) ? _root : sibling(x))

typedef enum {RB_RED, RE_BLACK} RBColor;

template <typename T>
struct BinNode {
	T data;
	BinNodePos(T) parent; BinNodePos(T) lc; BinNodePos(T) rc;
	int height;
	int npl;                 // null path length (can be replaced by height)
	RBColor color;           // color (red/ black tree)

	BinNode(): data(T()), parent(nullptr), lc(nullptr), rc(nullptr), height(0), npl(1), color(RB_RED) {};
	BinNode(T e = T(), BinNodePos(T) p = nullptr, BinNodePos(T) l = nullptr, BinNodePos(T) r = nullptr, int _height = 0, int _npl = 1, RBColor _color = RB_RED):
			data(e), parent(p), lc(l), rc(r), height(_height), npl(_npl), color(_color) {}

	int size();              // size of its successed tree(containing itself)
	BinNodePos(T) insert_as_lc(const T&);
	BinNodePos(T) insert_as_rc(const T&);
	BinNodePos(T) succ();
	template <typename VST> void trav_level(VST&);
	template <typename VST> void trav_pre(VST&);
	template <typename VST> void trav_in(VST&);
	template <typename VST> void trav_post(VST&);

	bool operator<(BinNode const& bn) {return data < bn.data;}
	bool operator==(BinNode const& bn) {return data == bn.data;}
};

#endif