#ifndef TABLE_TEST_H
#define TABLE_TEST_H

#include <cstring>
#include <iostream>
#include <vector>

#include <stdio.h>
#include <string.h>

#include "../../!includes/Table/table.h"

using namespace std;

typedef vector<string> vectorstr;
// =====================================================================

vectorstr records[] =
{{ "Del Rio",   "Jones" ,    "23",   "CS" ,      "IT",   "$020,000"  } ,
    { "Jane",   "Li",      "24",   "Math",     "MATH",   "$050,000"  } ,
    { "Steve",  "Booker",   "21",   "CS",       "IT",    "$070,000"  } ,
    { "Jack",   "Cork",     "19",   "Phys",     "PHY",   "$100,000"  } ,
    { "Steve",  "Bruce" ,   "31",   "Spy" ,     "FBI",   "$090,000"  } ,
    { "Betty",  "Tom",      "24",   "Science",  "CHEM",  "$090,000"  } ,
    { "Jack",   "Hugh" ,    "23",   "Bio",      "FDA",   "$080,000"  } ,
    { "Beth",   "Tom",      "19",   "Engin.",   "NASA",  "$120,000"  } } ;

vectorstr r[] =
  { { "Zack",   "Fred",     "29",   "Seal",     "NAVY",   "$120,000" },
    { "Albert", "Donald",   "25",   "P. Edu.",  "Health", "$200,000" } } ;

vector <string> FIELD_NAMES =
    { "First",    "Last",    "Age",    "Job",    "Dept",    "Salary" };


// =====================================================================


void test_table_big_three( );
// a test function for table copy ctor, assignment operator and d'tor

void test_table_constructors();
// a test function for Table :: CTOR

void test_select_where( );
// a test function for table select_where( )

void test_select( );



// =====================================================================
// =====================================================================
// =====================================================================
// =====================================================================

void test_table_big_three( )
{
    cout << "\n =   =   =   = test TABLE big three =   =  =  =   = \n\n";

    Table t ( "employee", FIELD_NAMES);
    for ( int i = 0 ; i < 8; i++ )
    {
        t.insert_into( records[i]);
    }
    cout << t << endl << endl << endl << endl;


    cout << "=  =   =   =   = copy ctor =   =   =   =   =   = \n\n";

    Table temp = (t);

    cout << temp << endl;
    temp.insert_into( r[1] );
    cout << temp << endl << endl;


    cout << "=  =   =   =   = assignment operator  =   =   =   =   =\n\n";
//    Table t2;
//    t2 = temp;
//    cout << t2 << endl;
//    t2.insert_into( r[0] );
//    cout << temp << endl << endl;
//    cout << t2 << endl << endl;


    cout << "\n =   =   = EXITING test TABLE big three ==  =  =   = \n\n";

}


void test_table_constructors( )
{
    cout << "\n =   =   =   = test TABLE Ctor =   =  =  =   = \n\n";

    Table t ( "employee");
    cout << t << endl << endl << endl << endl;


    Table table2 ( "employee_1", FIELD_NAMES);
    for ( unsigned int i = 0; i < 8 ; i++ )
    {
        table2.insert_into( records[i] ) ;
    }
    cout << table2 << endl << endl;
    table2.drop();


    cout << "\t=   =   =   EXITING TABLE Ctor test =   =   =   =\n\n\n";

}

void test_select_where( )
{
    cout << "\n\n =   =   =   = test select_where\t=   =   =   =\n\n";

    Table t ( "employee");
    cout << t << endl;

    cout << "\n =   =   =  select where( vector, vector) =   =   =\n";
    cout << "select last, first, age  from employee where last > fred" << endl;
    Table temp = t.select_where( {"Last", "First", "Age"},{"Last", ">", "Fred" });
    cout << temp << endl;
    temp.drop();

    cout << endl << endl << endl;

    cout << "\n\n =   =   =   = EXITING test select_where =   =  =  =   = \n";

}

void test_select( )
{
    cout << "\n =   =   = test select( vector<string>) =  =  =  = \n";

    Table t ( "employee");
    cout << t << endl << endl << endl << endl;

    cout << "\n =   =   =  select( {Last, height ,First, Age} ) =   =   =\n";
    Table temp = t.select( {"Last", "height", "First", "Age"} );
    cout << temp << endl;
    temp.drop();

    cout << "\n =   =   =  select( {Last, First, Age} ) =   =   =\n";
    Table table = t.select( {"Last", "First", "Age"} );
    cout << table << endl;
    table.drop();



    cout << "=  =  = EXITING  select( vector<string>) test =  =  =  = \n";

}


#endif // TABLE_TEST_H
