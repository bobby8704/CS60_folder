// Interface and implementation of templatized linked list bag
// Sara Krehbiel, 11/15/24

#ifndef BAG_H
#define BAG_H

#include "node.h"
#include <iostream>
using std::ostream;

template <typename T>
class Bag {
public:
  // 0-arg constructor 
  Bag() : head(nullptr), tail(nullptr) {}

  // TODO: copy constructor, destructor, overloaded assignment
  //Bag(const Bag<T>& other) : Bag() {list_copy(head, tail, other.head);}
  Bag(const Bag<T>& other) : Bag() {*this = other;}
  Bag<T>& operator =(const Bag<T>& rhs); 
  ~Bag() { list_clear(head, tail); }

  // accessors
  size_t size() const {return list_size(head, tail);} // return # elements in bag
  // TODO: accessor to count the # entries with a particular value
  size_t count(const T& val) const; 

  // mutators
  void insert(const T& val) {list_insert_head(head, tail, val);} // add to FRONT
  // TODO: mutators to erase_one or erase all copies of a particular value
  bool erase_one(const T& val) { return list_remove_one(head, tail, val); }
  size_t erase(const T& val);


private:
  node<T> * head;
  node<T> * tail;
  // invariants: head and tail point to the first and last nodes, respectively,
  //             in a dynamic linked list, or they are null if the list is empty
};

// TODO: implement <<, memory management and other accessor/mutator fns

template <typename T> 
Bag<T>& Bag<T>::operator=(const Bag<T>& rhs)
{
  // clear my own data
  list_clear(head, tail);
  // copy data from rhs
  list_copy(head, tail, rhs.head);
  // return ref to modified object (the calling object)
  return *this;
}


#endif
