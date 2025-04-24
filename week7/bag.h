// Interface for templatized dynamic array implementation of Bag.
// Also includes all the implementation normally in the cpp file
// to avoid platform-specific linking problems.
//
// Sara Krehbiel, modified code from Natalie Linnell and Nicholas Tran
// 11/4/24-11/6/24

#ifndef BAG_H
#define BAG_H

#include <iostream> 
using std::size_t;
using std::ostream;
using std::cout; // note: useful for cout debugging

// INTERFACE

template <typename T>
class Bag {
public:
  // CONSTRUCTORS AND DYNAMIC MEMORY MANAGEMENT
  // NOTE: DON'T templatize constructor/destructor names when declaring/defining
  Bag() : data_(nullptr), size_(0), cap_(0) {} 
  Bag(const Bag<T>& other); // NOTE: DO templatize any Bag object, incl params
  ~Bag(); // COMPILE ERROR: can't use Bag with ~ declared but not implemented
  Bag<T>& operator =(const Bag<T>& rhs); // NOTE: also templatize return types

  // CONSTANT ACCESSOR MEMBER FUNCTIONS
  size_t size() const { return size_; }
  size_t cap() const { return cap_; }
  T operator [](size_t i) const { return data_[i]; }
  size_t count(T val) const; 
  
  // MUTATOR MEMBER FUNCTIONS
  void insert(T val); 
  bool erase_one(T val);
  size_t erase(T val); 
  size_t erase_fast(T val); // (smarter implementation of erase)
  void operator +=(const Bag<T>& rhs); 

private:
  T *data_; // the address associated with a dynamic array
  size_t size_; // how much memory is currently used (#elements in bag)
  size_t cap_; // how much memory is currently allocated (#entries in array)
  // INVARIANTS: data_[0],...,data_[size_-1] always contain the elements,
  //             cap_*.25 < size_ <= cap_, or size_=cap_=0
};

// IMPLEMENTATION (note that this has to go in bag.h)

// pre: a well-formed bag
// post: a well-formed bag with one extra T val in the last spot 
template <typename T>
void Bag<T>::insert(T val) {
  if (size_ == cap_) {
    // create a new space for a new double-capacity array
    if (cap_==0) cap_ = 1;
    else cap_ *= 2;
    T *temp = new T[cap_];
    // deep copy contents from the old array into the new one
    for (size_t i=0; i<size_; i++) {
      temp[i] = data_[i]; // requires meaningful assignment overload for type T
    }
    // delete [] data_ to avoid orphaning, reassign data_ to point to new array
    delete [] data_;
    data_ = temp;
  }
  // insert val into the next available spot in data_ and increment size_
  data_[size_++] = val;
}

// pre: out is an ostream, b is a well-formed bag
// post: out has the contents of b inserted, b is unchanged
template <typename T>
ostream& operator <<(ostream& out, const Bag<T>& b) {
  size_t n = b.size();
  for (size_t i=0; i<n; i++) {
    out << b[i] << " ";
  }
  return out;
}

// pre: other is a well-formed bag
// post: *this is a well-formed deep copy of other, which is unchanged
template <typename T>
Bag<T>::Bag(const Bag<T>& other) : size_(other.size_), cap_(other.cap_), data_(nullptr) {
  if (size_ == 0) return; // the edge case that the other bag is empty
  data_ = new T[cap_]; 
  for (size_t i=0; i<size_; i++) { 
    data_[i] = other.data_[i];
  }
}

// pre: *this and rhs are well-formed bags
// post: *this is a deep-copy of other (unchanged), and old memory is released
template <typename T>
Bag<T>& Bag<T>::operator =(const Bag<T>& rhs) {
  if (&rhs == this) return *this;
  if (cap_ != rhs.cap_) { // only need new space if my cap is changing
    cap_ = rhs.cap_; 
    delete [] data_;
    if (rhs.size_ == 0) data_ = nullptr;
    else data_ = new T[cap_];
  }
  size_ = rhs.size_;
  for (size_t i=0; i<size_; i++) { // whether i've allocated new space or not
    data_[i] = rhs.data_[i]; // deep copy rhs contents
  }
  return *this;
}

// pre: *this is a well-formed bag
// post: old memory is released and *this is a well-formed empty bag
template <typename T>
Bag<T>::~Bag() {
  delete [] data_; 
  data_ = nullptr;
  size_ = cap_ = 0;
}

// pre: *this is a well-formed bag
// post: if val is in *this, its first occurrence is removed with true returned; 
//       otherwise false is returned with *this unchanged
template <typename T>
bool Bag<T>::erase_one(T val) {
  bool found = false;
  for (size_t i=0; i<size_; i++) {
    if (!found && data_[i]==val) {
      found = true;
      size_--;
      // HW7 TODO: check whether size_==.25cap_ and downsize the array if so
    }
    if (found) data_[i] = data_[i+1];
  }
  return found;
}


#endif
