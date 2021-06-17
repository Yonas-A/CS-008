/*
 * Author: Yonas Adamu
 * Project: multiple Sorting algorithms
 * Purpose: understanding the different types of sorting algorithms
 *          and investigate which algorithms is more efficient
 *          and quick
 */

#include <iostream>
#include "../../!includes/Sort/sort_test.h"
#include "../../!includes/Sort/bubble_sort.h"
#include "../../!includes/Sort/heap_sort.h"
#include "../../!includes/Sort/insertion_sort.h"
#include "../../!includes/Sort/merge_sort.h"
#include "../../!includes/Sort/quick_sort.h"
#include "../../!includes/Random/random.h"
#include <vector>


using namespace std;

//const int SIZE = 50000;
const int SIZE = 50;


int main()
{

    Random r ;

    int arr[ SIZE ] = {};
    create_new ( arr, SIZE );

    double time = 0;

    shuffle ( arr , SIZE );
    std::vector<int> vec;


    for ( int i = 0; i < SIZE; i++ )
    {
        vec.push_back(arr[i]);
    }

    heapSort_function( vec );


    for ( int i = 0; i < SIZE; i++ )
    {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    for ( int i = 0; i < SIZE; i++ )
    {

        cout << vec[i] << " ";
    }

//    time = test_sort( bubbleSort_function, arr, SIZE );
//    cout << "average duration - bubbleSort(50000): " << time << endl;

//    shuffle ( arr , SIZE );
//    time = test_sort( heapSort_function, arr, SIZE );
//    cout << "average duration - heapSort(50000): " << time << endl;

//    shuffle ( arr, SIZE );
//    time = test_sort(insertion_sort, arr, SIZE );
//    cout << "average duration - insertionSort(50000): " << time << endl;

//    shuffle ( arr, SIZE );
//    time = test_sort( mergeSort_function, arr, SIZE );
//    cout << "average duration - mergeSort(50000): " << time << endl;

//    shuffle ( arr, SIZE );
//    time = test_sort( quickSort_function, arr, SIZE );
//    cout << "average duration - quickSort(50000): " << time << endl;

    return 0;
}
