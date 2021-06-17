# pragma once

#ifndef ARRAY_FUNCTIONS_H
#define ARRAY_FUNCTIONS_H

#include <iomanip>
#include <iostream>
#include <vector>

#include <math.h>
#include <stdlib.h>



using namespace std;

/**
 * @brief attach_item attaches entry at the end of the array
 * @param data the array being used
 * @param n size of the array @code data
 * @param entry the item being appended
 */
template <typename T>
void attach_item( T data[ ], int& n, const T& entry );

/**
 * @brief  copy_array copy elements in @code src starting from the first
 *          element thru element at @code src_size onto the @code dest
 * @tparam dest the destination array data will be copied onto
 * @tparam src the source array holding the data
 * @param  dest_size the size of the @code dest array
 * @param  src_size the size of the @code data array
 */
template <typename T>
void copy_array( T dest[], const T src[], int& dest_size, int src_size );

/**
 * @brief  delete_item removes item at index @code i from the array,
 *         sets @code entry to the value of the deleted item and adjusts
 *         size of the array
 * @tparam data the array used
 * @param  i the index in the array from where an item will be deleted
 * @param  n size of the array
 * @tparam entry the item in the array that was deleted
 */
template <typename T>
void delete_item( T data[ ], int i, int& n, T& entry ) ;


/**
 * @brief  detach_item  removes the last element from the array,
 *         sets @code entry to the value of the removed item and
 *         adjusts size of the array
 * @tparam data the array used
 * @param  n size of the array
 * @tparam entry the item in the array that was deleted
 */
template <typename T>
void detach_item( T data[ ], int& n, T& entry );

/**
 * @brief  first_ge returns the index of the first element in @code data
 *         that's not  less than @code entry
 * @param  data the array
 * @param  n size of the array
 * @param  entry the item we are comparing the rest of the array with
 * @return the index of the first element in the array that's not
 *         less than entry
 */
template <typename T>
int first_ge( const T data[ ], int n, const T& entry );

/**
 * @brief  index_of_maximal finds the minimum element in @code data
 *         and returns its index
 * @tparam data the array
 * @param  n the size of the array
 * @return index of the minimum element in the array data
 */
template <typename T>
int index_of_maximal( T data[ ], int n );

/**
 * @brief  initialize_array sets the array @code data to the default
 *         value of T
 * @tparam data the array being initialized
 * @param  n size of the array
*/
template <typename T>
void initialize_array( T data[ ], int n );

/**
 * @brief  insert_item inserts @code entry in the array at index @code i
 * @tparam data the array used
 * @param  i the index in @code data where entry will be inserted
 * @param  n size of the array
 * @tparam entry the item to be inserted
 */
template <typename T>
void insert_item( T data[ ], int i, int& n, T entry );

/**
 * @brief  is_gt compares the value of @code item with all the elements
 *         of @code data
 * @tparam data the array used
 * @param  n size of the array
 * @param  item item being compared
 * @return true if the value of @code item is greater than all the elements
 *         of @code data: otherwise false
 */
template <typename T>
bool is_gt( const T data[], int n, const T& item ) ;

/**
 * @brief  is_le compares the value of @code item with all the elements
 *         of @code data
 * @tparam data the array used
 * @param  n size of the array
 * @param  item item being compared
 * @return true if the value of @code item is less than or equal to all
 *         the elements of @code data: otherwise false
 */
template <typename T>
bool is_le( const T data[], int n, const T& item );

/**
 * @brief maximal compares @code a and @code b
 * @param a the first item being compared
 * @param b the second item being compared
 * @return the larger of the two items
 */
template <typename T>
T maximal( const T& a, const T& b );

/**
 * @brief  merge attaches the values of @code data2 starting from it's first
 *         element to element at n2 to the end of @code data1
 * @tparam data1 the destination array item will be merged to
 * @param  n1 size of @code data1
 * @tparam data2 the array from which items will be merged onto @code data1
 * @param  n2 size of @code data2
 */
template <typename T>
void merge( T data1[ ], int& n1, T data2[ ], int& n2 );

/**
 * @brief  ordered_insert inserts @code entry in the correct order to
 *         @code data
 * @tparam data the array @entry will be inserted into
 * @param  n size of array @code data
 * @tparam entry the item being inserted
 */
template <typename T>
void ordered_insert( T data[ ], int& n, const T& entry );

/**
 * @brief  print_array prints the value of @code onto the console
 * @tparam data array being used
 * @param  n size of array @code data
 * @param  pos
 */
template <typename T>
void print_array( const T data[], int n, int pos = -1 );

/**
 * @brief  search_array searchs @code data for @code target and sets
 *         @code index to the index where target was found
 * @tparam data array target will be searched  used
 * @param  nsize of the array @code data
 * @tparam target item being searched for inside @code data
 * @param  index location of target inside @code data
 * @return true if target was found inside @code data: otherwise false
 */
template <typename T >
bool search_array( const T data[], int n, const T& target, int& index );

/**
 * @brief  split splits the array @code data1 into half, copies the second
 *         half onto the array  @code data2 and adjusts the size of both
 *         @code data1 and @code data2
 * @tparam data1 the array being split
 * @param  n1 size of the array @code data1
 * @tparam data2 the array wihich holds the split half from @code data1
 * @param  n2 size of the array @code data2
 */
template <typename T>
void split( T data1[ ], int& n1, T data2[ ], int& n2 ) ;

/**
 * @brief  swap_values swaps the values of @code a with @code b
 * @tparam a item being swapped
 * @tparam b item being swapped
 */
template <typename T>
void swap_values( T& a, T& b );


//-------------- Vector Extra operators: ---------------------

/**
 * @brief operator << prints the vector @code list onto console
 * @param outs an ostream object
 * @param list a vector holding items
 * @return an ostream object outs
 */
template <typename T>
ostream& operator << ( ostream& outs, const vector<T>& list );

/**
 * @brief operator += adds a single element onto the vector @code list
 * @tparam list a vector object @code addme is being added to
 * @tparam addme a single item that's being added
 * @return vector @code list with item @code addme as its last element
 */
template <typename T>
vector<T>& operator += ( vector<T>& list, const T& addme ) ;

/**
 * @brief  operator += adds the vector @code rhs onto @code list
 * @tparam list the vector which another vector is being added onto
 * @tparam rhs the vector whose elements are being added onto a different
 *        vector object
 * @return @code list that contains all the elements of @code rhs
 */
template <typename T>
vector<T>& operator +=( vector<T>& list, const vector<T>& rhs );

/**
 * @brief  operator += adds the vector @code rhs onto @code list
 * @tparam lhs first vector object that will be added to a new vector object
 * @tparam rhs second vector object that will be added to a new vector object
 * @return a @new vector object which will contain all elements of @code
 *         lhs and @code rhs
 */
template <typename T>
vector<T>& operator +( const vector<T>& lhs, const vector<T>& rhs );

// =============================================================
// =============================================================
//              Function definitions
// =============================================================
// =============================================================

template <typename T>
void attach_item( T data[ ], int& n, const T& entry )
{
    // the array must have large enough capacity
    // to hold entry to the right of data
    data[ n ] = entry; //attach entry at the nth index
    n++;    // increase data count ( n ) by one
}

template <typename T>
void copy_array( T dest[], const T src[], int& dest_size, int src_size )
{
    // the destination must have large enough capacity
    // to hold src_size elements from the src array

    dest_size = src_size;
    // destination size = source size
    for ( int i = 0; i < dest_size ; i++ )
    {
        dest[ i ] = src [ i ];
        // copy each item in the src at an index to dest
    }
}

template <typename T>
void delete_item( T data[ ], int i, int& n,  T& entry )
{
    assert ( i < n && "delete_item(): index must be less than size" );
    entry = data [ i ] ;        // entry equals item at index i

    n--;    // reduce size by 1;
    for ( int j = i ; j < n ; j++ )
    {
        // shift all elements starting at i one place to the left
        data [ j ] = data [ j + 1 ];
    }

}

template <typename T>
void detach_item( T data[ ], int& n, T& entry )
{
    assert ( n > 0 && "detach_item (): array must have size > 0" );
    n--;    // reduce size of data i.e. n  by one
    entry = data[ n ] ; // entry becomes the last item of data
}

template < typename T >
int first_ge( const T data[ ], int n, const T& entry )
{
    // asserting for the size of the array to be at least equal to 0
    assert ( n >= 0 && "first_ge(): array size can't be negative");

    for ( int i = 0; i < n ; i++ )
    {
        // if entry less or equal to an element at index i
        // return the index
        if ( entry <=  data[ i ] )
            return i;
    }
    // entry is greater than all elements, so return size
    return n;
}

template <typename T>
int index_of_maximal( T data[ ], int n )
{
    assert ( n > 0 && "index of maxima: size of array must be  > 0" );

   T temp = data [ 0 ]; // holds the maximum element from data
   int index = 0;       // holds index for the maximal element

   for ( int i = 1 ; i < n ; i++ )
   {
       // if array elements are greater than current max value
       if ( data [ i ] > temp )
       {
           temp = data [ i ] ;
           /// change current max value to array element at i
           index = i;
           /// change the max index to i
       }
   }
   return index;
}

template <typename T>
void initialize_array( T data[ ], int n )
{
    for ( int i = 0;i < n ; i++)
    {
        data[ i ] = T();
    }
}

template <typename T>
void insert_item( T data[ ], int i, int& n, T entry )
{
    const bool DEBUG = false;
    if ( DEBUG )
    {
        cout << "i " << i << "  size " << n << endl;
    }

    assert ( i <= n && "delete_item(): index must be less than size" );

    for ( int index = n; index > i ; index--)
    {
        // shift all elements starting at i one place to the right
        data [ index ] = data [ index - 1 ];
        if ( DEBUG )
        {
            cout << " index " << index << " i " << i << endl;
        }
    }
    data[ i  ] = entry;  // insert item at i
    n++;                 // increase the size by 1

    if ( DEBUG )    {
        cout << "   i " << i << "  size " << n << endl;
    }
}

template <typename T>
bool is_gt( const T data[], int n, const T& item )
{
    assert( n > 0 && "is_le(): size must be > 0 " );

    for ( int i = 0 ; i < n ; i++ )
    {
        //if item is less or equal to any of array elements return false,
        if ( item <= data [i ] )
            return false;
    }
    //item is greater than all array elements, so return true
    return true;
}

template < typename T >
bool is_le( const T data[] , int n , const T& item)
{
    assert( n > 0 && "is_le(): size must be > 0 " );

    for ( int i = 0 ; i < n ; i++ )
    {
        // if item is greater than any of array elements return false,
        if ( item > data [i ] )
            return false;
    }
    //item is less or equal to all array elements, so return true
    return true;
}

template <typename T>
T maximal( const T& a, const T& b )
{
    // return the maximum of the two using max from math.h
    return ( max ( a, b ) );
}

template <typename T>
void merge( T data1[ ], int& n1, T data2[ ], int& n2 )
{

    int j = 0;  //index for data2;
    for ( int i = n1; i < n1 + n2; i++ )
    {
        data1 [ i ] = data2 [ j ];
        // append all of  data2 elements at the back of data1 s
        j++; // increment index for data2
    }
    n1 += j;
    n2 = 0;
}

template <typename T>
void ordered_insert( T data[ ], int& n, const T& entry )
{
    int i;
    for ( i = n - 1; ( i >= 0 && data[ i ] > entry ); i-- )
    {
        data[i + 1] = data[i];
    }

    data[i + 1] = entry;
    n++;
}

template <typename T>
void print_array( const T data[], int n, int pos )
{
    for ( int i = 0; i < n ; i++ )
    {
        if ( i > 0 && ( i % 20 ) == 0 )
            cout << endl;
        cout << left << setw ( 4 ) <<  data [ i ];
    }
    cout << "\t[" << n << "]" << endl;
    for ( int i = 0; i < n +1 ; i++ )
    {
        if( i == pos )
            cout << "^";
        cout << left << setw ( 4 ) << "  ";
    }
    cout << endl;
}

template < typename T >

bool search_array( const T data[], int n, const T& target, int& index )
{
    for ( int i = 0; i < n; i++ )
    {
        if( data[ i ] == target )
        {
            index = i;
            return true;
        }
    }
    return false;
}

template <typename T>
void split( T data1[ ], int& n1, T data2[ ], int& n2 )
{
   assert ( n1 >= 0 && "split(): n1 > 0 ");

   int half =  n1 / 2  ;

   int j  = 0;  //index for data2
   for ( int i = n1 - half ; i < n1 ; i++ )
   {
        data2 [ j ] = data1 [ i ] ;
        //copy items in data1 into data2 starting from (n1 - half )th index
        j++;
   }

   n2 = j;  // index for data2 i.e. becomes size of data2;
   n1 -= half; // reduce the size of data1 by half its original size

}

template < typename T >
void swap_values (T& a, T& b)
{
    T temp = a;
    a = b ;
    b = a;
}
// ============================================================
// ============================================================
// =================  Vector Extra operators  =================
// ============================================================
// ============================================================

/// insertion operator
template <typename T>
ostream& operator << ( ostream& outs, const vector<T>& list )
{
    for ( size_t i= 0; i< list.size(); i++)
    {
       outs << left << std::setw( 15 ) << list[i] ;
//       outs << list[i] << "  " ;
    }
    return outs;
}

/// overloaded plus equal operator to add a single item on a vecto
template <typename T>
vector<T>& operator += ( vector<T>& list, const T& addme )
{
    const bool DEBUG = false;
    if ( DEBUG )    {
        cout << "operator += ( vector<T>& , const T& )" << endl;
    }

    list.push_back( addme );
    return list;
}

/// overloaded plus equal operator to add a vector to the exisitng vector
template <typename T>
vector<T>& operator += ( vector<T>& list, const vector<T>& rhs )
{
    if ( const bool DEBUG = false )
        cout << "operator += ( vector<T>& , const vector<T>& )" << endl;

    for ( size_t i = 0; i < rhs.size(); i++ )   {
        list.push_back(rhs[i] );
    }
    return list;
}

// overloaded plus operator to add two vectors and return new vector
template <typename T>
vector<T>& operator +( const vector<T>& lhs, const vector<T>& rhs )
{
    if ( const bool DEBUG = false )
        cout << "operator + ( const vector , const vector )" << endl;

    vector<T>* list = new vector<T>;

    for ( size_t i = 0; i < lhs.size(); i++ )
        list->push_back( lhs[i] );    /// copy the lhs vector first
    for ( size_t i = 0; i < rhs.size(); i++ )
        list->push_back( rhs[i] );   /// attach the rhs vector at the end of list

    return *list;
}


#endif // ARRAY_FUNCTIONS_H
