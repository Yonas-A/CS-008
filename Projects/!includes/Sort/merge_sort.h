#ifndef MERGE_SORT_H
#define MERGE_SORT_H
#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
void merge(T arr[], unsigned int start, unsigned int mid, unsigned int end);

template <typename T>
void merge_sort(T arr[], unsigned int start, unsigned int end) ;

template <typename T>
void mergeSort_function(T a[], unsigned int size);

//=========================================================
//=========================================================
// function definitons
//=========================================================
//=========================================================

template <typename T>
void merge(T arr[], unsigned int start, unsigned int mid, unsigned int end)
{
    T temp[ end - start + 1 ];
    // a temp array to store sorted items

    unsigned int i = start, j = mid + 1, k = 0;
    // crawlers for both intervals and for temp

    // traverse both arrays and add smaller of both elements in temp
    while( i <= mid && j <= end )
    {
        if( arr[i] <= arr[j] )
        {
            temp[k] = arr[i];
            k++; i++;
        }

        else
        {
            temp[k] = arr[j];
            k++; j++;
        }
    }

    // add elements left in the first interval
    while( i <= mid )
    {
        temp[k] = arr[i];
        k++; i++;
    }

    // add elements left in the second interval
    while( j <= end )
    {
        temp[k] = arr[j];
        k++; j++;
    }

    // copy temp to original interval
    for( i = start; i <= end; i++ )
    {
        arr[i] = temp[ i - start ];
    }

}

template <typename T>
void merge_sort(T arr[], unsigned int start, unsigned int end)
{
    if( start < end )
    {
        int mid = ( start + end) / 2;
        merge_sort( arr, start, mid );
        merge_sort( arr, mid + 1, end );
        merge( arr, start, mid, end );
    }
}


template <typename T>
void mergeSort_function(T a[], unsigned int size)
{
    merge_sort( a, 0, size - 1 );
    //must have size -1 for this specific implementation
    //of merge_sort and merge functions
}

#endif // MERGE_SORT_H
