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
	ListNodePosi(T) first() const {return header->succ;}
	ListNodePosi(T) last() const {return trailer->pred;}
	bool valid(ListNodePosi(T) p) {return p && (trailer != p) && (header != p);} // judge if p is legal (no judge whether it's in the list)
	int disordered() const;  // judge if it's ordered
	ListNodePosi(T) find(T const& e) const {return find(e, _size, trailer);}
	ListNodePosi(T) find(T const& e, int n, ListNodePosi(T) p) const;
	ListNodePosi(T) search(T const& e) const {return search(e, _size, trailer);}
	ListNodePosi(T) search(T const& e, int n, ListNodePosi(T) p) const;
	ListNodePosi(T) select_max(ListNodePosi(T) p, int n);
	ListNodePosi(T) select_max() {return select_max(header->succ, _size);}
// writable interface
	ListNodePosi(T) insert_as_first(T const& e);
	ListNodePosi(T) insert_as_last(T const& e);
	ListNodePosi(T) insert_before(ListNodePosi(T), T const& e);
	ListNodePosi(T) insert_after(ListNodePosi(T), T const& e);
	T remove(ListNodePosi(T) p);
	void merge(List<T>& L) {merge(this->first(), this->_size, L, L.first(), L._size);}
	void sort(ListNodePosi(T) p, int n);
	void sort() {sort(first(), _size);}
	int deduplicate();
	int uniquify();
	void reverse();
// traverse
	void traverse(void (*)(T&));
	template <typename VST> void traverse(VST&);
};