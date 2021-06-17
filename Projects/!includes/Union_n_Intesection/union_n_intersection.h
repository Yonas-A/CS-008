#ifndef UNION_AND_INTERSECTION_H
#define UNION_AND_INTERSECTION_H

#include <iostream>

#include "../../!includes/Map/BPlus_Tree/map.h"
#include "../../!includes/Sort/heap_sort.h"


using namespace  std;

// =================================================================
// unionn and intersections for arrays
// =================================================================

template  <typename T>
T* Union( T* first, int n1, T* second, int n2, int& size ) ;

template  <typename T>
T* Intersection(  T* first, int n1, T* second, int n2, int& size );

// =================================================================
// utility functions for arrays

template <typename T>
void fill_map( Map<T, T>& map, T* arr, int size) ;

template <typename T>
void union_helper( const Map<T, T>& map, T* arr, int& size );

template <typename T>
T*  intersect_helper( const Map<T, T>& map, int& size, T* arr, int n1);

template  <typename T>
void print( T* arr, int size);

// =================================================================
// unionn and intersections for vectors
// =================================================================

template <typename T>
vector<T>* Union( const vector<T>& first, const vector<T>& second );

template <typename T>
vector<T>* Intersection( const vector<T>& first, const vector<T>& second  );

// =================================================================
// utility functions for vectors

template <typename T>
void fill_map( Map<T, T>& map, const vector<T> & vec) ;

template <typename T>
void union_helper( const Map<T, T>& map, vector<T>* vec);

template <typename T>
void intersect_helper(const Map<T,T>& map,vector<T>* vec, const vector<T>&s);

template  <typename T>
void print( const vector<T>& arr);

// =================================================================

// =================================================================
// array intersection and union functions defintions

template  <typename T>
T* Union( T* first, int n1, T* second, int n2, int& size )
{
    const bool DEBUG = false;
    Map <T, T> m; // map to carry all items of first and second

    fill_map( m, first, n1 );
    ///  insert all elements of first onto the map
    fill_map( m, second, n2 );
    ///  insert all elements of second onto the map

    if ( DEBUG )
        cout << "Map: " << m << endl << endl;

    T* arr = new T [ n1 + n2 ];
    /// a new array to carry unions of two arrays
    union_helper( m, arr, size );
    /// get unions

    return arr;
}

template  <typename T>
T* Intersection(  T* first, int n1, T* second, int n2, int& size )
{
    const bool DEBUG = false;
    Map <T, T> m;
    /// array to hold intersection of first and second
    size = 0;
    if ( n1 > n2  )
    {
        fill_map( m, first, n1 );

        if ( DEBUG )
            cout << "Map: " << m << endl << endl;

        T* temp = intersect_helper( m ,size, second, n2 );
        heapSort_function( temp, size );
        return temp;
    }

    else
    {
        fill_map( m, second, n2 );
        if ( DEBUG )
            cout << "Map: " << m << endl << endl;

        T* temp = intersect_helper( m, size , first, n1 );
        heapSort_function( temp, size );
        return temp;
    }

}

// =================================================================
// vector intersection and union functions defintions

template <typename T>
vector<T>* Union( const vector<T>& first, const vector<T>& second )
{
    const bool DEBUG = false;
    Map <T, T> m;

    ///  insert all elements of first vector onto the map
    fill_map ( m, first );
    /// insert  all elements of second vector onto the map
    fill_map ( m , second);

    if ( DEBUG )
        cout << m << endl << endl;

    vector<T>* vec = new vector<T>;
    union_helper<T>( m, vec );
    return vec;

}

template <typename T>
vector<T>* Intersection( const vector<T>& first, const vector<T>& second )
{
    const bool DEBUG = false;
    Map <T,T> m;

    if ( first.size() > second.size()  )
    {
        fill_map( m, first );
        vector<T>* t = new vector<T>;

        if ( DEBUG )
            cout << m << endl << endl;
        intersect_helper( m, t, second );

        heapSort_function( t );
        return t;
    }

    else
    {
        fill_map( m, second );
        if ( DEBUG )
            cout << m << endl << endl;

        vector<T>* vec = new vector<T>;
        intersect_helper( m, vec, first );
        heapSort_function( vec );
        return vec;
    }
}

// =================================================================
// utility functions for arrays

template <typename T>
void fill_map( Map<T, T>& map, T* arr, int size)
{
    for ( int i = 0; i < size ; i++ )
    {
        map[ arr[i] ] = arr [ i ];
    }
}

template <typename T>
void union_helper( const Map<T,T>& map, T* arr, int& size )
{
    typename Map<T,T>::Iterator it = map.begin();
    size = 0;
    for (  ; it != map.end ( ); ++it )
    {
        arr[ size ] = (*it ).value;
        /// get the value and insert it into the return array
        size++;
    }
}

template <typename T>
T*  intersect_helper( const Map<T, T>& map, int& size, T* src, int n1)
{
    T* temp = new T [ map.size() ];

    size = 0;
    for ( int i = 0; i < n1; i++)
    {
        if ( map.contains( src[ i ] ) )
        {
            temp[ size ] = src[ i ];
            size++;
        }
    }
    return temp;
}

template  <typename T>
void print( T* arr, int size)
{
    for ( int i = 0; i < size; i++ )
        cout << arr[i] << "  ";

    cout << endl << endl;
}


// =================================================================
// utility functions for vectors

template <typename T>
void fill_map( Map<T, T>& map, const vector<T> & vec)
{
    for ( unsigned int i = 0; i < vec.size( ); i++ )
        map[ vec [ i ] ] = vec [i];
}

template <typename T>
void union_helper(const Map<T, T>& map, vector<T>* vec)
{
    if ( map.empty() )
        return ;
   typename Map<T, T>::Iterator it = map.begin( );

    int i = 0;
    for (  ; it != map.end ( ); ++it )
    {
        vec->push_back(  (*it ).value );
        /// get the value and insert it into the return array
        i++;
    }
}

template <typename T>
void intersect_helper(const Map<T,T>& map,vector<T>* vec, const vector<T>&s)
{
    if ( map.empty() )
        return ;
    int index = 0;
    for ( unsigned int i = 0; i < s.size( ); i++ )
    {
        if ( map.contains(  s[ i ]  ) )
        {
            vec->push_back( s [i ] );
            index++;
        }
    }
}

template  <typename T>
void print( const vector<T>& vec)
{
    ////for ( unsigned int i = 0; i < vec->size( ); i++ )
    ////cout << vec->at( i ) << " " ;

    for ( unsigned int i = 0; i < vec.size( ); i++ )
        cout << vec[i] << " " ;
    cout << endl << endl;
}




#endif // UNION_AND_INTERSECTION_H
