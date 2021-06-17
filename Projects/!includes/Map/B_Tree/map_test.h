#ifndef MAP_TEST_H
#define MAP_TEST_H

#include <iostream>

#include "../../!includes/B_Tree/b_tree.h"
#include "../../!includes/Map/B_Tree/map.h"
#include "../../!includes/Pair/pair.h"


const string str[] = { "Jan", "Feb", "Mar" , "Apr", "May", "Jun"};
const int arr[] = {31, 28 , 31, 31, 30, 30 };


void test_pair_struct();
// a test function for pair struct

void simple_map_test();
// a test function for map class

void test_map_operator();
// a test function for map bracket operator
// and at functions

// =============================================================
// =============================================================
//            test  Functions definition
// =============================================================
// =============================================================


void test_pair_struct()
{
    cout << "   =   =   = pair struct test =   =   =   =" << endl;

    BTree< Pair<string, int> > m;

    int size = sizeof( arr ) / sizeof( arr[ 0 ] );

    for ( int i = 0; i < size; i++ )
    {
        m.insert(  Pair <string, int>  (str[i], arr[i] ) ) ;
    }

    cout << "   =   =   =   FINAL TREE    =   =   =   =" << endl;
    cout << m << endl;

    cout << "\n   =   =   = EXITING pair test =   =   =   =\n" << endl;
}


void simple_map_test()
{

    Map < string, string> m;

    string color[] = { "Blue", "Yellow", "Red" , "Black", "Violet",
                         "Purple", "Pink", "Burgundy", "Veal", "Sapphire"};
    string name[] = { "Betty", "Jack", "Tom", "Li", "Joe",
                        "Beth", "Lily", "Jack" };
    int name_Size = sizeof ( name )/ sizeof ( name[ 0 ] );


    for ( int i = 0; i < name_Size; i++ )
    {
        if ( i + 1 == name_Size )
            cout << "testing + operator for pair in case"
                    " of duplicates" << endl << endl;
        m.insert(  name[i], color[i]) ;
        cout << "   =   =   = current tree  =   =   =   =" << endl;
        cout << m << endl;
        assert ( m.is_valid() && "Map not valid" );
    }



    cout << "   =   =   =   FINAL TREE    =   =   =   =" << endl;
    cout << m << endl;

    cout << "m [ PAUL ] =  Red" << endl << endl;
    m["PAUL"] = "Red";
    cout << m << endl;

    cout << m["PAUL"]  << "   calling PALU WITH operator []" << endl;
    cout << m << endl;

    cout << "chainging [ PAUL ] =  Red to Sapphire" << endl << endl;
    m["PAUL"] = "Sapphire";
    cout << m << endl;

    cout << "erase Joe" << endl << endl;
    m.erase("Joe");
    cout << m << endl;


    cout << "\n   =   = EXITING simple map test =   =   =\n" << endl;
}

void test_map_operator()
{
    Map < string, int> m;

    int size = sizeof( arr ) / sizeof( arr[ 0 ] );

    for ( int i = 0; i < size; i++ )
    {
        m.insert( str[i], arr[i]) ;
    }
    cout << "   =   =   =   FINAL TREE    =   =   =   =" << endl;
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
}


#endif // MAP_TEST_H
