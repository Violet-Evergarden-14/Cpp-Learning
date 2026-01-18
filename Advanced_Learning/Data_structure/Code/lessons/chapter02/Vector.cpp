#include <iostream>
using namespace std;

typedef int Rank;
#define DEFAULT_CAPACITY 3

template <typename T>
class Vector
{
protected: 
	Rank _size;        // 规模
	int  _capacity;    // 容量
	T*   _elem;        // 数据指针

	void copy_from(T const* A, Rank lo, Rank hi);  //// 复制数组区间 A[lo, hi)
	void expand();                                // 空间不足时扩容
	void shrink();                                // 装填因子过小时压缩

	bool bubble(Rank lo, Rank hi);                // 扫描交换
	void bubble_sort(Rank lo, Rank hi);            // 冒泡排序算法

	Rank max(Rank lo, Rank hi);                   // 选取最大元素
	void selection_sort(Rank lo, Rank hi);         // 选择排序算法

	void merge(Rank lo, Rank mi, Rank hi);        // 归并算法
	void merge_sort(Rank lo, Rank hi);             // 归并排序算法

	Rank partition(Rank lo, Rank hi);             // 轴点构造算法
	void quick_sort(Rank lo, Rank hi);              // 快速排序算法

	void heap_sort(Rank lo, Rank hi);               // 堆排序（稍后结合完全堆讲解）
	
public:
	// 构造与析构
	Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0);
	Vector(T const* A, Rank lo, Rank hi);
	Vector(T const* A, Rank n);
	Vector(Vector<T> const& V, Rank lo, Rank hi);
	Vector(Vector<T> const& V, Rank n);
	~Vector();

	// 重载
	Vector<T> & operator= (Vector<T> const&);

	// 只读访问接口
	Rank size() const;    // 显示_size值
};

// 构造与析构
template <typename T>
Vector<T>::Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0)
{
	_elem =  new T[_capacity = c];
	for (_size = 0; _size < c; _size++) {
		_elem[_size] = v;
	}
}

template <typename T>
Vector<T>::Vector(T const* A, Rank lo, Rank hi)
{
	copy_from(A, lo, hi);
}

template <typename T>
Vector<T>::Vector(T const* A, Rank n)
{
	copy_from(A, 0, n);
}

template <typename T>
Vector<T>::Vector(Vector<T> const& V, Rank lo, Rank hi)
{
	copy_from(V._elem, lo, hi);
}

template <typename T>
Vector<T>::Vector(Vector<T> const& V, Rank n)
{
	copy_from(V._elem, 0, n);
}

template <typename T>
Vector<T>::~Vector()
{
	delete[] _elem;
}

// public
template <typename T>
void Vector<T>::copy_from(T const* A, Rank lo, Rank hi)
{
	_elem = new T[_capacity = 2 * (hi - lo)];
	while (lo < hi) _elem[_size++] = A[lo++];
}

// 重载
template <typename T>
Vector<T>& Vector<T>::operator= (Vector<T> const& V)
{
	if (this->_elem) delete[] _elem;
	copy_from(V._elem, 0, V.size());
	return *this;
}

// 只读访问接口
template <typename T>
Rank Vector<T>::size() const
{
	return this._size;
}