#ifndef _UNION_INTERSECTION_HELPER_H_
#define _UNION_INTERSECTION_HELPER_H_

#include <iostream>

#include "../../!includes/Map/BPlus_Tree/map.h"
#include "../../!includes/Sort/heap_sort.h"

using namespace std;

// ===========================================================================
// ---------------------- ----------------------------- ----------------------
// ------------ helper functions for union with arrays N vectors -------------
// ---------------------- ----------------------------- ----------------------
// ===========================================================================

/**
 * @brief fills the map with the elements of the array
 * @param map the map that will hold the elements of the array
 * @param arr the array holding elements to fill the map with
 * @param size the number of elements in the array we want to fill the map with.
 */
template <typename T>
void fill_map(Map<T, T>& map, T* arr, int size);

/**
 * @brief fills the map with the elements of the vector
 * @param map the map that will hold the elements of the vector
 * @param vec the vector holding elements to fill the map with
 */
template <typename T>
void fill_map(Map<T, T>& map, const vector<T>& vec);

/**
 * @brief prints the array to the screen
 * @param arr the array to be printed to the screen
 */
template <typename T>
void print(T* arr, int size);

/**
 * @brief prints the vector to the screen
 * @param arr the vector to be printed to the screen
 */
template <typename T>
void print(const vector<T>& arr);


// ===========================================================================
// ---------------------- ----------------------------- ----------------------
// ------------ helper functions for union with arrays N vectors -------------
// ---------------------- ----------------------------- ----------------------
// ===========================================================================

/**
 * @brief fills the array with all the elements of the map.
 * @param map the map holding elements to fill the array with.
 * @param arr the array that will hold the elements of the map.
 * @param size the number of elements the array has been filled with.
 */
template <typename T>
void union_helper(const Map<T, T>& map, T* arr, int& size);

/**
 * @brief fills the vector with all the elements of the map.
 * @param map the map holding elements to fill the vector with.
 * @param vec the vector that will hold the elements of the map.
 */
template <typename T>
void union_helper(const Map<T, T>& map, vector<T>* vec);

// ============================================================================
// ---------------------- ----------------------------- -----------------------
// --------- helper functions for intersections with arrays N vectors ---------
// ---------------------- ----------------------------- -----------------------
// ============================================================================

/**
 * @brief fills vectors  with the intersecting elements of the map and vector vec
 * @param map a map holding some elements
 * @param vec a vector holding some elements 
 * @param s a vector that'll hold the intersecting elements of the map and vector vec
 */
template <typename T>
void intersect_helper(const Map<T, T>& map, vector<T>* vec, const vector<T>& s);

/**
 * @brief fills vectors  with the intersecting elements of the map and array arr
 * @param map a map holding some elements
 * @param size the size of the intersecting elements between map and array arr
 * @param arr an array holding some elements 
 * @param n the size of the array arr
 * @returns an array pointer to the array holding the intersecting elements
 */
template <typename T>
T* intersect_helper(const Map<T, T>& map, int& size, T* arr, int n1);


// *****************************************************************************
// *****************************************************************************
// --------------------------- function definitions ---------------------------
// *****************************************************************************
// *****************************************************************************

template <typename T>
void fill_map(Map<T, T>& map, T* arr, int size) {
    for (int i = 0; i < size; i++) {
        map[arr[i]] = arr[i];
    }
}

template <typename T>
void fill_map(Map<T, T>& map, const vector<T>& vec) {
    for (unsigned int i = 0; i < vec.size(); i++)
        map[vec[i]] = vec[i];
}

template <typename T>
void print(T* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl << endl;
}

template <typename T>
void print(const vector<T>& vec) {
    for (unsigned int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl << endl;
}


template <typename T>
void union_helper(const Map<T, T>& map, T* arr, int& size) {
    typename Map<T, T>::Iterator it = map.begin();
    size = 0;
    for (; it != map.end(); ++it) {
        arr[size] = (*it).value;
        /// get the value and insert it into the return array
        size++;
    }
}

template <typename T>
void union_helper(const Map<T, T>& map, vector<T>* vec) {
    if (map.empty()) {
        return;
    }
    typename Map<T, T>::Iterator it = map.begin();

    int i = 0;
    for (; it != map.end(); ++it) {
        vec->push_back((*it).value);
        /// get the value and insert it into the return array
        i++;
    }
}

template <typename T>
T* intersect_helper(const Map<T, T>& map, int& size, T* src, int n1) {
    T* temp = new T[map.size()];

    size = 0;
    for (int i = 0; i < n1; i++) {
        if (map.contains(src[i])) {
            temp[size] = src[i];
            size++;
        }
    }
    return temp;
}

template <typename T>
void intersect_helper(const Map<T, T>& map, vector<T>* vec, const vector<T>& s) {
    if (map.empty()) {
        return;
    }
    int index = 0;
    for (unsigned int i = 0; i < s.size(); i++) {
        if (map.contains(s[i])) {
            vec->push_back(s[i]);
            index++;
        }
    }
}

#endif  // _UNION_INTERSECTION_HELPER_H_
