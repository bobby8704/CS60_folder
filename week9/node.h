// Interface and implementation of templatized node class
// Sara Krehbiel, 11/18/24-11/22/24

#ifndef NODE_H
#define NODE_H

#include <iostream>
using std::ostream;

template <typename T>
class node {
public:
	// constructors
	node(): data_(T()), link_(nullptr){}
    node(const T& d, node<T> *l) : data_(d), link_(l) {}

    // accessors
    T data() const { return data_; }
    node<T>* link() const { return link_; }

    // mutators
    void set_data(const T& val) { data_ = val; }
    void set_link(node<T>* l) { link_ = l; }

private:
	T data_;
    node<T> *link_; // link is the ADDRESS of the next node
};

// implementation of non-member linked list functions

// old implementation of inserting a val into the head of a list, with templates
template <typename T>
void list_insert_head(node<T> *& h, node<T> *& t, const T& val) {
	h = new node<T>(val,h);
	if (t == nullptr) t = h; // handles edge case that the list started empty
}

// old implementation of inserting a val into the tail of a list, with templates
template <typename T>
void list_insert_tail(node<T> *& h, node<T> *& t, const T& val) {
	node<T> *new_node = new node<T>(val,nullptr);
	if (t==nullptr) h = new_node;
	else t->set_link(new_node);
	t = new_node;
}

// recursive implementation of list_size
template <typename T>
size_t list_size(const node<T>* h, const node<T>* t) {
	if (h==nullptr) return 0;
	return 1+list_size(h->link(),t);
}

// << overloaded (recursively) for node<T>* to print list contents
template <typename T>
ostream& operator <<(ostream& o, const node<T> * curr) {
	if (curr==nullptr) return o;
	return o << curr->data() << " " << curr->link();
}

// TODO: friday we'll replace this with your code from HW8
template <typename T>
void list_clear(node<T>*& head,node<T>*& tail) {
	if (!head) { tail = nullptr; return; } 
    node* temp = head;                     
    head = head->link();                   
    delete temp;                           
    list_clear(head, tail);
}

// pre: head_to and tail_to point to the head and tail of a well-formed list, 
//      head_from point to a starting point of another list
// post: contents starting from head_from have been copied into end of to list
template <typename T>
void list_copy(node<T>*& head_to, node<T>*& tail_to, const node<T>* head_from) {
	while(head_from!=nullptr) {
		// copy next val in from list into tail of to list to maintain order
		list_insert_tail(head_to,tail_to,head_from->data()); 
		head_from = head_from->link(); // move onto next val
	}
}

// pre: head and tail point to beginning and end of well-formed list
// post: list reflects removal of first instance of val, 
//       returning true if found and false otherwise
template <typename T>
bool list_remove_one(node<T>*& head, node<T>*& tail, const T& val) {
	node<T> *curr = head;
	node<T> *prev = nullptr;
	while (curr!=nullptr) { // scan list for val
		if (curr->data()==val) { // TODO: check edge cases
			if (prev==nullptr) head=head->link(); 
			else prev->set_link(curr->link()); // rewire to skip current node
			if (curr==tail) tail=prev;
			delete curr; // avoid orphaning the node we just routed around
			return true; // done! return true to indicate val was found
		}
		prev = curr;
		curr = curr->link();
	}
	return false; // finished list without finding val
}

// pre: head and tail point to beginning and end of well-formed list
// post: #instances of val in list is returned and list reflects their removal
template <typename T>
size_t list_remove_all(node<T>*& head, node<T>*& tail, const T& val) {
	size_t count=0;
	// EXERCISE: implement this stub to call from Bag's erase member function
	while (list_remove_one(head, tail, val)) count++;
	return count; 
}

#endif // NODE_H
