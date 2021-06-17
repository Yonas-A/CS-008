#ifndef BST_H
#define BST_H
#include <iostream>
#include "../../!includes/Binary_Search_Tree/binary_search_tree.h"

using namespace  std;

template <typename T>
class BST
{

public:
    
    BST(  );
    BST( const T* sorted_list, int size = -1 );


    // Big three
    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    BST( const BST<T>& copy_me );

    BST<T>& operator =( const BST<T>& rhs );

    ~BST(  );

    //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

    void clear  (  );

    void erase  ( const T& target );

    void insert ( const T& insert_me );

    bool search ( const T& target, tree_node<T>* & found_ptr );


    friend ostream& operator <<( ostream& outs, const BST<T>& tree )
    {
        tree_print( tree.root, 0, outs );
        return outs;
    }

    BST<T>& operator +=( const BST<T>& rhs );

private:
    tree_node<T>* root;

};

//==============================================================
//  CONSTRUCTORS
//==============================================================
template <typename T>
BST<T>::BST(  ): root( nullptr )
{
}

template <typename T>
BST<T>::BST( const T* sorted_list, int size  )
{
    root = tree_from_sorted_list( sorted_list,  size );
}

//==============================================================
//        Big Three functions
//==============================================================

template <typename T>
BST<T>::BST( const BST<T>& copy_me )
{
    const bool DEBUG = false;
    if ( DEBUG ){
        cout << "BST (  ) COPY CTOR" << endl;
    }

    root = tree_copy( copy_me.root );
}

template <typename T>
BST<T>& BST<T>::operator =( const BST<T>& rhs )
{
    const bool DEBUG = false;
    if ( DEBUG ){
        cout << "BST:: = (   )" << endl;
    }

    if( this == &rhs )
        return this;

    if(  root != nullptr )
    {
        tree_clear( root );   // clearing the BST
        root = NULL;
    }

    root = tree_copy( rhs.root ); // copying the rhs to the BST

    return  *this;
}

template <typename T>
BST<T>::~BST(  )
{
    const bool DEBUG = false;
    if ( DEBUG )      {
        cout << "~BST" << endl;
    }

    tree_clear( root );
    root = NULL;
}
//==============================================================
//
//==============================================================

template  <typename T>
void BST<T>::clear(  )
{
    tree_clear( root );
    root = NULL;
}

template  <typename T>
void BST<T>::erase( const T& target )
{
    bool DEBUG = false;
    bool erased = tree_erase( root, target );

    if( DEBUG )
    {
        if( erased )
        {
            cout << "target erased: " << endl;
        }
        else
            cout << "target not found" << endl;
    }
}

template  <typename T>
void BST<T>::insert( const T& insert_me )
{
    tree_insert<T>( root, insert_me );
}

template  <typename T>
bool BST<T>::search( const T& target, tree_node<T>* & found_ptr )
{
    return  tree_search( root, target, found_ptr );
}

template  <typename T>
BST<T>& BST<T>::operator +=( const BST<T>& RHS )
{
    tree_add( root, RHS.root );
    return *this;
}


#endif // BST_H
