#ifndef BPLUS_TREE_TEST_H
#define BPLUS_TREE_TEST_H

#include <iostream>

#include "../../!includes/Array_Functions/array_functions.h"
//#include "../../!includes/BPlus_Tree/bplus_tree.h"
#include "../../!includes/BPlus_Tree/bplus_tree.h"


using namespace std;


const int ARR [] = { 75, 100, 150 , 25, 200 , 95/*, 300, 400 */};

//const int ARR [ ] = { 18, 31, 12, 10, 15, 48, 45, 47, 50, 52, 23, 30, 20 };

//const int ARR [ ] = { 18, 31, 12, 10, 15, 48, 45, 47, 50, 52, 23, 30, 20, 75, 100, 150 , 25, 200 , 95, 300, 400 };

const int COMPARE_ARRAY [] = { 95, 13 , 12, 53 , 900, 60, 10001, 19, 75, 0 , 18, 31, 10, 15, 48, 45, 47, 50, 52, 23, 30, 20};

const int COMPARE_SIZE = sizeof( COMPARE_ARRAY ) / sizeof ( COMPARE_ARRAY[0] );


void test_iterators( );
/// iterators test

void test_big_three();
// a test function for BPlusTree's big three functions

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

void test_insert( BPlusTree<int>& bt );
// a function to insert items into a tree

void test_remove();
// a test function to for remove();

void test_new_remove();


// =============================================================
// =============================================================
//              Function definitions
// =============================================================
// =============================================================


void test_iterators()
{
    cout << "=  =   =  test  iterator =  =   =\n\n";
    BPlusTree <int> tree;
    test_insert( tree );

    BPlusTree<int>::Iterator it ;
    cout << "iterated list print" << endl << endl;

    for ( it = tree.begin(); it != tree.end(); ++it )
    {
        cout << "[" << *it << "]" << "->";
    }
    cout << "|||" <<  endl << endl;

    for ( int i = 0 ; i < COMPARE_SIZE; i++ )
    {
        cout << "lower_bound( " << COMPARE_ARRAY[i] << " )  ";
        it = tree.lower_bound( COMPARE_ARRAY [ i ] ) ;
        if ( it != tree.end() )
             cout << *it << endl;
        else
            cout << endl;
    }
    cout << "***************** UPPER BOUND ***************** \n\n";

    for ( int i = 0 ; i < COMPARE_SIZE; i++ )
    {
        if ( COMPARE_ARRAY[i] == 52 )
        {

        }
        cout << "upper_bound( " << COMPARE_ARRAY[i] << " )  ";
        it = tree.upper_bound( COMPARE_ARRAY [ i ] ) ;
        if ( it != tree.end() )
             cout << *it << endl;
        else
            cout << endl;

    }




    cout << "\n=  =   =  exiting  iterator test =  =   =\n\n";
}

void test_big_three()
{
    cout << "=  =   =  test  big three =  =   =" << endl << endl;
    BPlusTree <int> bt ;
    test_insert( bt );
    cout << endl << endl;

    cout << "=  =  BPlusTree ( const BPlusTree<T> ) test    =   =\n\n" ;
    BPlusTree<int> temp(bt);

    cout << "-------------- temp --------------" << endl << endl;
    temp.print( );

    temp.BPlusTree<int>::get( 30);

    cout << "\nAFTER CHANGING ONE ENTRY IN THE new TREE\n\n";
    cout << "--------------- bt ---------------"<< endl << endl;
    bt.print();
    cout << "-------------- temp --------------" << endl << endl;
    temp.print( );

    cout << endl << endl << endl << endl;
    cout << "=  =  BPlusTree operator =(const BPlusTree<T>) test    =   =\n\n" ;

    BPlusTree<int> hold = bt;
    cout << "-------------- hold --------------" << endl << endl;
    hold.print( );

    hold.get(270);


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
    BPlusTree <int> tree;
    test_insert( tree );

    tree.clear();
    tree.print();
    cout << "\n=  =   =  exiting  clear() =  =   =\n\n";
}

void test_contains()
{
    cout << "=  =   =  test  contains() =  =   =\n\n";

    BPlusTree <int> tree;
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
    BPlusTree <int> tree;
    test_insert( tree );

    BPlusTree <int> bt;
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

}

void test_find()
{
    cout << "=  =   =   test  find() =  =  =" << endl << endl;
    BPlusTree <int> tree;
    test_insert( tree );

    int size = sizeof ( COMPARE_ARRAY ) / sizeof ( COMPARE_ARRAY [ 0 ] );

    for ( int i = 0 ; i < size ; i++ )
    {
        cout << " entry: " << COMPARE_ARRAY [i];
        BPlusTree<int>::Iterator it = tree.find( COMPARE_ARRAY [ i ] );

        if ( it != nullptr )
            cout << "   Entry found: " << *it << endl;
        else
            cout << "   Entry not found:" << endl;

    }
    cout << "\n=  =   exiting find() test   =  =" << endl << endl;
}

void test_get()
{
    cout << "=  =   =   test  get() =  =  =" << endl << endl;
    BPlusTree <int> tree;
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
}

void test_insert( BPlusTree<int>& tree )
{
    const bool DEBUG = false;

    int size = sizeof ( ARR ) / sizeof ( ARR [ 0 ] );
    for ( int i = 0 ; i < size ; i++ )
    {
        if ( DEBUG )
            print_array ( ARR , size , i );

        tree.insert( ARR[ i ] );
        assert ( tree.is_valid() && "tree must be valid after insert");

        if ( DEBUG )
        {
            cout << "***************** tree ***************** \n\n"
                 << tree << endl << endl;

            BPlusTree<int>::Iterator it;
            cout << "iterated list print" << endl << endl;
            for ( it = tree.begin(); it != tree.end(); ++it )
            {
                cout << "[" << *it << "]" << "->";
            }
            cout << "|||" <<  endl << endl;
        }
    }

    cout << "\n=  =   =   =  Final tree   =   =   =   =\n\n";
    cout << "tree size " << tree.size() << endl
         << endl << tree << endl << endl;
    cout << "\n=  =   =   =  =  =   =   =  =   =   =   =\n\n";

}

void test_remove()
{
    cout << "=  =   =   test  remove() =  =   =" << endl << endl;
    BPlusTree <int> tree;
    test_insert(tree );

//     int arr [] = { 75, 100, 150 , 25, 200 , 95, 300, 400 };
//    int arr [] = { 18, 31, 12, 10, 15, 48, 45, 47, 50, 52, 23, 30, 20 };
     int arr [] = { 18, 31, 12, 10, 75, 100, 150 , 25, 200 , 95, 300, 400, 15, 48, 45, 47, 50, 52, 23, 30, 20 };

    int size = sizeof ( arr ) / sizeof ( arr [ 0 ] );

    int found_count = 0;
    for ( int i = 0 ; i < size ; i++ )
    {
        print_array ( arr , size , i );
        if ( arr[i] == 200 )
        {

        }
        tree.remove( arr[ i ] );
        cout << "\n=  =   =   =   =  B+ TREE =   =   =   =   =  =\n";
        cout << tree << endl << endl;
        cout << "find_for_debug( target ) " << arr[i] << "      ";
        cout << ( tree.find_for_debug( arr[i] ) ? "TARGET FOUND":
                "TARGET NOT FOUND") << endl;

        assert ( tree.is_valid() && "tree must be valid after remove");
        if ( tree.find_for_debug(arr[i] ) )
            found_count++;

        BPlusTree<int>::Iterator it;
        cout << "iterated list print" << endl << endl;
        if ( tree.size( ) > 0)
        {
            for ( it = tree.begin(); it != tree.end(); ++it )
            {
                cout << "[" << *it << "]" << "->";
            }
            cout << "|||" <<  endl << endl;
        }

    }

    cout << "\n=  =   =   =  Final tree   =   =   =   =\n";
    cout << "tree size " << tree.size() << endl;
    cout << "FOUND COUNT: " << found_count << endl << endl;
    cout << endl << endl << tree << endl << endl;

    cout << "=  =   =   exiting remove() test =  =   =" << endl << endl;

}


void test_new_remove()
{

    cout << "=  =   =   test NEW remove() =  =   =" << endl << endl;
    BPlusTree <int> tree;


    int arr [1000] = {0};
    int size = 0;

    int high = 10000, low = 1;

    for ( int i = 0; i < 1000 ; i++ )
    {
        int r = rand()%( high - low + 1 ) + low;
        int index = 0;
        if ( !search_array( arr, size, r, index) )
        {
            tree.insert(r );
            arr[ size ] = r;
            size ++;
        }
    }
    cout << "array_size: " << size << endl
         << "tree size: " << tree.size() << endl << endl;


    int new_size = 0;
    int found_count = 0;
    for ( int i = 0 ; i < size ; i++ )
    {
        tree.remove( arr[ i ] );
        new_size++;
        cout << "\n=  =   =   =   =  B+ TREE =   =   =   =   =  =\n";
        cout << ( tree.find_for_debug( arr[i] ) ? "TARGET FOUND":
                "TARGET NOT FOUND") << endl;
        if ( tree.find_for_debug(arr[i] ) )
            found_count++;

        assert ( tree.is_valid() && "tree must be valid after remove");

        BPlusTree<int>::Iterator it;
        if ( tree.size() > 0 )
        {
            cout << "iterated list print" << endl << endl;

            for ( it = tree.begin(); it != tree.end(); ++it )
            {
                cout << "[" << *it << "]" << "->";
            }
            cout << "|||" <<  endl << endl;
        }

    }
    cout << "new_size: " << new_size << endl
         << "tree size: " << tree.size() << endl
         << "FOUND COUNT: " << found_count << endl << endl;


    cout << "\n=  =   =   =  Final tree   =   =   =   =\n";
    cout << "tree size " << tree.size() << endl;
    cout << endl << endl << tree << endl << endl;

    cout << "=  =   =   exiting NEW remove() test =  =   =" << endl << endl;
}



#endif // BPLUS_TREE_TEST_H
