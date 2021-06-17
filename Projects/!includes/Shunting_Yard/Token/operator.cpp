
#include <iostream>
#include <string.h>

#include "../../!includes/Shunting_Yard/Token/operator.h"
#include "../../!includes/Shunting_Yard/Token/token.h"

// =========================================================
// ctor

Operator::Operator( string s )
{
    /// if there's quotation around s, remove the quotation
   _operator =  remove_quotations( s );
   this-> assign_precedence( );
}

// =========================================================
// accessors

string Operator::get_operator( )
{
    return _operator;
}

int Operator::get_precedence( ) const
{
    return _precedence[ _operator ];
}

ShuntingYardTokens::TokenType Operator::get_type( )
{
    return  static_cast<ShuntingYardTokens::TokenType>
               ( ShuntingYardTokens::TokenType::operators );
}

// =========================================================
// displays

void Operator::print( )
{
    cout << " " << _operator  << " ";
}

// =========================================================
// private modifiers

void Operator:: assign_precedence( )
{
    _precedence[ "or" ] = 0;
    _precedence[ "oR" ] = 0;
    _precedence[ "Or" ] = 0;
    _precedence[ "OR" ] = 0;
    _precedence[ "||" ] = 0;

    _precedence[ "and" ] = 1;
    _precedence[ "AND" ] = 1;
    _precedence[ "ANd" ] = 1;
    _precedence[ "And" ] = 1;
    _precedence[ "aND" ] = 1;
    _precedence[ "AnD" ] = 1;
    _precedence[ "&&"  ] = 1;

    _precedence[ "==" ] = 2;
    _precedence[ "="  ] = 2; /// just in case a user input error
    _precedence[ "!=" ] = 2;

    _precedence[ "<"  ] = 3;
    _precedence[ "<=" ] = 3;
    _precedence[ ">"  ] = 3;
    _precedence[ ">=" ] = 3;

}




