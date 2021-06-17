#ifndef FTOKENIZER_H
#define FTOKENIZER_H
#include <iostream>
#include <fstream>
#include "../../!includes/STokenizer/stokenizer.h"


class FTokenizer
{

public:

    const int MAX_BLOCK = STokenizer::MAX_BUFFER;

    // =========================================================
    // ctor
    FTokenizer( char* fname );

    // =========================================================
    Token next_token();

    // =========================================================

    int pos( ) const ;
    ///\returns the value of _pos

    int block_pos() const ;
    /// \returns the value of _blockPos

    bool more( ) const;
    /// \returns the current value of _more

    bool open_file( char *fName );
    /// opens the file

    // =========================================================

    friend FTokenizer & operator >> ( FTokenizer& f, Token& t );
    /// returns a

private:

    std::ifstream _f;
    /// file being tokenized

    STokenizer _stk;
    /// STokenizer object to tokenize current block

    int _pos;
    /// Current position in the file

    int _blockPos;
    /// Current position in the current block

    bool _more;
    /// \if there is more block of token to process \return true
    /// \else no more token to process, we are at the end of last block
    ///         \return false;

    // =========================================================
    bool get_new_block();
    /// gets the new block from the file

};


#endif // FTOKENIZER_H
