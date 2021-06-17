#ifndef COMMAND_LINE_TABLE_H
#define COMMAND_LINE_TABLE_H

#include <iostream>
#include <string>

using namespace std;


const int CMD_COL = 40;
const int CMD_ROW = 50;

enum class states:int { success = 1, fail = 0, start = -1 };


struct cmd_range
{
    /**
     * @brief  this'll tell us the starting and ending characters
     *         based on ascii values
     *         \example cmd_range { '0', '9' } means the cmd_range
     *          will go from 0 , 1, 3, all the way thru 9
     */
    const char start;
    const char end;
};

// =======================================================================
// initializer
// =======================================================================

void initialize_cmd( int table[][CMD_COL], int row, int col ) ;
/**
 * @pre takes a 2d integer array, two integers that will be used to initialize
 *          the array
 * @post the array from [0][0] to [row][col] are set to a value of -1
 */

// =======================================================================
// state markers
// =======================================================================

void mark_cells( int table[][CMD_COL], int row, cmd_range r, int state );
/**
 * @pre \param  a 2d integer array, an integer index value, a character
 *              range and an const int to mark table with
 * @post        array at this row and column of starting range thru
 *              ending range are set to state
 *              table[row][ start range  thru end range ] = state
 */

void mark_cells(int table[][CMD_COL], int row, char columns[], int state );
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

void set_success(int table[][CMD_COL], unsigned int row );
/**
 * @pre  \param a 2d integer array, and an integer index value
 * @post array at column 0 and this row ( table[0][row] ) are set to 1
 *          1. One is the success state for this table which indicates
 *          that we are currently at a success state
 */

void set_fail(int table[ ][ CMD_COL ], int row );
/**
 * @pre takes a 2d integer array, and an integer index value for the array
 * @post array at column 0 and this row ( table[0][row] ) are set to 0
 *          Zero is the fail state for this entire table which indicates
 *          that the thing that brought us to this state is currently not
 *          on a success state
 */

// =======================================================================
//  a master function for table: sets successes, fails, and all other states
// =======================================================================

void fill_table( int table[ ][ CMD_COL ] );
/**
 * @pre takes a 2d integer array,
 * @post array at different columns and rows are set to a value that
 *         our state machine will interpret as token values corresponding
 *         states whether they are at a success state or not a success state
 * \note this will be dependent on the states that the person decides
 *       to use for each different token
 *          \example state for START may be 1 or it may be 4
 * \note this will call the fill_ state _machine functions
 */

// ==================================================================
// modifiers for each state
// ==================================================================

void fill_create_machine(  int table[ ][ CMD_COL] );
/**
 * @pre takes a 2d integer array,
 * @post array for the create machine is initailzed based on a state
 *       decided according to the diagram in cmd_line.pdf
 */
void fill_delete_machine( int table[ ][ CMD_COL ] );
/**
 * @pre takes a 2d integer array,
 * @post array for the delete machine is initailzed based on
 *       a state decided according to the diagram in cmd_line.pdf
 */

void fill_drop_machine(  int table[ ][ CMD_COL] );
/**
 * @pre takes a 2d integer array,
 * @post array for the drop machine is initailzed based on
 *       a state decided according to the diagram in cmd_line.pdf
 */

void fill_make_machine(  int table[ ][ CMD_COL] );
/**
 * @pre takes a 2d integer array,
 * @post array for the make machine is initailzed based on
 *       a state decided according to the diagram in cmd_line.pdf
 */

void fill_select_machine( int table[ ][ CMD_COL] );
/**
 * @pre takes a 2d integer array,
 * @post array for the select machine is initailzed based on a state
 *       decided according to the diagram in cmd_line.pdf
 */
void fill_insert_machine( int table[ ][ CMD_COL] );
/**
 * @pre takes a 2d integer array,
 * @post array for the insert machine is initailzed based on a state
 *       decided according to the diagram in cmd_line.pdf
 */
void fill_make_machine( int table[ ][ CMD_COL] );
/**
 * @pre takes a 2d integer array,
 * @post array for the insert machine is initailzed based on a state
 *       decided according to the diagram in cmd_line.pdf
 */

// ==================================================================
// display functions
// ==================================================================

void print_cmd( const int table[][CMD_COL], int row, int col);
/**
 * @pre \param a 2d integer array, and two integers used for index
 *              values to end
 * @post        array from  table[0][0] thru table[row][col] are
 *              displayed on the screen
 */

void show_string( char s[], unsigned int pos);
/**
 * @pre takes a character array and an integer that will tell us what posion
 *      we currently are
 * @post all characters in the array are displayed on the screen with
 *       '^' pointing at a given position in the array
 *       \example //hello world   pos: 7
 *                        ^
 */

#endif // COMMAND_LINE_TABLE_H
