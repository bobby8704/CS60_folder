// Function definitions for static array implementation of Bag data structure
// Sara Krehbiel, 10/7/24-10/11/24

#include "bag.h"


Bag::Bag(int a[], size_t n) : Bag() { // constructor delegation for empty start
  	for (size_t i=0; i<n; i++) {
  		insert(a[i]); // note that insert increments size
  	}
}

size_t Bag::count(int val) const {
	size_t c = 0; // keeps track of how many instances of val seen so far
	for (size_t i=0; i<size_; i++) {
		if (data_[i]==val) c++;
	}
	return c;
}

bool Bag::erase_one(int val) {
	bool found = false;
	for (size_t i=0; i<size_; i++) {
		// when val is FIRST found, flip found bool and decrement size
		if (!found && data_[i]==val) {
			found = true;
			size_--;
		}
		// if val has already been found, overwrite current entry with next
		if (found) data_[i] = data_[i+1];
	}
	return found;
}

size_t Bag::erase(int val) {
	size_t c = 0;
	// erase_one until it finds no more copies of val, keeping track of # erased
	while (erase_one(val)) {
		c++;
	} 
	return c;
}


// TODO: implement += and +
void Bag::operator+=(const Bag& rhs)
{
	size_t new_size = size_ + rhs.size();
	size_t j = 0;
	for (size_t i = size_; i < new_size; i++)
	{
		data_[i] = rhs[j];
		j++;
	}

	size_ = new_size;
}

Bag operator + (const Bag& lhs, const Bag& rhs)
{
	Bag new_bag;
	for (size_t i = 0; i < lhs.size(); i++)
	{
		new_bag.insert(lhs[i]);
	}

	for (size_t i = 0; i < rhs.size(); i++)
	{
		new_bag.insert(rhs[i]);
	}

	return new_bag;
}


ostream& operator <<(ostream& o, const Bag& b) {
	for (size_t i=0; i<b.size(); i++) {
		o << b[i] << " "; // b.data_ is private but [] is public
	}
	return o;
}