#ifndef VARIABLE_H
#define VARIABLE_H

#include <iostream>

#include <string.h>

#include "../../!includes/Shunting_Yard/Token/token.h"

class Variable : public ShuntingYardTokens::Token
{

public:

    // =========================================================
    // ctor

    /// ctor with a string param which we set mem var _var to this value
    Variable( string var );

    // =========================================================
    // accessors

    /// a virtual function that'll return _left_paren's token type
    /// \returns an int that will be associated with a token type of
    ///          variables ( in this case 2 )
    virtual ShuntingYardTokens::TokenType get_type( ) override;

    /// \returns the value of mem var _var
    string get_var( );


    // =========================================================
    // display

    /// prints the value of _var to screen
    virtual void print( ) override ;

private:

    /// holds current string value
    string _var;

};

#endif // VARIABLE_H
