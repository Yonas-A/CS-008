#ifndef AVL_TEST_H
#define AVL_TEST_H
#include <iostream>

#include "../../!includes/AVL/avl.h"
#include "../../!includes/Binary_Search_Tree/binary_search_tree.h"

using namespace std;

void test_avl_big_three();
// test for avl constructors and destructors (big three)

void test_avl_constructors();
// test for avl default constructor and avl(sorted_list, size)

void test_avl_erase();
// a test for avl's erase function

void test_avl_insert(avl<int> &test);
// a test for avl's insert function

void test_avl_operator_Plus_equal();
// a test for avl's += operator

void test_avl_print_inorder();
// a test for avl's print_inorder() test

void test_avl_search();
// a test for avl's search function

//==============================================================
//  functions definitions
//==============================================================

void test_avl_big_three() {
    cout << "\n= = = = big three functions test = = = = =\n\n";

    avl<int> tree;
    test_avl_insert(tree);
    cout << "\n= = = = assignment operator test = = = = =\n"
         << endl;
    avl<int> temp1 = tree;

    cout << "tree: " << tree << endl;
    cout << "temp1: " << temp1 << endl;

    cout << "\n= = = = copy constructor  test = = = = =\n"
         << endl;
    avl<int> temp2(tree);

    cout << "tree: " << tree << endl;
    cout << "temp2: " << temp2 << endl;

    cout << "\n= = = = exiting big three functions test = = = =\n\n";
}

void test_avl_constructors() {
    cout << "\n= = = = = avl CTOR's  test = = = = =\n\n";

    int arr[] = {30, 31, 32, 33, 34, 35, 36, 37, 38, 39};
    int size = sizeof(arr) / sizeof(arr[0]);

    avl<int> tree(arr, size);

    cout << "Tree from avl( T* sorted_list , int size)"
         << endl
         << endl
         << tree << endl
         << endl;

    avl<int> second_Tree;
    cout << "Tree from avl( ) " << endl
         << endl;
    test_avl_insert(second_Tree);

    cout << "\n= = = = = exiting avl CTOR's  test = = = = =\n\n";
}

void test_avl_erase() {
    cout << "\n= = = =  avl erase(target) test = = = = =\n\n";
    avl<int> tree;
    test_avl_insert(tree);

    int target = 74;
    tree.erase(target);
    cout << "- - - Tree after erase(" << target << ") - -  - \n\n";
    cout << tree << endl;

    cout << "\n= = = = exiting avl erase(target) test = = = = =\n\n";
}

void test_avl_insert(avl<int> &tree) {
    const bool DEBUG = false;
    tree.insert(10);
    tree.insert(40);
    tree.insert(24);

    if (DEBUG)
        cout << "-  -   - tree    -   -   -"
             << endl
             << endl
             << tree << endl;

    tree.insert(50);
    tree.insert(13);

    if (DEBUG)
        cout << "-  -   - tree    -   -   -"
             << endl
             << endl
             << tree << endl;

    tree.insert(35);
    tree.insert(74);

    if (DEBUG)
        cout << "-  -   - tree    -   -   -"
             << endl
             << endl
             << tree << endl;

    tree.insert(21);

    if (DEBUG)
        cout << "-  -   - tree    -   -   -"
             << endl
             << endl
             << tree << endl;

    tree.insert(60);
    tree.insert(55);

    if (DEBUG)
        cout << "-  -   - tree    -   -   -"
             << endl
             << endl
             << tree << endl;

    tree.insert(5);
    tree.insert(90);

    cout << "-  -   -   -   AVL tree    -   -   -"
         << endl
         << endl
         << tree << endl;
}

void test_avl_operator_Plus_equal() {
    cout << "\n= = = = = avl += ( avl ) test = = = = =\n\n";

    int arr[] = {30, 31, 32, 33, 34, 35, 36, 37, 38, 39};
    int size = sizeof(arr) / sizeof(arr[0]);

    avl<int> tree(arr, size);

    cout << "```````````````  tree 1  `````````````````````\n\n";
    cout << tree << endl
         << endl;

    avl<int> second_Tree;
    cout << "```````````````  tree 2  `````````````````````\n\n";
    test_avl_insert(second_Tree);

    tree += second_Tree;
    cout << "```````````````  tree 1 += tree 2 ```````````````n\n";
    cout << tree << endl
         << endl;

    cout << "\n= = = = exiting avl += ( avl ) test test = = = =\n\n";
}

void test_avl_print_inorder() {
    cout << "\n= = = = = print_inorder( ) test = = = = =\n\n";

    avl<int> tree;
    test_avl_insert(tree);

    cout << "Printing avl tree in order " << endl;
    tree.print_inorder();

    cout << "\n= = = exiting print_inorder( ) test = = =\n\n";
}

void test_avl_search() {
    cout << "\n= = = = avl search(root, target) test = = = = = \n\n";
    avl<int> tree;
    test_avl_insert(tree);

    int target = 10;
    tree_node<int> *found = nullptr;
    bool located = tree.search(target, found);

    if (located) {
        cout << "found: " << found->_item << endl;
        found->_item = 120;
        cout << tree << endl;
    } else
        cout << "Target not found" << endl;
    tree_print(found);

    cout << "\n= = = = exiting avl search(root, target) = = =  =\n\n";
}

#endif  // AVL_TEST_H
