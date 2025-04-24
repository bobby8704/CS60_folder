// Test code for templatized linked list implementation of bag
// To compile: g++ main.cpp bag.cpp node.cpp -std=c++11
// Sara Krehbiel, 11/18/24-11/22/24

#include <iostream>
#include "bag.h" 
#include <vector>

using namespace std;


void monday();
void wednesday();
void friday();

int main() {
  //monday();
  //wednesday();
  friday();
  return 0;
}

void monday() {
  // construct bags with contents 1->4->12 and 8->6, resp
  Bag<int> b;
  b.insert(12);
  b.insert(4);
  b.insert(1);

  Bag<int> other;
  other.insert(6);
  other.insert(8);

  cout << "b: " << b << "\nother: " << other << endl;

  // test assignment operator
  b = other;
  cout << "b = other;\nb: " << b << "\nother: " << other << endl;
  other.insert(7); // test that modifying other does not modify b
  cout << "other.insert(7);\nb: " << b << "\nother: " << other << endl;

  // test copy-constructor
  Bag<int> b2(other);
  cout << "Bag<int> b2(other);\nother: " << other << "\nb2: " << b2 << endl;

  // test erase_one: erase_one(-1) should output 0, erase_one(8) should output 1
  cout << "b2.erase_one(-1) = " << b2.erase_one(-1) << "\nb2: " << b2 << endl;
  cout << "b2.erase_one(8) = " << b2.erase_one(8) << "\nb2: " << b2 << endl;
  
  // try erasing from tail
  cout << "TODO: Check memory diagrams for edge cases and debug segfault\n";
  cout << "b1.insert(1) x2\n";
  b2.insert(1);
  b2.insert(1);
  cout << "b2.erase_one(6);\n";
  b2.erase_one(6);
  cout << "b2: " << b2 << endl; 
  // erasing from tail seems to work, but check!
  cout << "About to run b2.erase_one(1)...\n";
  b2.erase_one(1); // TODO: fix edge case causing segfault
  cout << "b2: " << b2 << endl; 
  cout << "b2.erase_one(7);\n";
  b2.erase_one(7);
  cout << "b2: " << b2 << endl; 
  cout << "b2.erase_one(1);\n";
  b2.erase_one(1);
  cout << "b2: " << b2 << endl; 
  
  // test erase (EXERCISE!)
  cout << "other.insert(6) x2\nother: ";
  other.insert(6);
  other.insert(6); 
  cout << other << "\nother.erase(6) = ";
  cout << other.erase(6) << "\nother: " << other << endl;
}

void wednesday() {
  // range-based for loops for static arrays and vectors
  double arr[5] = {1.1,1.2,1.3,1.4,1.5};
  for (double d : arr) {
    cout << d << " ";
  }
  cout << endl;

  int a = 4;
  cout << "a=" << a++ << endl;
  cout << "a=" << a << endl;

  vector<string> vec;
  vec.push_back("winter");
  vec.push_back("is");
  vec.push_back("coming");
  for (auto word : vec) {
    cout << word << " ";
  }
  cout << endl;

  for (vector<string>::iterator it=vec.begin(); it!=vec.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;

  size_t numChars = 0;
  for (vector<string>::iterator it=vec.begin(); it!=vec.end(); ++it) {
    numChars += (*it).length();
  }
  cout << numChars << " characters\n";
}

void friday() {
  // GOAL: implement an iterator for our linked list bag
  Bag<double> b;
  for (int i=0; i<5; i++) {
    b.insert(i/2.0);
  }
  cout << b << endl;

  // testing while developing iterator functionality
  auto it=b.begin();
  cout << "*it = " << *it << endl;
  cout << "*(it++) = " << *(it++) << endl;
  cout << "*it = " << *it << endl;
  cout << "*(++it) = " << *(++it) << endl;
  cout << "*it = " << *it << endl;

  ++it;
  cout << "*it (after incrementation ++it) = " << *it << endl;
  auto end_it=b.end();
  cout << "is it!=end_it? " << (it!=end_it) << endl;

  for (auto e : b) {
    cout << e << " ";
  }
  cout << endl;

  for (Bag<double>::iterator it=b.begin(); it!=b.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  
  double total=0;
  for (Bag<double>::iterator it=b.begin(); it!=b.end(); ++it) {
    total += *it;
  }
  cout << total << endl;
}
