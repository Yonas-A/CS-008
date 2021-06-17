#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

#include "../../!includes/Doubly_Linked_List/doubly_linked_list.h"

template <typename T>
class Queue
{

public:

    Queue( );

    //=========================================================

    Queue( const Queue<T>& other );

    Queue<T> &operator =( const Queue& rhs );

    ~Queue( );

    //=========================================================

    void Clear ( );

    bool Empty( ) const;

    T Front( ) ;

    T Pop( );

    void Push( const T& item );

    int Size( );

    friend ostream& operator << ( ostream& outs, const Queue& q )
    {
        return _print_list( q._head, outs );
    }

private:
    node<T>* _head;
    node<T>* _tail;
};


//==============================================================
//  Default Ctor
//==============================================================

template <typename T>
Queue<T>::Queue( ) : _head( nullptr ), _tail( nullptr )
{

}

//==============================================================
//            Big three
//==============================================================

template <typename T>
Queue<T>::Queue( const Queue<T>& other )
{
    const bool debug = false;
    if (  debug  ){
        cout << "Queue (  ) COPY CTOR"<<endl;
    }

    _tail = _copy_list( other._head, _head = nullptr  );
    /// tail points to the last node in the new list
}

template <typename T>
Queue<T>& Queue<T>::operator =( const Queue& rhs )
{
    const bool debug = false;
    if ( debug  ){
        cout << "Queue:: = (   )" << endl;
    }

    if( this == &rhs  ) //self reference
        return *this;

    //clean up of the existing object
    if(  _head != nullptr  )
    {
        _clear_list( _head ); // clearing everyting in list
        _head = nullptr;  // setting the head_ptr to null
        _tail = nullptr; // setting the end ptr to null
    }

   _tail =  _copy_list( rhs._head, _head = nullptr );
    //copy contents of the rhs node

    return *this;
    //return ur self
}

template < typename T >
Queue<T>::~Queue( )
{
    const bool debug = false;
    if ( debug ) {
        cout << "~Queue(  ) destructor" << endl;
    }

    _clear_list( _head );
    _head = nullptr;
    _tail = nullptr;
}

//=============================================
//  member functions
//=============================================
template  <typename T>
void Queue<T>::Clear(  )
{
    ///clear everyting and set head and tail to null
    _clear_list( _head );
    _head = nullptr;
    _tail = nullptr;
}

template  <typename T>
bool Queue<T>::Empty (  ) const
{
    return _empty( _head );
}

template <typename T>
T Queue<T>:: Front(  )
{
    assert( _head != nullptr && "head is null" );
    return  _head->_item;
}

template <typename T>
T Queue<T>::Pop (  )
{
    T item = _remove_head( _head );

    if( _empty( _head ) )
        _tail = nullptr;
    // setting the _tail ptr to null if no list exists;

    return item;
}

template <typename T>
void  Queue<T>::Push ( const T& item )
{
    _tail = _insert_last( _head, item );
}

template <typename T>
int  Queue<T>::Size (  )
{
    return ( _size( _head ) );
}

#endif // QUEUE_H
