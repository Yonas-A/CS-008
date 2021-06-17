
#include <iostream>
#include <string>

#include <stdint.h>   // for uint32_t
#include <string.h>


#include "../../!includes/STokenizer/stokenizer_table.h"
#include "../../!includes/Token/token_strings.h"


using namespace StokenizerTokens;
//=========================================================
//   FUNCTION DEFINITIONS
//=========================================================

string appendString( char temp[], const int start, const int end)
{
    string token;
    for ( int i = start; i <= end; i++ )
    {
        token += temp[i];
    }
    return token;
}

// =======================================================================
// initializer
// =======================================================================

void initialize( int table[ ][ COL ],int row, int col )
{
    for ( int i = 0; i < row; i++)
    {
        for ( int j = 0; j < col; j++ )
        {
            table[ i ][ j ] = -1;
            /// initializing array elements to -1 and
            /// set col 0 to state 0 / fail state
        }
        //        set_fail( table, i );
    }
    for (int i = 0; i < ROW; i++)
    {
        set_fail(table, i);
    }
}
// =======================================================================
// state markers
// =======================================================================

void mark_cells( int row, int table[][COL], range r, int state )
{
    for( char col = r.start ; col <= r.end; col++ )
    {
        table[ row ][ col ] = state;
    }
}

void mark_cells(int row, int table[][COL], char column[], int state)
{
    for( unsigned int i = 0  ; i < strlen(column); i++)
    {
        char temp = column[i];
        table[ row ][ int( temp ) ] = state;
    }
}

// =======================================================================
// success and fail state setters

void set_success(int table[][COL], int row)
{
    // set table at column 0 and row = row to 1 / success
    table[ row ][ 0 ] = 1;
}

void set_fail(int table[][COL], int row)
{
    // set table at column 0 and row = row to 0 / fail
    table[ row ][ 0 ] = 0;
}


//==================================================================
// machine state markers
//==================================================================

void mark_alpha(int table[][COL])
{
    // alpha takes us from state 0 to 5 and from 5 it loops on itself
    mark_cells( 0,table, range{'A', 'Z'} ,static_cast<int>(TokenType::ALPHA));
    mark_cells( 5,table, range{'A', 'Z'} ,static_cast<int>(TokenType::ALPHA));
    mark_cells( 0,table, range{'a', 'z'} ,static_cast<int>(TokenType::ALPHA));
    mark_cells( 5,table, range{'a', 'z'} ,static_cast<int>(TokenType::ALPHA));
    set_success( table, static_cast<int>(TokenType::ALPHA) );

    // ==============================================================
    ///single quotation and double quotation, spaces and dot
    mark_cells( 25 , table , range{'A', 'Z'} ,6 );
    mark_cells( 25 , table , range{'a', 'z'} ,6 );
    mark_cells( 6  , table , range{'A', 'Z'} ,6 );
    mark_cells( 6  , table , range{'a', 'z'} ,6 );
    mark_cells( 6  , table , (char*)" ." , 7 );
    mark_cells( 7  , table , range{'A', 'Z'} ,6 );
    mark_cells( 7  , table , range{'a', 'z'} ,6 );

    mark_cells( 6  , table , (char*)"'\"" , 5 );
    mark_cells( 5  , table , (char*)"'." , 5 ); /// separete state for it's
    mark_cells( 7  , table , (char*)"'\"." , 5 );
    /// for after ... L."

    // ==============================================================

}

void mark_integer( int table[][COL] )
{
    // integers takes us from state 0 to state 10 and from 10 loops around
    mark_cells( 0,table, range{'0','9'} , static_cast<int>(TokenType::INTEGER));
    mark_cells( 10,table,range{'0','9'},static_cast<int>(TokenType::INTEGER));
    set_success( table, 10 );

    /// \newcode for database where user says Salary = "100000"
    // ==============================================================
    /// double quotation, around numbers
    mark_cells( 25 , table , range{'0', '9'} , 13 );
    mark_cells( 13 , table , range{'0', '9'} , 13 );
    mark_cells( 13 , table , (char*)"\"" , static_cast<int>(TokenType::INTEGER) );

    // ==============================================================

}

void mark_double(int table[][COL])
{
    // decimal takes us from state 10 (integers ) to state 12 (doubles)
    mark_cells( 10 , table, "." , static_cast<int>(TokenType::DOUBLE) );
    mark_cells( 12 , table, "." , 10 );
    /// has same success state as integers
    mark_cells( 12 , table, range{'0', '9'} , 10 );

}

void mark_whiteSpace(int table[][COL])
{
    /// any white space takes us from state 0 to state 20
    mark_cells( 0, table, " \t\n", static_cast<int>(TokenType::WHITESPACE) );
    set_success( table, static_cast<int>(TokenType::WHITESPACE) );
}

void mark_punctuation ( int table[][COL] )
{
    // two conseccuitive punctuations are separate tokens
    mark_cells( 0 , table, "!\"#$%&'()*+,-./" ,25 ) ;
    mark_cells( 0 , table, ":;<=>?@" ,25 );
    mark_cells( 0 , table, "[\\]^_`" ,25 );
    mark_cells( 0 , table, "{|}~" ,25 );

    set_success( table, static_cast<int>(TokenType::PUNCTUATION) );
}


void mark_operators( int table[ ] [ COL] )
{
    mark_cells( 25 , table, "<=>" ,static_cast<int>(TokenType::OPERATOR) );
    set_success( table, static_cast<int>(TokenType::OPERATOR) );
    /// MARKING states for  <, > , == , >= and <= operators

    mark_cells( 25, table , "|&" , static_cast<int>(TokenType::OPERATOR) );
    set_success(table , static_cast<int>(TokenType::OPERATOR) );
    /// MARKING states for || and or operators
}

// ==================================================================
// display functions
// ==================================================================

void print( int table[][COL],int row, int col )
{
    for ( int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << table[i][j] << " " ;
        }
        cout << endl << endl;
    }
}
