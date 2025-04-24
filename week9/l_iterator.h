// Interface and implementation of iterator for templatized linked list
// Sara Krehbiel, 11/20/24

#ifndef L_ITERATOR_H
#define L_ITERATOR_H

#include "node.h"

template <typename T>
class L_iterator {
public:
	//L_iterator() : curr(nullptr) {} // not necessary with default vals below!
	L_iterator(node<T>* head = nullptr) : curr(head) {}
	bool operator !=(const L_iterator<T>& rhs) const { return curr!=rhs.curr; }
	T operator *() const { return curr->data(); } 
	L_iterator<T>& operator ++(); // prefix incrementation
	L_iterator<T> operator ++(int); // postfix incrementation
	bool operator ==(const L_iterator<T>& rhs) const { return curr==rhs.curr; }
	bool operator <(const L_iterator<T>& rhs) const;
private:
	node<T>* curr; // address of node whose data is the current element in a bag
};

// implementations for iterator functions not defined inline:
// note that these will go in the cpp file for untemplatized iterators

// postfix: move to the next element and return reference to calling iterator
template <typename T>
L_iterator<T>& L_iterator<T>::operator ++() {
	curr = curr->link(); 
	return *this;
}

// prefix: snapshot current, move to next, return new iterator for old address
template <typename T>
L_iterator<T> L_iterator<T>::operator ++(int) {
	node<T>* temp = curr;
	curr = curr->link(); 
	return L_iterator<T>(temp);
}


#endif
