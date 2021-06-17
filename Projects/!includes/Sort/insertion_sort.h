#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H
#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
void insertion_sort( T a[] , unsigned int size );

//=========================================================
//=========================================================
// function definitons
//=========================================================
//=========================================================

template <typename T>
void insertion_sort( T a[] , unsigned int size )
{
    for( unsigned int  i = 1; i < size  ; i++)
    {
        T key = a[ i ];
        int next = i - 1;

        while ( next >= 0 && a[next] > key )
        {
            a[ next + 1 ] = a[ next ];
            next = next - 1;
        }
        a[next + 1] = key;
    }

}

#endif // INSERTION_SORT_H
