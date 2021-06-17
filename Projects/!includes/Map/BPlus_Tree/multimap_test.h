#ifndef MULTIMAP_TEST_H
#define MULTIMAP_TEST_H

#include <iostream>

#include "../../!includes/BPlus_Tree/bplus_tree.h"
#include "../../!includes/Map/BPlus_Tree/multimap.h"
#include "../../!includes/Pair/multipair.h"

 const string STR[] = { "Math" , "CS", "Art", "Chem", "Bio" };
 const vector<int> MATH = { 90, 89, 93, 22, 34, 32};
 const vector<int> CS = { 90, 89, 93, 56 };
 const vector<int> ART = { 10, 34, 89 };
 const vector<int> CHEM = { 190, 809, 93, 56 };
 const vector<int> BIO = { 31, 28 , 31, 31, 30 };

// ================================================================

string NAMES[] = { "Betty", "Jack", "Tom", "Li","Joe","Beth", "Jack" };
const vector<string> BETTY = { "Job: Pilot","color: Blue","Sport: Bowling" };
const vector<string> JACK = { "Job: Pilot","color: Blue","Sport: Bowling" };
const vector<string> TOM = { "Job: Officer","color: Green","Sport: Sprint" };
const vector<string> LI = { "Job: CEO","color: Yellow","Sport: Golf" };
const vector<string> JOE = { "Job: BIOLOGIST","color: Black","Sport: diving"};
const vector<string> BETH = { "Job: President","color: Pink","Sport: Soccer"};

// ================================================================

void simple_multimap_test();
// a test function for multimap class

void multimap_accessors_test();
// a test function for multimap bracket operators

void multimap_iterators_test();
// a test function fo multimap iterators

void multimap_modifiers_test();
// a test function for multimap erase, insert, clear and get

void multimap_operations_test();
// a test function for find and contains

// ================================================================
///                    FUNCTION DEFINITIONS
// ================================================================

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
    cout << "\n   =   =   =   MMap    =   =   =   =" << endl;
    cout << m << endl;

    cout << "inserting Jack with a different discription"
         << endl << "Jack: " << TOM << endl << endl;
    m.insert( NAMES[ 6 ], TOM );

    cout << "   =   =   =   MMap    =   =   =   =" << endl;
    cout << m << endl;



    vector<string> records = { "$20,000" , "$50,000", "$70,000" ,"$100,000" ,
                               "$90,000" , "$90,000" , "80,000", "$120,000"  };

    vector<int> rec = { 20000 , 50000 , 70000 , 100000 ,
                       90000 , 90000 , 80000, 120000  };

    MMap < string, int > multimap;

    for ( int i = 0; i < 8; i++ )
    {
        multimap.insert( records[i], i );
    }

    cout << multimap << endl;


    MMap<int,int> mmap;
    for ( int i = 0; i < 8; i++ )
    {
        mmap.insert( rec[i], i );
    }

    cout << mmap << endl;

    cout << "=   =   = EXITING simple multimap test =   =   =   =\n\n";

}

void multimap_accessors_test()
{
    cout << "=   =   =  multimap accessors test =   =   =   =\n\n";

    MMap < string, vector<int> > m;
    m[ STR[0] ] += MATH;            cout << m << endl << endl;

    m.insert( STR[1], CS ) ;
    m.insert( STR[2], ART ) ;
    m.insert( STR[3], CHEM ) ;
    m.insert( STR[4], BIO ) ;

    cout << "\n=   =   =   = Final MMap =   =   =   =   =\n\n";
    cout << m << endl << endl;


    cout << endl << m << endl << endl;
    cout << "m[history]: " << m["History"] << endl;
    cout << endl << m  << endl << endl;

    cout << "=  =  = EXITING multimap accessors test =  =  =\n\n";
}

void multimap_iterators_test( )
{
    cout << "=   =   =  multimap iterators test =   =   =   =\n\n";

    MMap < string, vector<int> > m;
    m[ STR[0] ] += MATH;
    m.insert( STR[1], CS ) ;
    m.insert( STR[2], ART ) ;
    m.insert( STR[3], CHEM ) ;
    m.insert( STR[4], BIO ) ;
    cout << "   =   =   =   MULTIMAP =   =   =   =\n" << endl;
    cout << m << endl << endl;

    MMap<string, vector<int> >::Iterator it;

//    cout << "Multimap Iterators print Map print" << endl << endl;
//    for ( it = m.begin(); it != m.end(); it++  )
//    {
//        cout << "[" << *it << "]" << "->";
//    }
//    cout << "|||" <<  endl << endl;


    cout << "   =   =   =   =   LOWER AND UPPER BOUNDS   =   =   =   =\n";
    cout << "m.lower_bound(\"Chem\" ): " << *m.lower_bound("Chem") << endl;
    cout << "m.upper_bound(\"Chem\" ): " << *m.upper_bound("Chem") << endl;
    /// ================================================================
    cout << "m.lower_bound(\"Art\" ):" << *m.lower_bound("Art") << endl;
    cout << "m.upper_bound(\"Art\" ): " << *m.upper_bound("Art") << endl;

    ///cout << "m.upper_bound(\"Betty\") " << *m.upper_bound("Betty") << endl;
    ///cout << "m.lower_bound(\"Betty\") " << *m.lower_bound("Betty") << endl;

    cout << "   =   =   =   =   =   EQUAL RANGE =   =   =   =   =   =\n";
    cout << "m.equal_range(\"Chem\" ) " << endl;
    MPair< MMap<string, vector<int> >::Iterator,
           MMap<string, vector<int> >::Iterator> pit;
    pit = m.equal_range("Chem");
    cout << *pit.key <<  "    " << &pit.value_list  << endl;

    cout << "=   =   = EXITING  multimap iterators test =   =   =   =\n\n";

}

void multimap_modifiers_test()
{
    cout << "=   =   =  multimap modifiers test =   =   =   =\n\n";

    MMap < string, vector<int> > m;
    m.insert( STR[0], MATH );
    m.insert( STR[1], CS ) ;
    m.insert( STR[2], ART ) ;
    m.insert( STR[3], CHEM ) ;
    m.insert( STR[4], BIO ) ;

    cout << "\n=   =   =   = Final MMap =   =   =   =   =\n\n";
    cout << m << endl << endl;

    cout << "get( History ): " <<  m.get("History") << endl;
    cout << m << endl << endl;

    cout << "m.erase ( Math ) " << endl;
    m.erase("Math");
    cout << m << endl << endl;

    cout << "m.clear( ) " << endl;
    m.clear();
    cout << "   =   =   =   MultiMap    =   =   =   =" << endl;
    cout << m << endl << endl;

    cout << "=   =   = EXITING multimap modifiers test =   =   =   =\n\n";

}

void multimap_operations_test( )
{
    cout << "=   =   =  test multimap operation  =   =   =   =\n\n";

    MMap < string, vector<int> > m;
    m.insert( STR[0], MATH ) ;
    m.insert( STR[1], CS ) ;
    m.insert( STR[2], ART ) ;
    m.insert( STR[3], CHEM ) ;
    m.insert( STR[4], BIO ) ;

    cout << "\n=   =   =   = Final MMap =   =   =   =   =\n\n";
    cout << m << endl << endl;

    m.find("Math") ;
    cout << "m.find( Math )" << *m.find("Math") <<  endl;

    cout << "m.contains( Art )" << endl ;
    cout << ( m.contains("Art")? "contains true": "contains false")<< endl;

    cout << "=   =   = EXITING multimap operation test =   =   =   =\n\n";

}

#endif // MULTIMAP_TEST_H
