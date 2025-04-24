// Goals: Introduce nodes for linked lists; practice writing recursive functions
// Sara Krehbiel, 11/8/24

#include <iostream>

using namespace std;

class node;
void nodeCode();

void printList(node* head);

void unpackAndRepackDolls(int);

int main() {
	nodeCode();
	unpackAndRepackDolls(3);
	return 0;
}

class node {
public:
    // constructors
    node(): data_(0), link_(nullptr){}
    node (int d, node *l) : data_(d), link_(l) {}

    // accessors
    int data() const { return data_; }
    node* link() const { return link_; }

    // mutators for data_ and link_
    void set_data(int val) { data_ = val; }
    void set_link(node* new_link) { link_ = new_link; }

private:
    int data_;
    node *link_; // link is the ADDRESS of the next node
};


void nodeCode() {
  // build a list 6->4->2 from the back to the front
	node *head = new node(2,nullptr); // at this point, head points to a single node with data 2
  node *tail = head;
	head = new node(4,head); // head points to 4, which points to 2
  //delete head; // note: this would free the 4 node and orphan the 2 node
	head = new node(6,head);

  //node *nodeArr = new node[3]; // note: this creates a block of consecutive nodes (weird)

  // build a list 6->4->2 from front to back
  node *head2 = new node(6,nullptr);
  node *tail2 = head2;
  tail2->set_link(new node(4,nullptr));
  tail2 = tail2->link();
  tail2->set_link(new node(2,nullptr));
  tail2 = tail2->link();

  cout << "The contents of the first list: ";
  cout << head->data() << " " << head->link()->data() << " " << head->link()->link()->data() << endl;

  printList(head);

  cout << head << endl;


	// TODO: print the contents of the list
	// 1. [DONE] With a loop, or a function with a loop
	// 2. With a recursive function
	// 3. By overloading << for node*, either iteratively or recursively
  // 4. Add const to the functions where appropriate!
}


void printList(node* head) {
  for (node *curr = head; curr != nullptr; curr = curr->link()) {
    cout << curr->data() << " ";
  }
  // OR, since head is just a LOCAL copy of an address, modify it instead of curr
  /*for ( ; head != nullptr; head = head->link()) {
    cout << head->data() << " ";
  }*/
  cout << endl;  
}


// a recursive function to unpack some nesting dolls from largest to smallest
void unpackAndRepackDolls(int nDolls) {
  if (nDolls == 0) return; // recursion base case
  cout << "Unpacking doll #" << nDolls << endl; // open biggest (non-recursive)
  unpackAndRepackDolls(nDolls-1); // open+close all remaining (recursive)
  cout << "Repacking doll #" << nDolls << endl; // close biggest (non-recursive)
}


