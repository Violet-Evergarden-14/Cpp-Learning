#include <vector>
using namespace std;

template <typename T>
class Stack {
private:
	vector<T> _elem;
	vector<T> min_elem;
	int _size;
public:
	Stack() {_size = 0;}

	int size() const {return _size;}
	bool is_empty() const {return !_size;}
	void push(const T& e) {
		_elem.push_back(e);
		if (_size == 0) min_elem.push_back(e);
		else min_elem.push_back(min(e, min_elem[_size - 1]));
		_size++;
	}
	const T& top() const {return _elem[_size - 1];}
	T pop() {
		T t = top();
		_size--;
		_elem.pop_back();
		min_elem.pop_back();
		return t;
	}
	const T& get_min() const {return min_elem[_size - 1];}
};