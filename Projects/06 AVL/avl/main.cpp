/*
* Author: Yonas Adamu
* Project: avl / bst/ binary search tree
* Purpose: write avl class
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../../!includes/AVL/avl.h"
#include "../../!includes/AVL/avl_test.h"
#include "../avl/Interface/avl_interface.h"


int main()
{
    srand( time( nullptr ) );

    Main_menu();  /// an interactive test for avl
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//          avl class test functions
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

//    avl<int> tree;
//    test_avl_big_three();

//    test_avl_constructors();

//    test_avl_erase();

//    test_avl_insert(tree);

//    test_avl_operator_Plus_equal();

    test_avl_print_inorder();

//    test_avl_search();


    return 0;
}


