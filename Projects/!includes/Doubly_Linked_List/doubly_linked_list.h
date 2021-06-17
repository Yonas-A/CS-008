#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <assert.h>

using namespace std;

template <typename T>
struct node
{

    T _item;
    node* _next;
    node* _previous;

    node(const T& item = T(), node* next = nullptr,
         node* previous = nullptr);

    template <typename U>
    friend std::ostream& operator <<(std::ostream& outs,
                                     const node<U> &printMe);

};


//===========================================
//      Definitions
//===========================================

template <typename T>
node <T>::node(const T& item, node <T>* next, node<T>* previous)
{
    _previous = previous;
    _item = item;
    _next = next;
}

template <typename U>
std::ostream& operator <<(std::ostream& outs, const node<U> &printMe)
{
    outs << "[" << printMe._item << "]->" ;
    return outs;
}


//====================================================================
//          list functions declarations
//====================================================================

template <typename T>
void _clear_list(node<T>* &head_ptr);
// same function and implementation as delete_all
//Precondition: takes type T head pointer to a node
//Postcondition: releases the space occupied by list;

template <typename T>
node<T>* _copy_list( const node<T>* src_head, node<T>* &dest_head);
//Precondition: takes 2 type T head_ptrs to a node
//Postcondition: copies the list to a new node and
//               returns the end node of the new_list

template <typename T>
bool _empty(const node<T>* head_ptr);
//Precondition: takes type T head pointer to a node
//Postcondition: returns true if list is empty else false

template <typename T>
node<T>* _end(node<T>* head_ptr);
//Precondition: takes type T head pointer to a node
//Postcondition: returns last node before nullptr

template <typename T>
node<T>* _initialize_head(node<T>* &head);
//Precondition: takes type T head pointer to a node
//Postcondition: returns an initialized head

template <typename T>
node<T>* _insert_after(node<T>* &head_ptr, node<T>* mark,
                       const T& insert_this);
//Precondition: takes two type T ptrs, and T variable to insert
//Postcondition: a new node is made out of insert_this and
//              is inserted after node mark and
//              returns ptr to inserted node;


template <typename T>
node<T>* _insert_before(node<T>* &head_ptr, node<T>* mark,
                        const T& insert_this);
//Precondition: takes two T ptrs, and T variable to insert
//Postcondition: a new node is made out of insert_this and
//              is inserted before node mark and ptr to
//              inserted node is returned.

template <typename T>
node<T>* _insert_head(node<T>* &head_ptr, const T& insert_this);
//Precondition: takes type T ptr, and T variable to insert
//Postcondition: a new node is made out of insert_this and
//              is inserted before all other nodes at the
//              head of list

template <typename T>
node<T>* _insert_last(node<T>* &head_ptr, const T& insert_this);
//Precondition: takes type T ptr, and T variable to insert
//Postcondition: a new node is made out of insert_this and
//              is inserted at the end of list
//              returns address to the last node

template <typename T>
void _print(node<T>* head_ptr , ostream& outs = cout);
//Precondition: takes type T node head ptr
//Postcondition: prints all items until nullptr

template <typename T>
void _print_backwards(node<T>* head_ptr , ostream& outs = cout);
//Precondition: takes type T node head ptr
//Postcondition: prints all items from back to front

//print the list and return outs
template<typename T>
ostream& _print_list(const node<T>* head, ostream& outs=cout);
//Precondition: takes a const type T node head ptr
//Postcondition: prints the list and returns outs

template  <typename T>
T _remove_head(node<T>* &head_ptr);
//Precondition: takes type T head_ptr
//Postcondition: delete first node and returns the value item had

template  <typename T>
T _remove_node(node<T>* &head_ptr, node<T>* remove_me);
//Precondition: takes type T head_ptr, and node to be removed
//Postcondition: deletes node and returns item deleted node had

template <typename T>
node <T>* _search(node<T>* head_ptr, const T& key);
//Precondition: takes type T head_ptr, and item we are looking for
//Postcondition: return address of key if found or return nullptr

template  <typename T>
int _size(node<T>* head_ptr);
//Precondition: takes type T head_ptr to a list
//Postcondition: return size of the list

//====================================================================
//          list functions Definitions
//====================================================================

template <typename T>
void _clear_list(node<T>* &head_ptr)
{
    /*
     * 1. if list is not empty, remove the head node till
     *    list is empty
     * 2. set head_ptr to null
     */
//    const bool debug = false;
    while( head_ptr != nullptr)     {

//        T hold = _remove_head(head_ptr);
        _remove_head(head_ptr);

//        if(debug) {
//            cout << "_clear_list(): node" << "[" << *hold << "] removed\n";
//        }
    }
    head_ptr = nullptr;
}

template <typename T>
node<T>* _copy_list(node<T>* src_head, node<T>* &dest_head)
{
    /*
     * 1. create a new head ptr;
     * 2. walk thru src_list and pass item and new head_ptr to
     *    _insert_last()
     */

    const bool debug = false;
    dest_head = nullptr;
    node<T>* src_walker = src_head;
    node<T>* dest_walker = dest_head;

    while(src_walker != nullptr)
    {
        dest_walker = _insert_after(dest_head,dest_walker,
                                    src_walker->_item);

        if(debug)
        {
            cout << "_copy_list():   copying :["
                 << src_walker ->_item << "]" <<  endl;
            cout << "\tdest_walker = [" << dest_walker->_item <<"]\n";
        }
        src_walker = src_walker ->_next;
    }

    return dest_walker;

}

template <typename T>
bool _empty(const node<T> *head_ptr)
{
    /*
     * 1. if list empty return true
     * 2. else return false
     */
    const bool debug = false;
    if(head_ptr == nullptr)     {
        if(debug)
            cout << " _empty(): List empty, returning true\n" << endl;
        return true;
    }

    else {
        if(debug)
            cout << "_empty(): List empty, returning false\n" << endl;
        return false;
    }

}

template <typename T>
node<T>* _end(node<T>* head_ptr)
{
    /*
     * 1. if list empty return nullptr
     * 2. else walk thru list and return last node
     */
    const bool debug = false;
    node<T>* walker = head_ptr;

    if(walker == nullptr)    {
        if(debug)
            cout << "_end(): List is empty. Returning NULL\n\n";
        return nullptr;
    }

    else
    {
        while( walker ->_next != nullptr)
        {
            walker = walker -> _next;
        }
        if(debug)
            cout << "_end(): List exists,returning last node \n\n";
        return walker;
    }
}

template <typename T>
node<T>* _initialize_head(node<T>* &head_ptr)
{
    head_ptr = nullptr;
    return head_ptr;
}

template <typename T>
node<T>* _insert_after(node<T>* &head_ptr, node<T>* mark,
                       const T& insert_this)
{
    /* CASE 1
     *  if head_ptr is nullptr call insert_head and insert node as head
     * CASE 2
     * 1. create a new node with insert_this as item
     * 2. new node's next points to where mark's next is pointing
     * 3. new node's previous points to the mark
     * 4. mark's next points to the new node
     * 5. if new node's _next is not null, change _previous of the node
                after temp(new node) to temp( the new node).
     */

    const bool debug = false;

    if(head_ptr == nullptr)
    {
        if(debug)        {
            cout << "\nInside _insert_after()" << endl;
            cout << "head is null. Calling _insert_head()\n" << endl;
        }

        //if list is empty, insert node as the head node
        _insert_head(head_ptr, insert_this);
        return head_ptr;
    }

    assert(mark != nullptr);
    // asserts mark is in the list


    node <T>* temp = new node<T> (insert_this);

    temp -> _next = mark-> _next;
    mark-> _next = temp;
    temp ->_previous = mark;

    if(temp->_next != nullptr)
        temp->_next ->_previous = temp;

    if(debug)
    {
        cout << "\nInside _insert_after()" << endl;
        cout << "Inserting [" << insert_this <<"] after ["
             << mark ->_item << "]" << endl << endl;
    }
    return temp;
}

template <typename T>
node<T>* _insert_before(node<T>* &head_ptr, node<T>* mark,
                        const T& insert_this)
{
    /* CASE 1
     *  if head_ptr is nullptr call insert_head and insert as head

     * CASE 2
     * 1. create a new node with insert_this as item
     * 2. new node's previous points to mark's previous
     * 3. new node's next points to mark
     * 4. mark's _previous points to new node
     * 5. if new node is not the first node then _next of the
     *        new node's  _previous points to new node
     *         (if new node's _previous is not null, change _next of
     *         the node before temp( new node) to temp ( the new node) )
     */

    const bool debug = false;

    if(head_ptr == nullptr)
    {
        if(debug)        {
            cout << "\nInside _insert_before()" << endl;
            cout << "head is null. Calling _insert_head()\n" << endl;
        }

        //if list is empty, insert node as the head node
        _insert_head(head_ptr, insert_this);
        return head_ptr;
    }

    assert(mark != nullptr);
    // asserts mark is in the list


    node <T>* temp = new node<T> (insert_this);

    temp -> _next = mark;
    temp -> _previous = mark -> _previous;
    mark ->_previous = temp;

    if(temp->_previous != nullptr)
        temp->_previous ->_next = temp;

    if(debug)
    {
        cout << "\nInside _insert_before()" << endl;
        cout << "Inserting [" << insert_this <<"] before ["
             << mark ->_item << "]" << endl << endl;
    }
    return temp;
}

template <typename T>
node<T>* _insert_head( node<T>* &head_ptr, const T& item)
{
    /*
     * 1. create a new node with item as _item
     * 2. new node's next points to where head_ptr is pointing to
     * 3. new node's previous is null since it is at head of list
     * 4. if head is not null change the last head node's previous to new node
     * 4. head_ptr points to the new node
     */

    node <T>* hold = new node<T>(item);
    hold->_next = head_ptr;
    hold->_previous = nullptr;

    if ( head_ptr  != nullptr )
        head_ptr->_previous = hold;

    head_ptr = hold;
    return hold;
}

template <typename T>
node<T>* _insert_last(node<T>* &head_ptr, const T& insert_this)
{
    /*  Case 1
     *  if list is empty, call _insert_head and add node at head
     *  Case 2
     * 1. get a walker and walk it to the last node
     * 2. create a new node with insert_this as the _item
     * 2. change the last node's (walker's) next to this new node
     * 3. new node's _previous is last node(walker).
     * 4. change new node's _next to null.
     */
    const bool debug = false;
    node<T>* last = _end(head_ptr);

    if(last == nullptr)     {
        if(debug)
            cout << "_insert_last():\t" << "inserting head\n\n";

        _insert_head(head_ptr, insert_this);
        return head_ptr;
    }

    else
    {
        node <T>* temp = new node<T> (insert_this);
        last -> _next = temp ;
        temp->_previous = last;
        temp -> _next = nullptr;

        if(debug)         {
            cout << " _insert_last():\t inserting [" << insert_this
                 << "] at the end of list" << endl << endl;
        }

        return temp;
    }
}

template  <typename T>
void _print(node <T>* head_ptr, ostream&)
{
    /*
     * 1. get a walker to walk thru all nodes
     * 2. send *walker to ostream for all nodes
     */
    cout <<"List : " << endl << "\t" << "H->";
    node <T>* walker = head_ptr;

    while( walker!= nullptr)
    {
        cout << *walker << " ";
        walker = walker ->_next;
    }
    cout << "|||" << "\n\t - - - - - - - - - - - - - - - - - - -\n" ;
}

template <typename T>
void _print_backward(node<T>* head_ptr , ostream& outs )
{
    outs <<"List : " << endl << "\t" << "|||->";
    node <T>* walker = _end(head_ptr);

    while( walker!= nullptr)
    {
        outs << *walker;
        walker = walker ->_previous;
    }
    outs << "H" << "\n\t - - - - - - - - - - - - - - - - - - -\n" ;
}

template<typename T>
ostream& _print_list(const node<T>* head_ptr, ostream& outs)
{
    //    cout << "List : " << endl << "\t" << "H->";
    while( head_ptr!= nullptr)
    {
        cout << " " << *head_ptr;
        head_ptr = head_ptr ->_next;
    }
    cout << "|||"  ;



    return outs;
}

template  <typename T>
T _remove_head(node <T>* &head_ptr)
{
    /*
     * 1. create a T var to hold item from node being removed
     * 2. copy item of removed node to T var
     * 3. remove node
     * 4. return item;
     */

    assert(head_ptr != NULL && "_remove_head: Head pointer cannot be null" );


    node <T>* temp =  head_ptr;
    T hold = temp->_item;

    if( temp ->_next != nullptr)
    {
        head_ptr = temp->_next;
        head_ptr->_previous = nullptr;
        delete temp;
        return hold;
    }

    else
    {
        head_ptr = nullptr;
        delete temp;
        return hold;
    }
}

template  <typename T>
T _remove_node(node<T>* &head_ptr, node<T>* remove_me)
{
    /*
     * 1. assert remove_me is in the list and list is not empty
     *  CASE 1:
     * 1. if remove_me is head of list, call _remove_head
     *          and remove it.
     * CASE 2:
     * 3. copy item of node to be removed
     * 4. node before remove_me's next points to where remove_me is
     *    pointing to
     * 5. remove node
     * 6. return item;
     */

    const bool debug = false;
    assert(head_ptr != nullptr && "head_ptr is null");
    assert(remove_me != nullptr && "remove_me is null");

    if( head_ptr == remove_me )
    {
        if(debug)
            cout << "_remove_node(): remove_me = head.\n";
        return (_remove_head(head_ptr));
    }

    T hold_item ;

    if( remove_me->_next != nullptr )
    {
        if(debug)
            cout << "_remove_node(): remove_me->_next != nullptr\n";
        remove_me->_next->_previous = remove_me->_previous;
        hold_item = remove_me->_item;
    }

    if(remove_me->_previous != nullptr)
    {
        if(debug)
            cout << "_remove_node(): remove_me->_prev != nullptr\n";
        remove_me->_previous->_next = remove_me->_next;
        hold_item = remove_me ->_item;
    }

    delete remove_me;
    return hold_item;

}

template <typename T>
node <T>* _search(node <T>* head_ptr, const T& key)
{
    /*
     * 1. get a walker to walk thru all nodes
     * 2. search each node for key
     * 3. return address or return null if not found
     */
    assert( head_ptr != nullptr && "head can't be null: _search()");

    const bool debug = false;
    node <T>* walker = head_ptr;

    while(walker != nullptr)
    {
        if( walker ->_item == key)
        {
            if(debug)
                cout << "\nInside _search(): \titem is found\n" << endl;
            return walker;
        }
        walker = walker ->_next;
    }

    if(debug)
        cout << "\nInside _search(): \tItem is not found\n" << endl;

    return nullptr;
}

template  <typename T>
int _size(node<T>* head_ptr)
{
    /*
     * 1. walk thru all the nodes
     * 2. count number of nodes
     * 3. return count;
     */

    node<T>* walker = head_ptr;
    int count = 0;
    while(walker != nullptr )
    {
        walker = walker ->_next;
        count++;
    }
    return count;
}



#endif // LIST_H
