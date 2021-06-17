
#include <iostream>

#include "../../!includes/Map/BPlus_Tree/map_test.h"
#include "../../!includes/Map/BPlus_Tree/multimap_test.h"

using namespace std;


int main()
{



    Map < string, string> m;
    int name_Size = sizeof ( name )/ sizeof ( name[ 0 ] );

    cout << "total pairs to insert: " << name_Size << endl;
    for ( int i = 0; i < name_Size; i++ )
    {
        m.insert(  name[i], color[i]) ;
        m[name[i]] = color[i];
//        assert ( m.is_valid() && "Map not valid" );

        cout << "   =   =   = Map  =   =   =   =" << endl;
        cout << m << endl;
    }







    /// Map functions tests

//    simple_map_test();

//    map_accessors_test( );

//    map_iterators_test( );

//    map_modifiers_test( );

//    map_operations_test( );


// =============================================================
// =============================================================

    /// Multimap functions tests

//    simple_multimap_test();

//    multimap_accessors_test( );

//    multimap_iterators_test( );

//    multimap_modifiers_test( );

//    multimap_operations_test( );


    return 0;
}

