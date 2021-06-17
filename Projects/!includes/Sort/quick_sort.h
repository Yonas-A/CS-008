#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
unsigned int partition(T a[], unsigned int start, unsigned int end);

template <typename T>
void quick_sort(T arr[],  int start, int end) ;

template <typename T>
void quickSort_function(T a[], unsigned int size);

template <typename T>
void swap_values(T& lhs, T& rhs);

//=========================================================
//=========================================================
//                  function definitons
//=========================================================
//=========================================================


template <typename T>
unsigned int partition(T arr[], unsigned int start, unsigned int end)
{
    unsigned int start_index = start + 1;
    T pivot = arr[start] ;     /// first element as pivot

    /// start the the next element from the pivot
    for( unsigned int i = start + 1; i <= end ; i++ )
    {
        // if current element is less than pivot,
        if ( arr[ i ] < pivot )
        {
            swap_values (arr [ start_index ], arr [ i ]);
            start_index++;
        }
    }

   swap_values ( arr[ start ] ,arr[ start_index - 1 ] ) ;
   ///place pivot in a sorted manner

   return start_index - 1;
   /// return the pivot position
}

template <typename T>
void quick_sort(T arr[], int start, int end)
{
    if( start < end )
    {
        unsigned int pivot = partition ( arr, start, end );
        quick_sort( arr, start , pivot - 1 );
        quick_sort( arr, pivot + 1, end);
    }
}

template <typename T>
void quickSort_function(T a[], unsigned int size)
{
    quick_sort( a, 0, size - 1 );
    // need size - 1 for this specific implementation
    // of quick_sort to work
}

template <typename T>
void swap_values(T& lhs, T& rhs)
{
    T temp = lhs;
    lhs = rhs;
    rhs = temp;
}

#endif // QUICK_SORT_H
