#pragma once

#ifndef TABLE_H
#define TABLE_H

#include <fstream>
#include <vector>

#include "../../!includes/Map/BPlus_Tree/map.h"
#include "../../!includes/Map/BPlus_Tree/multimap.h"

//enum EMPLOYEE_FIELDS { First = 0, Last = 1, Age = 2, Job = 3,
//                       Dept = 4, Salary = 5 };


using namespace  std;

class Table
{
public:

    // ==============================================================
    // constructors

    /// a default ctor
    Table ( );

    /// a ctor with a table/file name with an already existing binary file
    Table( const string& name );
    /**
      * creates a table with name, opens file name.bin and , builds
      *      _indicies mmap from  all the records on this file
      * \note a call to this ctor doesn't create a new file as it
      *       already has a file associated with its name. but this
      *       new Table object has access to this file whether to
      *       read from it or write onto it
      */

    /// a ctor with file name and field lists to write on file
    Table( const string& name, vector <string> field_names );
    /// creates a table with name, creates a new file with name.bin
    ///      and writes field_names on the file name.bin
    /// \note a call to this ctor creates a new Table as well as
    ///      a binary file with name.bin. Afterwards, any operation
    ///      whether reading from or writing onto this file is possible

    // ==============================================================
    //copy ctor, assignment operator & dtor

    Table( const Table& other);

    Table& operator =(const Table& RHS);

    ~Table();


    // ==============================================================
    // modifiers

    /// writes the vector fields onto this table's associated file and
    /// also updates _indicies multimap to include this new record
    void insert_into( vector<string> fields );
    /// \param a vector of strings that are records of a particular table
    ///        e.g last, first, age and department for a faculty table

    /// removes the binary file associated with this table object
     void drop( );

     /// removes  a row /rows of record from a table that meet the certain
     /// conditions stated by the vector<string> conditions
     void delete_where(vector<string> conditions );

    // ==============================================================
    // accessors

     /// \returns a vector of longs of records on this table for a given
     /// field and an operator e.g. find_records( "Lname", ">", "Jack")
     /// returns all the record numbers where lname is greater than jack
    vector<long> find_records( string field, string Operator,
                               string name );

    /// \returns the table name for  this table as string
    std::string get_tablename( ) const ;

    /// @brief file has only field lists, or file doesn't have anything
    /// return false
    /// @returns the value of empty member var
    bool is_empty( ) ;


    /// \returns true if  current table is in error state  or
    /// false if current table is not in error state
    bool get_error( ) const ;
    // ==============================================================
    // accessors and Modifiers

    /// sets memeber variable _error to s when an error occurs
    void set_error( bool s );

    /// \returns a new table with all the contents of this table and
    ///          a new file with 1000++.bin extension
    Table select_all( );

    /// \returns a new table with all the contents of this table and
    ///          that meet the conditions in the vector conditions or
    /// \returns a new table with only a list of field_names of this table
    Table select_all( const vector<std::string>& conditions );

    /// \returns a table with records based on fields of this table
    ///          if all elments of fld exist in field_orders map
    ///          of this table and conditions are meet  or
    /// \returns an empty table if at least one element of fld
    ///         does not exist in this table's field_orders map or
    /// \returns a new table with only a list of field_names of this table
    ///         if all elements of fld exist in this table but conditions
    ///         are not met
    Table select_where( const vector<string>& fld, const vector<string>& cond );

    /// \returns a table with records based on fields of this table
    ///          if all elments of fields exist in field_orders map
    ///          of this table or
    /// \returns an empty table if at least one element of fields
    ///         does not exist in this table's field_orders map
    Table select( const vector<string>& fields ) ;

    // ==============================================================
    // insertion operators and displays

    /// accesses table t' and opens the binary file associated with it
    ///  prints all the records of this table onto the screen /console
    friend ostream& operator << ( ostream& outs, const Table& t );

    /// prints the indicies onto the screen
    void print_debug_indicies( ) const;


    static const string EXTENSION;
    std::fstream _f;

private:

    /// refers to the sign we use to indicate a record has been deleted
    static const string DELETE_SIGN;

    static int serial_num;

    /// table name or filename
    string  file_name;

    /// the field list that are stored in the table
    vector<string> field_names;

    /// number of records stored in the table
    int record_num ;

    /// stores the record number and their names
    vector < MMap<string, long> > _indices;

    /// stores  field names with their corresponding ordering number
    ///  "first" = 0, "last" = 1 , "age" = 2   ...
    Map < string, long > field_order;

    ///  holds a bool indicating whether or not table contains any record
    bool empty;
     /// \if   table has no records or no record has been added to table
     ///       , empty = true
     /// \else record has been added , empty = false;

    /// holds a bool indicating whether current table is in error state

    bool _error;
    /// is set to true when errors occur such as non-existing fields
    /// for a condition
    // ==============================================================
    // private accessors

    /// \returns a string of the name of this Table with a signiture of .bin
    std::string filename( ) const ;

    /// @returns a table name with current table + serial_num signiture
    string generate_table_name( );
    /// a generates a new table name to instantiate a new table object

    /// \returns a vector of longs of records after v is converted
    /// into a post fix expression and run thru the shunting yard and RPN
    /// classes
    vector<long> get_conditions_records( const vector<string>& v);

    // ==============================================================
    // private modifiers

    /// reads a row of record from file and inserts a single col from this
    /// record and its record_number onto the _indices vector of mmap
    void build_indices( );

    /// sets the field_list to given vector str
    void set_fields( const vector<string>& str );

    /// inserts a single record and its corresponding record_number
    /// into the _indicies vector of multimap of this table
    void update_indices( const vector<string>& s , const long & num  );

    /// modifies input vector to include a space as the first element
    /// so that we can implement delete_where with ease
    void modify_fields_for_delete( vector<string> &s );

    /// \returns true if a all of elements of fld exist in the map
    /// field_orders and returns v with flds corresponding order numbers
    /// \returns false if at least a single element from fld does not
    /// exist in the map field_orders and  and returns v empty
    bool verify_fields( vector<long>& v , const vector<string>& fld);

    /// @returns a vector of long of record_numbers at _indicies[index]
    ///         that satisfy a given conditon or
    /// @returns an empty vector if conditions are not met
    vector<long> lookup(const int& i, const string& op, const string& data);
    /// \param int i: position in _indices where all types of data exist
    ///             eg. if i = 0 in employee table, data holds Last names
    /// \param string op:  a '<', ">=" , "<=" or "= / == " operators
    /// \param string data: any string that we are trying to find in the
    ///         table. eg any last names first names, ages ...  a record
    ///         eg. i = 5; op = "=" and data = "$50,000", we search
    ///          indicies[i] for any records that have equal values as data


};

#endif // TABLE_H
