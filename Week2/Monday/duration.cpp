// Implementation file for the Duration class.
// Function body of toString shows some string concepts (to_string and +),
// implementations for overloaded operators and analogous functions are similar
// but member functions require scope resolution (like toString) and access 
// mins directly for the calling object (first operand) vs rhs.mins for 
// the parameter (second operand).
// Sara Krehbiel, 9/30/24-10/2/24

#include <string>
#include "duration.h" // include the interface file

// define all functions declared but not defined in duration.h

// returns a string expressing value as hrs,min, e.g., 150 -> "2 hours, 30 mins"
string Duration::toString() const {
	//mins+=60; // illegal if member function is declared const
	int numHours = mins/60;
	int numMins = mins%60;
	// note: string concatenation uses +, to_string converts ints to strings
	return to_string(numHours) + " hours, " + to_string(numMins) + " mins";
}

// OPTION 1: OVERLOAD OPERATORS AS MEMBER FUNCTIONS

// constructs and returns object corresponding to the sum of two operands
Duration Duration::operator +(const Duration& rhs) const { // scope resolution!
	//mins+=60; // illegal for const member functions
	//rhs.mins+=60; // illegal for const parameters
	Duration total(mins+rhs.mins); // mins corresponds to calling object (lhs)
	return total; 
}

// compare to syntax for regular member functions
Duration Duration::sumDuration(const Duration& rhs) const {
	Duration total(mins+rhs.mins); 
	return total;
}


/*
// OPTION 2: OVERLOAD OPERATORS AS NON-MEMBER FRIEND FUNCTIONS

// constructs and returns object corresponding to the sum of two operands
Duration operator +(const Duration& lhs, const Duration& rhs) { 
	Duration total(lhs.mins+rhs.mins);
	return total; 
}

// compare to syntax for regular non-member friend functions
Duration sumDuration(const Duration& lhs, const Duration& rhs) {
	Duration total(lhs.mins+rhs.mins);
	return total;
}


// OPTION 3: OVERLOAD OPERATORS AS NON-MEMBER NON-FRIEND FUNCTIONS

// constructs and returns object corresponding to the sum ot two operands
Duration operator +(const Duration& lhs, const Duration& rhs) {
	//Duration total(lhs.mins+rhs.mins); // illegal: mins is private
	Duration total(lhs.getMins()+rhs.getMins()); // use accessor instead
	return total; 
}

// compare to syntax for regular non-member non-friend functions
Duration sumDuration(const Duration& lhs, const Duration& rhs) {
	Duration total(lhs.getMins()+rhs.getMins()); 
	return total; 
}
*/