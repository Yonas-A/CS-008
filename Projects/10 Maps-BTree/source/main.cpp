#include <iostream>

#include "../../!includes/Map/B_Tree/map_test.h"
//#include "../../!includes/Map/B_Tree/multimap_test.h"

using namespace std;

int main()
{


    /// Map functions tests

    test_pair_struct();

    test_map_operator();

    simple_map_test();

// =============================================================
// =============================================================

    /// Multimap functions tests

//    test_multi_pair_struct();

//    simple_multimap_test();

//    test_multimap_operators();


    return 0;
}

