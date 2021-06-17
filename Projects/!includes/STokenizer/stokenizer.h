#ifndef STOKENIZER_H
#define STOKENIZER_H

#include <iostream>

#include "../../!includes/STokenizer/stokenizer_table.h"
#include "../../!includes/Token/token_strings.h"


using namespace std;

using namespace StokenizerTokens;

class STokenizer
{

public:

    static const int MAX_BUFFER = 500;
    static const int MAX_COLUMNS = COL;
    static const int MAX_ROWS = ROW;
    // ============================================================

    /// default ctor, input will be set using set_string();
    STokenizer( );

    /// takes a character array
    STokenizer( const char str[] );

    // ============================================================
    // modifiers

    /// set buffer to this character string
    void set_string( const char str[] );

    // ============================================================
    //
    /// \returns true or false based on whether we've tokenized the string
    bool done( ) const;
    /*!
     * @brief:
     *  \if     the current position we are at is less
     *          than the length of the string in the buffer
     *          we have more tokens to process. \return false
     * \else    the current position we are at is equal to or
     *          greater than the length of the string in the buffer
     *          we don't any have more tokens to process. \return true
     */

    /// \returns true or false based on whether there's more items
    /// on buffer to tokenize
    bool more( ) const ;
    /*!
     * @brief:
     *  \if     the current position we are at is less or equal
     *          to the length of the string in the buffer, we have
     *          more tokens to process \return true
     *
     * \else    the current position we are at is greater than
     *          the length of the string in the buffer, we don't
     *          have more tokens to process \return false
     */


    /// extracts one token from s (very similar to the way cin >> works)
    friend STokenizer& operator >> ( STokenizer& s,
                                  StokenizerTokens::Token& t );

private:

    static int _table[ MAX_ROWS ][ MAX_COLUMNS ];

    /// input string
    char _buffer[ MAX_BUFFER ];

    /// total length of input string
    int _length;

    /// current position in the string
    int _pos;

    // ============================================================
    // private functions

    /// set all elements of buffer to null character: buffer[i] = '\0'
    void initialize_buffer( ) ;

    /// create table for all the tokens we will recognize
    ///   (e.g. doubles, words, etc.)
    void make_table ( int _table[][ MAX_COLUMNS ] );

    // ==================================================================
    // private modifiers

    ///extract the longest string that match one acceptable token types
    bool get_token( int& start_state, string& token);

    /// removes quotation marks around a token
    void remove_quotations( std::string &token);
    /// \note added for when working with table class

};

#endif // STOKENIZER_H
