#ifndef RECORD_TEST_H
#define RECORD_TEST_H

#include <fstream>
#include <iostream>

#include "../../!includes/Bin_File_functions/bin_file_functions.h"
#include "../../!includes/Record/1D-record/record.h"

using namespace std;


void record_test();
// a test function for record of a one dimensional array

// ========================================================
//              DEFINITIONS
// ========================================================

void record_test( )
{

    cout <<"\n\n=  =   =   =   =  RECORD TEST =   =   =   =   =\n\n";

    string list[10] = { "zero",  "one",  "two",   "three",  "four",
                        "five",  "six",  "seven",  "eight",  "nine"};
    fstream f;

    // reset the file:
    open_fileW( f, "record_list.bin" );

    for ( int i= 0 ; i < 10; i++ )
    {
        Record r( list[i] );
        int recno = r.write( f );
        cout << "[" << list[i] << "]\t" <<  " was written into file"
             << " as record: "<< recno << endl;
    }
    cout << endl << endl << "=  =   =   =   =   = " << endl << endl;

    f.close(  );



    Record r;
    //open the file for reading and writing.
    open_fileRW( f, "record_list.bin"  );

    r.read( f, 3 );
    cout << "record 3: " << r << endl;
    r.read( f, 6 );
    cout << "record 6: " << r << endl;

    cout <<"\n\n=  =   =   =   Exiting Record Test ]  =   =   =   =\n\n";

}


#endif // RECORD_TEST_H
