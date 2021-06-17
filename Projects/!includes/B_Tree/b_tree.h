#ifndef B_TREE_H
#define B_TREE_H

#include <iostream>
#include <string.h>

#include "../../!includes/Array_Functions/array_functions.h"



using namespace std;

template < typename T >
class BTree
{

public:

    BTree( bool dups = false );

    // =============================================================
    //big three:
    BTree(const BTree<T>& other);

    ~BTree( );

    BTree<T>& operator =( const BTree<T>& RHS );
    // =============================================================

    void clear();
    //clear this object (delete all nodes etc.)

    bool contains( const T& target ) const;
    //true if entry can be found in the array

    void copy( const BTree<T>& other );
    //copy other into this object

    bool empty() const;
    // true if the tree is empty

    T* find(const T& target);
    //return a pointer to this key. NULL if not there.

    T& get( const T& entry);
    //return a reference to entry in the tree

    const T& get( const T& entry) const;
    //return a reference to entry in the tree

    void insert(const T& entry);
    //insert entry into the tree

    bool is_valid( ) const;
    // checks if this tree follows all the rules of BTree

    void print ( int level = 0, ostream& outs = cout ) const;
    //print a readable version of the tree

    void remove( const T& target );
    //remove entry from the tree

    int size( ) const;
    //count the number of elements in the tree


    friend ostream& operator << ( ostream& outs, const BTree<T>& t )
    {
        t.print(0, outs);
        return outs;
    }


private:
    static const int MINIMUM = 1;
    static const int MAXIMUM = 2 * MINIMUM;

    bool dups;                       //true if duplicate may be inserted

    T data [ MAXIMUM + 1];           //holds the keys

    BTree* subset [ MAXIMUM + 2 ];   //subtrees

    int data_count = 0;              // number of data elements

    int child_count = 0;             // number of children


    void fix_excess( int i );
    //fix excess data elements in child i

    void fix_shortage( int i );
    //fix shortage of data elements in child i

    T& get_existing( const T& target );
    // return a reference to the target if found

    bool is_leaf( ) const ;
    ///true if this is a leaf node

    bool loose_insert(const T& entry);
    //allows MAXIMUM +1 data elements in root

    bool loose_remove( const T& entry );
    //allows MINIMUM -1 data elements in the root

    void merge_with_next_subset( int i );
    //merge subset i with subset i+1

    void merge_with_previous_subset( int i );
    //merge subset i with subset i-1

    void remove_biggest(T& entry);
    // remove the biggest child of this tree->entry

    void rotate_left(int i);
    //transfer one element LEFT from child i

    void rotate_right(int i);
    //transfer one element RIGHT from child i

};


// =============================================================
//             ctor and big three
// =============================================================

template < typename T >
BTree<T>::BTree( bool d ): dups(d), data_count(0), child_count(0)
{
    const bool DEBUG = false;
    if ( DEBUG )  {
        cout << "BTree( dups) " << endl;
    }

    // not necessary but just to make it clear for debugging
    for ( int i = 0 ; i < MAXIMUM + 2; i++ )
        subset[ i ] = nullptr;

    initialize_array<T>( data, MAXIMUM + 1 );
    // not necessary since
}

template  < typename T >
BTree<T>::BTree( const BTree<T>& other )
{
    const bool DEBUG = false;
    if ( DEBUG )
        cout << "BTree (const BTree<T>& )" << endl;

    copy( other );
}

template<typename T>
BTree<T>::~BTree()
{
    const bool DEBUG = false;
    if ( DEBUG )
        cout << "~BTree ( )" << endl;

    clear();
}

template<typename T>
BTree<T>& BTree<T>::operator = ( const BTree<T>& RHS )
{
    const bool DEBUG = false;
    if ( DEBUG )
        cout << "BTree =( const BTree<T> ) " << endl;

    if ( this ==  &RHS )// check if self and RHS are the same
        return *this;

    clear();
    // clear the tree
    dups = RHS.dups;
    // copy all the necessary details from RHS to this
    copy( RHS );
    // copy the tree from RHS to this

    return *this;   // return self
}

// =============================================================
// =============================================================
//             public utility function definitions
// =============================================================
// =============================================================

template < typename T>
void BTree<T>::clear()
{
    for( int i =  0 ; i < child_count ; i++ )
    {
        // if it has subtrees recursively call clear tree on each children
        if( ! is_leaf() )
            subset[ i ]->clear();

        // delete the each subtree (subset ) and set subset to null
        delete subset[ i ];
        subset[i ] = nullptr;

    }
    //set tree's data count and child_count to 0
    child_count = 0;
    data_count = 0;

}

template < typename T>
bool BTree<T>::contains ( const T& target ) const
{
    int i = first_ge ( data, data_count , target );
    bool found = ( i < data_count && data[ i ] == target );

    //if target is found at data[i]
    if (  found )
        return true;

    //if root has no children
    else if ( is_leaf( ) )
        return false;

    else // or else recursively call contain on root's i-th child
        return subset[ i ]->contains( target );
}

template < typename T >
void BTree<T>::copy( const BTree<T>& other )
{
    assert( empty( ) && "BTree<T>::copy: 'this' is not empty");

    dups = other.dups;
    child_count = other.child_count; // copy number of child
    copy_array ( data, other.data, data_count, other.data_count);
    // copy data items in other to this object
    // this object's data count is updated in copy_array function

    // check if current tree has children and copy those children
    for ( int i = 0; i < other.child_count ; i++)
    {
        subset [ i ] = new BTree<T>;
        // construct a new subset for each data

        subset[ i ]->copy( *other.subset[i] );
        // call copy tree recursively on each childrens ( subset )
    }
}

template < typename T >
bool BTree<T>::empty( ) const
{
   return ( data_count == 0 );
}

template < typename T >
T* BTree<T>::find( const T& target )
{
    int i = first_ge ( data, data_count , target );
    bool found = ( i < data_count && data[ i ] == target);

    //if item is found return pointer to item
    if( found )
        return &data [ i ];

    // if not found and root doesn't have children return null
    else if( is_leaf ( ) )
        return nullptr;

    else // call find recursively on the tree's i-th child
        return subset[ i ]->find ( target );
}

template < typename T >
T& BTree<T>::get ( const T& entry )
{
    if ( contains( entry ) == false )   {
        insert ( entry );
    }

    return get_existing ( entry );
}

template < typename T >
const T& BTree<T>::get ( const T& entry ) const
{
    int i = first_ge ( data, data_count , entry );
    //since data is partially filled make sure that i is
    // less than data count and data at i == entry
    bool found = ( i < data_count && data[ i ] == entry);

    if( found == true )
        return data [ i ];

    else if( ! found && is_leaf ( ) )
    {
        assert ( !found && "get() const: searching a nonexistant item");
    }
    else /*if ( found != true )*/
        return subset[ i ]->get ( entry );

}

template < typename T >
void BTree<T>::insert( const T& entry )
{
    const bool DEBUG = false;
    if ( loose_insert( entry ) == false )
    {
        if( DEBUG )
            cout << entry << "  was already in the tree" << endl;
        return;
    }

    if ( data_count > MAXIMUM ) // if the root node is excess,
    {
        BTree<T>* a = new BTree<T>; // a is a pointer to a new tree
        /// create a new tree
        a->copy( *this );
        /// copy the entire tree into the new tree
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
bool BTree<T>::is_valid( ) const
{
    const bool DEBUG = false;

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
                             << data[i] << "  <=  " << subset[i]->data[i+1] <<endl;
                    return false;
                }
            }

            for ( int j = 0; j < subset[i+1]->data_count ; j++)
            {
                if ( data[ i ] >= subset[ i+1 ]->data[ j ] )
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

template < typename T >
void BTree<T>::print( int level , ostream& outs ) const
{
    int i = int();
    for ( i = data_count ; i > 0; i-- )
    {
        if ( is_leaf() == false)    {
            // if tree has children recursively call print on each children
            subset[ i ]->print( level + 1 );
        }
        // print the data to the screen
        outs << setw(4 * level) << "" << "["  << data[i-1] << "]" << endl;
    }

    if ( is_leaf() == false )
        subset[ i ]->print( level + 1 );
}

template < typename T >
void BTree<T>::remove ( const T& target )
{
   if ( loose_remove( target ) == false )   {
       return;
   }

   // if root has no elements but one child
   if ( ( data_count == 0 ) && ( child_count == 1 ) )
   {
       BTree<T>* temp = subset[0];
       // point at the child
       copy( *temp);
       //shallow copy the child to this
       temp->child_count = 0;
       // set pointers child count and data count to 0
       temp->data_count = 0;
       // delete the pointer
       delete temp;
   }

}

template < typename T >
int BTree<T>::size( ) const
{
    int count = 0;
    for ( int i = 0; i < data_count + 1 ; i++)
    {
        if ( !is_leaf( ) )   {
            count += subset[i]->size();
        }
    }
    count += data_count;
    return count;
}

// =============================================================
// =============================================================
//             private Function definitions
// =============================================================
// =============================================================

template < typename T >
void BTree<T>::fix_excess( int i )
{
    insert_item( this->subset, i + 1, this->child_count, new BTree<T>);
    // insert a new empty subtree ( subset ) next to the excess node

    split( subset[ i ]->data, subset[ i ]->data_count,
           subset[ i + 1 ]->data, subset[ i + 1 ]->data_count );
    //split the excess node data and share it with the newly inserted
    // subtree

    if ( subset[ i ] ->child_count > 0 )
    {
        split ( subset[ i ]->subset, subset[ i ]->child_count,
                subset[ i + 1 ]->subset, subset[ i + 1 ] ->child_count);
        //split the once excess node's subtrees ( subsets or children )
        // between itself and the the newly inserted subtree

        for ( int j = subset[ i ]->child_count ; j < MAXIMUM + 2 ; j++)
        {
            subset[i]->subset[j] = nullptr;
        }
    }


    T entry = T();
    detach_item (subset[ i ]->data, subset[ i ]->data_count, entry );
    // remove the last element from the once excess node's data

    // insert the removed item into the root data array
    ordered_insert ( data , data_count, entry );
}

// subset [i] is short of the required # of entries
template < typename T >
void BTree<T>::fix_shortage( int i )
{

    //Case 1: Transfer an extra entry from subtree[i-1]
    //      subset[i-1]  has more than MINIMUM number of entries
    if ( i > 0 && subset[ i - 1 ]->data_count > MINIMUM )
    {
        rotate_right( i );
    }

    //Case 2: Transfer extra entry from subtree[i+1]
    //      subset[i+1]  has more than MINIMUM number of entries
    else if (  i+1 < child_count  && subset[ i+1 ]->data_count > MINIMUM )
    {
        rotate_left( i );
    }

    //Case 3: Combine subtree[i] with subtree[i-1]
    //      i-1 exists and subset[ i-1 ] has only MINIMUM elements
    else if ( i > 0 && subset[ i - 1 ]->data_count == MINIMUM )
    {
        merge_with_next_subset(i-1);

//        merge_with_previous_subset( i );
    }

    // Case 4: Combine subtree[i]with subtree[i+1]
    //       subset[ i+1 ] has only MINIMUM elements
    else if ( i +1 < child_count && subset[ i+1 ]->data_count == MINIMUM )
    {
        merge_with_next_subset(i);
    }

}

template < typename T >
T& BTree<T>::get_existing( const T& entry )
{
    int i = first_ge ( data, data_count , entry );
    //since data is partially filled make sure that i is
    // less than data count and data at i == entry
    bool found = ( i < data_count && data[ i ] == entry);

    if( found )
        return data [ i ];

    else if( is_leaf ( ) )
    {
        assert ( found && "get_existing(): searching a nonexistant item");
        abort();
    }
    else /*if ( found != true )*/
        return subset[ i ]->get_existing ( entry );
}

template < typename T >
bool BTree<T>::is_leaf( ) const
{
    return ( child_count == 0 ) ;
}

template < typename T >
bool BTree<T>::loose_insert( const T& entry )
{
    int i = first_ge ( data, data_count , entry );
    // find the first i such that data[i] >= entry
    bool found = ( i < data_count && data[ i ] == entry);

    //if entry is found in the tree
    if( found )
    {
        if ( dups == true ) // if duplicates are allowed dups == true
        {
            data[i] = data[i] + entry;
            return true;
        }
        else {
            data[ i ] = entry;  // no duplicates
        }
        return false;
    }

    else if ( is_leaf( ) )
    {
        // if it is leaf insert the entry at the right position
        ordered_insert ( data , data_count, entry ) ;
        return true;
    }

    // if entry not found and tree has children
    else
    {
        // call loose insert recursively on the children
        subset[ i ]->loose_insert ( entry );

        //if the root of subset[i] now has an excess element fix it
        if ( subset[ i ]->data_count > MAXIMUM )
        {
            fix_excess( i );
        }
        return true;
    }

}

template < typename T >
bool BTree<T>::loose_remove( const T& target )
{
    int i = first_ge ( data, data_count , target );
    bool found = ( i < data_count && data[ i ] == target);
    // bool to indicate if item was found in the tree

    // root has no children, & target not found
    if ( is_leaf() && ! found )
    {
        return false;
    }

    // root has no children but target is found
    else if ( is_leaf() && found == true )
    {
        T temp = T();
        // remove target from root and return true
        delete_item ( data , i , data_count , temp );
        return true;
    }

    // root has children, but target not found yet
    else if ( ! is_leaf () && found == false  )
    {
        // recursively call loose insert on root's i-th child
        subset[ i ] ->loose_remove ( target );

        // if subset [i]'s root has less than required minimum entries
        if ( subset[ i ] != NULL && subset[ i ]->data_count < MINIMUM )
            fix_shortage( i );

        return true;
    }


    // root has children ( _subsets ) and target is found
    else //if ( ! is_leaf () && found == true )
    {
        subset[ i ]->remove_biggest( data [i] );
        // remove largest item in subset[i], replace data with this item

        // if subset [i]'s root has less than required minimum entries
        if ( subset[ i ]->data_count < MINIMUM )
            fix_shortage( i );

        return true;
    }

}

template < typename T >
void BTree<T>::merge_with_next_subset( int i )
{
    /*  STEPS
     * 1. Transfer data[i] down to the end of subset[i]->data.
     * 2. Transfer all items and children from subset[i + 1] to the
     *      end of subset[i]
     * 3. Delete the node subset[ i + 1; ]
     *
     */

    T temp = T();
    delete_item ( data , i, data_count , temp );
    // removes i-th item from root, and hold on to it

    ordered_insert ( subset[i]->data, subset[i]->data_count , temp );
    // attach removed item to the end of root's i  subset's data

    merge ( subset[ i ]->data , subset[ i ]->data_count ,
            subset[ i+1 ]->data , subset[ i+1]->data_count );
    // merge subset[i]'s root with subset[i+1] root at subset[i]->data

    // merge all of subset[i]'s and subset[i+1]'s children
    //  as subset[i]'s children
    merge ( subset[i]->subset, subset[i]->child_count,
            subset[i+1]->subset, subset[i+1]->child_count );

    BTree<T>* hold;
    delete_item ( subset, i+1, child_count, hold);
    delete hold;
    for ( int j = child_count ; j < MAXIMUM + 2 ; j++)    {
        subset[j] = nullptr;
    }

}

template < typename T >
void BTree<T>::merge_with_previous_subset( int i )
{
    /*  STEPS
     * 1. Transfer data[i-1]down to the end of subset[i-1]->data.
     * 2. Transfer all items and children from subset[i] to the
     *      end of subset[i-1]
     * 3. Delete the node subset[ i ]
     */

    T temp = T();
    delete_item ( data , i-1, data_count , temp );
    // removes [i] item from root, and hold on to it
    ordered_insert( subset[i-1]->data, subset[i-1]->data_count, temp);
    // attach removed item to the end of root's i - 1 subset's data

    merge ( subset[i-1]->data, subset[i-1]->data_count,
            subset[i]->data, subset[i]->data_count );
    //merge all off subset[i]'s data into subset[i-1]

    merge ( subset[i-1]->subset, subset[i-1]->child_count,
            subset[i]->subset, subset[i]->child_count );
    //merge all off subset[i]'s children into subset[i-1]

    BTree<T>* hold ;
    delete_item ( this->subset, i, child_count, hold);
    delete hold;
    for ( int j = child_count ; j < MAXIMUM + 2 ; j++)
    {
        subset[j] = nullptr;
    }
}

template < typename T >
void BTree<T>::remove_biggest( T& max_value )
{
    // if tree doesn't have children ( _subsets )
    if ( is_leaf () )
    {
        // remove the last item and return the removed item
        detach_item ( data , data_count , max_value );
        return;
    }
    else
    {
        // recursively on the last subtree of each node
        subset[ child_count - 1 ]->remove_biggest(max_value);

        // if after remove_biggest, root has one less entry than minimum
        if ( subset[ child_count - 1 ]->data_count  < MINIMUM)
        {
            fix_shortage( child_count - 1 );
        }
    }
}

template < typename T >
void BTree<T>::rotate_left( int i )
{
    /* STEPS
     * 1. Transfer data[i] down to the end of subset[i].data.
     * 2. Transfer the first element of subset[i+1].data up to
     *      replace data[i].
     * 3. If subset[i+1] has children, transfer its' first child
     *    over to the end of subset[i].
     */
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
        BTree<T>* bt;
        delete_item( subset[i+1]->subset, 0 ,subset[i+1]->child_count, bt );
        // remove subset[i + 1 ]'s first child, hold it

        // insert subset[i+1]'s removed child as the last child of subset [i]
        insert_item ( subset[i]->subset, subset[i]->data_count,
                      subset[i]->child_count, bt );
    }
}

template < typename T >
void BTree<T>::rotate_right( int i )
{
    /* STEPS
     * 1. Transfer data[i-1] down to the front of subset[i].data.
     * 2. Transfer the final element of subset[i-1].data up to
     *      replace data[i-1].
     * 3. If subset[i-1] has children, transfer the final child of
     *          subset[i-1] over to the front of subset[i].
     */

    T temp = T();
    delete_item( data , i-1, data_count, temp );
    // remove data's last element and hold on to it
    ordered_insert( subset[i]->data, subset[i]->data_count, temp );
    // insert the removed item from data's into root's data

    detach_item ( subset[ i-1 ]->data, subset[ i-1 ]->data_count, temp );
    // remove the last ( biggest ) element from root's data, hold it
    ordered_insert ( data , data_count , temp);
    // insert the removed item from root's data into the subset[i]'s data

    // if subset [ i -1 ] has children ( subsets )
    if ( subset[ i - 1 ]->is_leaf()  == false)
    {
        // remove subset[i -1 ]'s last child, & hold it
        BTree<T>* bt;
        detach_item( subset[i-1]->subset, subset[i-1]->child_count, bt);

        // insert removed subset[i-1]'s child as subset[i]'s first child
        insert_item ( subset[i]->subset, 0, subset[i]->child_count, bt );
    }
}


#endif // B_TREE_H
