#ifndef RECORD_TEST_H
#define RECORD_TEST_H

#include <fstream>
#include <iostream>

#include "../../!includes/Bin_File_functions/bin_file_functions.h"
#include "../../!includes/Record/record.h"

using namespace std;

// ========================================================================
const vector <string> field_names = {"First", "Last", "Age", "Job"};

const vectorstr records[4] = { { "BOB",  "jones", "23" ,"CS" },
                               { "Jane", "Doe", "24", "Math" },
                               { "Steve", "Booker", "21", "CS" },
                               { "Jack", "Thompson", "19", "Phys" }  };
//========================================================================

void record_test( );
// test function for record with a record of 2 dimensional array

void record_test_manually();

// ========================================================
//              DEFINITIONS
// ========================================================


void record_test()
{
    cout <<"\n\n=  =   =   =   Record Test   =   =   =   =\n\n";

    fstream f;
    open_fileW( f, "record_list.bin");

    Record rec( field_names);
    int record_num = rec.write(f);
    f.close();

    open_fileRW(f, "record_list.bin");

    for (int i = 0; i < 4; i++)
    {
        Record rec( records[i]);
        record_num = rec.write( f );
        cout << "record_num " << record_num << endl;
    }

    f.close();
    cout << "record_num: " << record_num  << endl;
    cout <<"\n\n************************************************ \n\n";


    Record r;
    open_fileRW( f, "record_list.bin" );
    int recno = 0;
    while ( !f.eof( ) )
    {
        r.read(f, recno);
        recno++;
        cout << "[" << recno << "]\t" << r.get_record( ) << endl;
    }


    cout <<"\n\n=  =   =   =   Exiting Record_2D Test ]  =   =   =   =\n\n";

}

void record_test_manually ()
{
    cout <<"\n\n=  =   =   =   Record Test manually  =   =   =   =\n\n";

    fstream f;
    open_fileW( f, "record_description.bin");

    Record rec( field_names);
    int record_num = rec.write(f);
    f.close();
    cout << "record_num: " <<  record_num << endl;

    cout <<"\n\n************************************************ \n\n";


    Record r;
    open_fileRW( f, "record_description.bin" );
    int recno = 0;
    while ( !f.eof( ) )
    {
        r.read(f, recno);
        recno++;
        cout << "[" << recno << "]\t" << r.get_record( ) << endl;
    }
    f.close();
// ==========================================================
    open_fileRW(f, "record_description.bin");
    Record r1( records[0]);
    record_num = rec.write( f );
    f.close();
    cout << "record_num: " <<  record_num << endl;

// ==========================================================

    open_fileRW(f, "record_description.bin");
    Record r2( records[1]);
    record_num = rec.write( f );
    f.close();
    cout << "record_num: " <<  record_num << endl;

// ==========================================================

    open_fileRW(f, "record_description.bin");
    Record r3( records[2]);
    record_num = rec.write( f );
    f.close();
    cout << "record_num: " <<  record_num << endl;

// ==========================================================

    open_fileRW(f, "record_description.bin");
    Record r4( records[3]);
    record_num = rec.write( f );
    f.close();
    cout << "record_num: " <<  record_num << endl;

// ==========================================================


    cout <<"\n\n************************************************ \n\n";


//    Record r;
    open_fileRW( f, "record_description.bin" );
    /*int */recno = 0;
    while ( !f.eof( ) )
    {
        r.read(f, recno);
        recno++;
        cout << "[" << recno << "]\t" << r.get_record( ) << endl;
    }

    cout <<"\n\n=  =   =   =   Exiting Record_2D Test two =   =   =   =\n\n";

}

#endif // RECORD_TEST_H
