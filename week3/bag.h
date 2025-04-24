// Complete interface for static array implementation of a container called Bag,
// which should holds up to CAPACITY ints, possibly with repetition. 
//
// Sara Krehbiel, via Natalie Linnell and Nicholas Tran, 10/7/24-10/11/24

#ifndef BAG_H
#define BAG_H

#include <cstdlib>
using std::size_t; 

#include <iostream>
using std::ostream; // allows you to use ostream instead of std::ostream
// Note: using namespace std in class defns results in namespace pollution

class Bag {
public:
  static const size_t CAPACITY = 1000; // static = NOT a member variable

  // constructors (post-conditions guarantee well-structured bags)
  Bag() : size_(0) { }
  Bag(int a[], size_t n);

  // accessors (pre- and post-conditions are the same well-structured bags)
  size_t size() const { return size_; }
  int operator [](size_t index) const { return data_[index]; }
  size_t count(int val) const; // returns #times target appears in data_

  // mutators (pre-conditions are well-structured bags, post-conditions differ)

  // Post: size_ is incremented, data_[size_-1]=val, data_[0..size_-1] as before
  void insert(int val) { if (size_<CAPACITY) data_[size_++] = val; }

  // Post: if data_ initially contained val, first copy is removed (overwritten)
  //       with size_ decremented and true returned; otherwise false is returned
  bool erase_one(int val);

  // Post: all copies of val are removed with # removed returned
  size_t erase(int val);

  // Post: rhs contents are inserted in order to calling object, rhs unchanged
  void operator +=(const Bag& rhs); 
 
private:
	int data_[CAPACITY];
	size_t size_;
  // INVARIANT: data_[0],...,data_[size_-1] contain previously-inserted ints,
  //            and size_<=CAPACITY
};

// Post: rhs contents are inserted in order to lhs, rhs unchanged
//void operator +=(Bag& lhs, const Bag& rhs); // if we implemented as non-member

// Post: bag with lhs and rhs contents in order returned, lhs and rhs unchanged
Bag operator +(const Bag& lhs, const Bag& rhs);

// Post: in-order true contents of b.data_ are inserted into ostream o
ostream& operator <<(ostream& o, const Bag& b);


#endif
