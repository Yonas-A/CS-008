#ifndef PQUEUE_TEST_H
#define PQUEUE_TEST_H
#include <iostream>
#include <string.h>
#include "../../!includes/Priority_Queue/pqueue.h"

using namespace  std;

/// info struct test functions
///=================///=================///=================
void test_info();
// a test function for info struct

void test_info_comparison();
// a test functionfor info struct > & < operator


/// priority queue test functions
///=================///=================///=================

void test_insert(PQueue<int> & tree);
// a test function for PQueue insert() function

void test_is_empty();
// a test function for PQueue is_empty() function

void test_Pop();
// a test function for PQueue Pop() function

void test_size();
// a test function for PQueue size() function


///================= ================== ==================
/// test function definitions for info struct
///================= ================== ==================

void test_info()
{
    cout << "\n= = = = info ctor test = = = = =\n\n";

    info<string> midterm("Midterm", 7);
    cout << midterm << endl;

    info<string> final ("Final", 10);
    cout << final << endl;

    cout << "\n= = = = exiting info ctor test = = = = =\n\n";
}

void test_info_comparison()
{
    cout << "\n= = = info < && info > operatro test = = =\n\n";

    info<string> midterm("Midterm", 10);
    cout << midterm << endl;

    info<string> final ("Final", 10, 7);
    cout << final << endl;


    if( midterm > final)
    {
        cout << "midterm is greater than final: " << endl;
    }

    else if( midterm < final)
    {
        cout << "midterm is less than final: " << endl;
    }

    else
    {
        cout << "midterm is equal to final: " << endl;
    }

    cout << "\n= = = exiting info < && info > operatro test = = =\n\n";

}


///================= ================== ==================
/// test function definitions for PQueue class
///================= ================== ==================

void test_insert(PQueue<int> & tree)
{
    const bool DEBUG = true;
    int arr[] = {10, 40, 24, 50, 13, 35/*, 74, 21, 60, 55, 5, 90*/ };
    int size = sizeof(arr) / sizeof (arr[0]);


    if(DEBUG)
    {
        cout << "Inserting the following in order : " << endl;

        for(int i = 0; i < size; i++)
        {
            cout << "Item: " <<  arr[i] << "    Priority: " << i << endl;
        }
        cout << endl << endl;
    }

    for(int i = 0; i < size; i++)
    {
        tree.insert(arr[i] , i);
    }

    cout << tree << endl << endl; ;

}

void test_is_empty()
{
    cout << "\n=  =   =   =  is_empty()  test =   =   =   \n";
    PQueue<int> tree;
    test_insert(tree);

    if( tree.is_empty() )
        cout << "tree is empty" << endl;
    else
    {
        cout << "tree is not empty. Tree" << endl << endl
                << tree << endl << endl;
    }


    cout << "\n=  =   =   = exiting is_empty()  test =   =   = \n\n";
}

void test_Pop()
{
    cout << "\n\n=  =   =   =   Pop()  test =   =   =   \n";
    PQueue<int> tree;
    test_insert(tree);

    unsigned int temp_size = tree.size();

    for( unsigned int i = 0; i < temp_size + 1; i++)
    {
        cout << "erased item: " << tree.Pop() << endl
             << endl << tree <<  endl << endl;
    }

    cout << "\n=  =   =   = exiting Pop()  test =   =   =   \n\n";
}

void test_size()
{
    cout << "\n=  =   =   =  size()  test =   =   =   \n";
    PQueue<int> tree;
    test_insert(tree);

    cout << endl << "Tree size: " << tree.size() << endl;

    cout << "\n=  =   =   =  exiting size()  test =   =   =\n\n";
}




#endif // PQUEUE_TEST_H
