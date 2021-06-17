#ifndef MULTI_MAP_TEST_H
#define MULTI_MAP_TEST_H

#include <iostream>

#include "../../!includes/B_Tree/b_tree.h"
#include "../../!includes/Map/B_Tree/multimap.h"
#include "../../!includes/Pair/multipair.h"

 const string STR[] = { "Math" , "CS", "Art", "Chem", "Bio" };
 const vector<int> MATH = { 90, 89, 93, 22, 34, 32};
 const vector<int> CS = { 90, 89, 93, 56, 81, 45, 22, 34, 32};
 const vector<int> ART = { 10, 34, 89, 93, 56, 32, 81, 45, 22, 34};
 const vector<int> CHEM = { 190, 809, 93, 56, 801, 45, 22, 34, 32};
 const vector<int> BIO = { 31, 28 , 31, 31, 30, 303, 56, 81, 45, 22, 34, 32};


string NAMES[] = { "Betty", "Jack", "Tom", "Li","Joe","Beth", "Jack" };
const vector<string> BETTY = { "Job: Pilot","color: Blue","Sport: Bowling" };
const vector<string> JACK = { "Job: Pilot","color: Blue","Sport: Bowling" };
const vector<string> TOM = { "Job: Officer","color: Green","Sport: Sprint" };
const vector<string> LI = { "Job: CEO","color: Yellow","Sport: Golf" };
const vector<string> JOE = { "Job: BIOLOGIST","color: Black","Sport: diving"};
const vector<string> BETH = { "Job: President","color: Pink","Sport: Soccer"};



void test_multi_pair_struct();
 // a test function for multi pair struct

void simple_multimap_test();
// a test function for multimap class

void test_multimap_operators( );
// a function to test multimap operators and functions

// ================================================================
///                    FUNCTION DEFINITIONS
// ================================================================

void test_multi_pair_struct()
{
    cout << "=   =   =  multi pair struct test =   =   =   =\n\n";
    BTree< MPair<string, int> > m;
    m.insert( MPair <string, int>( STR[0], MATH )) ;
    m.insert( MPair <string, int>( STR[1], CS )) ;
    m.insert( MPair <string, int>( STR[2], ART )) ;
    m.insert( MPair <string, int>( STR[3], CHEM )) ;
    m.insert( MPair <string, int>( STR[4], BIO )) ;

    cout << "\n=   =   =   = Tree =   =   =   =   =\n\n";
    cout << m << endl << endl;
    cout << "\n=   =   =  EXITING multi pair test =   =  =\n\n";
}

void simple_multimap_test()
{
    cout << "=   =   = simple multimap test =   =   =   =\n\n";

    MMap < string, vector<string> > m;
    m.insert( NAMES[ 0 ], BETTY );
    m.insert( NAMES[ 1 ], JACK );
    m.insert( NAMES[ 2 ], TOM );
    m.insert( NAMES[ 3 ], LI );
    m.insert( NAMES[ 4 ], JOE );
    m.insert( NAMES[ 5 ], BETH );


    assert ( m.is_valid() && "Map not valid" );
    cout << "\n   =   =   =   TREE    =   =   =   =" << endl;
    cout << m << endl;

    cout << "inserting Jack with a different discription"
         << endl << "Jack: " << TOM << endl << endl;
    m.insert( NAMES[ 6 ], TOM );

    cout << "   =   =   =   TREE    =   =   =   =" << endl;
    cout << m << endl;
    cout << "=   =   = EXITING simple multimap test =   =   =   =\n\n";

}

void test_multimap_operators()
{
    cout << "=   =   =  multimap operators test =   =   =   =\n\n";

    MMap < string, vector<int> > m;
    m.insert( STR[0], MATH ) ;
    m.insert( STR[1], CS ) ;
    m.insert( STR[2], ART ) ;
    m.insert( STR[3], CHEM ) ;
    m.insert( STR[4], BIO ) ;
    cout << "\n=   =   =   = Final MMap =   =   =   =   =\n\n";
    cout << m << endl << endl;


    cout << "m.contains( July )" << endl << endl;
    cout << ( m.contains("July")? "contains true": "contains false")<< endl;


    cout << "get( Math ): " <<  m.get("Math") << endl;
    cout << "[Math]: " << m["Math"] << endl;

    cout << endl << m << endl << endl;
    cout << "[history]: " << m["History"] << endl;
    cout << endl << m  << endl << endl;


    cout << "m.empty( )" << endl << endl;
    cout << ( m.empty( )? "mmap empty": "mmap not empty")<< endl;
    cout << m << endl << endl << endl;

    cout << "m.erase ( Math ) " << endl;
    m.erase("Math");

    cout << "   =   =   =   =    Final Tree =   =   =   =   =" << endl;
    cout << m << endl;
//    cout << "[Math]: " << m["Math"] << endl;

    cout << "m.count ( Math ) " << m.count ( "Math") << endl << endl;

    cout << m << endl;
    cout << "=   =   = EXITING multimap operator test =   =   =   =\n\n";

}


#endif // MULTI_MAP_TEST_H
