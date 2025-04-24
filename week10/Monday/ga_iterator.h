// Interface for GA_Iterator, an iterator for the GArray class
// Sara Krehbiel, 11/24/24 for 12/2/24 asynchronous lecture

#ifndef GA_ITERATOR_H
#define GA_ITERATOR_H

class GA_Iterator {
public:
  // constructor and overloaded !=, ++, and * operators
  GA_Iterator(int *start = nullptr) : curr(start) {}
  bool operator !=(const GA_Iterator& rhs) const { return curr!=rhs.curr; }
  GA_Iterator& operator ++();
  int operator *() const { return *curr; } 

private:
  int *curr; // address of current element in GArray object
};

#endif