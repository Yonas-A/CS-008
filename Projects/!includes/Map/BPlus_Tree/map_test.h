#ifndef MAP_TEST_H
#define MAP_TEST_H

#include <iostream>

#include "../../!includes/BPlus_Tree/bplus_tree.h"
#include "../../!includes/Map/BPlus_Tree/map.h"
#include "../../!includes/Pair/pair.h"
#include <utility>

// =============================================================

const string str[] = { "Jan", "Feb", "Mar" , "Apr", "May", "Jun"};
const int arr[] = {31, 28 , 31, 31, 30, 30 };


string color[] = { "Blue", "Burgundy", "Yellow", "Red" , "Black",
                   "Violet", "Purple", "Pink",  "Veal", "Sapphire"};

string name[] = { "Betty", "Macklemore", "Tom", "Li", "Jack",
                    "Beth", "Lily", "Jack" };

// =============================================================

void simple_map_test();
// a test function for map class

void map_iterators_test( );
// a test function for map iterators

void map_accessors_test( );
// a test function for map accessor functions

void map_modifiers_test( );
// a test function for map modifing functions

void map_operations_test( );
// a test function for map operating functiong

// =============================================================
// =============================================================
//            test  Functions definition
// =============================================================
// =============================================================

void simple_map_test()
{
    cout << "\n   =   = simple map test =   =   =\n" << endl;

    Map < string, string> m;
    int name_Size = sizeof ( name )/ sizeof ( name[ 0 ] );

    cout << "total pairs to insert: " << name_Size << endl;
    for ( int i = 0; i < name_Size; i++ )
    {
        m.insert(  name[i], color[i]) ;
        assert ( m.is_valid() && "Map not valid" );

        cout << "   =   =   = Map  =   =   =   =" << endl;
        cout << m << endl;
    }

    cout << "map size: " << m.size() <<  endl;
    cout << "   =   =   =   FINAL Map    =   =   =   =" << endl;
    cout << m << endl;

    cout << "m [ PAUL ] =  Red" << endl << endl;
    m["PAUL"] = "Red";
    cout << m << endl;

    cout << m["PAUL"]  << "   calling PALU WITH operator []" << endl;
    cout << m << endl;

    cout << "chainging [ PAUL ] =  Red to Sapphire" << endl << endl;
    m["PAUL"] = "Sapphire";
    cout << m << endl;

    cout << "erase Macklmore" << endl << endl;
    m.erase("Macklemor");
    cout << m << endl;

    cout << "\n   =   = EXITING simple map test =   =   =\n" << endl;
}

void map_accessors_test( )
{
    cout << "=   =   =  map accessors test =   =   =   =\n\n";
    Map < string, int> m;

    int size = sizeof( arr ) / sizeof( arr[ 0 ] );
    for ( int i = 0; i < size; i++ )
        m.insert( str[i], arr[i]) ;

    cout << "   =   =   =   Map    =   =   =   =" << endl;
    cout << m << endl;

    cout << "m [ jan ] = 21" << endl;
    m["jan"] = 21;
    cout << m << endl;


    cout << "m[ Jan ]: " << m["Jan"] << endl;
    cout << "m.at(Jan): " <<  m.at( "Jan") << endl;
    cout << m << endl;

    cout << "m.at(feb):  = 29" << endl;
    m.at("feb") = 29;
    cout << m << endl;

     m["Jan"] = 1101;
    cout << "m[ Jan ]: " << m["Jan"] << endl;

    cout << "   =   =   =   =    Final Tree =   =   =   =   =" << endl;
    cout << m << endl;

    cout << "=  =  = EXITING map accessors test =  =  =\n\n";

}

void map_iterators_test( )
{
    cout << "=   =   =  map iterators test =   =   =   =\n\n";

    Map < string, int> m;

    int size = sizeof( arr ) / sizeof( arr[ 0 ] );
    for ( int i = 0; i < size; i++ )
        m.insert( str[i], arr[i]) ;

    cout << "   =   =   =   Map    =   =   =   =\n" << endl;
    cout << m << endl;

    Map<string, int >::Iterator it;
    cout << "Map Iterators print" << endl;
    for ( it = m.begin(); it != m.end(); it++  )
    {
        cout << "[" << *it << "]" << "->";
    }
    cout << "|||" <<  endl << endl;

    cout << "   =   =   =   =   LOWER AND UPPER BOUNDS   =   =   =   =\n";

    cout << "m.lower_bound(\"Mar\" ) " << *m.lower_bound("Mar") << endl;
    cout << "m.upper_bound(\"Mar\" ) " << *m.upper_bound("Mar") << endl;
    /// ================================================================
    cout << "m.lower_bound(\"Jun\" ) " << *m.lower_bound("Jun") << endl;
    cout << "m.upper_bound(\"Jun\" ) " << *m.upper_bound("Jun") << endl;
    /// ================================================================
//    cout << "m.lower_bound(\"May\" ) " << *m.lower_bound("May") << endl;
//    cout << "m.upper_bound(\"May\" ) " << *m.upper_bound("May") << endl;
//    /// ================================================================
//    cout << "m.lower_bound(\"Apr\" ) " << *m.lower_bound("Apr") << endl;
//    cout << "m.upper_bound(\"Feb\" ) " << *m.upper_bound("Feb") << endl;
//    /// ================================================================
//    cout << "m.upper_bound(\"Monday\") " << *m.upper_bound("Monday")<<endl;
//    cout << "m.lower_bound(\"Monday\") " << *m.lower_bound("Monday")<<endl;

    cout << "   =   =   =   =   =   EQUAL RANGE =   =   =   =   =   =\n";
    cout << "m.equal_range(\"Mar\" ) " << endl;

    Pair<Map<string, int >::Iterator,Map<string, int >::Iterator> pit;
    pit = m.equal_range("Mar");
    cout << *pit.key <<  "    " << *pit.value << endl;

    cout << "=   =   = EXITING map iterators test =   =   =   =\n\n";
}

void map_modifiers_test( )
{
    cout << "=   =   =  map modifiers test =   =   =   =\n\n";
    Map < string, int> m;

    int size = sizeof( arr ) / sizeof( arr[ 0 ] );
    for ( int i = 0; i < size; i++ )
        m.insert( str[i], arr[i]) ;


    cout << "m.get( September ) " << m.get( "Septemeber") << endl;
    cout << m << endl << endl;


    cout << "m.erase ( July ) " << endl;
    m.erase("July");
    cout << m << endl << endl;

    cout << "m.clear( ) " << endl;
    m.clear();
    cout << "   =   =   =   Map    =   =   =   =" << endl;
    cout << m << endl << endl;

    cout << "=   =   = EXITING map modifiers test =   =   =   =\n\n";

}

void map_operations_test( )
{
    cout << "=   =   =  map operations test =   =   =   =\n\n";
    Map < string, int> m;

    int size = sizeof( arr ) / sizeof( arr[ 0 ] );
    for ( int i = 0; i < size; i++ )
        m.insert( str[i], arr[i]) ;

    cout << "\n=   =   =   = Map =   =   =   =   =\n\n";
    cout << m << endl << endl;

    cout << "m.find( Apr ):  " << *m.find( "Apr" ) <<  endl;
    cout << "m.find( Jun ):  " << *m.find("Jun") <<  endl;

    cout << "m.contains( (Jun, 30 )     " ;
    cout << ( m.contains( Pair<string, int> ( "Jun" , 30 ) )?
         "contains true": " contains false") << endl << endl;


    cout << "=   =   = EXITING map operations test =   =   =   =\n\n";

}

#endif // MAP_TEST_H
