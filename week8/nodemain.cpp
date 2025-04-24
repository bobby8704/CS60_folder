// A driver program to start experimenting with linked lists built on nodes,
// including a general recursion refresher and linked list recursion exercises.
// Sara Krehbiel, 11/11/24-11/15/24

#include <iostream>
#include "node.h"
using namespace std;

void monday();
void printList(node* head); // print a list given a pointer to the first node

void wednesday();
// a recursive function for conceptual inspiration
void unpackAndRepackDolls(int nDolls) {
  if (nDolls == 0) return; // recursion base case
  cout << "Unpacking doll #" << nDolls << endl; // open biggest (non-recursive)
  unpackAndRepackDolls(nDolls-1); // open+close all remaining (recursive)
  cout << "Repacking doll #" << nDolls << endl; // close biggest (non-recursive)
}

int main() {
	monday(); // TODO #1: learn about const with pointers and update <<
	//unpackAndRepackDolls(3); // TODO #2: practice with recursion and update <<
	//wednesday(); // TODO #3: recursively implement list_size and list_search
	return 0;
}

void wednesday() {
	node *head = nullptr, *tail = nullptr;
	for (int i=0; i<10; i++) {
		list_insert_head(head,tail,(i+1)*(i+1)); 
	}
	cout << head << endl;
}

void monday() {

	// quiz!
	node *head = nullptr, *tail = nullptr;
	list_insert_head(head,tail,0); // or list_insert_tail!
	//node *head = new node(0,nullptr);
	//node *tail = head;

	// insert 1 at head
	//head = new node(1,head);
	list_insert_head(head,tail,1);

	// insert 2 at tail
	// option 1: use a temp ptr and construct/rewire in 3 steps
	//node *temp = new node(2,nullptr);
	//tail->set_link(temp);
	//tail = temp;
	// option 2: don't use a temp ptr, get all info you need from tail
	//tail->set_link(new node(2,nullptr));
	//tail = tail->link();
	list_insert_tail(head,tail,2);

	// TODO #2: practice with recursion
	//unpackAndRepackDolls(3);

	// TODO #3: recap printList, incl while loop/no loop variable variants,
	//          then implement printListRec and non-recursive and recursive <<
	
	/*cout << "Contents of first list: ";
	cout << head1->data() << " " << head1->link()->data() << " " 
		<< head1->link()->link()->data() << endl;
*/
	cout << "Contents: ";
	printList(head);

  	cout << "Contents: " << head << endl;
}

// given a pointer to a first node in a list, print its and all subsequent data
void printList(node* head) { 
	// inspired by: for (int i=0; i<n; i++) cout << a[i] << " "; 
	/*for (node *curr = head; curr!=nullptr; curr = curr->link()) {
		cout << curr->data() << " "; // using ptr to current node, cout its data
	}*/
	// or as a while loop:
	node *curr = head;
	while (curr != nullptr) {
		cout << curr->data() << " ";
		curr = curr->link();
	}
	// without a loop variable (better to rename param from head to curr)
	/*for ( ; head!=nullptr; head=head->link()) {
		cout << head->data() << " ";
	}*/
	// or as a while loop:
	/*while (head!=nullptr) {
		cout << head->data() << " ";
		head = head->link();
	}*/
	cout << endl;
}	

