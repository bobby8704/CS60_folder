// Small program to learn how to declare and define a template function
// Sara Krehbiel, 10/28/24

#include <iostream>
using namespace std;

/* Fraction class definition and overloaded << */

// a class that stores a fraction as an integer numerator and denominator
class Fraction {
public:
	// two constructors
	Fraction(int num, int denom) : n(num), d(denom) {}
	Fraction() : Fraction(0,1) {}

	// comparators
	double getVal() const { return 1.0*n/d; }
	bool operator <(const Fraction& rhs) const { return (getVal()<rhs.getVal()); } // note: returning (rhs > *this) initiates infinite recursion
	bool operator >(const Fraction& rhs) const { return (rhs < *this); }

	// friend declaration for <<
	friend ostream& operator <<(ostream&, const Fraction&);

private:
	// NOTE: const member variables can't be changed once intialized
	const int n;
	const int d;

};

// << is a friend so can access private member vars of its Fraction param
ostream& operator <<(ostream& o, const Fraction& f) { return o<<f.n<<"/"<<f.d; }


/* declarations of helper (incl template) functions for driver program below */

void compareInts(); 
void compareFractions();
void searchForLargeElement();

const int& biggerInt(const int& a, const int& b);
const Fraction& biggerFraction(const Fraction& a, const Fraction& b);

template <typename T> // need template prefix for declaration AND definition
const T& biggerQuantity(const T& a, const T& b);

template <typename T> 
bool hasLargeValue(T* arr, size_t size, T threshold) { return false; }


/* driver program */

int main() {
	compareInts();
	compareFractions();
	searchForLargeElement();
	return 0;
}


/* helper function definitions */

void compareInts() {
	int n = 3, m = 4;
	cout << "My ints are n=" << n << " and m= " << m << endl;
	cout << biggerQuantity(n,m) << " is bigger.\n";
}

void compareFractions() {
	Fraction r(1,3), s(1,4);
	cout << "Burger options: a " << r << "-pounder vs a " << s << "-pounder.\n";
	cout << biggerQuantity(r,s) << " is more meat.\n";
}

template <typename T> // declares T as type placeholder, eg T=int or Fraction
const T& biggerQuantity(const T& a, const T& b) {
 	if (a<b) return b;
	return a;
}

/*
// returns first int unless second is strictly larger
const int& biggerInt(const int& a, const int& b) {
 	if (a<b) return b;
	return a;
}

const Fraction& biggerFraction(const Fraction& a, const Fraction& b) {
	if (a<b) return b;
	return a;
}
*/

void searchForLargeElement() {
	// set up an array of ints 
	int a[] = {-1,3,6,2};
	int t = 5;
	// check whether a contains anything of size >= thresh
	if (hasLargeValue(a,4,t)) cout << "a has a value larger than " << t << endl;
	else cout << "a has no value larger than " << t << endl;

	// WEDNESDAY TODO: implement template fn and test with an array of Fractions
	
}
