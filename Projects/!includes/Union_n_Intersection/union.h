#ifndef _UNION_H_
#define _UNION_H_

#include <iostream>

#include "../../!includes/Map/BPlus_Tree/map.h"
#include "../../!includes/Sort/heap_sort.h"
#include "./union_intersection_helper.h"

using namespace std;

/**
 * @brief a union function that uses maps to find unions between two arrays or 
 * two vectors
 */ 

/**
 * @brief finds the union of two arrays 
 * @return an array pointer containing the union of two arrays
 * @param first the first array containing some elements
 * @param n1 the number of elements in the first array we want to find the union of
 * @param second the second array containing some elements
 * @param n2 the number of elements in the second array we want to find the union of
 */
template <typename T>
T* Union(T* first, int n1, T* second, int n2, int& size);

/**
 * @brief finds the union of two vectors 
 * @return a vector containing the union of two vectors
 * @param first the first vector for union
 * @param second the second vector for union
 */
template <typename T>
vector<T>* Union(const vector<T>& first, const vector<T>& second);


// *****************************************************************************
// ------------------------ union functions defintions ------------------------
// *****************************************************************************

template <typename T>
T* Union(T* first, int n1, T* second, int n2, int& size) {
    const bool DEBUG = false;
    Map<T, T> *m;  // map to carry all items of first and second

    fill_map(m, first, n1);
    fill_map(m, second, n2);
    //  insert all elements of first and second onto the map

    if (DEBUG) {
        cout << "Map: " << m << endl
             << endl;
    }

    T* arr = new T[n1 + n2];  // new array to hold the union of the two arrays
    union_helper(m, arr, size);

    return arr;
}

template <typename T>
vector<T>* Union(const vector<T>& first, const vector<T>& second) {
    const bool DEBUG = false;
    Map<T, T> m;

    fill_map(m, first);
    fill_map(m, second);  //  insert all elements of first and second onto the map

    if (DEBUG) {
        cout << m << endl << endl;
    }

    vector<T>* vec = new vector<T>;
    union_helper<T>(m, vec);
    return vec;
}

#endif  // _UNION_H_
