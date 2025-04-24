// Implementations of linked list functionality declared in node.h
// Sara Krehbiel, 11/11/24-11/15/24
#include "node.h"

template <typename T> 
void list_insert_head(node<T> *& h, node<T> *& t, const T& val) 
{
    h = new node<T>(val,h);
    if (t == nullptr) t = h; // handles edge case that the list started empty
}

template <typename T>
void list_insert_tail(node<T> *& h, node<T> *& t, const T& val)
{
    if (t == nullptr) 
    { // handles edge case that list starts empty
        h = t = new node<T>(val,nullptr);
    } 
    else 
    {
        t->set_link(new node<T>(val,nullptr));
        t = t->link();
    }
}

template <typename T> 
size_t list_size(const node<T>* h, const node<T>* t)
{
    if (h==nullptr) return 0; 
    return 1+list_size(h->link(), t);
}

template <typename T> 
ostream& operator <<(ostream& o, node<T> * curr)
{
    // Recursively
    if (curr == nullptr) return o;
    return o << curr->data() << " " << curr->link();

    /*
    node<T> *curr = n;
    while (curr != nullptr) 
    {
        o << curr->data() << " ";
        curr = curr->link();
    }
    return o;
    */
}

template <typename T> 
void list_clear(node<T>*& head, node<T>*& tail)
{
    if (!head) {tail = nullptr; return;}
    node* temp = head;
    head = head->link();
    delete temp;
    list_clear(head, tail)

}

template <typename T> 
void list_copy(node<T>*& head_to, node<T>*& tail_to, const node<T>* head_from)
{
    while (head_from != nullptr)
    {
        list_insert_tail(head_to, tail_to, head_from->data());
        head_from = head_from->link();
    }
}

template <typename T> 
bool list_remove_one(node<T> *& h, node<T> *& t, const T& val)
{
    node<T> *curr = head;
    node<T> *prev = nullptr;
    while (curr != nullptr)
    {
        if (curr->data() == val)
        {
            prev->set_link(curr->link());

            delete curr;
            return true;
        }
        prev = curr;
        curr = curr->link();
    }
    return false;
}