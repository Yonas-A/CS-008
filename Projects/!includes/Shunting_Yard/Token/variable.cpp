
#include <iostream>

#include <string.h>

#include "../../!includes/Shunting_Yard/Token/variable.h"
#include "../../!includes/Shunting_Yard/Token/token.h"

// =========================================================
// ctor's

/// sets _var  to s, also instantiates parent class Token
Variable::Variable( string s )
{
    /// removes quotations if there happens to be quotation around s
   _var =  remove_quotations(s);
}


// =========================================================
// accessors

string Variable::get_var()
{
    return  _var;
}

ShuntingYardTokens::TokenType Variable::get_type()
{
    return  static_cast<ShuntingYardTokens::TokenType>
               ( ShuntingYardTokens::TokenType::variables );
    /// \return  value of TokenType enum from ShuntingYardTokens namespace
}


// =========================================================
// display

void Variable::print()
{
//    cout << "Var: " << _var ;
    cout << " " << _var << " " ;
}


