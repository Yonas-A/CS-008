#ifndef SORT_TEST_H
#define SORT_TEST_H
#include <iostream>
#include <string.h>
#include <iomanip>
#include "../../!includes/Random/random.h"
#include "../../!includes/Timer/timer.h"

using namespace  std;


template <typename T>
void copy_array(T dest[], const T src[], unsigned int size);

template <typename T>
void create_new( T a[], unsigned int size);

template <typename T>
void print_array(const T a[], unsigned int size, bool status_only = false);
//print array if status_only is true along with info on sortedness of a[]

template <typename T>
void print_array_segment(T a[], unsigned int start, unsigned int end);
//print a[] from start to end

template <typename T>
void shuffle (T a[] , unsigned int size );
// shuffle elements of the array

template <typename T>
double test_sort( void(*f)(T*, unsigned int), T* a, unsigned int size );
// the test function which activates sorting functions and  controls
// the time duration for 500 runs

template <class T>
float time_sort_routine( void (*f)( T *, unsigned int),
                         T a[], unsigned int  size );

template <typename T>
bool verify(const T a[], unsigned int  size);
//return true if a[] is in ascending order

template <typename T>
string verifystr(const T a[], unsigned int  size);
//return a string "SORTED" or "NOT SORTED" depending if a[] is sorted



//=========================================================
//=========================================================
//                  function definitons
//=========================================================
//=========================================================

template <typename T>
void copy_array(T dest[], const T src[], unsigned int size)
{
    for ( unsigned int index = 0; index < size ; ++index)
    {
        dest[ index ] = src [ index ];
    }
}

template <typename T>
void create_new( T arr[], unsigned int size )
{
    Random r;
    for( unsigned int i = 0; i < size; i++)
    {
        arr[i] = r.Next( 0, size );
    }
}

template <typename T>
void shuffle (T a[] , unsigned int size )
{
    unsigned int low = 0;
    Random r;
    for( unsigned int i = 0; i < size; i++)
    {
        swap( a[i],  a[ r.Next( low, size - 1) ]);
    }
}


template <typename T>
void print_array(const T a[], unsigned int size, bool status_only)
{
    if( status_only )
    {
        assert( verify( a, size ) && "print_array verification failed" );
        cout << "SORTED VERIFIED" << endl;
        for ( unsigned int i = 0; i < size; ++i)
        {
            cout << a[i] << ", " ;
        }
        cout << endl;
    }
}

template <class T>
void print_array_segment(T a[], unsigned int start, unsigned int end)
{
    for (unsigned int i = start; i < end; ++i)
    {
        cout << a[i] << " | " ;
    }
    cout << endl;
}

template <typename T>
double test_sort(void(*f)(T*, unsigned int), T* a, unsigned int size)
{
    float total_time = 0;
    unsigned int index;
    for ( index  = 0 ; index < 500 ; index ++)
    {
        total_time += time_sort_routine( *f, a, size ); //time

        f(a, size);
        // calling the function passed i.e. the sorting functions.

        assert( verify( a, size ) && "print_array verification failed" );

        create_new(a, size);
        // load new items into the array for the next iteration
    }

    return ( double) total_time / index; // average time
}


template <class T>
float time_sort_routine( void (*f)(T *, unsigned int) ,
                        T a[], unsigned int  size )
{
    Timer t;
    t.start();
    f(a, size); // sorting function
    t.stop();
    return t.duration();
}


template <class T>
bool verify(const T a[], unsigned int  size)
{
    for ( unsigned int i = 0; i < size -1; i++)
    {
        if(a[i] > a[i + 1])
            return false;
    }
    return true;
}

template <typename T>
string verifystr(const T a[], unsigned int  size)
{
    bool verified = verify ( a, size);

    if( verified )
        return "SORTED";

    return "NOT SORTED" ;

}

#endif // SORT_TEST_H
