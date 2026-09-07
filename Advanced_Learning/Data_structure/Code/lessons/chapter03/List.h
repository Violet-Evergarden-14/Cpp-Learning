# include "ListNode.h"

template <typename T> class List {
private:
	int _size; ListNodePosi(T) header; ListNodePosi(T) trailer;
protected:
	void init();
	int clear();
	void copy_nodes(ListNodePosi(T), int);
	void merge(ListNodePosi(T)&, int, List<T>&, ListNodePosi(T), int);
	void merge_sort(ListNodePosi(T)&, int);
	void selection_sort(ListNodePosi(T)&, int);
	void insertion_sort(ListNodePosi(T)&, int);
public:
// constructor
	List() {init();}
	List(List<T> const& L);
	List(List<T> const& L, Rank r, int n);
	List(ListNodePosi(T) p, int n);
// destructor
	~List();
// read-only interface
	Rank size() const {return _size;}
	bool empty() const {return _size <= 0;}
	T& operator[](Rank r) const;     // low efficiency
	
// writable interface

};