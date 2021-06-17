#ifndef _INTERSECTION_H_
#define _INTERSECTION_H_

#include <iostream>

#include "../../!includes/Map/BPlus_Tree/map.h"
#include "../../!includes/Sort/heap_sort.h"
#include "./union_intersection_helper.h"

using namespace std;

/**
 * @brief an intersection function that uses maps to find intersection between
 *  two arrays or two vectors
 */ 

/**
 * @brief finds the intersection of two arrays 
 * @return an array pointer containing the intersection of two arrays
 * @param first the first array containing some elements
 * @param n1 the number of elements in the first array 
 * @param second the second array containing some elements
 * @param n2 the number of elements in the second array
 */
template <typename T>
T* Intersection(T* first, int n1, T* second, int n2, int& size);

/**
 * @brief finds the intersection of two vectors 
 * @return a vector pointer containing the intersection of two vectors
 * @param first the first vector containing some elements
 * @param second the second vector containing some elements
 */
template <typename T>
vector<T>* Intersection(const vector<T>& first, const vector<T>& second);

// *****************************************************************************
// --------------------- Intersection functions defintions ---------------------
// *****************************************************************************

template <typename T>
T* Intersection(T* first, int n1, T* second, int n2, int& size) {
    const bool DEBUG = false;
    Map<T, T> map; // map to hold intersection of first and second
    size = 0;
    if (n1 > n2) {
        fill_map(map, first, n1);
        if (DEBUG) {
            cout << "Map: " << map << endl << endl;           
        }

        T* temp = intersect_helper(map, size, second, n2);
        heapSort_function(temp, size);
        return temp;
    }

    else {
        fill_map(map, second, n2);
        if (DEBUG) {
            cout << "Map: " << map << endl << endl;           
        }

        T* temp = intersect_helper(map, size, first, n1);
        heapSort_function(temp, size);
        return temp;
    }
}

template <typename T>
vector<T>* Intersection(const vector<T>& first, const vector<T>& second) {
    const bool DEBUG = false;
    Map<T, T> map; // map to hold intersection of first and second

    if (first.size() > second.size()) {
        fill_map(map, first);  // fill map with the biggest sized array
        if (DEBUG) {
            cout << "Map: " << map << endl << endl;           
        }
        vector<T>* vec = new vector<T>;
        intersect_helper(map, vec, second);
        heapSort_function(vec);
        return vec;
    } else {
        fill_map(map, second);
        if (DEBUG) {
            cout << "Map: " << map << endl << endl;           
        }
        vector<T>* vec = new vector<T>;
        intersect_helper(map, vec, first);
        heapSort_function(vec);
        return vec;
    }
}

#endif  // _INTERSECTION_H_
