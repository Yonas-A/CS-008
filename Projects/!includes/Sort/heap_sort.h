#ifndef HEAP_SORT_H
#define HEAP_SORT_H
#include <iostream>
#include <iomanip>
#include "../../!includes/Heap/heap.h"

using namespace  std;


template <typename T>
void heapSort_function(T a[], unsigned int size);

template  <typename T>
void heapSort_function( vector<T>* v );

//=========================================================
//=========================================================
//                  function definitons
//=========================================================
//=========================================================

template <typename T>
void heapSort_function( T a[], unsigned int size)
{
    Heap<T> sort;   // Heap class

    for ( unsigned int index = 0; index < size; index++)
    {
        T temp = a[ index ];
        sort.insert(temp);
    }

    // One by one extract an element from heap
    for ( unsigned int index = 0 ; index < size; index++ )
    {
        a[ size - 1 - index ] = sort.Pop();
        // pop the highest item from heap and insert item in array
        // starting at the end of array
    }

}


template <typename T>
void heapSort_function( vector<T>* vec )
{
    unsigned int size = vec->size( );
    Heap<T> sort;   // Heap class

    for ( unsigned int index = 0; index < size; index++)
    {
        T temp = vec->at( index );
        sort.insert(temp);
    }

    // One by one extract an element from heap
    for ( unsigned int index = 0 ; index < size; index++ )
    {
        vec->at( size - 1 - index ) = sort.Pop();
//        vec[ size - 1 - index ] = sort.Pop();
        /// pop the highest item from heap and insert item in array
        /// starting at the end of array
    }


}



#endif // HEAP_SORT_H
