#include "../../!includes/Shunting_Yard/Token/left_paren.h"

#include <iostream>
#include <string>

#include "../../!includes/Shunting_Yard/Token/token.h"

// =========================================================
// ctor

Left_Paren::Left_Paren(std::string s) : _l_parenthesis(s) {
    /// if there's quotation around s, remove the quotation
    _l_parenthesis = remove_quotations(s);
}

// =========================================================
// accessors

std::string Left_Paren::get_Left_Paren() {
    return _l_parenthesis;
}

ShuntingYardTokens::TokenType Left_Paren::get_type() {
    return static_cast<ShuntingYardTokens::TokenType>(ShuntingYardTokens::TokenType::lparenthesis);
}

// =========================================================
// displays

void Left_Paren::print() {
    std::cout << " " << _l_parenthesis << " ";
}
