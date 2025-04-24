// Driver program to test a templatized Bag class that uses dynamic arrays.
// Also includes a little bit of code using vectors from the STL.
//
// Sara Krehbiel, 11/4/24-11/6/24

#include <iostream>
#include <vector>
#include "bag.h"
using namespace std;

void vectorTests();
void bagTests();

template <typename T, typename U>
void minAmaxB(vector<T> , vector<U> );

int main() {
  //vectorTests();
  bagTests();
  return 0;
}

void vectorTests() {
  // declare a vector of ints and insert the values 0-9
  vector<int> intV;
  for (int i=0; i<10; i++) {
    intV.push_back(2*i); 
    cout << i << endl;
    cout << "Size: " << intV.size() << "\nCap: " << intV.capacity() << endl;   
  }
  //intV.shrink_to_fit(); // a function for controlling capacity
  //cout << "Size: " << intV.size() << "\nCap: " << intV.capacity() << endl;   
  //cout << "intV: " << intV << endl; // COMPILE ERROR: not overloaded
  
  for (int i=0; i<intV.size(); i++) {
    cout << intV[i] << " ";
  }
  cout << endl;
  //cout << intV[100] << endl; // subscript operator does not do bounds checking
  //cout << intV.at(100) << endl; // RUNTIME ERROR: at does bounds checking
  //cout << intV << endl; 

  // declare a vector of strings and insert some words
  vector<string> strV;
  strV.push_back("Hello");
  strV.push_back("armadillo");
  for (int i=0; i<2; i++) {
    cout << strV[i] << " ";
  }
  cout << endl;

  // using a doubly templatized function
  minAmaxB(intV, strV); // should print min int in intV and max string in strV
  minAmaxB(strV, intV); // should print min string in strV and max int in intV
  minAmaxB(intV, intV); // should print min int and max int in intV

}

// reports smallest val in a and largest in b
// requirement: < must be overloaded for a, > must be overloaded for b
template <typename T1, typename T2>
void minAmaxB(vector<T1> a, vector<T2> b) {
  
  if (a.size()==0) cout << "a is empty\n";
  else { // iterate through contents of a, keeping track of the smallest one
    T1 minSoFar = a[0];
    for (int i=1; i<a.size(); i++) {
      if (a[i]<minSoFar) minSoFar = a[i];
    }
    cout << "smallest element in a is " << minSoFar << endl;
  }
  if (b.size()==0) cout << "b is empty\n";
  else {
    T2 maxSoFar = b[0];
    for (int i=1; i<b.size(); i++) {
      if (b[i]>maxSoFar) maxSoFar = b[i];
    }
    cout << "largest element in b is " << maxSoFar << endl;
  }
}


void bagTests() {
  Bag<int> b1;
  cout << "Initial bag size: " << b1.size() << endl;
  size_t n = 5;
  cout << "Adding " << n << " 1s to a capacity " << b1.cap() << " bag\n";
  for (int i=0; i<n; i++) {
    b1.insert(1); // note: insert for bag plays the role of push_back for vector
    cout << "Capacity " << b1.cap() << " after insertion " << (i+1) << endl;
  }

  cout << "b1 contents: " << b1 << endl;

  
  // dynamic memory management tests
  Bag<int> b2(b1); // makes bag with same contents, separate memory
  b2.insert(2);
  cout << "b1: " << b1 << "\nb2: " << b2 << endl; // overload << for Bag
  b1 = b2; // deep-copies b2's contents into separate memory for b
  cout << "b1: " << b1 << "\nb2: " << b2 << endl; 
  b2 = b2; // note the change we made to make sure it works in this case!
  cout << "b1: " << b1 << "\nb2: " << b2 << endl; 
  
  // erase_one tests
  cout << "Erasing one 2\n";
  b1.erase_one(2); 
  cout << b1 << endl;
  
  cout << "Erasing 1s, one-by-one\n";
  for (int i=0; i<n+2; i++) {
    b1.erase_one(1); 
    cout << b1 << endl;
    cout << "Size " << b1.size() << " and capacity " << b1.cap() << endl;
  }


  Bag<string> sb;
  sb.insert("hello");
  sb.insert("world");
  cout << "sb: " << sb << endl;
}