/*
 * Author: Yonas Adamu
 * Project: Heap
 * Purpose: write a tree based data structure (Heap) where
 *          no entry is bigger than its parents
 */

#include <stdlib.h>
#include <time.h>

#include <iostream>

#include "../../!includes/Heap/heap.h"
#include "../../!includes/Heap/heap_test.h"
#include "./heap_interface.h"

using namespace std;

int main() {
    srand(time(nullptr));

    //an interactive interface to test heap class
    ///==============================================================

    Main_menu();

    ///==============================================================

    //    test_big_three();

    //    test_capacity();

    //    test_copy();

    //    Heap<int> tree;
    //    test_insert(tree);

    //    test_is_empty();

    //    test_Pop();

    //    test_size();

    return 0;
}
