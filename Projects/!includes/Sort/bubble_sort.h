#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H
#include <iostream>
#include <iomanip>

using namespace std;


template <typename T>
void bubbleSort_function( T a[], unsigned int size);


//=========================================================
//=========================================================
// function definitons
//=========================================================
//=========================================================

template <typename T>
void bubbleSort_function( T a[], unsigned int size)
{
    bool swapped ;

    for( unsigned int i = 0; i < size -1; i++ )
    {
        swapped = false;
        for( unsigned int j = 0; j < size - i -1; j++ )
        {
            if( a[ j ] > a[ j+1 ] )
            {
                swap ( a[ j ], a[ j + 1 ] );
                swapped = true;
            }
        }
        if(!swapped)
           break;
    }

    return ;
}




#endif // BUBBLE_SORT_H
