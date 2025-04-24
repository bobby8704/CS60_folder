// Test code for templatized linked list implementation of bag
// To compile: g++ main.cpp bag.cpp node.cpp -std=c++11
// Sara Krehbiel, 11/15/24

#include <iostream>
#include "bag.h" 

using namespace std;


int main() {
  // construct empty bag and insert 3 elements
  Bag<int> b;
  b.insert(1);
  b.insert(2);
  b.insert(3);

  // ouput bag size and contents
  cout << "size: " << b.size() << endl;
  //cout << "b: " << b << endl;
  return 0;
}
