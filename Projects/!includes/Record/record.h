#ifndef RECORD_H
#define RECORD_H

#include <fstream>
#include <iostream>
#include <vector>

using namespace  std;

typedef vector<string> vectorstr;

class Record
{

public:

    // ==============================================================
    // constructors

    /// default
    Record( );

    /// a record that takes a vector of strings
    Record( const vectorstr& v );

    // ==============================================================
    // accessors

    /// @returns  a row of string record from a file
    vectorstr get_record( ) const;

    /// @returns a single string from a row of record
    vectorstr get_record( const int& index ) const;

    // ==============================================================
    // modifiers

    /// @returns a record number a row of record from a file after
    /// reading  a single row of record from this file
    long read( fstream& ins, long recno );

    /// writes a single record into a file and @return the record number
    /// of this record
    long write( fstream& outs );


    /// writes a single record into a file at positon recno and
    ///  @return the record numbernof this record
    long write( fstream& outs , long recno);


    // ==============================================================

    /// returns the number of fields a record has
    int number_of_fields( ) const ;

    // ==============================================================
    // insertion operator

    friend ostream& operator << ( ostream& outs, const Record& r );

private:

    static const int MAX_ROWS = 20;
    static const int MAX_COLS = 50;

    /// total fields/columns a given record will have
    int _num_of_fields;

    /// will carray the current string into a 2d array of record
    char record[ MAX_ROWS ][ MAX_COLS ];

    // ==============================================================
    // initializer
    /// initializes the record to null
    void initialize_record();
};


#endif // RECORD_H
