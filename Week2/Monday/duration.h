// Header file containing the interface for the Duration class. 
// Declares and defines constructors inline, declares toString accessor without
// defining (using const to modify the function and ensure the calling object's
// member variables aren't changed by the function body), provides three options
// for overloading + with analogous code for a non-operator function declared in
// each of these ways. The latter functions pass parameters by const reference
// for efficiency and a guarantee that the objects passed in won't be changed.
// The non-member non-friend option requires an additional getMins accessor to
// be implemented as it can't access private member variables directly.
// Sara Krehbiel, 9/30/24-10/2/24

#ifndef DURATION_H // boilerplate for header files (no need to memorize)
#define DURATION_H

#include <iostream>
#include <string>
using namespace std;

// class definition: declares all member fields, may have inline functions defs
class Duration {
public:
	// three constructors with inline definitions using initialization section
	Duration() : mins(0) { }
	Duration(int hrs, int mins) : mins(60*hrs+mins) { }
	Duration(int mins) : mins(mins) { }

	// a member function (can be seen as an accessor)
	string toString() const; // const says the calling object can't be changed

	// OPTION 1: OVERLOAD OPERATORS AS MEMBER FUNCTIONS

	// Member functions have a calling object, the lhs for binary operators.
	// The const in the parameter list says rhs can't change.
	// The const at the end says the calling object can't change.
	Duration operator +(const Duration& rhs) const;

	// compare to syntax for regular member functions
	Duration sumDuration(const Duration& rhs) const;

/*
	// OPTION 2: OVERLOAD OPERATORS AS NON-MEMBER FRIEND FUNCTIONS

	// Non-member functions must declare both operands.
	// Declare inside the class with the keyword friend to access member vars
	friend Duration operator +(const Duration& lhs, const Duration& rhs);

	// compare to syntax for regular non-member friend functions
	friend Duration sumDuration(const Duration& lhs, const Duration& rhs);

	// OPTION 3: OVERLOAD OPERATORS AS NON-MEMBER NON-FRIEND FUNCTIONS

	// Non-member non-friends aren't declared in the class.
	// They can't access member vars directly so might need extra accessors.
	int getMins() const { return mins; } // accessors are typically const
*/
private:
	int mins;
};
/*
// OPTION 3: Non-member non-friends are declared outside the class.

Duration operator +(const Duration& lhs, const Duration& rhs);

// compare to syntax for regular non-member non-friend functions
Duration sumDuration(const Duration& lhs, const Duration& rhs);
*/
#endif
