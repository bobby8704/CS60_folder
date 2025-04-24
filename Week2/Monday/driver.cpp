// Source code for driver program that uses the Duration class.
// The program illustrates how to call all the functions in the Duration class,
// including 0-, 1-, and 2-argument constructors, a toString member function, 
// and the overloaded operator. Commented out code shows how the way 
// sumDuration is declared and defined (as a member vs non-member function)
// influences how it is called, whereas + is called the same way regardless of
// how it is overloaded.
// Note: You must compile the implementation file to run this, e.g.,
//   $ g++ driver.cpp duration.cpp -std=c++11
// Sara Krehbiel, 9/30/24-10/2/24

#include <iostream>
#include "duration.h" // include the interface file
using namespace std;

int main() {
  Duration d0; // calls a 0-arg constructor 
  // NOTE: compiler writes/uses default iff no constructors are defined
  cout << "D0: " << d0.toString() << endl; // calls a toString member function

  // declare more Duration objects using other constructors
  Duration d1(1,55);
  Duration d2(100);
  cout << "D1: " << d1.toString() << endl; 
  cout << "D2: " << d2.toString() << endl;

  // WEDNESDAY: member vs non-member functions and operator overloading 

  // + is called the same way no matter how it is overloaded
  Duration total = d1+d2; 
  // use the dot operator to call regular member functions
  //Duration total = d1.sumDuration(d2);
  // non-member functions are called the same way whether they're friensd or not
  //Duration total = sumDuration(d1,d2); 
  cout << "Total: " << total.toString() << endl;

  return 0;
}

