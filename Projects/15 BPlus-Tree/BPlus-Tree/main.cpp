#include <iostream>


#include "../../!includes/BPlus_Tree/bplus_tree_test.h"
//#include "random_test.h"

using namespace std;


void final_test( )
{

    cout << "=  =   = final B+ tree test =  =   =" << endl << endl;

    BPlusTree <int> tree;

    int arr[50];
    for ( int i = 0 ; i < 100; i++ )
    {
        tree.insert( i );
        arr[i] = i;
    }

    cout << tree << endl << endl;

    for ( int i = 96; i < 100 ; i++ )
    {
        tree.remove(i );
        cout << "==================================================" << endl << endl;
        cout << tree << endl;
    }



    cout << endl<< "=  =   = exiting final B+ tree test =  =   ="
         << endl << endl;

}


int main()
{
    srand( time( NULL ) );



    final_test( );





    // =============================================================
    // =============================================================
    //              Btree functions test
    // =============================================================
    // =============================================================





//        test_iterators();

    //    test_big_three();

    //    test_clear();

    //    test_contains();

    //    test_copy( );

    //    test_find();

    //    test_get();

    //    BPlusTree<int> t;
    //    test_insert(t );

    //    test_remove();

//        test_new_remove();

    //    test_tree_auto( 1000, 5, true );




    return 0;
}


