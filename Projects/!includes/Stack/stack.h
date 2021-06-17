#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "../../!includes/Doubly_Linked_List/doubly_linked_list.h"

template <typename T>
class Stack
{
public:

    Stack();

    ~Stack();

    Stack(const Stack <T>& other);

    Stack<T>& operator =(const Stack<T>& rhs);


    bool Empty() const;

    T Pop();

    void Push( const T& item );

    T Top( ) const;

    /// retuns the size of the list
    int Size( )  const;

    friend ostream& operator << ( ostream& outs, const Stack& s )
    {
        return _print_list( s._top, outs );
    }

private:

    node<T>* _top;
};


//================================
//  Default Ctor
//================================

template<typename T>
Stack<T>::Stack()
{
    _top = nullptr;
}

//=============================================
//            Big three
//=============================================

template <typename T>
Stack<T>::~Stack()
{
    const bool debug = false;
    if (debug) {
        cout << "~Stack() destructor" << endl;
    }

    _clear_list(_top);
    _top = nullptr;
}

template <typename T>
Stack<T>::Stack( const Stack<T>& other )
{
    const bool debug = false;
    if (debug){
        cout<<"Stack () COPY CTOR"<<endl;
    }

     _copy_list(other._top, _top = nullptr);
    // Last points to the last node in the new list
}

template <typename T>
Stack<T>& Stack<T>::operator =(const Stack& rhs)
{
    const bool debug = false;
    if (debug){
        cout << "Stack:: = ( )" << endl;
    }

    if(this == &rhs) //self reference
        return *this;

    //clean up of the existing object
    if(_top != nullptr)
    {
        _clear_list(_top); // clearing everyting in list
        _top = nullptr;  // setting the head_ptr to null
    }

    _copy_list(rhs._top, _top = nullptr);
    //copy contents of the rhs node

    return *this;
    //return ur self
}


//=============================================
//  member functions
//=============================================

template  <typename T>
bool Stack<T>::Empty ( ) const
{
    return _empty( _top );
}

template <typename T>
T Stack<T>::Pop ( )
{
//    const bool DEBUG = false;

    T item = _remove_head( _top );
    if( _empty( _top ) )
        _top = nullptr;

//    if( DEBUG && _top != nullptr )
//        cout << "Pop():    _head_ptr = " << _top->_item << endl;

    return item;
}

template<typename T>
void Stack<T>::Push(const T& item)
{
    _insert_head( _top, item );
}

template <typename T>
T Stack<T>::Top() const
{
    return _top->_item;
}

template <typename T>
int Stack<T>:: Size( )  const
{
    return _size( _top) ;
}




#endif // STACK_H
