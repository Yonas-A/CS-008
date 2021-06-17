#include <iostream>
#include <cassert>
#include <string.h>
#include <stdio.h>

#include "../../!includes/STokenizer/stokenizer.h"
#include "../../!includes/STokenizer/stokenizer_table.h"
#include "../../!includes/Token/token_strings.h"

int STokenizer:: _table[MAX_ROWS][MAX_COLUMNS];

using  StokenizerTokens::Token;

// =============================================================
// default ctor

STokenizer::STokenizer( ): _length( -1 ), _pos( 0 )
{
    initialize_buffer();
    /// set elements of buffer to null
    make_table( _table );
    /// ready the table to run this input and tokenize it into words
}

// =============================================================
/// ctor with character array parameter

STokenizer::STokenizer( const char str[] ):_pos( 0 )
{
    initialize_buffer();
    /// set elements of buffer to null
    make_table( _table );
    /// ready the table to run this input and tokenize it into words
    set_string( str  );
    /// set input into the buffer
}

// =========================================================================

void STokenizer::set_string( const char str [ ] )
{
    /// \if input has more characters that what our max buffer can hold
    if ( strlen (str) > MAX_BUFFER )
    {
        _length = MAX_BUFFER - 1;
        /// set _length to max and only copy until this max
        /// the last index holds the null character '\0'
    }
    else
    {
        _length = strlen( str ) ;
    }
    _pos = 0;
    /// set the position to zero

    int i;
    for ( i = 0; i < _length ; i++ )
    {
        _buffer[ i ] = str[ i ] ;
    }
    _buffer [ i ] = '\0';
    /// set the last space at buffer with null character

    assert ( _buffer[ _length ] == '\0' && "buffer[ _length-1] != NULL");
    /// we must always make sure that the last character at buffer is null
}


// =========================================================================


bool STokenizer::done( ) const
{
    /// \if there are more tokens to be processed: \return false
    /// \else if there are no more tokens to process \return true
    return ( _pos > _length  );
}

bool STokenizer::more( ) const
{
    /// \if there are more tokens to be processed: \return true
    /// \else if there are no more tokens to process \return false

    return ( _pos <= _length );
}

// =========================================================================

STokenizer& operator >> ( STokenizer& s, StokenizerTokens::Token& t)
{
    string temp;
    int state = 0;
    bool more_Token = s.get_token ( state = 0, temp);

    if( more_Token )
        t = StokenizerTokens::Token( temp, state );
    else
        t = StokenizerTokens::Token();

    return s;
}

// ==================================================================
//      private initializer

void STokenizer::initialize_buffer( )
{
    for ( unsigned int row = 0; row < MAX_BUFFER + 5 ; row ++ )
        _buffer[ row ] = '\0';
        /// set each elements of buffer to null
}

void STokenizer::make_table( int _table[][ MAX_COLUMNS ])
{
    initialize( _table, MAX_ROWS, MAX_COLUMNS );
    /// initalize table to -1
    mark_alpha( _table );
    /// marks letter columns to 1
    mark_double( _table );
    /// marks double columns to 5
    mark_integer( _table );
    /// marks number columns to 5
    mark_punctuation( _table );
    /// marks punctuation columns to 15
    mark_operators( _table );
    /// marks >= <= or == operators
    mark_whiteSpace( _table );
    /// marks white space columns to 20
//    print( _table, MAX_ROWS, MAX_COLUMNS );
}

// ==================================================================
// private modifiers
bool STokenizer::get_token( int &state, string &token)
{
    const bool debug = false;

    if( _buffer[ _pos ] == '\0' ||  _pos > _length )
    {
        _pos = _length + 1;
        return false;
    }

    int current_state;
    int success_pos ;
    const int START_POS = _pos ;


    current_state = _table[ state ][ (int )_buffer[ _pos ] ];

    while( current_state != -1  && _buffer[_pos] != '\0' &&
          ( current_state < 100 && current_state >= 0 )         )
    {
        /// if current state is success ( marked by 1 );
        if( _table[ current_state ][ 0 ] == 1)
        {
            success_pos = _pos;
            /// current success pos = pos;
            state = current_state;
            /// the success tokens state is current state
        }

        if(debug)
        {
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n";
            cout << "proccessing input: " << _buffer[_pos] << endl;
            cout << "_pos: " << _pos << "\tsuccess_Pos: "
                 << success_pos << endl;
            cout << "current state: " << current_state
                 << "\tstate: " << state << endl;
            cout << "success/fail: "  << _table[ current_state ][0] << endl;
        }
        _pos++;
        current_state = _table[ current_state ][ (int )_buffer[ _pos ] ];

    }

    if( ( int )_buffer [ _pos]  < 0 )
    {
        // special cases for accented and unkown characters
        int temp = _pos;
        int start = _pos;
        int temp_state =  _table[ state ][ (int )_buffer[ _pos ] ];

        while( (int)_buffer [ _pos]  < 0 || temp_state != -1)
        {
            temp = _pos;
            _pos++;
            temp_state = _table[ state ][ (int )_buffer[ _pos ] ];
        }

        if( start >= START_POS)
            token =  appendString( _buffer, START_POS, temp);
        else
            token =  appendString( _buffer, start, temp);
        state = 0;
        return  true;
    }

    if( _pos - 1 > success_pos )
    {
        _pos = success_pos +1;
    }

    if ( success_pos <= _length )
    token =  appendString( _buffer, START_POS, success_pos);

    /// \newcode for database where "Jack" is just Jack"
    remove_quotations( token );
    return true;
}


void STokenizer::remove_quotations( std::string & token )
{
    if ( token[0] == '\"'  )
        /// delete the quotation mark at the front of token
        token.erase(0, 1);

    if ( token[ token.size() -1] == '\"' )
        token.resize( token.size() - 1);
    /// delete the quotation mark at the end of token

}
