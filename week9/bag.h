// Interface and implementation of templatized linked list bag
// Sara Krehbiel, 11/18/24-11/22/24

#ifndef BAG_H
#define BAG_H

#include "node.h"
#include "l_iterator.h"
#include <iostream>
using std::ostream;

template <typename T>
class Bag {
public:
  // 0-arg constructor 
  Bag() : head(nullptr), tail(nullptr) {}

  //Bag(const Bag<T>& other) : Bag() { list_copy(head,tail,other.head); }  
  Bag(const Bag<T>& other) : Bag() { *this = other; }  // shortcut by calling =
  Bag<T>& operator =(const Bag<T>& rhs); 
  ~Bag() { list_clear(head,tail); }

  // accessors
  size_t size() const { return list_size(head,tail); } // # contents in bag
  // EXERCISE: accessor to count the # entries with a particular value
  size_t dup(const T& val);

  // mutators
  void insert(const T& val) { list_insert_head(head,tail,val); } // add to FRONT
  bool erase_one(const T& val) { return list_remove_one(head,tail,val); } 
  size_t erase(const T& val); // EXERCISE

  // declare << as a friend because can't be member but needs access to head
  friend ostream& operator <<(ostream& o, const Bag<T>& b) {return o << b.head;}

  // iterator content: specify iterator class, give begin and end functions
  typedef L_iterator<T> iterator;
  iterator begin() const { return iterator(head); }
  iterator end() const { return iterator(); }

private:
  node<T> * head;
  node<T> * tail;
  // invariants: head and tail point to the first and last nodes, respectively,
  //             in a dynamic linked list, or they are null if the list is empty
};


// implementations of bag member functions node defined inline

template <typename T>
Bag<T>& Bag<T>::operator =(const Bag<T>& rhs) {
  list_clear(head,tail); // clear calling object's data
  list_copy(head,tail,rhs.head); // deep copy other's data into calling object
  return *this; // return ref to modified calling object
}

template <typename T>
size_t Bag<T>::dup(const T& val)
{
  size_t count = 0;
  for (node<T>* curr = head; curr!=nullptr; curr = curr->link())
  {
    if (curr->data() == val) count++;
  }
  return count;
}

template <typename T>
size_t Bag<T>::erase(const T& val)
{
  return list_remove_all(head, tail, val);
}





#endif
