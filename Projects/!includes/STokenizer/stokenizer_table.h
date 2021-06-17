#ifndef STOKENIZER_TABLE_H
#define STOKENIZER_TABLE_H
#include <iostream>
#include <string.h>

using namespace std;


const int COL = 128;
const int ROW = 30;

struct range
{
    /**
     * @brief  this'll tell us what our starting and ending
     *          characters are based on ascii values
     *         \example cmd_range { '0', '9' } means the range
     *          will go from '0' all the way through '9'
     */
    char start;
    char end;
};

string appendString( char temp[], const int start, const int end );
/**
 * @pre takes character array, two integers used as starting and ending points
 * @post \returns a string that's created from the array at start to end
 */

// =======================================================================
// initializer
// =======================================================================

void initialize( int table[ ][ COL ], int row, int col );
/**
 * @pre takes a 2d integer array, two integers that will be used to initialize
 *          the array
 * @post the array from [0][0] to [row][col] are set to a value of -1
 */

// =======================================================================
// state markers
// =======================================================================

void mark_cells( int row, int table[ ][ COL ], range r , int state );
/**
 * @pre \param  a 2d integer array, an integer index value, a character
 *              range and a const integer to mark table with
 * @post        array at this row and column of starting range thru
 *              ending range are set to state
 *              table[row][ start range  thru end range ] = state
 */


void mark_cells( int row, int table[ ][ COL ], char columns[ ], int state );
/**
 * @pre \param  a 2d integer array, an integer index value, a character
 *              array and a const integer to mark table with
 * @post        array at this row and column of first item of the char array
 *              to its last elemnt are set equal to state
 *              table[ row ][ columns [ first thru last element ] ] = state
 */

// =======================================================================
// success and fail state setters
// =======================================================================

void set_success( int table[][COL], int row);
/**
 * @pre  \param a 2d integer array, and an integer index value
 * @post        array at column 0 and this row ( table[0][row] ) are
 *              set to 1
 *              One is the succes state for this table which indicates
 *              that we are currently at a success state
 */

void set_fail( int table[ ][ COL ],  int row);
/**
 * @pre  \param a 2d integer array, and an integer index value
 * @post        array at column 0 and this row ( table[0][row] ) are
 *              set to 0
 *              Zero is the fail state for this table which indicates
 *              that the thing that brought us to this state is
 *              currently not on a success state
 */

//==================================================================
// machine state markers
//==================================================================

void mark_alpha( int table[ ][ COL ] );
/**
* @pre \param  a 2d integers array,
 * @post        array at a specific row & col is filled with a const
*              integer which will tell us that table[row][col] holds
*              a state for alpha numberical/ alphabets
*/

void mark_integer( int table[ ][ COL ] );
/**
* @pre \param  a 2d integers array,
 * @post       array at a specific row & col is filled with a const
*              integer which will tell us that table[row][col] holds
*              a state for integers/ whole numbers
*/

void mark_double( int table[ ][ COL ] );
/**
* @pre \param  a 2d integers array,
 * @post       array at a specific row & col is filled with a const
*              integer which will tell us that table[row][col] holds
*              a state for doubles/ decimals numbers
*/

void mark_whiteSpace( int table[ ][ COL ] );
 /**
 * @pre \param  a 2d integers array,
 * @post        array at a specific row & col is filled with a const
 *              integer which will tell us that table[row][col] holds
 *              a state for white spaces ( spaces, new lines )
 */

void mark_punctuation( int table[ ][ COL ] );
/**
 * @pre \param  a 2d integers array,
 * @post        array at a specific row & col is filled with a const
 *              integer which will tell us that table[row][col] holds
 *              a state for punctuations ( question marks, commans,
 *              hyphens, brackets, etc...)
 */

void mark_operators( int table[ ] [ COL] );
/**
 * @pre \param  a 2d integers array,
 * @post        array at a specific row & col is filled with a const
 *              integer which will tell us that table[row][col] holds
 *              a state for operators <=, >= , >>, << or ==
 */

// ==================================================================
// display functions
// ==================================================================

void print( int table[ ][ COL ], int row, int col );
/**
 * @pre \param  a 2d integer array, and two integers used for index
 *              values to end
 * @post        array from  table[0][0] thru table[row][col] are
 *              displayed on the screen
 */



#endif // STOKENIZER_TABLE_H
