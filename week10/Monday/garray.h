// Interface for GArray, a growable dynamic arrays, now enhanced with an iterator
// Sara Krehbiel, 10/25/24, modified 11/24/24 for 12/2/24 asynchronous lecture

#ifndef GARRAY_H
#define GARRAY_H

#include <iostream>
#include "ga_iterator.h"

using std::ostream;
using std::cout;

class GArray {
public:
  // constructor and dynamic memory management functions
  GArray() : size_(0), data_(nullptr) {} // a basic 0-arg constructor
  GArray(const GArray& other);
  ~GArray();
  GArray& operator =(const GArray& rhs);

  // mutator
  void insert(int val); // insert in new, slightly larger array

  // accessors 
  size_t length() const { return size_; }
  int operator [](size_t i) const { return data_[i]; }

  // iterator
  typedef GA_Iterator iterator;
  iterator begin() const { return iterator(data_); }
  iterator end() const { return iterator(data_+size_); }

private:
  size_t size_;
  int *data_;
};

ostream& operator <<(ostream& out, const GArray& a);

#endif