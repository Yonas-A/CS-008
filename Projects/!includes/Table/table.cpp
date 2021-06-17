#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#include "../../!includes/Array_Functions/array_functions.h"
#include "../../!includes/Bin_File_functions/bin_file_functions.h"
#include "../../!includes/Map/BPlus_Tree/multimap.h"
#include "../../!includes/Pair/multipair.h"
#include "../../!includes/Record/record.h"
#include "../../!includes/RPN/rpn.h"
#include "../../!includes/Table/table.h"


/// filesstream being used
std::fstream finout;
/// \attention used for when a function uses a const reference of Table

/// extension used for files
const std::string Table::EXTENSION( ".bin" );
const std::string Table::DELETE_SIGN("*");
int Table::serial_num  = 1000;

using namespace  std;

// ==============================================================
// constructors

Table::Table ( ):record_num( 0 )
{

}

/// \todo \a

Table::Table( const string& n ): file_name(n),  record_num(0)
{
    const bool DEBUG = false;
    if ( DEBUG )
        cout << " >\tTable::Table( const string& n )" << endl;

    open_fileRW( _f, filename() );
    /// opening file to in a reading / writing mode
    Record rec;
    rec.read( _f , record_num++);
    /// read the first line from file which is the field names
    set_fields( rec.get_record( ) );
    /// set fields name vector
    _f.close();
    /// \attention always make sure to close file after openning a file
    build_indices();
    /// fill _indices from the already exisitng file (filename.bin)
}

/// \todo \a

Table::Table( const string& n, vector<string> fld ) :
                file_name(n), record_num(0),  empty(false)
{
    const bool DEBUG = false;
    if ( DEBUG )
        cout << " >\tTable::Table( const string& , vector<string> )" << endl;

    /// \newcode
    modify_fields_for_delete( fld );

    set_fields( fld );
    /// sets the fields into the field names member var
    int i = 0;
    if ( fld.front() == " " || fld.front() == DELETE_SIGN )
        i = 1;
    _indices.resize( fld.size()  - i );
    /// set vector _indicies size for all the multimaps it's store
    open_fileW( _f, filename() );
    /// open file in rewriting mode, erasing any existing records in it



    Record rec ( fld );
    record_num = rec.write( _f );
    /// write the field names in the file
    _f.close();
    /// \attention always close file afterwards
}

// ==============================================================
//copy ctor, assignment operator & dtor

Table::Table( const Table& OTHER)
{
    if ( const bool DEBUG = false )
        cout << "Table ( const Table& other )" << endl;

    file_name = OTHER.file_name;
    /// copy file name
    field_names = OTHER.field_names;
    /// copy all the field names of OTHER'S table
    field_order = OTHER.field_order;
    /// copy the field order map
    _indices = OTHER._indices;
    /// copy the _indicies multimap
    record_num = OTHER.record_num;

    empty = OTHER.empty;
}

Table& Table::operator =( const Table& RHS )
{
    if ( const bool DEBUG = false )
        cout << "Table:: operator =(const Table& RHS)" << endl;

    if ( this ==  &RHS ) // check if self and RHS are the same
        return *this;

    field_order.clear();    /// clear map
    for ( unsigned int i = 0; i < _indices.size() ; ++i )
         this->_indices[i].clear(); /// clear each mmap from _indices
    this->_indices.clear(); /// clear _indices itself

    this->file_name = RHS.file_name;        /// file name
    this->field_names = RHS.field_names;    /// field names
    this->record_num = RHS.record_num;      /// record numbers
    this->_indices = RHS._indices;          /// vector and mmap copy
    this->field_order = RHS.field_order;    /// map copy
    this->empty = RHS.empty;                /// bool empty
    return *this;
}

Table::~Table( )
{
    field_names.clear();
    /// clear the field names
    field_order.clear();
    /// clear the field orders

    for ( unsigned int i = 0; i < _indices.size() ; ++i )
         this->_indices[i].clear();
    _indices.clear();
    /// clear the mmap indicies and its vector
}

// ==============================================================
// modifiers

/// checked
void Table::drop( )
{
    char t_name[ filename().size() + 1 ];
    if( remove( strcpy ( t_name, filename().c_str() ))  != 0 )
    {
        char fail[ filename().size() + 100];
        string temp = "Error deleting " +filename() ;
        strcpy ( fail, temp.c_str() );
        perror( fail ); /// puts fail message on the screen
    }
    else
    {
        char success[ filename().size() +  100];
        string temp = filename() + " successfully deleted\n";
        strcpy ( success, temp.c_str() );
        puts( success ); /// puts success message on the screen
    }

}

void Table::delete_where( vector<string> conditions )
{
    vector <long> records_from_RPN = get_conditions_records( conditions);

    /// if vector records_from_rpn contains at least one record
    if ( ! records_from_RPN.empty( ) )
    {
        Record rec; /// holds a single row of record
        open_fileRW( _f, filename() );

        vector<string> vec; // a temporary vector to hol record
        /// create a new table with the same fields as this table's
        for ( unsigned i = 0; i <  records_from_RPN.size( ); i++ )
        {
            rec.read( _f, records_from_RPN[i] );
            /// read from file at record line records_from_RPN[i]
            vec = rec.get_record();
            vec.resize( field_names.size() );
            /// resize current vector to actual vector size with values
            vec[0] = DELETE_SIGN;
            /// change the first col
            Record temp ( vec );
            long test = temp.write( _f, records_from_RPN[i]  );
            /// write the current set of record onto the file at the end of the
            /// files current records,
            ///set record_num to record number of this newly inserted record
        }
        _f.close();
        /// close this table's file
    }

}

/// \todo \newcode \a
void Table::insert_into( vector<string> fields )
{
    open_fileRW( _f, filename( ) );
    /// open file in reading/writing mode to write a new record at the end

    /// \newcode
    modify_fields_for_delete( fields );

    Record rec ( fields );
    /// convert the string to a record of strings

    record_num = rec.write( _f );
    /// write the current set of record onto the file at the end of the
    /// files current records,
    ///set record_num to record number of this newly inserted record
    _f.close();

    update_indices( fields, long( record_num ) );
    /// update _indices to include current record
}

// ==============================================================
// accessors

///checked
bool Table::is_empty( )
{
    empty = _f.peek() == std::ifstream::traits_type::eof();;
    /// look at the file to see if it is empty or not
    return _f.peek() == std::ifstream::traits_type::eof();
}

/// checked
bool Table::get_error( ) const
{
    return _error;
}

/// checked
vector<long> Table::find_records( string field, string op, string name )
{
    /// if field exists in the field_order map, get its number
    unsigned int i =  int( );
    if ( field_order.contains( field) )
    {
        i = field_order[ field ];
        return lookup( i , op , name );
    }
    else
        return vector<long>();
}

/// checked
std::string Table::get_tablename() const
{
    return file_name;
}
// ==============================================================
// modifiers and accessors

/// checked
void Table::set_error( bool s )
{
    /// set mem variable _error to s;
    _error = s;
}

/// checked
Table Table::select_all( )
{
    Record rec;

    /// create a new table with the same fields as this table's
    Table t( generate_table_name(), field_names );

    open_fileRW( _f, filename() );

    int record_count = 1;
    /// read the first record after the field_names row from this table
    rec.read( _f, record_count++ );

    while ( ! _f.eof( ) )
    {
        vector<string> vec = rec.get_record();
        /// resize vec's size to match field_names size since we cannot
        /// have a table with multiple rows that have varying columns
        vec.resize( field_names.size() );
        t.insert_into( vec );
        rec.read( _f, record_count++ );
    }

    _f.close();
    /// close this table's file
    return t;
    /// return new table
}

/// checked
Table Table::select_all( const vector<std::string>& conditions )
{
    vector <long> records_from_RPN = get_conditions_records( conditions);

    Table t( generate_table_name(), field_names );

    /// records_from_rpn contains at least one records do select
    if ( ! records_from_RPN.empty( ) )
    {
        Record rec; /// holds a single row of record
        open_fileRW( _f, filename() );

        vector<string> vec; // a temporary vector to hol record
        /// create a new table with the same fields as this table's
        for ( unsigned i = 0; i <  records_from_RPN.size( ); i++ )
        {
            rec.read( _f, records_from_RPN[i] );
            /// read from file at record line records_from_RPN[i]
            vec = rec.get_record();
            vec.resize( field_names.size() );
            /// resize current vector to actual vector size with values
            t.insert_into( vec );
        }
        _f.close();
        /// close this table's file
    }
    ///\note t can be empty if records_from_rpn contains no records that
    ///     match the conditions
    return t;

}

/// \todo \newcode \a
Table Table::select_where(const vector<string>&fld, const vector<string>&cond )
{
    vector<long> temp;

    /// check if fields[i] exist as fields_names for this table
    if ( ! verify_fields( temp, fld) )
    {
        /// at least one entry from fields was not recognized
        ///  display error
        perror( "Table::select_where( vector<string>, vector<string>):"
                "\n\tcommand contains non existing field");
        Table t;
        /// create a table object witout any thing on it
        t.set_error( true );
        /// set _error of this table to indicate that this table is in
        /// error state
        return t; /// return new table
    }

    Table t( generate_table_name(), fld );
    /// create new table with the fields  from fld

    vector <long> records_from_RPN = get_conditions_records( cond );
    /// stores the records of conditons that were manipulated with RPN

    /// records_from_rpn contains at least one records do select
    if ( ! records_from_RPN.empty( ) )
    {
        Record rec; /// holds a single row of record
        open_fileRW( _f, filename() );

        /// create a new table with the same fields as this table's
        for ( unsigned int i = 0; i <  records_from_RPN.size( ); i++ )
        {
            vector<string> vec; // a temporary vector to hold record
            rec.read( _f, records_from_RPN[i] );
            /// read from file at record line records_from_RPN[i]
            for ( unsigned int j = 0; j < temp.size( ); j++ )
            {
                /// fill vec with records at columns specified by
                /// temp's value
                vec += rec.get_record( temp[j] );
            }

            /// \newcode
            modify_fields_for_delete( vec );
            /// add a delete column for new vector

            t.insert_into( vec );
        }
        _f.close();
        /// close this table's file
    }
    ///\note table t can be empty if records_from_rpn contains no records that
    ///     match the conditions
    return t;
}

/// checked
Table Table::select( const vector<string> &fields )
{
    /// holds the field's order that we want to identify
    vector<long> temp;

    /// check if fields[i] exist as fields_names for this table
    if ( ! verify_fields( temp, fields ) )
    {
        /// at least one entry from fields was not recognized
        ///  display error
        perror( "Table::select( vector<string> ):"
                "\n\tcommand contains non existing field");
        Table t;
        /// create a table object witout any thing on it
        t.set_error( true );
        /// set _error of this table to indicate that this table is in
        /// error state
        return t; /// return new table
    }

    Table t( generate_table_name(), fields );
    /// create a new table to store processed info

    Record rec;
    open_fileRW( _f, this->filename() );
    /// open the original file to read intended fields
    int record_count = 1;

    /// read the whole row from this table / file, increment record_num
    rec.read( _f , record_count++ );
    while ( ! _f.eof( ) )
    {
        vector<string> vec;
        /// reading a row of record and put it in a temp vector
        vector<string> hold = rec.get_record( );

        for ( size_t j = 0; j < fields.size() ; j++ )
        {
            /// select the desired record columns from temp,
            /// and push these records into vec
            vec.push_back( hold.at( temp[j] ) );
        }

        t.insert_into( vec );
        rec.read( _f, record_count ++ );
    }

    /// close current table's file
    _f.close();

    /// return new table
    return t;
}

// ==============================================================

/// checked
ostream& operator << ( ostream& outs, const Table& t)
{
    const bool DEBUG = false;

    cout << endl << "Table:: " << t.get_tablename() << "        "
         << "record: " << t.record_num << endl << endl;

    Record rec;
    open_fileRW( finout, t.filename( ) );
    /// open the file for reading
    int record_count = 0;
    rec.read( finout, record_count );
    /// read the first line on file

    while ( ! finout.eof( ) )
    {
        if ( record_count <= 0  )
        {
            vector<string> v = rec.get_record( );
            v[0] = "rec";
            v.insert( v.begin( ) + 1, "del");
            cout << v << endl;
            record_count++;
        }
        else {
            outs << "[" << record_count - 1 << "]\t\t" << rec.get_record( ) << endl;
            /// output current record to screen
            record_count++;
        }

        rec.read( finout, record_count );
    }
    finout.close(); /// \attention always close file after any operator

    if ( DEBUG )
        t.print_debug_indicies();
    /// also print the indicies multimap of this table
    return outs;
}

///\todo
void Table::print_debug_indicies() const
{
    for ( unsigned int i = 0 ; i < _indices.size(); i++ )
    {
        cout << "=  =   =   =  " << field_names[i+1] << " =   =   =   =\n"
             << _indices[i] << endl;
    }
}

// ==============================================================
// private member functions
// ==============================================================

// ==============================================================
// private accessors

/// \checked
std::string Table::filename( ) const
{
    /// return a table_name with the .bin extension
    return ( file_name + EXTENSION );
}

/// \checked
std::string Table::generate_table_name( )
{
    /// return a string with table_name + serial_num signiture
    return (  file_name + to_string( serial_num ++)  ) ;
}

/// \checked
vector<long> Table::get_conditions_records( const vector<string>& v)
{
    Shunting_Yard sh;
    /// a shunting yard class object that will convert vector v
    /// to infix expression
    sh.set_conditions( v );
    /// set shunting yard to this vector v

    RPN rpn ( sh.Post_Fix( ) );
    /// create an instance of a RPN class with a queue of token
    /// ShuntingYardTokens from sh Post_Fix return value

    vector<long> vector_record = rpn( *this );
    return vector_record;
    /// get the record numbers associated with
    /// conditions and return this vector
}

// ==============================================================
// private modifiers


///\todo \newcode \a
void Table::build_indices( )
{
    /// \attention MUST BE CALLED AFTER WE READ THE FILE'S/TABLES FIELD NAMES
    ///     SO THAT WE HAVE AN IDEA WHAT SIZE OUR INDICIES WHILL HAVE

    open_fileRW( _f, filename( ) );
    /// opening file to in a reading / writing mode
    /// \newcode
    assert( record_num == 1 && "Table::build_indices( ): record_num != 1");
    if ( ! is_empty( ) )
    {
        Record rec;
        /// set indicies size for max number of mmaps that'll be stored in it
        /// \newcode
        _indices.resize( field_names.size()  - 1 );
        /// since we are adding an empty col onto the record
        /// ignore this col when building our _indices mmap

        rec.read( _f , record_num); // record_num must be 1
        /// read a single row of record
        while ( ! _f.eof( ) )
        {
            vector<string> v = rec.get_record();
            /// push current record into a vector
            v.resize( field_names.size() );
            /// resize v to actual value size

            /// \remark since update indices takes care of the extra field
            /// no need to erase v.begin();
            update_indices( v, long( record_num ) );
            /// use update to actually fill _indicies
            record_num++;
            rec.read( _f, record_num );
        }
    }


    _f.close( );
}

/// \todo \newcode \a
void Table::set_fields( const vector<string>& str )
{
    field_names = str;
    /// copy string to field_names member var
    for ( unsigned int  i = 0 ; i < field_names.size() ; i++ )
    {
        if ( field_names[i] == "\0")
        {
            field_names.resize( i );
            /**
             * \note
             *  since the record object reads one whole row, we must
             *  check the actual size of the records to make sure
             *  that later it won't have any effect on our mmap
             */
            break;
        }
    }

    /// build field_order for field description and their column #
    /// \newcode this new line for updated record insert with " " or *
    for ( unsigned int  i = 1 ; i < field_names.size() ; i++ )
        field_order[ field_names[ i ] ] += long( i - 1 );
}


///\todo \newcode \a
void Table::update_indices( const vector<string> &s, const long & num)
{
    /// \newcode added after delete_table
    for ( unsigned int i = 1; i < s.size() ; i++ )
    {
        _indices[i - 1 ][ s[i] ] += long( num);
        /// fill indicies with the current record and its record number
    }
}

void Table::modify_fields_for_delete(  vector<string>& s )
{
    if ( s.front() != " " && s.front() != DELETE_SIGN )
        s.insert ( s.begin() , " " );
}

///checked
bool Table::verify_fields( vector<long> &v, const vector<string> &fld )
{
    v.clear();
    for ( unsigned i = 0 ; i < fld.size() ; i++ )
    {
        if ( field_order.contains( fld[i] ))
            /// if fld[i] exist in this table's field_order's map,
            /// push fld[i]'s correct column number into v
            v.push_back( field_order[ fld[ i ] ] );
        else
        {
            /// if at least one element from fld doesn't exist this table's
            /// field_order's map, clear v and return false
            v.clear();
            return false;
        }
    }

    return true;
}

///checked
vector<long>Table::lookup( const int& i, const string& op ,const string& data)
{
    vector<long> record_numbers;

    if ( op == "==" || op  == "=")
    {
        /// \if data exists in _indicies mmap, return its record numbers
        if ( _indices[i].contains( data ) )
            record_numbers = _indices[i].get( data );
    }

    else if( op == "<" )
    {
        MMap<string,long> ::Iterator it = _indices[i].begin( );

        ///  iterate from beginning of _indicies[i]  upto but
        ///  not including data's lower bound
        for (  ; it != _indices[i].lower_bound( data ) ; it++ )
        {
            /// add into vector record_numbers, the iterator's return
            /// value's vector_list ( the multipair's vector)
            record_numbers += (*it ).value_list;
            /// \note iterator's return value is a MPair<string, long>
            ///    so since we want the values vector values of this MPair,
            ///    we have to access the vector directly inorder to push it
            ///    into our vector<long> record_numbers
        }
    }

    else if( op == ">" )
    {
        MMap<string,long>::Iterator it = _indices[i].upper_bound(data);
        ///  iterate from upperbound of data thru end of _indices[i]
        for (  ; it != _indices[i].end( ) ; it++ )
        {
            /// add into vector record_numbers, the iterator's return
            /// value's vector_list ( MPair's vector of value_list )
            record_numbers += (*it ).value_list;
        }
    }

    else if( op == ">=" )
    {
        MMap<string,long> ::Iterator it = _indices[i].lower_bound(data);
        ///  iterate from lowerbound of data thru end of _indices[i]
        for (  ; it != _indices[i].end( ) ; it++ )
        {
            /// add into vector record_numbers, the iterator's return
            /// value's vector_list ( the multipair's vector)
            record_numbers += (*it ).value_list;
        }
    }

    else if( op == "<=" )
    {
        MMap<string,long> ::Iterator it = _indices[i].begin();
        ///  iterate from beginning of _indicies[i]  upto but
        ///  not including data's upper bound
        for (  ; it != _indices[i].upper_bound(data) ; it++ )
        {
            /// add into vector record_numbers, the iterator's return
            /// value's vector_list ( the multipair's vector)
            record_numbers += (*it ).value_list;
        }
    }

    return record_numbers;
    /// \note record numbers can be empty if data was not found
    /// in the multimpa at _indicies[i]
}

// ==============================================================
