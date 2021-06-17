#ifndef B_TREE_TEST_H
#define B_TREE_TEST_H

#include <iostream>

#include "../../!includes/Array_Functions/array_functions.h"
#include "../../!includes/B_Tree/b_tree.h"
#include "../../!includes/Random/random.h"

using namespace std;

const int REMOVE_MAX = 100;
const int INSERT_MAX = 100;

//const int ARR [] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 10,  11, 12, 13, 14,15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 26, 31, 32};
//const int ARR [] = { 20, 30, 12, 7, 10, 15, 17, 25, 22, 35, 32};
//const int ARR [] = { 50, 25 , 12, 53 , 90, 60,  75};
const int ARR [ ] = { 0, 30, 12, 7, 10, 15, 17, 25, 22, 35, 32,50, 25 , 12, 53 , 90, 60,  75 };
const int COMPARE_ARRAY [] = { 50, 25 , 12, 53 , 90, 60, 10001, 19, 75, 0 };

void test_big_three();
// a test function for btree's big three functions

void test_clear();
// a test function for clear();

void test_contains();
// a test function for contains();

void test_copy();
// a test function for copy();

void test_find();
// a test function for find();

void test_get();
// a test function for get();

void test_insert( BTree<int>& bt );
// a function to insert items into a tree

void test_remove();
// a test function to for remove();

// **************************************************


void bulk_remove();
// random remove function

// **************************************************

int Random( int lo, int hi);

// =============================================================
// =============================================================
//              Function definitions
// =============================================================
// =============================================================

void test_big_three()
{
    cout << "=  =   =  test  big three =  =   =" << endl << endl;
    BTree <int> bt ;
    test_insert( bt );
    cout << endl << endl;

    cout << "=  =  BTree ( const BTree<T> ) test    =   =\n\n" ;
    BTree<int> temp(bt);

    cout << "-------------- temp --------------" << endl << endl;
    temp.print( );

    int entry = 30 ;
    int* ptr = temp.find( entry );
    if ( ptr )
        *ptr += 1;

    cout << "\nAFTER CHANGING ONE ENTRY IN THE new TREE\n\n";
    cout << "--------------- bt ---------------"<< endl << endl;
    bt.print();
    cout << "-------------- temp --------------" << endl << endl;
    temp.print( );

    cout << endl << endl << endl << endl;
    cout << "=  =  BTree operator =(const BTree<T>) test    =   =\n\n" ;

    BTree<int> hold = bt;
    cout << "-------------- hold --------------" << endl << endl;
    hold.print( );

    entry = 25 ;
    ptr = hold.find( entry );
    if ( ptr )
        *ptr += 1;

    cout << "\nAFTER CHANGING ONE ENTRY IN THE NEW TREE\n\n";
    cout << "--------------- bt ---------------"<< endl << endl;
    bt.print();
    cout << "-------------- hold --------------" << endl << endl;
    hold.print( );

    cout << "=  =   =  exiting big three test =  =   =" << endl << endl;

}

void test_clear()
{
    cout << "=  =   =  test  clear() =  =   =\n\n";
    BTree <int> tree;
    test_insert( tree );

    tree.clear();
    tree.print();
    cout << "\n=  =   =  exiting  clear() =  =   =\n\n";
}

void test_contains()
{
    cout << "=  =   =  test  contains() =  =   =\n\n";

    BTree <int> tree;
    test_insert( tree );

    int size = sizeof ( COMPARE_ARRAY ) / sizeof ( COMPARE_ARRAY [ 0 ] );

    for ( int i = 0 ; i < size ; i++ )
    {
        int entry = COMPARE_ARRAY [ i ] ;
        bool found = tree.contains ( entry );

        cout << ( found? "Tree contains: ": "Tree doesn't contain: " )
             << entry << endl;
    }

    cout << "\n=  =   exiting contains() test   =  =  =\n\n";
}

void test_copy()
{
    cout << "=  =   =  test  copy() =  =   =\n\n";
    BTree <int> tree;
    test_insert( tree );

    BTree <int> bt;
    bt.copy( tree );

    cout << "-  -   -   - new tree  -   -   -   -" << endl
         << endl << bt << endl << endl;

    cout << "=  =   =   =   =   =   =   =   =   =\n\n" ;

    int size = sizeof ( COMPARE_ARRAY ) / sizeof ( COMPARE_ARRAY [ 0 ] );

    for ( int i = 0 ; i < size ; i++ )
    {
        bt.get( ARR[i] );

        cout << "new-tree.get( " << ARR[i] << " )" << endl;

        cout << " ------------- new tree ------------- " << endl
             <<  endl << bt  << endl;

        cout << " ------------- original tree ------------- " << endl
             << endl << tree << endl;
    }

    cout << "=  =   =   =  FINAL TREE OUTPUT =   =   =   =   =   =\n\n" ;
    cout << " -  -   -   - new tree -  -   -   - " << endl
         << endl << bt << endl << endl;
    cout << " -   -   - original tree -  -  -  -" << endl
         << endl << tree << endl << endl;

    cout << "=  =   =    exiting copy() test    =   =   =\n\n";

    cout << "=  =   =    exiting copy() test    =   =   =\n\n";

}

void test_find()
{
    cout << "=  =   =   test  find() =  =  =" << endl << endl;
    BTree <int> tree;
    test_insert( tree );

    int arr [] = { 50, 25 , 12, 53 , 90, 60,  75, 22, 35, 32, 37, 20  };
    int size = sizeof ( arr ) / sizeof ( arr [ 0 ] );

    for ( int i = 0 ; i < size ; i++ )
    {
        cout << " entry: " << arr [i];
        int* ptr = tree.find( arr [ i ] );

        cout << (ptr? " entry found: " : "entry not found" ) << endl;

    }

    cout << "\n=  =   exiting find() test   =  =" << endl << endl;
}

void test_get()
{
    cout << "=  =   =   test  get() =  =  =" << endl << endl;
    BTree <int> tree;
    test_insert( tree );

    int size = sizeof ( COMPARE_ARRAY ) / sizeof ( COMPARE_ARRAY [ 0 ] );
    for ( int i = 0 ; i < size ; i++ )
    {
        cout << "tree.get(" << COMPARE_ARRAY[i] << "): "
             << tree.get( COMPARE_ARRAY[i] )
             << " size: " << tree.size() << endl;

        cout << " =  =   =  tree  =   =   =\n\n" << tree << endl;
    }

    cout << "\n=  =   =   =  = final Tree   =   =  =  =   =\n\n";
    cout << "tree size: " << tree.size() << endl << tree << endl;

    cout << "\n=  =   exiting get() test   =  =" << endl << endl;

    cout << "\n=  =   exiting get() test   =  =" << endl << endl;
}

void test_insert( BTree<int>& tree )
{
    const bool DEBUG = false;

    int size = sizeof ( ARR ) / sizeof ( ARR [ 0 ] );
    for ( int i = 0 ; i < size ; i++ )
    {
        if ( DEBUG )
            print_array ( ARR , size , i );

        tree.insert( ARR[ i ] );
        assert ( tree.is_valid( ) && "insert" );

        if ( DEBUG )
            cout << "***************** tree ***************** \n\n"
                 << tree << endl << endl;

    }

    cout << "\n=  =   =   =  Final tree   =   =   =   =\n\n";
    cout << "tree size " << tree.size() << endl
         << endl << tree << endl;;
    cout << "\n=  =   =   =  =  =   =   =  =   =   =   =\n\n";

}

void test_remove()
{
    cout << "=  =   =   test  remove() =  =   =" << endl << endl;
    BTree <int> tree;
    test_insert(tree );

    int arr [ ] = {0, 30, 12, 7, 10, 15, 17, 25, 22, 35, 32,50, 25 , 12, 53 , 90, 60,  75 };
    int size = sizeof ( arr ) / sizeof ( arr [ 0 ] );

    for ( int i = 0 ; i < size ; i++ )
    {
        print_array ( arr , size , i );
        tree.remove( arr[ i ] );

        cout << "=  =  =    =   =   =  size: " << tree.size()
             <<"=  =   =   =   =   =   =" << endl;


        cout << endl << tree <<  endl;
        assert ( tree.is_valid() && "tree must be valid");
        tree.is_valid();
    }

    cout << "\n=  =   =   =  Final tree   =   =   =   =" << endl << endl;
    cout << tree << endl << endl <<  "tree size " << tree.size() << endl;

    cout << "=  =   =   exiting remove() test =  =   =" << endl << endl;

}


int Random( int low, int high )
{
    int r = rand() % ( high - low + 1 )+ low;
    return r;
}

#endif // B_TREE_TEST_H
