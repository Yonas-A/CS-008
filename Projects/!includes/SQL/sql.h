#ifndef SQL_H
#define SQL_H

#include <iostream>

#include "../../!includes/Enums/enumerations.h"
#include "../../!includes/Map/BPlus_Tree/map.h"
#include "../../!includes/Map/BPlus_Tree/multimap.h"
#include "../../!includes/Parser/parser.h"
#include "../../!includes/Queue/queue.h"
#include "../../!includes/STokenizer/stokenizer.h"
#include "../../!includes/State_Machine/command_line_table.h"
#include "../../!includes/Table/table.h"

class SQL
{

public:

    // =============================================================
    // ctor

    SQL( );

    // =============================================================
    //copy ctor, assignment operator & dtor

//    SQL ( const SQL& other );

//    SQL& operator = ( const SQL& other );

    ~ SQL();

    // =============================================================

    /// oversees all the actions of sql
    void run(  bool state = true );

    /// reads input from file and returns command to run
    void batch( );

    /// reads input from console
    void console( );

    /// takes a character of strings of command, calls Parser on this
    /// command, and in return gets a multimap of parser commands which
    /// it calls other functions based on the command type
    void parse_command( char cmd [ ] );

    // =============================================================
    // Table/Database modifiers

    /// \returns true if a database was created based on given
    ///          conditions or
    /// \returns false if an error occured when creating a new database
    bool create( MMap<string, string> &ptree );
    /// oversees the create command to create a new database with given
    /// fields

    /// \returns true if a record was erased from current database
    ///          based on the certain conditions OR
    /// \returns false if an error occured when erasing a record
    ///          from a database
    bool delete_table( MMap<string, string> &ptree );
    /// oversees the delete where command to erase a record from
    /// an existing database

    /// \returns true if the database was erased/ .bin file was erased
    /// \returns false if an error occured when database/ .bin file
    bool drop( MMap<string, string> &ptree );
    /// oversees the drop command to erase a database/ table object
    ///  and its associated binary file from disk

    /// \returns true if a record was inserted without failure into
    ///          the database
    /// \returns false if an error occured when inserting a record
    ///          into the database / table
    bool insert( MMap<string, string> &ptree );

    /// \returns true if a new database was made based on given
    ///          conditions
    /// \returns false if an error occured when creating a new database
    bool make( MMap<string, string> &ptree );
    /// oversees the make command to create a new database with given
    /// fields

    /// \returns true if a record was erased from current database
    ///          based on the certain conditions OR
    /// \returns false if an error occured when erasing a record
    ///          from a database
    bool select( MMap<string, string> &ptree );
    /// oversees the select and select where commands to
    /// perform the required action

    // =============================================================

    /// holds the startup file name from which _sql_table reads table
    /// names and builds _sql_table with table names and table
    static const string STARTUP_FILE;
    static const string BATCH_FILE;

private:

    /// stores current input from console or input file
    string _sql_command;

    /// a parser object that oversees command parsing of new inputs
    Parser _parser;

    /// a map of string and table that stores table objects and their
    /// table/file name
    Map<std::string, Table> _sql_table;


    ///  true if an error occured while performing an action
    ///  false if no error occured
    bool _fail;

    static const bool DEBUG = false;

    // =============================================================
    // private initializer

    /// opens a text file and reads the table names and initializes
    /// several tables with the names
    void build_sql_table( );

    // =============================================================
    // private accessor

    /// opens a text file and reads the table names and initializes
    /// several tables with the names
    bool is_valid( ) const;

    /// writes the given command onto the screen
    void display_command( ) const;

    // =============================================================
    // private modifiers

    /// clears the debug folder \note used for debugging
    void clear_debug_folder( );

    /// when new tables are created, it updates the member variable
    /// _sql_table to include the newest table object and its
    /// table name
    void update_sql_table( const std::string& s, Table& t );

    /// removes a table from SQL member var _sql_table and
    /// deletes associated table name from file
    void remove_sql_table(const std::string& s);

};

#endif // SQL_H
