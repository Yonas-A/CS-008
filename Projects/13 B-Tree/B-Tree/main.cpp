#include <iostream>

//#include "../../!includes/Array_Functions/array_functions_test.h"
#include "../../!includes/B_Tree/b_tree_test.h"

//#include "random_test.h"


using namespace std;

int main( int argc, char *argv[] )
{    
    srand ( time ( NULL));

    setprogname( argv[0]);

//    test_attach_item();

//    test_copy_array();

//    test_delete_item();

//    test_detach_item();

//    test_first_ge ();

//    test_index_max();

//    test_insert_item();

//    test_is_gt();

//    test_is_le();

//    test_maximal();

//    test_merge();

//    test_ordered_insert();

//    test_split();

//    test_overloaded_PLUS_OPERATOR( );

//    test_overloaded_PLUS_EQUAL( );



// =============================================================
// =============================================================
//              Btree functions test
// =============================================================
// =============================================================


    test_big_three();

//    test_clear();

//    test_contains();

//    test_copy( );

//    test_find();

//    test_get();

//    BTree<int> t;
//    test_insert(t );

//    test_remove();

//    bulk_remove();


//    test_tree_auto( 1000, 500, false);



    return 0;

}
