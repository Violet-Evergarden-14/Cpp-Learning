#include "..\chapter03\List.h"

template <typename T> class Queue: public List<T> {
public:
	void enqueue(const T& e) {insert_as_last(e);}  // push back
	T dequeue() {return remove(first());}          // delete front
	T& front() {return first()->data;}             // get front
};