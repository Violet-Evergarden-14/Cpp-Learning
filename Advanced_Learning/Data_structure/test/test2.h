#include <stack>
using namespace std;

template <typename T>
class Queue {
private:
	stack<T> s1;
	stack<T> s2;
	int _size;
public:
	Queue() {_size = 0;}
	int size() const {return _size;}
	bool is_empty() const {return s1.empty() && s2.empty();}
	void enqueue(const T& e) {s2.push(e); _size++;}
	T dequeue() {
		if (s1.empty()) {
			while (!s2.empty()) {
				T cur = s2.top();
				s1.push(cur);
				s2.pop();
			}
		}
		T r = s1.top(); s1.pop();
		_size--;
		return r;
	}
};