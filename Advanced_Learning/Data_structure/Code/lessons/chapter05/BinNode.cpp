#include "BinNode.h"

// we may assume that *this does not have a left child
template <typename T>
BinNodePos(T) BinNode<T>::insert_as_lc(const T& e) {return lc = new BinNode(e, this);}

template <typename T>
BinNodePos(T) BinNode<T>::insert_as_rc(const T& e) {return rc = new BinNode(e, this);}

template <typename T> template <typename VST>
void BinNode<T>::trav_in(VST& visit) {
	switch (rand() % 5) {
		case 1: travIn_I1 ( this, visit ); break;
        case 2: travIn_I2 ( this, visit ); break;
        case 3: travIn_I3 ( this, visit ); break;
        case 4: travIn_I4 ( this, visit ); break;
        default: travIn_R ( this, visit ); break;
	}
}