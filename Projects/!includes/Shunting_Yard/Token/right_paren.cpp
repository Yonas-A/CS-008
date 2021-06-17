#include <iostream>
#include <string>

#include "../../!includes/Shunting_Yard/Token/right_paren.h"
#include "../../!includes/Shunting_Yard/Token/token.h"


// =========================================================
// ctor's

Right_Paren::Right_Paren( std::string s )
{
    /// removes quotations if there happens to be quotation around s
   _r_parenthesis =  remove_quotations(s);
}

// =========================================================
// accessors

std::string Right_Paren::get_Right_Paren( )
{
    return _r_parenthesis;
}

ShuntingYardTokens:: TokenType Right_Paren::get_type()
{
    return  static_cast<ShuntingYardTokens::TokenType>
               ( ShuntingYardTokens::TokenType::rparenthesis );
}

// =========================================================
// display

void Right_Paren::print ( )
{
    std::cout << " " << _r_parenthesis << " " ;
}
