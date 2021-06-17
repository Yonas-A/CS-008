
#include <fstream>
#include <iostream>

#include <string.h>

#include "../../!includes/FTokenizer/ftokenizer.h"
#include "../../!includes/STokenizer/stokenizer.h"

// =======================================================================
//  CTOR

FTokenizer::FTokenizer(char* fName):_stk(), _pos(0), _blockPos(0)
{
    open_file(fName);
    /// open file
    _more = true;
    /// set more to true
    get_new_block();
    /// get a block of text from the file to process
}

// =======================================================================
Token FTokenizer::next_token()
{
    Token t;
    _stk >> t;
    /// get a token from STOKENIZER:: _buffer

    if( _stk.done( ) )
    {
        _blockPos = 0;
        if ( get_new_block() )
        {
            _pos = _f.tellg();
            _stk >> t;
        }
        else /// there is no more block of token to grab
            _more = false;
    }
    return t;
}

int FTokenizer::block_pos( ) const
{
    return _blockPos;
}

int FTokenizer::pos( ) const
{
    return _pos;
}

bool FTokenizer::more( ) const
{
    return _more;
}

bool FTokenizer::open_file(char* fName)
{
    _f.open( fName );
    if( _f.fail( ))
    {
        cout << "file did not open!" << endl;
        return -2;
    }
    return true;
}

FTokenizer& operator >> ( FTokenizer& f, Token& t )
{
    t = f.next_token();
    /// read a token from Ftokneizers _buffer
    f._blockPos += t.get_string_token().size() ;
    /// set the blockpos to the sum of itself and current token's size
    return f;
}

bool FTokenizer::get_new_block()
{
    const bool DEBUG = false;

    char temp[ MAX_BLOCK  ] ;
    /// a temporary array to hold a bock of chars from file
    _f.read( temp, MAX_BLOCK - 1  );
    /// read a maximum of 499 characters
    temp[ _f.gcount()  ] = '\0';
    /// set the last element to null
    _stk.set_string( temp );
    /// copy the current input into STOKENIZER:: _buffer

    if ( DEBUG )
    {
        cout << "Ftoken::get_new_block: _gcount: " << _f.gcount( ) << endl;
    }

    if ( _f.gcount() == 0)
    {
        _f.close();
        return false;  //there was nothing to get.
    }

    return true; //we did, in fact get a block of chars.
}











