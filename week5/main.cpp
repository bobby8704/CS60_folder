// Test file illustrating memory management for classes, specifically GArray.
// We'll implement insert to handle dynamic memory for a single object, and 
// by the end of the week, we'll have understood the need for and implemented
// an overloaded assignment operator, a copy constructor, and a destructor.
//
// Monday: 
//   Finish learning about heap memory in Lesson 4 of pointers.cpp
//   Overview insertTests and the skeletal interface in garray.h
//   Plan how to implement insert using dynamic memory
// Wednesday: 
//   Implement insert and understand corresponding memory diagrams
//   Overload ASSIGNMENT operator (as void function) to deep copy rhs
//   Implement a COPY CONSTRUCTOR to deep copy existing object into new one
// Friday:
//   Modify assignment operator for chained assignment
//   Implement DESTRUCTOR
//   Add cout statements for assignment, copy constructor, and destructor
//    and run passByValueAndReturnObject to see when they are called
//   
// Sara Krehbiel, 10/21/24-10/25/24

#include <iostream>
#include "garray.h"

using namespace std;

void insertTests();
void memoryTests();
GArray passByValueAndReturnObject(GArray arr);

int main() {
  cout << "main is beginning\n";
  //insertTests();
	memoryTests();
  cout << "main is returning\n";
	return 0;
}

void insertTests() {
  cout << "insertTests is beginning\n\n";

  GArray arr;
  cout << "arr after 0-arg construction: " << arr << endl;

  arr.insert(2);
  arr.insert(4);
  arr.insert(6);
  arr.insert(8);
  cout << "arr after four inserts: " << arr << endl;

  cout << "\ninsertTests is returning\n";
}

void memoryTests() {
  cout << "memoryTests is beginning\n";
  // set up two GArray objects and cout their contents
  GArray first;
  first.insert(1);
  first.insert(2);
  GArray second;
  second.insert(3);
  second.insert(4);
  second.insert(5);
  cout << "\nFirst: " << first << endl;
  cout << "Second: " << second << endl;

  // assignment: enforces correct memory (non-)sharing for identical objects
  cout << "\nsecond = first;\n";
  second = first; // without overloading =, this makes a shallow copy
  cout << "\nFirst: " << first << endl;
  cout << "Second: " << second << endl;


  // copy-constructor: makes a new object by deep copying an existing one 
  cout << "\nGArray third(first);\n";
  GArray third(first); 
  cout << "\nFirst: " << first << endl;
  cout << "Second: " << second << endl;
  cout << "Third: " << third << endl;

  // modifying one object shouldn't affect others if dynamic memory isn't shared
  cout << "\nfirst.insert(6);\n";
  first.insert(6); 
  cout << "\nFirst: " << first << endl;
  cout << "Second: " << second << endl;
  cout << "Third: " << third << endl;

  // uncommon, but can call destructor explicitly
  //cout << "\nfirst.~GArray();\n";
  //first.~GArray(); uncomment to check this doesn't mess up subsequent code!

  // chained assignment requires GArray& as return type for = overload
  cout << "\nthird = second = first; // COMPILE ERROR until we modify = \n";
  third = second = first; // chained assignment
  
  cout << "\nfirst = first;\n"; // modify = to ensure this works!
  first = first;
  
  cout << "\nFirst: " << first << endl;
  cout << "Second: " << second << endl;
  cout << "Third: " << third << endl;


  // note other places that copy-constructor is called automatically
  cout << "\nfirst = passByValueAndReturnObject(second);\n";
  first = passByValueAndReturnObject(second);

  cout << "\nmemoryTests is returning\n"; 
  // locally declared objects call their destructors when the function returns;
  // define it to avoid orphaning memory when local vars pop off the stack
}

// note: the copy-constructor gets called when parameters are passed by val
// and when objects are returned by value; note destructor calls, too!
GArray passByValueAndReturnObject(GArray arr) { 
  cout << "pBVARO is running\n"; 
  return arr; 
}

