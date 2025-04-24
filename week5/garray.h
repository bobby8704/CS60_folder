// Interface for GArray, a class for (inefficient) growable dynamic arrays 
// Sara Krehbiel, 10/21/24-10/25/24

#ifndef GARRAY_H
#define GARRAY_H

#include <iostream>

//using namespace std;
using std::ostream;
using std::cout;

class GArray {
public:
  // constructor and dynamic memory management functions
  GArray() : size_(0), data_(nullptr) {} // a basic 0-arg constructor
  GArray(const GArray& other);
  ~GArray();
  //GArray& operator = (const GArray& rhs);

  GArray& operator =(const GArray& rhs);

  // mutator
  void insert(int val); // insert in new, slightly larger array

  // accessors to help implement overloaded <<
  size_t length() const { return size_; }
  int operator [](size_t i) const { return data_[i]; }
  int* dataAddress() const { return data_; }

private:
  size_t size_;
  int *data_;
};

ostream& operator <<(ostream& out, const GArray& a);

#endif