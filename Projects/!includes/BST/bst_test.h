#ifndef BST_TEST_H
#define BST_TEST_H
#include <iostream>
#include "../../!includes/BST/bst.h"
#include "../../!includes/Binary_Search_Tree/binary_search_tree.h"

using namespace  std;

void test_BST_big_three();
// test for BST constructors and destructors (big three)

void test_BST_constructors();
// test for BST default constructor and BST(sorted_list, size)

void test_BST_erase();
// a test for BST's erase function

void test_BST_insert(BST<int> &test);
// a test for BST's insert function

void test_BST_operator_Plus_equal();
// a test for BST's += operator

void test_BST_search();
// a test for BST's search function

//==============================================================
//  functions definitions
//==============================================================

void test_BST_big_three()
{
    cout << "\n= = = = big three functions test = = = = =\n\n";

    BST<int> tree ;
    test_BST_insert(tree);
    cout << "\n= = = = assignment operator test = = = = =\n" << endl;
    BST<int> temp1 = tree;

    cout << "tree: " << tree << endl;
    cout << "temp1: " <<temp1 << endl;

    cout << "\n= = = = copy constructor  test = = = = =\n" << endl;
    BST<int> temp2 (tree);

    cout << "tree: " << tree << endl;
    cout << "temp2: " <<temp2 << endl;

    cout << "\n= = = = exiting big three functions test = = = =\n\n";

}

void test_BST_constructors()
{
    cout << "\n= = = = = BST CTOR's  test = = = = =\n\n";

    int arr[] = {30,31,32,33,34,35,36,37,38,39};
    int size = sizeof(arr) / sizeof(arr[0]);

    BST<int> tree(arr, size);

    cout << "Tree from BST( T* sorted_list , int size)"
         << endl << endl << tree << endl << endl;

    BST<int> second_Tree;
    cout << "Tree from BST( ) " << endl << endl;
    test_BST_insert(second_Tree);

    cout << "\n= = = = = exiting BST CTOR's  test = = = = =\n\n";

}

void test_BST_insert(BST <int> &tree)
{
    const bool DEBUG = false;
    int arr[] = {10, 40, 24, 50, 13, 35, 74, 21, 60, 55, 5, 90 };
    int size = sizeof(arr) / sizeof (arr[0]);

    for(int i = 0; i < size; i++)
    {
        tree.insert(arr[i]);
        if(DEBUG)
        cout << "Heap " << endl << endl << tree << endl;
    }


    cout << "\n   =   =   =  FINAL BST TREE  =   =   =   =\n";
    cout << endl << tree << endl;
}

void test_BST_operator_Plus_equal()
{
    cout << "\n= = = = = BST += ( BST ) test = = = = =\n\n";

    int arr[] = {30,31,32,33,34,35,36,37,38,39};
    int size = sizeof(arr) / sizeof(arr[0]);

    BST<int> tree(arr, size);

    cout << "```````````````    tree 1  `````````````````````\n\n";
    cout << tree << endl << endl;

    BST<int> second_Tree;
    cout << "```````````````    tree 2  `````````````````````\n\n";
    test_BST_insert(second_Tree);


    tree += second_Tree;
    cout << "```````````````    tree 1 += tree 2  `````````````````````\n\n";
    cout << tree << endl << endl;

    cout << "\n= = = = exiting BST += ( BST ) test test = = = =\n\n";
}

void test_BST_search()
{
    cout << "\n= = = = BST search(root, target) test = = = = = \n\n";
    BST<int> tree;
    test_BST_insert(tree);

    int target = 10;
    tree_node<int>* found = nullptr;
    bool located = tree.search(target, found);

    if(located)
    {
        cout << "found: " << found->_item << endl;
    }
    else
        cout << "Target not found" << endl;
    tree_print (found) ;

    cout << "\n= = = = exiting BST search(root, target) = = =  =\n\n";
}

#endif // BST_TEST_H
