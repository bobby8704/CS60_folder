// A simple class (defined inline) for node: the building block of linked lists
// Sara Krehbiel, 11/11/24-11/15/24
#ifndef NODE_H
#define NODE_H
#include <iostream>
using std::ostream;

template <typename T> 
class node 
{
    public:
    // constructors
        node(): data_(T()), link_(nullptr){}
        node (T initdata, node<T> *initlink) : data_(initdata), link_(initlink) {}
        // accessors
        T data() const { return data_; }
        node<T>* link() const { return link_; }
        // mutators
        void set_data(const T& val) { data_ = val; }
        void set_link(node<T>* new_link) { link_ = new_link; }

    private:
        T data_;
        node<T> *link_; // link is the ADDRESS of the next node
};

// declarations of linked list toolkit functions
template <typename T> 
ostream& operator <<(ostream& o, node<T> * curr);
// pre: h and t point to the first and last node of a linked list (including an empty list)
// post: t is the same, h points to a newly constructed first node
template <typename T> 
void list_insert_head(node<T> *& h, node<T> *& t, const T& val);
// pre: h and t point to the first and last node of a linked list (including an empty list)
// post: h is the same, t points to a newly constructed last node
template <typename T>
void list_insert_tail(node<T> *& h, node<T> *& t, const T& val);

template <typename T> 
size_t list_size(const node<T>* h, const node<T>* t);

template <typename T> 
void list_clear(node<T>*& head, node<T>*& tail);

template <typename T> 
void list_copy(node<T>*& head_to, node<T>*& tail_to, const node<T>* head_from);

template <typename T> 
bool list_remove_one(node<T> *& h, node<T> *& t, const T& val);

#endif // NODE_H
