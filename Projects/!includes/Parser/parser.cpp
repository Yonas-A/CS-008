
#include <iostream>

#include "../../!includes/Parser/parser.h"
#include "../../!includes/Enums/enumerations.h"
#include "../../!includes/Token/token_strings.h"


int Parser:: cmd_table[ CMD_MAX_ROWS ][ CMD_MAX_COLUMNS ];

// ==============================================================
// constructors

/// default ctor
Parser::Parser( ): _stk(), input_queue()
{
    build_keyword( );
    /// fill the _keyword multimap with commands and an int identifier
    make_cmd_table( cmd_table );
}

/// ctor with a c string of input command
Parser::Parser( char s[] ): _stk(), input_queue()
{
    build_keyword( );
    /// fill the _keyword multimap with commands and an int identifier
    make_cmd_table( cmd_table );
    /// ready the command line state machine
    set_string( s );
    /// call set string to do all the work
}

// ==============================================================
// accessors

MMap<string, string> Parser::get_parse_tree(  ) const
{
    ///\todo change name to get_ptree( );
    return  _ptree;
}

bool Parser::is_valid ( ) const
{
    /// if _flag = true ,
    return _flag;
}

// =======================================================================
// modifiers

void Parser::set_string( const char str [ ] )
{
    const bool DEBUG = false;
    if ( DEBUG )
        cout << "Parser:: set_string( const char str [ ] )\n\n";

    this->clear_parse();
    /// clear everyting previously used

    _input_string = str;
    /// copy the input string into our member var _buffer
    _stk.set_string( str );
    /// copy input string into stokenizer's _buffer

    StokenizerTokens::Token t;
    _stk >> t;
    /// tokenize current string
    while( !_stk.done() )
    {
        /// if current token is not a space or new line
        if ( t.get_type( ) !=
             static_cast<int>( StokenizerTokens::TokenType::WHITESPACE ))
        {
            input_queue.Push( t.get_string_token() );
            /// push current token in to a queue
            if ( DEBUG )
                cout << "string  " << t.get_string_token() << endl;
        }
        _stk >> t;
    }

    _flag = parse_tree();
    /// set flag to the success or failure of parsing command
}

bool Parser::parse_tree(  )
{
    const bool DEBUG = false;
    Queue<std::string> temp( input_queue );
    int keyword_NUM = 0;    /// a conversion from _keyword of string to numbers
    int success_state = 0;
    int state = 0;

    while( state != static_cast<int>(states::start) && ! temp.Empty() )
    {
        string str = temp.Pop();

        int debug_state = state;
        if ( _keyword.contains( str )  == false )
            keyword_NUM = 15;
        else
            keyword_NUM = _keyword[ str ];

//        ( _keyword.contains( str ) ? keyword_NUM = _keyword[str]: keyword_NUM = 15 );
        state = cmd_table[ state ][ keyword_NUM ];
        success_state = cmd_table[ state][0];


        if( DEBUG )
        {
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n";
            cout << "proccessing input: " << str << endl;
            cout << "inputs'  keyword value: " << keyword_NUM << endl;

            cout << "previous state: " << debug_state
                 << "\tstate: " << state << endl;
            cout << "success/fail: "  << cmd_table[ state ][0] << endl;
        }

        switch ( state )
        {
        case 1:
        case 41: /// using this case for drop command only
            _ptree["command"] += str;
            break;
        case 2:
        case 11:    /// using this case for insert command only
            _ptree["fields"] += str;
            break;
        case 4:
        case 34: /// using this for drop command only
            _ptree["table"] += str;
            break;
        case 6:
            _ptree["conditions"] += str;
            break;
         }
    }

    if ( DEBUG )
        cout << _ptree << endl << endl;

    if ( success_state == static_cast<int>( states::success ) )
        return true;  /// we have reached a success state

    _ptree.clear();
    return false; /// we have not reached a success state
}


void Parser::clear_parse( )
{
    _input_string.clear();
    // clear the input string

    input_queue.Clear( );
    /// clear the queue that holds tokenized input string
    _ptree.clear();
    /// clear the map that holds parsed sql commands

}

// ============================================================
// private initializer

void Parser::make_cmd_table ( int cmd_table[ ][ CMD_MAX_COLUMNS ] )
{
    initialize_cmd( cmd_table, CMD_MAX_ROWS, CMD_MAX_COLUMNS);
    fill_table( cmd_table );
//    print_cmd( cmd_table, CMD_MAX_ROWS, CMD_MAX_COLUMNS );

}

// ============================================================
// accessors

int Parser::get_column( const std::string &str )
{
    if ( _keyword.contains( str ) )
        return _keyword[ str ];
    /// \return  str's value from _keyword
    else
        return static_cast<int>( KEYWORDS::SYMBOL);
        /// \return  default value symbole = 15
}

// ============================================================
// private modifiers/initializers

void Parser::build_keyword( )
{
    /// map sql commands of strings with a defined integers
    _keyword[ "select" ] += static_cast<int>( KEYWORDS::SELECT );
    _keyword[ "*" ] += static_cast<int>( KEYWORDS::STAR );
    _keyword[ "from" ] += static_cast<int>( KEYWORDS::FROM );
    _keyword[ "make" ] += static_cast<int>( KEYWORDS::MAKE );
    _keyword[ "create" ] += static_cast<int>( KEYWORDS::CREATE );
    _keyword[ "batch" ] += static_cast<int>( KEYWORDS::BATCH );
    _keyword[ "where" ] += static_cast<int>( KEYWORDS::WHERE );
    _keyword[ "update" ] += static_cast<int>( KEYWORDS::UPDATE );
    _keyword[ "delete" ] += static_cast<int>( KEYWORDS::DELETE );
    _keyword[ "insert" ] += static_cast<int>( KEYWORDS::INSERT );
    _keyword[ "drop" ] += static_cast<int>( KEYWORDS::DROP );
    _keyword[ "into" ] += static_cast<int>( KEYWORDS::INTO );
    _keyword[ "table" ] += static_cast<int>( KEYWORDS::TABLE);
    _keyword[ "fields" ] += static_cast<int>( KEYWORDS::FIELDS);



}

// ============================================================
