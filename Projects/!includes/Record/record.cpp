#include <fstream>
#include <iomanip>
#include <iostream>

#include "../../!includes/Record/record.h"

using namespace  std;


// ==============================================================
// constructors

/// default ctor
Record::Record (): _num_of_fields( int() )
{
    initialize_record( );
    /// initialize the record object to null
}

Record::Record( const vectorstr& v ) : _num_of_fields ( v.size( ) )
{ /// set records field numbers to the size of input vectorstr

    /// initialize the record object to null
    initialize_record( );

    /// copying this vectorstr into the record member variable
    for ( size_t i = 0; i < v.size(); i++)
        strcpy( record[ i ], v[ i ].c_str( ) );

    if ( const bool DEBUG = false )
        cout << "Record(): num_of_fields " << _num_of_fields << endl;
}

// ==============================================================
// accessors

/// reads a whole record
vectorstr Record::get_record( ) const
{
    vectorstr v;
    for ( int i = 0; i < MAX_ROWS; i++ )
        v.push_back( string( record[ i ] ) );
    /// push the current record into a temporary vectorstr object

    return v;
    /// return the temp vector
}

/// reads a specific record from a line of records
vectorstr Record::get_record( const int& index ) const
{
    vectorstr v;
    v.push_back( string( record[ index ] ) );
    /// push the current record into a temporary vectorstr object

    return v;
    /// return the temp vector
}

// ==============================================================
// modifiers

/// reads a record from a file
long Record:: read( fstream &ins, long recno )
{
    long pos = recno * sizeof( record );
    /// find the current line to read
    ins.seekg( pos, ios_base::beg );
    /// seek the positon on which we can start reading a record from file
    ins.read( &record[ 0 ][ 0 ], sizeof( record ) );
    /// reading from the file the current record
    return ins.gcount();
}

/// writes a record onto a file
long Record::write( fstream &outs )
{
    outs.seekg( 0, outs.end );
    /// seek the end line in the file
    long pos = outs.tellp( );
    /// get the current positon
    outs.write( &record[ 0 ][ 0 ], sizeof( record ) );
    /// writing onto the file the current record
    return pos / sizeof( record );
    /// returning current records line number
}

/// writes a record onto a file
long Record::write( fstream &outs, long recno )
{
    long pos = recno * sizeof( record );
    /// find the current line to read
    outs.seekg( pos, ios_base::beg );
    /// get the current positon
    outs.write( &record[ 0 ][ 0 ], sizeof( record ) );
    /// writing onto the file the current record
    return pos / sizeof( record );
    /// returning current records line number
}

// ==============================================================
//
int Record::number_of_fields() const
{
    return _num_of_fields;
}

// ==============================================================
// insertion operator

ostream& operator << ( ostream& outs, const Record& r )
{
    for ( int i = 0; i < r._num_of_fields; i++ )
        outs << left << r.record[i] << "|";
    return outs;
}


// ==============================================================
//  private memeber functions
// ==============================================================
// initializer

void Record::initialize_record( )
{
    /// initializing record to null characters
    for ( unsigned int i = 0 ; i < MAX_ROWS ; i++ )
    {
        for ( unsigned int j = 0; j < MAX_COLS  ; j++ )
        {
            record[ i ][ j ] = '\0';
        }
    }
}

// ==============================================================
