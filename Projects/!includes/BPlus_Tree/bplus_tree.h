#pragma once

#ifndef BPLUS_TREE_H
#define BPLUS_TREE_H

#include <iostream>
#include <string>

#include "../../!includes/Array_Functions/array_functions.h"


using namespace std;


template < typename T >
class BPlusTree
{

public:

    class Iterator
    {
    public:

        friend class BPlusTree<T>;

        Iterator( const BPlusTree<T>* t = NULL,int kp = 0 ):it( t ), key_ptr(kp)
        {
            assert( kp >= 0 && "Iterator: key ptr < 0 " );
        }

        T operator *()
        {
            assert( key_ptr < it-> data_count &&
                    "key_ptr == current iterators data count" );
            return it->data[ key_ptr ];
        }

        /// The postfix ++ operator, advances the iterator to the next
        /// in data and \returns an iterator to the previously current item.
        Iterator operator ++( int )
        {
            if ( key_ptr + 1 == it-> data_count )
            {
                Iterator hold = it;
                it = it->next;
                key_ptr = 0;
                return hold;
            }

            else
            {
                key_ptr++;
                return *this;
            }
        }

        ///The prefix ++ operator, advances the iterator to the next
        /// item in the data  and returns this iterator.
        Iterator operator ++( )
        {
            if ( key_ptr + 1 == it-> data_count )
            {
                it = it->next;
                key_ptr = 0; /// reset key_ptr to zero for the next node
            }
            else
            {
                key_ptr++;
            }

            return *this;
        }

        friend bool operator == (const Iterator& LHS, const Iterator& RHS)
        {
            return ( LHS.it == RHS.it );
        }

        friend bool operator != (const Iterator& LHS, const Iterator& RHS)
        {
            return ( LHS.it != RHS.it );
        }

        void print_Iterator()
        {
            cout << "data count: " << it->data_count << endl;
            cout << "key_ptr: " << key_ptr << endl;
            cout << "[" << it->data[key_ptr] << "] ->" ;
        }

        bool is_null()
        {
            return !it;
        }

    private:
        const BPlusTree<T>* it;
        int key_ptr;
    };

    // =============================================================
    // ctor
    BPlusTree( bool dups = false);

    // =============================================================
    //copy ctor, assignment operator & dtor

    BPlusTree( const BPlusTree<T>& other);

    BPlusTree<T>& operator =(const BPlusTree<T>& RHS);

    ~BPlusTree();

    // =============================================================
    // iterators

    /// @returns the leftmost leaf node with the smallest item in the tree
    Iterator begin( ) const  ;

    /// @returns a nullptr iterator to indicate iterator is at the end
    Iterator end( )  const ;

    /// @returns first node that goes NOT BEFORE key if key exists OR
    /// @returns the next nearest item if  key does not exist
    Iterator lower_bound( const T& key ) const;

    /// @returns first node that goes AFTER key if key exists in B+ tree OR
    /// @returns the nearest item with a greater key if  key does not exist
    Iterator upper_bound( const T& key ) const;

    // ==============================================================
    // Accessors / modifiers

    /// @returns a reference to entry if entry already exists in B+ tree or
    /// entry is inserted in the B+ tree and @returns a reference to the
    ///     newly inserted entry
    T& get( const T& entry );

    /// return a const reference to entry in the tree
    const T& get( const T& entry ) const;


    // ==============================================================
    // modifiers

    /// clears this object ( deletes all subtrees and sets data_count
    /// and child_count to 0
    void clear( );

    /// copy everything other has onto 'this' object
    void copy( const BPlusTree<T>& other );

    /// insertes entry into the tree
    void insert( const T& entry );
    ///  @if  entry is already in the tree update the tree or append entry
    ///  \else insert entry into tree

    /// removes target if it exists in the tree
    void remove( const T& target );
    /// \if target is in the B+ tree structure, remove this key
    /// \else do nothing

    // ==============================================================
    // operations

    /// \returns true if target is found or
    /// \returns false if target cannot be found in the tree
    bool contains( const T& target) const;


    /// @returns an iterator to the node containing target if it exists
    /// in the tree or
    /// @returns a null iterator if target cannot be found in the tree
    Iterator find( const T& target ) const;


    /// @returns tree if after deleting an item, it it's reference
    ///     (bread crumbs ) exists in the tree or
    /// @returns false if after deleting an item, its' reference is
    ///         also deleted
    bool find_for_debug( const T& target) const;


    // ==============================================================
    // capacity and size

    /// @returns true if tree doesn't have any data or
    /// @returns true if tree has data and or children
    bool empty( ) const;

    /// \returns total element counts in the entire B+ Tree structure
    int size( ) const;

    // ==============================================================
    // validations

    /// @returns true if tree sastisfies all of B+ tree structure rules
    /// or
    /// @returns false if at lease a single rule of B+ tree is violated
    bool is_valid( ) const;

    // =============================================================
    // insertion operator and outputs

    /// prints a readable tree vertically, starting from rightmost leaf
    void print ( int level = 0, ostream& outs = cout ) const;

    friend ostream& operator << ( ostream& outs, const BPlusTree<T>& t )
    {
        t.print( 0, outs );
        return outs;
    }


private:
    static const int MINIMUM = 1;
    static const int MAXIMUM = 2 * MINIMUM;

    /// true if duplicate may be inserted
    bool dups;
    /// holds the keys
    T data [ MAXIMUM + 1];
    /// holds pointers for subtree ( children
    BPlusTree<T>* subset [ MAXIMUM + 2 ];
    /// number of data elements
    int data_count = 0;
    /// number of children nodes / subtrees
    int child_count = 0;
    /// leaf link
    BPlusTree<T>* next = nullptr;

    /// =============================================================
    ///             private helper Function
    // =============================================================
    // all purpose helper functions

    /// @returns true if tree has children or subsets or
    /// @returns false if tree has no children
    bool is_leaf( ) const ;

    // =============================================================
    // Iterators search process helper

    /// @returns the leftmost node of a given B+ tree node
    const BPlusTree<T> *get_smallest_node()  const ;

    // =============================================================
    // accessors / modifiers process helper

    /// @returns a reference to the target if found or
    /// Asserts to indicate that item could not be found
    T& get_existing( const T& target );

    /// @returns a reference to the target if found or
    /// Asserts to indicate that item could not be found
    const T &get_existing( const T& target ) const;


    // =============================================================
    // copying process helper

    /// copies all of other's items into this tree and connects
    /// the links at leaf nodes
    void copy_tree(const BPlusTree<T>& other, BPlusTree<T>*&last_leaf=NULL);
    /// called by copy( ) to copy all other's data and also connect
    /// leaf nodes of 'this' object thru BPlusTree pointer next

    // =============================================================
    // insertion process helper

    /// inserts entry into tree, allows MAXIMUM +1 data elements in root
    bool loose_insert(const T& entry);

    /// fix excess data elements in child i
    void fix_excess( int i );

    // =============================================================
    // removing process helper

    bool loose_remove( const T& entry );
    /// removes entry from tree, allows MINIMUM -1 data elements in root

    /// @return child at i ( subset[i])  after fixing a data shortage at subset[i]
    BPlusTree<T>* fix_shortage(int i);


    /// finds and sets entry to the smallest ( leftmost ) element in the tree
    /// and @returns entry by reference
    void get_smallest( T& entry );

    /// combines ( merges ) subset[i+1]'s data and children with its
    /// neighbour subset[i] and @return subset[i]
    BPlusTree<T>* merge_with_next_subset( int i );


    /// transferes a single emeemnt from subset[i+1] to subset[i] to
    /// fix data shortage at subset[i]
    void rotate_left( int i );

    /// transferes a single emeemnt from subset[i-1] to subset[i] to
    /// fix data shortage at subset[i]
    void rotate_right( int i );


    // =============================================================
    // search process helper

    /// @returns a pointer to target if target is found in b+ tree or
    /// @returns a nullptr if target can not be found in b+ tree
    T* find_ptr( const T& target );

    // ===============================================================
    // undetermined use so far

    /// finds and sets entry to the largest ( rightmost ) leaf element in
    /// the tree and @returns entry by reference
    void get_biggest( T& entry );
    ///entry := rightmost leaf
};

/// ===============================================================
/// ===============================================================

// =============================================================
// defualt ctor

template < typename T >
BPlusTree<T>::BPlusTree( bool d ): dups(d), data_count(0), child_count(0)
{
    if ( const bool DEBUG = false )
        cout << "BPlusTree( dups) " << endl;

    initialize_array<T>( data, MAXIMUM + 1 );
    for ( int i = 0 ; i < MAXIMUM + 2; i++ )
        subset[ i ] = nullptr;
}

// =============================================================
// copy ctor, assignment operator and dtor

template  < typename T >
BPlusTree<T>::BPlusTree(const BPlusTree<T>& other )
{
    if ( const bool DEBUG = false )
        cout << "BPlusTree ( const BPlusTree<T>& )" << endl;

    dups = other.dups;
    copy( other );
}

template<typename T>
BPlusTree<T>& BPlusTree<T>::operator = ( const BPlusTree<T>& RHS )
{
    if ( const bool DEBUG = false )
        cout << "BPlusTree =( const BPlusTree<T> ) " << endl;

    if ( this ==  &RHS ) // check if self and RHS are the same
        return *this;

    clear();        /// clear the tree
    copy( RHS );    /// copy the tree from RHS to this

    return *this;
}

template<typename T>
BPlusTree<T>::~BPlusTree()
{
    if ( const bool DEBUG = false )
        cout << "~BPlusTree ( )" << endl;

    clear();
}

// =============================================================
// Iterators

template <typename T>
typename BPlusTree<T>::Iterator BPlusTree<T>::begin( ) const
{
    /// @returns an iterator from the leftmost tree with smalles value
    return Iterator( get_smallest_node( ) ) ;
}

template <typename T>
typename BPlusTree<T>::Iterator BPlusTree<T>::end( ) const
{
    /// @returns nullptr
    return Iterator( nullptr );
}

template <typename T>
typename BPlusTree<T>::Iterator BPlusTree<T>::lower_bound(const T& key) const
{
    Iterator it;
    int i = first_ge ( data, data_count , key );
    bool found = ( i < data_count && data[ i ] == key);

    /// if key is found and current node has no children
    if( found && is_leaf( ) )
    {
        //// return an iterator to this key
        it = Iterator( this, i );
        return it;
    }

    /// if key is found but current node has children
    else if ( found && !is_leaf() )
        /// recursive call on root's i+1 child
        return subset[i+1]->lower_bound( key );

    /// if key is not found and current node has no children
    else if ( !found  && is_leaf( ) )
    {
        if ( is_le( data, data_count, key ) )
        {
            it = Iterator ( this, i);
            return it;
        }
        else
        {
            it = Iterator ( this, i-1 );
            return it;
        }
    }

    /// if key is not found and current node has children
    else /// if ( !found && !is_leaf() )
    {
        // recursively call lower_bound on root's i-th child
        it =  subset[ i ]->lower_bound( key );
        if ( it != Iterator(nullptr) && key > *it  )
            it++;
        return it;
    }

}

template <typename T>
typename BPlusTree<T>::Iterator BPlusTree<T>::upper_bound(const T& key) const
{
    Iterator it;
    int i = first_ge ( data, data_count , key );
    bool found = ( i < data_count && data[ i ] == key);

    /// if key is found and current node has no children
    if( found && is_leaf( ) )
    {
        /// \if key is in the tree, \return an iterator to its previous item
        it = Iterator( this, i );
        return it;
    }

    /// if key is found but current node has children
    else if ( found && !is_leaf() )
        /// recursive call on root's i+1 child
    {
        it =  subset[ i+1 ]->upper_bound( key );
        if ( it != Iterator(nullptr) &&  *it <= key  )
            it++;
        return it;
    }

    /// if key is not found and current node has no children
    else if ( !found  && is_leaf( ) )
    {
        if ( is_gt( data, data_count, key ) )
        {
            it = Iterator ( this, i-1);
            return it;
        }
        else
        {
            it = Iterator ( this, i );
            return it;
        }

    }

    /// if key is not found and current node has children
    else /// if ( !found && !is_leaf() )
    {
        // recursively call upper_bound on root's i-th child
        it =  subset[ i ]->upper_bound( key );
        if ( it != Iterator(nullptr) &&  *it <= key  )
            it++;
        return it;
    }

}

// ==============================================================
// Accessors / modifiers

template < typename T >
T& BPlusTree<T>::get ( const T& entry )
{
    /** \details
     * \if entry does not exist in the tree, insert entry
     * \else if entry does exist, then @return a const reference to entry
     */
    if ( contains( entry ) == false )
        insert ( entry );

    return BPlusTree<T>::get_existing( entry );
}

template < typename T >
const T& BPlusTree<T>::get ( const T& entry ) const
{
    if ( contains( entry ) == false )
        assert (false && "B+ get( ) const : entry does not exist" );
    return get_existing ( entry );
}

// ==============================================================
// modifiers

template < typename T>
void BPlusTree<T>::clear()
{
    /** \details
     * if  current tree has children
     *      for ( int i =  0 ; i < child_count ; i++ )
     *          call clear on each child:  subset[i]->clear()
     *          delete each subset
     *          set each subset to null
     * set data count and child count of current tree to zero
     */

    for( int i =  0 ; i < child_count ; i++ )
    {
        subset[ i ]->clear();
        /// delete each child and set it to null
        delete subset[ i ];
        subset[ i ] = nullptr;
    }
    child_count = 0;
    data_count = 0;
}

template < typename T >
void BPlusTree<T>::copy( const BPlusTree<T>& other )
{
    /** \note
     * must make sure last_leaf_ptr is null otherwise
     * our leaf node next pointer will be corrupted
     **/
    assert( empty( ) && "BPlusTree<T>::copy: 'this' is not empty");
    BPlusTree* last_leaf_ptr = nullptr;
    copy_tree(other, last_leaf_ptr);
}

template < typename T >
void BPlusTree<T>::insert( const T& entry )
{
    if ( loose_insert( entry ) == false )
    {
        if( const bool DEBUG = true )
            cout << "B+ insert( ): " << entry << " already exists" << endl;
        return;
    }

    if ( data_count > MAXIMUM ) // if the root node is excess,
    {
        BPlusTree<T>* a = new BPlusTree<T>; // a is a pointer to a new tree
        // create a new tree
        a->copy( *this );
        // copy the entire tree into the new tree
        clear();
        // clear this root node,
        data_count = 0;   child_count = 1;
        // set new roots data count to 0 & child count to 1
        subset[ 0 ] = a;
        // make the new node this root's only child (subset[0])
        fix_excess( 0 );
        // call fix_excess on the new root that has no data and 1 child
    }
}

template < typename T >
void BPlusTree<T>::remove ( const T& target )
{
    if ( loose_remove( target ) == false )
    {
        if( const bool DEBUG = false )
            cout << "B+ remove( ): " << target << " not in tree" << endl;
        return;
    }

    // if root has no elements but one child
    if ( ( data_count == 0 ) && ( child_count == 1 ) )
    {
        BPlusTree<T>* temp = subset[0];
        // point at the child
        copy ( *temp );
        //shallow copy the child to this
        temp->child_count = 0;
        // set pointers child count and data count to 0
        temp->data_count = 0;
        // delete the pointer
        delete temp;
    }
}

// ==============================================================
// operations

template < typename T>
bool BPlusTree<T>::contains ( const T& target ) const
{
    int i = first_ge ( data, data_count , target );
    bool found = ( i < data_count && data[ i ] == target );

    //if target is found and current node has no children
    if (  found && is_leaf()  )
        return true;

    //if target is found but current node has children
    else if ( found && !is_leaf() )
        // recursive call on root's i+1 child
        return subset[i+1]->contains( target );

    //if target is not found and current node has no children
    else if ( !found  && is_leaf( ) )
        return false;

    //if target is not found and current node has children
    else  ///if ( !found && !is_leaf() )
        // recursively call contain on root's i-th child
        return subset[ i ]->contains( target );

}

template < typename T >
typename BPlusTree<T>::Iterator BPlusTree<T>::find( const T& target ) const
{
    int i = first_ge ( data, data_count , target );
    bool found = ( i < data_count && data[ i ] == target);

    //if target is found and current node has no children
    if( found && is_leaf( ) )
    {
        return Iterator( this, i );
    }

    //if target is found but current node has children
    else if ( found && !is_leaf() )
        // recursive call on root's i+1 child
        return subset[i+1]->find( target );

    //if target is not found and current node has no children
    else if ( !found  && is_leaf( ) )
        return Iterator(nullptr);

    //if target is not found and current node has children
    else /// if ( !found && !is_leaf() )
        // recursively call contain on root's i-th child
        return subset[ i ]->find( target );
}

template < typename T >
bool BPlusTree<T>::find_for_debug(const T& target ) const
{
    int i = first_ge ( data, data_count , target );
    bool found = ( i < data_count && data[ i ] == target);

    //if item is found return pointer to item
    if( found )
        return true;

    // if not found and root doesn't have children return null
    else if( is_leaf ( ) )
        return false;

    else // call find recursively on the tree's i-th child
        return subset[ i ]->find_for_debug ( target );
}

// ==============================================================
// capacity and size

template < typename T >
bool BPlusTree<T>::empty( ) const
{
    return ( data_count == 0 );
}

template < typename T >
int BPlusTree<T>::size( ) const
{
    int count = 0;
    for ( int i = 0; i < data_count + 1 ; i++)
    {
        if ( !is_leaf( ) )
            count += subset[i]->size();
    }
    count += data_count;
    return count;
}

// ==============================================================
// validations

template < typename T >
bool BPlusTree<T>::is_valid( ) const
{
    const bool DEBUG = true;

    // do an inorder traversal
    //  1. if data[i] > data[i+1] if true then tree is invalid:
    //  2.
    //  3. if tree has children & child_count > data_count + 1, tree invalid
    //  4. check if child_count > allowed max + 1, true == tree invalid


    int i;
    for (  i = 0; i < data_count; i++ )
    {
        if ( i + 1 < data_count && data[i] >= data[ i + 1 ] )
        {
            if ( DEBUG )
                cout << "is_valid(): data[i] > data[i+1]    \n"
                     << data[i] << "  >  " << data[i+1] <<endl;
            return false;
        }

        if ( ! is_leaf( ) )
        {
            for ( int j = 0; j < subset[i]->data_count ; j++)
            {
                if ( data[ i ] <= subset[ i ]->data[ j ] )
                {
                    if ( DEBUG )
                        cout << "is_valid(): data[i] <= subset[i]->data \n"
                             << data[i] << "  <=  " << subset[i]->data[i] <<endl;
                    return false;
                }
            }

            for ( int j = 0; j < subset[i+1]->data_count ; j++)
            {
                if ( data[ i ] > subset[ i+1 ]->data[ j ] )
                {
                    if ( DEBUG )
                        cout << "is_valid(): data[i] >= subset[i+1]->data \n"
                             << data[i] << "  >=  " << subset[i+1]->data[i] <<endl;
                    return false;
                }
            }

            if ( ! subset[ i ]->is_valid() )
                return false;
        }
    }
    if ( is_leaf() == false )
        subset[ i ]->is_valid( );

    return true;
}

// =============================================================
// insertion operator and outputs

template < typename T >
void BPlusTree<T>::print( int level , ostream& outs ) const
{
    /**
     * @brief printing a B+ tree vertically from highest value to lowest
     *  \a  for ( i = data_count ; i > 0; i-- )
     *          if current tree is not leaf go to subset[i]
     *        print each value in the tree
     *  if current tree is not leaf
     *          go to subset[i]
     */
    int i = int();
    for ( i = data_count ; i > 0; i-- )
    {
        if ( is_leaf() == false)
            subset[ i ]->print( level + 1 );

        outs << setw(4 * level) << "" << "["  << data[i-1] << "]" << endl;
    }

    if ( is_leaf() == false)
        subset[ i ]->print( level + 1 );
}

/// =============================================================
///             private Function definitions
/// =============================================================
// ==============================================================
// all purpose helper function

template < typename T >
bool BPlusTree<T>::is_leaf( ) const
{
    return ( child_count == 0 ) ;
}

// =============================================================
// Iterators search process helper

template < typename T >
const BPlusTree<T> *BPlusTree<T>::get_smallest_node() const
{
    /** \details
    * \if current node is leaf , @return 'this' pointer to node
    * \else call get_smallest_node on the first child of current node
    */
    if( is_leaf() )
        return this;
    else
        return subset[ 0 ]->get_smallest_node( );
}

// =============================================================
// accessors /modifiers helper

template < typename T >
T& BPlusTree<T>::get_existing( const T& entry )
{
    int i = first_ge ( data, data_count , entry );
    // since data is partially filled make sure that i is
    // less than data count and data at i == entry
    bool found = ( i < data_count && data[ i ] == entry);


    //if target is found and current node has no children
    if( found && is_leaf( ) )
        return data[ i ];

    //if target is found but current node has children
    else if ( found && !is_leaf( ) )
        // recursive call on root's i+1 child
        return subset[ i+1 ]->get_existing( entry );

    //if target is not found and current node has no children
    else if( !found && is_leaf ( ) ){
        assert ( found && "get_existing(): searching a nonexistant item");
        abort();
    }

    //if target is not found and current node has children
    else   /// if ( !found && !is_leaf( ) )
        // recursive call on root's i child
        return subset[ i ]->get_existing ( entry );
}


template < typename T >
const T& BPlusTree<T>::get_existing( const T& entry ) const
{
    int i = first_ge ( data, data_count , entry );
    // since data is partially filled make sure that i is
    // less than data count and data at i == entry
    bool found = ( i < data_count && data[ i ] == entry);


    //if target is found and current node has no children
    if( found && is_leaf( ) )
        return data[ i ];

    //if target is found but current node has children
    else if ( found && !is_leaf( ) )
        // recursive call on root's i+1 child
        return subset[ i+1 ]->get_existing( entry );

    //if target is not found and current node has no children
    else if( !found && is_leaf ( ) ){
        assert ( found && "get_existing(): searching a nonexistant item");
        abort();
    }

    //if target is not found and current node has children
    else   /// if ( !found && !is_leaf( ) )
        // recursive call on root's i child
        return subset[ i ]->get_existing ( entry );
}

// =============================================================
// copying process helper

template < typename T >
void BPlusTree<T>::copy_tree( const BPlusTree<T>& other,
                              BPlusTree<T>* &last_leaf )
{
    /** ********************************************************
     * \param other, the tree we are copying
     * \param last_leaf, a pointer to a tree that'll be used
     *        to connect the next pointer at leaf level
     *      \details first passes as nullptr but carries the previous leaf
     *        node from 'this' object
     *
     * copy other's total # of data and total no. of child for this tree
     * copy all of the other's data into this->data
     * if other tree has children,
     *      for i = child_count of other
     *          create a new tree at subset[i] ,
     *          call copy tree on the new tree
     *          // subset[i]->copy_tree( other.subset[i], last_leaf )
     * if other tree doesn't have children
     *       if last_leaf is not null
     *          point last_leaf's next pointer to this object
     *      point last_leaf to 'this'
     * ****************************************************** */
    dups = other.dups;
    child_count = other.child_count;
    copy_array ( data, other.data, data_count, other.data_count);
    /// copy other's data into this data, data_count updated by this function


    /// if other has children
    if( ! other.is_leaf() )
    {
        for ( int i = 0; i < other.child_count ; i++)
        {
            subset [ i ] = new BPlusTree<T>;
            // construct a new subset for each data
            subset[ i ]->copy_tree( *other.subset[i], last_leaf );
            // call copy recursively on each childrens
        }
    }

    // if other is leaf or doesn't have children,
    else
    {
        // if last_leaf is not null, point last-leaf's next to
        // the current node ( this node )
        /// \note last_leaf is null indicates that we are at the
        /// leftmost node of the tree, meaning its at this point
        /// that next pointer prepares to point at the next leaf
        if ( last_leaf != nullptr )
            last_leaf->next = this;

        // point last leaf to this node
        last_leaf = this;
    }

}

// ==============================================================
// insertion process helpers

template < typename T >
bool BPlusTree<T>::loose_insert( const T& entry )
{
    int i = first_ge ( data, data_count , entry );
    // find_ptr the first i such that data[i] >= entry
    bool found = ( i < data_count && data[ i ] == entry);

    //if entry is found && current node has no child its a duplicate
    if( found && is_leaf( ) )
    {
        if ( dups ) // if duplicates are allowed dups == true
            data[i] = data[i] + entry;

        data[ i ] = entry;
        return false;   // no duplicates
    }

    //if entry is found but current node has children
    else if ( found && ! is_leaf( ) )
    {
        // recursive call loose_insert on root's i+1 child
        subset[ i + 1]->loose_insert ( entry );

        //if the root of subset[i+1] now has an excess element fix it
        if ( subset[ i+1 ]->data_count > MAXIMUM )
            fix_excess( i+1 );

        return true;
    }

    //if entry is not found and current node has no children
    else if ( !found && is_leaf( ) )
    {
        // insert the entry at the right position
        ordered_insert ( data , data_count, entry ) ;
        return true;
    }

    //if entry is not found and current node has children
    else
    {
        // call loose insert recursively on the i-th child
        subset[ i ]->loose_insert ( entry );

        //if the root of subset[i] now has an excess element fix it
        if ( subset[ i ]->data_count > MAXIMUM )
            fix_excess( i );

        return true;
    }

}

template < typename T >
void BPlusTree<T>::fix_excess( int i )
{
    insert_item( subset, i + 1, child_count, new BPlusTree<T>);
    // insert a new empty subtree ( subset ) next to the excess node

    split( subset[ i ]->data, subset[ i ]->data_count,
           subset[ i + 1 ]->data, subset[ i + 1 ]->data_count );
    //split the excess node data and share it with the newly inserted
    // subtree

    if ( subset[ i ]->child_count > 0 )
    {
        split ( subset[ i ]->subset, subset[ i ]->child_count,
                subset[ i + 1 ]->subset, subset[ i + 1 ] ->child_count);
        //split the once excess node's suBPlusTrees ( subsets or children )
        // between itself and the the newly inserted subtree

        for ( int j = subset[ i ]->child_count ; j < MAXIMUM + 2 ; j++)
            subset[i]->subset[j] = nullptr;
    }

    T entry = T();
    detach_item (subset[ i ]->data, subset[ i ]->data_count, entry );
    // remove the last element from the once excess node's data

    // insert the removed item into the root data array
    ordered_insert ( data , data_count, entry );

    if ( subset[i]->is_leaf( ) )
    {
        // if current tree's child is leaf, then insert subset[i]'s
        // middle element as subset[i+1]'s first element
        insert_item ( subset[i+1]->data, 0, subset[i+1]->data_count, entry );

        // updating the link on leaf nodes
        subset[i+1]->next = subset[i]->next;
        subset[i]->next = subset[i+1];
    }
}

// ==============================================================
// removal process helpers

template < typename T >
bool BPlusTree<T>::loose_remove( const T& target )
{
    int i = first_ge ( data, data_count , target );
    bool found = ( i < data_count && data[ i ] == target);

    // target is found and root has no children
    if ( found && is_leaf() )
    {
        T temp = T();
        // remove target from root and return true
        delete_item ( data , i , data_count , temp );
        return true;
    }

    // target is found but root has children
    else if ( found && ! is_leaf( ) )
    {
        // recursive call on root's i+1 child
        subset[ i+1 ]->loose_remove( target );

        // if subset [i+1]'s root has less than required minimum entries
        if ( subset[ i+1 ]->data_count < MINIMUM )
        {
            BPlusTree<T>* temp = fix_shortage( i+1 );
            int index = int();

            if ( search_array( data, data_count, target, index ) )
            {
                subset[i+1]->get_smallest( data[index] );
            }
            /// sometimes there may not be a subset[i+1] but there will always
            /// be temp so use temp->data instead of subset[i+1]->data
            else if ( search_array( temp->data, temp->data_count, target, index ) )
            {
                temp->subset[index+1]->get_smallest( temp->data[index] );
            }
            else
            {
                // it's possible that data[i] will be gone by the time
                // fix_shortage returns.
            }
        }
        else
        {
            subset[i+1]->get_smallest( data[i] );
        }
        // if data was deleted but current node has minimum entries,
        // update the reference to that leaf by getting the smallest node

        return true;
    }

    // target not found and root has no children,
    else if ( ! found &&  is_leaf()  )
        // there's nothing to do
        return false;

    // target not found but root has children
    else    ///if ( ! found && ! is_leaf( ) )
    {
        // recursively call loose insert on root's i-th child
        subset[ i ] ->loose_remove ( target );

        // if subset [i]'s root has less than required minimum entries
        if ( subset[ i ] != NULL && subset[ i ]->data_count < MINIMUM )
            fix_shortage( i );

        return true;
    }

}

// subset [i] is short of the required # of entries
template < typename T >
BPlusTree<T> *BPlusTree<T>::fix_shortage( int i )
{
    /** \details
     *  \if     : subset[i+1]  has more than MINIMUM number of entries
     *              Transfer extra entry from subtree[i+1]
     *  \elseif : subset[i-1]  has more than MINIMUM number of entries
     *              Transfer an extra entry from subtree[i-1]
     *  \elseif : i-1 exists and subset[ i-1 ] has only MINIMUM elements
     *              Combine subtree[i] with subtree[i-1]
     *  \else   : subset[ i+1 ] has only MINIMUM elements
     *              Combine subtree[i]with subtree[i+1]
     */
    if (  i  < child_count - 1 && subset[ i+1 ]->data_count > MINIMUM )
    {
        rotate_left( i );
        return subset[i];
    }

    else if ( i > 0 && subset[ i - 1 ]->data_count > MINIMUM )
    {
        rotate_right( i );
        return subset[i];
    }

    else if ( i > 0 && subset[ i - 1 ]->data_count == MINIMUM )
    {
        return merge_with_next_subset( i - 1 );
    }

    else //if ( 0 < i < child_count && subset[ i+1 ]->data_count == MINIMUM )
    {
        return  merge_with_next_subset( i );
    }

}

template < typename T >
void BPlusTree<T>::get_smallest( T& entry )
{
    /**  \details
    * \if current node is leaf, entry = data' first item, @return entry by ref
    * \else call get_smallest on the first child of current node
    */
    if ( is_leaf () )
    {
        entry = data[0];
        return;
    }
    else
        subset[ 0 ]->get_smallest( entry );
}

template < typename T >
BPlusTree<T> *BPlusTree<T>::merge_with_next_subset( int i )
{
    /**  \brief
     *   1. remove data[i] from this object
     *   2. if not a leaf, append it to child[i]->data:
     *   3. Move all data items from subset[i+1]->data to
     *          the right of subset[i]->data
     *   4. Move all the children from subset[i+1]->subset
     *          to the right of subset[i]->subset
     *   5. delete subset[i+1] (store in a temp ptr)
     *   6. if a leaf, point subset[i]->next to temp_ptr->next
     *   6. delete temp ptr
     *
     */

    T temp = T();
    delete_item ( data , i, data_count , temp );
    // removes i-th item from root, and hold on to it

    if ( ! subset[i]->is_leaf( ) )
        ordered_insert ( subset[i]->data, subset[i]->data_count , temp );
    // attach removed item to the end of root's i  subset's data

    merge ( subset[ i ]->data , subset[ i ]->data_count ,
            subset[ i+1 ]->data , subset[ i+1]->data_count );
    // combine all data items subset[i+1] with subset[i]

    merge ( subset[i]->subset, subset[i]->child_count,
            subset[i+1]->subset, subset[i+1]->child_count );
    // combine all children of subset[i+1] with subset[i]


    BPlusTree<T>* hold;
    delete_item ( subset, i+1, child_count, hold );
    // delete subset[i+1],
    if ( !is_leaf() )
        subset[i]->next = hold->next;
    delete hold;

    for ( int j = child_count ; j < MAXIMUM + 2 ; j++)
        subset[j] = nullptr;

    return subset[i];
}

template < typename T >
void BPlusTree<T>::rotate_left( int i )
{
    /** \details
     * \a non leaf nodes, same as B-Tree
     *      1. Transfer data[i] down to the end of subset[i]->data
     *      2. Transfer subset[i+1]->data's first element up replace
     *          data[i]
     *      3. If subset[i+1] has children, transfer its' first child
     *          over to the end of subset[i].
     * \b leaf nodes
     *      1. transfer the first element of subset[i+1]->data down
     *          to the end of subset[i]->data
     *      2. update data[i] with subset[i+1]->data first element
     */
    if ( ! subset[i]->is_leaf( ) )
    {
        T temp = T();
        delete_item( data , i , data_count , temp );
        //remove data's i-th element, and hold it
        ordered_insert( subset[i]->data, subset[i]->data_count, temp );
        // insert removed item from data[i]->data's into subset[i]'s data

        delete_item( subset[i+1]->data, 0 , subset[i+1]->data_count, temp );
        // remove subset[i + 1]->data's first element and hold on to it
        ordered_insert ( data , data_count , temp );
        // insert the removed item from subset[i + 1]->data's into root's data

        // if subset [ i + 1 ] has children ( subsets )
        if ( ! subset[ i + 1 ]->is_leaf() )
        {
            BPlusTree<T>* bt;
            delete_item( subset[i+1]->subset, 0 ,subset[i+1]->child_count, bt );
            // remove subset[i + 1 ]'s first child, hold it

            insert_item ( subset[i]->subset, subset[i]->data_count,
                          subset[i]->child_count, bt );
            // insert subset[i+1]'s removed child as subset [i]'s last child
        }
    }

    else
    {
        T temp = T();
        delete_item( subset[i+1]->data, 0 , subset[i+1]->data_count, temp );
        // remove subset[i + 1]->data's first element and hold on to it
        ordered_insert( subset[i]->data, subset[i]->data_count, temp );
        // insert the removed item from subset[i + 1]->data's into subset[i+1] data
        data[i] = subset[i+1]->data[0];
        //replace root's i-th element with subset[i+1].data's first element
    }

}

template < typename T >
void BPlusTree<T>::rotate_right( int i )
{
    /** \details
     * \a non leaf nodes: same as B-Tree
     *      1. Transfer data[i-1] down to the front of subset[i]->data
     *      2. Transfer subset[i-1]->data's final item up to replace data[i-1]
     *      3. If subset[i-1] has children, transfer the final child of
     *          subset[i-1] over to the front of subset[i].
     * \b leaf nodes:
     *      1. transfer subset[i-1]'s final element to the front of
     *          subset[i]->data
     *      2. update data[i-1] with subset[i]->data's first element
     */

    if ( ! subset[i]->is_leaf() )
    {
        T temp = T();
        delete_item( data , i-1, data_count, temp );
        // remove data[i-1] element and hold on to it
        insert_item ( subset[i]->data, 0, subset[i]->data_count, temp);
        // insert the removed item from data's into  subset[i]->data

        detach_item ( subset[ i-1 ]->data, subset[ i-1 ]->data_count, temp );
        // remove the last ( biggest ) element from root's data, hold it
        ordered_insert ( data , data_count , temp);
        // insert the removed item from root's data into the subset[i]'s data

        // if subset [ i -1 ] has children
        if ( subset[ i - 1 ]->is_leaf()  == false)
        {
            BPlusTree<T>* bt;
            // remove subset[i -1 ]'s last child, & hold it
            detach_item( subset[i-1]->subset, subset[i-1]->child_count, bt);

            // insert removed subset[i-1]'s child as subset[i]'s first child
            insert_item ( subset[i]->subset, 0, subset[i]->child_count, bt );
        }
    }
    else
    {
        T temp = T();
        detach_item ( subset[ i-1 ]->data, subset[ i-1 ]->data_count, temp );
        // remove the last element from subset[i-1] and hold it,
        ordered_insert( subset[i]->data, subset[i]->data_count, temp );
        /// insert the removed item from subset[i-1] into subset[i]
        data[i-1] = subset[i]->data[0];
        ///replace data[i-1]'s element with subset[i].data's first element
    }

}


// =============================================================
// search process helpers

template < typename T >
T* BPlusTree<T>::find_ptr( const T& target )
{
    int i = first_ge ( data, data_count , target );
    bool found = ( i < data_count && data[ i ] == target);

    //if target is found and current node has no children
    if( found && is_leaf( ) )
        return &data [ i ];

    //if target is found but current node has children
    else if ( found && !is_leaf() )
        // recursive call on root's i+1 child
        return subset[i+1]->find_ptr( target );

    //if target is not found and current node has no children
    else if ( !found  && is_leaf( ) )
        return nullptr;

    //if target is not found and current node has children
    else /// if ( !found && !is_leaf() )
        // recursively call contain on root's i-th child
        return subset[ i ]->find_ptr( target );

}

// ===============================================================
// undetermined use so far

template < typename T >
void BPlusTree<T>::get_biggest( T& entry )
{
    /**
     * \if current tree is leaf, entry = data' last item,
     *           @return entry by ref
     * \else call get_biggest on the last child of current node
     */
    if ( is_leaf () )
    {
        entry = data[ data_count - 1 ];
        return;
    }
    else
        subset[ child_count - 1 ]->get_biggest( entry );
}


#endif // BPLUS_TREE_H
