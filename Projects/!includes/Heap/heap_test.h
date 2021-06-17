#ifndef HEAP_TEST_H
#define HEAP_TEST_H
#include <iostream>
#include "../../!includes/Heap/heap.h"

using namespace  std;


void test_big_three();
// test for Heap constructors and destructors (big three)

void test_capacity();
// a test for Heap's capacity function

void test_copy();
// a test for copy function;

void test_insert(Heap<int> &test);
// a test for Heap's insert function

void test_is_empty();
// a test for Heap's is_empty function

void test_Pop();
// a test for Heap's Pop function

void test_size();
// a test for Heap's size() function

//==============================================================
//  functions definitions
//==============================================================

void test_big_three()
{
    cout << "\n= = = = big three functions test = = = = =\n\n";

    Heap<int> tree ;
    test_insert(tree);
    cout << "\n= = = = assignment operator test = = = = =\n" << endl;
    Heap<int> temp1;
    temp1 = tree;

    cout << "tree: " << tree << endl;
    cout << "temp1: " << temp1 << endl;
    temp1.insert(101);

    cout << "\n-  -   -  after temp1.insert(101)  -  -   -  -\n\n";
    cout << "tree: " << tree << endl ;
    cout << "temp1: " << temp1 << endl;


    cout << "\n= = = = copy constructor test = = = = =\n" << endl;
    Heap<int> temp2 (tree);

    cout << "tree: " << tree << endl;
    cout << "temp2: " << temp2 << endl;

    temp2.insert(202);

    cout << "\n-  -   -  after temp2.insert(202)  -  -   -  -\n\n";
    cout << "tree: " << tree << endl;
    cout << "temp1: " << temp1 << endl;
    cout << "temp2: " << temp2 << endl;

    cout << "\n= = = = exiting big three functions test = = = =\n\n";

}

void test_capacity()
{
    cout << "=  =   =   =  capacity()  test =   =   =   \n";
    Heap<int> tree;
    test_insert(tree);

    cout << endl << "total tree capacity: " << tree.capacity()
         << endl << endl << "TREE: " << tree << endl;

    cout << "\n=  =   =   =  exiting capacity()  test =   =   =   \n";
}

void test_copy()
{
    cout << "\n=  =   =   =  copy()  test =   =   =   \n";
    Heap<int> tree;


    int src[] = { 1, 3, 5, 6, 7, 8, 9, 18, 12};
    int size = 5;
    int arr[20];
    int* ptr = arr;

    tree.copy(ptr, src, size);


    cout << endl <<  "src array: " << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << src[i] << "    " ;
    }
    cout << endl;

    cout << endl << "copy array with: " << size << " size: " << endl;
    for(int i = 0; i < size ; i++)
    {
        cout << ptr[i] << "    " ;
    }
    cout << endl;

    cout << "=  =   =   =  exiting copy()  test =   =   =\n\n";
}

void test_insert(Heap <int> &tree)
{
    const bool DEBUG = false;
//    int arr[] = { 10, 40, 24/*, 50 */};
    int arr[] = {10, 40, 24, 50 , 13, 35, 74, 21, 60, 55, 5, 90 };

    int size = sizeof(arr) / sizeof (arr[0]);

    if(DEBUG)
    {
        cout << "inserting the following in order : " << endl;
        for(int i = 0; i < size; i++)
        {
            cout << arr[i] << "     " ;
        }
        cout << endl;
    }


    for(int i = 0; i < size; i++)
    {
        tree.insert(arr[i]);
        if(DEBUG)
        cout << endl << endl << tree << endl;
    }

    cout << "\n   =   =   =   =   FINAL TREE  =   =   =   =\n";
    cout << endl << tree << endl << endl;
}

void test_is_empty()
{
    cout << "\n=  =   =   =  is_empty()  test =   =   =   \n";
    Heap<int> tree;
    test_insert(tree);

    if(tree.is_empty() )
        cout << "tree is empty" << endl;
    else
        cout <<  "tree is not empty" << endl;


    cout << "\n=  =   =   = exiting is_empty()  test =   =   = \n\n";
}

void test_Pop()
{
    cout << "\n\n=  =   =   =   Pop()  test =   =   =   \n";
    Heap<int> tree;
    test_insert(tree);

    size_t s = tree.size();

    for( size_t  i = 0; i  < s ; ++i)
    {
        int erased = tree.Pop();
        cout << "erased item: " << erased << endl;
        cout << endl << "tree after pop: " << endl << tree << endl;
    }

    cout << "\n=  =   =   = exiting Pop()  test =   =   =   \n\n";
}

void test_size()
{
    cout << "\n=  =   =   =  size()  test =   =   =   \n";
    Heap<int> tree;
    test_insert(tree);

    cout << endl << "Tree size: " << tree.size() << endl;

    cout << "\n=  =   =   =  exiting size()  test =   =   =\n\n";
}

#endif // HEAP_TEST_H
