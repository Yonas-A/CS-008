#include "../../!includes/Shunting_Yard/Token/number.h"

#include <iostream>
#include <string>

#include "../../!includes/Shunting_Yard/Token/token.h"

// =========================================================
// ctor

Number::Number(double n) : _num(n) {
}

Number::Number(std::string s) {
    /// if there's quotation around s, remove the quotation
    _num = stod(remove_quotations(s));
}

// =========================================================
// accessors

double Number::get_num() {
    return _num;
}

ShuntingYardTokens::TokenType Number::get_type() {
    return static_cast<ShuntingYardTokens::TokenType>(ShuntingYardTokens::TokenType::numbers);
}

// =========================================================
// displays

void Number::print() {
    std::cout << " " << _num << " ";
}
