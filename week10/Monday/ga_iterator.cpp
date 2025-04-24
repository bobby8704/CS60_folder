// Implementation of GA_Iterator, an iterator for the GArray class
// Sara Krehbiel, 11/24/24 for 12/2/24 asynchronous lecture

#include "ga_iterator.h"

// prefix increment moves curr to next int and returns modified calling object
GA_Iterator& GA_Iterator::operator ++() { 
  curr++;
  return *this; 
}
